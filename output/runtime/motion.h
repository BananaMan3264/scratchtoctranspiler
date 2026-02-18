#include "types.h"

extern double scratch_motion_SpriteX[];
extern double scratch_motion_SpriteY[];

extern bool PenDown;

void motion_movesteps(double Steps);
void motion_turnright(double degrees);
void motion_turnleft(double degrees);
void motion_goto(double x, double y);
void motion_pointtowards(ScratchValue dir);
void motion_changexby(double x);
void motion_changeyby(double y);
void motion_setx(double x);
void motion_sety(double y);
void motion_setrotationstyle_leftzncright();
void motion_setrotationstyle_donzhct_rotate();
void motion_setrotationstyle_all_around();
void motion_ifonedgebounce();
double motion_xposition();
double motion_yposition();
double motion_direction();
ScratchValue motion_pointtowards_menuY_amaoauasaea_();

#define motion_goto_menu_zpfrandomzpf() operator_random(-240, 240), operator_random(-180, 180)								
#define motion_goto_menu_zpfmousezpf()  ScratchVarGetDouble(sensing_mousex()), ScratchVarGetDouble(sensing_mousey())		

#define motion_glideto_menu_zpfrandomzpf motion_goto_menu_zpfrandomzpf
#define motion_glideto_menu_zpfmousezpf  motion_goto_menu_zpfmousezpf

#define motion_pointtowards_menu_zpfmousezpf() ScratchSetDouble(operator_random(0, 360))
#define motion_pointtowards_menu_zpfrandomzpf() ScratchSetDouble(atan2(ScratchVarGetDouble(sensing_mousey()), ScratchVarGetDouble(sensing_mousex())))

#define motion_gotoxy motion_goto
#define motion_pointindirection motion_pointtowards

double getX(double x, double y) { return x; }
double getY(double x, double y) { return y; }

#define motion_glideto(secs, pos)																					\
{																													\
double startTime = clock() / (double)CLOCKS_PER_SEC;																\
double _secs = secs, _x = getX(pos), _y = getY(pos);																\
double startx = scratch_motion_SpriteX[activeSprite], starty = scratch_motion_SpriteY[activeSprite];				\
double time = (clock() / (double)CLOCKS_PER_SEC);																	\
while (time < startTime + _secs)																					\
{																													\
	double t = (time - startTime) / (_secs);																		\
																													\
	double sx = _x * t + startx * (1 - t);																			\
	double sy = _y * t + starty * (1 - t);																			\
																													\
	if (PenDown)																									\
	{																												\
		penDrawLine(sx, sy, scratch_motion_SpriteX[activeSprite], scratch_motion_SpriteY[activeSprite]);			\
	}																												\
																													\
	scratch_motion_SpriteX[activeSprite] = sx;																		\
	scratch_motion_SpriteY[activeSprite] = sy;																		\
																													\
	YIELD																											\
	time = (clock() / (double)CLOCKS_PER_SEC);																		\
}																													\
																													\
scratch_motion_SpriteX[activeSprite] = _x;																			\
scratch_motion_SpriteY[activeSprite] = _y;																			\
}

#define motion_glidesecstoxy(secs, x, y)																			\
{																													\
double startTime = clock() / (double)CLOCKS_PER_SEC;																\
double _secs = secs, _x = x, _y = y;																				\
double startx = scratch_motion_SpriteX[activeSprite], starty = scratch_motion_SpriteY[activeSprite];				\
double time = (clock() / (double)CLOCKS_PER_SEC);																	\
while (time < startTime + _secs)																					\
{																													\
	double t = (time - startTime) / (_secs);																		\
																													\
	double sx = _x * t + startx * (1 - t);																			\
	double sy = _y * t + starty * (1 - t);																			\
																													\
	if (PenDown)																									\
	{																												\
		penDrawLine(sx, sy, scratch_motion_SpriteX[activeSprite], scratch_motion_SpriteY[activeSprite]);			\
	}																												\
																													\
	scratch_motion_SpriteX[activeSprite] = sx;																		\
	scratch_motion_SpriteY[activeSprite] = sy;																		\
																													\
	YIELD																											\
	time = (clock() / (double)CLOCKS_PER_SEC);																		\
}																													\
																													\
scratch_motion_SpriteX[activeSprite] = _x;																			\
scratch_motion_SpriteY[activeSprite] = _y;																			\
}