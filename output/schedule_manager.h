#include "runtime/types.h"
void InitialiseThreads();
void AddThread(Thread data);
void RemoveThread(int idx2);
#define THREAD(cothread, idx) (Thread){idx, cothread}