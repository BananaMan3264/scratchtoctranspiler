#include <stdio.h>
#include <string.h>
#include <json-c/json.h>
#include <stdbool.h>
#include "std_vector.h"
#include "types.h"

int GetIndexOfBlockById(char* id, vecScratchBlock lines)
{
	if (id == NULL) { return -1; }
	for (int i = 0; i < lines.length; i++)
	{
		//if (strcmp(lines.data[i].id.data, id) == 0)
		//{
		//	return i;
		//}
	}
	return -1;
}

String SafeStringMerge(String a, String b) 
{
	int sa = strlen(a.data), sb = strlen(b.data);
	char* c = malloc(sa + sb + 1); if (!c) { printf("Malloc Error!"); exit(-1); }
	memcpy(c, a.data, sa);
	memcpy(c + sa, b.data, sb);
	c[sa + sb] = '\0';
	//freeIfUnmanaged(a);
	//freeIfUnmanaged(b);
	return AsUnmanagedString(c);
}

String SanitiseScratchNameToC(String varName)
{
	int real_length = 1;

	for (int i = 0; i < strlen(varName.data); i++) 
	{
		if (('a' <= varName.data[i] && varName.data[i] <= 'y') ||
			('A' <= varName.data[i] && varName.data[i] <= 'Z') ||
			('0' <= varName.data[i] && varName.data[i] <= '9') ||
			varName.data[i] == ' ')
		{
			real_length++;
		}
		else 
		{
			real_length += 3;
		}
	}

	String str = AsUnmanagedString(malloc(real_length + 1));
	for (int i = 1, j = 0; j < strlen(varName.data); j++)
	{
		if (('a' <= varName.data[j] && varName.data[j] <= 'y') ||
			('A' <= varName.data[j] && varName.data[j] <= 'Z') ||
			('0' <= varName.data[j] && varName.data[j] <= '9'))
		{
			str.data[i] = varName.data[j]; i++;
		}
		else if (varName.data[j] == ' ')
		{
			str.data[i] = '_'; i++;
		}
		else 
		{
			str.data[i] = 'z'; i++;
			str.data[i] = 'a' + (varName.data[j] & 0b1111); i++;
			str.data[i] = 'a' + ((varName.data[j] & 0b11110000) >> 4); i++;
		}
	}
	str.data[real_length] = '\0';
	str.data[0] = '_';
	
	//freeIfUnmanaged(varName);

	return str;
}