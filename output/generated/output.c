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
#include <libco.h>

extern cothread_t scheduler;
extern bool delete_thread; 

ScratchValue YbajaEakbba4cbaidbcbaFakdbeba8axfbaAaVgbhbamayibavaaaraiaaabalae;

void _0_Init()
{
	YbajaEakbba4cbaidbcbaFakdbeba8axfbaAaVgbhbamayibavaaaraiaaabalae = ScratchSetDouble(0);
}



void _1_Init()
{
}

void _1_Ykevent_whenflagclicked();

void _1_Ykevent_whenflagclicked() 
{
	while(1)
	{
		motion_goto(motion_goto_menuY_araaanadaoama_());
		YIELD
	}
	END_THREAD
}


void _2_Init()
{
}

void _2_Ymevent_whenflagclicked();
void _2_Yoevent_whenkeypressed();

void _2_Ymevent_whenflagclicked() 
{
	while(1)
	{
		motion_goto(motion_goto_menuY_araaanadaoama_());
		YIELD
	}
	END_THREAD
}

void _2_Yoevent_whenkeypressed() 
{
	motion_pointtowards(motion_pointtowards_menuY_araaanadaoama_());
	END_THREAD
}


void _3_Init()
{
}

void _3_Yqevent_whenflagclicked();

void _3_Yqevent_whenflagclicked() 
{
	while(1)
	{
		motion_changeyby(ScratchSetDouble(10));
		if(ScratchVarGetBool(operator_lt(ScratchSetString("200"), motion_yposition())))
		{
			motion_goto(motion_goto_menuY_araaanadaoama_());
		}
		YIELD
	}
	END_THREAD
}

