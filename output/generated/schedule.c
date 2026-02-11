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
		if (keysdownheld[SDL_SCANCODE_SPACE] == 1)
		{
			AddThread(THREAD(co_create(64 * 1024, _1_Yabevent_whenkeypressed),1));
		}
		if (keysdownheld[SDL_SCANCODE_UP] == 1)
		{
			AddThread(THREAD(co_create(64 * 1024, _1_Yacevent_whenkeypressed),1));
		}
		if (keysdownheld[SDL_SCANCODE_RIGHT] == 1)
		{
			AddThread(THREAD(co_create(64 * 1024, _1_Yagevent_whenkeypressed),1));
		}
		if (keysdownheld[SDL_SCANCODE_LEFT] == 1)
		{
			AddThread(THREAD(co_create(64 * 1024, _1_Yaievent_whenkeypressed),1));
		}
		if (keysdownheld[SDL_SCANCODE_DOWN] == 1)
		{
			AddThread(THREAD(co_create(64 * 1024, _1_Yaeevent_whenkeypressed),1));
		}
		if (keysdownheld[SDL_SCANCODE_RETURN] == 1)
		{
			AddThread(THREAD(co_create(64 * 1024, _1_Yakevent_whenkeypressed),1));
			AddThread(THREAD(co_create(64 * 1024, _1_Yabasevent_whenkeypressed),1));
		}
		if (keysdownheld[SDL_SCANCODE_A] == 1)
		{
			AddThread(THREAD(co_create(64 * 1024, _1_Yamevent_whenkeypressed),1));
		}
		if (keysdownheld[SDL_SCANCODE_B] == 1)
		{
			AddThread(THREAD(co_create(64 * 1024, _1_Yaoevent_whenkeypressed),1));
		}
		if (keysdownheld[SDL_SCANCODE_C] == 1)
		{
			AddThread(THREAD(co_create(64 * 1024, _1_Yaqevent_whenkeypressed),1));
		}
		if (keysdownheld[SDL_SCANCODE_D] == 1)
		{
			AddThread(THREAD(co_create(64 * 1024, _1_Yasevent_whenkeypressed),1));
		}
		if (keysdownheld[SDL_SCANCODE_E] == 1)
		{
			AddThread(THREAD(co_create(64 * 1024, _1_Yauevent_whenkeypressed),1));
		}
		if (keysdownheld[SDL_SCANCODE_F] == 1)
		{
			AddThread(THREAD(co_create(64 * 1024, _1_Yawevent_whenkeypressed),1));
		}
		if (keysdownheld[SDL_SCANCODE_G] == 1)
		{
			AddThread(THREAD(co_create(64 * 1024, _1_Yayevent_whenkeypressed),1));
		}
		if (keysdownheld[SDL_SCANCODE_H] == 1)
		{
			AddThread(THREAD(co_create(64 * 1024, _1_YaAevent_whenkeypressed),1));
		}
		if (keysdownheld[SDL_SCANCODE_I] == 1)
		{
			AddThread(THREAD(co_create(64 * 1024, _1_YaCevent_whenkeypressed),1));
		}
		if (keysdownheld[SDL_SCANCODE_J] == 1)
		{
			AddThread(THREAD(co_create(64 * 1024, _1_YaEevent_whenkeypressed),1));
		}
		if (keysdownheld[SDL_SCANCODE_K] == 1)
		{
			AddThread(THREAD(co_create(64 * 1024, _1_YaGevent_whenkeypressed),1));
		}
		if (keysdownheld[SDL_SCANCODE_L] == 1)
		{
			AddThread(THREAD(co_create(64 * 1024, _1_YaIevent_whenkeypressed),1));
		}
		if (keysdownheld[SDL_SCANCODE_M] == 1)
		{
			AddThread(THREAD(co_create(64 * 1024, _1_YaKevent_whenkeypressed),1));
		}
		if (keysdownheld[SDL_SCANCODE_N] == 1)
		{
			AddThread(THREAD(co_create(64 * 1024, _1_YaMevent_whenkeypressed),1));
		}
		if (keysdownheld[SDL_SCANCODE_O] == 1)
		{
			AddThread(THREAD(co_create(64 * 1024, _1_YaOevent_whenkeypressed),1));
		}
		if (keysdownheld[SDL_SCANCODE_P] == 1)
		{
			AddThread(THREAD(co_create(64 * 1024, _1_YaQevent_whenkeypressed),1));
		}
		if (keysdownheld[SDL_SCANCODE_Q] == 1)
		{
			AddThread(THREAD(co_create(64 * 1024, _1_YaSevent_whenkeypressed),1));
		}
		if (keysdownheld[SDL_SCANCODE_R] == 1)
		{
			AddThread(THREAD(co_create(64 * 1024, _1_YaUevent_whenkeypressed),1));
		}
		if (keysdownheld[SDL_SCANCODE_S] == 1)
		{
			AddThread(THREAD(co_create(64 * 1024, _1_YaWevent_whenkeypressed),1));
		}
		if (keysdownheld[SDL_SCANCODE_T] == 1)
		{
			AddThread(THREAD(co_create(64 * 1024, _1_YaYevent_whenkeypressed),1));
		}
		if (keysdownheld[SDL_SCANCODE_U] == 1)
		{
			AddThread(THREAD(co_create(64 * 1024, _1_Yvbevent_whenkeypressed),1));
		}
		if (keysdownheld[SDL_SCANCODE_V] == 1)
		{
			AddThread(THREAD(co_create(64 * 1024, _1_Ylbevent_whenkeypressed),1));
		}
		if (keysdownheld[SDL_SCANCODE_W] == 1)
		{
			AddThread(THREAD(co_create(64 * 1024, _1_Yfbevent_whenkeypressed),1));
		}
		if (keysdownheld[SDL_SCANCODE_X] == 1)
		{
			AddThread(THREAD(co_create(64 * 1024, _1_Yobevent_whenkeypressed),1));
		}
		if (keysdownheld[SDL_SCANCODE_Y] == 1)
		{
			AddThread(THREAD(co_create(64 * 1024, _1_Yhbevent_whenkeypressed),1));
		}
		if (keysdownheld[SDL_SCANCODE_Z] == 1)
		{
			AddThread(THREAD(co_create(64 * 1024, _1_Ytbevent_whenkeypressed),1));
		}
		if (keysdownheld[SDL_SCANCODE_0] == 1 && !( keysdown[SDL_SCANCODE_LSHIFT] == 1 || keysdown[SDL_SCANCODE_RSHIFT] == 1))
		{
			AddThread(THREAD(co_create(64 * 1024, _1_Yjbevent_whenkeypressed),1));
		}
		if (keysdownheld[SDL_SCANCODE_1] == 1 && !( keysdown[SDL_SCANCODE_LSHIFT] == 1 || keysdown[SDL_SCANCODE_RSHIFT] == 1))
		{
			AddThread(THREAD(co_create(64 * 1024, _1_Y1bevent_whenkeypressed),1));
		}
		if (keysdownheld[SDL_SCANCODE_2] == 1 && !( keysdown[SDL_SCANCODE_LSHIFT] == 1 || keysdown[SDL_SCANCODE_RSHIFT] == 1))
		{
			AddThread(THREAD(co_create(64 * 1024, _1_Ydbevent_whenkeypressed),1));
		}
		if (keysdownheld[SDL_SCANCODE_3] == 1 && !( keysdown[SDL_SCANCODE_LSHIFT] == 1 || keysdown[SDL_SCANCODE_RSHIFT] == 1))
		{
			AddThread(THREAD(co_create(64 * 1024, _1_Ypbevent_whenkeypressed),1));
		}
		if (keysdownheld[SDL_SCANCODE_4] == 1 && !( keysdown[SDL_SCANCODE_LSHIFT] == 1 || keysdown[SDL_SCANCODE_RSHIFT] == 1))
		{
			AddThread(THREAD(co_create(64 * 1024, _1_YAbevent_whenkeypressed),1));
		}
		if (keysdownheld[SDL_SCANCODE_5] == 1 && !( keysdown[SDL_SCANCODE_LSHIFT] == 1 || keysdown[SDL_SCANCODE_RSHIFT] == 1))
		{
			AddThread(THREAD(co_create(64 * 1024, _1_Ycbevent_whenkeypressed),1));
		}
		if (keysdownheld[SDL_SCANCODE_6] == 1 && !( keysdown[SDL_SCANCODE_LSHIFT] == 1 || keysdown[SDL_SCANCODE_RSHIFT] == 1))
		{
			AddThread(THREAD(co_create(64 * 1024, _1_Yrbevent_whenkeypressed),1));
		}
		if (keysdownheld[SDL_SCANCODE_7] == 1 && !( keysdown[SDL_SCANCODE_LSHIFT] == 1 || keysdown[SDL_SCANCODE_RSHIFT] == 1))
		{
			AddThread(THREAD(co_create(64 * 1024, _1_Yaaabevent_whenkeypressed),1));
		}
		if (keysdownheld[SDL_SCANCODE_8] == 1 && !( keysdown[SDL_SCANCODE_LSHIFT] == 1 || keysdown[SDL_SCANCODE_RSHIFT] == 1))
		{
			AddThread(THREAD(co_create(64 * 1024, _1_Yaaadevent_whenkeypressed),1));
		}
		if (keysdownheld[SDL_SCANCODE_9] == 1 && !( keysdown[SDL_SCANCODE_LSHIFT] == 1 || keysdown[SDL_SCANCODE_RSHIFT] == 1))
		{
			AddThread(THREAD(co_create(64 * 1024, _1_Yaaafevent_whenkeypressed),1));
		}
		if (keysdownheld[SDL_SCANCODE_MINUS] == 1 && !( keysdown[SDL_SCANCODE_LSHIFT] == 1 || keysdown[SDL_SCANCODE_RSHIFT] == 1))
		{
			AddThread(THREAD(co_create(64 * 1024, _1_Yaaahevent_whenkeypressed),1));
		}
		if (keysdownheld[SDL_SCANCODE_COMMA] == 1 && !( keysdown[SDL_SCANCODE_LSHIFT] == 1 || keysdown[SDL_SCANCODE_RSHIFT] == 1))
		{
			AddThread(THREAD(co_create(64 * 1024, _1_Yaaajevent_whenkeypressed),1));
		}
		if (keysdownheld[SDL_SCANCODE_PERIOD] == 1 && !( keysdown[SDL_SCANCODE_LSHIFT] == 1 || keysdown[SDL_SCANCODE_RSHIFT] == 1))
		{
			AddThread(THREAD(co_create(64 * 1024, _1_Yaaalevent_whenkeypressed),1));
		}
		if (keysdownheld[SDL_SCANCODE_GRAVE] == 1 && !( keysdown[SDL_SCANCODE_LSHIFT] == 1 || keysdown[SDL_SCANCODE_RSHIFT] == 1))
		{
			AddThread(THREAD(co_create(64 * 1024, _1_Yaaanevent_whenkeypressed),1));
		}
		if (keysdownheld[SDL_SCANCODE_EQUALS] == 1 && !( keysdown[SDL_SCANCODE_LSHIFT] == 1 || keysdown[SDL_SCANCODE_RSHIFT] == 1))
		{
			AddThread(THREAD(co_create(64 * 1024, _1_Yaaapevent_whenkeypressed),1));
		}
		if (keysdownheld[SDL_SCANCODE_LEFTBRACKET] == 1 && !( keysdown[SDL_SCANCODE_LSHIFT] == 1 || keysdown[SDL_SCANCODE_RSHIFT] == 1))
		{
			AddThread(THREAD(co_create(64 * 1024, _1_Yaaarevent_whenkeypressed),1));
		}
		if (keysdownheld[SDL_SCANCODE_RIGHTBRACKET] == 1 && !( keysdown[SDL_SCANCODE_LSHIFT] == 1 || keysdown[SDL_SCANCODE_RSHIFT] == 1))
		{
			AddThread(THREAD(co_create(64 * 1024, _1_Yaaatevent_whenkeypressed),1));
		}
		if (keysdownheld[SDL_SCANCODE_BACKSLASH] == 1 && !( keysdown[SDL_SCANCODE_LSHIFT] == 1 || keysdown[SDL_SCANCODE_RSHIFT] == 1))
		{
			AddThread(THREAD(co_create(64 * 1024, _1_Yaaavevent_whenkeypressed),1));
		}
		if (keysdownheld[SDL_SCANCODE_SEMICOLON] == 1 && !( keysdown[SDL_SCANCODE_LSHIFT] == 1 || keysdown[SDL_SCANCODE_RSHIFT] == 1))
		{
			AddThread(THREAD(co_create(64 * 1024, _1_Yaaaxevent_whenkeypressed),1));
		}
		if (keysdownheld[SDL_SCANCODE_APOSTROPHE] == 1 && !( keysdown[SDL_SCANCODE_LSHIFT] == 1 || keysdown[SDL_SCANCODE_RSHIFT] == 1))
		{
			AddThread(THREAD(co_create(64 * 1024, _1_Yaaazevent_whenkeypressed),1));
		}
		if (keysdownheld[SDL_SCANCODE_SLASH] == 1 && !( keysdown[SDL_SCANCODE_LSHIFT] == 1 || keysdown[SDL_SCANCODE_RSHIFT] == 1))
		{
			AddThread(THREAD(co_create(64 * 1024, _1_YaaaBevent_whenkeypressed),1));
		}
		if (keysdownheld[SDL_SCANCODE_0] == 1 && ( keysdown[SDL_SCANCODE_LSHIFT] == 1 || keysdown[SDL_SCANCODE_RSHIFT] == 1))
		{
			AddThread(THREAD(co_create(64 * 1024, _1_YaaaDevent_whenkeypressed),1));
		}
		if (keysdownheld[SDL_SCANCODE_1] == 1 && ( keysdown[SDL_SCANCODE_LSHIFT] == 1 || keysdown[SDL_SCANCODE_RSHIFT] == 1))
		{
			AddThread(THREAD(co_create(64 * 1024, _1_YaaaFevent_whenkeypressed),1));
		}
		if (keysdownheld[SDL_SCANCODE_2] == 1 && ( keysdown[SDL_SCANCODE_LSHIFT] == 1 || keysdown[SDL_SCANCODE_RSHIFT] == 1))
		{
			AddThread(THREAD(co_create(64 * 1024, _1_YaaaHevent_whenkeypressed),1));
		}
		if (keysdownheld[SDL_SCANCODE_3] == 1 && ( keysdown[SDL_SCANCODE_LSHIFT] == 1 || keysdown[SDL_SCANCODE_RSHIFT] == 1))
		{
			AddThread(THREAD(co_create(64 * 1024, _1_YaaaJevent_whenkeypressed),1));
		}
		if (keysdownheld[SDL_SCANCODE_4] == 1 && ( keysdown[SDL_SCANCODE_LSHIFT] == 1 || keysdown[SDL_SCANCODE_RSHIFT] == 1))
		{
			AddThread(THREAD(co_create(64 * 1024, _1_YaaaLevent_whenkeypressed),1));
		}
		if (keysdownheld[SDL_SCANCODE_5] == 1 && ( keysdown[SDL_SCANCODE_LSHIFT] == 1 || keysdown[SDL_SCANCODE_RSHIFT] == 1))
		{
			AddThread(THREAD(co_create(64 * 1024, _1_YaaaNevent_whenkeypressed),1));
		}
		if (keysdownheld[SDL_SCANCODE_6] == 1 && ( keysdown[SDL_SCANCODE_LSHIFT] == 1 || keysdown[SDL_SCANCODE_RSHIFT] == 1))
		{
			AddThread(THREAD(co_create(64 * 1024, _1_YaaaPevent_whenkeypressed),1));
		}
		if (keysdownheld[SDL_SCANCODE_7] == 1 && ( keysdown[SDL_SCANCODE_LSHIFT] == 1 || keysdown[SDL_SCANCODE_RSHIFT] == 1))
		{
			AddThread(THREAD(co_create(64 * 1024, _1_YaaaRevent_whenkeypressed),1));
		}
		if (keysdownheld[SDL_SCANCODE_8] == 1 && ( keysdown[SDL_SCANCODE_LSHIFT] == 1 || keysdown[SDL_SCANCODE_RSHIFT] == 1))
		{
			AddThread(THREAD(co_create(64 * 1024, _1_YaaaTevent_whenkeypressed),1));
		}
		if (keysdownheld[SDL_SCANCODE_9] == 1 && ( keysdown[SDL_SCANCODE_LSHIFT] == 1 || keysdown[SDL_SCANCODE_RSHIFT] == 1))
		{
			AddThread(THREAD(co_create(64 * 1024, _1_YaaaVevent_whenkeypressed),1));
		}
		if (keysdownheld[SDL_SCANCODE_MINUS] == 1 && ( keysdown[SDL_SCANCODE_LSHIFT] == 1 || keysdown[SDL_SCANCODE_RSHIFT] == 1))
		{
			AddThread(THREAD(co_create(64 * 1024, _1_YaaaXevent_whenkeypressed),1));
		}
		if (keysdownheld[SDL_SCANCODE_EQUALS] == 1 && ( keysdown[SDL_SCANCODE_LSHIFT] == 1 || keysdown[SDL_SCANCODE_RSHIFT] == 1))
		{
			AddThread(THREAD(co_create(64 * 1024, _1_YaaaZevent_whenkeypressed),1));
		}
		if (keysdownheld[SDL_SCANCODE_LEFTBRACKET] == 1 && ( keysdown[SDL_SCANCODE_LSHIFT] == 1 || keysdown[SDL_SCANCODE_RSHIFT] == 1))
		{
			AddThread(THREAD(co_create(64 * 1024, _1_Yaacbevent_whenkeypressed),1));
		}
		if (keysdownheld[SDL_SCANCODE_RIGHTBRACKET] == 1 && ( keysdown[SDL_SCANCODE_LSHIFT] == 1 || keysdown[SDL_SCANCODE_RSHIFT] == 1))
		{
			AddThread(THREAD(co_create(64 * 1024, _1_Yaaebevent_whenkeypressed),1));
		}
		if (keysdownheld[SDL_SCANCODE_BACKSLASH] == 1 && ( keysdown[SDL_SCANCODE_LSHIFT] == 1 || keysdown[SDL_SCANCODE_RSHIFT] == 1))
		{
			AddThread(THREAD(co_create(64 * 1024, _1_Yaasbevent_whenkeypressed),1));
		}
		if (keysdownheld[SDL_SCANCODE_SEMICOLON] == 1 && ( keysdown[SDL_SCANCODE_LSHIFT] == 1 || keysdown[SDL_SCANCODE_RSHIFT] == 1))
		{
			AddThread(THREAD(co_create(64 * 1024, _1_Yaaubevent_whenkeypressed),1));
		}
		if (keysdownheld[SDL_SCANCODE_APOSTROPHE] == 1 && ( keysdown[SDL_SCANCODE_LSHIFT] == 1 || keysdown[SDL_SCANCODE_RSHIFT] == 1))
		{
			AddThread(THREAD(co_create(64 * 1024, _1_Yaagbevent_whenkeypressed),1));
		}
		if (keysdownheld[SDL_SCANCODE_SLASH] == 1 && ( keysdown[SDL_SCANCODE_LSHIFT] == 1 || keysdown[SDL_SCANCODE_RSHIFT] == 1))
		{
			AddThread(THREAD(co_create(64 * 1024, _1_Yaakbevent_whenkeypressed),1));
		}
		if (keysdownheld[SDL_SCANCODE_COMMA] == 1 && ( keysdown[SDL_SCANCODE_LSHIFT] == 1 || keysdown[SDL_SCANCODE_RSHIFT] == 1))
		{
			AddThread(THREAD(co_create(64 * 1024, _1_Yaawbevent_whenkeypressed),1));
		}
		if (keysdownheld[SDL_SCANCODE_PERIOD] == 1 && ( keysdown[SDL_SCANCODE_LSHIFT] == 1 || keysdown[SDL_SCANCODE_RSHIFT] == 1))
		{
			AddThread(THREAD(co_create(64 * 1024, _1_Yaabbevent_whenkeypressed),1));
		}
		if (keysdownheld[SDL_SCANCODE_GRAVE] == 1 && ( keysdown[SDL_SCANCODE_LSHIFT] == 1 || keysdown[SDL_SCANCODE_RSHIFT] == 1))
		{
			AddThread(THREAD(co_create(64 * 1024, _1_Yaanbevent_whenkeypressed),1));
		}
		if (keysdownheld[SDL_SCANCODE_BACKSPACE] == 1)
		{
			AddThread(THREAD(co_create(64 * 1024, _1_Yaaa_event_whenkeypressed),1));
		}
		if (keysdownheld[SDL_SCANCODE_DELETE] == 1)
		{
			AddThread(THREAD(co_create(64 * 1024, _1_Yaaqbevent_whenkeypressed),1));
		}
		if (keysdownheld[SDL_SCANCODE_LSHIFT] == 1 || keysdownheld[SDL_SCANCODE_RSHIFT] == 1)
		{
			AddThread(THREAD(co_create(64 * 1024, _1_Yaambevent_whenkeypressed),1));
		}
		if (keysdownheld[SDL_SCANCODE_CAPSLOCK] == 1)
		{
			AddThread(THREAD(co_create(64 * 1024, _1_Yabaaevent_whenkeypressed),1));
		}
		if (keysdownheld[SDL_SCANCODE_SCROLLLOCK] == 1)
		{
			AddThread(THREAD(co_create(64 * 1024, _1_Yabacevent_whenkeypressed),1));
		}
		if (keysdownheld[SDL_SCANCODE_LCTRL] == 1 || keysdownheld[SDL_SCANCODE_RCTRL] == 1)
		{
			AddThread(THREAD(co_create(64 * 1024, _1_Yabaeevent_whenkeypressed),1));
		}
		if (keysdownheld[SDL_SCANCODE_ESCAPE] == 1)
		{
			AddThread(THREAD(co_create(64 * 1024, _1_Yabagevent_whenkeypressed),1));
		}
		if (keysdownheld[SDL_SCANCODE_INSERT] == 1)
		{
			AddThread(THREAD(co_create(64 * 1024, _1_Yabaievent_whenkeypressed),1));
		}
		if (keysdownheld[SDL_SCANCODE_HOME] == 1)
		{
			AddThread(THREAD(co_create(64 * 1024, _1_Yabakevent_whenkeypressed),1));
		}
		if (keysdownheld[SDL_SCANCODE_END] == 1)
		{
			AddThread(THREAD(co_create(64 * 1024, _1_Yabamevent_whenkeypressed),1));
		}
		if (keysdownheld[SDL_SCANCODE_PAGEUP] == 1)
		{
			AddThread(THREAD(co_create(64 * 1024, _1_Yabaoevent_whenkeypressed),1));
		}
		if (keysdownheld[SDL_SCANCODE_PAGEDOWN] == 1)
		{
			AddThread(THREAD(co_create(64 * 1024, _1_Yabaqevent_whenkeypressed),1));
		}
		Render();
	}
}
