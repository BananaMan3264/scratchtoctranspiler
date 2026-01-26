#include<scratch.h>
double YbjaEakabb4acbiadbcbFakadbeb8axafbAaVagbhbmayaibvaaaraiaaabalaea = 1;
double Ya5aHacb2ajblbSagbpajbdbkbuajbmbqaNa8aeb = 0;
double Yaaanbdbabobyahbpbqbka2alagacala8afaabHa = 0;
double Ybga3ahamazajbwbtb4aaa9aOacadb4aFaQawaAa = 0;
double YbFaKaoaGaKaeabb8aUaDahagbgb4aiaLambVaVa = 0;
double YatbxbVa9apbiaeboakbHaqbeacaEawaOapbOaqb = 0;
double YabbPaobAaLa2a2a2a5aUaebVarbNaAaDaQaTaka = 0;
double Ybfb6atbua0aqaBaDa7axbYauavaEapaoaebIasb = 0;
double Yahasa9anb0arbWaLasaZaGaebxbpazaiaebMaEa = 0;
double YaAakbiaubxbvb1adbvblbVaiavaZa8axbhaJalb = 0;
char*  YawbRayaxaub9aabLarbba1alaHaEaVamazajb2a = "test";
int main() {
	start();
}
void Start () {
	motion_movesteps(10);
	motion_turnright(15);
	motion_turnleft(15);
	motion_goto(motion_goto_menuYaraaanadaoama_a());
	motion_goto(motion_goto_menuYamaoauasaea_a());
	motion_gotoxy(218, 57);
	motion_glideto(1, motion_glideto_menuYaraaanadaoama_a());
	motion_glideto(1, motion_glideto_menuYamaoauasaea_a());
	motion_glidesecstoxy(1, 218, 57);
	motion_pointindirection(90);
	motion_pointtowards(motion_pointtowards_menuYaraaanadaoama_a());
	motion_pointtowards(motion_pointtowards_menuYamaoauasaea_a());
	motion_changexby(10);
	motion_setx(218);
	motion_changeyby(10);
	motion_sety(57);
	motion_ifonedgebounce();
	motion_setrotationstyleYaeafatahbraiagahata();
	motion_setrotationstyleYaoanaybtaibraoataaataea();
	motion_setrotationstyleYalalaibaaraoauanada();
	motion_changexby(motion_xposition());
	motion_changexby(motion_yposition());
	motion_changexby(motion_direction());
	motion_gotoxy(sensing_mousex(), sensing_mousey());
	motion_changexby(operator_random(1, 10));
}
