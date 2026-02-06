#include <stdio.h>
#include <string.h>
#include <json-c/json.h>
#include <stdbool.h>
#include "std_vector.h"
#include "types.h"
#include "parsejson.h"
#include "util.h"

#define NEXT(a, b) json_object_object_get(a, b)
#define NEXT2(a, b, c) NEXT(NEXT(a,b),c)

typedef struct ScratchArg
{
	ScratchArgData data;
	int type;
} ScratchArg;

ScratchArg ParseArg(struct json_object* block_val, char* block_key) 
{
	ScratchArg arg;

	struct json_object* this = block_val;
	int a = json_object_get_int(json_object_array_get_idx(this, 0));
	arg.type = a;
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
			arg.data.idPointer = AsManagedString(json_object_get_string(json_object_array_get_idx(this, 1)));
			arg.type = ArgType_Pointer;
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
		arg.data.text = AsManagedString(json_object_get_string(json_object_array_get_idx(this, 1)));
		arg.type = ArgType_Number;
		break;
	case ArgType_String:
	case ArgType_Colour:
		arg.data.text = AsManagedString(json_object_get_string(json_object_array_get_idx(this, 1)));
		arg.type = ArgType_String;
		break;
	case ArgType_Variable:
		arg.data.text = SanitiseScratchNameToC(AsManagedString(json_object_get_string(json_object_array_get_idx(this, 2))));
		arg.type = ArgType_Variable;
		break;
	default:
		printf("These argument types have not been implemented! %i\n", a);
		exit(-1);
	}
	return arg;
}

ScratchBlock GetBlock(const char* id, struct json_object* blocks) 
{
	ScratchBlock sb;
	struct json_object* block = json_object_object_get(blocks, id);

	sb.opcode = AsManagedString(json_object_get_string(json_object_object_get(block, "opcode")));

	if (strcmp(sb.opcode.data, "procedures_call") == 0)
	{
		sb.opcode = SanitiseScratchNameToC(AsManagedString(json_object_get_string(NEXT2(block, "mutation", "proccode"))));
	}

	struct json_object* fields = NEXT(block, "fields");

	if (strcmp(sb.opcode.data, "data_setvariableto") == 0 || strcmp(sb.opcode.data, "data_changevariableby") == 0)
	{
		sb.args = 2;
		sb.argdata = malloc(sizeof(ScratchArgData) * sb.args); if (!sb.argdata) { printf("Malloc error!"); exit(-1); }
		sb.argtypes = malloc(sizeof(int) * sb.args); if (!sb.argtypes) { printf("Malloc error!"); exit(-1); }
		sb.argdata[1].text = SanitiseScratchNameToC(AsManagedString(json_object_get_string(json_object_array_get_idx(NEXT2(block, "fields", "VARIABLE"), 1))));
		sb.argtypes[1] = ArgType_Variable;
	}
	else if (	strcmp(sb.opcode.data, "data_itemoflist") == 0 || strcmp(sb.opcode.data, "data_itemnumoflist") == 0 || 
				strcmp(sb.opcode.data, "data_addtolist") == 0 || strcmp(sb.opcode.data, "data_deleteoflist") == 0 ||
				strcmp(sb.opcode.data, "data_listcontainsitem") == 0
			)
	{
		sb.args = 2;
		sb.argdata = malloc(sizeof(ScratchArgData) * sb.args); if (!sb.argdata) { printf("Malloc error!"); exit(-1); }
		sb.argtypes = malloc(sizeof(int) * sb.args); if (!sb.argtypes) { printf("Malloc error!"); exit(-1); }
		sb.argdata[1].text = SanitiseScratchNameToC(AsManagedString(json_object_get_string(json_object_array_get_idx(NEXT2(block, "fields", "LIST"), 1))));
		sb.argtypes[1] = ArgType_Variable;
	}
	else if (strcmp(sb.opcode.data, "data_deletealloflist") == 0 || strcmp(sb.opcode.data, "data_lengthoflist") == 0)
	{
		sb.args = 1;
		sb.argdata = malloc(sizeof(ScratchArgData) * sb.args); if (!sb.argdata) { printf("Malloc error!"); exit(-1); }
		sb.argtypes = malloc(sizeof(int) * sb.args); if (!sb.argtypes) { printf("Malloc error!"); exit(-1); }
		sb.argdata[0].text = SanitiseScratchNameToC(AsManagedString(json_object_get_string(json_object_array_get_idx(NEXT2(block, "fields", "LIST"), 1))));
		sb.argtypes[0] = ArgType_Variable;
	}
	else if (strcmp(sb.opcode.data, "data_insertatlist") == 0 || strcmp(sb.opcode.data, "data_replaceitemoflist") == 0)
	{
		sb.args = 3;
		sb.argdata = malloc(sizeof(ScratchArgData) * sb.args); if (!sb.argdata) { printf("Malloc error!"); exit(-1); }
		sb.argtypes = malloc(sizeof(int) * sb.args); if (!sb.argtypes) { printf("Malloc error!"); exit(-1); }
		sb.argdata[2].text = SanitiseScratchNameToC(AsManagedString(json_object_get_string(json_object_array_get_idx(NEXT2(block, "fields", "LIST"), 1))));
		sb.argtypes[2] = ArgType_Variable;
	}
	else if (strcmp(sb.opcode.data, "looks_costume") == 0)
	{
		sb.args = 1;
		sb.argdata = malloc(sizeof(ScratchArgData) * sb.args); if (!sb.argdata) { printf("Malloc error!"); exit(-1); }
		sb.argtypes = malloc(sizeof(int) * sb.args); if (!sb.argtypes) { printf("Malloc error!"); exit(-1); }
		sb.argdata[0].text = AsManagedString(json_object_get_string(json_object_array_get_idx(NEXT2(block, "fields", "COSTUME"), 0)));
		sb.argtypes[0] = ArgType_String;
	}
	else if (strcmp(sb.opcode.data, "looks_backdrops") == 0)
	{
		sb.args = 1;
		sb.argdata = malloc(sizeof(ScratchArgData) * sb.args); if (!sb.argdata) { printf("Malloc error!"); exit(-1); }
		sb.argtypes = malloc(sizeof(int) * sb.args); if (!sb.argtypes) { printf("Malloc error!"); exit(-1); }
		sb.argdata[0].text = AsManagedString(json_object_get_string(json_object_array_get_idx(NEXT2(block, "fields", "BACKDROP"), 0)));
		sb.argtypes[0] = ArgType_String;
	}
	else if (strcmp(sb.opcode.data, "argument_reporter_string_number") == 0)
	{
		sb.args = 1;
		sb.argdata = malloc(sizeof(ScratchArgData) * sb.args); if (!sb.argdata) { printf("Malloc error!"); exit(-1); }
		sb.argtypes = malloc(sizeof(int) * sb.args); if (!sb.argtypes) { printf("Malloc error!"); exit(-1); }
		sb.argdata[0].text = SanitiseScratchNameToC(AsManagedString(json_object_get_string(json_object_array_get_idx(NEXT2(block, "fields", "VALUE"), 0))));
		sb.argtypes[0] = ArgType_Variable;
	}
	else 
	{
		json_object_object_foreach(fields, key, val)
		{
			sb.opcode = SafeStringMerge(sb.opcode, SanitiseScratchNameToC(AsManagedString(json_object_get_string(json_object_array_get_idx(val, 0)))));
		}

		sb.args = json_object_object_length(json_object_object_get(block, "inputs"));
		sb.argdata = malloc(sizeof(ScratchArgData) * sb.args); if (!sb.argdata) { printf("Malloc error!"); exit(-1); }
		sb.argtypes = malloc(sizeof(int) * sb.args); if (!sb.argtypes) { printf("Malloc error!"); exit(-1); }
	}
	struct json_object* args = NEXT(block, "inputs");
	int i = 0;
	json_object_object_foreach(args, block_key, block_val)
	{
		ScratchArg a = ParseArg(block_val, block_key);

		sb.argdata[i] = a.data;
		sb.argtypes[i] = a.type;

		i++;
	}
	return sb;
}

void PushBlock(const char* id, struct json_object* blocks, vecScratchBlock* lines) 
{

	ScratchBlock sb;

	struct json_object* this = json_object_object_get(blocks, id);

	sb.opcode = AsManagedString(json_object_get_string(json_object_object_get(this, "opcode")));

	if (strcmp(sb.opcode.data, "control_repeat") == 0)
	{
		sb.args = 1;
		sb.argdata  = malloc(sizeof(ScratchArgData)); if(!sb.argdata ) { printf("Malloc error!"); exit(-1); } 
		sb.argtypes = malloc(sizeof(int)		   ); if(!sb.argtypes) { printf("Malloc error!"); exit(-1); } 

		struct json_object* arg_data = NEXT2(this, "inputs", "TIMES");

		ScratchArg a = ParseArg(arg_data, "TIMES");

		sb.argdata[0] = a.data;
		sb.argtypes[0] = a.type;

		if (lines->length + 1 > lines->allocated_size) {
			{
				lines->allocated_size = lines->allocated_size * 2; void* temp = realloc(lines->data, lines->allocated_size * lines->sizeoftype); if (!temp) {
					exit(-1);
				} lines->data = temp;
			};
		} lines->data[lines->length] = sb; lines->length++;

		const char* next = json_object_get_string(json_object_array_get_idx(NEXT2(this,"inputs","SUBSTACK"), 1));
		while (next) 
		{
			PushBlock(next, blocks, lines);

			next = json_object_get_string(NEXT2(blocks, next, "next"));
		}

		sb.opcode = SafeStringMerge(AsManagedString("control_loop_end"),AsManagedString(""));
		sb.args = 0;
	}
	else if (strcmp(sb.opcode.data, "control_if") == 0 || strcmp(sb.opcode.data, "control_repeat_until") == 0 || strcmp(sb.opcode.data, "control_while") == 0)
	{
		sb.args = 1;
		sb.argdata = malloc(sizeof(ScratchArgData)); if (!sb.argdata) { printf("Malloc error!"); exit(-1); }
		sb.argtypes = malloc(sizeof(int)); if (!sb.argtypes) { printf("Malloc error!"); exit(-1); }

		sb.argdata[0].text = AsManagedString(json_object_get_string(json_object_array_get_idx(NEXT2(this, "inputs", "CONDITION"), 1)));
		sb.argtypes[0] = ArgType_Pointer;

		if (lines->length + 1 > lines->allocated_size) {
			{
				lines->allocated_size = lines->allocated_size * 2; void* temp = realloc(lines->data, lines->allocated_size * lines->sizeoftype); if (!temp) {
					exit(-1);
				} lines->data = temp;
			};
		} lines->data[lines->length] = sb; lines->length++;

		const char* next = json_object_get_string(json_object_array_get_idx(NEXT2(this, "inputs", "SUBSTACK"), 1));
		while (next)
		{
			PushBlock(next, blocks, lines);

			next = json_object_get_string(NEXT2(blocks, next, "next"));
		}

		if (strcmp(sb.opcode.data, "control_if") == 0)
		{
			sb.opcode = SafeStringMerge(AsManagedString("control_if_end"), AsManagedString(""));
		}
		else 
		{
			sb.opcode = SafeStringMerge(AsManagedString("control_loop_end"), AsManagedString(""));
		}
		sb.args = 0;
	}
	else if (strcmp(sb.opcode.data, "control_if_else") == 0) 
	{
		sb.args = 1;
		sb.opcode = SafeStringMerge(AsManagedString("control_if"), AsManagedString(""));
		sb.argdata = malloc(sizeof(ScratchArgData)); if (!sb.argdata) { printf("Malloc error!"); exit(-1); }
		sb.argtypes = malloc(sizeof(int)); if (!sb.argtypes) { printf("Malloc error!"); exit(-1); }

		sb.argdata[0].text = AsManagedString(json_object_get_string(json_object_array_get_idx(NEXT2(this, "inputs", "CONDITION"), 1)));
		sb.argtypes[0] = ArgType_Pointer;

		if (lines->length + 1 > lines->allocated_size) {
			{
				lines->allocated_size = lines->allocated_size * 2; void* temp = realloc(lines->data, lines->allocated_size * lines->sizeoftype); if (!temp) {
					exit(-1);
				} lines->data = temp;
			};
		} lines->data[lines->length] = sb; lines->length++;

		const char* next = json_object_get_string(json_object_array_get_idx(NEXT2(this, "inputs", "SUBSTACK"), 1));
		while (next)
		{
			PushBlock(next, blocks, lines);

			next = json_object_get_string(NEXT2(blocks, next, "next"));
		}

		sb.opcode = SafeStringMerge(AsManagedString("control_else"), AsManagedString(""));
		sb.args = 0;

		if (lines->length + 1 > lines->allocated_size) {
			{
				lines->allocated_size = lines->allocated_size * 2; void* temp = realloc(lines->data, lines->allocated_size * lines->sizeoftype); if (!temp) {
					exit(-1);
				} lines->data = temp;
			};
		} lines->data[lines->length] = sb; lines->length++;

		next = json_object_get_string(json_object_array_get_idx(NEXT2(this, "inputs", "SUBSTACK2"), 1));
		while (next)
		{
			PushBlock(next, blocks, lines);

			next = json_object_get_string(NEXT2(blocks, next, "next"));
		}

		sb.opcode = SafeStringMerge(AsManagedString("control_if_end"), AsManagedString(""));
		sb.args = 0;
	}
	else if (strcmp(sb.opcode.data, "control_forever") == 0)
	{
		sb.args = 0;

		if (lines->length + 1 > lines->allocated_size) {
			{
				lines->allocated_size = lines->allocated_size * 2; void* temp = realloc(lines->data, lines->allocated_size * lines->sizeoftype); if (!temp) {
					exit(-1);
				} lines->data = temp;
			};
		} lines->data[lines->length] = sb; lines->length++;

		const char* next = json_object_get_string(json_object_array_get_idx(NEXT2(this, "inputs", "SUBSTACK"), 1));
		while (next)
		{
			PushBlock(next, blocks, lines);

			next = json_object_get_string(NEXT2(blocks, next, "next"));
		}

		sb.opcode = SafeStringMerge(AsManagedString("control_loop_end"), AsManagedString(""));
		sb.args = 0;
	}
	else
	{
		sb = GetBlock(id, blocks);
	}

	{
		if (lines->length + 1 > lines->allocated_size) {
			{
				lines->allocated_size = lines->allocated_size * 2; void* temp = realloc(lines->data, lines->allocated_size * lines->sizeoftype); if (!temp) {
					exit(-1);
				} lines->data = temp;
			};
		} lines->data[lines->length] = sb; lines->length++;
	}
}

vecFunction ParseText(struct json_object* blocks)
{
	vecFunction functions;

	functions.allocated_size = 8; functions.length = 0; functions.sizeoftype = sizeof(Function); functions.data = malloc(sizeof(Function) * functions.allocated_size);
	if (!functions.data) {
		exit(-1);
	}

	json_object_object_foreach(blocks, key, block)
	{
		const char* opcode = json_object_get_string(json_object_object_get(block, "opcode"));

		if (strcmp(opcode, "event_whenflagclicked") == 0)
		{
			Function f;

			vecScratchBlock lines;

			lines.allocated_size = 8; lines.length = 0; lines.sizeoftype = sizeof(ScratchBlock); lines.data = malloc(sizeof(ScratchBlock) * lines.allocated_size); if (!lines.data) {
				exit(-1);
			}

			f.blocks = lines;

			f.args = 0;
			f.next = AsManagedString(json_object_get_string(json_object_object_get(block, "next")));

			f.proccode = SafeStringMerge(AsManagedString("Start"), AsManagedString(""));

			f.warp = false;

			std_vector_pushback(functions, f);
		}
		else if (strcmp(opcode, "procedures_prototype") == 0) 
		{
			Function f;

			vecScratchBlock lines;

			lines.allocated_size = 8; lines.length = 0; lines.sizeoftype = sizeof(ScratchBlock); lines.data = malloc(sizeof(ScratchBlock) * lines.allocated_size); if (!lines.data) {
				exit(-1);
			}

			f.blocks = lines;

			char* str = json_object_get_string(json_object_object_get(json_object_object_get(block,"mutation"), "argumentnames"));

			json_object* arg_names = json_tokener_parse(str);

			f.args = json_object_array_length(arg_names);

			f.argids = malloc(f.args * sizeof(String));
			f.argTypes = malloc(f.args);

			char* pc = json_object_get_string(json_object_object_get(json_object_object_get(block, "mutation"), "proccode"));

			for (int i = 0, idx = 0; i < f.args;) 
			{
				// This fails if %'s are included i proccodes. It seems as though Scratch handling is just as janky though. Just adding %s to a text portion of a proccode crashes scratch
				if (pc[idx] == '%')
				{
					f.argTypes[i] = pc[idx + 1];
					i++;
				}
				idx++;
			}

			for (int i = 0; i < f.args; i++) 
			{
				f.argids[i] = SanitiseScratchNameToC(AsManagedString(json_object_get_string(json_object_array_get_idx(arg_names, i))));
			}

			json_object_put(arg_names);

			const char* parent = json_object_get_string(json_object_object_get(block, "parent"));

			f.next = AsManagedString(json_object_get_string(json_object_object_get(json_object_object_get(blocks, parent),"next")));

			f.proccode = SanitiseScratchNameToC(AsManagedString(json_object_get_string(json_object_object_get(json_object_object_get(block, "mutation"), "proccode"))));

			f.warp = strcmp(json_object_get_string(json_object_object_get(json_object_object_get(block, "mutation"), "warp")), "true") == 0;

			std_vector_pushback(functions, f);
		}
	}

	for (int i = 0; i < functions.length; i++) 
	{
		const char* next = functions.data[i].next.data;

		while (next != NULL) 
		{
			PushBlock(next, blocks, &functions.data[i].blocks);

			next = json_object_get_string(json_object_object_get(json_object_object_get(blocks, next), "next"));
		}
	}

	return functions;
}