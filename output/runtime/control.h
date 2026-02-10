#include <time.h>
#include "types.h"

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