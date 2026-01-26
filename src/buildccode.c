#include <stdio.h>
#include <string.h>
#include <json-c/json.h>
#include <stdbool.h>
#include "std_vector.h"
#include "types.h"
#include "util.h"

String GetArg(int argtype, ScratchArgData argdata, vecScratchBlock lines);

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

String LineToBlock(int index, vecScratchBlock lines, bool top)
{
	String str = SafeStringMerge(lines.data[index].opcode, AsManagedString("("));
	for (int i = 0; i < lines.data[index].args - 1; i++)
	{
		str = SafeStringMerge(str, GetArg(lines.data[index].argtypes[i], lines.data[index].argdata[i], lines));
		str = SafeStringMerge(str, AsManagedString(", "));
	}
	if (lines.data[index].args != 0)
	{
		str = SafeStringMerge(str, GetArg(lines.data[index].argtypes[lines.data[index].args - 1], lines.data[index].argdata[lines.data[index].args - 1], lines));
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

String GetArg(int argtype, ScratchArgData argdata, vecScratchBlock lines)
{
	switch (argtype) 
	{
	case ArgType_Pointer:
		return LineToBlock(GetIndexOfBlockById(argdata.idPointer.data,lines), lines, false);
	
	case ArgType_Number:
	case ArgType_PositiveNumber:
	case ArgType_NegativeNumber:
	case ArgType_Integer:
	case ArgType_Angle:
		return argdata.text;

	case ArgType_String:
		return SafeStringMerge(SafeStringMerge(AsManagedString("\""), argdata.text), AsManagedString("\""));
	}
}

char* GetFullProgram(vecScratchBlock lines)
{
	FILE* file = fopen("../../../../output/output.c", "w");

	fprintf(file, "#include<scratch.h>\nint main() {\n\tstart();\n}\n");

	if (file == NULL) {
		perror("Error opening file");
		return 1;
	}


	int index = GetFirstWhenFlagClicked(lines);

	int indentation = 0;

	while (index != -1)
	{
		for (int i = 0; i < indentation; i++)
		{
			fprintf(file, "\t");
		}
		if (strcmp(lines.data[index].opcode.data, "event_whenflagclicked") == 0)
		{
			fprintf(file, "void start() \n{\n");
			indentation++;
		}
		else 
		{
			fprintf(file, "%s\n", LineToBlock(index, lines, true).data);
		}
		index = GetIndexOfBlockById(lines.data[index].next.data, lines);
	}
	while (indentation > 0) 
	{
		indentation--;
		for (int i = 0; i < indentation; i++)
		{
			fprintf(file, "\t");
		}
		fprintf(file, "}\n");
	}

	fclose(file);
}