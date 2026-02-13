#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "types.h"
#include "scratch.h"
#include "garbagecollector.h"

bool operator_equals_t(ScratchValue a, ScratchValue b)
{
	switch (max(a.ScratchType, b.ScratchType))
	{
	ScratchType_Bool:
		return (strcmp(ScratchVarGetString(a), ScratchVarGetString(b)) == 0);
	ScratchType_Number:
		return (strcmp(ScratchVarGetString(a), ScratchVarGetString(b)) == 0);
	ScratchType_String:
		return (strcmp(ScratchVarGetString(a), ScratchVarGetString(b)) == 0);
	default:
		return (false);
	}
}

#define SanitiseIndex(index) min((max((index),0)),(l2.length - 1))

ScratchList initialiseList()
{
	ScratchList list;
	list.data = malloc(sizeof(ScratchValue) * 8); if (!list.data) { printf("Malloc error!"); exit(-1); }
	list.allocated_size = 8;
	list.length = 0;
	return list;
}

ScratchList resizeList(ScratchList list, int length)
{
	ScratchList l2 = list;
	l2.allocated_size = length;
	void* temp = realloc(l2.data, l2.allocated_size * sizeof(ScratchValue));
	if (!temp) { exit(-1); }
	l2.data = temp;
	return l2;
}

ScratchList addDataToList(ScratchList list, ScratchValue data)
{
	ScratchList l2 = list;
	if (l2.length + 1 > l2.allocated_size)
	{
		l2 = resizeList(l2, l2.allocated_size * 2);
	}
	l2.data[l2.length] = data;
	l2.length++;
	return l2;
}

ScratchList removeListItem(ScratchList list, int idx2) 
{
	ScratchList l2 = list;
	int idx = SanitiseIndex(idx2);
	if (idx < 0 || idx >= l2.length) 
	{
		return l2;
	}
	memmove(l2.data + idx, l2.data + idx + 1, (l2.length - idx - 1) * sizeof(ScratchValue));
	l2.length--;
	return l2;
}

ScratchList insertItemAtList(ScratchList list, int idx2, ScratchValue item) 
{
	ScratchList l2 = list;
	int idx = SanitiseIndex(idx2);
	if (l2.length + 1 > l2.allocated_size)
	{
		l2 = resizeList(l2, l2.allocated_size * 2);
	}
	memmove(l2.data + idx + 1, l2.data + idx, (l2.length - idx) * sizeof(ScratchValue));
	l2.data[idx] = item;
	l2.length++;
	return l2;
}

ScratchValue data_itemnumoflist(ScratchValue item, ScratchList list)
{
	for (int i = 0; i < list.length; i++)
	{
		if (operator_equals_t(item, list.data[i])) 
		{
			return ScratchSetDouble(i + 1);
		}
	}
	return ScratchSetDouble(0);
}

ScratchValue data_listcontainsitem(ScratchValue item, ScratchList list)
{
	for (int i = 0; i < list.length; i++)
	{
		if (operator_equals_t(item, list.data[i]))
		{
			return ScratchSetBool(true);
		}
	}
	return ScratchSetBool(false);
}