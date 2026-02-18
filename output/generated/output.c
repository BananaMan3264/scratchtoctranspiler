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

ScratchValue _my_variable;

ScratchValue* vars[] = 
{	&_my_variable,
};


ScratchList* lists[] = { NULL };

int vars_length = 1, lists_length = 0;

void _0_Init()
{
	_my_variable = ScratchSetString("backdrop1");
}



void _1_Init()
{
}

void _1__Aevent_whenflagclicked();

void _1__Aevent_whenflagclicked() 
{
	activeSprite = 1;
	motion_movesteps((((1) + (1))));
	motion_turnright((((1) + (1))));
	motion_turnleft((((1) + (1))));
	motion_goto(motion_goto_menu_zpfrandomzpf());
	motion_goto(motion_goto_menu_zpfmousezpf());
	motion_gotoxy((((1) + (1))), (((1) + (1))));
	motion_glideto((((1) + (1))), motion_glideto_menu_zpfrandomzpf());
	motion_glideto((((1) + (1))), motion_glideto_menu_zpfmousezpf());
	motion_glidesecstoxy((((1) + (1))), (((1) + (1))), (((1) + (1))));
	motion_pointindirection(ScratchSetDouble(((1) + (1))));
	motion_pointtowards(motion_pointtowards_menu_zpfmousezpf());
	motion_pointtowards(motion_pointtowards_menu_zpfrandomzpf());
	motion_changexby((((1) + (1))));
	motion_setx((((1) + (1))));
	motion_changeyby((((1) + (1))));
	motion_sety((((1) + (1))));
	motion_ifonedgebounce();
	motion_setrotationstyle_leftzncright();
	motion_setrotationstyle_donzhct_rotate();
	motion_setrotationstyle_all_around();
	data_setvariableto(ScratchSetDouble((((motion_xposition())) + (1))), _my_variable);
	data_setvariableto(ScratchSetDouble((((motion_yposition())) + (1))), _my_variable);
	data_setvariableto(ScratchSetDouble((((motion_direction())) + (1))), _my_variable);
#define YIELD TRUE_YIELD
	END_THREAD
}

