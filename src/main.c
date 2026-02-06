#include <stdio.h>
#include <string.h>
#include <json-c/json.h>
#include <stdbool.h>
#include "std_vector.h"
#include "types.h"
#include "parsejson.h"
#include "util.h"
#include "buildccode.h"

int main(int argc, char**argv)
{	
	//if (argc < 2) {
	//	printf("Error: no arguments supplied!\n");
	//	exit(-1);
	//}
	//
	//const char* filePath = argv[1];
	//FILE* json = fopen(filePath, "r");
	//if (json == NULL)
	//{
	//	printf("Error opening file - File could not be found!\n");
	//	exit(-1);
	//}

	FILE* json = fopen("../../../scratch/Project/project.json", "r");

	if (!json)
	{
		printf("Error opening file - file could not be opened!\n");
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

	vecFunction functions = ParseText(blocks);

	for (int i = 0; i < functions.length; i++) 
	{
		printf("Function: %s\n",functions.data[i].proccode.data);
		for (int j = 0; j < functions.data[i].blocks.length; j++) 
		{
#define this functions.data[i].blocks.data[j]
			printf("\tBlock: %s\n\tArgs: %i\n", this.opcode.data, this.args);
#undef this
		}
		printf("\n");
	}

	struct json_object* vars = json_object_object_get(json_object_array_get_idx(json_object_object_get(project, "targets"), 0), "variables");

	PrintData(json_object_object_get(project, "targets"));

	GetFullProgram(vars, json_object_object_get(json_object_array_get_idx(json_object_object_get(project, "targets"), 0), "lists"), functions, blocks);

	return 0;
}