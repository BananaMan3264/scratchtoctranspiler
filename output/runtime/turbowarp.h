#include <stdio.h>
#include "scratch.h"

void Yqekcknqekcknalaoagqekcknqekckniblbas(ScratchValue val) { printf("Log: %s\033[0m\n", ScratchVarGetString(val)); }
void Yqekcknqekcknawaaaranqekcknqekckniblbas(ScratchValue val) { printf("\033[1;33mWarn: %s\033[0m\n", ScratchVarGetString(val)); }
void Yqekcknqekcknaeararaoarqekcknqekckniblbas(ScratchValue val) { printf("\033[1;31mError: %s\033[0m\n", ScratchVarGetString(val)); }