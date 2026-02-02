#include <math.h>
#include <string.h>
#include "scratch.h"
#include "looks.h"
#include "types.h"


extern double scratch_motion_SpriteSize[];
extern int scratch_looks_CostumeIndex[];
extern int scratch_looks_CostumeCounts[];
extern char* scratch_looks_CostumeNames[3][3];

extern double scratch_looks_effects_colour[];
extern double scratch_looks_effects_fisheye[];
extern double scratch_looks_effects_whirl[];
extern double scratch_looks_effects_pixelate[];
extern double scratch_looks_effects_mosaic[];
extern double scratch_looks_effects_brightness[];
extern double scratch_looks_effects_ghost[];

extern bool scratch_looks_hidden[];

extern int activeSprite;

#define SS  scratch_motion_SpriteSize[activeSprite]
#define SCI scratch_looks_CostumeIndex[activeSprite]
#define SCC scratch_looks_CostumeCounts[activeSprite]
#define SCN scratch_looks_CostumeNames[activeSprite]
#define SH  scratch_looks_hidden[activeSprite]

#define EFFECT_COLOUR     scratch_looks_effects_colour    [activeSprite]
#define EFFECT_FISHEYE    scratch_looks_effects_fisheye   [activeSprite]
#define EFFECT_WHIRL      scratch_looks_effects_whirl     [activeSprite]
#define EFFECT_PIXELATE   scratch_looks_effects_pixelate  [activeSprite]
#define EFFECT_MOSAIC     scratch_looks_effects_mosaic    [activeSprite]
#define EFFECT_BRIGHTNESS scratch_looks_effects_brightness[activeSprite]
#define EFFECT_GHOST      scratch_looks_effects_ghost     [activeSprite]

void looks_sayforsecs(ScratchValue text, ScratchValue secs)
{
	char* Text = ScratchVarGetString(text);
	double Secs = ScratchVarGetDouble(secs);
	//TODO: Finish this
}

void looks_say(ScratchValue text) 
{
	char* Text = ScratchVarGetString(text);
	//TODO: Finish this
}
void looks_thinkforsecs(ScratchValue text, ScratchValue secs)
{
	char* Text = ScratchVarGetString(text);
	double Secs = ScratchVarGetDouble(secs);
	//TODO: Finish this
}

void looks_think(ScratchValue text)
{
	char* Text = ScratchVarGetString(text);
	//TODO: Finish this
}

void looks_switchcostumeto(ScratchValue index)
{
	SCI = ((int)ScratchVarGetDouble(index) - 1)%(SCC);
}

void looks_nextcostume() 
{
	SCI = (SCI + 1) % (SCC);
}

void looks_switchbackdropto(ScratchValue index)
{
	scratch_looks_CostumeIndex[0] = ((int)ScratchVarGetDouble(index) - 1) % (scratch_looks_CostumeCounts[0]);
}

void looks_nextbackdrop()
{
	scratch_looks_CostumeIndex[0] = (scratch_looks_CostumeIndex[0] + 1) % (scratch_looks_CostumeCounts[0]);
}

void looks_changesizeby(ScratchValue change)
{
	SS += ScratchVarGetDouble(change);
}

void looks_setsizeto(ScratchValue val)
{
	SS = ScratchVarGetDouble(val);
}

void looks_changeeffectbyYCaOaLaOaR(ScratchValue change) 
{
	EFFECT_COLOUR += ScratchVarGetDouble(change);
}

void looks_seteffecttoYCaOaLaOaR(ScratchValue set) 
{
	EFFECT_COLOUR = ScratchVarGetDouble(set);
}

void looks_changeeffectbyYFaIaSaHaEaYaE(ScratchValue change)
{
	EFFECT_FISHEYE += ScratchVarGetDouble(change);
}

void looks_seteffecttoYFaIaSaHaEaYaE(ScratchValue set)
{
	EFFECT_FISHEYE = ScratchVarGetDouble(set);
}

void looks_changeeffectbyYWaHaIaRaL(ScratchValue change)
{
	EFFECT_WHIRL += ScratchVarGetDouble(change);
}

void looks_seteffecttoYWaHaIaRaL(ScratchValue set)
{
	EFFECT_WHIRL = ScratchVarGetDouble(set);
}

void looks_changeeffectbyYPaIaXaEaLaAaTaE(ScratchValue change)
{
	EFFECT_PIXELATE += ScratchVarGetDouble(change);
}

void looks_seteffecttoYPaIaXaEaLaAaTaE(ScratchValue set)
{
	EFFECT_PIXELATE = ScratchVarGetDouble(set);
}

void looks_changeeffectbyYMaOaSaAaIaC(ScratchValue change)
{
	EFFECT_MOSAIC += ScratchVarGetDouble(change);
}

void looks_seteffecttoYMaOaSaAaIaC(ScratchValue set)
{
	EFFECT_MOSAIC = ScratchVarGetDouble(set);
}

void looks_changeeffectbyYBaRaIaGaHaTaNaEaSaS(ScratchValue change)
{
	EFFECT_BRIGHTNESS += ScratchVarGetDouble(change);
}

void looks_seteffecttoYBaRaIaGaHaTaNaEaSaS(ScratchValue set)
{
	EFFECT_BRIGHTNESS = ScratchVarGetDouble(set);
}

void looks_changeeffectbyYGaHaOaSaT(ScratchValue change)
{
	EFFECT_GHOST += ScratchVarGetDouble(change);
}

void looks_seteffecttoYGaHaOaSaT(ScratchValue set)
{
	EFFECT_GHOST = ScratchVarGetDouble(set);
}

void looks_cleargraphiceffects() 
{
	EFFECT_COLOUR     = 0;
	EFFECT_FISHEYE    = 0;
	EFFECT_WHIRL      = 0;
	EFFECT_PIXELATE   = 0;
	EFFECT_MOSAIC     = 0;
	EFFECT_BRIGHTNESS = 0;
	EFFECT_GHOST      = 0;
}

void looks_show() 
{
	SH = false;
}

void looks_hide()
{
	SH = true;
}

void looks_gotofrontbackYfaraoanat() 
{
	// TODO: layering system
}

void looks_gotofrontbackYbaaacak() 
{
	// TODO: layering system
}

void looks_goforwardbackwardlayersYfaoarawaaarad(ScratchValue layers)
{
	// TODO: layering system
}

void looks_goforwardbackwardlayersYbaaacakawaaarad(ScratchValue layers)
{
	// TODO: layering system
}

ScratchValue looks_costumenumbernameYnauamabaear() 
{
	return ScratchSetDouble(SCI + 1);
}

ScratchValue looks_costumenumbernameYnaaamae() 
{
	return ScratchSetString(SCN[SCI]);
}

ScratchValue looks_backdropnumbernameYnauamabaear()
{
	return ScratchSetDouble(scratch_looks_CostumeIndex[0]);
}

ScratchValue looks_backdropnumbernameYnaaamae()
{
	return ScratchSetString(scratch_looks_CostumeNames[0][scratch_looks_CostumeIndex[0]]);
}

ScratchValue looks_size() 
{
	return ScratchSetDouble(SS);
}

ScratchValue looks_costume(ScratchValue id)
{
	char* str = ScratchVarGetString(id);
	for (int i = 0; i < SCC; i++) 
	{
		if (strcmp(SCN[i], str) == 0) 
		{
			return ScratchSetDouble(i + 1);
		}
	}
	return ScratchSetDouble(1);
}

ScratchValue looks_backdrops(ScratchValue id)
{
	char* str = ScratchVarGetString(id);
	for (int i = 0; i < scratch_looks_CostumeCounts[0]; i++)
	{
		if (strcmp(scratch_looks_CostumeNames[0][i], str) == 0)
		{
			return ScratchSetDouble(i + 1);
		}
	}
	return ScratchSetDouble(1);
}