#include <stdio.h>
#include <string.h>
#include <json-c/json.h>
#include <stdbool.h>
#include "std_vector.h"
#include "types.h"
#include "util.h"
#include "parsejson.h"

#define DEG_TO_RAD 0.0174532925199

extern char* sprite_index;

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

	FILE* file = fopen("../../../output/generated/sprite_data.c", "w");

	int sprites_count = json_object_array_length(targets);

	fprintf(file, "#include <stdbool.h>\n#include <stdlib.h>\n#include \"../runtime/motion.h\"\n#include \"../sprite_data.h\"\n\n");

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

	fprintf(file, "double scratch_looks_RotationCentreX[SPRITES][MAX_COSTUME_LENGTH] = {\n");
	for (int i = 0; i < sprites_count; i++) {
		fprintf(file, "\t{ ");
		for (int j = 0; j < max_costume_count; j++) {
			json_object* this = json_object_object_get(json_object_array_get_idx(targets, i), "costumes");
			json_object* this_name = json_object_object_get(json_object_array_get_idx(this, j), "rotationCenterX");
			if (json_object_get_type(this_name) != json_type_null) {
				fprintf(file, "%f", json_object_get_double(this_name));
			}
			else
			{
				fprintf(file, "0.0");
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

	fprintf(file, "double scratch_looks_RotationCentreY[SPRITES][MAX_COSTUME_LENGTH] = {\n");
	for (int i = 0; i < sprites_count; i++) {
		fprintf(file, "\t{ ");
		for (int j = 0; j < max_costume_count; j++) {
			json_object* this = json_object_object_get(json_object_array_get_idx(targets, i), "costumes");
			json_object* this_name = json_object_object_get(json_object_array_get_idx(this, j), "rotationCenterY");
			if (json_object_get_type(this_name) != json_type_null) {
				fprintf(file, "%f", json_object_get_double(this_name));
			}
			else
			{
				fprintf(file, "0.0");
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

	int max_sound_count = 0;

	fprintf(file, "int scratch_sound_SoundEffectCounts[] = { ");
	for (int i = 0; i < sprites_count; i++) {
		json_object* this = json_object_object_get(json_object_array_get_idx(targets, i), "sounds");
		int len = (int)json_object_array_length(this);
		fprintf(file, "%i", len);
		if (len > max_sound_count) { max_sound_count = len; }
		if (i != sprites_count - 1) {
			fprintf(file, ", ");
		}
	}
	fprintf(file, " };\n");

	fprintf(file, "char* scratch_sound_SoundEffectNames[SPRITES][MAX_SOUND_LENGTH] = {\n");
	for (int i = 0; i < sprites_count; i++) {
		fprintf(file, "\t{ ");
		for (int j = 0; j < max_sound_count; j++) {
			json_object* this = json_object_object_get(json_object_array_get_idx(targets, i), "sounds");
			json_object* this_name = json_object_object_get(json_object_array_get_idx(this, j),"name");
			if (json_object_get_type(this_name) != json_type_null) {
				fprintf(file, "\"%s\", ", json_object_get_string(this_name));
			}
			else 
			{
				fprintf(file, "NULL, ");
			}
		}
		fprintf(file, "NULL");
		if (i != sprites_count - 1) {
			fprintf(file, " },\n");
		}
		else 
		{
			fprintf(file, " }\n");
		}
	}
	fprintf(file, " };\n");

	fprintf(file, "char* scratch_sound_SoundEffectFiles[SPRITES][MAX_SOUND_LENGTH] = {\n");
	for (int i = 0; i < sprites_count; i++) {
		fprintf(file, "\t{ ");
		for (int j = 0; j < max_sound_count; j++) {
			json_object* this = json_object_object_get(json_object_array_get_idx(targets, i), "sounds");
			json_object* this_name = json_object_object_get(json_object_array_get_idx(this, j), "assetId");
			if (json_object_get_type(this_name) != json_type_null) {
				fprintf(file, "\"%s.wav\", ", json_object_get_string(this_name));
			}
			else
			{
				fprintf(file, "NULL, ");
			}
		}
		fprintf(file, "NULL");
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

	fprintf(header, "#define SPRITES %i\n#define MAX_COSTUME_LENGTH %i\n#define MAX_SOUND_LENGTH %i", sprites_count, max_costume_count, max_sound_count + 1);

	fclose(header);
}

char* GetFullProgram(FILE* header_file, FILE* source_file, FILE* scheduler, struct json_object* variables, struct json_object* lists, vecFunction functions, struct json_object* blocks)
{

	fprintf(header_file, "void Init_%s_();\n", sprite_index);
	for (int i = 0; i < functions.length; i++)
	{
		fprintf(header_file, "void %s(", functions.data[i].proccode.data);
		for (int j = 0; j < functions.data[i].args - 1; j++)
		{
			fprintf(header_file, "ScratchValue %s, ", functions.data[i].argids[j].data);
		}
		if (functions.data[i].args > 0)
		{
			fprintf(header_file, "ScratchValue %s", functions.data[i].argids[functions.data[i].args - 1].data);
		}
		fprintf(header_file, ");\n");
	}

	{
		json_object_object_foreach(variables, key, val)
		{

			fprintf(source_file, "ScratchValue %s;\n", SanitiseScratchNameToC(AsManagedString(key)).data);
		}
	}

	int a = json_object_get_type(lists);
	{
		json_object_object_foreach(lists, key, val)
		{
			fprintf(source_file, "ScratchList %s;\n", SanitiseScratchNameToC(AsManagedString(key)).data);
		}
	}
	fprintf(source_file, "\nvoid _%s_Init()\n{\n", sprite_index);
	{
		json_object_object_foreach(variables, key, val)
		{
			int type = json_object_get_type(json_object_array_get_idx(val, 1));
			switch (json_object_get_type(json_object_array_get_idx(val, 1)))
			{
			case json_type_int:
				fprintf(source_file, "\t%s = ScratchSetDouble(%i);\n", SanitiseScratchNameToC(AsManagedString(key)).data, json_object_get_int(json_object_array_get_idx(val, 1)));
				break;
			case json_type_double:
				fprintf(source_file, "\t%s = ScratchSetDouble(%f);\n", SanitiseScratchNameToC(AsManagedString(key)).data, json_object_get_double(json_object_array_get_idx(val, 1)));
				break;
			case json_type_string:
				fprintf(source_file, "\t%s = ScratchSetString(\"%s\");\n", SanitiseScratchNameToC(AsManagedString(key)).data, json_object_get_string(json_object_array_get_idx(val, 1)));
				break;
			case json_type_boolean:
				fprintf(source_file, "\t%s = ScratchSetBool(\"%s\");\n", SanitiseScratchNameToC(AsManagedString(key)).data, json_object_get_boolean(json_object_array_get_idx(val, 1)) ? "true" : "false");
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
			fprintf(source_file, "\t%s = initialiseList();\n", SanitiseScratchNameToC(AsManagedString(key)).data);
		}
	}

	fprintf(source_file, "}\n\n");

	int indentation = 0;

#define PRINT_INDENTATION for(int qx = 0; qx < indentation; qx++) { fprintf(source_file, "\t"); }

	for (int i = 0; i < functions.length; i++)
	{
		fprintf(source_file, "void %s(", functions.data[i].proccode.data);
		for (int j = 0; j < functions.data[i].args - 1; j++) 
		{
			fprintf(source_file, "ScratchValue %s, ", functions.data[i].argids[j].data);
		}
		if (functions.data[i].args > 0)
		{
			fprintf(source_file, "ScratchValue %s", functions.data[i].argids[functions.data[i].args - 1].data);
		}
		fprintf(source_file, ");\n");
	}

	fprintf(source_file, "\n");

	for (int i = 0; i < functions.length; i++) 
	{
		PRINT_INDENTATION fprintf(source_file, "void %s(", functions.data[i].proccode.data);
		for (int j = 0; j < functions.data[i].args - 1; j++)
		{
			fprintf(source_file, "ScratchValue %s, ", functions.data[i].argids[j].data);
		}
		if (functions.data[i].args > 0)
		{
			fprintf(source_file, "ScratchValue %s", functions.data[i].argids[functions.data[i].args - 1].data);
		}
		PRINT_INDENTATION fprintf(source_file, ") \n{\n");
		if (functions.data[i].warp) 
		{
			fprintf(source_file, "#define YIELD\n");
		}
		indentation++;
		for (int j = 0; j < functions.data[i].blocks.length; j++) 
		{
#define THIS functions.data[i].blocks.data[j]

			if (strcmp(THIS.opcode.data, "control_repeat") == 0)
			{
				PRINT_INDENTATION fprintf(source_file, "for(int i%i = 0; i%i < (int)ScratchVarGetDouble(%s); i%i++)\n", indentation, indentation, GetArg(THIS.argtypes[0], THIS.argdata[0], blocks).data, indentation);
				PRINT_INDENTATION fprintf(source_file, "{\n");
				indentation++;
			}
			else if (strcmp(THIS.opcode.data, "control_if") == 0) 
			{
				PRINT_INDENTATION fprintf(source_file, "if(ScratchVarGetBool(%s))\n", GetArg(THIS.argtypes[0], THIS.argdata[0], blocks).data);
				PRINT_INDENTATION fprintf(source_file, "{\n");
				indentation++;
			}
			else if (strcmp(THIS.opcode.data, "control_repeat_until") == 0)
			{
				PRINT_INDENTATION fprintf(source_file, "while(!(ScratchVarGetBool(%s)))\n", GetArg(THIS.argtypes[0], THIS.argdata[0], blocks).data);
				PRINT_INDENTATION fprintf(source_file, "{\n");
				indentation++;
			}
			else if (strcmp(THIS.opcode.data, "control_while") == 0)
			{
				PRINT_INDENTATION fprintf(source_file, "while(ScratchVarGetBool(%s))\n", GetArg(THIS.argtypes[0], THIS.argdata[0], blocks).data);
				PRINT_INDENTATION fprintf(source_file, "{\n");
				indentation++;
			}
			else if (strcmp(THIS.opcode.data, "control_forever") == 0)
			{
				PRINT_INDENTATION fprintf(source_file, "while(1)\n");
				PRINT_INDENTATION fprintf(source_file, "{\n");
				indentation++;
			}
			else if (strcmp(THIS.opcode.data, "control_loop_end") == 0)
			{
				PRINT_INDENTATION fprintf(source_file, "YIELD\n");
				indentation--;
				PRINT_INDENTATION fprintf(source_file, "}\n");
			}
			else if (strcmp(THIS.opcode.data, "control_if_end") == 0)
			{
				indentation--;
				PRINT_INDENTATION fprintf(source_file, "}\n");
			}
			else if (strcmp(THIS.opcode.data, "control_else") == 0)
			{
				indentation--;
				PRINT_INDENTATION fprintf(source_file, "}\n");
				PRINT_INDENTATION fprintf(source_file, "else\n");
				PRINT_INDENTATION fprintf(source_file, "{\n");
				indentation++;
			}
			else
			{
				PRINT_INDENTATION fprintf(source_file, "%s\n", LineToBlock(THIS, blocks, true).data);
			}

#undef THIS
		}
		if (functions.data[i].warp)
		{
			fprintf(source_file, "#define YIELD TRUE_YIELD\n");
		}
		if (functions.data[i].opcode != procedures_prototype)
		{
			PRINT_INDENTATION fprintf(source_file, "END_THREAD\n");
		}
		indentation--;
		PRINT_INDENTATION fprintf(source_file, "}\n\n");

	}
}