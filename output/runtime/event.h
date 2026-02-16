#include "types.h"
#include "../generated/schedule.h"
#include"../schedule_manager.h"

extern ThreadList threads;

#define event_broadcast(var) BroadcastInfo out = broadcast_##var(); free(out.threads)
#define event_broadcastandwait(var)										\
{																		\
	BroadcastInfo out = broadcast_##var(); 								\
																		\
restart:																\
																		\
	for (int i = 0; i < out.numthreads; i++) 							\
	{																	\
		if (isThreadActive(out.threads[i]))								\
		{																\
			TRUE_YIELD													\
			goto restart;												\
		}																\
	}																	\
																		\
	free(out.threads);													\
}																		