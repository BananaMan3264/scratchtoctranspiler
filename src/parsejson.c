#include <stdio.h>
#include <string.h>
#include <json-c/json.h>
#include <stdbool.h>
#include "std_vector.h"
#include "types.h"
#include "parsejson.h"
#include "util.h"

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

		sb.opcode = AsManagedString(json_object_get_string(json_object_object_get(val, "opcode")));

		if (strcmp(sb.opcode.data, "procedures_call") == 0)
		{
			sb.opcode = 
			SanitiseScratchNameToC(
				AsManagedString(
					json_object_get_string(
						json_object_object_get(
							json_object_object_get(
								val, 
								"mutation"
							), 
							"proccode"
						)
					)
				)
			);
		}

		if (strcmp(sb.opcode.data, "procedures_definition") == 0)
		{
			continue;
		}

		if (strcmp(sb.opcode.data, "event_whenflagclicked") == 0) 
		{
			Function f;

			f.args = 0;
			char* c = "Start";
			char* d = malloc(strlen(c) + 1); if (!d) { printf("Malloc error!"); exit(-1); }
			memcpy(d, c, strlen(c) + 1);
			f.proccode = AsUnmanagedString(d);

			f.next = sb.next;

			std_vector_pushback(functions, f);
			continue;
		}

		if (strcmp(sb.opcode.data, "procedures_prototype") == 0) 
		{
			Function f;

			struct json_object* mutation = json_object_object_get(val, "mutation");

			struct json_object* argnames = json_tokener_parse(json_object_get_string(json_object_object_get(mutation,"argumentnames")));

			f.args = json_object_array_length(argnames);

			f.argids   = malloc(sizeof(String*) * f.args);
			f.argTypes = malloc(sizeof(char*  ) * f.args);

			f.next = AsManagedString(json_object_get_string(json_object_object_get(json_object_object_get(blocks, sb.previous.data), "next")));

			if (!f.argids  ) { printf("Malloc Error!"); exit(-1); }
			if (!f.argTypes) { printf("Malloc Error!"); exit(-1); }

			for (int i = 0; i < f.args; i++)
			{
				f.argTypes[i] = 'n';
				char* a = json_object_get_string(json_object_array_get_idx(argnames, i));
				char* b = malloc(strlen(a) + 1);
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

			std_vector_pushback(functions, f);
			continue;
		}

		if (strcmp(sb.opcode.data, "argument_reporter_string_number") == 0)
		{
			sb.args = 1;
			sb.argtypes = malloc(sizeof(int*           )); if (!sb.argtypes) { printf("Malloc error!"); exit(-1); } sb.argtypes[0] = ArgType_Variable;
			ScratchArgData ad; ad.text = AsManagedString(json_object_get_string(json_object_array_get_idx(json_object_object_get(json_object_object_get(val, "fields"),"VALUE"), 0)));
			sb.argdata  = malloc(sizeof(ScratchArgData*)); if (!sb.argdata ) { printf("Malloc error!"); exit(-1); } sb.argdata [0] =               ad;
			std_vector_pushback(lines, sb);
			continue;
		}

		struct json_object* args = json_object_object_get(val, "inputs");
		sb.args = json_object_object_length(json_object_object_get(val, "inputs"));

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
			if (strcmp(json_object_get_string(json_object_object_get(val, "opcode")), "procedures_call") == 0)
			{
				sb.argtypes[i] = ArgType_Number;
			}
			i++;
		}

		struct json_object* fields = json_object_object_get(val, "fields");

		json_object_object_foreach(fields, fields_key, fields_val) 
		{
			String new = SanitiseScratchNameToC(AsManagedString(json_object_get_string(json_object_array_get_idx(fields_val, 0))));
			sb.opcode = SafeStringMerge(sb.opcode, new);
		}

		std_vector_pushback(lines, sb);
	}

	ParseTextReturn output;

	output.blocks = lines;
	output.functions = functions;

	return output;
}