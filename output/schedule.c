#include<SDL2/SDL.h>
#include<libco.h>
#include"sprite1.h"
#include"runtime/main.h"
#include"runtime/types.h"
#include"schedule_manager.h"

extern bool keysdown[];
ThreadList threads;
cothread_t scheduler;
cothread_t draw_thread;
bool delete_thread = false;


void RunScheduler()
{
	Init();
	InitialiseThreads();

	scheduler = co_active();

	AddThread(co_create(64 * 1024, Yjevent_whenflagclicked));

	while (1)
	{
		for (int i = 0; i < threads.length; i++)
		{
			co_switch(threads.data[i]);
			if (delete_thread) { RemoveThread(i); i--;  delete_thread = false; }
		}
		if (keysdown[SDL_SCANCODE_A])
		{
			AddThread(co_create(64 * 1024, Yfevent_whenkeypressedYa));
		}
		if (keysdown[SDL_SCANCODE_D])
		{
			AddThread(co_create(64 * 1024, Yhevent_whenkeypressedYd));
		}
		if (keysdown[SDL_SCANCODE_S])
		{
			AddThread(co_create(64 * 1024, Ydevent_whenkeypressedYs));
		}
		if (keysdown[SDL_SCANCODE_W])
		{
			AddThread(co_create(64 * 1024, Ybevent_whenkeypressedYw));
		}
		Render();
	}
}