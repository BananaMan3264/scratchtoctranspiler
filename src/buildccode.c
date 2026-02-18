#include <stdio.h>
#include <string.h>
#include <json-c/json.h>
#include <stdbool.h>
#include <sys/stat.h>
#include "std_vector.h"
#include "types.h"
#include "util.h"
#include "parsejson.h"

#define DEG_TO_RAD 0.0174532925199

extern char* sprite_index;

typedef struct return_vals 
{
	String double_return;
	String string_return;
	String bool_return;
	String scratch_return;
} return_vals;

#define RETV(dbl,str,bl,scr) (return_vals){dbl, str, bl, scr}

#define MERGE3(a,b,c) SafeStringMerge(SafeStringMerge(a,b),c)

return_vals GetArg(int argtype, ScratchArgData argdata, struct json_object* blocks);

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

#define MERGE_OP(start,val,middle,val2,end) MERGE3(AsManagedString(start),val,MERGE3(AsManagedString(middle),val2,AsManagedString(end)))

#define DEF_2DOUBLE_OPERATOR(opc, id, middle)													\
if (strcmp(sb.opcode.data, id) == 0)															\
{																								\
	String a = GetArg(sb.argtypes[0], sb.argdata[0], blocks).double_return;						\
	String b = GetArg(sb.argtypes[1], sb.argdata[1], blocks).double_return;						\
																								\
	return RETV(MERGE_OP("("opc"((", a, middle, b, ")))"),										\
		MERGE_OP("ScratchVarGetString(ScratchSetDouble("opc"((", a, middle, b, "))))"),			\
		MERGE_OP("ScratchVarGetBool(ScratchSetDouble("opc"((", a, middle, b, "))))"),			\
		MERGE_OP("ScratchSetDouble("opc"((", a, middle, b, ")))"));								\
}

#define DEF_1DOUBLE_OPERATOR(opc, id)																			\
if (strcmp(sb.opcode.data, id) == 0)																			\
{																												\
	String a = GetArg(sb.argtypes[0], sb.argdata[0], blocks).double_return;										\
	return RETV(MERGE3(AsManagedString("("opc"(("), a, AsManagedString(")))")),									\
		MERGE3(AsManagedString("ScratchVarGetString(ScratchSetDouble("opc"(("), a, AsManagedString("))))")),	\
		MERGE3(AsManagedString("ScratchVarGetBool(ScratchSetDouble("opc"(("), a, AsManagedString("))))")),		\
		MERGE3(AsManagedString("ScratchSetDouble("opc"(("), a, AsManagedString(")))")));						\
}

#define DEF_0DOUBLE_OPERATOR(opc, id)																			\
if (strcmp(sb.opcode.data, id) == 0)																			\
{																												\
	return RETV((AsManagedString("("opc"())")),																	\
		(AsManagedString("ScratchVarGetString(ScratchSetDouble("opc"()))")),									\
		(AsManagedString("ScratchVarGetBool(ScratchSetDouble("opc"()))")),										\
		(AsManagedString("ScratchSetDouble("opc"())")));														\
}

#define DEF_1DOUBLE_BLOCK(opc, id)														\
if (strcmp(sb.opcode.data, id) == 0)													\
{																						\
	String a = GetArg(sb.argtypes[0], sb.argdata[0], blocks).double_return;				\
	return RETV(AsManagedString(""), AsManagedString(""), AsManagedString(""),			\
				MERGE3(AsManagedString(""opc"("), a, AsManagedString(");")),			\
		);																				\
}		

#define DEF_3DOUBLE_BLOCK(opc, id)														\
if (strcmp(sb.opcode.data, id) == 0)													\
{																						\
	String a = GetArg(sb.argtypes[0], sb.argdata[0], blocks).double_return;				\
	String b = GetArg(sb.argtypes[1], sb.argdata[1], blocks).double_return;				\
	String c = GetArg(sb.argtypes[2], sb.argdata[2], blocks).double_return;				\
																						\
	return RETV(AsManagedString(""), AsManagedString(""), AsManagedString(""),			\
		MERGE_OP(""opc"(", a, ", ", MERGE3(b, AsManagedString(", "), c), ");"));		\
}

#define DEF_2DOUBLE_BLOCK(opc, id)														\
if (strcmp(sb.opcode.data, id) == 0)													\
{																						\
	String a = GetArg(sb.argtypes[0], sb.argdata[0], blocks).double_return;				\
	String b = GetArg(sb.argtypes[1], sb.argdata[1], blocks).double_return;				\
																						\
	return RETV(AsManagedString(""), AsManagedString(""), AsManagedString(""),			\
		MERGE_OP(""opc"(", a, ", ", b, ");"));											\
}

#define DEF_2DOUBLE_SCRATCH_BLOCK(opc, id)												\
if (strcmp(sb.opcode.data, id) == 0)													\
{																						\
	String a = GetArg(sb.argtypes[0], sb.argdata[0], blocks).double_return;				\
	String b = GetArg(sb.argtypes[1], sb.argdata[1], blocks).scratch_return;			\
																						\
	return RETV(AsManagedString(""), AsManagedString(""), AsManagedString(""),			\
		MERGE_OP(""opc"(", a, ", ", b, ");"));											\
}


return_vals LineToBlock(ScratchBlock sb, struct json_object* blocks, bool top)
{
		 DEF_2DOUBLE_OPERATOR("", "operator_add", ") + (")
	else DEF_2DOUBLE_OPERATOR("", "operator_subtract", ") - (")
	else DEF_2DOUBLE_OPERATOR("", "operator_multiply", ") * (")
	else DEF_2DOUBLE_OPERATOR("", "operator_divide", ") / (double)(")
	else DEF_2DOUBLE_OPERATOR("operator_random", "operator_random", "), (")
	else DEF_1DOUBLE_BLOCK("motion_movesteps", "motion_movesteps")
	else DEF_1DOUBLE_BLOCK("motion_turnright", "motion_turnright")
	else DEF_1DOUBLE_BLOCK("motion_turnleft", "motion_turnleft")
	else DEF_2DOUBLE_BLOCK("motion_gotoxy", "motion_gotoxy")
	else DEF_2DOUBLE_SCRATCH_BLOCK("motion_glideto", "motion_glideto")
	else DEF_1DOUBLE_BLOCK("motion_changexby", "motion_changexby")
	else DEF_1DOUBLE_BLOCK("motion_setx", "motion_setx")
	else DEF_1DOUBLE_BLOCK("motion_changeyby", "motion_changeyby")
	else DEF_1DOUBLE_BLOCK("motion_sety", "motion_sety")
	else DEF_0DOUBLE_OPERATOR("motion_xposition", "motion_xposition")
	else DEF_0DOUBLE_OPERATOR("motion_yposition", "motion_yposition")
	else DEF_0DOUBLE_OPERATOR("motion_direction", "motion_direction")
	else DEF_3DOUBLE_BLOCK("motion_glidesecstoxy", "motion_glidesecstoxy")

	String str;

	str = SafeStringMerge(sb.opcode, AsManagedString("("));
	for (int i = 0; i < sb.args - 1; i++)
	{
		str = SafeStringMerge(str, GetArg(sb.argtypes[i], sb.argdata[i], blocks).scratch_return);
		str = SafeStringMerge(str, AsManagedString(", "));
	}
	if (sb.args != 0)
	{
		int idx = sb.args - 1;
		String c = GetArg(sb.argtypes[idx], sb.argdata[idx], blocks).scratch_return;
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
	return RETV(MERGE3(AsManagedString("ScratchVarGetDouble("), str, AsManagedString(")")),
				MERGE3(AsManagedString("ScratchVarGetString("), str, AsManagedString(")")),
				MERGE3(AsManagedString("ScratchVarGetBool("), str, AsManagedString(")")),
				str);
}

return_vals GetArg(int argtype, ScratchArgData argdata, struct json_object* blocks)
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
		if (strlen(argdata.text.data) == 0)
		{
			return RETV(AsManagedString("0"), AsManagedString("\"0\""), AsManagedString("false"), AsManagedString("ScratchSetDouble(0)"));
		}
		if (strcmp(argdata.text.data, "infinity") == 0) 
		{
			return RETV(AsManagedString("INFINITY"), AsManagedString("\"INFINITY\""), AsManagedString("true"), AsManagedString("ScratchSetDouble(INFINITY)"));
		}
		return RETV(argdata.text,
					MERGE3(AsManagedString("ScratchVarGetString(ScratchSetDouble("), argdata.text, AsManagedString("))")),
					MERGE3(AsManagedString("ScratchVarGetBool(ScratchSetDouble("), argdata.text, AsManagedString("))")),
					MERGE3(AsManagedString("ScratchSetDouble("), argdata.text, AsManagedString(")")));

	case ArgType_String:
		{
			char* text = argdata.text.data;
			char* endptr;

			double value = strtod(text, &endptr);

			if (endptr == text) {
				return RETV(MERGE3(AsManagedString("ScratchVarGetString(ScratchSetString(\""), argdata.text, AsManagedString("\"))")),
							MERGE3(AsManagedString("\""),argdata.text, AsManagedString("\"")),
							MERGE3(AsManagedString("ScratchVarGetBool(ScratchSetString(\""), argdata.text, AsManagedString("\"))")),
							MERGE3(AsManagedString("ScratchSetString(\""), argdata.text, AsManagedString("\")")));
			}
			else {
				if (strcmp(argdata.text.data, "infinity") == 0)
				{
					return RETV(AsManagedString("INFINITY"), AsManagedString("\"INFINITY\""), AsManagedString("true"), AsManagedString("ScratchSetDouble(INFINITY)"));
				}
				return RETV(argdata.text,
							MERGE3(AsManagedString("ScratchVarGetString(ScratchSetDouble("), argdata.text, AsManagedString("))")),
							MERGE3(AsManagedString("ScratchVarGetBool(ScratchSetDouble("), argdata.text, AsManagedString("))")),
							MERGE3(AsManagedString("ScratchSetDouble("), argdata.text, AsManagedString(")")));
			}

		}
	case ArgType_Variable:
		return RETV(MERGE3(AsManagedString("ScratchVarGetDouble("), argdata.text, AsManagedString(")")),
					MERGE3(AsManagedString("ScratchVarGetString("), argdata.text, AsManagedString(")")),
					MERGE3(AsManagedString("ScratchVarGetBool("), argdata.text, AsManagedString(")")),
					argdata.text);
	}
}

void PrintData(struct json_object* targets) 
{
#define SetAllZeros()																						\
																											\
for (int i = 0; i < sprites_count; i++)																		\
{																											\
	fprintf(file, "0.0");																					\
	if (i != sprites_count - 1)																				\
	{																										\
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
		json_object* this = json_object_object_get(json_object_array_get_idx(targets, i), "direction"); 
		if (json_object_get_type(this) == json_type_null)
		{
			fprintf(file, "0.0");
		}
		else 
		{
			double d = json_object_get_double(this); fprintf(file, "%f", (d - 90) * DEG_TO_RAD);
		} if (i != sprites_count - 1) {
			fprintf(file, ", ");
		}
	} fprintf(file, " };\n");;

	fprintf(file, "bool scratch_" "looks_hidden" "[] = { "); 
	for (int i = 0; i < sprites_count; i++) 
	{
		json_object* this = json_object_object_get(json_object_array_get_idx(targets, i), "visible"); 
		if (json_object_get_type(this) == json_type_null) 
		{
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
		if (i != sprites_count - 1) 
		{
			fprintf(file, ", ");
		}
	} 
	fprintf(file, " };\n");

	fprintf(file, "int scratch_motion_SpriteRotStyle[] = { ");
	for (int i = 0; i < sprites_count; i++) {
		json_object* this = json_object_object_get(json_object_array_get_idx(targets, i), "size");
		if (json_object_get_type(this) == json_type_null) 
		{
			fprintf(file, "RotStyle_allaround");
		}
		else 
		{
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
	for (int i = 0; i < sprites_count; i++) 
	{
		json_object* this = json_object_object_get(json_object_array_get_idx(targets, i), "currentCostume");
		fprintf(file, "%i", json_object_get_int(this));
		if (i != sprites_count - 1) 
		{
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
		if (i != sprites_count - 1) 
		{
			fprintf(file, ", ");
		}
	}
	fprintf(file, " };\n");

	fprintf(file, "char* scratch_looks_CostumeNames[SPRITES][MAX_COSTUME_LENGTH] = {\n");
	for (int i = 0; i < sprites_count; i++) 
	{
		fprintf(file, "\t{ ");
		for (int j = 0; j < max_costume_count; j++) 
		{
			json_object* this = json_object_object_get(json_object_array_get_idx(targets, i), "costumes");
			json_object* this_name = json_object_object_get(json_object_array_get_idx(this, j),"name");
			if (json_object_get_type(this_name) != json_type_null) 
			{
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
		if (i != sprites_count - 1) 
		{
			fprintf(file, " },\n");
		}
		else 
		{
			fprintf(file, " }\n");
		}
	}
	fprintf(file, " };\n");

	bool** isPNG = malloc(sizeof(bool*) * sprites_count); if (!isPNG) { printf("Malloc error!"); exit(-1); }

	for (int i = 0; i < sprites_count; i++) 
	{
		isPNG[i] = malloc(sizeof(bool) * max_costume_count); if (!isPNG[i]) { printf("Malloc error!"); exit(-1); }
	}

	fprintf(file, "char* scratch_looks_CostumeFiles[SPRITES][MAX_COSTUME_LENGTH] = {\n");
	for (int i = 0; i < sprites_count; i++) {
		fprintf(file, "\t{ ");
		for (int j = 0; j < max_costume_count; j++) {
			json_object* this = json_object_object_get(json_object_array_get_idx(targets, i), "costumes");
			json_object* this_name = json_object_object_get(json_object_array_get_idx(this, j), "assetId");
			if (json_object_get_type(this_name) != json_type_null) {

				char data_this[70];

				snprintf(data_this, 70, "../../../scratch/Project/%s.svg", json_object_get_string(this_name));

				struct stat buffer;

				if (stat(data_this, &buffer) == 0)
				{
					fprintf(file, "\"%s.svg\"", json_object_get_string(this_name));
					isPNG[i][j] = false;
				}
				else 
				{
					fprintf(file, "\"%s.png\"", json_object_get_string(this_name));
					isPNG[i][j] = true;
				}
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
				if (isPNG[i][j])
				{
					fprintf(file, "%f", json_object_get_double(this_name) / 2);
				}
				else 
				{
					fprintf(file, "%f", json_object_get_double(this_name));
				}
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
				if (isPNG[i][j])
				{
					fprintf(file, "%f", json_object_get_double(this_name) / 2);
				}
				else
				{
					fprintf(file, "%f", json_object_get_double(this_name));
				}
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

	for (int i = 0; i < sprites_count; i++)
	{
		free(isPNG[i]);
	}
	free(isPNG);

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

char* GetFullProgram(FILE* header_file, FILE* source_file, FILE* scheduler, struct json_object* variables, struct json_object* lists, vecFunction functions, struct json_object* blocks, int working_index)
{

	fprintf(header_file, "void _%s_Init();\n", sprite_index);
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

	int a = json_object_get_type(lists);

	fprintf(source_file, "\nvoid _%s_Init()\n{\n", sprite_index);
	{
		json_object_object_foreach(variables, key, val)
		{
			int type = json_object_get_type(json_object_array_get_idx(val, 1));
			switch (json_object_get_type(json_object_array_get_idx(val, 1)))
			{
			case json_type_int:
				fprintf(source_file, "\t%s = ScratchSetDouble(%i);\n", SanitiseScratchNameToC(AsManagedString(json_object_get_string(json_object_array_get_idx(val, 0)))).data, json_object_get_int(json_object_array_get_idx(val, 1)));
				break;
			case json_type_double:
				fprintf(source_file, "\t%s = ScratchSetDouble(%f);\n", SanitiseScratchNameToC(AsManagedString(json_object_get_string(json_object_array_get_idx(val, 0)))).data, json_object_get_double(json_object_array_get_idx(val, 1)));
				break;
			case json_type_string:
				fprintf(source_file, "\t%s = ScratchSetString(\"%s\");\n", SanitiseScratchNameToC(AsManagedString(json_object_get_string(json_object_array_get_idx(val, 0)))).data, json_object_get_string(json_object_array_get_idx(val, 1)));
				break;
			case json_type_boolean:
				fprintf(source_file, "\t%s = ScratchSetBool(\"%s\");\n", SanitiseScratchNameToC(AsManagedString(json_object_get_string(json_object_array_get_idx(val, 0)))).data, json_object_get_boolean(json_object_array_get_idx(val, 1)) ? "true" : "false");
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
			fprintf(source_file, "\t%s = initialiseList();\n", SanitiseScratchNameToC(AsManagedString(json_object_get_string(json_object_array_get_idx(val, 0)))).data);
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
		indentation++;
		PRINT_INDENTATION fprintf(source_file, "activeSprite = %i;\n", working_index);
		if (functions.data[i].opcode == procedures_prototype)
		{
			if (functions.data[i].warp)
			{
				fprintf(source_file, "#define YIELD\n");
			}
			else
			{
				fprintf(source_file, "#define YIELD FUNCTION_YIELD\n");
			}
		}
		for (int j = 0; j < functions.data[i].blocks.length; j++) 
		{
#define THIS functions.data[i].blocks.data[j]

			if (strcmp(THIS.opcode.data, "control_repeat") == 0)
			{
				String arg_this = GetArg(THIS.argtypes[0], THIS.argdata[0], blocks).scratch_return;
				if ((strlen(arg_this.data) > strlen("ScratchSetDouble") && strncmp(arg_this.data, "ScratchSetDouble", 16) == 0)) 
				{
					PRINT_INDENTATION fprintf(source_file, "for(int i%i = 0; i%i < (int)(%s); i%i++)\n", indentation, indentation, arg_this.data + 16, indentation);
				}
				else
				{
					PRINT_INDENTATION fprintf(source_file, "for(int i%i = 0; i%i < (int)ScratchVarGetDouble(%s); i%i++)\n", indentation, indentation, arg_this.data, indentation);
				}
				PRINT_INDENTATION fprintf(source_file, "{\n");
				indentation++;
			}
			else if (strcmp(THIS.opcode.data, "control_if") == 0) 
			{
				PRINT_INDENTATION fprintf(source_file, "if(ScratchVarGetBool(%s))\n", GetArg(THIS.argtypes[0], THIS.argdata[0], blocks).scratch_return.data);
				PRINT_INDENTATION fprintf(source_file, "{\n");
				indentation++;
			}
			else if (strcmp(THIS.opcode.data, "control_repeat_until") == 0)
			{
				PRINT_INDENTATION fprintf(source_file, "while(!(ScratchVarGetBool(%s)))\n", GetArg(THIS.argtypes[0], THIS.argdata[0], blocks).scratch_return.data);
				PRINT_INDENTATION fprintf(source_file, "{\n");
				indentation++;
			}
			else if (strcmp(THIS.opcode.data, "control_while") == 0)
			{
				PRINT_INDENTATION fprintf(source_file, "while(ScratchVarGetBool(%s))\n", GetArg(THIS.argtypes[0], THIS.argdata[0], blocks).scratch_return.data);
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
				PRINT_INDENTATION fprintf(source_file, "%s\n", LineToBlock(THIS, blocks, true).scratch_return.data);
			}

#undef THIS
		}
		fprintf(source_file, "#define YIELD TRUE_YIELD\n");
		if (functions.data[i].opcode != procedures_prototype)
		{
			PRINT_INDENTATION fprintf(source_file, "END_THREAD\n");
		}
		indentation--;
		PRINT_INDENTATION fprintf(source_file, "}\n\n");

	}
}