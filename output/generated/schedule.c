#include<SDL2/SDL.h>
#include<libco.h>
#include"output.h"
#include"../runtime/main.h"
#include"../runtime/types.h"
#include"../schedule_manager.h"

extern bool keysdown[];
extern int keysdownheld[];
ThreadList threads;
cothread_t scheduler;
cothread_t draw_thread;
bool delete_thread = false;
bool stop_all = false;
bool stop_other = false;
extern int activeSprite;


void RunScheduler()
{
	InitialiseThreads();

	scheduler = co_active();

	_0_Init();
	_1_Init();
	AddThread(THREAD(co_create(64 * 1024, _1_Yadevent_whenflagclicked),1));

	while (1)
	{
		for (int i = 0; i < threads.length; i++)
		{
			activeSprite = threads.data[i].index;
			co_switch(threads.data[i].thread);
			if (delete_thread) { RemoveThread(i); i--;  delete_thread = false; }
			if (stop_all) { while (threads.length) { RemoveThread(0); } stop_all = false; }
			if (stop_other) { cothread_t this = threads.data[i].thread; int this_index = threads.data[i].index; for (int i = 0; i < threads.length; i++) { if (threads.data[i].index == this_index && threads.data[i].thread != this) { RemoveThread(i--); } } stop_other = false; }
		}
		Render();
	}
}
BroadcastInfo broadcast_YaOaXsbadubaja8a2aB1blbwbsbaz1bazaza4xbaS()
{
	Thread* output = malloc(sizeof(Thread)* 2);
	output[0] = THREAD(co_create(64 * 1024, _1_Yaeevent_whenbroadcastreceived_YaOaXsbadubaja8a2aB1blbwbsbaz1bazaza4xbaS),1); AddThread(output[0]);
	output[1] = THREAD(co_create(64 * 1024, _1_Yagevent_whenbroadcastreceived_YaOaXsbadubaja8a2aB1blbwbsbaz1bazaza4xbaS),1); AddThread(output[1]);
	return (BroadcastInfo) {output, 2};
}
BroadcastInfo broadcast_YacaKxb1bpbasazapacafagwbamaiayaiamcbaZak()
{
	Thread* output = malloc(sizeof(Thread)* 1);
	output[0] = THREAD(co_create(64 * 1024, _1_Yalevent_whenbroadcastreceived_YacaKxb1bpbasazapacafagwbamaiayaiamcbaZak),1); AddThread(output[0]);
	return (BroadcastInfo) {output, 1};
}
