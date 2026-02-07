#include <stdio.h>
#include <string.h>
#include <json-c/json.h>
#include <stdbool.h>
#include "std_vector.h"
#include "types.h"
#include "util.h"
#include "parsejson.h"

#define DEG_TO_RAD 0.0174532925199

String GetArg(int argtype, ScratchArgData argdata, struct json_object* blocks);

int GetFirstWhenFlagClicked(vecScratchBlock lines)
{
	for (int i = 0; i < lines.length; i++) 
	{
		if (strcmp(lines.data[i].opcode.data, "event_whenflagclicked") == 0) 
		{
			return i;
		}
	}
}

String LineToBlock(ScratchBlock sb, struct json_object* blocks, bool top)
{
	String str = SafeStringMerge(sb.opcode, AsManagedString("("));
	for (int i = 0; i < sb.args - 1; i++)
	{
		str = SafeStringMerge(str, GetArg(sb.argtypes[i], sb.argdata[i], blocks));
		str = SafeStringMerge(str, AsManagedString(", "));
	}
	if (sb.args != 0)
	{
		int idx = sb.args - 1;
		String c = GetArg(sb.argtypes[idx], sb.argdata[idx], blocks);
		str = SafeStringMerge(str, c);
	}
	if (top)
	{
		str = SafeStringMerge(str, AsManagedString(");"));
	}
	else
	{
		str = SafeStringMerge(str, AsManagedString(")"));
	}
	return str;
}

String GetArg(int argtype, ScratchArgData argdata, struct json_object* blocks)
{
	switch (argtype) 
	{
	case ArgType_Pointer:
		return LineToBlock(GetBlock(argdata.idPointer.data, blocks), blocks, false);
	
	case ArgType_Number:
	case ArgType_PositiveNumber:
	case ArgType_NegativeNumber:
	case ArgType_Integer:
	case ArgType_Angle:
		return SafeStringMerge(SafeStringMerge(AsManagedString("ScratchSetDouble("), argdata.text), AsManagedString(")"));

	case ArgType_String:
		return SafeStringMerge(SafeStringMerge(AsManagedString("ScratchSetString(\""), argdata.text), AsManagedString("\")"));

	case ArgType_Variable:
		return argdata.text;
	}
}

void PrintData(struct json_object* targets) 
{
#define SetAllZeros()																						\
																											\
for (int i = 0; i < sprites_count; i++) {																	\
	fprintf(file, "0.0");																					\
	if (i != sprites_count - 1) {																			\
		fprintf(file, ", ");																				\
	}																										\
}																											
#define GetAttrib(name, key)																				\
fprintf(file, "double scratch_" name "[] = { ");															\
for (int i = 0; i < sprites_count; i++)																		\
{																											\
	json_object* this = json_object_object_get(json_object_array_get_idx(targets, i), key);					\
	if (json_object_get_type(this) == json_type_null)														\
	{																										\
		fprintf(file, "0.0");																				\
	}																										\
	else																									\
	{																										\
		double d = json_object_get_double(this);															\
		fprintf(file, "%f", d);																				\
	}																										\
	if (i != sprites_count - 1) 																			\
	{																										\
		fprintf(file, ", ");																				\
	}																										\
}																											\
fprintf(file, " };\n");

	FILE* file = fopen("../../../output/sprite_data.c", "w");

	int sprites_count = json_object_array_length(targets);

	fprintf(file, "#include <stdbool.h>\n#include <stdlib.h>\n#include \"runtime/motion.h\"\n#include \"sprite_data.h\"\n\n");

	GetAttrib("motion_SpriteX", "x");
	GetAttrib("motion_SpriteY", "y");

	fprintf(file, "double scratch_" "motion_SpriteDirection" "[] = { "); for (int i = 0; i < sprites_count; i++) {
		json_object* this = json_object_object_get(json_object_array_get_idx(targets, i), "direction"); if (json_object_get_type(this) == json_type_null) {
			fprintf(file, "0.0");
		}
		else {
			double d = json_object_get_double(this); fprintf(file, "%f", (d - 90) * DEG_TO_RAD);
		} if (i != sprites_count - 1) {
			fprintf(file, ", ");
		}
	} fprintf(file, " };\n");;

	fprintf(file, "bool scratch_" "looks_hidden" "[] = { "); 
	for (int i = 0; i < sprites_count; i++) {
		json_object* this = json_object_object_get(json_object_array_get_idx(targets, i), "visible"); 
		if (json_object_get_type(this) == json_type_null) {
			fprintf(file, "false");
		}
		else {
			json_bool d = json_object_get_boolean(this);
			if (d)
			{
				fprintf(file, "false");
			}
			else
			{
				fprintf(file, "true");
			}
		} 
		if (i != sprites_count - 1) {
			fprintf(file, ", ");
		}
	} 
	fprintf(file, " };\n");

	fprintf(file, "int scratch_motion_SpriteRotStyle[] = { ");
	for (int i = 0; i < sprites_count; i++) {
		json_object* this = json_object_object_get(json_object_array_get_idx(targets, i), "size");
		if (json_object_get_type(this) == json_type_null) {
			fprintf(file, "RotStyle_allaround");
		}
		else {
			char* d = json_object_get_string(this);
			if (strcmp(d, "left-right") == 0)
			{
				fprintf(file, "RotStyle_leftright");
			}
			else if (strcmp(d, "don't rotate") == 0)
			{
				fprintf(file, "RotStyle_dontrotate");
			}
			else 
			{
				fprintf(file, "RotStyle_allaround");
			}
		}
		if (i != sprites_count - 1) {
			fprintf(file, ", ");
		}
	};
	fprintf(file, " };\n");

	fprintf(file, "int scratch_looks_CostumeIndex[] = { ");
	for (int i = 0; i < sprites_count; i++) {
		json_object* this = json_object_object_get(json_object_array_get_idx(targets, i), "currentCostume");
		fprintf(file, "%i", json_object_get_int(this));
		if (i != sprites_count - 1) {
			fprintf(file, ", ");
		}
	}
	fprintf(file, " };\n");

	int max_costume_count = 0;

	fprintf(file, "int scratch_looks_CostumeCounts[] = { ");
	for (int i = 0; i < sprites_count; i++) {
		json_object* this = json_object_object_get(json_object_array_get_idx(targets, i), "costumes");
		int len = (int)json_object_array_length(this);
		fprintf(file, "%i", len);
		if (len > max_costume_count) { max_costume_count = len; }
		if (i != sprites_count - 1) {
			fprintf(file, ", ");
		}
	}
	fprintf(file, " };\n");

	fprintf(file, "char* scratch_looks_CostumeNames[SPRITES][MAX_COSTUME_LENGTH] = {\n");
	for (int i = 0; i < sprites_count; i++) {
		fprintf(file, "\t{ ");
		for (int j = 0; j < max_costume_count; j++) {
			json_object* this = json_object_object_get(json_object_array_get_idx(targets, i), "costumes");
			json_object* this_name = json_object_object_get(json_object_array_get_idx(this, j),"name");
			if (json_object_get_type(this_name) != json_type_null) {
				fprintf(file, "\"%s\"", json_object_get_string(this_name));
			}
			else 
			{
				fprintf(file, "NULL");
			}
			if (j != max_costume_count - 1) {
				fprintf(file, ", ");
			}
		}
		if (i != sprites_count - 1) {
			fprintf(file, " },\n");
		}
		else 
		{
			fprintf(file, " }\n");
		}
	}
	fprintf(file, " };\n");

	fprintf(file, "char* scratch_looks_CostumeFiles[SPRITES][MAX_COSTUME_LENGTH] = {\n");
	for (int i = 0; i < sprites_count; i++) {
		fprintf(file, "\t{ ");
		for (int j = 0; j < max_costume_count; j++) {
			json_object* this = json_object_object_get(json_object_array_get_idx(targets, i), "costumes");
			json_object* this_name = json_object_object_get(json_object_array_get_idx(this, j), "assetId");
			if (json_object_get_type(this_name) != json_type_null) {
				fprintf(file, "\"%s.svg\"", json_object_get_string(this_name));
			}
			else
			{
				fprintf(file, "NULL");
			}
			if (j != max_costume_count - 1) {
				fprintf(file, ", ");
			}
		}
		if (i != sprites_count - 1) {
			fprintf(file, " },\n");
		}
		else
		{
			fprintf(file, " }\n");
		}
	}
	fprintf(file, " };\n");

	fprintf(file, "double scratch_" "motion_SpriteSize" "[] = { "); for (int i = 0; i < sprites_count; i++) {
		json_object* this = json_object_object_get(json_object_array_get_idx(targets, i), "size"); if (json_object_get_type(this) == json_type_null) {
			fprintf(file, "100.0");
		}
		else {
			double d = json_object_get_double(this); fprintf(file, "%f", d);
		} if (i != sprites_count - 1) {
			fprintf(file, ", ");
		}
	} fprintf(file, " };\n");;

	fprintf(file, "double scratch_motion_SpriteWidth[SPRITES][MAX_COSTUME_LENGTH] = { ");
	for (int i = 0; i < sprites_count; i++) {
		fprintf(file, "{");
		for (int j = 0; j < max_costume_count; j++) {
			fprintf(file, "0.0");
			if (j != max_costume_count - 1) {
				fprintf(file, ", ");
			}
		}
		fprintf(file, "}"); 
		if (i != sprites_count - 1) {
			fprintf(file, ", ");
		}
	}
	fprintf(file, " };\n");

	fprintf(file, "double scratch_motion_SpriteHeight[SPRITES][MAX_COSTUME_LENGTH] = { ");
	for (int i = 0; i < sprites_count; i++) {
		fprintf(file, "{");
		for (int j = 0; j < max_costume_count; j++) {
			fprintf(file, "0.0");
			if (j != max_costume_count - 1) {
				fprintf(file, ", ");
			}
		}
		fprintf(file, "}");
		if (i != sprites_count - 1) {
			fprintf(file, ", ");
		}
	}
	fprintf(file, " };\n");

	fprintf(file, "double scratch_looks_effects_colour[] = { ");
	SetAllZeros();
	fprintf(file, " };\n");

	fprintf(file, "double scratch_looks_effects_fisheye[] = { ");
	SetAllZeros();
	fprintf(file, " };\n");

	fprintf(file, "double scratch_looks_effects_whirl[] = { ");
	SetAllZeros();
	fprintf(file, " };\n");

	fprintf(file, "double scratch_looks_effects_pixelate[] = { ");
	SetAllZeros();
	fprintf(file, " };\n");

	fprintf(file, "double scratch_looks_effects_mosaic[] = { ");
	SetAllZeros();
	fprintf(file, " };\n");

	fprintf(file, "double scratch_looks_effects_brightness[] = { ");
	SetAllZeros();
	fprintf(file, " };\n");

	fprintf(file, "double scratch_looks_effects_ghost[] = { ");
	SetAllZeros();
	fprintf(file, " };\n");

	fclose(file);

	FILE* header = fopen("../../../output/sprite_data.h", "w");

	fprintf(header, "#define SPRITES %i\n#define MAX_COSTUME_LENGTH %i", sprites_count, max_costume_count);

	fclose(header);
}

char* GetFullProgram(struct json_object* variables, struct json_object* lists, vecFunction functions, struct json_object* blocks)
{
	FILE* mainh = fopen("../../../output/sprite1.h", "w");

	fprintf(mainh, "void Init();\n\n");

	for (int i = 0; i < functions.length; i++)
	{
		fprintf(mainh, "void %s();\n", functions.data[i].proccode.data);
	}

	fclose(mainh);
	FILE* scheduler = fopen("../../../output/schedule.c", "w");

	fprintf(scheduler, "#include<libco.h>\n#include\"sprite1.h\"\n#include\"runtime/main.h\"\n\ncothread_t scheduler;\ncothread_t draw_thread;\n\n");

	for (int i = 0; i < functions.length; i++)
	{
		fprintf(scheduler, "cothread_t %s_thread;\n", functions.data[i].proccode.data);
	}

	fprintf(scheduler, "\nvoid RunScheduler()\n{\n\tInit();\n\n\tscheduler = co_active();\n\n");

	for (int i = 0; i < functions.length; i++)
	{
		fprintf(scheduler, "\t%s_thread = co_create(64 * 1024, %s);\n", functions.data[i].proccode.data, functions.data[i].proccode.data);
	}

	fprintf(scheduler, "\n\twhile (1)\n\t{\n");
	for (int i = 0; i < functions.length; i++)
	{
		fprintf(scheduler, "\t\tco_switch(%s_thread);\n", functions.data[i].proccode.data);
	}
	fprintf(scheduler, "\t\tRender();\n\t}\n}");

	fclose(scheduler);

	FILE* file = fopen("../../../output/sprite1.c", "w");

	fprintf(file, "#define TRUE_YIELD co_switch(scheduler);\n#define YIELD TRUE_YIELD;\n#include \"runtime/scratch.h\"\n#include \"runtime/motion.h\"\n#include \"runtime/looks.h\"\n");
	fprintf(file, "#include \"runtime/operators.h\"\n#include \"runtime/control.h\"\n#include \"runtime/sensing.h\"\n#include \"runtime/data.h\"\n#include \"runtime/pen.h\"\n");
	fprintf(file, "#include <libco.h>\n\nextern cothread_t scheduler;\n\n");
	{
		json_object_object_foreach(variables, key, val)
		{

			fprintf(file, "ScratchValue %s;\n", SanitiseScratchNameToC(AsManagedString(key)).data);
		}
	}
	{
		json_object_object_foreach(lists, key, val)
		{
			fprintf(file, "ScratchList %s;\n", SanitiseScratchNameToC(AsManagedString(key)).data);
		}
	}
	fprintf(file, "\nvoid Init()\n{\n");
	{
		json_object_object_foreach(variables, key, val)
		{
			int type = json_object_get_type(json_object_array_get_idx(val, 1));
			switch (json_object_get_type(json_object_array_get_idx(val, 1)))
			{
			case json_type_int:
				fprintf(file, "\t%s = ScratchSetDouble(%i);\n", SanitiseScratchNameToC(AsManagedString(key)).data, json_object_get_int(json_object_array_get_idx(val, 1)));
				break;
			case json_type_double:
				fprintf(file, "\t%s = ScratchSetDouble(%f);\n", SanitiseScratchNameToC(AsManagedString(key)).data, json_object_get_double(json_object_array_get_idx(val, 1)));
				break;
			case json_type_string:
				fprintf(file, "\t%s = ScratchSetString(\"%s\");\n", SanitiseScratchNameToC(AsManagedString(key)).data, json_object_get_string(json_object_array_get_idx(val, 1)));
				break;
			case json_type_boolean:
				fprintf(file, "\t%s = ScratchSetBool(\"%s\");\n", SanitiseScratchNameToC(AsManagedString(key)).data, json_object_get_boolean(json_object_array_get_idx(val, 1)) ? "true" : "false");
				break;
			default:
				printf("Type not implemented!");
				exit(-1);
			}
		}
	}
	{
		json_object_object_foreach(lists, key, val)
		{
			fprintf(file, "\t%s = initialiseList();\n", SanitiseScratchNameToC(AsManagedString(key)).data);
		}
	}

	fprintf(file, "}\n\n");

	int indentation = 0;

#define PRINT_INDENTATION for(int qx = 0; qx < indentation; qx++) { fprintf(file, "\t"); }

	for (int i = 0; i < functions.length; i++)
	{
		fprintf(file, "void %s(", functions.data[i].proccode.data);
		for (int j = 0; j < functions.data[i].args - 1; j++) 
		{
			fprintf(file, "ScratchValue %s, ", functions.data[i].argids[j].data);
		}
		if (functions.data[i].args > 0)
		{
			fprintf(file, "ScratchValue %s", functions.data[i].argids[functions.data[i].args - 1].data);
		}
		fprintf(file, ");\n");
	}

	fprintf(file, "\n");

	for (int i = 0; i < functions.length; i++) 
	{
		PRINT_INDENTATION fprintf(file, "void %s(", functions.data[i].proccode.data);
		for (int j = 0; j < functions.data[i].args - 1; j++)
		{
			fprintf(file, "ScratchValue %s, ", functions.data[i].argids[j].data);
		}
		if (functions.data[i].args > 0)
		{
			fprintf(file, "ScratchValue %s", functions.data[i].argids[functions.data[i].args - 1].data);
		}
		PRINT_INDENTATION fprintf(file, ") \n{\n");
		if (functions.data[i].warp) 
		{
			fprintf(file, "#define YIELD\n");
		}
		indentation++;
		for (int j = 0; j < functions.data[i].blocks.length; j++) 
		{
#define THIS functions.data[i].blocks.data[j]

			if (strcmp(THIS.opcode.data, "control_repeat") == 0)
			{
				PRINT_INDENTATION fprintf(file, "for(int i%i = 0; i%i < (int)ScratchVarGetDouble(%s); i%i++)\n", indentation, indentation, GetArg(THIS.argtypes[0], THIS.argdata[0], blocks).data, indentation);
				PRINT_INDENTATION fprintf(file, "{\n");
				indentation++;
			}
			else if (strcmp(THIS.opcode.data, "control_if") == 0) 
			{
				PRINT_INDENTATION fprintf(file, "if(ScratchVarGetBool(%s))\n", GetArg(THIS.argtypes[0], THIS.argdata[0], blocks).data);
				PRINT_INDENTATION fprintf(file, "{\n");
				indentation++;
			}
			else if (strcmp(THIS.opcode.data, "control_repeat_until") == 0)
			{
				PRINT_INDENTATION fprintf(file, "while(!(ScratchVarGetBool(%s)))\n", GetArg(THIS.argtypes[0], THIS.argdata[0], blocks).data);
				PRINT_INDENTATION fprintf(file, "{\n");
				indentation++;
			}
			else if (strcmp(THIS.opcode.data, "control_while") == 0)
			{
				PRINT_INDENTATION fprintf(file, "while(ScratchVarGetBool(%s))\n", GetArg(THIS.argtypes[0], THIS.argdata[0], blocks).data);
				PRINT_INDENTATION fprintf(file, "{\n");
				indentation++;
			}
			else if (strcmp(THIS.opcode.data, "control_forever") == 0)
			{
				PRINT_INDENTATION fprintf(file, "while(1)\n");
				PRINT_INDENTATION fprintf(file, "{\n");
				indentation++;
			}
			else if (strcmp(THIS.opcode.data, "control_loop_end") == 0)
			{
				PRINT_INDENTATION fprintf(file, "YIELD\n");
				indentation--;
				PRINT_INDENTATION fprintf(file, "}\n");
			}
			else if (strcmp(THIS.opcode.data, "control_if_end") == 0)
			{
				indentation--;
				PRINT_INDENTATION fprintf(file, "}\n");
			}
			else if (strcmp(THIS.opcode.data, "control_else") == 0)
			{
				indentation--;
				PRINT_INDENTATION fprintf(file, "}\n");
				PRINT_INDENTATION fprintf(file, "else\n");
				PRINT_INDENTATION fprintf(file, "{\n");
				indentation++;
			}
			else
			{
				PRINT_INDENTATION fprintf(file, "%s\n", LineToBlock(THIS, blocks, true).data);
			}

#undef THIS
		}
		if (functions.data[i].warp)
		{
			fprintf(file, "#define YIELD TRUE_YIELD\n");
		}
		indentation--;
		PRINT_INDENTATION fprintf(file, "}\n\n");

	}

	fclose(file);
}