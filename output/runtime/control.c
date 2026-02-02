#include <time.h>
#include "main.h"
#include "scratch.h"
#include "motion.h"
#include "types.h"

void control_wait(ScratchValue secs) 
{
	double startTime = clock() / (double)CLOCKS_PER_SEC;
	double _secs = ScratchVarGetDouble(secs);
	double time = (clock() / (double)CLOCKS_PER_SEC);
	while (time < startTime + _secs)
	{
		Yield();
		time = (clock() / (double)CLOCKS_PER_SEC);
	}
}