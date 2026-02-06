#define TRUE_YIELD Yield();
#define YIELD TRUE_YIELD;
#include "runtime/scratch.h"
#include "runtime/motion.h"
#include "runtime/looks.h"
#include "runtime/operators.h"
#include "runtime/control.h"
#include "runtime/sensing.h"
#include "runtime/data.h"
#include "runtime/pen.h"

ScratchValue YbajaEakbba4cbaidbcbaFakdbeba8axfbaAaVgbhbamayibavaaaraiaaabalae;
ScratchValue YbaqaMasaSaKcbaJanahaZpba0mbaDaPaAa2aya4;
ScratchList Yfaqaoagrba4aedba9oba7vbaZaCaUaba6axattb;
ScratchList YsafaLxbaVaZangbbbubaifba7aZawaranaNhbaK;
ScratchList YJaubbamayaLobama7aQa7apfbaoaVaha9aPaKac;
ScratchList YDsbajaxaZqbaaarxba3avaLjbaDaQaFa7aAaga8;

void Init()
{
	YbajaEakbba4cbaidbcbaFakdbeba8axfbaAaVgbhbamayibavaaaraiaaabalae = ScratchSetDouble(0);
	YbaqaMasaSaKcbaJanahaZpba0mbaDaPaAa2aya4 = ScratchSetDouble(10);
	Yfaqaoagrba4aedba9oba7vbaZaCaUaba6axattb = initialiseList();
	YsafaLxbaVaZangbbbubaifba7aZawaranaNhbaK = initialiseList();
	YJaubbamayaLobama7aQa7apfbaoaVaha9aPaKac = initialiseList();
	YDsbajaxaZqbaaarxba3avaLjbaDaQaFa7aAaga8 = initialiseList();
}

void Start();
void YAadadaLaianaeiblbasiblbasiblbasiblbas(ScratchValue Yxa1, ScratchValue Yya1, ScratchValue Yxa2, ScratchValue Yya2);
void YRaeanadaear();

void Start() 
{
	looks_hide();
	while(1)
	{
		YRaeanadaear();
		YIELD
	}
}

void YAadadaLaianaeiblbasiblbasiblbasiblbas(ScratchValue Yxa1, ScratchValue Yya1, ScratchValue Yxa2, ScratchValue Yya2) 
{
#define YIELD
	data_addtolist(argument_reporter_string_number(Yxa1), Yfaqaoagrba4aedba9oba7vbaZaCaUaba6axattb);
	data_addtolist(argument_reporter_string_number(Yya1), YsafaLxbaVaZangbbbubaifba7aZawaranaNhbaK);
	data_addtolist(argument_reporter_string_number(Yxa2), YJaubbamayaLobama7aQa7apfbaoaVaha9aPaKac);
	data_addtolist(argument_reporter_string_number(Yya2), YDsbajaxaZqbaaarxba3avaLjbaDaQaFa7aAaga8);
#define YIELD TRUE_YIELD
}

void YRaeanadaear() 
{
#define YIELD
	data_deletealloflist(Yfaqaoagrba4aedba9oba7vbaZaCaUaba6axattb);
	data_deletealloflist(YJaubbamayaLobama7aQa7apfbaoaVaha9aPaKac);
	data_deletealloflist(YsafaLxbaVaZangbbbubaifba7aZawaranaNhbaK);
	data_deletealloflist(YDsbajaxaZqbaaarxba3avaLjbaDaQaFa7aAaga8);
	for(int i1 = 0; i1 < (int)ScratchVarGetDouble(ScratchSetDouble(10)); i1++)
	{
		YAadadaLaianaeiblbasiblbasiblbasiblbas(operator_random(ScratchSetDouble(-240), ScratchSetDouble(240)), operator_random(ScratchSetDouble(-180), ScratchSetDouble(180)), operator_random(ScratchSetDouble(-240), ScratchSetDouble(240)), operator_random(ScratchSetDouble(-180), ScratchSetDouble(180)));
		YIELD
	}
	pen_clear();
	data_setvariableto(ScratchSetString("0"), YbaqaMasaSaKcbaJanahaZpba0mbaDaPaAa2aya4);
	for(int i1 = 0; i1 < (int)ScratchVarGetDouble(data_lengthoflist(Yfaqaoagrba4aedba9oba7vbaZaCaUaba6axattb)); i1++)
	{
		data_changevariableby(ScratchSetDouble(1), YbaqaMasaSaKcbaJanahaZpba0mbaDaPaAa2aya4);
		motion_gotoxy(data_itemoflist(YbaqaMasaSaKcbaJanahaZpba0mbaDaPaAa2aya4, Yfaqaoagrba4aedba9oba7vbaZaCaUaba6axattb), data_itemoflist(YbaqaMasaSaKcbaJanahaZpba0mbaDaPaAa2aya4, YsafaLxbaVaZangbbbubaifba7aZawaranaNhbaK));
		pen_penDown();
		motion_gotoxy(data_itemoflist(YbaqaMasaSaKcbaJanahaZpba0mbaDaPaAa2aya4, YJaubbamayaLobama7aQa7apfbaoaVaha9aPaKac), data_itemoflist(YbaqaMasaSaKcbaJanahaZpba0mbaDaPaAa2aya4, YDsbajaxaZqbaaarxba3avaLjbaDaQaFa7aAaga8));
		pen_penUp();
		YIELD
	}
#define YIELD TRUE_YIELD
}

