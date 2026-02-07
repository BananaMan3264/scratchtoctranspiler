#define TRUE_YIELD co_switch(scheduler);
#define YIELD TRUE_YIELD;
#include "runtime/scratch.h"
#include "runtime/motion.h"
#include "runtime/looks.h"
#include "runtime/operators.h"
#include "runtime/control.h"
#include "runtime/sensing.h"
#include "runtime/data.h"
#include "runtime/pen.h"
#include <libco.h>

extern cothread_t scheduler;

ScratchValue YbajaEakbba4cbaidbcbaFakdbeba8axfbaAaVgbhbamayibavaaaraiaaabalae;

void Init()
{
	YbajaEakbba4cbaidbcbaFakdbeba8axfbaAaVgbhbamayibavaaaraiaaabalae = ScratchSetDouble(0);
}

void Yoevent_whenflagclicked();
void Ypevent_whenflagclicked();
void Yvevent_whenflagclicked();

void Yoevent_whenflagclicked() 
{
	motion_setx(ScratchSetDouble(0));
	while(1)
	{
		motion_changexby(ScratchSetDouble(10));
		control_wait(operator_random(ScratchSetDouble(0.1), ScratchSetDouble(0.3)));
		if(ScratchVarGetBool(operator_equals(motion_xposition(), ScratchSetString("100"))))
		{
			motion_setx(ScratchSetDouble(0));
		}
		YIELD
	}
}

void Ypevent_whenflagclicked() 
{
	looks_setsizeto(ScratchSetDouble(100));
	motion_setx(ScratchSetDouble(0));
	while(1)
	{
		looks_changesizeby(ScratchSetDouble(1));
		if(ScratchVarGetBool(operator_equals(looks_size(), ScratchSetString("200"))))
		{
			looks_setsizeto(ScratchSetDouble(100));
		}
		YIELD
	}
}

void Yvevent_whenflagclicked() 
{
	motion_pointindirection(ScratchSetDouble(90));
	while(1)
	{
		motion_turnright(ScratchSetDouble(10));
		YIELD
	}
}

