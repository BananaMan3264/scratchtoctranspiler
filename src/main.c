#include <stdio.h>
#include <string.h>
#include <json-c/json.h>
#include <stdbool.h>
#include "std_vector.h"

typedef struct ScratchLine 
{
	char* opcode;
	int args;
	char** argsData;
	int indentation;
} ScratchLine;

struct vecScratchLine {
	ScratchLine* data; size_t allocated_size; size_t length; size_t sizeoftype;
} lines;

void PrintScratchLine(ScratchLine line)
{
	printf("%s(",line.opcode);
	for (int i = 0; i < line.args; i++) 
	{
		printf("%s,",line.argsData[i]);
	}
	//printf("%s", line.argsData[line.args - 1]);
	printf(");\n");
}

char* GetArgFromJson(struct json_object* arg) 
{
	printf("%s\n", json_object_to_json_string(arg));

	return NULL;
}

ScratchLine GetScratchLineFromJson(struct json_object* object)
{
	ScratchLine sl;
	sl.opcode = json_object_get_string(json_object_object_get(object, "opcode"));
	sl.args = 0;

	struct json_object* args = json_object_object_get(object, "inputs");

	GetArgFromJson(json_object_object_get(args,"X"));

	return sl;
}

int main()
{
	 
	lines.allocated_size = 8; lines.length = 0; lines.sizeoftype = sizeof(ScratchLine); lines.data = malloc(sizeof(ScratchLine) * lines.allocated_size); if (!lines.data) {
		exit(-1);
	}
	
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

	char* text = SafeMalloc(bufferSize);

	if (text == NULL)
	{
		printf("Malloc Error.");
		exit(-1);
	}

	fread(text, 1, bufferSize, json);

	struct json_object* project = json_tokener_parse(text);

	struct json_object* blocks = json_object_object_get(json_object_array_get_idx(json_object_object_get(project, "targets"), 1), "blocks");
	
	char* next = NULL;

	json_object_object_foreach(blocks, key, val)
	{
		if (strcmp(json_object_get_string(json_object_object_get(val, "opcode")),"event_whenflagclicked") == 0)
		{
			next = json_object_get_string(json_object_object_get(val, "next"));
		}
	}

	while (json_object_get_string(json_object_object_get(json_object_object_get(blocks, next), "next")) != NULL)
	{
		std_vector_pushback(lines, GetScratchLineFromJson(json_object_object_get(blocks, next)));

		next = json_object_get_string(json_object_object_get(json_object_object_get(blocks, next), "next"));
	}
	std_vector_pushback(lines, GetScratchLineFromJson(json_object_object_get(blocks, next)));

	for (int i = 0; i < lines.length; i++) 
	{
		PrintScratchLine(lines.data[i]);
	}

	free(text);

	return 0;
}