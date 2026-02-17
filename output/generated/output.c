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

ScratchValue YaiaQlbaUaAaGrbaVaQsbada0awapaMaWaiwba1an;
ScratchValue Ya9aDakaWobqbaDaRaCa0aBaCaMawjbrba0avaXaQ;
ScratchValue YvbobahalsbaPabAb1ba6a_dba7a7nbauobpbtba_;
ScratchValue YaZcbaKahxbaiaIawaOxbaPebaqnba0dbmbqbaNas;
ScratchValue YaYaRa0abaPazamaSa4agsbafaNazawbbaKakaxaA;
ScratchValue Ya9fbaOaVaXaaa2axobadlbaSAblbAbanaHaYaQa4;
ScratchValue YqbaKaxanlbadataaaCaSebaaaKaoaOa8a3a7gbaz;
ScratchValue YaWqba0fbaHaralawaMaCajauaraNa8aWebrbgba0;
ScratchValue YqbapaKobrbaVaLaMpbnbaNwba9AbaWa0aTrbaiaM;
ScratchValue YagcbkbebebtbadjbhbwbqbaoubaSaZhbamwblbhb;
ScratchValue Yrbaga7axaDagaYafa5aeaIaasbagubobaua4aQwb;
ScratchValue YkbaladaWaNaoaba7obqbsbxbabacrbaYamaxaSbb;
ScratchValue Ynbawa9aIalaAeba_aWbbaCqbaAa0ahaka_aNpbtb;
ScratchValue YaFebaOaKaJalabtbaMacaFaPaEaTaBawa4aeaUaD;
ScratchValue YaJasa2aOnbaxalagaWanazpbaadbara9gbgbagnb;
ScratchValue Ya4a6alaIa1fbaSdbrbdbkbadqbaIakaIa4wbebaU;
ScratchValue YobaHajubanaTavaTa7aqa8AbaSapaNakAbaFa8ak;
ScratchValue Yaoa5akangbjbaapbaYava3akqbcbcbhbpba0araV;
ScratchValue Ypba8obaXoba7aqa3aZjbaiebobwbpbaAvbaJausb;
ScratchValue Yazuba8a8aJdba4aragacobaKeba5rbaIgbaiaUam;
ScratchValue YaHaGhbqbapa3a8aEaXaxaCaxaRaoamanaEampbaF;
ScratchValue YaCaDlbaCaMadaGac1baMa5wbnbpbasaKaEaJkbar;
ScratchValue YaLa9aTnbajaj1baparata8aIagaAazaQAbabaZub;
ScratchValue Ya2anaUebakaRrbkbaQqbcba7AbaIa0dbtbsbagaq;
ScratchValue Yobaqa6akaxubaNbbwbxbxbawara_aSa2xbaOAbay;
ScratchValue Ycbubpba1adaoalaYaJasaHanaga9aFaSaiaCa_az;
ScratchValue YaGaFa6aHa9avkba8aNa5tbadcbaPwba4apaaa6ao;
ScratchValue Yagapa2adbbqbapaKaOalaAuba9a7a9aBmbaPdbrb;
ScratchValue YaRahaKaHaWvbaTa1aHaEawaL1bwbataBa_aJaRaz;
ScratchValue YaFaXa7ama3atjbaegbaKaYavazaNauaKaFnbmbar;
ScratchValue YcbaAxbaJahaFaldbsba9aqasalaahba2sbcbaKa5;
ScratchValue YaOapkbaga8aeaBa0aiawaha2aQaUamawaZrblbaY;
ScratchValue YobaLadcbgbantbawaUuba0aDaKvbsbalaUa1aZaT;
ScratchValue YdbrbhbaMjbaIaYaVacaExbaIaaaIa5aEazrbaAaS;
ScratchValue Ydba81baoaiaQa8cbdbamaNa3aTaiaIaTtbaBaavb;
ScratchValue Ya6aLcbnba7qbacaYaZgbfbpbaRa2fbbba3ahamax;
ScratchValue YnbcbaBauaXaNebhbAbazaFqbaraPaqaIaeavaGay;
ScratchValue YebaBaKaNaJaSqbaqawaYauebaOaMhbcbaFcbaeaI;
ScratchValue YaBaeaBaaahcbaFaua6fbaGaljbaOagqbaFadaia_;
ScratchValue YacaQaFaVaLfbaWoba7fbaiaxaCazaBaJauhba0aC;
ScratchValue YahaXaza3a3AbaCa_ebaqaBaxjbwbdbaHwbakkbaA;
ScratchValue Ya8lbqbAbasaDarkblbaIarabobmbfbacabaEayad;
ScratchValue YobaambanvbaHkbanauacaiaanbaArbbbuba2cbAb;
ScratchValue YasaLlbawaFaEa1aua6au1baHazxbagahxbaeaAcb;
ScratchValue YwbrbaraWaHama5aTa7aaqbfbaaaLnbcbaoatpbaG;
ScratchValue YatajaJaxafaTaiaAa3qbampbahaYawcbaIahaLao;
ScratchValue YqbaAqbalaGaSaXaombaWaRaiaOa0aDobaXaoar1b;
ScratchValue YaLaFaQakayacaNaZaGxbqbaEmbagaoaGrbbbawrb;
ScratchValue Yaoana1aNazaBaprbgba1aEnba_a1ayaba21ba2aP;
ScratchValue Yaka3aEnbapgbaaa0alabkbaaaflbaffbAbhbaFwb;
ScratchValue YaKbbwbaWubaoadhbqbabaYadapaDajnba_apaoaD;
ScratchValue YagahaQa5a2xbobdbaHaMpbgbawaNebkbaZa0anal;
ScratchValue Ya0hbaCa3xbaSvbadaLauaG1baWayasdbaKobajaw;
ScratchValue YaCaCAb1bwbaYaHa_aZwbcbdbaWahamaI1baKjbam;
ScratchValue YebaUsbaeaBrba7amaQavahara0aJazaJebobAba9;
ScratchValue Ya0a_awaYaYaJa2gbaYa9aHaQ1bpbebebjbafcbaw;
ScratchValue YaPnba7aSankbaAamaFaAajdbfbmbhbazAba5aYaD;
ScratchValue YacaFfbaoanaplbalaMsbaFaoubjbapfbobafqbaU;
ScratchValue Yub1bgbxba2aorbfbaVafauaRaFubakdbaMakhbak;
ScratchValue Yrba6vbadaDa8a4ata2aZa8hbfbaKabaCaYtbrbaB;
ScratchValue YwbkbaHa_fbdbpbdbaLobvba5aaayaDaYvbpbasaa;
ScratchValue YafaUpbaWa7aAaFajamnbAbata5a7aGa1eblbaJa1;
ScratchValue YayanebaYana1ahagaKjbaba8ajaMagqbaeqbalaC;
ScratchValue Yjba8aZaNcbcbadaPubapaMawajaAaKcbaCa3bbaF;
ScratchValue YathbgbaAaraAaSaccbrbmbnbaUafa0qbaFdba9cb;
ScratchValue YaNaiagobaZaMalaXwbaadbaJagaOamlba7aZhbaW;
ScratchValue YaHaHasubaPaIahaYazlbqbbbaoa0a4ebsbaOa4eb;
ScratchValue YaSaJaOazrba9aGaFaKaqaJvbazafaOaohbaFaGmb;

ScratchValue* vars[] = 
{	&YaiaQlbaUaAaGrbaVaQsbada0awapaMaWaiwba1an,
	&Ya9aDakaWobqbaDaRaCa0aBaCaMawjbrba0avaXaQ,
	&YvbobahalsbaPabAb1ba6a_dba7a7nbauobpbtba_,
	&YaZcbaKahxbaiaIawaOxbaPebaqnba0dbmbqbaNas,
	&YaYaRa0abaPazamaSa4agsbafaNazawbbaKakaxaA,
	&Ya9fbaOaVaXaaa2axobadlbaSAblbAbanaHaYaQa4,
	&YqbaKaxanlbadataaaCaSebaaaKaoaOa8a3a7gbaz,
	&YaWqba0fbaHaralawaMaCajauaraNa8aWebrbgba0,
	&YqbapaKobrbaVaLaMpbnbaNwba9AbaWa0aTrbaiaM,
	&YagcbkbebebtbadjbhbwbqbaoubaSaZhbamwblbhb,
	&Yrbaga7axaDagaYafa5aeaIaasbagubobaua4aQwb,
	&YkbaladaWaNaoaba7obqbsbxbabacrbaYamaxaSbb,
	&Ynbawa9aIalaAeba_aWbbaCqbaAa0ahaka_aNpbtb,
	&YaFebaOaKaJalabtbaMacaFaPaEaTaBawa4aeaUaD,
	&YaJasa2aOnbaxalagaWanazpbaadbara9gbgbagnb,
	&Ya4a6alaIa1fbaSdbrbdbkbadqbaIakaIa4wbebaU,
	&YobaHajubanaTavaTa7aqa8AbaSapaNakAbaFa8ak,
	&Yaoa5akangbjbaapbaYava3akqbcbcbhbpba0araV,
	&Ypba8obaXoba7aqa3aZjbaiebobwbpbaAvbaJausb,
	&Yazuba8a8aJdba4aragacobaKeba5rbaIgbaiaUam,
	&YaHaGhbqbapa3a8aEaXaxaCaxaRaoamanaEampbaF,
	&YaCaDlbaCaMadaGac1baMa5wbnbpbasaKaEaJkbar,
	&YaLa9aTnbajaj1baparata8aIagaAazaQAbabaZub,
	&Ya2anaUebakaRrbkbaQqbcba7AbaIa0dbtbsbagaq,
	&Yobaqa6akaxubaNbbwbxbxbawara_aSa2xbaOAbay,
	&Ycbubpba1adaoalaYaJasaHanaga9aFaSaiaCa_az,
	&YaGaFa6aHa9avkba8aNa5tbadcbaPwba4apaaa6ao,
	&Yagapa2adbbqbapaKaOalaAuba9a7a9aBmbaPdbrb,
	&YaRahaKaHaWvbaTa1aHaEawaL1bwbataBa_aJaRaz,
	&YaFaXa7ama3atjbaegbaKaYavazaNauaKaFnbmbar,
	&YcbaAxbaJahaFaldbsba9aqasalaahba2sbcbaKa5,
	&YaOapkbaga8aeaBa0aiawaha2aQaUamawaZrblbaY,
	&YobaLadcbgbantbawaUuba0aDaKvbsbalaUa1aZaT,
	&YdbrbhbaMjbaIaYaVacaExbaIaaaIa5aEazrbaAaS,
	&Ydba81baoaiaQa8cbdbamaNa3aTaiaIaTtbaBaavb,
	&Ya6aLcbnba7qbacaYaZgbfbpbaRa2fbbba3ahamax,
	&YnbcbaBauaXaNebhbAbazaFqbaraPaqaIaeavaGay,
	&YebaBaKaNaJaSqbaqawaYauebaOaMhbcbaFcbaeaI,
	&YaBaeaBaaahcbaFaua6fbaGaljbaOagqbaFadaia_,
	&YacaQaFaVaLfbaWoba7fbaiaxaCazaBaJauhba0aC,
	&YahaXaza3a3AbaCa_ebaqaBaxjbwbdbaHwbakkbaA,
	&Ya8lbqbAbasaDarkblbaIarabobmbfbacabaEayad,
	&YobaambanvbaHkbanauacaiaanbaArbbbuba2cbAb,
	&YasaLlbawaFaEa1aua6au1baHazxbagahxbaeaAcb,
	&YwbrbaraWaHama5aTa7aaqbfbaaaLnbcbaoatpbaG,
	&YatajaJaxafaTaiaAa3qbampbahaYawcbaIahaLao,
	&YqbaAqbalaGaSaXaombaWaRaiaOa0aDobaXaoar1b,
	&YaLaFaQakayacaNaZaGxbqbaEmbagaoaGrbbbawrb,
	&Yaoana1aNazaBaprbgba1aEnba_a1ayaba21ba2aP,
	&Yaka3aEnbapgbaaa0alabkbaaaflbaffbAbhbaFwb,
	&YaKbbwbaWubaoadhbqbabaYadapaDajnba_apaoaD,
	&YagahaQa5a2xbobdbaHaMpbgbawaNebkbaZa0anal,
	&Ya0hbaCa3xbaSvbadaLauaG1baWayasdbaKobajaw,
	&YaCaCAb1bwbaYaHa_aZwbcbdbaWahamaI1baKjbam,
	&YebaUsbaeaBrba7amaQavahara0aJazaJebobAba9,
	&Ya0a_awaYaYaJa2gbaYa9aHaQ1bpbebebjbafcbaw,
	&YaPnba7aSankbaAamaFaAajdbfbmbhbazAba5aYaD,
	&YacaFfbaoanaplbalaMsbaFaoubjbapfbobafqbaU,
	&Yub1bgbxba2aorbfbaVafauaRaFubakdbaMakhbak,
	&Yrba6vbadaDa8a4ata2aZa8hbfbaKabaCaYtbrbaB,
	&YwbkbaHa_fbdbpbdbaLobvba5aaayaDaYvbpbasaa,
	&YafaUpbaWa7aAaFajamnbAbata5a7aGa1eblbaJa1,
	&YayanebaYana1ahagaKjbaba8ajaMagqbaeqbalaC,
	&Yjba8aZaNcbcbadaPubapaMawajaAaKcbaCa3bbaF,
	&YathbgbaAaraAaSaccbrbmbnbaUafa0qbaFdba9cb,
	&YaNaiagobaZaMalaXwbaadbaJagaOamlba7aZhbaW,
	&YaHaHasubaPaIahaYazlbqbbbaoa0a4ebsbaOa4eb,
	&YaSaJaOazrba9aGaFaKaqaJvbazafaOaohbaFaGmb,
};

ScratchList YataEaMaQaZa6qbpbaRxbobrbaGhbaCa9aUaXobaU;
ScratchList Y1ba5avcbaPamapubqbtbkbawakaaaaaYxbhbalbb;
ScratchList YjbaspbaRkbadaAaTxbasa1aBacada6aZaE1bgbaU;
ScratchList Yaga7obqbaNaha3aLaQAbauaRmbavaraclbanaoar;
ScratchList YaZaoaBaraRa0mbaffbaxaNubaaebacaroba9aGqb;
ScratchList YfbagwbAbasaKcbuba4avaSaSaRaxkbaYajaJaTa8;
ScratchList Ya5avaBazaHadnbapa_bbaLa3abdbkbebhbmbobwb;
ScratchList YaLafpbagjbaflbaTawtbayacagcbaO1bqbaoxba5;

ScratchList* lists[] = 
{	&YataEaMaQaZa6qbpbaRxbobrbaGhbaCa9aUaXobaU,
	&Y1ba5avcbaPamapubqbtbkbawakaaaaaYxbhbalbb,
	&YjbaspbaRkbadaAaTxbasa1aBacada6aZaE1bgbaU,
	&Yaga7obqbaNaha3aLaQAbauaRmbavaraclbanaoar,
	&YaZaoaBaraRa0mbaffbaxaNubaaebacaroba9aGqb,
	&YfbagwbAbasaKcbuba4avaSaSaRaxkbaYajaJaTa8,
	&Ya5avaBazaHadnbapa_bbaLa3abdbkbebhbmbobwb,
	&YaLafpbagjbaflbaTawtbayacagcbaO1bqbaoxba5,
};

int vars_length = 68, lists_length = 8;

void _0_Init()
{
	YaiaQlbaUaAaGrbaVaQsbada0awapaMaWaiwba1an = ScratchSetDouble(0);
	Ya9aDakaWobqbaDaRaCa0aBaCaMawjbrba0avaXaQ = ScratchSetDouble(-0.971632);
	YvbobahalsbaPabAb1ba6a_dba7a7nbauobpbtba_ = ScratchSetDouble(0);
	YaZcbaKahxbaiaIawaOxbaPebaqnba0dbmbqbaNas = ScratchSetDouble(1);
	YaYaRa0abaPazamaSa4agsbafaNazawbbaKakaxaA = ScratchSetDouble(-0.236499);
	Ya9fbaOaVaXaaa2axobadlbaSAblbAbanaHaYaQa4 = ScratchSetDouble(1);
	YqbaKaxanlbadataaaCaSebaaaKaoaOa8a3a7gbaz = ScratchSetDouble(-1.418994);
	YaWqba0fbaHaralawaMaCajauaraNa8aWebrbgba0 = ScratchSetDouble(-5);
	YqbapaKobrbaVaLaMpbnbaNwba9AbaWa0aTrbaiaM = ScratchSetDouble(18.829790);
	YagcbkbebebtbadjbhbwbqbaoubaSaZhbamwblbhb = ScratchSetDouble(172800);
	Yrbaga7axaDagaYafa5aeaIaasbagubobaua4aQwb = ScratchSetDouble(3);
	YkbaladaWaNaoaba7obqbsbxbabacrbaYamaxaSbb = ScratchSetDouble(-4.521539);
	Ynbawa9aIalaAeba_aWbbaCqbaAa0ahaka_aNpbtb = ScratchSetDouble(-24.980308);
	YaFebaOaKaJalabtbaMacaFaPaEaTaBawa4aeaUaD = ScratchSetDouble(-30.203544);
	YaJasa2aOnbaxalagaWanazpbaadbara9gbgbagnb = ScratchSetDouble(-15.932201);
	Ya4a6alaIa1fbaSdbrbdbkbadqbaIakaIa4wbebaU = ScratchSetDouble(-17.230688);
	YobaHajubanaTavaTa7aqa8AbaSapaNakAbaFa8ak = ScratchSetDouble(-25.904485);
	Yaoa5akangbjbaapbaYava3akqbcbcbhbpba0araV = ScratchSetDouble(-7.865583);
	Ypba8obaXoba7aqa3aZjbaiebobwbpbaAvbaJausb = ScratchSetDouble(-17.230688);
	Yazuba8a8aJdba4aragacobaKeba5rbaIgbaiaUam = ScratchSetDouble(0.869790);
	YaHaGhbqbapa3a8aEaXaxaCaxaRaoamanaEampbaF = ScratchSetDouble(0.602186);
	YaCaDlbaCaMadaGac1baMa5wbnbpbasaKaEaJkbar = ScratchSetDouble(-24.783874);
	YaLa9aTnbajaj1baparata8aIagaAazaQAbabaZub = ScratchSetDouble(-7.025501);
	Ya2anaUebakaRrbkbaQqbcba7AbaIa0dbtbsbagaq = ScratchSetDouble(0);
	Yobaqa6akaxubaNbbwbxbxbawara_aSa2xbaOAbay = ScratchSetDouble(2.575338);
	Ycbubpba1adaoalaYaJasaHanaga9aFaSaiaCa_az = ScratchSetDouble(-25);
	YaGaFa6aHa9avkba8aNa5tbadcbaPwba4apaaa6ao = ScratchSetDouble(-10);
	Yagapa2adbbqbapaKaOalaAuba9a7a9aBmbaPdbrb = ScratchSetDouble(0);
	YaRahaKaHaWvbaTa1aHaEawaL1bwbataBa_aJaRaz = ScratchSetDouble(1);
	YaFaXa7ama3atjbaegbaKaYavazaNauaKaFnbmbar = ScratchSetDouble(1);
	YcbaAxbaJahaFaldbsba9aqasalaahba2sbcbaKa5 = ScratchSetDouble(1);
	YaOapkbaga8aeaBa0aiawaha2aQaUamawaZrblbaY = ScratchSetDouble(1);
	YobaLadcbgbantbawaUuba0aDaKvbsbalaUa1aZaT = ScratchSetDouble(0.130210);
	YdbrbhbaMjbaIaYaVacaExbaIaaaIa5aEazrbaAaS = ScratchSetDouble(0);
	Ydba81baoaiaQa8cbdbamaNa3aTaiaIaTtbaBaavb = ScratchSetDouble(0.869790);
	Ya6aLcbnba7qbacaYaZgbfbpbaRa2fbbba3ahamax = ScratchSetDouble(0.115290);
	YnbcbaBauaXaNebhbAbazaFqbaraPaqaIaeavaGay = ScratchSetDouble(0);
	YebaBaKaNaJaSqbaqawaYauebaOaMhbcbaFcbaeaI = ScratchSetDouble(1);
	YaBaeaBaaahcbaFaua6fbaGaljbaOagqbaFadaia_ = ScratchSetDouble(0.097499);
	YacaQaFaVaLfbaWoba7fbaiaxaCazaBaJauhba0aC = ScratchSetDouble(1.037608);
	YahaXaza3a3AbaCa_ebaqaBaxjbwbdbaHwbakkbaA = ScratchSetDouble(0.902501);
	Ya8lbqbAbasaDarkblbaIarabobmbfbacabaEayad = ScratchSetDouble(0.100278);
	YobaambanvbaHkbanauacaiaanbaArbbbuba2cbAb = ScratchSetDouble(-0.100278);
	YasaLlbawaFaEa1aua6au1baHazxbagahxbaeaAcb = ScratchSetDouble(1);
	YwbrbaraWaHama5aTa7aaqbfbaaaLnbcbaoatpbaG = ScratchSetDouble(0.197777);
	YatajaJaxafaTaiaAa3qbampbahaYawcbaIahaLao = ScratchSetDouble(0.922318);
	YqbaAqbalaGaSaXaombaWaRaiaOa0aDobaXaoar1b = ScratchSetDouble(0.802223);
	YaLaFaQakayacaNaZaGxbqbaEmbagaoaGrbbbawrb = ScratchSetDouble(-0.053482);
	Yaoana1aNazaBaprbgba1aEnba_a1ayaba21ba2aP = ScratchSetDouble(-0.008006);
	Yaka3aEnbapgbaaa0alabkbaaaflbaffbAbhbaFwb = ScratchSetDouble(0.197777);
	YaKbbwbaWubaoadhbqbabaYadapaDajnba_apaoaD = ScratchSetDouble(0.802223);
	YagahaQa5a2xbobdbaHaMpbgbawaNebkbaZa0anal = ScratchSetDouble(18.829790);
	Ya0hbaCa3xbaSvbadaLauaG1baWayasdbaKobajaw = ScratchSetDouble(17.410796);
	YaCaCAb1bwbaYaHa_aZwbcbdbaWahamaI1baKjbam = ScratchSetDouble(11.581006);
	YebaUsbaeaBrba7amaQavahara0aJazaJebobAba9 = ScratchSetDouble(17.885929);
	Ya0a_awaYaYaJa2gbaYa9aHaQ1bpbebebjbafcbaw = ScratchSetDouble(0.672115);
	YaPnba7aSankbaAamaFaAajdbfbmbhbazAba5aYaD = ScratchSetDouble(0.726893);
	YacaFfbaoanaplbalaMsbaFaoubjbapfbobafqbaU = ScratchSetDouble(17.630042);
	Yub1bgbxba2aorbfbaVafauaRaFubakdbaMakhbak = ScratchSetDouble(18.123043);
	Yrba6vbadaDa8a4ata2aZa8hbfbaKabaCaYtbrbaB = ScratchSetDouble(16.957927);
	YwbkbaHa_fbdbpbdbaLobvba5aaayaDaYvbpbasaa = ScratchSetDouble(17.396150);
	YafaUpbaWa7aAaFajamnbAbata5a7aGa1eblbaJa1 = ScratchSetDouble(17.396150);
	YayanebaYana1ahagaKjbaba8ajaMagqbaeqbalaC = ScratchSetDouble(0.029215);
	Yjba8aZaNcbcbadaPubapaMawajaAaKcbaCa3bbaF = ScratchSetDouble(1);
	YathbgbaAaraAaSaccbrbmbnbaUafa0qbaFdba9cb = ScratchSetDouble(60);
	YaNaiagobaZaMalaXwbaadbaJagaOamlba7aZhbaW = ScratchSetDouble(240);
	YaHaHasubaPaIahaYazlbqbbbaoa0a4ebsbaOa4eb = ScratchSetDouble(180);
	YaSaJaOazrba9aGaFaKaqaJvbazafaOaohbaFaGmb = ScratchSetDouble(-16.904485);
	YataEaMaQaZa6qbpbaRxbobrbaGhbaCa9aUaXobaU = initialiseList();
	Y1ba5avcbaPamapubqbtbkbawakaaaaaYxbhbalbb = initialiseList();
	YjbaspbaRkbadaAaTxbasa1aBacada6aZaE1bgbaU = initialiseList();
	Yaga7obqbaNaha3aLaQAbauaRmbavaraclbanaoar = initialiseList();
	YaZaoaBaraRa0mbaffbaxaNubaaebacaroba9aGqb = initialiseList();
	YfbagwbAbasaKcbuba4avaSaSaRaxkbaYajaJaTa8 = initialiseList();
	Ya5avaBazaHadnbapa_bbaLa3abdbkbebhbmbobwb = initialiseList();
	YaLafpbagjbaflbaTawtbayacagcbaO1bqbaoxba5 = initialiseList();
}



void _1_Init()
{
}

void _1_YafaWevent_whenflagclicked();
void YaSaeatibaMaoadaealibaMaaataraiaxkbibaPaoasiblbasiblbasiblbasibaSacaaalaeiblbasiblbasiblbasibaRaoataaataiaoaniblbasiblbasiblbas(ScratchValue Yapax, ScratchValue Yapay, ScratchValue Yapaz, ScratchValue Yasax, ScratchValue Yasay, ScratchValue Yasaz, ScratchValue Yarax, ScratchValue Yaray, ScratchValue Yaraz);
void YaAapapalayibaMaoadaealibaMaaataraiax();
void YaDaraaawibaTaraiaaanagalaeas();
void Y();
void YaRaaasataearaiasaeibaTaraiaaanagalaeiblbasiblbasiblbasiblbasiblbasiblbasiblbasiblbasiblbasiblbasiblbasiblbasiblbasiblbasiblbas(ScratchValue Yaxa1, ScratchValue Yaya1, ScratchValue Yaxa2, ScratchValue Yaya2, ScratchValue Yaxa3, ScratchValue Yaya3, ScratchValue Yaua1, ScratchValue Yaua2, ScratchValue Yaua3, ScratchValue Yava1, ScratchValue Yava2, ScratchValue Yava3, ScratchValue Yaza1, ScratchValue Yaza2, ScratchValue Yaza3);
void YaSaeatibaCaoalaoauariblbasiblbas(ScratchValue Yau, ScratchValue Yav);
void YaSaeataCaoalaoauaraBayaDaiasataaanacaeiblbas(ScratchValue Yad);
void YaSaeataZaBauafafaeariblbasiblbasiblbas(ScratchValue Yax, ScratchValue Yay, ScratchValue Yaz);
void YaSaeataCaoalaBauafafaeariblbasiblbasiblbas(ScratchValue Yax, ScratchValue Yay, ScratchValue YaCaoal);
void YaCalaeaaaribaBauafafaearas();
void YaDaraaawaRaaasataear();

void _1_YafaWevent_whenflagclicked() 
{
	activeSprite = 1;
	while(1)
	{
		data_deletealloflist(Yaga7obqbaNaha3aLaQAbauaRmbavaraclbanaoar);
		data_deletealloflist(YataEaMaQaZa6qbpbaRxbobrbaGhbaCa9aUaXobaU);
		data_deletealloflist(Y1ba5avcbaPamapubqbtbkbawakaaaaaYxbhbalbb);
		data_deletealloflist(YjbaspbaRkbadaAaTxbasa1aBacada6aZaE1bgbaU);
		data_deletealloflist(YaZaoaBaraRa0mbaffbaxaNubaaebacaroba9aGqb);
		data_deletealloflist(YfbagwbAbasaKcbuba4avaSaSaRaxkbaYajaJaTa8);
		YaSaeatibaMaoadaealibaMaaataraiaxkbibaPaoasiblbasiblbasiblbasibaSacaaalaeiblbasiblbasiblbasibaRaoataaataiaoaniblbasiblbasiblbas(ScratchSetDouble(0), ScratchSetDouble(-5), ScratchSetDouble(13), ScratchSetDouble(6), ScratchSetDouble(6), ScratchSetDouble(6), ScratchSetDouble(0), ScratchSetDouble(((ScratchVarGetDouble(sensing_timer())) * (90))), ScratchSetDouble(0));
		data_addtolist(ScratchSetDouble(0), YataEaMaQaZa6qbpbaRxbobrbaGhbaCa9aUaXobaU);
		data_addtolist(ScratchSetDouble(0), Y1ba5avcbaPamapubqbtbkbawakaaaaaYxbhbalbb);
		data_addtolist(ScratchSetDouble(0), YjbaspbaRkbadaAaTxbasa1aBacada6aZaE1bgbaU);
		data_addtolist(ScratchSetDouble(1), YaZaoaBaraRa0mbaffbaxaNubaaebacaroba9aGqb);
		data_addtolist(ScratchSetDouble(1), YfbagwbAbasaKcbuba4avaSaSaRaxkbaYajaJaTa8);
		data_addtolist(ScratchSetDouble(0), YataEaMaQaZa6qbpbaRxbobrbaGhbaCa9aUaXobaU);
		data_addtolist(ScratchSetDouble(0), Y1ba5avcbaPamapubqbtbkbawakaaaaaYxbhbalbb);
		data_addtolist(ScratchSetDouble(1), YjbaspbaRkbadaAaTxbasa1aBacada6aZaE1bgbaU);
		data_addtolist(ScratchSetDouble(1), YaZaoaBaraRa0mbaffbaxaNubaaebacaroba9aGqb);
		data_addtolist(ScratchSetDouble(0), YfbagwbAbasaKcbuba4avaSaSaRaxkbaYajaJaTa8);
		data_addtolist(ScratchSetDouble(1), YataEaMaQaZa6qbpbaRxbobrbaGhbaCa9aUaXobaU);
		data_addtolist(ScratchSetDouble(0), Y1ba5avcbaPamapubqbtbkbawakaaaaaYxbhbalbb);
		data_addtolist(ScratchSetDouble(0), YjbaspbaRkbadaAaTxbasa1aBacada6aZaE1bgbaU);
		data_addtolist(ScratchSetDouble(0), YaZaoaBaraRa0mbaffbaxaNubaaebacaroba9aGqb);
		data_addtolist(ScratchSetDouble(1), YfbagwbAbasaKcbuba4avaSaSaRaxkbaYajaJaTa8);
		Y();
		data_addtolist(ScratchSetDouble(1), YataEaMaQaZa6qbpbaRxbobrbaGhbaCa9aUaXobaU);
		data_addtolist(ScratchSetDouble(0), Y1ba5avcbaPamapubqbtbkbawakaaaaaYxbhbalbb);
		data_addtolist(ScratchSetDouble(1), YjbaspbaRkbadaAaTxbasa1aBacada6aZaE1bgbaU);
		data_addtolist(ScratchSetDouble(1), YaZaoaBaraRa0mbaffbaxaNubaaebacaroba9aGqb);
		data_addtolist(ScratchSetDouble(1), YfbagwbAbasaKcbuba4avaSaSaRaxkbaYajaJaTa8);
		data_addtolist(ScratchSetDouble(0), YataEaMaQaZa6qbpbaRxbobrbaGhbaCa9aUaXobaU);
		data_addtolist(ScratchSetDouble(0), Y1ba5avcbaPamapubqbtbkbawakaaaaaYxbhbalbb);
		data_addtolist(ScratchSetDouble(1), YjbaspbaRkbadaAaTxbasa1aBacada6aZaE1bgbaU);
		data_addtolist(ScratchSetDouble(1), YaZaoaBaraRa0mbaffbaxaNubaaebacaroba9aGqb);
		data_addtolist(ScratchSetDouble(0), YfbagwbAbasaKcbuba4avaSaSaRaxkbaYajaJaTa8);
		data_addtolist(ScratchSetDouble(1), YataEaMaQaZa6qbpbaRxbobrbaGhbaCa9aUaXobaU);
		data_addtolist(ScratchSetDouble(0), Y1ba5avcbaPamapubqbtbkbawakaaaaaYxbhbalbb);
		data_addtolist(ScratchSetDouble(0), YjbaspbaRkbadaAaTxbasa1aBacada6aZaE1bgbaU);
		data_addtolist(ScratchSetDouble(0), YaZaoaBaraRa0mbaffbaxaNubaaebacaroba9aGqb);
		data_addtolist(ScratchSetDouble(1), YfbagwbAbasaKcbuba4avaSaSaRaxkbaYajaJaTa8);
		Y();
		YaAapapalayibaMaoadaealibaMaaataraiax();
		data_setvariableto(ScratchSetDouble(((180) / (double)(ScratchVarGetDouble(Yjba8aZaNcbcbadaPubapaMawajaAaKcbaCa3bbaF)))), YaHaHasubaPaIahaYazlbqbbbaoa0a4ebsbaOa4eb);
		data_setvariableto(ScratchSetDouble(((240) / (double)(ScratchVarGetDouble(Yjba8aZaNcbcbadaPubapaMawajaAaKcbaCa3bbaF)))), YaNaiagobaZaMalaXwbaadbaJagaOamlba7aZhbaW);
		YaCalaeaaaribaBauafafaearas();
		YaDaraaawibaTaraiaaanagalaeas();
		YaDaraaawaRaaasataear();
		YIELD
	}
#define YIELD TRUE_YIELD
	END_THREAD
}

void YaSaeatibaMaoadaealibaMaaataraiaxkbibaPaoasiblbasiblbasiblbasibaSacaaalaeiblbasiblbasiblbasibaRaoataaataiaoaniblbasiblbasiblbas(ScratchValue Yapax, ScratchValue Yapay, ScratchValue Yapaz, ScratchValue Yasax, ScratchValue Yasay, ScratchValue Yasaz, ScratchValue Yarax, ScratchValue Yaray, ScratchValue Yaraz) 
{
	activeSprite = 1;
#define YIELD
	data_setvariableto(operator_mathopYasaian(argument_reporter_string_number(Yarax)), YaiaQlbaUaAaGrbaVaQsbada0awapaMaWaiwba1an);
	data_setvariableto(operator_mathopYasaian(argument_reporter_string_number(Yaray)), Ya9aDakaWobqbaDaRaCa0aBaCaMawjbrba0avaXaQ);
	data_setvariableto(operator_mathopYasaian(argument_reporter_string_number(Yaraz)), YvbobahalsbaPabAb1ba6a_dba7a7nbauobpbtba_);
	data_setvariableto(operator_mathopYacaoas(argument_reporter_string_number(Yarax)), YaZcbaKahxbaiaIawaOxbaPebaqnba0dbmbqbaNas);
	data_setvariableto(operator_mathopYacaoas(argument_reporter_string_number(Yaray)), YaYaRa0abaPazamaSa4agsbafaNazawbbaKakaxaA);
	data_setvariableto(operator_mathopYacaoas(argument_reporter_string_number(Yaraz)), Ya9fbaOaVaXaaa2axobadlbaSAblbAbanaHaYaQa4);
	data_deletealloflist(Yaga7obqbaNaha3aLaQAbauaRmbavaraclbanaoar);
	data_addtolist(ScratchSetDouble((((((ScratchVarGetDouble(YaYaRa0abaPazamaSa4agsbafaNazawbbaKakaxaA)) * (ScratchVarGetDouble(Ya9fbaOaVaXaaa2axobadlbaSAblbAbanaHaYaQa4))))) * (ScratchVarGetDouble(argument_reporter_string_number(Yasax))))), Yaga7obqbaNaha3aLaQAbauaRmbavaraclbanaoar);
	data_addtolist(ScratchSetDouble(((ScratchVarGetDouble(argument_reporter_string_number(Yasay))) * ((((((((((ScratchVarGetDouble(YaiaQlbaUaAaGrbaVaQsbada0awapaMaWaiwba1an)) * (ScratchVarGetDouble(Ya9aDakaWobqbaDaRaCa0aBaCaMawjbrba0avaXaQ))))) * (ScratchVarGetDouble(Ya9fbaOaVaXaaa2axobadlbaSAblbAbanaHaYaQa4))))) - ((((ScratchVarGetDouble(YaZcbaKahxbaiaIawaOxbaPebaqnba0dbmbqbaNas)) * (ScratchVarGetDouble(YvbobahalsbaPabAb1ba6a_dba7a7nbauobpbtba_)))))))))), Yaga7obqbaNaha3aLaQAbauaRmbavaraclbanaoar);
	data_addtolist(ScratchSetDouble(((ScratchVarGetDouble(argument_reporter_string_number(Yasaz))) * ((((((((((ScratchVarGetDouble(YaZcbaKahxbaiaIawaOxbaPebaqnba0dbmbqbaNas)) * (ScratchVarGetDouble(Ya9aDakaWobqbaDaRaCa0aBaCaMawjbrba0avaXaQ))))) * (ScratchVarGetDouble(Ya9fbaOaVaXaaa2axobadlbaSAblbAbanaHaYaQa4))))) + ((((ScratchVarGetDouble(YaiaQlbaUaAaGrbaVaQsbada0awapaMaWaiwba1an)) * (ScratchVarGetDouble(YvbobahalsbaPabAb1ba6a_dba7a7nbauobpbtba_)))))))))), Yaga7obqbaNaha3aLaQAbauaRmbavaraclbanaoar);
	data_addtolist(argument_reporter_string_number(Yapax), Yaga7obqbaNaha3aLaQAbauaRmbavaraclbanaoar);
	data_addtolist(ScratchSetDouble((((((ScratchVarGetDouble(YaYaRa0abaPazamaSa4agsbafaNazawbbaKakaxaA)) * (ScratchVarGetDouble(YvbobahalsbaPabAb1ba6a_dba7a7nbauobpbtba_))))) * (ScratchVarGetDouble(argument_reporter_string_number(Yasax))))), Yaga7obqbaNaha3aLaQAbauaRmbavaraclbanaoar);
	data_addtolist(ScratchSetDouble(((ScratchVarGetDouble(argument_reporter_string_number(Yasay))) * ((((((((((ScratchVarGetDouble(YaiaQlbaUaAaGrbaVaQsbada0awapaMaWaiwba1an)) * (ScratchVarGetDouble(Ya9aDakaWobqbaDaRaCa0aBaCaMawjbrba0avaXaQ))))) * (ScratchVarGetDouble(YvbobahalsbaPabAb1ba6a_dba7a7nbauobpbtba_))))) + ((((ScratchVarGetDouble(YaZcbaKahxbaiaIawaOxbaPebaqnba0dbmbqbaNas)) * (ScratchVarGetDouble(Ya9fbaOaVaXaaa2axobadlbaSAblbAbanaHaYaQa4)))))))))), Yaga7obqbaNaha3aLaQAbauaRmbavaraclbanaoar);
	data_addtolist(ScratchSetDouble(((ScratchVarGetDouble(argument_reporter_string_number(Yasaz))) * ((((((((((ScratchVarGetDouble(YaZcbaKahxbaiaIawaOxbaPebaqnba0dbmbqbaNas)) * (ScratchVarGetDouble(Ya9aDakaWobqbaDaRaCa0aBaCaMawjbrba0avaXaQ))))) * (ScratchVarGetDouble(YvbobahalsbaPabAb1ba6a_dba7a7nbauobpbtba_))))) - ((((ScratchVarGetDouble(YaiaQlbaUaAaGrbaVaQsbada0awapaMaWaiwba1an)) * (ScratchVarGetDouble(Ya9fbaOaVaXaaa2axobadlbaSAblbAbanaHaYaQa4)))))))))), Yaga7obqbaNaha3aLaQAbauaRmbavaraclbanaoar);
	data_addtolist(argument_reporter_string_number(Yapay), Yaga7obqbaNaha3aLaQAbauaRmbavaraclbanaoar);
	data_addtolist(ScratchSetDouble((((((0) - (ScratchVarGetDouble(Ya9aDakaWobqbaDaRaCa0aBaCaMawjbrba0avaXaQ))))) * (ScratchVarGetDouble(argument_reporter_string_number(Yasax))))), Yaga7obqbaNaha3aLaQAbauaRmbavaraclbanaoar);
	data_addtolist(ScratchSetDouble((((((ScratchVarGetDouble(YaiaQlbaUaAaGrbaVaQsbada0awapaMaWaiwba1an)) * (ScratchVarGetDouble(YaYaRa0abaPazamaSa4agsbafaNazawbbaKakaxaA))))) * (ScratchVarGetDouble(argument_reporter_string_number(Yasay))))), Yaga7obqbaNaha3aLaQAbauaRmbavaraclbanaoar);
	data_addtolist(ScratchSetDouble((((((ScratchVarGetDouble(YaZcbaKahxbaiaIawaOxbaPebaqnba0dbmbqbaNas)) * (ScratchVarGetDouble(YaYaRa0abaPazamaSa4agsbafaNazawbbaKakaxaA))))) * (ScratchVarGetDouble(argument_reporter_string_number(Yasaz))))), Yaga7obqbaNaha3aLaQAbauaRmbavaraclbanaoar);
	data_addtolist(argument_reporter_string_number(Yapaz), Yaga7obqbaNaha3aLaQAbauaRmbavaraclbanaoar);
#define YIELD TRUE_YIELD
}

void YaAapapalayibaMaoadaealibaMaaataraiax() 
{
	activeSprite = 1;
#define YIELD
	data_setvariableto(ScratchSetDouble(1), YagcbkbebebtbadjbhbwbqbaoubaSaZhbamwblbhb);
	for(int i1 = 0; i1 < (int)ScratchVarGetDouble(data_lengthoflist(YataEaMaQaZa6qbpbaRxbobrbaGhbaCa9aUaXobaU)); i1++)
	{
		data_setvariableto(ScratchSetDouble((((((ScratchVarGetDouble(data_itemoflist(ScratchSetDouble(4), Yaga7obqbaNaha3aLaQAbauaRmbavaraclbanaoar))) + ((((ScratchVarGetDouble(data_itemoflist(ScratchSetDouble(1), Yaga7obqbaNaha3aLaQAbauaRmbavaraclbanaoar))) * (ScratchVarGetDouble(data_itemoflist(YagcbkbebebtbadjbhbwbqbaoubaSaZhbamwblbhb, YataEaMaQaZa6qbpbaRxbobrbaGhbaCa9aUaXobaU))))))))) + (((((((ScratchVarGetDouble(data_itemoflist(ScratchSetDouble(2), Yaga7obqbaNaha3aLaQAbauaRmbavaraclbanaoar))) * (ScratchVarGetDouble(data_itemoflist(YagcbkbebebtbadjbhbwbqbaoubaSaZhbamwblbhb, Y1ba5avcbaPamapubqbtbkbawakaaaaaYxbhbalbb)))))) + ((((ScratchVarGetDouble(data_itemoflist(ScratchSetDouble(3), Yaga7obqbaNaha3aLaQAbauaRmbavaraclbanaoar))) * (ScratchVarGetDouble(data_itemoflist(YagcbkbebebtbadjbhbwbqbaoubaSaZhbamwblbhb, YjbaspbaRkbadaAaTxbasa1aBacada6aZaE1bgbaU))))))))))), YqbaKaxanlbadataaaCaSebaaaKaoaOa8a3a7gbaz);
		data_setvariableto(ScratchSetDouble((((((ScratchVarGetDouble(data_itemoflist(ScratchSetDouble(8), Yaga7obqbaNaha3aLaQAbauaRmbavaraclbanaoar))) + ((((ScratchVarGetDouble(data_itemoflist(ScratchSetDouble(5), Yaga7obqbaNaha3aLaQAbauaRmbavaraclbanaoar))) * (ScratchVarGetDouble(data_itemoflist(YagcbkbebebtbadjbhbwbqbaoubaSaZhbamwblbhb, YataEaMaQaZa6qbpbaRxbobrbaGhbaCa9aUaXobaU))))))))) + (((((((ScratchVarGetDouble(data_itemoflist(ScratchSetDouble(6), Yaga7obqbaNaha3aLaQAbauaRmbavaraclbanaoar))) * (ScratchVarGetDouble(data_itemoflist(YagcbkbebebtbadjbhbwbqbaoubaSaZhbamwblbhb, Y1ba5avcbaPamapubqbtbkbawakaaaaaYxbhbalbb)))))) + ((((ScratchVarGetDouble(data_itemoflist(ScratchSetDouble(7), Yaga7obqbaNaha3aLaQAbauaRmbavaraclbanaoar))) * (ScratchVarGetDouble(data_itemoflist(YagcbkbebebtbadjbhbwbqbaoubaSaZhbamwblbhb, YjbaspbaRkbadaAaTxbasa1aBacada6aZaE1bgbaU))))))))))), YaWqba0fbaHaralawaMaCajauaraNa8aWebrbgba0);
		data_setvariableto(ScratchSetDouble((((((ScratchVarGetDouble(data_itemoflist(ScratchSetDouble(12), Yaga7obqbaNaha3aLaQAbauaRmbavaraclbanaoar))) + ((((ScratchVarGetDouble(data_itemoflist(ScratchSetDouble(9), Yaga7obqbaNaha3aLaQAbauaRmbavaraclbanaoar))) * (ScratchVarGetDouble(data_itemoflist(YagcbkbebebtbadjbhbwbqbaoubaSaZhbamwblbhb, YataEaMaQaZa6qbpbaRxbobrbaGhbaCa9aUaXobaU))))))))) + (((((((ScratchVarGetDouble(data_itemoflist(ScratchSetDouble(10), Yaga7obqbaNaha3aLaQAbauaRmbavaraclbanaoar))) * (ScratchVarGetDouble(data_itemoflist(YagcbkbebebtbadjbhbwbqbaoubaSaZhbamwblbhb, Y1ba5avcbaPamapubqbtbkbawakaaaaaYxbhbalbb)))))) + ((((ScratchVarGetDouble(data_itemoflist(ScratchSetDouble(11), Yaga7obqbaNaha3aLaQAbauaRmbavaraclbanaoar))) * (ScratchVarGetDouble(data_itemoflist(YagcbkbebebtbadjbhbwbqbaoubaSaZhbamwblbhb, YjbaspbaRkbadaAaTxbasa1aBacada6aZaE1bgbaU))))))))))), YqbapaKobrbaVaLaMpbnbaNwba9AbaWa0aTrbaiaM);
		data_replaceitemoflist(YagcbkbebebtbadjbhbwbqbaoubaSaZhbamwblbhb, YqbaKaxanlbadataaaCaSebaaaKaoaOa8a3a7gbaz, YataEaMaQaZa6qbpbaRxbobrbaGhbaCa9aUaXobaU);
		data_replaceitemoflist(YagcbkbebebtbadjbhbwbqbaoubaSaZhbamwblbhb, YaWqba0fbaHaralawaMaCajauaraNa8aWebrbgba0, Y1ba5avcbaPamapubqbtbkbawakaaaaaYxbhbalbb);
		data_replaceitemoflist(YagcbkbebebtbadjbhbwbqbaoubaSaZhbamwblbhb, YqbapaKobrbaVaLaMpbnbaNwba9AbaWa0aTrbaiaM, YjbaspbaRkbadaAaTxbasa1aBacada6aZaE1bgbaU);
		data_changevariableby(ScratchSetDouble(1), YagcbkbebebtbadjbhbwbqbaoubaSaZhbamwblbhb);
		YIELD
	}
#define YIELD TRUE_YIELD
}

void YaDaraaawibaTaraiaaanagalaeas() 
{
	activeSprite = 1;
#define YIELD
	data_setvariableto(ScratchSetDouble(((60) / (double)(ScratchVarGetDouble(Yjba8aZaNcbcbadaPubapaMawajaAaKcbaCa3bbaF)))), YathbgbaAaraAaSaccbrbmbnbaUafa0qbaFdba9cb);
	data_setvariableto(ScratchSetDouble(1), YagcbkbebebtbadjbhbwbqbaoubaSaZhbamwblbhb);
	for(int i1 = 0; i1 < (int)((((ScratchVarGetDouble(data_lengthoflist(YataEaMaQaZa6qbpbaRxbobrbaGhbaCa9aUaXobaU))) / (double)(3)))); i1++)
	{
		YaRaaasataearaiasaeibaTaraiaaanagalaeiblbasiblbasiblbasiblbasiblbasiblbasiblbasiblbasiblbasiblbasiblbasiblbasiblbasiblbasiblbas(ScratchSetDouble((((((ScratchVarGetDouble(data_itemoflist(ScratchSetDouble(((ScratchVarGetDouble(YagcbkbebebtbadjbhbwbqbaoubaSaZhbamwblbhb)) + (0))), YataEaMaQaZa6qbpbaRxbobrbaGhbaCa9aUaXobaU))) / (double)(ScratchVarGetDouble(data_itemoflist(ScratchSetDouble(((ScratchVarGetDouble(YagcbkbebebtbadjbhbwbqbaoubaSaZhbamwblbhb)) + (0))), YjbaspbaRkbadaAaTxbasa1aBacada6aZaE1bgbaU)))))) * (ScratchVarGetDouble(YathbgbaAaraAaSaccbrbmbnbaUafa0qbaFdba9cb)))), ScratchSetDouble((((((ScratchVarGetDouble(data_itemoflist(ScratchSetDouble(((ScratchVarGetDouble(YagcbkbebebtbadjbhbwbqbaoubaSaZhbamwblbhb)) + (0))), Y1ba5avcbaPamapubqbtbkbawakaaaaaYxbhbalbb))) / (double)(ScratchVarGetDouble(data_itemoflist(ScratchSetDouble(((ScratchVarGetDouble(YagcbkbebebtbadjbhbwbqbaoubaSaZhbamwblbhb)) + (0))), YjbaspbaRkbadaAaTxbasa1aBacada6aZaE1bgbaU)))))) * (ScratchVarGetDouble(YathbgbaAaraAaSaccbrbmbnbaUafa0qbaFdba9cb)))), ScratchSetDouble((((((ScratchVarGetDouble(data_itemoflist(ScratchSetDouble(((ScratchVarGetDouble(YagcbkbebebtbadjbhbwbqbaoubaSaZhbamwblbhb)) + (1))), YataEaMaQaZa6qbpbaRxbobrbaGhbaCa9aUaXobaU))) / (double)(ScratchVarGetDouble(data_itemoflist(ScratchSetDouble(((ScratchVarGetDouble(YagcbkbebebtbadjbhbwbqbaoubaSaZhbamwblbhb)) + (1))), YjbaspbaRkbadaAaTxbasa1aBacada6aZaE1bgbaU)))))) * (ScratchVarGetDouble(YathbgbaAaraAaSaccbrbmbnbaUafa0qbaFdba9cb)))), ScratchSetDouble((((((ScratchVarGetDouble(data_itemoflist(ScratchSetDouble(((ScratchVarGetDouble(YagcbkbebebtbadjbhbwbqbaoubaSaZhbamwblbhb)) + (1))), Y1ba5avcbaPamapubqbtbkbawakaaaaaYxbhbalbb))) / (double)(ScratchVarGetDouble(data_itemoflist(ScratchSetDouble(((ScratchVarGetDouble(YagcbkbebebtbadjbhbwbqbaoubaSaZhbamwblbhb)) + (1))), YjbaspbaRkbadaAaTxbasa1aBacada6aZaE1bgbaU)))))) * (ScratchVarGetDouble(YathbgbaAaraAaSaccbrbmbnbaUafa0qbaFdba9cb)))), ScratchSetDouble((((((ScratchVarGetDouble(data_itemoflist(ScratchSetDouble(((ScratchVarGetDouble(YagcbkbebebtbadjbhbwbqbaoubaSaZhbamwblbhb)) + (2))), YataEaMaQaZa6qbpbaRxbobrbaGhbaCa9aUaXobaU))) / (double)(ScratchVarGetDouble(data_itemoflist(ScratchSetDouble(((ScratchVarGetDouble(YagcbkbebebtbadjbhbwbqbaoubaSaZhbamwblbhb)) + (2))), YjbaspbaRkbadaAaTxbasa1aBacada6aZaE1bgbaU)))))) * (ScratchVarGetDouble(YathbgbaAaraAaSaccbrbmbnbaUafa0qbaFdba9cb)))), ScratchSetDouble((((((ScratchVarGetDouble(data_itemoflist(ScratchSetDouble(((ScratchVarGetDouble(YagcbkbebebtbadjbhbwbqbaoubaSaZhbamwblbhb)) + (2))), Y1ba5avcbaPamapubqbtbkbawakaaaaaYxbhbalbb))) / (double)(ScratchVarGetDouble(data_itemoflist(ScratchSetDouble(((ScratchVarGetDouble(YagcbkbebebtbadjbhbwbqbaoubaSaZhbamwblbhb)) + (2))), YjbaspbaRkbadaAaTxbasa1aBacada6aZaE1bgbaU)))))) * (ScratchVarGetDouble(YathbgbaAaraAaSaccbrbmbnbaUafa0qbaFdba9cb)))), data_itemoflist(ScratchSetDouble(((ScratchVarGetDouble(YagcbkbebebtbadjbhbwbqbaoubaSaZhbamwblbhb)) + (0))), YaZaoaBaraRa0mbaffbaxaNubaaebacaroba9aGqb), data_itemoflist(ScratchSetDouble(((ScratchVarGetDouble(YagcbkbebebtbadjbhbwbqbaoubaSaZhbamwblbhb)) + (1))), YaZaoaBaraRa0mbaffbaxaNubaaebacaroba9aGqb), data_itemoflist(ScratchSetDouble(((ScratchVarGetDouble(YagcbkbebebtbadjbhbwbqbaoubaSaZhbamwblbhb)) + (2))), YaZaoaBaraRa0mbaffbaxaNubaaebacaroba9aGqb), data_itemoflist(ScratchSetDouble(((ScratchVarGetDouble(YagcbkbebebtbadjbhbwbqbaoubaSaZhbamwblbhb)) + (0))), YfbagwbAbasaKcbuba4avaSaSaRaxkbaYajaJaTa8), data_itemoflist(ScratchSetDouble(((ScratchVarGetDouble(YagcbkbebebtbadjbhbwbqbaoubaSaZhbamwblbhb)) + (1))), YfbagwbAbasaKcbuba4avaSaSaRaxkbaYajaJaTa8), data_itemoflist(ScratchSetDouble(((ScratchVarGetDouble(YagcbkbebebtbadjbhbwbqbaoubaSaZhbamwblbhb)) + (2))), YfbagwbAbasaKcbuba4avaSaSaRaxkbaYajaJaTa8), data_itemoflist(ScratchSetDouble(((ScratchVarGetDouble(YagcbkbebebtbadjbhbwbqbaoubaSaZhbamwblbhb)) + (0))), YjbaspbaRkbadaAaTxbasa1aBacada6aZaE1bgbaU), data_itemoflist(ScratchSetDouble(((ScratchVarGetDouble(YagcbkbebebtbadjbhbwbqbaoubaSaZhbamwblbhb)) + (1))), YjbaspbaRkbadaAaTxbasa1aBacada6aZaE1bgbaU), data_itemoflist(ScratchSetDouble(((ScratchVarGetDouble(YagcbkbebebtbadjbhbwbqbaoubaSaZhbamwblbhb)) + (2))), YjbaspbaRkbadaAaTxbasa1aBacada6aZaE1bgbaU));
		data_changevariableby(ScratchSetDouble(3), YagcbkbebebtbadjbhbwbqbaoubaSaZhbamwblbhb);
		YIELD
	}
#define YIELD TRUE_YIELD
}

void Y() 
{
	activeSprite = 1;
#define YIELD FUNCTION_YIELD
#define YIELD TRUE_YIELD
}

void YaRaaasataearaiasaeibaTaraiaaanagalaeiblbasiblbasiblbasiblbasiblbasiblbasiblbasiblbasiblbasiblbasiblbasiblbasiblbasiblbasiblbas(ScratchValue Yaxa1, ScratchValue Yaya1, ScratchValue Yaxa2, ScratchValue Yaya2, ScratchValue Yaxa3, ScratchValue Yaya3, ScratchValue Yaua1, ScratchValue Yaua2, ScratchValue Yaua3, ScratchValue Yava1, ScratchValue Yava2, ScratchValue Yava3, ScratchValue Yaza1, ScratchValue Yaza2, ScratchValue Yaza3) 
{
	activeSprite = 1;
#define YIELD
	if(ScratchVarGetBool(operator_and(operator_lt(argument_reporter_string_number(Yaya3), argument_reporter_string_number(Yaya1)), operator_lt(argument_reporter_string_number(Yaya2), argument_reporter_string_number(Yaya1)))))
	{
		data_setvariableto(ScratchSetDouble(1), Yrbaga7axaDagaYafa5aeaIaasbagubobaua4aQwb);
		data_setvariableto(argument_reporter_string_number(Yaya1), YaJasa2aOnbaxalagaWanazpbaadbara9gbgbagnb);
		data_setvariableto(argument_reporter_string_number(Yaxa1), YkbaladaWaNaoaba7obqbsbxbabacrbaYamaxaSbb);
		data_setvariableto(argument_reporter_string_number(Yaua1), Yagapa2adbbqbapaKaOalaAuba9a7a9aBmbaPdbrb);
		data_setvariableto(argument_reporter_string_number(Yava1), YaFaXa7ama3atjbaegbaKaYavazaNauaKaFnbmbar);
		data_setvariableto(argument_reporter_string_number(Yaza1), YagahaQa5a2xbobdbaHaMpbgbawaNebkbaZa0anal);
		if(ScratchVarGetBool(operator_lt(argument_reporter_string_number(Yaya3), argument_reporter_string_number(Yaya2))))
		{
			data_setvariableto(argument_reporter_string_number(Yaya2), Ya4a6alaIa1fbaSdbrbdbkbadqbaIakaIa4wbebaU);
			data_setvariableto(argument_reporter_string_number(Yaxa2), Ynbawa9aIalaAeba_aWbbaCqbaAa0ahaka_aNpbtb);
			data_setvariableto(argument_reporter_string_number(Yaua2), YaRahaKaHaWvbaTa1aHaEawaL1bwbataBa_aJaRaz);
			data_setvariableto(argument_reporter_string_number(Yava2), YcbaAxbaJahaFaldbsba9aqasalaahba2sbcbaKa5);
			data_setvariableto(argument_reporter_string_number(Yaza2), Ya0hbaCa3xbaSvbadaLauaG1baWayasdbaKobajaw);
			Y();
			data_setvariableto(argument_reporter_string_number(Yaya3), YobaHajubanaTavaTa7aqa8AbaSapaNakAbaFa8ak);
			data_setvariableto(argument_reporter_string_number(Yaxa3), YaFebaOaKaJalabtbaMacaFaPaEaTaBawa4aeaUaD);
			data_setvariableto(argument_reporter_string_number(Yaua3), YaOapkbaga8aeaBa0aiawaha2aQaUamawaZrblbaY);
			data_setvariableto(argument_reporter_string_number(Yava3), YdbrbhbaMjbaIaYaVacaExbaIaaaIa5aEazrbaAaS);
			data_setvariableto(argument_reporter_string_number(Yaza3), YaCaCAb1bwbaYaHa_aZwbcbdbaWahamaI1baKjbam);
		}
		else
		{
			data_setvariableto(argument_reporter_string_number(Yaya2), YobaHajubanaTavaTa7aqa8AbaSapaNakAbaFa8ak);
			data_setvariableto(argument_reporter_string_number(Yaxa2), YaFebaOaKaJalabtbaMacaFaPaEaTaBawa4aeaUaD);
			data_setvariableto(argument_reporter_string_number(Yaua2), YaOapkbaga8aeaBa0aiawaha2aQaUamawaZrblbaY);
			data_setvariableto(argument_reporter_string_number(Yava2), YdbrbhbaMjbaIaYaVacaExbaIaaaIa5aEazrbaAaS);
			data_setvariableto(argument_reporter_string_number(Yaza2), YaCaCAb1bwbaYaHa_aZwbcbdbaWahamaI1baKjbam);
			Y();
			data_setvariableto(argument_reporter_string_number(Yaya3), Ya4a6alaIa1fbaSdbrbdbkbadqbaIakaIa4wbebaU);
			data_setvariableto(argument_reporter_string_number(Yaxa3), Ynbawa9aIalaAeba_aWbbaCqbaAa0ahaka_aNpbtb);
			data_setvariableto(argument_reporter_string_number(Yaua3), YaRahaKaHaWvbaTa1aHaEawaL1bwbataBa_aJaRaz);
			data_setvariableto(argument_reporter_string_number(Yava3), YcbaAxbaJahaFaldbsba9aqasalaahba2sbcbaKa5);
			data_setvariableto(argument_reporter_string_number(Yaza3), Ya0hbaCa3xbaSvbadaLauaG1baWayasdbaKobajaw);
		}
	}
	if(ScratchVarGetBool(operator_and(operator_lt(argument_reporter_string_number(Yaya3), argument_reporter_string_number(Yaya2)), operator_lt(argument_reporter_string_number(Yaya1), argument_reporter_string_number(Yaya2)))))
	{
		data_setvariableto(ScratchSetDouble(2), Yrbaga7axaDagaYafa5aeaIaasbagubobaua4aQwb);
		data_setvariableto(argument_reporter_string_number(Yaya2), YaJasa2aOnbaxalagaWanazpbaadbara9gbgbagnb);
		data_setvariableto(argument_reporter_string_number(Yaxa2), YkbaladaWaNaoaba7obqbsbxbabacrbaYamaxaSbb);
		data_setvariableto(argument_reporter_string_number(Yaua2), Yagapa2adbbqbapaKaOalaAuba9a7a9aBmbaPdbrb);
		data_setvariableto(argument_reporter_string_number(Yava2), YaFaXa7ama3atjbaegbaKaYavazaNauaKaFnbmbar);
		data_setvariableto(argument_reporter_string_number(Yaza2), YagahaQa5a2xbobdbaHaMpbgbawaNebkbaZa0anal);
		if(ScratchVarGetBool(operator_lt(argument_reporter_string_number(Yaya3), argument_reporter_string_number(Yaya1))))
		{
			data_setvariableto(argument_reporter_string_number(Yaya1), Ya4a6alaIa1fbaSdbrbdbkbadqbaIakaIa4wbebaU);
			data_setvariableto(argument_reporter_string_number(Yaxa1), Ynbawa9aIalaAeba_aWbbaCqbaAa0ahaka_aNpbtb);
			data_setvariableto(argument_reporter_string_number(Yaua1), YaRahaKaHaWvbaTa1aHaEawaL1bwbataBa_aJaRaz);
			data_setvariableto(argument_reporter_string_number(Yava1), YcbaAxbaJahaFaldbsba9aqasalaahba2sbcbaKa5);
			data_setvariableto(argument_reporter_string_number(Yaza1), Ya0hbaCa3xbaSvbadaLauaG1baWayasdbaKobajaw);
			Y();
			data_setvariableto(argument_reporter_string_number(Yaya3), YobaHajubanaTavaTa7aqa8AbaSapaNakAbaFa8ak);
			data_setvariableto(argument_reporter_string_number(Yaxa3), YaFebaOaKaJalabtbaMacaFaPaEaTaBawa4aeaUaD);
			data_setvariableto(argument_reporter_string_number(Yaua3), YaOapkbaga8aeaBa0aiawaha2aQaUamawaZrblbaY);
			data_setvariableto(argument_reporter_string_number(Yava3), YdbrbhbaMjbaIaYaVacaExbaIaaaIa5aEazrbaAaS);
			data_setvariableto(argument_reporter_string_number(Yaza3), YaCaCAb1bwbaYaHa_aZwbcbdbaWahamaI1baKjbam);
		}
		else
		{
			data_setvariableto(argument_reporter_string_number(Yaya1), YobaHajubanaTavaTa7aqa8AbaSapaNakAbaFa8ak);
			data_setvariableto(argument_reporter_string_number(Yaxa1), YaFebaOaKaJalabtbaMacaFaPaEaTaBawa4aeaUaD);
			data_setvariableto(argument_reporter_string_number(Yaua1), YaOapkbaga8aeaBa0aiawaha2aQaUamawaZrblbaY);
			data_setvariableto(argument_reporter_string_number(Yava1), YdbrbhbaMjbaIaYaVacaExbaIaaaIa5aEazrbaAaS);
			data_setvariableto(argument_reporter_string_number(Yaza1), YaCaCAb1bwbaYaHa_aZwbcbdbaWahamaI1baKjbam);
			Y();
			data_setvariableto(argument_reporter_string_number(Yaya3), Ya4a6alaIa1fbaSdbrbdbkbadqbaIakaIa4wbebaU);
			data_setvariableto(argument_reporter_string_number(Yaxa3), Ynbawa9aIalaAeba_aWbbaCqbaAa0ahaka_aNpbtb);
			data_setvariableto(argument_reporter_string_number(Yaua3), YaRahaKaHaWvbaTa1aHaEawaL1bwbataBa_aJaRaz);
			data_setvariableto(argument_reporter_string_number(Yava3), YcbaAxbaJahaFaldbsba9aqasalaahba2sbcbaKa5);
			data_setvariableto(argument_reporter_string_number(Yaza3), Ya0hbaCa3xbaSvbadaLauaG1baWayasdbaKobajaw);
		}
	}
	if(ScratchVarGetBool(operator_and(operator_lt(argument_reporter_string_number(Yaya2), argument_reporter_string_number(Yaya3)), operator_lt(argument_reporter_string_number(Yaya1), argument_reporter_string_number(Yaya3)))))
	{
		data_setvariableto(ScratchSetDouble(3), Yrbaga7axaDagaYafa5aeaIaasbagubobaua4aQwb);
		data_setvariableto(argument_reporter_string_number(Yaya3), YaJasa2aOnbaxalagaWanazpbaadbara9gbgbagnb);
		data_setvariableto(argument_reporter_string_number(Yaxa3), YkbaladaWaNaoaba7obqbsbxbabacrbaYamaxaSbb);
		data_setvariableto(argument_reporter_string_number(Yaua3), Yagapa2adbbqbapaKaOalaAuba9a7a9aBmbaPdbrb);
		data_setvariableto(argument_reporter_string_number(Yava3), YaFaXa7ama3atjbaegbaKaYavazaNauaKaFnbmbar);
		data_setvariableto(argument_reporter_string_number(Yaza3), YagahaQa5a2xbobdbaHaMpbgbawaNebkbaZa0anal);
		if(ScratchVarGetBool(operator_lt(argument_reporter_string_number(Yaya2), argument_reporter_string_number(Yaya1))))
		{
			data_setvariableto(argument_reporter_string_number(Yaya1), Ya4a6alaIa1fbaSdbrbdbkbadqbaIakaIa4wbebaU);
			data_setvariableto(argument_reporter_string_number(Yaxa1), Ynbawa9aIalaAeba_aWbbaCqbaAa0ahaka_aNpbtb);
			data_setvariableto(argument_reporter_string_number(Yaua1), YaRahaKaHaWvbaTa1aHaEawaL1bwbataBa_aJaRaz);
			data_setvariableto(argument_reporter_string_number(Yava1), YcbaAxbaJahaFaldbsba9aqasalaahba2sbcbaKa5);
			data_setvariableto(argument_reporter_string_number(Yaza1), Ya0hbaCa3xbaSvbadaLauaG1baWayasdbaKobajaw);
			Y();
			data_setvariableto(argument_reporter_string_number(Yaya2), YobaHajubanaTavaTa7aqa8AbaSapaNakAbaFa8ak);
			data_setvariableto(argument_reporter_string_number(Yaxa2), YaFebaOaKaJalabtbaMacaFaPaEaTaBawa4aeaUaD);
			data_setvariableto(argument_reporter_string_number(Yaua2), YaOapkbaga8aeaBa0aiawaha2aQaUamawaZrblbaY);
			data_setvariableto(argument_reporter_string_number(Yava2), YdbrbhbaMjbaIaYaVacaExbaIaaaIa5aEazrbaAaS);
			data_setvariableto(argument_reporter_string_number(Yaza2), YaCaCAb1bwbaYaHa_aZwbcbdbaWahamaI1baKjbam);
		}
		else
		{
			data_setvariableto(argument_reporter_string_number(Yaya1), YobaHajubanaTavaTa7aqa8AbaSapaNakAbaFa8ak);
			data_setvariableto(argument_reporter_string_number(Yaxa1), YaFebaOaKaJalabtbaMacaFaPaEaTaBawa4aeaUaD);
			data_setvariableto(argument_reporter_string_number(Yaua1), YaOapkbaga8aeaBa0aiawaha2aQaUamawaZrblbaY);
			data_setvariableto(argument_reporter_string_number(Yava1), YdbrbhbaMjbaIaYaVacaExbaIaaaIa5aEazrbaAaS);
			data_setvariableto(argument_reporter_string_number(Yaza1), YaCaCAb1bwbaYaHa_aZwbcbdbaWahamaI1baKjbam);
			Y();
			data_setvariableto(argument_reporter_string_number(Yaya2), Ya4a6alaIa1fbaSdbrbdbkbadqbaIakaIa4wbebaU);
			data_setvariableto(argument_reporter_string_number(Yaxa2), Ynbawa9aIalaAeba_aWbbaCqbaAa0ahaka_aNpbtb);
			data_setvariableto(argument_reporter_string_number(Yaua2), YaRahaKaHaWvbaTa1aHaEawaL1bwbataBa_aJaRaz);
			data_setvariableto(argument_reporter_string_number(Yava2), YcbaAxbaJahaFaldbsba9aqasalaahba2sbcbaKa5);
			data_setvariableto(argument_reporter_string_number(Yaza2), Ya0hbaCa3xbaSvbadaLauaG1baWayasdbaKobajaw);
		}
	}
	data_setvariableto(ScratchSetDouble((((((ScratchVarGetDouble(Ya4a6alaIa1fbaSdbrbdbkbadqbaIakaIa4wbebaU)) - (ScratchVarGetDouble(YobaHajubanaTavaTa7aqa8AbaSapaNakAbaFa8ak))))) / (double)((((ScratchVarGetDouble(YaJasa2aOnbaxalagaWanazpbaadbara9gbgbagnb)) - (ScratchVarGetDouble(YobaHajubanaTavaTa7aqa8AbaSapaNakAbaFa8ak))))))), Yazuba8a8aJdba4aragacobaKeba5rbaIgbaiaUam);
	data_setvariableto(ScratchSetDouble((((((ScratchVarGetDouble(Yazuba8a8aJdba4aragacobaKeba5rbaIgbaiaUam)) * ((((ScratchVarGetDouble(YkbaladaWaNaoaba7obqbsbxbabacrbaYamaxaSbb)) - (ScratchVarGetDouble(YaFebaOaKaJalabtbaMacaFaPaEaTaBawa4aeaUaD)))))))) + (ScratchVarGetDouble(YaFebaOaKaJalabtbaMacaFaPaEaTaBawa4aeaUaD)))), Yaoa5akangbjbaapbaYava3akqbcbcbhbpba0araV);
	data_setvariableto(Ya4a6alaIa1fbaSdbrbdbkbadqbaIakaIa4wbebaU, Ypba8obaXoba7aqa3aZjbaiebobwbpbaAvbaJausb);
	data_setvariableto(ScratchSetDouble((((((ScratchVarGetDouble(Yazuba8a8aJdba4aragacobaKeba5rbaIgbaiaUam)) * ((((ScratchVarGetDouble(Yagapa2adbbqbapaKaOalaAuba9a7a9aBmbaPdbrb)) - (ScratchVarGetDouble(YaOapkbaga8aeaBa0aiawaha2aQaUamawaZrblbaY)))))))) + (ScratchVarGetDouble(YaOapkbaga8aeaBa0aiawaha2aQaUamawaZrblbaY)))), YobaLadcbgbantbawaUuba0aDaKvbsbalaUa1aZaT);
	data_setvariableto(ScratchSetDouble((((((ScratchVarGetDouble(Yazuba8a8aJdba4aragacobaKeba5rbaIgbaiaUam)) * ((((ScratchVarGetDouble(YaFaXa7ama3atjbaegbaKaYavazaNauaKaFnbmbar)) - (ScratchVarGetDouble(YdbrbhbaMjbaIaYaVacaExbaIaaaIa5aEazrbaAaS)))))))) + (ScratchVarGetDouble(YdbrbhbaMjbaIaYaVacaExbaIaaaIa5aEazrbaAaS)))), Ydba81baoaiaQa8cbdbamaNa3aTaiaIaTtbaBaavb);
	data_setvariableto(ScratchSetDouble((((((ScratchVarGetDouble(Yazuba8a8aJdba4aragacobaKeba5rbaIgbaiaUam)) * ((((ScratchVarGetDouble(YagahaQa5a2xbobdbaHaMpbgbawaNebkbaZa0anal)) - (ScratchVarGetDouble(YaCaCAb1bwbaYaHa_aZwbcbdbaWahamaI1baKjbam)))))))) + (ScratchVarGetDouble(YaCaCAb1bwbaYaHa_aZwbcbdbaWahamaI1baKjbam)))), YebaUsbaeaBrba7amaQavahara0aJazaJebobAba9);
	Y();
	if(ScratchVarGetBool(operator_not(operator_equals(Ya4a6alaIa1fbaSdbrbdbkbadqbaIakaIa4wbebaU, YaJasa2aOnbaxalagaWanazpbaadbara9gbgbagnb))))
	{
		data_setvariableto(ScratchSetDouble(((0) - (((((((ScratchVarGetDouble(Ynbawa9aIalaAeba_aWbbaCqbaAa0ahaka_aNpbtb)) - (ScratchVarGetDouble(YkbaladaWaNaoaba7obqbsbxbabacrbaYamaxaSbb))))) / (double)((((ScratchVarGetDouble(Ya4a6alaIa1fbaSdbrbdbkbadqbaIakaIa4wbebaU)) - (ScratchVarGetDouble(YaJasa2aOnbaxalagaWanazpbaadbara9gbgbagnb)))))))))), YaHaGhbqbapa3a8aEaXaxaCaxaRaoamanaEampbaF);
		data_setvariableto(ScratchSetDouble(((0) - (((((((ScratchVarGetDouble(Yaoa5akangbjbaapbaYava3akqbcbcbhbpba0araV)) - (ScratchVarGetDouble(YkbaladaWaNaoaba7obqbsbxbabacrbaYamaxaSbb))))) / (double)((((ScratchVarGetDouble(Ypba8obaXoba7aqa3aZjbaiebobwbpbaAvbaJausb)) - (ScratchVarGetDouble(YaJasa2aOnbaxalagaWanazpbaadbara9gbgbagnb)))))))))), Yobaqa6akaxubaNbbwbxbxbawara_aSa2xbaOAbay);
		data_setvariableto(ScratchSetDouble(((0) - (((((((ScratchVarGetDouble(YcbaAxbaJahaFaldbsba9aqasalaahba2sbcbaKa5)) - (ScratchVarGetDouble(YaFaXa7ama3atjbaegbaKaYavazaNauaKaFnbmbar))))) / (double)((((ScratchVarGetDouble(Ya4a6alaIa1fbaSdbrbdbkbadqbaIakaIa4wbebaU)) - (ScratchVarGetDouble(YaJasa2aOnbaxalagaWanazpbaadbara9gbgbagnb)))))))))), Ya6aLcbnba7qbacaYaZgbfbpbaRa2fbbba3ahamax);
		data_setvariableto(ScratchSetDouble(((0) - (((((((ScratchVarGetDouble(YaRahaKaHaWvbaTa1aHaEawaL1bwbataBa_aJaRaz)) - (ScratchVarGetDouble(Yagapa2adbbqbapaKaOalaAuba9a7a9aBmbaPdbrb))))) / (double)((((ScratchVarGetDouble(Ya4a6alaIa1fbaSdbrbdbkbadqbaIakaIa4wbebaU)) - (ScratchVarGetDouble(YaJasa2aOnbaxalagaWanazpbaadbara9gbgbagnb)))))))))), YnbcbaBauaXaNebhbAbazaFqbaraPaqaIaeavaGay);
		data_setvariableto(ScratchSetDouble(((0) - (((((((ScratchVarGetDouble(Ydba81baoaiaQa8cbdbamaNa3aTaiaIaTtbaBaavb)) - (ScratchVarGetDouble(YaFaXa7ama3atjbaegbaKaYavazaNauaKaFnbmbar))))) / (double)((((ScratchVarGetDouble(Ya4a6alaIa1fbaSdbrbdbkbadqbaIakaIa4wbebaU)) - (ScratchVarGetDouble(YaJasa2aOnbaxalagaWanazpbaadbara9gbgbagnb)))))))))), Ya8lbqbAbasaDarkblbaIarabobmbfbacabaEayad);
		data_setvariableto(ScratchSetDouble(((0) - (((((((ScratchVarGetDouble(YobaLadcbgbantbawaUuba0aDaKvbsbalaUa1aZaT)) - (ScratchVarGetDouble(Yagapa2adbbqbapaKaOalaAuba9a7a9aBmbaPdbrb))))) / (double)((((ScratchVarGetDouble(Ya4a6alaIa1fbaSdbrbdbkbadqbaIakaIa4wbebaU)) - (ScratchVarGetDouble(YaJasa2aOnbaxalagaWanazpbaadbara9gbgbagnb)))))))))), YobaambanvbaHkbanauacaiaanbaArbbbuba2cbAb);
		data_setvariableto(ScratchSetDouble(((0) - (((((((ScratchVarGetDouble(Ya0hbaCa3xbaSvbadaLauaG1baWayasdbaKobajaw)) - (ScratchVarGetDouble(YagahaQa5a2xbobdbaHaMpbgbawaNebkbaZa0anal))))) / (double)((((ScratchVarGetDouble(Ya4a6alaIa1fbaSdbrbdbkbadqbaIakaIa4wbebaU)) - (ScratchVarGetDouble(YaJasa2aOnbaxalagaWanazpbaadbara9gbgbagnb)))))))))), Ya0a_awaYaYaJa2gbaYa9aHaQ1bpbebebjbafcbaw);
		data_setvariableto(ScratchSetDouble(((0) - (((((((ScratchVarGetDouble(YebaUsbaeaBrba7amaQavahara0aJazaJebobAba9)) - (ScratchVarGetDouble(YagahaQa5a2xbobdbaHaMpbgbawaNebkbaZa0anal))))) / (double)((((ScratchVarGetDouble(Ya4a6alaIa1fbaSdbrbdbkbadqbaIakaIa4wbebaU)) - (ScratchVarGetDouble(YaJasa2aOnbaxalagaWanazpbaadbara9gbgbagnb)))))))))), YaPnba7aSankbaAamaFaAajdbfbmbhbazAba5aYaD);
		data_setvariableto(YkbaladaWaNaoaba7obqbsbxbabacrbaYamaxaSbb, YaCaDlbaCaMadaGac1baMa5wbnbpbasaKaEaJkbar);
		data_setvariableto(YkbaladaWaNaoaba7obqbsbxbabacrbaYamaxaSbb, YaLa9aTnbajaj1baparata8aIagaAazaQAbabaZub);
		data_setvariableto(Yagapa2adbbqbapaKaOalaAuba9a7a9aBmbaPdbrb, YebaBaKaNaJaSqbaqawaYauebaOaMhbcbaFcbaeaI);
		data_setvariableto(Yagapa2adbbqbapaKaOalaAuba9a7a9aBmbaPdbrb, YaBaeaBaaahcbaFaua6fbaGaljbaOagqbaFadaia_);
		data_setvariableto(YaFaXa7ama3atjbaegbaKaYavazaNauaKaFnbmbar, YacaQaFaVaLfbaWoba7fbaiaxaCazaBaJauhba0aC);
		data_setvariableto(YaFaXa7ama3atjbaegbaKaYavazaNauaKaFnbmbar, YahaXaza3a3AbaCa_ebaqaBaxjbwbdbaHwbakkbaA);
		data_setvariableto(YagahaQa5a2xbobdbaHaMpbgbawaNebkbaZa0anal, YacaFfbaoanaplbalaMsbaFaoubjbapfbobafqbaU);
		data_setvariableto(YagahaQa5a2xbobdbaHaMpbgbawaNebkbaZa0anal, Yub1bgbxba2aorbfbaVafauaRaFubakdbaMakhbak);
		data_setvariableto(YaJasa2aOnbaxalagaWanazpbaadbara9gbgbagnb, YaSaJaOazrba9aGaFaKaqaJvbazafaOaohbaFaGmb);
		for(int i2 = 0; i2 < (int)((((1) + ((((ScratchVarGetDouble(YaJasa2aOnbaxalagaWanazpbaadbara9gbgbagnb)) - (ScratchVarGetDouble(Ypba8obaXoba7aqa3aZjbaiebobwbpbaAvbaJausb)))))))); i2++)
		{
			data_setvariableto(operator_round(YaLa9aTnbajaj1baparata8aIagaAazaQAbabaZub), Ycbubpba1adaoalaYaJasaHanaga9aFaSaiaCa_az);
			data_setvariableto(operator_round(YaCaDlbaCaMadaGac1baMa5wbnbpbasaKaEaJkbar), YaGaFa6aHa9avkba8aNa5tbadcbaPwba4apaaa6ao);
			data_setvariableto(YaBaeaBaaahcbaFaua6fbaGaljbaOagqbaFadaia_, YasaLlbawaFaEa1aua6au1baHazxbagahxbaeaAcb);
			data_setvariableto(YebaBaKaNaJaSqbaqawaYauebaOaMhbcbaFcbaeaI, YwbrbaraWaHama5aTa7aaqbfbaaaLnbcbaoatpbaG);
			data_setvariableto(YahaXaza3a3AbaCa_ebaqaBaxjbwbdbaHwbakkbaA, YatajaJaxafaTaiaAa3qbampbahaYawcbaIahaLao);
			data_setvariableto(YacaQaFaVaLfbaWoba7fbaiaxaCazaBaJauhba0aC, YqbaAqbalaGaSaXaombaWaRaiaOa0aDobaXaoar1b);
			data_setvariableto(Yub1bgbxba2aorbfbaVafauaRaFubakdbaMakhbak, Yrba6vbadaDa8a4ata2aZa8hbfbaKabaCaYtbrbaB);
			data_setvariableto(YacaFfbaoanaplbalaMsbaFaoubjbapfbobafqbaU, YwbkbaHa_fbdbpbdbaLobvba5aaayaDaYvbpbasaa);
			if(ScratchVarGetBool(operator_lt(YaGaFa6aHa9avkba8aNa5tbadcbaPwba4apaaa6ao, Ycbubpba1adaoalaYaJasaHanaga9aFaSaiaCa_az)))
			{
				data_setvariableto(operator_round(YaCaDlbaCaMadaGac1baMa5wbnbpbasaKaEaJkbar), Ycbubpba1adaoalaYaJasaHanaga9aFaSaiaCa_az);
				data_setvariableto(operator_round(YaLa9aTnbajaj1baparata8aIagaAazaQAbabaZub), YaGaFa6aHa9avkba8aNa5tbadcbaPwba4apaaa6ao);
				data_setvariableto(YebaBaKaNaJaSqbaqawaYauebaOaMhbcbaFcbaeaI, YasaLlbawaFaEa1aua6au1baHazxbagahxbaeaAcb);
				data_setvariableto(YaBaeaBaaahcbaFaua6fbaGaljbaOagqbaFadaia_, YwbrbaraWaHama5aTa7aaqbfbaaaLnbcbaoatpbaG);
				data_setvariableto(YacaQaFaVaLfbaWoba7fbaiaxaCazaBaJauhba0aC, YatajaJaxafaTaiaAa3qbampbahaYawcbaIahaLao);
				data_setvariableto(YahaXaza3a3AbaCa_ebaqaBaxjbwbdbaHwbakkbaA, YqbaAqbalaGaSaXaombaWaRaiaOa0aDobaXaoar1b);
				data_setvariableto(YacaFfbaoanaplbalaMsbaFaoubjbapfbobafqbaU, Yrba6vbadaDa8a4ata2aZa8hbfbaKabaCaYtbrbaB);
				data_setvariableto(Yub1bgbxba2aorbfbaVafauaRaFubakdbaMakhbak, YwbkbaHa_fbdbpbdbaLobvba5aaayaDaYvbpbasaa);
			}
			data_setvariableto(YasaLlbawaFaEa1aua6au1baHazxbagahxbaeaAcb, Yaka3aEnbapgbaaa0alabkbaaaflbaffbAbhbaFwb);
			data_setvariableto(ScratchSetDouble((((((ScratchVarGetDouble(YwbrbaraWaHama5aTa7aaqbfbaaaLnbcbaoatpbaG)) - (ScratchVarGetDouble(YasaLlbawaFaEa1aua6au1baHazxbagahxbaeaAcb))))) / (double)((((ScratchVarGetDouble(YaGaFa6aHa9avkba8aNa5tbadcbaPwba4apaaa6ao)) - (ScratchVarGetDouble(Ycbubpba1adaoalaYaJasaHanaga9aFaSaiaCa_az))))))), YaLaFaQakayacaNaZaGxbqbaEmbagaoaGrbbbawrb);
			data_setvariableto(YatajaJaxafaTaiaAa3qbampbahaYawcbaIahaLao, YaKbbwbaWubaoadhbqbabaYadapaDajnba_apaoaD);
			data_setvariableto(ScratchSetDouble((((((ScratchVarGetDouble(YqbaAqbalaGaSaXaombaWaRaiaOa0aDobaXaoar1b)) - (ScratchVarGetDouble(YatajaJaxafaTaiaAa3qbampbahaYawcbaIahaLao))))) / (double)((((ScratchVarGetDouble(YaGaFa6aHa9avkba8aNa5tbadcbaPwba4apaaa6ao)) - (ScratchVarGetDouble(Ycbubpba1adaoalaYaJasaHanaga9aFaSaiaCa_az))))))), Yaoana1aNazaBaprbgba1aEnba_a1ayaba21ba2aP);
			data_setvariableto(Yrba6vbadaDa8a4ata2aZa8hbfbaKabaCaYtbrbaB, YafaUpbaWa7aAaFajamnbAbata5a7aGa1eblbaJa1);
			data_setvariableto(ScratchSetDouble((((((ScratchVarGetDouble(YwbkbaHa_fbdbpbdbaLobvba5aaayaDaYvbpbasaa)) - (ScratchVarGetDouble(Yrba6vbadaDa8a4ata2aZa8hbfbaKabaCaYtbrbaB))))) / (double)((((ScratchVarGetDouble(YaGaFa6aHa9avkba8aNa5tbadcbaPwba4apaaa6ao)) - (ScratchVarGetDouble(Ycbubpba1adaoalaYaJasaHanaga9aFaSaiaCa_az))))))), YayanebaYana1ahagaKjbaba8ajaMagqbaeqbalaC);
			motion_gotoxy(ScratchVarGetDouble(operator_round(Ycbubpba1adaoalaYaJasaHanaga9aFaSaiaCa_az)),ScratchVarGetDouble(operator_round(YaSaJaOazrba9aGaFaKaqaJvbazafaOaohbaFaGmb)));
			for(int i3 = 0; i3 < (int)((((ScratchVarGetDouble(YaGaFa6aHa9avkba8aNa5tbadcbaPwba4apaaa6ao)) - (ScratchVarGetDouble(Ycbubpba1adaoalaYaJasaHanaga9aFaSaiaCa_az))))); i3++)
			{
				YaSaeatibaCaoalaoauariblbasiblbas(Yaka3aEnbapgbaaa0alabkbaaaflbaffbAbhbaFwb, YaKbbwbaWubaoadhbqbabaYadapaDajnba_apaoaD);
				motion_changexby(ScratchSetDouble(1));
				data_changevariableby(YaLaFaQakayacaNaZaGxbqbaEmbagaoaGrbbbawrb, Yaka3aEnbapgbaaa0alabkbaaaflbaffbAbhbaFwb);
				data_changevariableby(Yaoana1aNazaBaprbgba1aEnba_a1ayaba21ba2aP, YaKbbwbaWubaoadhbqbabaYadapaDajnba_apaoaD);
				data_changevariableby(YayanebaYana1ahagaKjbaba8ajaMagqbaeqbalaC, YafaUpbaWa7aAaFajamnbAbata5a7aGa1eblbaJa1);
				if(ScratchVarGetBool(operator_lt(ScratchSetDouble(1), Yaka3aEnbapgbaaa0alabkbaaaflbaffbAbhbaFwb)))
				{
					data_setvariableto(ScratchSetDouble(1), Yaka3aEnbapgbaaa0alabkbaaaflbaffbAbhbaFwb);
				}
				if(ScratchVarGetBool(operator_lt(ScratchSetDouble(1), YaKbbwbaWubaoadhbqbabaYadapaDajnba_apaoaD)))
				{
					data_setvariableto(ScratchSetDouble(1), YaKbbwbaWubaoadhbqbabaYadapaDajnba_apaoaD);
				}
				YIELD
			}
			data_changevariableby(ScratchSetDouble(-1), YaSaJaOazrba9aGaFaKaqaJvbazafaOaohbaFaGmb);
			data_changevariableby(YaHaGhbqbapa3a8aEaXaxaCaxaRaoamanaEampbaF, YaCaDlbaCaMadaGac1baMa5wbnbpbasaKaEaJkbar);
			data_changevariableby(Yobaqa6akaxubaNbbwbxbxbawara_aSa2xbaOAbay, YaLa9aTnbajaj1baparata8aIagaAazaQAbabaZub);
			data_changevariableby(Ya6aLcbnba7qbacaYaZgbfbpbaRa2fbbba3ahamax, YacaQaFaVaLfbaWoba7fbaiaxaCazaBaJauhba0aC);
			data_changevariableby(YnbcbaBauaXaNebhbAbazaFqbaraPaqaIaeavaGay, YebaBaKaNaJaSqbaqawaYauebaOaMhbcbaFcbaeaI);
			data_changevariableby(Ya8lbqbAbasaDarkblbaIarabobmbfbacabaEayad, YahaXaza3a3AbaCa_ebaqaBaxjbwbdbaHwbakkbaA);
			data_changevariableby(YobaambanvbaHkbanauacaiaanbaArbbbuba2cbAb, YaBaeaBaaahcbaFaua6fbaGaljbaOagqbaFadaia_);
			data_changevariableby(Ya0a_awaYaYaJa2gbaYa9aHaQ1bpbebebjbafcbaw, YacaFfbaoanaplbalaMsbaFaoubjbapfbobafqbaU);
			data_changevariableby(YaPnba7aSankbaAamaFaAajdbfbmbhbazAba5aYaD, Yub1bgbxba2aorbfbaVafauaRaFubakdbaMakhbak);
			YIELD
		}
	}
	Y();
	if(ScratchVarGetBool(operator_not(operator_equals(Ya4a6alaIa1fbaSdbrbdbkbadqbaIakaIa4wbebaU, YobaHajubanaTavaTa7aqa8AbaSapaNakAbaFa8ak))))
	{
		data_setvariableto(ScratchSetDouble((((((ScratchVarGetDouble(Ynbawa9aIalaAeba_aWbbaCqbaAa0ahaka_aNpbtb)) - (ScratchVarGetDouble(YaFebaOaKaJalabtbaMacaFaPaEaTaBawa4aeaUaD))))) / (double)((((ScratchVarGetDouble(Ya4a6alaIa1fbaSdbrbdbkbadqbaIakaIa4wbebaU)) - (ScratchVarGetDouble(YobaHajubanaTavaTa7aqa8AbaSapaNakAbaFa8ak))))))), YaHaGhbqbapa3a8aEaXaxaCaxaRaoamanaEampbaF);
		data_setvariableto(ScratchSetDouble((((((ScratchVarGetDouble(Yaoa5akangbjbaapbaYava3akqbcbcbhbpba0araV)) - (ScratchVarGetDouble(YaFebaOaKaJalabtbaMacaFaPaEaTaBawa4aeaUaD))))) / (double)((((ScratchVarGetDouble(Ypba8obaXoba7aqa3aZjbaiebobwbpbaAvbaJausb)) - (ScratchVarGetDouble(YobaHajubanaTavaTa7aqa8AbaSapaNakAbaFa8ak))))))), Yobaqa6akaxubaNbbwbxbxbawara_aSa2xbaOAbay);
		data_setvariableto(ScratchSetDouble((((((ScratchVarGetDouble(YcbaAxbaJahaFaldbsba9aqasalaahba2sbcbaKa5)) - (ScratchVarGetDouble(YdbrbhbaMjbaIaYaVacaExbaIaaaIa5aEazrbaAaS))))) / (double)((((ScratchVarGetDouble(Ya4a6alaIa1fbaSdbrbdbkbadqbaIakaIa4wbebaU)) - (ScratchVarGetDouble(YobaHajubanaTavaTa7aqa8AbaSapaNakAbaFa8ak))))))), Ya6aLcbnba7qbacaYaZgbfbpbaRa2fbbba3ahamax);
		data_setvariableto(ScratchSetDouble((((((ScratchVarGetDouble(YaRahaKaHaWvbaTa1aHaEawaL1bwbataBa_aJaRaz)) - (ScratchVarGetDouble(YaOapkbaga8aeaBa0aiawaha2aQaUamawaZrblbaY))))) / (double)((((ScratchVarGetDouble(Ya4a6alaIa1fbaSdbrbdbkbadqbaIakaIa4wbebaU)) - (ScratchVarGetDouble(YobaHajubanaTavaTa7aqa8AbaSapaNakAbaFa8ak))))))), YnbcbaBauaXaNebhbAbazaFqbaraPaqaIaeavaGay);
		data_setvariableto(ScratchSetDouble((((((ScratchVarGetDouble(Ydba81baoaiaQa8cbdbamaNa3aTaiaIaTtbaBaavb)) - (ScratchVarGetDouble(YdbrbhbaMjbaIaYaVacaExbaIaaaIa5aEazrbaAaS))))) / (double)((((ScratchVarGetDouble(Ypba8obaXoba7aqa3aZjbaiebobwbpbaAvbaJausb)) - (ScratchVarGetDouble(YobaHajubanaTavaTa7aqa8AbaSapaNakAbaFa8ak))))))), Ya8lbqbAbasaDarkblbaIarabobmbfbacabaEayad);
		data_setvariableto(ScratchSetDouble((((((ScratchVarGetDouble(YobaLadcbgbantbawaUuba0aDaKvbsbalaUa1aZaT)) - (ScratchVarGetDouble(YaOapkbaga8aeaBa0aiawaha2aQaUamawaZrblbaY))))) / (double)((((ScratchVarGetDouble(Ypba8obaXoba7aqa3aZjbaiebobwbpbaAvbaJausb)) - (ScratchVarGetDouble(YobaHajubanaTavaTa7aqa8AbaSapaNakAbaFa8ak))))))), YobaambanvbaHkbanauacaiaanbaArbbbuba2cbAb);
		data_setvariableto(ScratchSetDouble((((((ScratchVarGetDouble(Ya0hbaCa3xbaSvbadaLauaG1baWayasdbaKobajaw)) - (ScratchVarGetDouble(YaCaCAb1bwbaYaHa_aZwbcbdbaWahamaI1baKjbam))))) / (double)((((ScratchVarGetDouble(Ya4a6alaIa1fbaSdbrbdbkbadqbaIakaIa4wbebaU)) - (ScratchVarGetDouble(YobaHajubanaTavaTa7aqa8AbaSapaNakAbaFa8ak))))))), Ya0a_awaYaYaJa2gbaYa9aHaQ1bpbebebjbafcbaw);
		data_setvariableto(ScratchSetDouble((((((ScratchVarGetDouble(YebaUsbaeaBrba7amaQavahara0aJazaJebobAba9)) - (ScratchVarGetDouble(YaCaCAb1bwbaYaHa_aZwbcbdbaWahamaI1baKjbam))))) / (double)((((ScratchVarGetDouble(Ypba8obaXoba7aqa3aZjbaiebobwbpbaAvbaJausb)) - (ScratchVarGetDouble(YobaHajubanaTavaTa7aqa8AbaSapaNakAbaFa8ak))))))), YaPnba7aSankbaAamaFaAajdbfbmbhbazAba5aYaD);
		data_setvariableto(YaFebaOaKaJalabtbaMacaFaPaEaTaBawa4aeaUaD, YaCaDlbaCaMadaGac1baMa5wbnbpbasaKaEaJkbar);
		data_setvariableto(YaFebaOaKaJalabtbaMacaFaPaEaTaBawa4aeaUaD, YaLa9aTnbajaj1baparata8aIagaAazaQAbabaZub);
		data_setvariableto(YaOapkbaga8aeaBa0aiawaha2aQaUamawaZrblbaY, YebaBaKaNaJaSqbaqawaYauebaOaMhbcbaFcbaeaI);
		data_setvariableto(YaOapkbaga8aeaBa0aiawaha2aQaUamawaZrblbaY, YaBaeaBaaahcbaFaua6fbaGaljbaOagqbaFadaia_);
		data_setvariableto(YdbrbhbaMjbaIaYaVacaExbaIaaaIa5aEazrbaAaS, YacaQaFaVaLfbaWoba7fbaiaxaCazaBaJauhba0aC);
		data_setvariableto(YdbrbhbaMjbaIaYaVacaExbaIaaaIa5aEazrbaAaS, YahaXaza3a3AbaCa_ebaqaBaxjbwbdbaHwbakkbaA);
		data_setvariableto(YaCaCAb1bwbaYaHa_aZwbcbdbaWahamaI1baKjbam, YacaFfbaoanaplbalaMsbaFaoubjbapfbobafqbaU);
		data_setvariableto(YaCaCAb1bwbaYaHa_aZwbcbdbaWahamaI1baKjbam, Yub1bgbxba2aorbfbaVafauaRaFubakdbaMakhbak);
		data_setvariableto(YobaHajubanaTavaTa7aqa8AbaSapaNakAbaFa8ak, YaSaJaOazrba9aGaFaKaqaJvbazafaOaohbaFaGmb);
		for(int i2 = 0; i2 < (int)((((0) + (ScratchVarGetDouble(operator_mathopYacaeaialaianag(ScratchSetDouble(((ScratchVarGetDouble(Ypba8obaXoba7aqa3aZjbaiebobwbpbaAvbaJausb)) - (ScratchVarGetDouble(YobaHajubanaTavaTa7aqa8AbaSapaNakAbaFa8ak)))))))))); i2++)
		{
			data_setvariableto(operator_round(YaLa9aTnbajaj1baparata8aIagaAazaQAbabaZub), Ycbubpba1adaoalaYaJasaHanaga9aFaSaiaCa_az);
			data_setvariableto(operator_round(YaCaDlbaCaMadaGac1baMa5wbnbpbasaKaEaJkbar), YaGaFa6aHa9avkba8aNa5tbadcbaPwba4apaaa6ao);
			data_setvariableto(YaBaeaBaaahcbaFaua6fbaGaljbaOagqbaFadaia_, YasaLlbawaFaEa1aua6au1baHazxbagahxbaeaAcb);
			data_setvariableto(YebaBaKaNaJaSqbaqawaYauebaOaMhbcbaFcbaeaI, YwbrbaraWaHama5aTa7aaqbfbaaaLnbcbaoatpbaG);
			data_setvariableto(YahaXaza3a3AbaCa_ebaqaBaxjbwbdbaHwbakkbaA, YatajaJaxafaTaiaAa3qbampbahaYawcbaIahaLao);
			data_setvariableto(YacaQaFaVaLfbaWoba7fbaiaxaCazaBaJauhba0aC, YqbaAqbalaGaSaXaombaWaRaiaOa0aDobaXaoar1b);
			data_setvariableto(Yub1bgbxba2aorbfbaVafauaRaFubakdbaMakhbak, Yrba6vbadaDa8a4ata2aZa8hbfbaKabaCaYtbrbaB);
			data_setvariableto(YacaFfbaoanaplbalaMsbaFaoubjbapfbobafqbaU, YwbkbaHa_fbdbpbdbaLobvba5aaayaDaYvbpbasaa);
			if(ScratchVarGetBool(operator_lt(YaGaFa6aHa9avkba8aNa5tbadcbaPwba4apaaa6ao, Ycbubpba1adaoalaYaJasaHanaga9aFaSaiaCa_az)))
			{
				data_setvariableto(operator_round(YaCaDlbaCaMadaGac1baMa5wbnbpbasaKaEaJkbar), Ycbubpba1adaoalaYaJasaHanaga9aFaSaiaCa_az);
				data_setvariableto(operator_round(YaLa9aTnbajaj1baparata8aIagaAazaQAbabaZub), YaGaFa6aHa9avkba8aNa5tbadcbaPwba4apaaa6ao);
				data_setvariableto(YebaBaKaNaJaSqbaqawaYauebaOaMhbcbaFcbaeaI, YasaLlbawaFaEa1aua6au1baHazxbagahxbaeaAcb);
				data_setvariableto(YaBaeaBaaahcbaFaua6fbaGaljbaOagqbaFadaia_, YwbrbaraWaHama5aTa7aaqbfbaaaLnbcbaoatpbaG);
				data_setvariableto(YacaQaFaVaLfbaWoba7fbaiaxaCazaBaJauhba0aC, YatajaJaxafaTaiaAa3qbampbahaYawcbaIahaLao);
				data_setvariableto(YahaXaza3a3AbaCa_ebaqaBaxjbwbdbaHwbakkbaA, YqbaAqbalaGaSaXaombaWaRaiaOa0aDobaXaoar1b);
				data_setvariableto(YacaFfbaoanaplbalaMsbaFaoubjbapfbobafqbaU, Yrba6vbadaDa8a4ata2aZa8hbfbaKabaCaYtbrbaB);
				data_setvariableto(Yub1bgbxba2aorbfbaVafauaRaFubakdbaMakhbak, YwbkbaHa_fbdbpbdbaLobvba5aaayaDaYvbpbasaa);
			}
			data_setvariableto(YasaLlbawaFaEa1aua6au1baHazxbagahxbaeaAcb, Yaka3aEnbapgbaaa0alabkbaaaflbaffbAbhbaFwb);
			data_setvariableto(ScratchSetDouble((((((ScratchVarGetDouble(YwbrbaraWaHama5aTa7aaqbfbaaaLnbcbaoatpbaG)) - (ScratchVarGetDouble(YasaLlbawaFaEa1aua6au1baHazxbagahxbaeaAcb))))) / (double)((((ScratchVarGetDouble(YaGaFa6aHa9avkba8aNa5tbadcbaPwba4apaaa6ao)) - (ScratchVarGetDouble(Ycbubpba1adaoalaYaJasaHanaga9aFaSaiaCa_az))))))), YaLaFaQakayacaNaZaGxbqbaEmbagaoaGrbbbawrb);
			data_setvariableto(YatajaJaxafaTaiaAa3qbampbahaYawcbaIahaLao, YaKbbwbaWubaoadhbqbabaYadapaDajnba_apaoaD);
			data_setvariableto(ScratchSetDouble((((((ScratchVarGetDouble(YqbaAqbalaGaSaXaombaWaRaiaOa0aDobaXaoar1b)) - (ScratchVarGetDouble(YatajaJaxafaTaiaAa3qbampbahaYawcbaIahaLao))))) / (double)((((ScratchVarGetDouble(YaGaFa6aHa9avkba8aNa5tbadcbaPwba4apaaa6ao)) - (ScratchVarGetDouble(Ycbubpba1adaoalaYaJasaHanaga9aFaSaiaCa_az))))))), Yaoana1aNazaBaprbgba1aEnba_a1ayaba21ba2aP);
			data_setvariableto(Yrba6vbadaDa8a4ata2aZa8hbfbaKabaCaYtbrbaB, YafaUpbaWa7aAaFajamnbAbata5a7aGa1eblbaJa1);
			data_setvariableto(ScratchSetDouble((((((ScratchVarGetDouble(YwbkbaHa_fbdbpbdbaLobvba5aaayaDaYvbpbasaa)) - (ScratchVarGetDouble(Yrba6vbadaDa8a4ata2aZa8hbfbaKabaCaYtbrbaB))))) / (double)((((ScratchVarGetDouble(YaGaFa6aHa9avkba8aNa5tbadcbaPwba4apaaa6ao)) - (ScratchVarGetDouble(Ycbubpba1adaoalaYaJasaHanaga9aFaSaiaCa_az))))))), YayanebaYana1ahagaKjbaba8ajaMagqbaeqbalaC);
			motion_gotoxy(ScratchVarGetDouble(Ycbubpba1adaoalaYaJasaHanaga9aFaSaiaCa_az),ScratchVarGetDouble(operator_round(YaSaJaOazrba9aGaFaKaqaJvbazafaOaohbaFaGmb)));
			YaSaeatibaCaoalaoauariblbasiblbas(Yaka3aEnbapgbaaa0alabkbaaaflbaffbAbhbaFwb, YaKbbwbaWubaoadhbqbabaYadapaDajnba_apaoaD);
			for(int i3 = 0; i3 < (int)((((ScratchVarGetDouble(YaGaFa6aHa9avkba8aNa5tbadcbaPwba4apaaa6ao)) - (ScratchVarGetDouble(Ycbubpba1adaoalaYaJasaHanaga9aFaSaiaCa_az))))); i3++)
			{
				YaSaeatibaCaoalaoauariblbasiblbas(Yaka3aEnbapgbaaa0alabkbaaaflbaffbAbhbaFwb, YaKbbwbaWubaoadhbqbabaYadapaDajnba_apaoaD);
				motion_changexby(ScratchSetDouble(1));
				data_changevariableby(YaLaFaQakayacaNaZaGxbqbaEmbagaoaGrbbbawrb, Yaka3aEnbapgbaaa0alabkbaaaflbaffbAbhbaFwb);
				data_changevariableby(Yaoana1aNazaBaprbgba1aEnba_a1ayaba21ba2aP, YaKbbwbaWubaoadhbqbabaYadapaDajnba_apaoaD);
				data_changevariableby(YayanebaYana1ahagaKjbaba8ajaMagqbaeqbalaC, YafaUpbaWa7aAaFajamnbAbata5a7aGa1eblbaJa1);
				if(ScratchVarGetBool(operator_lt(ScratchSetDouble(1), Yaka3aEnbapgbaaa0alabkbaaaflbaffbAbhbaFwb)))
				{
					data_setvariableto(ScratchSetDouble(1), Yaka3aEnbapgbaaa0alabkbaaaflbaffbAbhbaFwb);
				}
				if(ScratchVarGetBool(operator_lt(ScratchSetDouble(1), YaKbbwbaWubaoadhbqbabaYadapaDajnba_apaoaD)))
				{
					data_setvariableto(ScratchSetDouble(1), YaKbbwbaWubaoadhbqbabaYadapaDajnba_apaoaD);
				}
				YIELD
			}
			data_changevariableby(YaHaGhbqbapa3a8aEaXaxaCaxaRaoamanaEampbaF, YaCaDlbaCaMadaGac1baMa5wbnbpbasaKaEaJkbar);
			data_changevariableby(Yobaqa6akaxubaNbbwbxbxbawara_aSa2xbaOAbay, YaLa9aTnbajaj1baparata8aIagaAazaQAbabaZub);
			data_changevariableby(Ya6aLcbnba7qbacaYaZgbfbpbaRa2fbbba3ahamax, YacaQaFaVaLfbaWoba7fbaiaxaCazaBaJauhba0aC);
			data_changevariableby(YnbcbaBauaXaNebhbAbazaFqbaraPaqaIaeavaGay, YebaBaKaNaJaSqbaqawaYauebaOaMhbcbaFcbaeaI);
			data_changevariableby(Ya8lbqbAbasaDarkblbaIarabobmbfbacabaEayad, YahaXaza3a3AbaCa_ebaqaBaxjbwbdbaHwbakkbaA);
			data_changevariableby(YobaambanvbaHkbanauacaiaanbaArbbbuba2cbAb, YaBaeaBaaahcbaFaua6fbaGaljbaOagqbaFadaia_);
			data_changevariableby(Ya0a_awaYaYaJa2gbaYa9aHaQ1bpbebebjbafcbaw, YacaFfbaoanaplbalaMsbaFaoubjbapfbobafqbaU);
			data_changevariableby(YaPnba7aSankbaAamaFaAajdbfbmbhbazAba5aYaD, Yub1bgbxba2aorbfbaVafauaRaFubakdbaMakhbak);
			data_changevariableby(ScratchSetDouble(1), YaSaJaOazrba9aGaFaKaqaJvbazafaOaohbaFaGmb);
			YIELD
		}
	}
#define YIELD TRUE_YIELD
}

void YaSaeatibaCaoalaoauariblbasiblbas(ScratchValue Yau, ScratchValue Yav) 
{
	activeSprite = 1;
#define YIELD
	YaSaeataCaoalaBauafafaeariblbasiblbasiblbas(motion_xposition(), motion_yposition(), ScratchSetDouble(((((((((ScratchVarGetDouble(operator_round(ScratchSetDouble(((ScratchVarGetDouble(argument_reporter_string_number(Yau))) * (255)))))) * (256)))) * (256)))) + ((((ScratchVarGetDouble(operator_round(ScratchSetDouble(((ScratchVarGetDouble(argument_reporter_string_number(Yav))) * (255)))))) * (256)))))));
#define YIELD TRUE_YIELD
}

void YaSaeataCaoalaoauaraBayaDaiasataaanacaeiblbas(ScratchValue Yad) 
{
	activeSprite = 1;
#define YIELD
	pen_setPenColorToColor(ScratchSetDouble((((((ScratchVarGetDouble(operator_mod(operator_round(ScratchSetDouble((((((4) / (double)(ScratchVarGetDouble(argument_reporter_string_number(Yad)))))) * (255)))), ScratchSetDouble(256)))) * ((((256) * (256))))))) + (((((((ScratchVarGetDouble(operator_mod(operator_round(ScratchSetDouble((((((4) / (double)(ScratchVarGetDouble(argument_reporter_string_number(Yad)))))) * (255)))), ScratchSetDouble(256)))) * (256)))) + (ScratchVarGetDouble(operator_mod(operator_round(ScratchSetDouble((((((4) / (double)(ScratchVarGetDouble(argument_reporter_string_number(Yad)))))) * (255)))), ScratchSetDouble(256))))))))));
#define YIELD TRUE_YIELD
}

void YaSaeataZaBauafafaeariblbasiblbasiblbas(ScratchValue Yax, ScratchValue Yay, ScratchValue Yaz) 
{
	activeSprite = 1;
#define YIELD
	data_replaceitemoflist(ScratchSetDouble(((((((((ScratchVarGetDouble(argument_reporter_string_number(Yax))) + (ScratchVarGetDouble(YaNaiagobaZaMalaXwbaadbaJagaOamlba7aZhbaW))))) * ((((ScratchVarGetDouble(YaHaHasubaPaIahaYazlbqbbbaoa0a4ebsbaOa4eb)) + (ScratchVarGetDouble(YaHaHasubaPaIahaYazlbqbbbaoa0a4ebsbaOa4eb)))))))) + ((((ScratchVarGetDouble(argument_reporter_string_number(Yay))) + (ScratchVarGetDouble(YaHaHasubaPaIahaYazlbqbbbaoa0a4ebsbaOa4eb))))))), argument_reporter_string_number(Yaz), YaLafpbagjbaflbaTawtbayacagcbaO1bqbaoxba5);
#define YIELD TRUE_YIELD
}

void YaSaeataCaoalaBauafafaeariblbasiblbasiblbas(ScratchValue Yax, ScratchValue Yay, ScratchValue YaCaoal) 
{
	activeSprite = 1;
#define YIELD
	data_replaceitemoflist(ScratchSetDouble(((((((((ScratchVarGetDouble(argument_reporter_string_number(Yax))) + (ScratchVarGetDouble(YaNaiagobaZaMalaXwbaadbaJagaOamlba7aZhbaW))))) * ((((ScratchVarGetDouble(YaHaHasubaPaIahaYazlbqbbbaoa0a4ebsbaOa4eb)) + (ScratchVarGetDouble(YaHaHasubaPaIahaYazlbqbbbaoa0a4ebsbaOa4eb)))))))) + ((((ScratchVarGetDouble(argument_reporter_string_number(Yay))) + (ScratchVarGetDouble(YaHaHasubaPaIahaYazlbqbbbaoa0a4ebsbaOa4eb))))))), argument_reporter_string_number(YaCaoal), YaLafpbagjbaflbaTawtbayacagcbaO1bqbaoxba5);
#define YIELD TRUE_YIELD
}

void YaCalaeaaaribaBauafafaearas() 
{
	activeSprite = 1;
#define YIELD
	data_deletealloflist(Ya5avaBazaHadnbapa_bbaLa3abdbkbebhbmbobwb);
	data_deletealloflist(YaLafpbagjbaflbaTawtbayacagcbaO1bqbaoxba5);
	for(int i1 = 0; i1 < (int)((((ScratchVarGetDouble(YaNaiagobaZaMalaXwbaadbaJagaOamlba7aZhbaW)) + (ScratchVarGetDouble(YaNaiagobaZaMalaXwbaadbaJagaOamlba7aZhbaW))))); i1++)
	{
		for(int i2 = 0; i2 < (int)((((ScratchVarGetDouble(YaHaHasubaPaIahaYazlbqbbbaoa0a4ebsbaOa4eb)) + (ScratchVarGetDouble(YaHaHasubaPaIahaYazlbqbbbaoa0a4ebsbaOa4eb))))); i2++)
		{
			data_addtolist(ScratchSetDouble(0), YaLafpbagjbaflbaTawtbayacagcbaO1bqbaoxba5);
			data_addtolist(ScratchSetDouble(INFINITY), Ya5avaBazaHadnbapa_bbaLa3abdbkbebhbmbobwb);
			YIELD
		}
		YIELD
	}
#define YIELD TRUE_YIELD
}

void YaDaraaawaRaaasataear() 
{
	activeSprite = 1;
#define YIELD
	pen_clear();
	pen_setPenColorToColor(ScratchSetString("#000000"));
	pen_setPenSizeTo(ScratchSetDouble(1000));
	pen_penDown();
	pen_penUp();
	if(ScratchVarGetBool(operator_equals(Yjba8aZaNcbcbadaPubapaMawajaAaKcbaCa3bbaF, ScratchSetDouble(1))))
	{
		pen_setPenSizeTo(ScratchSetDouble(1));
	}
	else
	{
		pen_setPenSizeTo(ScratchSetDouble(((ScratchVarGetDouble(Yjba8aZaNcbcbadaPubapaMawajaAaKcbaCa3bbaF)) * (1.5))));
		motion_changexby(Yjba8aZaNcbcbadaPubapaMawajaAaKcbaCa3bbaF);
		motion_changeyby(Yjba8aZaNcbcbadaPubapaMawajaAaKcbaCa3bbaF);
	}
	data_setvariableto(ScratchSetDouble(0), YagcbkbebebtbadjbhbwbqbaoubaSaZhbamwblbhb);
	motion_gotoxy(-240,-180);
	for(int i1 = 0; i1 < (int)((((ScratchVarGetDouble(YaNaiagobaZaMalaXwbaadbaJagaOamlba7aZhbaW)) + (ScratchVarGetDouble(YaNaiagobaZaMalaXwbaadbaJagaOamlba7aZhbaW))))); i1++)
	{
		motion_sety(ScratchSetDouble(-180));
		for(int i2 = 0; i2 < (int)((((ScratchVarGetDouble(YaHaHasubaPaIahaYazlbqbbbaoa0a4ebsbaOa4eb)) + (ScratchVarGetDouble(YaHaHasubaPaIahaYazlbqbbbaoa0a4ebsbaOa4eb))))); i2++)
		{
			data_changevariableby(ScratchSetDouble(1), YagcbkbebebtbadjbhbwbqbaoubaSaZhbamwblbhb);
			pen_setPenColorToColor(data_itemoflist(YagcbkbebebtbadjbhbwbqbaoubaSaZhbamwblbhb, YaLafpbagjbaflbaTawtbayacagcbaO1bqbaoxba5));
			pen_penDown();
			pen_penUp();
			motion_changeyby(Yjba8aZaNcbcbadaPubapaMawajaAaKcbaCa3bbaF);
			YIELD
		}
		motion_changexby(Yjba8aZaNcbcbadaPubapaMawajaAaKcbaCa3bbaF);
		YIELD
	}
#define YIELD TRUE_YIELD
}

