#include<scratch.h>
int main() {
	start();
}
void start() 
{
	motion_movesteps(operator_add(operator_add(1, 2), operator_add(1, operator_add(1, 2))));
	motion_turnright(operator_subtract(1, 1));
	motion_turnleft(operator_multiply(2, 4));
	motion_gotoxy(operator_divide(2, 8), 0);
	motion_glidesecstoxy(1, 186, 86);
	motion_pointindirection(90);
	motion_changexby(operator_mod(1, 2));
	motion_setx(operator_round(1.2));
	motion_changeyby(10);
	motion_sety(86);
	motion_ifonedgebounce();
	looks_sayforsecs("Hello!", 2);
	looks_say("Hello!");
	looks_thinkforsecs("Hmm...", 2);
	looks_think("Hmm...");
	looks_nextcostume();
	looks_nextbackdrop();
	looks_changesizeby(10);
	looks_setsizeto(100);
}
