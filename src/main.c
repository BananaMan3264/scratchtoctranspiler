#include <stdio.h>
#include <string.h>
#include <json-c/json.h>
#include <stdbool.h>
#include "std_vector.h"

struct json_object* blocks;

#define AsUnmanagedString(a) (String){false, a}
#define AsManagedString(a)   (String){true,  a}

#define freeIfUnmanaged(a) if(!a.managed) { free(a.data); }

enum ArgTypes
{
	ArgType_Pointer = 3,
	ArgType_Text	= 4,
	ArgType_Number	= 5,
	ArgType_Number1	= 6,	// Positive number | These two are Scratch jankness; they
	ArgType_Number2	= 7,	// Angle		   | work the same way as ArgType_Number
};

typedef struct String
{
	bool managed; // True if the string should not be freed (Managed by json-c)
	char* data;
} String;

typedef union ScratchArgData 
{
	String idPointer;
	String text;
	double number;
} ScratchArgData;

typedef struct ScratchBlock 
{
	String id;
	String opcode;
	String next;
	String previous;
	int args;
	int* argtypes;
	ScratchArgData* argdata;
} ScratchBlock;

struct vecScratchBlock {
	ScratchBlock* data; size_t allocated_size; size_t length; size_t sizeoftype;
} lines;

int main()
{
	lines.allocated_size = 8; lines.length = 0; lines.sizeoftype = sizeof(ScratchBlock); lines.data = malloc(sizeof(ScratchBlock) * lines.allocated_size); if (!lines.data) {
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

	char* text = malloc(bufferSize); if (!text) { printf("Malloc error!"); exit(-1); }

	if (text == NULL)
	{
		printf("Malloc Error.");
		exit(-1);
	}

	fread(text, 1, bufferSize, json);

	struct json_object* project = json_tokener_parse(text);

	blocks = json_object_object_get(json_object_array_get_idx(json_object_object_get(project, "targets"), 1), "blocks");

	json_object_object_foreach(blocks, key, val)
	{
		ScratchBlock sb;
		sb.id = AsManagedString(key);
		struct json_object* next = json_object_object_get(val, "next");
		if (json_object_is_type(next, json_type_null)) 
		{
			sb.next = (String){ NULL, false };
		}
		else
		{
			sb.next = AsManagedString(json_object_get_string(next));
		}
		struct json_object* previous = json_object_object_get(val, "parent");
		if (json_object_is_type(previous, json_type_null))
		{
			sb.previous = (String){ NULL, false };
		}
		else
		{
			sb.previous = AsManagedString(json_object_get_string(previous));
		}

		sb.opcode = AsManagedString(json_object_get_string(json_object_object_get(val,"opcode")));

		sb.args = json_object_object_length(json_object_object_get(val, "inputs"));

		sb.argdata  = malloc(sb.args * sizeof(ScratchArgData));
		sb.argtypes = malloc(sb.args * sizeof(int)			 );

		int i = 0;
		json_object_object_foreach(json_object_object_get(val, "inputs"), block_key, block_val)
		{
			int a = json_object_get_int(json_object_array_get_idx(block_val, 0));
			struct json_object* this = block_val;
			sb.argtypes[i] = a;
			get_by_type:
			switch (a) 
			{
			case 1:
			case 2:
				a = json_object_get_int(json_object_array_get_idx(json_object_array_get_idx(this, 1),0));
				this = json_object_array_get_idx(this, 1);
				goto get_by_type;
			case ArgType_Pointer:
				sb.argdata[i].idPointer = AsManagedString(json_object_get_string(json_object_array_get_idx(this, 1)));
				sb.argtypes[i] = a;
				break;
			case ArgType_Text:
				sb.argdata[i].text = AsManagedString(json_object_get_string(json_object_array_get_idx(this, 1)));
				sb.argtypes[i] = a;
				break;
			default:
				printf("These argument types have not been implemented!");
				exit(-1);
			}
			i++;
		}

		std_vector_pushback(lines, sb);
	}

	for (int i = 0; i < lines.length; i++) 
	{
		ScratchBlock sb = lines.data[i];
		printf("Id: %s\nOpcode: %s\nNext: %s\nParent: %s\n", sb.id.data, sb.opcode.data, sb.next.data, sb.previous.data);
		for (int j = 0; j < sb.args; j++)
		{
			switch (sb.argtypes[j])
			{
			case ArgType_Pointer:
				printf("\tBlock pointer: %s\n", sb.argdata[j].text.data);
				break;
			case ArgType_Text:
				printf("\tString: %s\n", sb.argdata[j].text.data);
				break;
			}
		}
		printf("\n");
	}

	return 0;
}