#include <stdio.h>
#include <string.h>
#include <json-c/json.h>
#include <stdbool.h>
#include "std_vector.h"
#include "types.h"
#include "parsejson.h"
#include "util.h"

ScratchBlock GetScratchBlock(struct json_object* block, String id, vecScratchBlock* lines, struct json_object* blocks, bool probe)
{
	int idx = GetIndexOfBlockById(id.data, *lines);
	if (idx != -1) 
	{
		return lines->data[idx];
	}

	ScratchBlock sb;

	sb.id = id;

	sb.opcode = AsManagedString(json_object_get_string(json_object_object_get(block, "opcode")));

	struct json_object* next = json_object_object_get(block, "next");
	if (json_object_is_type(next, json_type_null))
	{
		sb.next = (String){ NULL, false };
	}
	else
	{
		sb.next = AsManagedString(json_object_get_string(next));
	}
	struct json_object* previous = json_object_object_get(block, "parent");
	if (json_object_is_type(previous, json_type_null))
	{
		sb.previous = (String){ NULL, false };
	}
	else
	{
		sb.previous = AsManagedString(json_object_get_string(previous));
	}


	if (strcmp("control_repeat", sb.opcode.data) == 0)
	{
		sb.args = 1;
		sb.argdata = malloc(sizeof(ScratchArgData)); if (!sb.argdata) { printf("Malloc error!"); exit(-1); }
		sb.argtypes = malloc(sizeof(int)); if (!sb.argtypes) { printf("Malloc error!"); exit(-1); }

		sb.argdata[0].text = AsManagedString(json_object_get_string(json_object_array_get_idx(json_object_array_get_idx(
			json_object_object_get(json_object_object_get(block, "inputs"), "TIMES"),
			1), 1)));
		sb.argtypes[0] = ArgType_Number;

		String realNext = AsManagedString(json_object_get_string(json_object_array_get_idx(json_object_object_get(json_object_object_get(block, "inputs"), "SUBSTACK"), 1)));

		String storeRealNext = realNext;

		ScratchBlock sbLoop;
		String buf;
		while (realNext.data != NULL)
		{
			sbLoop = GetScratchBlock(json_object_object_get(blocks, realNext.data), realNext, lines, blocks, true);

			String storePrevNext = sbLoop.next;


			if (sbLoop.next.data == NULL)
			{
				
				int idx = GetIndexOfBlockById(realNext.data, *lines);
				buf = AsManagedString(SafeStringMerge(sb.id, AsManagedString("_LoopEnd")).data);
				if (idx == -1)
				{
					struct json_object* block = json_object_object_get(blocks, realNext.data);
					if (json_object_object_add(block, "next", json_object_new_string(buf.data)) != 0)
					{
						printf("Could not reset next value");
						exit(-1);
					}
					free(buf.data);
				}
				else 
				{
					lines->data[idx].next = buf;
				}
			}


			realNext = storePrevNext;
		}

		ScratchBlock sbLoopEnd;

		sbLoopEnd.args = 0;
		sbLoopEnd.next = sb.next;
		sbLoopEnd.previous = sbLoop.id;

		sbLoopEnd.id = SafeStringMerge(sb.id, AsManagedString("_LoopEnd"));

		sbLoopEnd.opcode = SafeStringMerge(AsManagedString(""),AsManagedString("control_repeat_end"));

		if (!probe) 
		{
			if (lines->length + 1 > lines->allocated_size) {
				{
					lines->allocated_size = lines->allocated_size * 2; void* temp = realloc(lines->data, lines->allocated_size * lines->sizeoftype); if (!temp) {
						exit(-1);
					} lines->data = temp;
				};
			} lines->data[lines->length] = sbLoopEnd; lines->length++;
		}

		sb.next = storeRealNext;

		return sb;
	}

	if (strcmp(sb.opcode.data, "procedures_call") == 0)
	{
		sb.opcode =
			SanitiseScratchNameToC(
				AsManagedString(
					json_object_get_string(
						json_object_object_get(
							json_object_object_get(
								block,
								"mutation"
							),
							"proccode"
						)
					)
				)
			);
	}

	if (strcmp(sb.opcode.data, "argument_reporter_string_number") == 0)
	{
		sb.args = 1;
		sb.argtypes = malloc(sizeof(int)); if (!sb.argtypes) { printf("Malloc error!"); exit(-1); } sb.argtypes[0] = ArgType_Variable;
		ScratchArgData ad; ad.text = AsManagedString(json_object_get_string(json_object_array_get_idx(json_object_object_get(json_object_object_get(block, "fields"), "VALUE"), 0)));
		sb.argdata = malloc(sizeof(ScratchArgData)); if (!sb.argdata) { printf("Malloc error!"); exit(-1); } sb.argdata[0] = ad;
		return sb;
	}

	struct json_object* args = json_object_object_get(block, "inputs");
	sb.args = json_object_object_length(json_object_object_get(block, "inputs"));

	sb.argdata = malloc(sb.args * sizeof(ScratchArgData));
	sb.argtypes = malloc(sb.args * sizeof(int));

	int i = 0;
	json_object_object_foreach(args, block_key, block_val)
	{
		struct json_object* this = block_val;
		int a = json_object_get_int(json_object_array_get_idx(this, 0));
		sb.argtypes[i] = a;
	get_by_type:
		switch (a)
		{
		case 1:
		case 2:
			if (json_object_get_type(json_object_array_get_idx(this, 1)) == json_type_string)
			{
				goto three;
			}
			a = json_object_get_int(json_object_array_get_idx(json_object_array_get_idx(this, 1), 0));
			this = json_object_array_get_idx(this, 1);
			goto get_by_type;
		three:
		case ArgType_Pointer:
			if (json_object_get_type(json_object_array_get_idx(this, 1)) == json_type_string)
			{
				struct json_object* this = block_val;
				sb.argdata[i].idPointer = AsManagedString(json_object_get_string(json_object_array_get_idx(this, 1)));
				sb.argtypes[i] = ArgType_Pointer;
			}
			else
			{
				a = json_object_get_int(json_object_array_get_idx(json_object_array_get_idx(this, 1), 0));
				this = json_object_array_get_idx(this, 1);

				goto get_by_type;
			}
			break;
		case ArgType_Number:
		case ArgType_PositiveNumber:
		case ArgType_NegativeNumber:
		case ArgType_Integer:
		case ArgType_Angle:
			sb.argdata[i].text = AsManagedString(json_object_get_string(json_object_array_get_idx(this, 1)));
			sb.argtypes[i] = ArgType_Number;
			break;
		case ArgType_String:
			sb.argdata[i].text = AsManagedString(json_object_get_string(json_object_array_get_idx(this, 1)));
			sb.argtypes[i] = ArgType_String;
			break;
		case ArgType_Variable:
			sb.argdata[i].text = SanitiseScratchNameToC(AsManagedString(json_object_get_string(json_object_array_get_idx(this, 2))));
			sb.argtypes[i] = ArgType_Variable;
			break;
		default:
			printf("These argument types have not been implemented! %i\n", a);
			exit(-1);
		}
		if (strcmp(json_object_get_string(json_object_object_get(block, "opcode")), "procedures_call") == 0)
		{
			sb.argtypes[i] = ArgType_Number;
		}
		i++;
	}

	struct json_object* fields = json_object_object_get(block, "fields");

	json_object_object_foreach(fields, fields_key, fields_val)
	{
		String new = SanitiseScratchNameToC(AsManagedString(json_object_get_string(json_object_array_get_idx(fields_val, 0))));
		sb.opcode = SafeStringMerge(sb.opcode, new);
	}

	return sb;
}

ParseTextReturn ParseText(struct json_object* blocks)
{
	vecScratchBlock lines;

	lines.allocated_size = 8; lines.length = 0; lines.sizeoftype = sizeof(ScratchBlock); lines.data = malloc(sizeof(ScratchBlock) * lines.allocated_size); if (!lines.data) {
		exit(-1);
	}

	vecFunction functions;

	functions.allocated_size = 8; functions.length = 0; functions.sizeoftype = sizeof(Function); functions.data = malloc(sizeof(Function) * functions.allocated_size);
	if (!functions.data) {
		exit(-1);
	}

	json_object_object_foreach(blocks, key, val)
	{
		ScratchBlock sb;
		sb.id = AsManagedString(key);

		sb.opcode = AsManagedString(json_object_get_string(json_object_object_get(val, "opcode")));

		struct json_object* next = json_object_object_get(val, "next");
		if (json_object_is_type(next, json_type_null))
		{
			sb.next = (String){ NULL, false };
		}
		else
		{
			sb.next = AsManagedString(json_object_get_string(next));
		}
		struct json_object* previous = json_object_object_get(val, "parent");
		if (json_object_is_type(previous, json_type_null))
		{
			sb.previous = (String){ NULL, false };
		}
		else
		{
			sb.previous = AsManagedString(json_object_get_string(previous));
		}

		if (strcmp(sb.opcode.data, "event_whenflagclicked") == 0)
		{
			Function f;

			f.args = 0;
			char* c = "Start";
			char* d = malloc(strlen(c) + 1); if (!d) { printf("Malloc error!"); exit(-1); }
			memcpy(d, c, strlen(c) + 1);
			f.proccode = AsUnmanagedString(d);

			f.warp = false;

			f.next = sb.next;
			
			std_vector_pushback(functions, f);
			continue;
		}

		if (strcmp(sb.opcode.data, "procedures_definition") == 0)
		{
			continue;
		}

		if (strcmp(sb.opcode.data, "procedures_prototype") == 0)
		{
			Function f;

			struct json_object* mutation = json_object_object_get(val, "mutation");

			struct json_object* argnames = json_tokener_parse(json_object_get_string(json_object_object_get(mutation, "argumentnames")));

			f.args = json_object_array_length(argnames);

			f.argids = malloc(sizeof(String) * f.args);
			f.argTypes = malloc(sizeof(char) * f.args);

			f.next = AsManagedString(json_object_get_string(json_object_object_get(json_object_object_get(blocks, sb.previous.data), "next")));

			if (!f.argids) { printf("Malloc Error!"); exit(-1); }
			if (!f.argTypes) { printf("Malloc Error!"); exit(-1); }

			for (int i = 0; i < f.args; i++)
			{
				f.argTypes[i] = 'n';
				char* a = json_object_get_string(json_object_array_get_idx(argnames, i));
				char* b = malloc(strlen(a) + 1); if (!b) { printf("Malloc error!"); exit(-1); }
				memcpy(b, a, strlen(a) + 1);
				f.argids[i] = AsManagedString(b);
			}

			json_object_put(argnames);

			f.proccode =
				SanitiseScratchNameToC(
					AsManagedString(
						json_object_get_string(
							json_object_object_get(
								mutation,
								"proccode"
							)
						)
					)
				);

			f.warp = strcmp(json_object_get_string(json_object_object_get(mutation, "warp")), "true") == 0;

			std_vector_pushback(functions, f);
			continue;
		}

		sb = GetScratchBlock(val, AsManagedString(key), &lines, blocks, false);

		std_vector_pushback(lines, sb);
	}

	ParseTextReturn output;

	output.blocks = lines;
	output.functions = functions;

	return output;
}