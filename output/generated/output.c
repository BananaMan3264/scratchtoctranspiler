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
	YAbajaEakbba4cbaidbcbaFak1beba8axfbaAaVgbhbamayibavaaaraiaaabalae = ScratchSetDouble(2026);
}



void _1_Init()
{
}

void _1_Yaaevent_whenflagclicked();

void _1_Yaaevent_whenflagclicked() 
{
	activeSprite = 1;
#define YIELD FUNCTION_YIELD
	Yqekcknqekcknalaoagqekcknqekckniblbas(ScratchSetString("abc"));
#define YIELD TRUE_YIELD
	END_THREAD
}

