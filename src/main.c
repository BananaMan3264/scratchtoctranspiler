#include <stdio.h>
#include <string.h>
#include <json-c/json.h>
#include <stdbool.h>
#include "std_vector.h"
#include "types.h"
#include "parsejson.h"
#include "util.h"
#include "buildccode.h"

int main()
{
	FILE* json = fopen("../../../../scratch/Project/project.json", "r");
	if (json == NULL)
	{
		printf("Error opening file - File could not be found!\n");
		exit(-1);
	}

	fseek(json, 0, SEEK_END);
	size_t bufferSize = ftell(json);
	fseek(json, 0, SEEK_SET);

	if (bufferSize < 0)
	{
		printf("Error opening file - file size could not be ascertained!\n");
		exit(-1);
	}
	if (bufferSize == 0)
	{
		printf("Error opening file - file was empty!");
		exit(-1);
	}

	char* text = malloc(bufferSize); if (!text) { printf("Malloc error!"); exit(-1); }

	if (text == NULL)
	{
		printf("Malloc Error.");
		exit(-1);
	}

	fread(text, 1, bufferSize, json);

	struct json_object* project = json_tokener_parse(text);

	struct json_object* blocks = json_object_object_get(json_object_array_get_idx(json_object_object_get(project, "targets"), 1), "blocks");

	vecScratchBlock lines = ParseText(blocks);

	//int jEk@4 | i[#Fk ? (8x)AV. - my variable a;

	//for (int i = 0; i < lines.length; i++) 
	//{
	//	ScratchBlock sb = lines.data[i];
	//	printf("Id: %s\nOpcode: %s\nNext: %s\nParent: %s\n", sb.id.data, sb.opcode.data, sb.next.data, sb.previous.data);
	//	for (int j = 0; j < sb.args; j++)
	//	{
	//		switch (sb.argtypes[j])
	//		{
	//		case ArgType_Pointer:
	//			printf("\tBlock pointer: %s\n", sb.argdata[j].text.data);
	//			break;
	//		case ArgType_Text:
	//			printf("\tString: %s\n", sb.argdata[j].text.data);
	//			break;
	//		}
	//	}
	//	printf("\n");
	//}

	GetFullProgram(lines, json_object_object_get(json_object_array_get_idx(json_object_object_get(project, "targets"), 0), "variables"));

	return 0;
}