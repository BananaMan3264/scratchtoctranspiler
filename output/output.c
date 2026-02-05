#define YIELD Yield();
#include "runtime/scratch.h"
#include "runtime/motion.h"
#include "runtime/looks.h"
#include "runtime/operators.h"
#include "runtime/control.h"
#include "runtime/sensing.h"

ScratchValue YbajaEakbba4cbaidbcbaFakdbeba8axfbaAaVgbhbamayibavaaaraiaaabalae;
ScratchValue YbdbabalaaaiayakgbcbayaMfbamnbaaajnbavay;
ScratchValue YbaAwbeba8jbkbwbsbvbapaHamgbaXabgbaCalgb;
ScratchValue YocbgbaLadaJaOa7aOaTa0asnbaqa_aAaFaraKaN;
ScratchValue Yaa6a1ama4mbqbasabaJa_oba_aUaJkbcbasaba5;
ScratchValue YbahmbaqaOata5aGebcbqbaDaoaIacayanubakay;
ScratchValue YbatashbaesbamaMavfbavahaHlbaaaswbpbaZaw;
ScratchValue YbebadaVaFdbauaRa5kbalaMcbcba6qbqbvbqba3;
ScratchValue YzazaqayakrbagazaTaGa3aYvbaeaMobaQkbavkb;
ScratchValue YDwbqbarauarvbayaFaRmbayaflbaNada5gbubaT;
ScratchValue YRanafsba_xba6agaWa9asaua1anaFaOaVfbaUrb;
ScratchValue Y1aVa6ebsbaSaBawaQaMacaFa9pbmbaka8a7amaK;
ScratchValue YbbbakhbxbaGaaakaaaLadabauaxsbatwbaMahap;
ScratchValue Yga_aDa8a5aTqbpbaOaqaQpbaAaEaraPamamjbaR;
ScratchValue Y6ayabakmbasaPayvbdba8aba3aVaFaBa5a_aggb;
ScratchValue Y4a9ebbbapdbahaAobaratnbtbaDahaCa9lbatag;
ScratchValue YoaOaaaYaHaaaJdba5aIbbpbvbabara2anasfbaD;
ScratchValue YsaXaHasa7a7sba9ala1adavaxaAaeaka6a8hbaw;

void Init()
{	YbajaEakbba4cbaidbcbaFakdbeba8axfbaAaVgbhbamayibavaaaraiaaabalae = ScratchSetDouble(0);
	YbdbabalaaaiayakgbcbayaMfbamnbaaajnbavay = ScratchSetDouble(0);
	YbaAwbeba8jbkbwbsbvbapaHamgbaXabgbaCalgb = ScratchSetDouble(0);
	YocbgbaLadaJaOa7aOaTa0asnbaqa_aAaFaraKaN = ScratchSetDouble(0);
	Yaa6a1ama4mbqbasabaJa_oba_aUaJkbcbasaba5 = ScratchSetDouble(0);
	YbahmbaqaOata5aGebcbqbaDaoaIacayanubakay = ScratchSetDouble(0);
	YbatashbaesbamaMavfbavahaHlbaaaswbpbaZaw = ScratchSetDouble(0);
	YbebadaVaFdbauaRa5kbalaMcbcba6qbqbvbqba3 = ScratchSetDouble(0);
	YzazaqayakrbagazaTaGa3aYvbaeaMobaQkbavkb = ScratchSetDouble(0);
	YDwbqbarauarvbayaFaRmbayaflbaNada5gbubaT = ScratchSetDouble(0);
	YRanafsba_xba6agaWa9asaua1anaFaOaVfbaUrb = ScratchSetDouble(0);
	Y1aVa6ebsbaSaBawaQaMacaFa9pbmbaka8a7amaK = ScratchSetDouble(0);
	YbbbakhbxbaGaaakaaaLadabauaxsbatwbaMahap = ScratchSetDouble(0);
	Yga_aDa8a5aTqbpbaOaqaQpbaAaEaraPamamjbaR = ScratchSetDouble(0);
	Y6ayabakmbasaPayvbdba8aba3aVaFaBa5a_aggb = ScratchSetDouble(0);
	Y4a9ebbbapdbahaAobaratnbtbaDahaCa9lbatag = ScratchSetDouble(0);
	YoaOaaaYaHaaaJdba5aIbbpbvbabara2anasfbaD = ScratchSetDouble(0);
	YsaXaHasa7a7sba9ala1adavaxaAaeaka6a8hbaw = ScratchSetDouble(0);
}

void Start();

void Start() 
{
	while(1)
	{
		if(ScratchVarGetBool(sensing_keypressed(sensing_keyoptionsY1())))
		{
			motion_gotoxy(ScratchSetDouble(-100), ScratchSetDouble(-100));
			motion_pointindirection(ScratchSetDouble(-42));
			looks_setsizeto(ScratchSetDouble(200));
		}
		if(ScratchVarGetBool(sensing_keypressed(sensing_keyoptionsY2())))
		{
			motion_gotoxy(ScratchSetDouble(0), ScratchSetDouble(0));
			motion_pointindirection(ScratchSetDouble(90));
			looks_setsizeto(ScratchSetDouble(100));
		}
		YIELD
	}
}

