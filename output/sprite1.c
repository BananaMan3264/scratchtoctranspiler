
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
extern bool delete_thread; 

ScratchValue YbajaEakbba4cbaidbcbaFakdbeba8axfbaAaVgbhbamayibavaaaraiaaabalae;

void Init()
{
	YbajaEakbba4cbaidbcbaFakdbeba8axfbaAaVgbhbamayibavaaaraiaaabalae = ScratchSetDouble(0);
}

void Ybevent_whenkeypressedYw();
void Ydevent_whenkeypressedYs();
void Yfevent_whenkeypressedYa();
void Yhevent_whenkeypressedYd();
void Yjevent_whenflagclicked();

void Ybevent_whenkeypressedYw() 
{
	motion_changeyby(ScratchSetDouble(10));
	END_THREAD
}

void Ydevent_whenkeypressedYs() 
{
	motion_changeyby(ScratchSetDouble(-10));
	END_THREAD
}

void Yfevent_whenkeypressedYa() 
{
	motion_changexby(ScratchSetDouble(-10));
	END_THREAD
}

void Yhevent_whenkeypressedYd() 
{
	motion_changexby(ScratchSetDouble(10));
	END_THREAD
}

void Yjevent_whenflagclicked() 
{
	while(1)
	{
		motion_turnright(ScratchSetDouble(10));
		YIELD
	}
	END_THREAD
}

