#include "types.h"
#include "../generated/schedule.h"
#include"../schedule_manager.h"

extern ThreadList threads;

#define event_broadcast(var) BroadcastInfo out = broadcast_##var(); free(out.threads)
#define event_broadcastandwait(var)											\
{																			\
	BroadcastInfo out = broadcast_##var(); 									\
																			\
	bool finished = false;													\
																			\
	while (!finished)														\
	{																		\
		finished = true;													\
		for (int i = 0; i < out.numthreads; i++)							\
		{																	\
			if (isThreadActive(out.threads[i]))								\
			{																\
				TRUE_YIELD													\
				finished = false;											\
				break;														\
			}																\
		}																	\
	}																		\
																			\
	free(out.threads);														\
}																			