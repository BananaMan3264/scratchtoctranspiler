#include <stdio.h>
#include "scratch.h"

void _zcozaizlizcozaizlilogzcozaizlizcozaizli_zfcs(ScratchValue val) { printf("Log: %s\033[0m\n", ScratchVarGetString(val)); }
void _zcozaizlizcozaizliwarnzcozaizlizcozaizli_zfcs(ScratchValue val) { printf("\033[1;33mWarn: %s\033[0m\n", ScratchVarGetString(val)); }
void _zcozaizlizcozaizlierrorzcozaizlizcozaizli_zfcs(ScratchValue val) { printf("\033[1;31mError: %s\033[0m\n", ScratchVarGetString(val)); }