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
		if (strcmp(lines.data[i].id.data, id) == 0)
		{
			return i;
		}
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
	freeIfUnmanaged(a);
	freeIfUnmanaged(b);
	return AsUnmanagedString(c);
}