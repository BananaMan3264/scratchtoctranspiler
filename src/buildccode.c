#include <stdio.h>
#include <string.h>
#include <json-c/json.h>
#include <stdbool.h>
#include "std_vector.h"
#include "types.h"
#include "util.h"
#include "parsejson.h"

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
		return argdata.text;

	case ArgType_String:
		return SafeStringMerge(SafeStringMerge(AsManagedString("\""), argdata.text), AsManagedString("\""));

	case ArgType_Variable:
		return argdata.text;
	}
}

char* GetFullProgram(struct json_object* variables, vecFunction functions, struct json_object* blocks)
{
	FILE* file = fopen("../../../../output/output.c", "w");

	fprintf(file, "#include<scratch.h>\n\n");

	json_object_object_foreach(variables, key, val)
	{
		switch (json_object_get_type(json_object_array_get_idx(val, 1)))
		{
		case json_type_int:
			fprintf(file, "double %s = %i;\n", SanitiseScratchNameToC(AsManagedString(key)).data, json_object_get_int(json_object_array_get_idx(val, 1)));
			break;
		case json_type_double:
			fprintf(file, "double %s = %f;\n", SanitiseScratchNameToC(AsManagedString(key)).data, json_object_get_double(json_object_array_get_idx(val, 1)));
			break;
		case json_type_string:
			fprintf(file, "char*  %s = \"%s\";\n", SanitiseScratchNameToC(AsManagedString(key)).data, json_object_get_string(json_object_array_get_idx(val, 1)));
			break;
		default:
			printf("Type not implemented!");
			exit(-1);
		}
	}

	fprintf(file, "\n");

	int indentation = 0;

#define PRINT_INDENTATION for(int qx = 0; qx < indentation; qx++) { fprintf(file, "\t"); }

	for (int i = 0; i < functions.length; i++) 
	{
		PRINT_INDENTATION fprintf(file, "void %s(", functions.data[i].proccode.data);
		PRINT_INDENTATION fprintf(file, ") \n{\n");
		indentation++;
		for (int j = 0; j < functions.data[i].blocks.length; j++) 
		{
#define THIS functions.data[i].blocks.data[j]

			if (strcmp(THIS.opcode.data, "control_repeat") == 0)
			{
				PRINT_INDENTATION fprintf(file, "for(int i%i = 0; i%i < %s; i%i++)\n", indentation, indentation, GetArg(THIS.argtypes[0], THIS.argdata[0], blocks).data, indentation);
				PRINT_INDENTATION fprintf(file, "{\n");
				indentation++;
			}
			else if (strcmp(THIS.opcode.data, "control_if") == 0) 
			{
				PRINT_INDENTATION fprintf(file, "if(%s)\n", GetArg(THIS.argtypes[0], THIS.argdata[0], blocks).data);
				PRINT_INDENTATION fprintf(file, "{\n");
				indentation++;
			}
			else if (strcmp(THIS.opcode.data, "control_repeat_until") == 0)
			{
				PRINT_INDENTATION fprintf(file, "while(!(%s))\n", GetArg(THIS.argtypes[0], THIS.argdata[0], blocks).data);
				PRINT_INDENTATION fprintf(file, "{\n");
				indentation++;
			}
			else if (strcmp(THIS.opcode.data, "control_while") == 0)
			{
				PRINT_INDENTATION fprintf(file, "while(%s)\n", GetArg(THIS.argtypes[0], THIS.argdata[0], blocks).data);
				PRINT_INDENTATION fprintf(file, "{\n");
				indentation++;
			}
			else if (strcmp(THIS.opcode.data, "control_forever") == 0)
			{
				PRINT_INDENTATION fprintf(file, "while(1)\n");
				PRINT_INDENTATION fprintf(file, "{\n");
				indentation++;
			}
			else if (strcmp(THIS.opcode.data, "control_repeat_end") == 0)
			{
				indentation--;
				PRINT_INDENTATION fprintf(file, "}\n");
			}
			else
			{
				PRINT_INDENTATION fprintf(file, "%s\n", LineToBlock(THIS, blocks, true).data);
			}

#undef THIS
		}
		indentation--;
		PRINT_INDENTATION fprintf(file, "}\n\n");

	}

	fclose(file);
}