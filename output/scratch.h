#include<math.h>
#include <stdlib.h>

#define operator_add(a,b)		 ((a)+(b))
#define operator_subtract(a,b)	 ((a)-(b))
#define operator_multiply(a,b)	 ((a)*(b))
#define operator_divide(a,b)	 ((a)/(double)(b))
#define operator_mod(a,b)		 ((a)%(b))
#define operator_round(a)		 round(a)

int operator_random(int min, int max)
{
	return rand() % (max - min) + min;
}

#define argument_reporter_string_number(a) a

#define motion_goto_menuYaraaanadaoama_a() operator_random(-240, 240), operator_random(-180, 180)	// Motion Menu Random
#define motion_goto_menuYamaoauasaea_a()   sensing_mousex(), sensing_mousey()

#define motion_glideto_menuYaraaanadaoama_a motion_goto_menuYaraaanadaoama_a
#define motion_glideto_menuYamaoauasaea_a   motion_goto_menuYamaoauasaea_a

#define motion_pointtowards_menuYaraaanadaoama_a motion_goto_menuYaraaanadaoama_a
#define motion_pointtowards_menuYamaoauasaea_a   motion_goto_menuYamaoauasaea_a