#include<libco.h>
#include"sprite1.h"
#include"runtime/main.h"

cothread_t scheduler;
cothread_t draw_thread;

cothread_t Yoevent_whenflagclicked_thread;
cothread_t Ypevent_whenflagclicked_thread;
cothread_t Yvevent_whenflagclicked_thread;

void RunScheduler()
{
	Init();

	scheduler = co_active();

	Yoevent_whenflagclicked_thread = co_create(64 * 1024, Yoevent_whenflagclicked);
	Ypevent_whenflagclicked_thread = co_create(64 * 1024, Ypevent_whenflagclicked);
	Yvevent_whenflagclicked_thread = co_create(64 * 1024, Yvevent_whenflagclicked);

	while (1)
	{
		co_switch(Yoevent_whenflagclicked_thread);
		co_switch(Ypevent_whenflagclicked_thread);
		co_switch(Yvevent_whenflagclicked_thread);
		Render();
	}
}