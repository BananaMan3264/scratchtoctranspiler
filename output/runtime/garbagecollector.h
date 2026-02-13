void* gc_malloc(int length);
void gc_init();
void gc_tick();

typedef struct MemoryMap
{
	void** data;
	size_t allocated_size;
	size_t length;
} MemoryMap;