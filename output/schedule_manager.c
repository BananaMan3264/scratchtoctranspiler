#include <stdlib.h>
#include <string.h>
#include "schedule_manager.h"
#include "runtime/types.h"

#define SanitiseIndex(index) min((max((index),0)),(threads.length - 1))

extern ThreadList threads;

void InitialiseThreads()
{
	threads.data = malloc(sizeof(cothread_t) * 8); if (!threads.data) { printf("Malloc error!"); exit(-1); }
	threads.allocated_size = 8;
	threads.length = 0;
}

void ResizeThreadsList(int length)
{
	threads.allocated_size = length;
	void* temp = realloc(threads.data, threads.allocated_size * sizeof(cothread_t));
	if (!temp) { exit(-1); }
	threads.data = temp;
}

void AddThread(cothread_t data)
{
	if (threads.length + 1 > threads.allocated_size)
	{
		ResizeThreadsList(threads.allocated_size * 2);
	}
	threads.data[threads.length] = data;
	threads.length++;
}

void RemoveThread(int idx2)
{
	int idx = SanitiseIndex(idx2);
	memmove(threads.data + idx, threads.data + idx + 1, (threads.length - idx - 1) * sizeof(cothread_t));
	threads.length--;
}