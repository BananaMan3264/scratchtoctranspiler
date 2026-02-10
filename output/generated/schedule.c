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
extern int activeSprite;


void RunScheduler()
{
	InitialiseThreads();

	scheduler = co_active();

	_0_Init();
	_1_Init();
	_2_Init();
	_3_Init();
	AddThread(THREAD(co_create(64 * 1024, _1_Ykevent_whenflagclicked),1));
	AddThread(THREAD(co_create(64 * 1024, _2_Ymevent_whenflagclicked),2));
	AddThread(THREAD(co_create(64 * 1024, _3_Yqevent_whenflagclicked),3));

	while (1)
	{
		for (int i = 0; i < threads.length; i++)
		{
			activeSprite = threads.data[i].index;
			co_switch(threads.data[i].thread);
			if (delete_thread) { RemoveThread(i); i--;  delete_thread = false; }
		}
		if (keysdownheld[SDL_SCANCODE_A] == 1)
		{
			AddThread(THREAD(co_create(64 * 1024, _2_Yoevent_whenkeypressed),2));
		}
		Render();
	}
}
