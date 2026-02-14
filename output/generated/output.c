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

ScratchList YebdbhbubawaZaha4azawAbayafaCaVacaTaVa2hb;

ScratchList* lists[] = 
{	&YebdbhbubawaZaha4azawAbayafaCaVacaTaVa2hb,
};

int vars_length = 1, lists_length = 1;

void _0_Init()
{
	YAbajaEakbba4cbaidbcbaFak1beba8axfbaAaVgbhbamayibavaaaraiaaabalae = ScratchSetString("apple banana");
	YebdbhbubawaZaha4azawAbayafaCaVacaTaVa2hb = initialiseList();
}



void _1_Init()
{
}

void _1_Yagevent_whenbroadcastreceived_YaGgbaEaXa8a0a5ara1a9aNaraeaCa7pbaFalaqob();
void _1_Yahevent_whenbroadcastreceived_YaGgbaEaXa8a0a5ara1a9aNaraeaCa7pbaFalaqob();
void _1_Yaievent_whenbroadcastreceived_YaGgbaEaXa8a0a5ara1a9aNaraeaCa7pbaFalaqob();
void _1_Yafevent_whenkeypressed();

void _1_Yagevent_whenbroadcastreceived_YaGgbaEaXa8a0a5ara1a9aNaraeaCa7pbaFalaqob() 
{
	activeSprite = 1;
#define YIELD FUNCTION_YIELD
	motion_goto(motion_goto_menuYa_araaanadaoama_());
#define YIELD TRUE_YIELD
	END_THREAD
}

void _1_Yahevent_whenbroadcastreceived_YaGgbaEaXa8a0a5ara1a9aNaraeaCa7pbaFalaqob() 
{
	activeSprite = 1;
#define YIELD FUNCTION_YIELD
	motion_pointtowards(motion_pointtowards_menuYa_araaanadaoama_());
#define YIELD TRUE_YIELD
	END_THREAD
}

void _1_Yaievent_whenbroadcastreceived_YaGgbaEaXa8a0a5ara1a9aNaraeaCa7pbaFalaqob() 
{
	activeSprite = 1;
#define YIELD FUNCTION_YIELD
	looks_setsizeto(operator_random(ScratchSetDouble(50), ScratchSetDouble(150)));
#define YIELD TRUE_YIELD
	END_THREAD
}

void _1_Yafevent_whenkeypressed() 
{
	activeSprite = 1;
#define YIELD FUNCTION_YIELD
	event_broadcast(YaGgbaEaXa8a0a5ara1a9aNaraeaCa7pbaFalaqob);
#define YIELD TRUE_YIELD
	END_THREAD
}


void _2_Init()
{
}

void _2_Yamevent_whenbroadcastreceived_YaGgbaEaXa8a0a5ara1a9aNaraeaCa7pbaFalaqob();

void _2_Yamevent_whenbroadcastreceived_YaGgbaEaXa8a0a5ara1a9aNaraeaCa7pbaFalaqob() 
{
	activeSprite = 2;
#define YIELD FUNCTION_YIELD
	motion_goto(motion_goto_menuYa_araaanadaoama_());
#define YIELD TRUE_YIELD
	END_THREAD
}

