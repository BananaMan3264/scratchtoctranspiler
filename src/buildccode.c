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
		return SafeStringMerge(SafeStringMerge(AsManagedString("ScratchSetDouble("), argdata.text), AsManagedString(")"));

	case ArgType_String:
		return SafeStringMerge(SafeStringMerge(AsManagedString("ScratchSetString(\""), argdata.text), AsManagedString("\")"));

	case ArgType_Variable:
		return argdata.text;
	}
}

char* GetFullProgram(struct json_object* variables, vecFunction functions, struct json_object* blocks)
{
	FILE* file = fopen("../../../output/output.c", "w");

	fprintf(file, "#define YIELD Yield();\n#include \"runtime/scratch.h\"\n#include \"runtime/motion.h\"\n#include \"runtime/looks.h\"\n#include \"runtime/operators.h\"");
	fprintf(file, "\n#include \"runtime/control.h\"\n#include \"runtime/sensing.h\"\n\n");
	{
		json_object_object_foreach(variables, key, val)
		{
			switch (json_object_get_type(json_object_array_get_idx(val, 1)))
			{
			case json_type_int:
				fprintf(file, "ScratchValue %s;\n", SanitiseScratchNameToC(AsManagedString(key)).data);
				break;
			case json_type_double:
				fprintf(file, "ScratchValue %s;\n", SanitiseScratchNameToC(AsManagedString(key)).data);
				break;
			case json_type_string:
				fprintf(file, "ScratchValue %s;\n", SanitiseScratchNameToC(AsManagedString(key)).data);
				break;
			default:
				printf("Type not implemented!");
				exit(-1);
			}
		}
	}
	fprintf(file, "\nvoid Init()\n{");
	{
		json_object_object_foreach(variables, key, val)
		{
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
			default:
				printf("Type not implemented!");
				exit(-1);
			}
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
		indentation--;
		PRINT_INDENTATION fprintf(file, "}\n\n");

	}

	fclose(file);
}