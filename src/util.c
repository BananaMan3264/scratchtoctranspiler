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

String SanitiseScratchNameToC(String varName)
{
	String str = AsUnmanagedString(malloc(strlen(varName.data) * 2 + 1));
	if (!str.data) { printf("Malloc Error!"); exit(-1); }

	for (int i = 0, j = 0; i < strlen(varName.data); i++)
	{
		switch (varName.data[i])
		{
		case '`':
			str.data[j] = 'a'; j++;
			goto next;
		case '@':
			str.data[j] = 'b'; j++;
			goto next;
		case '|':
			str.data[j] = 'c'; j++;
			goto next;
		case '[':
			str.data[j] = 'd'; j++;
			goto next;
		case '#':
			str.data[j] = 'c'; j++;
			goto next;
		case '?':
			str.data[j] = 'd'; j++;
			goto next;
		case '(':
			str.data[j] = 'e'; j++;
			goto next;
		case ')':
			str.data[j] = 'f'; j++;
			goto next;
		case '.':
			str.data[j] = 'g'; j++;
			goto next;
		case '-':
			str.data[j] = 'h'; j++;
			goto next;
		case ' ':
			str.data[j] = 'i'; j++;
			goto next;
		case ';':
			str.data[j] = 'j'; j++;
			goto next;
		case ':':
			str.data[j] = 'k'; j++;
			goto next;
		case '%':
			str.data[j] = 'l'; j++;
			goto next;
		case '}':
			str.data[j] = 'm'; j++;
			goto next;
		case ']':
			str.data[j] = 'n'; j++;
			goto next;
		case '+':
			str.data[j] = 'o'; j++;
			goto next;
		case '^':
			str.data[j] = 'p'; j++;
			goto next;
		case '{':
			str.data[j] = 'q'; j++;
			goto next;
		case '~':
			str.data[j] = 'r'; j++;
			goto next;
		case '*':
			str.data[j] = 's'; j++;
			goto next;
		case '/':
			str.data[j] = 't'; j++;
			goto next;
		case ',':
			str.data[j] = 'u'; j++;
			goto next;
		case '!':
			str.data[j] = 'v'; j++;
			goto next;
		case '=':
			str.data[j] = 'w'; j++;
			goto next;
		case '$':
			str.data[j] = 'x'; j++;
			goto next;
		case '\'':
			str.data[j] = 'y'; j++;
			goto next;
		next:
			str.data[j] = 'b'; j++;
			break;
		default:
			str.data[j] = varName.data[i]; j++;
			str.data[j] = 'a'; j++;
			break;
		}
	}
	str.data[0] = 'Y';

	str.data[strlen(varName.data) * 2] = '\0';
	freeIfUnmanaged(varName);

	return str;
}