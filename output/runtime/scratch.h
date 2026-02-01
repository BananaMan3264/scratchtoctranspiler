#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include "runtime/motion.h"

#define operator_add(a,b)		 ScratchSetDouble(ScratchVarGetDouble(a)+ScratchVarGetDouble(b))
#define operator_subtract(a,b)	 ScratchSetDouble(ScratchVarGetDouble(a)-ScratchVarGetDouble(b))
#define operator_multiply(a,b)	 ScratchSetDouble(ScratchVarGetDouble(a)*ScratchVarGetDouble(b))
#define operator_divide(a,b)	 ScratchSetDouble(ScratchVarGetDouble(a)/ScratchVarGetDouble(b))
#define operator_mod(a,b)		 ScratchSetDouble(fmod(ScratchVarGetDouble(a)%ScratchVarGetDouble(b))) // fmod
#define operator_round(a)		 ScratchSetDouble(round(ScratchVarGetDouble(a)))
#define operator_equals(a,b)	 a==b

int operator_random(int min, int max)
{
	return rand() % (max - min) + min;
}

#define argument_reporter_string_number(a) a

#define motion_goto_menuY_araaanadaoama_() operator_random(-240, 240), operator_random(-180, 180)	// Motion Menu Random
#define motion_goto_menuY_amaoauasaea_()   sensing_mousex(), sensing_mousey()						// Motion Menu Mouse

#define motion_glideto_menuY_araaanadaoama_ motion_goto_menuY_araaanadaoama_						// Motion Menu Random
#define motion_glideto_menuY_amaoauasaea_   motion_goto_menuY_amaoauasaea_							// Motion Menu Mouse

#define motion_pointtowards_menuYaraaanadaoama_a motion_goto_menuY_araaanadaoama_					// Motion Menu Random
#define motion_pointtowards_menuYamaoauasaea_a   motion_goto_menuY_amaoauasaea_						// Motion Menu Mouse

#define data_setvariableto(a,b) b = a

enum ScratchType 
{
	ScratchType_Number,
	ScratchType_Bool,
	ScratchType_String
};

typedef struct ScratchVar 
{
	int ScratchType;
	union data
	{
		bool Bool;
		double Number;
		char* String;
	} data;
} ScratchValue;