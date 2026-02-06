#define TRUE_YIELD Yield();
#define YIELD TRUE_YIELD;
#include "runtime/scratch.h"
#include "runtime/motion.h"
#include "runtime/looks.h"
#include "runtime/operators.h"
#include "runtime/control.h"
#include "runtime/sensing.h"
#include "runtime/data.h"

ScratchValue YbajaEakbba4cbaidbcbaFakdbeba8axfbaAaVgbhbamayibavaaaraiaaabalae;
ScratchList Yba1aoaka9aaaBa7azaMvbamaOhba6cbaIafa5sb;
ScratchList YTasuba2axaskbhbamhbacnbobaSaPasa7aIafaY;

void Init()
{
	YbajaEakbba4cbaidbcbaFakdbeba8axfbaAaVgbhbamayibavaaaraiaaabalae = ScratchSetDouble(10);
	Yba1aoaka9aaaBa7azaMvbamaOhba6cbaIafa5sb = initialiseList();
	YTasuba2axaskbhbamhbacnbobaSaPasa7aIafaY = initialiseList();
}

void Start();
void YAadadibaRaaanadibaPaoaianat();
void YDaraaawibaPaoaianatas();

void Start() 
{
	data_deletealloflist(Yba1aoaka9aaaBa7azaMvbamaOhba6cbaIafa5sb);
	data_deletealloflist(YTasuba2axaskbhbamhbacnbobaSaPasa7aIafaY);
	for(int i1 = 0; i1 < (int)ScratchVarGetDouble(ScratchSetDouble(10)); i1++)
	{
		YAadadibaRaaanadibaPaoaianat();
		YIELD
	}
	while(1)
	{
		YDaraaawibaPaoaianatas();
		YIELD
	}
}

void YAadadibaRaaanadibaPaoaianat() 
{
#define YIELD
	data_addtolist(operator_random(ScratchSetDouble(-240), ScratchSetDouble(240)), Yba1aoaka9aaaBa7azaMvbamaOhba6cbaIafa5sb);
	data_addtolist(operator_random(ScratchSetDouble(-180), ScratchSetDouble(180)), YTasuba2axaskbhbamhbacnbobaSaPasa7aIafaY);
#define YIELD TRUE_YIELD
}

void YDaraaawibaPaoaianatas() 
{
	data_setvariableto(ScratchSetString("0"), YbajaEakbba4cbaidbcbaFakdbeba8axfbaAaVgbhbamayibavaaaraiaaabalae);
	for(int i1 = 0; i1 < (int)ScratchVarGetDouble(data_lengthoflist(Yba1aoaka9aaaBa7azaMvbamaOhba6cbaIafa5sb)); i1++)
	{
		data_changevariableby(ScratchSetDouble(1), YbajaEakbba4cbaidbcbaFakdbeba8axfbaAaVgbhbamayibavaaaraiaaabalae);
		motion_gotoxy(data_itemoflist(YbajaEakbba4cbaidbcbaFakdbeba8axfbaAaVgbhbamayibavaaaraiaaabalae, Yba1aoaka9aaaBa7azaMvbamaOhba6cbaIafa5sb), data_itemoflist(YbajaEakbba4cbaidbcbaFakdbeba8axfbaAaVgbhbamayibavaaaraiaaabalae, YTasuba2axaskbhbamhbacnbobaSaPasa7aIafaY));
		control_wait_until(sensing_keypressed(sensing_keyoptionsYsapaaacae()));
		control_wait_until(operator_not(sensing_keypressed(sensing_keyoptionsYsapaaacae())));
		YIELD
	}
}

