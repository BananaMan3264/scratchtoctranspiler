#include "types.h"
#include "scratch.h"

ScratchValue sensing_keypressed(int key);
ScratchValue sensing_mousex();
ScratchValue sensing_mousey();

#define control_wait_until(a) while(!ScratchVarGetBool(a)) { YIELD }

#define sensing_keyoptionsYsapaaacae() SDL_SCANCODE_SPACE
#define sensing_keyoptionsY1() SDL_SCANCODE_1
#define sensing_keyoptionsY2() SDL_SCANCODE_2
#define sensing_keyoptionsY3() SDL_SCANCODE_3
#define sensing_keyoptionsY4() SDL_SCANCODE_4
#define sensing_keyoptionsY5() SDL_SCANCODE_5
#define sensing_keyoptionsY6() SDL_SCANCODE_6
#define sensing_keyoptionsY7() SDL_SCANCODE_7
#define sensing_keyoptionsY8() SDL_SCANCODE_8
#define sensing_keyoptionsY9() SDL_SCANCODE_9
#define sensing_keyoptionsY0() SDL_SCANCODE_0

#define sensing_keyoptionsYa() SDL_SCANCODE_A
#define sensing_keyoptionsYb() SDL_SCANCODE_B
#define sensing_keyoptionsYc() SDL_SCANCODE_C
#define sensing_keyoptionsYd() SDL_SCANCODE_D
#define sensing_keyoptionsYe() SDL_SCANCODE_E
#define sensing_keyoptionsYf() SDL_SCANCODE_F
#define sensing_keyoptionsYg() SDL_SCANCODE_G
#define sensing_keyoptionsYh() SDL_SCANCODE_H
#define sensing_keyoptionsYi() SDL_SCANCODE_I
#define sensing_keyoptionsYj() SDL_SCANCODE_J
#define sensing_keyoptionsYk() SDL_SCANCODE_K
#define sensing_keyoptionsYl() SDL_SCANCODE_L
#define sensing_keyoptionsYm() SDL_SCANCODE_M
#define sensing_keyoptionsYn() SDL_SCANCODE_N
#define sensing_keyoptionsYo() SDL_SCANCODE_O
#define sensing_keyoptionsYp() SDL_SCANCODE_P
#define sensing_keyoptionsYq() SDL_SCANCODE_Q
#define sensing_keyoptionsYr() SDL_SCANCODE_R
#define sensing_keyoptionsYs() SDL_SCANCODE_S
#define sensing_keyoptionsYt() SDL_SCANCODE_T
#define sensing_keyoptionsYu() SDL_SCANCODE_U
#define sensing_keyoptionsYv() SDL_SCANCODE_V
#define sensing_keyoptionsYw() SDL_SCANCODE_W
#define sensing_keyoptionsYx() SDL_SCANCODE_X
#define sensing_keyoptionsYy() SDL_SCANCODE_Y
#define sensing_keyoptionsYz() SDL_SCANCODE_Z