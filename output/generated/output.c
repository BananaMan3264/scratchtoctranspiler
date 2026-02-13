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
#include <libco.h>

extern cothread_t scheduler;
extern bool delete_thread;
extern bool stop_all;
extern bool stop_other;
extern bool gc_enabled;

ScratchValue YAbajaEakbba4cbaidbcbaFak1beba8axfbaAaVgbhbamayibavaaaraiaaabalae;

ScratchValue* vars[] = 
{	&YAbajaEakbba4cbaidbcbaFak1beba8axfbaAaVgbhbamayibavaaaraiaaabalae,
};


ScratchList* lists[] = { NULL };

int vars_length = 1, lists_length = 0;

void _0_Init()
{
	YAbajaEakbba4cbaidbcbaFak1beba8axfbaAaVgbhbamayibavaaaraiaaabalae = ScratchSetString("apple banana");
}



void _1_Init()
{
}

void _1_Yaeevent_whenflagclicked();
void YaTahaias();

void _1_Yaeevent_whenflagclicked() 
{
#define YIELD FUNCTION_YIELD
	while(1)
	{
		YaTahaias();
		YIELD
	}
#define YIELD TRUE_YIELD
	END_THREAD
}

void YaTahaias() 
{
#define YIELD
	for(int i1 = 0; i1 < (int)ScratchVarGetDouble(ScratchSetDouble(1000)); i1++)
	{
		data_setvariableto(operator_join(ScratchSetString("apple apple apple apple apple apple apple apple apple apple apple apple apple apple apple apple apple apple apple apple apple apple apple apple apple apple apple apple apple apple apple apple apple apple apple apple apple apple apple apple apple apple apple apple apple apple apple apple apple apple apple apple apple apple apple apple apple apple apple apple apple apple apple apple apple apple apple apple apple apple apple apple apple apple apple apple apple apple apple apple apple apple apple apple apple apple apple apple apple "), ScratchSetString("banana")), YAbajaEakbba4cbaidbcbaFak1beba8axfbaAaVgbhbamayibavaaaraiaaabalae);
		YIELD
	}
#define YIELD TRUE_YIELD
}

