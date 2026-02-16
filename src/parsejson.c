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

extern char* sprite_index;

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
	case 11:
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

	struct json_object* args = NEXT(block, "inputs");

	if (strcmp(sb.opcode.data, "procedures_call") == 0)
	{
		sb.opcode = SanitiseScratchNameToC(AsManagedString(json_object_get_string(NEXT2(block, "mutation", "proccode"))));
		json_object* argumentids = json_tokener_parse(json_object_get_string(NEXT2(block, "mutation", "argumentids")));
		
		sb.args = json_object_array_length(argumentids);
		sb.argdata = malloc(sizeof(ScratchArgData) * sb.args); if (!sb.argdata) { printf("Malloc error!"); exit(-1); }
		sb.argtypes = malloc(sizeof(int) * sb.args); if (!sb.argtypes) { printf("Malloc error!"); exit(-1); }
		for (int i = 0; i < json_object_array_length(argumentids); i++)
		{
			char* str = json_object_get_string(json_object_array_get_idx(argumentids, i));
			
			ScratchArg a = ParseArg(json_object_object_get(args, str), str);

			sb.argdata[i] = a.data;
			sb.argtypes[i] = a.type;
		}

		return sb;
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
	else if (strcmp(sb.opcode.data, "sound_sounds_menu") == 0)
	{
		sb.args = 1;
		sb.argdata = malloc(sizeof(ScratchArgData) * sb.args); if (!sb.argdata) { printf("Malloc error!"); exit(-1); }
		sb.argtypes = malloc(sizeof(int) * sb.args); if (!sb.argtypes) { printf("Malloc error!"); exit(-1); }
		sb.argdata[0].text = AsManagedString(json_object_get_string(json_object_array_get_idx(NEXT2(block, "fields", "SOUND_MENU"), 0)));
		sb.argtypes[0] = ArgType_String;
	}
	else if (strcmp(sb.opcode.data, "looks_costume") == 0)
	{
		sb.args = 1;
		sb.argdata = malloc(sizeof(ScratchArgData) * sb.args); if (!sb.argdata) { printf("Malloc error!"); exit(-1); }
		sb.argtypes = malloc(sizeof(int) * sb.args); if (!sb.argtypes) { printf("Malloc error!"); exit(-1); }
		sb.argdata[0].text = AsManagedString(json_object_get_string(json_object_array_get_idx(NEXT2(block, "fields", "COSTUME"), 0)));
		sb.argtypes[0] = ArgType_String;
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

		if (opcode == NULL) { continue; }

		if (strcmp(opcode, "event_whenflagclicked") == 0)
		{
			Function f;

			f.opcode = event_whenflagclicked;

			vecScratchBlock lines;

			lines.allocated_size = 8; lines.length = 0; lines.sizeoftype = sizeof(ScratchBlock); lines.data = malloc(sizeof(ScratchBlock) * lines.allocated_size); if (!lines.data) {
				exit(-1);
			}

			f.blocks = lines;

			f.args = 0;
			f.next = AsManagedString(json_object_get_string(json_object_object_get(block, "next")));

			String str2 = SanitiseScratchNameToC(AsManagedString(key));

			int length = strlen(str2.data) + strlen(opcode) + strlen(sprite_index) + 3;

			f.proccode = AsUnmanagedString(malloc(length));

			snprintf(f.proccode.data, length, "_%s_%s%s", sprite_index, str2.data, opcode);

			free(str2.data);

			f.warp = false;

			std_vector_pushback(functions, f);
		}
		else if (strcmp(opcode, "event_whenbroadcastreceived") == 0)
		{
			Function f;

			f.opcode = event_whenbroadcastreceived;

			vecScratchBlock lines;

			lines.allocated_size = 8; lines.length = 0; lines.sizeoftype = sizeof(ScratchBlock); lines.data = malloc(sizeof(ScratchBlock) * lines.allocated_size); if (!lines.data) {
				exit(-1);
			}

			f.blocks = lines;

			f.args = 0;
			f.next = AsManagedString(json_object_get_string(json_object_object_get(block, "next")));

			String str2 = SanitiseScratchNameToC(AsManagedString(key));

			char* broadcast = SanitiseScratchNameToC(AsManagedString(json_object_get_string(json_object_array_get_idx(json_object_object_get(json_object_object_get(block, "fields"), "BROADCAST_OPTION"),1)))).data;

			int length = strlen(str2.data) + strlen(opcode) + strlen(sprite_index) + strlen(broadcast) + 4;
			
			f.proccode = AsUnmanagedString(malloc(length));

			f.argids = malloc(sizeof(String));

			f.argids[0] = SafeStringMerge(AsManagedString(broadcast), AsManagedString(""));

			snprintf(f.proccode.data, length, "_%s_%s%s_%s", sprite_index, str2.data, opcode, broadcast);

			free(str2.data);

			f.warp = false;

			std_vector_pushback(functions, f);
		}
		else if (strcmp(opcode, "event_whenkeypressed") == 0)
		{
			Function f;


			vecScratchBlock lines;

			lines.allocated_size = 8; lines.length = 0; lines.sizeoftype = sizeof(ScratchBlock); lines.data = malloc(sizeof(ScratchBlock) * lines.allocated_size); if (!lines.data) {
				exit(-1);
			}

			f.blocks = lines;

			f.args = 0;
			f.next = AsManagedString(json_object_get_string(json_object_object_get(block, "next")));

			char* key_press = json_object_get_string(json_object_array_get_idx(json_object_object_get(json_object_object_get(block, "fields"),"KEY_OPTION"),0));

			if (strcmp(key_press,"space"		) == 0) { f.opcode = event_whenkeypressed_space;		}
			if (strcmp(key_press,"up arrow"		) == 0) { f.opcode = event_whenkeypressed_up_arrow;		}
			if (strcmp(key_press,"down arrow"	) == 0) { f.opcode = event_whenkeypressed_down_arrow;	}
			if (strcmp(key_press,"left arrow"	) == 0) { f.opcode = event_whenkeypressed_left_arrow;	}
			if (strcmp(key_press,"right arrow"	) == 0) { f.opcode = event_whenkeypressed_right_arrow;	}
			if (strcmp(key_press,"enter"		) == 0) { f.opcode = event_whenkeypressed_enter;		}

			if (strcmp(key_press,"a") == 0) { f.opcode = event_whenkeypressed_a; }
			if (strcmp(key_press,"b") == 0) { f.opcode = event_whenkeypressed_b; }
			if (strcmp(key_press,"c") == 0) { f.opcode = event_whenkeypressed_c; }
			if (strcmp(key_press,"d") == 0) { f.opcode = event_whenkeypressed_d; }
			if (strcmp(key_press,"e") == 0) { f.opcode = event_whenkeypressed_e; }
			if (strcmp(key_press,"f") == 0) { f.opcode = event_whenkeypressed_f; }
			if (strcmp(key_press,"g") == 0) { f.opcode = event_whenkeypressed_g; }
			if (strcmp(key_press,"h") == 0) { f.opcode = event_whenkeypressed_h; }
			if (strcmp(key_press,"i") == 0) { f.opcode = event_whenkeypressed_i; }
			if (strcmp(key_press,"j") == 0) { f.opcode = event_whenkeypressed_j; }
			if (strcmp(key_press,"k") == 0) { f.opcode = event_whenkeypressed_k; }
			if (strcmp(key_press,"l") == 0) { f.opcode = event_whenkeypressed_l; }
			if (strcmp(key_press,"m") == 0) { f.opcode = event_whenkeypressed_m; }
			if (strcmp(key_press,"n") == 0) { f.opcode = event_whenkeypressed_n; }
			if (strcmp(key_press,"o") == 0) { f.opcode = event_whenkeypressed_o; }
			if (strcmp(key_press,"p") == 0) { f.opcode = event_whenkeypressed_p; }
			if (strcmp(key_press,"q") == 0) { f.opcode = event_whenkeypressed_q; }
			if (strcmp(key_press,"r") == 0) { f.opcode = event_whenkeypressed_r; }
			if (strcmp(key_press,"s") == 0) { f.opcode = event_whenkeypressed_s; }
			if (strcmp(key_press,"t") == 0) { f.opcode = event_whenkeypressed_t; }
			if (strcmp(key_press,"u") == 0) { f.opcode = event_whenkeypressed_u; }
			if (strcmp(key_press,"v") == 0) { f.opcode = event_whenkeypressed_v; }
			if (strcmp(key_press,"w") == 0) { f.opcode = event_whenkeypressed_w; }
			if (strcmp(key_press,"x") == 0) { f.opcode = event_whenkeypressed_x; }
			if (strcmp(key_press,"y") == 0) { f.opcode = event_whenkeypressed_y; }
			if (strcmp(key_press,"z") == 0) { f.opcode = event_whenkeypressed_z; }

			if (strcmp(key_press, "0") == 0) { f.opcode = event_whenkeypressed_0; }
			if (strcmp(key_press, "1") == 0) { f.opcode = event_whenkeypressed_1; }
			if (strcmp(key_press, "2") == 0) { f.opcode = event_whenkeypressed_2; }
			if (strcmp(key_press, "3") == 0) { f.opcode = event_whenkeypressed_3; }
			if (strcmp(key_press, "4") == 0) { f.opcode = event_whenkeypressed_4; }
			if (strcmp(key_press, "5") == 0) { f.opcode = event_whenkeypressed_5; }
			if (strcmp(key_press, "6") == 0) { f.opcode = event_whenkeypressed_6; }
			if (strcmp(key_press, "7") == 0) { f.opcode = event_whenkeypressed_7; }
			if (strcmp(key_press, "8") == 0) { f.opcode = event_whenkeypressed_8; }
			if (strcmp(key_press, "9") == 0) { f.opcode = event_whenkeypressed_9; }

			if (strcmp(key_press, "-") == 0) { f.opcode = event_whenkeypressed_minus;				   }
			if (strcmp(key_press, ",") == 0) { f.opcode = event_whenkeypressed_comma;				   }
			if (strcmp(key_press, ".") == 0) { f.opcode = event_whenkeypressed_full_stop;			   }
			if (strcmp(key_press, "`") == 0) { f.opcode = event_whenkeypressed_back_tick;			   }
			if (strcmp(key_press, "=") == 0) { f.opcode = event_whenkeypressed_equals;				   }
			if (strcmp(key_press, "[") == 0) { f.opcode = event_whenkeypressed_left_bracket;		   }
			if (strcmp(key_press, "]") == 0) { f.opcode = event_whenkeypressed_right_bracket;		   }
			if (strcmp(key_press,"\\") == 0) { f.opcode = event_whenkeypressed_backslash;			   }
			if (strcmp(key_press, ";") == 0) { f.opcode = event_whenkeypressed_semicolon;			   }
			if (strcmp(key_press, "'") == 0) { f.opcode = event_whenkeypressed_single_quote;		   }
			if (strcmp(key_press, "/") == 0) { f.opcode = event_whenkeypressed_solidus;				   }
			if (strcmp(key_press, "!") == 0) { f.opcode = event_whenkeypressed_exclamation_mark;	   }
			if (strcmp(key_press, "@") == 0) { f.opcode = event_whenkeypressed_at_sign;				   }
			if (strcmp(key_press, "#") == 0) { f.opcode = event_whenkeypressed_pound;				   }
			if (strcmp(key_press, "$") == 0) { f.opcode = event_whenkeypressed_dollar;				   }
			if (strcmp(key_press, "%") == 0) { f.opcode = event_whenkeypressed_percent;				   }
			if (strcmp(key_press, "^") == 0) { f.opcode = event_whenkeypressed_caret;				   }
			if (strcmp(key_press, "&") == 0) { f.opcode = event_whenkeypressed_ampersand;			   }
			if (strcmp(key_press, "*") == 0) { f.opcode = event_whenkeypressed_star;				   }
			if (strcmp(key_press, "(") == 0) { f.opcode = event_whenkeypressed_left_parenth;		   }
			if (strcmp(key_press, ")") == 0) { f.opcode = event_whenkeypressed_right_parenth;		   }
			if (strcmp(key_press, "_") == 0) { f.opcode = event_whenkeypressed_underscore;			   }
			if (strcmp(key_press, "+") == 0) { f.opcode = event_whenkeypressed_plus;				   }
			if (strcmp(key_press, "{") == 0) { f.opcode = event_whenkeypressed_left_brace;			   }
			if (strcmp(key_press, "}") == 0) { f.opcode = event_whenkeypressed_right_brace;			   }
			if (strcmp(key_press, "|") == 0) { f.opcode = event_whenkeypressed_pipe;				   }
			if (strcmp(key_press, ":") == 0) { f.opcode = event_whenkeypressed_colon;				   }
			if (strcmp(key_press,"\"") == 0) { f.opcode = event_whenkeypressed_double_quote;		   }
			if (strcmp(key_press, "?") == 0) { f.opcode = event_whenkeypressed_question_mark;		   }
			if (strcmp(key_press, "<") == 0) { f.opcode = event_whenkeypressed_left_triangle_bracket;  }
			if (strcmp(key_press, ">") == 0) { f.opcode = event_whenkeypressed_right_traingle_bracket; }
			if (strcmp(key_press, "~") == 0) { f.opcode = event_whenkeypressed_tilda; }

			if (strcmp(key_press, "backspace"		) == 0) { f.opcode = event_whenkeypressed_backspace;   }
			if (strcmp(key_press, "delete"			) == 0) { f.opcode = event_whenkeypressed_delete;	   }
			if (strcmp(key_press, "shift"			) == 0) { f.opcode = event_whenkeypressed_shift;	   }
			if (strcmp(key_press, "caps lock"		) == 0) { f.opcode = event_whenkeypressed_caps_lock;   }
			if (strcmp(key_press, "scroll lock"		) == 0) { f.opcode = event_whenkeypressed_scroll_lock; }
			if (strcmp(key_press, "control"			) == 0) { f.opcode = event_whenkeypressed_control;	   }
			if (strcmp(key_press, "escape"			) == 0) { f.opcode = event_whenkeypressed_escape;	   }
			if (strcmp(key_press, "insert"			) == 0) { f.opcode = event_whenkeypressed_insert;	   }
			if (strcmp(key_press, "home"			) == 0) { f.opcode = event_whenkeypressed_home;		   }
			if (strcmp(key_press, "end"				) == 0) { f.opcode = event_whenkeypressed_end;		   }
			if (strcmp(key_press, "page up"			) == 0) { f.opcode = event_whenkeypressed_page_up;	   }
			if (strcmp(key_press, "page down"		) == 0) { f.opcode = event_whenkeypressed_page_down;   }



			String str2 = SanitiseScratchNameToC(AsManagedString(key));

			int length = strlen(str2.data) + strlen(opcode) + strlen(sprite_index) + 3;

			f.proccode = AsUnmanagedString(malloc(length));

			snprintf(f.proccode.data, length, "_%s_%s%s", sprite_index, str2.data, opcode);

			f.warp = false;

			std_vector_pushback(functions, f);
		}
		else if (strcmp(opcode, "procedures_prototype") == 0) 
		{
			Function f;

			f.opcode = procedures_prototype;

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

			char* pc2 = json_object_get_string(json_object_object_get(json_object_object_get(block, "mutation"), "proccode"));

			char* pc = SafeStringMerge(AsManagedString(sprite_index), AsManagedString(pc2)).data;

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