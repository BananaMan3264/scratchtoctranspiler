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

vecString initialiseStringVector()
{
	vecString list;
	list.data = malloc(sizeof(String) * 8); if (!list.data) { printf("Malloc error!"); exit(-1); }
	list.allocated_size = 8;
	list.length = 0;
	return list;
}

vecString resizeStringVector(vecString list, int length)
{
	vecString l2 = list;
	l2.allocated_size = length;
	void* temp = realloc(l2.data, l2.allocated_size * sizeof(String));
	if (!temp) { exit(-1); }
	l2.data = temp;
	return l2;
}

vecString addDataToStringVector(vecString list, String data)
{
	vecString l2 = list;
	if (l2.length + 1 > l2.allocated_size)
	{
		l2 = resizeStringVector(l2, l2.allocated_size * 2);
	}
	l2.data[l2.length] = data;
	l2.length++;
	return l2;
}

vecString removeStringVectorItem(vecString list, int idx)
{
	vecString l2 = list;
	if (idx < 0 || idx >= l2.length)
	{
		return l2;
	}
	memmove(l2.data + idx, l2.data + idx + 1, (l2.length - idx - 1) * sizeof(String));
	l2.length--;
	return l2;
}

vecString insertItemAtStringVector(vecString list, int idx, String item)
{
	vecString l2 = list;
	if (l2.length + 1 > l2.allocated_size)
	{
		l2 = resizeStringVector(l2, l2.allocated_size * 2);
	}
	memmove(l2.data + idx + 1, l2.data + idx, (l2.length - idx) * sizeof(String));
	l2.data[idx] = item;
	l2.length++;
	return l2;
}

int indexOfItemStringVector(String item, vecString list)
{
	for (int i = 0; i < list.length; i++)
	{
		if (strcmp(item.data, list.data[i].data) == 0)
		{
			return i;
		}
	}
	return -1;
}

bool stringVectorContainsItem(String item, vecString list)
{
	for (int i = 0; i < list.length; i++)
	{
		if (strcmp(item.data, list.data[i].data) == 0)
		{
			return true;
		}
	}
	return false;
}

vecString varIds;
vecString varNames;

void initVarIdeas() 
{
	varIds   = initialiseStringVector();
	varNames = initialiseStringVector();
}

void AddVariable(String varId, String varName, int sprite_idx) 
{
	int len = snprintf(NULL, 0, "_%d_%s", sprite_idx, varName.data) + 1;
	char* nm = malloc(len);

	snprintf(nm, len, "_%d%s", sprite_idx, varName.data);
	
	String name = AsUnmanagedString(nm);

	varIds   = addDataToStringVector(varIds  , varId);
	varNames = addDataToStringVector(varNames, name );
}

int getVariableIndexById(String id)
{
	return indexOfItemStringVector(id, varIds);
}

int getVariableIndexByName(String id)
{
	return indexOfItemStringVector(id, varNames);
}

String getVariableNameById(String id) 
{
	return varNames.data[indexOfItemStringVector(id, varIds)];
}