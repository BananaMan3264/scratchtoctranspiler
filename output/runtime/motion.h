#include "types.h"

void motion_movesteps(ScratchValue steps);
void motion_turnright(ScratchValue degrees);
void motion_turnleft(ScratchValue degrees);
void motion_goto(ScratchValue x, ScratchValue y);
void motion_glideto(ScratchValue secs, ScratchValue x, ScratchValue y);
void motion_pointtowards(ScratchValue dir);
void motion_changexby(ScratchValue x);
void motion_changeyby(ScratchValue y);
void motion_setx(ScratchValue x);
void motion_sety(ScratchValue y);
void motion_setrotationstyleYlaeafathbaraiagahat();
void motion_setrotationstyleYdaoanybatibaraoataaatae();
void motion_setrotationstyleYaalalibaaaraoauanad();
void motion_ifonedgebounce();
ScratchValue motion_xposition();
ScratchValue motion_yposition();
ScratchValue motion_direction();
ScratchValue motion_pointtowards_menuY_amaoauasaea_();

#define motion_goto_menuY_araaanadaoama_() operator_random(ScratchSetDouble(-240), ScratchSetDouble(240)), operator_random(ScratchSetDouble(-180), ScratchSetDouble(180))	// Motion Menu Random
#define motion_goto_menuY_amaoauasaea_()   sensing_mousex(), sensing_mousey()						// Motion Menu Mouse

#define motion_glideto_menuY_araaanadaoama_ motion_goto_menuY_araaanadaoama_						// Motion Menu Random
#define motion_glideto_menuY_amaoauasaea_   motion_goto_menuY_amaoauasaea_							// Motion Menu Mouse

#define motion_pointtowards_menuY_araaanadaoama_() operator_random(ScratchSetDouble(0), ScratchSetDouble(360))

#define motion_gotoxy motion_goto
#define motion_glidesecstoxy motion_glideto
#define motion_pointindirection motion_pointtowards