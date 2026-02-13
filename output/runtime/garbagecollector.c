#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "types.h"
#include "garbagecollector.h"

MemoryMap mem;

extern ScratchValue* vars[];
extern ScratchList* lists[];

extern int  vars_length;
extern int lists_length;

#define SanitiseIndex(index) min((max((index),0)),(mem.length - 1))

void initialiseMem()
{
	mem.data = malloc(sizeof(void*) * 8); if (!mem.data) { printf("Malloc error!"); exit(-1); }
	mem.allocated_size = 8;
	mem.length = 0;
}

void resizeMem(int length)
{
	mem.allocated_size = length;
	void** temp = realloc(mem.data, mem.allocated_size * sizeof(void*));
	if (!temp) { exit(-1); }
	mem.data = temp;
}

void addToMem(void* data)
{
	if (mem.length + 1 > mem.allocated_size)
	{
		resizeMem(mem.allocated_size * 2);
	}
	mem.data[mem.length] = data;
	mem.length++;
}

void removeFromMem(int idx2)
{
	int idx = SanitiseIndex(idx2);
	if (idx < 0 || idx >= mem.length)
	{
		return;
	}
	memmove(mem.data + idx, mem.data + idx + 1, (mem.length - idx - 1) * sizeof(void*));
	mem.length--;
}

bool memHasPointer(void* item)
{
	for (int i = 0; i < mem.length; i++)
	{
		if (operator_equals_t(item, mem.data[i]))
		{
			return true;
		}
	}
	return false;
}

void* gc_malloc(int length)
{
	void* this = malloc(length);
	addToMem(this);
	return this;
}

void gc_init() 
{
	initialiseMem();
}

void gc_tick()
{
	if (!mem.data) { gc_init(); }
	if (!mem.data) { printf("Malloc error!"); exit(-1); }

	int i = 0;
restart_loop:

	if (i >= mem.length) { goto end; }

	for (int j = 0; j < vars_length; j++) 
	{
		if (mem.data[i] == (void*)vars[j]->data.String)
		{
			i++;
			goto restart_loop;
		}
	}
	for (int j = 0; j < lists_length; j++)
	{
		for (int k = 0; k < lists[j]->length; k++) 
		{
			if (mem.data[i] == (void*)lists[j]->data[k].data.String)
			{
				i++;
				goto restart_loop;
			}
		}
	}

	free(mem.data[i]);
	removeFromMem(i);
	goto restart_loop;

end:
	i++;
	//printf("\033[2J\033[H%lli\n", mem.length);
}