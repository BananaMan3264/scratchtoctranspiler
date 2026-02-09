#include<SDL2/SDL.h>
#include<libco.h>
#include"sprite1.h"
#include"runtime/main.h"
#include"runtime/types.h"
#include"schedule_manager.h"

extern bool keysdown[];
extern int keysdownheld[];
ThreadList threads;
cothread_t scheduler;
cothread_t draw_thread;
bool delete_thread = false;


void RunScheduler()
{
	Init();
	InitialiseThreads();

	scheduler = co_active();

	AddThread(co_create(64 * 1024, Ybubevent_whenflagclicked));
	AddThread(co_create(64 * 1024, YhaWevent_whenflagclicked));

	while (1)
	{
		for (int i = 0; i < threads.length; i++)
		{
			co_switch(threads.data[i]);
			if (delete_thread) { RemoveThread(i); i--;  delete_thread = false; }
		}
		Render();
	}
}