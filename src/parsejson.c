#include <stdio.h>
#include <string.h>
#include <json-c/json.h>
#include <stdbool.h>
#include "std_vector.h"
#include "types.h"
#include "util.h"

vecScratchBlock ParseText(struct json_object* blocks)
{
	vecScratchBlock lines;

	lines.allocated_size = 8; lines.length = 0; lines.sizeoftype = sizeof(ScratchBlock); lines.data = malloc(sizeof(ScratchBlock) * lines.allocated_size); if (!lines.data) {
		exit(-1);
	}

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

		if (strcmp(sb.opcode.data, "procedures_call") == 0)
		{
			sb.opcode = 
			SanitiseScratchNameToC(
				AsManagedString(
					json_object_get_string(
						json_object_object_get(
							json_object_object_get(
								val, 
								"mutation"
							), 
							"proccode"
						)
					)
				)
			);
		}

		if (strcmp(sb.opcode.data, "procedures_definition") == 0)
		{
			continue;
		}

		if (strcmp(sb.opcode.data, "procedures_prototype") == 0) 
		{
			continue;
		}

		sb.args = json_object_object_length(json_object_object_get(val, "inputs"));

		sb.argdata = malloc(sb.args * sizeof(ScratchArgData));
		sb.argtypes = malloc(sb.args * sizeof(int));

		int i = 0;
		json_object_object_foreach(json_object_object_get(val, "inputs"), block_key, block_val)
		{
			struct json_object* this = block_val;
			int a = json_object_get_int(json_object_array_get_idx(this, 0));
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
				if (json_object_get_type(json_object_array_get_idx(this, 1)) == json_type_string)
				{
					struct json_object* this = block_val;
					sb.argdata[i].idPointer = AsManagedString(json_object_get_string(json_object_array_get_idx(this, 1)));
					sb.argtypes[i] = a;
				}
				else 
				{
					a = json_object_get_int(json_object_array_get_idx(json_object_array_get_idx(this, 1), 0));
					this = json_object_array_get_idx(this, 1);

					goto get_by_type;
				}
				break;
			case ArgType_Number:
			case ArgType_PositiveNumber:
			case ArgType_NegativeNumber:
			case ArgType_Integer:
			case ArgType_Angle:
				sb.argdata[i].text = AsManagedString(json_object_get_string(json_object_array_get_idx(this, 1)));
				sb.argtypes[i] = ArgType_Number;
				break;
			case ArgType_String:
				sb.argdata[i].text = AsManagedString(json_object_get_string(json_object_array_get_idx(this, 1)));
				sb.argtypes[i] = ArgType_String;
				break;
			case ArgType_Variable:
				sb.argdata[i].text = SanitiseScratchNameToC(AsManagedString(json_object_get_string(json_object_array_get_idx(this, 2))));
				sb.argtypes[i] = ArgType_Variable;
				break;
			default:
				printf("These argument types have not been implemented! %i\n", a);
				exit(-1);
			}
			if (strcmp(json_object_get_string(json_object_object_get(val, "opcode")), "procedures_call") == 0)
			{
				sb.argtypes[i] = ArgType_Number;
			}
			i++;
		}

		std_vector_pushback(lines, sb);
	}

	return lines;
}