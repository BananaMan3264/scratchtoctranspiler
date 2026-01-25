#include <stdio.h>
#include <string.h>
#include <json-c/json.h>
#include <stdbool.h>
#include "std_vector.h"
#include "types.h"

vecScratchBlock ParseText(char* data)
{
	vecScratchBlock lines;

	lines.allocated_size = 8; lines.length = 0; lines.sizeoftype = sizeof(ScratchBlock); lines.data = malloc(sizeof(ScratchBlock) * lines.allocated_size); if (!lines.data) {
		exit(-1);
	}

	struct json_object* project = json_tokener_parse(data);

	struct json_object* blocks = json_object_object_get(json_object_array_get_idx(json_object_object_get(project, "targets"), 1), "blocks");

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

		sb.opcode = AsManagedString(json_object_get_string(json_object_object_get(val, "opcode")));

		sb.args = json_object_object_length(json_object_object_get(val, "inputs"));

		sb.argdata = malloc(sb.args * sizeof(ScratchArgData));
		sb.argtypes = malloc(sb.args * sizeof(int));

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
				a = json_object_get_int(json_object_array_get_idx(json_object_array_get_idx(this, 1), 0));
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

	return lines;
}

int GetIndexOfBlockById(char* id, vecScratchBlock lines) 
{
	for (int i = 0; i < lines.length; i++) 
	{
		if (strcmp(lines.data[i].id.data, id) == 0) 
		{
			return i;
		}
	}
	return -1;
}