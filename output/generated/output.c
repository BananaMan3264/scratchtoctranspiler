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
	YAbajaEakbba4cbaidbcbaFak1beba8axfbaAaVgbhbamayibavaaaraiaaabalae = ScratchSetDouble(0);
}



void _1_Init()
{
}

void _1_Yafevent_whenflagclicked();

void _1_Yafevent_whenflagclicked() 
{
	activeSprite = 1;
#define YIELD FUNCTION_YIELD
	if(ScratchVarGetBool(ScratchSetDouble(0)))
	{
	}
	while(!(ScratchVarGetBool(ScratchSetDouble(0))))
	{
		YIELD
	}
	while(ScratchVarGetBool(ScratchSetDouble(0)))
	{
		YIELD
	}
	for(int i1 = 0; i1 < (int)ScratchVarGetDouble(ScratchSetDouble(10)); i1++)
	{
		YIELD
	}
	if(ScratchVarGetBool(ScratchSetDouble(0)))
	{
	}
	else
	{
	}
	while(1)
	{
		YIELD
	}
#define YIELD TRUE_YIELD
	END_THREAD
}

