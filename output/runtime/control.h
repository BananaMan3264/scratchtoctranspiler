#include <time.h>
#include <stdbool.h>
#include "types.h"

extern bool stop_all;

#define control_wait_until(a) while(!ScratchVarGetBool(a)) { YIELD }
#define control_wait(secs)									\
{															\
	double startTime = clock() / (double)CLOCKS_PER_SEC;	\
	double _secs = ScratchVarGetDouble(secs);				\
	double time = (clock() / (double)CLOCKS_PER_SEC);		\
	while (time < startTime + _secs)						\
	{														\
		YIELD												\
		time = (clock() / (double)CLOCKS_PER_SEC);			\
	}														\
}											
#define control_stop_other_scripts_in_sprite() stop_other = true

#define control_stop_all() stop_all = true

#define control_stop_this_script() END_THREAD