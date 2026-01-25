#include <stdio.h>
#include <string.h>
#include <json-c/json.h>
#include <stdbool.h>
#include "std_vector.h"
#include "types.h"

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