#define YIELD TRUE_YIELD;
#include "../runtime/scratch.h"
#include "../runtime/motion.h"
#include "../runtime/looks.h"
#include "../runtime/sound.h"
#include "../runtime/operators.h"
#include "../runtime/control.h"
#include "../runtime/sensing.h"
#include "../runtime/data.h"
#include "../runtime/pen.h"
#include "../runtime/turbowarp.h"
#include "../runtime/event.h"
#include "schedule.h"
#include <libco.h>

extern cothread_t scheduler;
extern bool delete_thread;
extern bool stop_all;
extern bool stop_other;
extern bool gc_enabled;
extern int activeSprite;

ScratchValue YAbajaEakbba4cbaidbcbaFak1beba8axfbaAaVgbhbamayibavaaaraiaaabalae;

ScratchValue* vars[] = 
{	&YAbajaEakbba4cbaidbcbaFak1beba8axfbaAaVgbhbamayibavaaaraiaaabalae,
};


ScratchList* lists[] = { NULL };

int vars_length = 1, lists_length = 0;

void _0_Init()
{
	YAbajaEakbba4cbaidbcbaFak1beba8axfbaAaVgbhbamayibavaaaraiaaabalae = ScratchSetDouble(0);
}



void _1_Init()
{
}

void _1_Yadevent_whenflagclicked();
void _1_Yaeevent_whenbroadcastreceived_YaOaXsbadubaja8a2aB1blbwbsbaz1bazaza4xbaS();
void _1_Yagevent_whenbroadcastreceived_YaOaXsbadubaja8a2aB1blbwbsbaz1bazaza4xbaS();
void _1_Yalevent_whenbroadcastreceived_YacaKxb1bpbasazapacafagwbamaiayaiamcbaZak();

void _1_Yadevent_whenflagclicked() 
{
	activeSprite = 1;
	Yqekcknqekcknalaoagqekcknqekckniblbas(sensing_timer());
	event_broadcastandwait(YaOaXsbadubaja8a2aB1blbwbsbaz1bazaza4xbaS);
	Yqekcknqekcknalaoagqekcknqekckniblbas(sensing_timer());
	event_broadcast(YacaKxb1bpbasazapacafagwbamaiayaiamcbaZak);
#define YIELD TRUE_YIELD
	END_THREAD
}

void _1_Yaeevent_whenbroadcastreceived_YaOaXsbadubaja8a2aB1blbwbsbaz1bazaza4xbaS() 
{
	activeSprite = 1;
	control_wait(ScratchSetDouble(1));
#define YIELD TRUE_YIELD
	END_THREAD
}

void _1_Yagevent_whenbroadcastreceived_YaOaXsbadubaja8a2aB1blbwbsbaz1bazaza4xbaS() 
{
	activeSprite = 1;
	control_wait(ScratchSetDouble(2));
#define YIELD TRUE_YIELD
	END_THREAD
}

void _1_Yalevent_whenbroadcastreceived_YacaKxb1bpbasazapacafagwbamaiayaiamcbaZak() 
{
	activeSprite = 1;
#define YIELD TRUE_YIELD
	END_THREAD
}

