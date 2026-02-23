#define YIELD TRUE_YIELD;
#include "../runtime/scratch.h"
#include "../runtime/motion.h"
#include "../runtime/looks.h"
#include "../runtime/sound.h"
#include "../runtime/operators.h"
#include "../runtime/control.h"
#include "../runtime/sensing.h"
#include "../runtime/data.h"
#include "../runtime/pen.h"
#include "../runtime/turbowarp.h"
#include "../runtime/event.h"
#include "schedule.h"
#include <libco.h>

extern cothread_t scheduler;
extern bool delete_thread;
extern bool stop_all;
extern bool stop_other;
extern bool gc_enabled;
extern int activeSprite;

double _0_c;
double _0_px;
double _0_py;
double _0_pa;
double _0_tempx;
double _0_tempy;
double _0_c1;
double _0_NearPlane;
double _0_Sector;
double _0_resolution;
double _0_SectorCount;
double _0_c2;
double _0_c3;
double _0_lastTime;
double _0_fps;
double _0_frames;
double _0_topCounter;
double _0_bottomCounter;
double _0_topSlope;
double _0_bottomSlope;
double _0_xleft;
double _0_xright;
double _0_globalyleft;
double _0_globalyright;
double _0_topzpft;
double _0_bottomzpft;
double _0_topBCounter;
double _0_topBSlope;
double _0_bottomBCounter;
double _0_bottomBSlope;
double _0_topCounterPrev;
double _0_bottomCounterPrev;
double _0_maxzpfdepth;
double _0_pzkh;
double _0_deltatime;
double _0_deltazpflasttime;
double _0_my_variable;
double _0_tempy2;
double _0_tempy3;
double _0_tempy4;
double _0_tempx2;
double _0_lastSpriteSector;
double _0_sectorOut;
double _0_t;
double _0_c4;
double _0_c5;
double _0_c6;
double _0_cpa;
double _0_spa;

ScratchValue* vars[] = 
{	&_0_c,
	&_0_px,
	&_0_py,
	&_0_pa,
	&_0_tempx,
	&_0_tempy,
	&_0_c1,
	&_0_NearPlane,
	&_0_Sector,
	&_0_resolution,
	&_0_SectorCount,
	&_0_c2,
	&_0_c3,
	&_0_lastTime,
	&_0_fps,
	&_0_frames,
	&_0_topCounter,
	&_0_bottomCounter,
	&_0_topSlope,
	&_0_bottomSlope,
	&_0_xleft,
	&_0_xright,
	&_0_globalyleft,
	&_0_globalyright,
	&_0_topzpft,
	&_0_bottomzpft,
	&_0_topBCounter,
	&_0_topBSlope,
	&_0_bottomBCounter,
	&_0_bottomBSlope,
	&_0_topCounterPrev,
	&_0_bottomCounterPrev,
	&_0_maxzpfdepth,
	&_0_pzkh,
	&_0_deltatime,
	&_0_deltazpflasttime,
	&_0_my_variable,
	&_0_tempy2,
	&_0_tempy3,
	&_0_tempy4,
	&_0_tempx2,
	&_0_lastSpriteSector,
	&_0_sectorOut,
	&_0_t,
	&_0_c4,
	&_0_c5,
	&_0_c6,
	&_0_cpa,
	&_0_spa,
};

ScratchList _LevelBase;
ScratchList _LevelTransform;
ScratchList _SectorPointers;
ScratchList _SectorLengths;
ScratchList _WallBounds;
ScratchList _SectorDataTransformed;
ScratchList _DrawCalls;
ScratchList _SectorData;
ScratchList _SectorCentres;
ScratchList _RealDrawCalls;
ScratchList _Actors;
ScratchList _ActorsTransform;
ScratchList _DefSectorPointers;
ScratchList _DefSectorLengths;

ScratchList* lists[] = 
{	&_LevelBase,
	&_LevelTransform,
	&_SectorPointers,
	&_SectorLengths,
	&_WallBounds,
	&_SectorDataTransformed,
	&_DrawCalls,
	&_SectorData,
	&_SectorCentres,
	&_RealDrawCalls,
	&_Actors,
	&_ActorsTransform,
	&_DefSectorPointers,
	&_DefSectorLengths,
};

int vars_length = 49, lists_length = 14;

void _0_Init()
{
	_0_c = 7.000000;
	_0_px = 9.826293;
	_0_py = -8.398392;
	_0_pa = 49.500000;
	_0_tempx = 1.000000;
	_0_tempy = 72.824228;
	_0_c1 = 278.323010;
	_0_NearPlane = 0.001000;
	_0_Sector = 0.000000;
	_0_resolution = 1.000000;
	_0_SectorCount = 2.000000;
	_0_c2 = -92.774337;
	_0_c3 = 0.000000;
	_0_lastTime = 1.001000;
	_0_fps = 31.000000;
	_0_frames = 16.000000;
	_0_topCounter = 115.238908;
	_0_bottomCounter = -69.143345;
	_0_topSlope = 6.082461;
	_0_bottomSlope = -2.027487;
	_0_xleft = 131.000000;
	_0_xright = 163.000000;
	_0_globalyleft = -240.000000;
	_0_globalyright = 240.000000;
	_0_topzpft = 0.600000;
	_0_bottomzpft = 0.333333;
	_0_topBCounter = 181.000000;
	_0_topBSlope = 1.121134;
	_0_bottomBCounter = -181.000000;
	_0_bottomBSlope = -0.373711;
	_0_topCounterPrev = 0.600000;
	_0_bottomCounterPrev = 0.333333;
	_0_maxzpfdepth = 10.000000;
	_0_pzkh = -5.000000;
	_0_deltatime = 0.032000;
	_0_deltazpflasttime = 1.529000;
	_0_my_variable = 1.000000;
	_0_tempy2 = -24.274743;
	_0_tempy3 = 277.991763;
	_0_tempy4 = -92.663921;
	_0_tempx2 = 0.000000;
	_0_lastSpriteSector = 0.000000;
	_0_sectorOut = 0.000000;
	_0_t = 0.000000;
	_0_c4 = 85.000000;
	_0_c5 = 0.000000;
	_0_c6 = 2.000000;
	_0_cpa = 0.760406;
	_0_spa = 0.649448;
	_LevelBase = initialiseList();
	_LevelTransform = initialiseList();
	_SectorPointers = initialiseList();
	_SectorLengths = initialiseList();
	_WallBounds = initialiseList();
	_SectorDataTransformed = initialiseList();
	_DrawCalls = initialiseList();
	_SectorData = initialiseList();
	_SectorCentres = initialiseList();
	_RealDrawCalls = initialiseList();
	_Actors = initialiseList();
	_ActorsTransform = initialiseList();
	_DefSectorPointers = initialiseList();
	_DefSectorLengths = initialiseList();
}



void _1_Init()
{
}

void _Debug_Level_Render();
void _Add_Wall_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs(double _x1, double _y1, double _x2, double _y2, double _colour, double _sector, double _portalto);
void _1__ldevent_whenflagclicked();
void _Input();
void _Transform_Level();
void _Prepare_Bounds();
void _Set_Sector_Pointers();
void _Render();
void _AddSector_zfcs_zfcs_zfcs_zfcs(double _top, double _bottom, double _floorColour, double _ceilingColour);
void _FPS();
void _Draw_Wall_zfcs_Bounds_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs(double _wall, double _bx1, double _by1, double _by2, double _bx2, double _by3, double _by4, double _depth);
void _AddDrawCall_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs(double _wall, double _bx1, double _by1, double _by2, double _bx2, double _by3, double _by4, double _depth);
void _Check_Sector();
void _Frame();
void _RotateWalls();
void _DrawRealWall_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs(double _xleft, double _xright, double _topSlope, double _topBSlope, double _bottomSlope, double _bottomBSlope, double _ceilColour, double _wallColour, double _floorColour, double _topCounter, double _topBCounter, double _bottomCounter, double _bottomBCounter);
void _AddRealDrawCall_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs(double _xleft, double _xright, double _topSlope, double _topBSlope, double _bottomSlope, double _bottomBSlope, double _ceilColour, double _wallColour, double _floorColour, double _topCounter, double _topBCounter, double _bottomCounter, double _bottomBCounter, double _sector);
void _Add_Actor_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs(double _x, double _y, double _zkh, double _sizkhe, double _sprite, double _sector);
void _Draw_Sprites_zfcs(double _sector);
void _Get_Sector_zfcs_zfcs(double _x, double _y);

void _Debug_Level_Render() 
{
	activeSprite = 1;
#define YIELD
	pen_clear();
	PenSize = 1;
	_0_c = 1;
	for(int i1 = 0; i1 < (int)((((_LevelTransform.length) / (double)(7)))); i1++)
	{
		pen_setPenColorToColor(_LevelTransform.data[iclamp(((4) + (_0_c)), 1, _LevelTransform.length) - 1]);
		motion_gotoxy(ScratchVarGetDouble(_LevelTransform.data[iclamp(_0_c, 1, _LevelTransform.length) - 1]), ScratchVarGetDouble(_LevelTransform.data[iclamp(((1) + (_0_c)), 1, _LevelTransform.length) - 1]));
		pen_penDown();
		motion_gotoxy(ScratchVarGetDouble(_LevelTransform.data[iclamp(((2) + (_0_c)), 1, _LevelTransform.length) - 1]), ScratchVarGetDouble(_LevelTransform.data[iclamp(((3) + (_0_c)), 1, _LevelTransform.length) - 1]));
		pen_penUp();
		_0_c += 7;
		YIELD
	}
#define YIELD TRUE_YIELD
}

void _Add_Wall_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs(double _x1, double _y1, double _x2, double _y2, double _colour, double _sector, double _portalto) 
{
	activeSprite = 1;
#define YIELD
	data_addtolist(ScratchSetDouble(_x1), _LevelBase);
	data_addtolist(ScratchSetDouble(_y1), _LevelBase);
	data_addtolist(ScratchSetDouble(_x2), _LevelBase);
	data_addtolist(ScratchSetDouble(_y2), _LevelBase);
	data_addtolist(ScratchSetDouble(_colour), _LevelBase);
	data_addtolist(ScratchSetDouble(_sector), _LevelBase);
	data_addtolist(ScratchSetDouble(_portalto), _LevelBase);
#define YIELD TRUE_YIELD
}

void _1__ldevent_whenflagclicked() 
{
	activeSprite = 1;
	_0_NearPlane = .001;
	_0_py = 0;
	_0_pa = 0;
	_0_px = 0;
	_0_SectorCount = 2;
	data_deletealloflist(_SectorData);
	_AddSector_zfcs_zfcs_zfcs_zfcs(-20, 20, ScratchVarGetDouble(ScratchSetString("#000000")), 0xffffff);
	_AddSector_zfcs_zfcs_zfcs_zfcs(-10, 10, ScratchVarGetDouble(ScratchSetString("#444444")), ScratchVarGetDouble(ScratchSetString("#666666")));
	data_deletealloflist(_LevelBase);
	_Add_Wall_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs(-10, 20, 10, 20, 0xff0000, 0, -1);
	_Add_Wall_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs(10, 20, 20, 10, 0xffff00, 0, -1);
	_Add_Wall_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs(20, 10, 20, -10, 0x00ff00, 0, 1);
	_Add_Wall_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs(10, -20, -10, -20, 0x0000ff, 0, -1);
	_Add_Wall_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs(-10, -20, -20, -10, 0x880000, 0, -1);
	_Add_Wall_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs(20, -10, 10, -20, 0x888800, 0, -1);
	_Add_Wall_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs(-20, -10, -20, 10, 0x008800, 0, -1);
	_Add_Wall_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs(-10, 20, -20, 10, 0x008888, 0, -1);
	_Add_Wall_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs(20, 10, 40, 10, ScratchVarGetDouble(ScratchSetString("#880088")), 1, -1);
	_Add_Wall_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs(40, 10, 40, -10, ScratchVarGetDouble(ScratchSetString("#ff00ff")), 1, -1);
	_Add_Wall_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs(40, -10, 20, -10, ScratchVarGetDouble(ScratchSetString("#ff8800")), 1, -1);
	_Add_Wall_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs(20, -10, 20, 10, ScratchVarGetDouble(ScratchSetString("#008800")), 1, 0);
	data_deletealloflist(_Actors);
	_Add_Actor_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs(10, 0, 0, 20, 1, 0);
	_0_lastTime = 0;
	_0_frames = 0;
	_0_resolution = 1;
	_0_deltazpflasttime = 0;
	data_deletealloflist(_SectorPointers);
	data_deletealloflist(_SectorLengths);
	for(int i1 = 0; i1 < (int)((_0_SectorCount)); i1++)
	{
		data_addtolist(ScratchSetDouble(0), _SectorPointers);
		YIELD
	}
	_Set_Sector_Pointers();
	_RotateWalls();
	while(1)
	{
		_Actors.data[iclamp(1, 1, _Actors.length) - 1] = ScratchSetDouble(((30) * (sin(((((clock() / (double)CLOCKS_PER_SEC)) * (100))) * DEG_TO_RAD))));
		_Frame();
		YIELD
	}
#define YIELD TRUE_YIELD
	END_THREAD
}

void _Input() 
{
	activeSprite = 1;
#define YIELD
	_0_deltatime = (((clock() / (double)CLOCKS_PER_SEC)) - (_0_deltazpflasttime));
	_0_deltazpflasttime = (clock() / (double)CLOCKS_PER_SEC);
	if(ScratchVarGetBool(sensing_keypressed(sensing_keyoptions_a())))
	{
		_0_pa += ((300) * (_0_deltatime));
	}
	if(ScratchVarGetBool(sensing_keypressed(sensing_keyoptions_d())))
	{
		_0_pa += ((-300) * (_0_deltatime));
	}
	_0_pzkh = ((ScratchVarGetDouble(_SectorData.data[iclamp(((((_0_Sector) * (4))) + (1)), 1, _SectorData.length) - 1])) + (15));
	if(ScratchVarGetBool(sensing_keypressed(sensing_keyoptions_w())))
	{
		_0_px += ((cos((_0_pa) * DEG_TO_RAD)) * (((30) * (_0_deltatime))));
		_0_py += ((sin((_0_pa) * DEG_TO_RAD)) * (((30) * (_0_deltatime))));
	}
	if(ScratchVarGetBool(sensing_keypressed(sensing_keyoptions_s())))
	{
		_0_px += ((cos((((_0_pa) + (180))) * DEG_TO_RAD)) * (((30) * (_0_deltatime))));
		_0_py += ((sin((((_0_pa) + (180))) * DEG_TO_RAD)) * (((30) * (_0_deltatime))));
	}
	if(ScratchVarGetBool(sensing_keypressed(sensing_keyoptions_q())))
	{
		_0_px += ((cos((((_0_pa) + (90))) * DEG_TO_RAD)) * (((30) * (_0_deltatime))));
		_0_py += ((sin((((_0_pa) + (90))) * DEG_TO_RAD)) * (((30) * (_0_deltatime))));
	}
	if(ScratchVarGetBool(sensing_keypressed(sensing_keyoptions_e())))
	{
		_0_px += ((cos((((_0_pa) + (270))) * DEG_TO_RAD)) * (((30) * (_0_deltatime))));
		_0_py += ((sin((((_0_pa) + (270))) * DEG_TO_RAD)) * (((30) * (_0_deltatime))));
	}
#define YIELD TRUE_YIELD
}

void _Transform_Level() 
{
	activeSprite = 1;
#define YIELD
	data_deletealloflist(_LevelTransform);
	_0_cpa = cos((((90) - (_0_pa))) * DEG_TO_RAD);
	_0_spa = sin((((90) - (_0_pa))) * DEG_TO_RAD);
	_0_c = 1;
	for(int i1 = 0; i1 < (int)((((_LevelBase.length) / (double)(7)))); i1++)
	{
		_0_tempx = ((ScratchVarGetDouble(_LevelBase.data[iclamp(_0_c, 1, _LevelBase.length) - 1])) - (_0_px));
		_0_tempy = ((ScratchVarGetDouble(_LevelBase.data[iclamp(((1) + (_0_c)), 1, _LevelBase.length) - 1])) - (_0_py));
		data_addtolist(ScratchSetDouble(((((_0_tempx) * (_0_cpa))) - (((_0_tempy) * (_0_spa))))), _LevelTransform);
		data_addtolist(ScratchSetDouble(((((_0_tempx) * (_0_spa))) + (((_0_tempy) * (_0_cpa))))), _LevelTransform);
		_0_tempx = ((ScratchVarGetDouble(_LevelBase.data[iclamp(((2) + (_0_c)), 1, _LevelBase.length) - 1])) - (_0_px));
		_0_tempy = ((ScratchVarGetDouble(_LevelBase.data[iclamp(((3) + (_0_c)), 1, _LevelBase.length) - 1])) - (_0_py));
		data_addtolist(ScratchSetDouble(((((_0_tempx) * (_0_cpa))) - (((_0_tempy) * (_0_spa))))), _LevelTransform);
		data_addtolist(ScratchSetDouble(((((_0_tempx) * (_0_spa))) + (((_0_tempy) * (_0_cpa))))), _LevelTransform);
		data_addtolist(_LevelBase.data[iclamp(((4) + (_0_c)), 1, _LevelBase.length) - 1], _LevelTransform);
		data_addtolist(_LevelBase.data[iclamp(((5) + (_0_c)), 1, _LevelBase.length) - 1], _LevelTransform);
		data_addtolist(_LevelBase.data[iclamp(((6) + (_0_c)), 1, _LevelBase.length) - 1], _LevelTransform);
		_0_c += 7;
		YIELD
	}
	_0_c = 1;
	for(int i1 = 0; i1 < (int)((((_LevelTransform.length) / (double)(7)))); i1++)
	{
		if((ScratchVarGetDouble(_LevelTransform.data[iclamp(((1) + (_0_c)), 1, _LevelTransform.length) - 1]) < _0_NearPlane) && (ScratchVarGetDouble(_LevelTransform.data[iclamp(((3) + (_0_c)), 1, _LevelTransform.length) - 1]) < _0_NearPlane))
		{
			data_deleteoflist(ScratchSetDouble(_0_c), _LevelTransform);
			data_deleteoflist(ScratchSetDouble(_0_c), _LevelTransform);
			data_deleteoflist(ScratchSetDouble(_0_c), _LevelTransform);
			data_deleteoflist(ScratchSetDouble(_0_c), _LevelTransform);
			data_deleteoflist(ScratchSetDouble(_0_c), _LevelTransform);
			data_deleteoflist(ScratchSetDouble(_0_c), _LevelTransform);
			data_deleteoflist(ScratchSetDouble(_0_c), _LevelTransform);
			_0_c += -7;
		}
		else
		{
			if(ScratchVarGetDouble(_LevelTransform.data[iclamp(((1) + (_0_c)), 1, _LevelTransform.length) - 1]) < _0_NearPlane)
			{
				_0_c1 = ((((_0_NearPlane) - (ScratchVarGetDouble(_LevelTransform.data[iclamp(((3) + (_0_c)), 1, _LevelTransform.length) - 1])))) / (double)(((ScratchVarGetDouble(_LevelTransform.data[iclamp(((1) + (_0_c)), 1, _LevelTransform.length) - 1])) - (ScratchVarGetDouble(_LevelTransform.data[iclamp(((3) + (_0_c)), 1, _LevelTransform.length) - 1])))));
				_LevelTransform.data[iclamp(_0_c, 1, _LevelTransform.length) - 1] = ScratchSetDouble(((((_0_c1) * (ScratchVarGetDouble(_LevelTransform.data[iclamp(_0_c, 1, _LevelTransform.length) - 1])))) + (((((1) - (_0_c1))) * (ScratchVarGetDouble(_LevelTransform.data[iclamp(((2) + (_0_c)), 1, _LevelTransform.length) - 1]))))));
				_LevelTransform.data[iclamp(((1) + (_0_c)), 1, _LevelTransform.length) - 1] = ScratchSetDouble(_0_NearPlane);
			}
			if(ScratchVarGetDouble(_LevelTransform.data[iclamp(((3) + (_0_c)), 1, _LevelTransform.length) - 1]) < _0_NearPlane)
			{
				_0_c1 = ((((_0_NearPlane) - (ScratchVarGetDouble(_LevelTransform.data[iclamp(((3) + (_0_c)), 1, _LevelTransform.length) - 1])))) / (double)(((ScratchVarGetDouble(_LevelTransform.data[iclamp(((1) + (_0_c)), 1, _LevelTransform.length) - 1])) - (ScratchVarGetDouble(_LevelTransform.data[iclamp(((3) + (_0_c)), 1, _LevelTransform.length) - 1])))));
				_LevelTransform.data[iclamp(((2) + (_0_c)), 1, _LevelTransform.length) - 1] = ScratchSetDouble(((((_0_c1) * (ScratchVarGetDouble(_LevelTransform.data[iclamp(_0_c, 1, _LevelTransform.length) - 1])))) + (((((1) - (_0_c1))) * (ScratchVarGetDouble(_LevelTransform.data[iclamp(((2) + (_0_c)), 1, _LevelTransform.length) - 1]))))));
				_LevelTransform.data[iclamp(((3) + (_0_c)), 1, _LevelTransform.length) - 1] = ScratchSetDouble(_0_NearPlane);
			}
		}
		_0_c += 7;
		YIELD
	}
	_0_c = 1;
	for(int i1 = 0; i1 < (int)((((_LevelTransform.length) / (double)(7)))); i1++)
	{
		if(0 > ((((ScratchVarGetDouble(_LevelTransform.data[iclamp(_0_c, 1, _LevelTransform.length) - 1])) * (((ScratchVarGetDouble(_LevelTransform.data[iclamp(((3) + (_0_c)), 1, _LevelTransform.length) - 1])) - (ScratchVarGetDouble(_LevelTransform.data[iclamp(((1) + (_0_c)), 1, _LevelTransform.length) - 1])))))) - (((ScratchVarGetDouble(_LevelTransform.data[iclamp(((1) + (_0_c)), 1, _LevelTransform.length) - 1])) * (((ScratchVarGetDouble(_LevelTransform.data[iclamp(((2) + (_0_c)), 1, _LevelTransform.length) - 1])) - (ScratchVarGetDouble(_LevelTransform.data[iclamp(_0_c, 1, _LevelTransform.length) - 1]))))))))
		{
			data_deleteoflist(ScratchSetDouble(_0_c), _LevelTransform);
			data_deleteoflist(ScratchSetDouble(_0_c), _LevelTransform);
			data_deleteoflist(ScratchSetDouble(_0_c), _LevelTransform);
			data_deleteoflist(ScratchSetDouble(_0_c), _LevelTransform);
			data_deleteoflist(ScratchSetDouble(_0_c), _LevelTransform);
			data_deleteoflist(ScratchSetDouble(_0_c), _LevelTransform);
			data_deleteoflist(ScratchSetDouble(_0_c), _LevelTransform);
			_0_c += -7;
		}
		_0_c += 7;
		YIELD
	}
	data_deletealloflist(_SectorDataTransformed);
	_0_c = 1;
	for(int i1 = 0; i1 < (int)((10.0)); i1++)
	{
		data_addtolist(ScratchSetDouble(((ScratchVarGetDouble(_SectorData.data[iclamp(_0_c, 1, _SectorData.length) - 1])) - (_0_pzkh))), _SectorDataTransformed);
		data_addtolist(ScratchSetDouble(((ScratchVarGetDouble(_SectorData.data[iclamp(((_0_c) + (1)), 1, _SectorData.length) - 1])) - (_0_pzkh))), _SectorDataTransformed);
		data_addtolist(_SectorData.data[iclamp(((_0_c) + (2)), 1, _SectorData.length) - 1], _SectorDataTransformed);
		data_addtolist(_SectorData.data[iclamp(((_0_c) + (3)), 1, _SectorData.length) - 1], _SectorDataTransformed);
		_0_c += 4;
		YIELD
	}
	data_deletealloflist(_ActorsTransform);
	_0_c = 1;
	for(int i1 = 0; i1 < (int)((((_Actors.length) / (double)(6)))); i1++)
	{
		_0_tempx = ((ScratchVarGetDouble(_Actors.data[iclamp(_0_c, 1, _Actors.length) - 1])) - (_0_px));
		_0_tempy = ((ScratchVarGetDouble(_Actors.data[iclamp(((_0_c) + (1)), 1, _Actors.length) - 1])) - (_0_py));
		data_addtolist(ScratchSetDouble(((((_0_tempx) * (_0_cpa))) - (((_0_tempy) * (_0_spa))))), _ActorsTransform);
		data_addtolist(ScratchSetDouble(((((_0_tempx) * (_0_spa))) + (((_0_tempy) * (_0_cpa))))), _ActorsTransform);
		data_addtolist(ScratchSetDouble(((ScratchVarGetDouble(_Actors.data[iclamp(((_0_c) + (2)), 1, _Actors.length) - 1])) - (_0_pzkh))), _ActorsTransform);
		data_addtolist(_Actors.data[iclamp(((_0_c) + (3)), 1, _Actors.length) - 1], _ActorsTransform);
		data_addtolist(_Actors.data[iclamp(((_0_c) + (4)), 1, _Actors.length) - 1], _ActorsTransform);
		_Get_Sector_zfcs_zfcs(ScratchVarGetDouble(_Actors.data[iclamp(_0_c, 1, _Actors.length) - 1]), ScratchVarGetDouble(_Actors.data[iclamp(((_0_c) + (1)), 1, _Actors.length) - 1]));
		data_addtolist(ScratchSetDouble(_0_sectorOut), _ActorsTransform);
		_0_c += 6;
		YIELD
	}
#define YIELD TRUE_YIELD
}

void _Prepare_Bounds() 
{
	activeSprite = 1;
#define YIELD
	data_deletealloflist(_WallBounds);
	_0_c = 1;
	_0_c3 = 0;
	for(int i1 = 0; i1 < (int)((((_LevelTransform.length) / (double)(7)))); i1++)
	{
		_0_c1 = ((100) * (((ScratchVarGetDouble(_LevelTransform.data[iclamp(((2) + (_0_c)), 1, _LevelTransform.length) - 1])) / (double)(ScratchVarGetDouble(_LevelTransform.data[iclamp(((3) + (_0_c)), 1, _LevelTransform.length) - 1])))));
		_0_c2 = ((100) * (((ScratchVarGetDouble(_LevelTransform.data[iclamp(_0_c, 1, _LevelTransform.length) - 1])) / (double)(ScratchVarGetDouble(_LevelTransform.data[iclamp(((1) + (_0_c)), 1, _LevelTransform.length) - 1])))));
		if(_0_c1 < _0_c2)
		{
			data_addtolist(ScratchSetDouble(_0_c1), _WallBounds);
			data_addtolist(ScratchSetDouble(_0_c2), _WallBounds);
			_0_c1 = ((100) * (((ScratchVarGetDouble(_SectorDataTransformed.data[iclamp(((2) + (((ScratchVarGetDouble(_LevelTransform.data[iclamp(((5) + (_0_c)), 1, _LevelTransform.length) - 1])) * (4)))), 1, _SectorDataTransformed.length) - 1])) / (double)(ScratchVarGetDouble(_LevelTransform.data[iclamp(((3) + (_0_c)), 1, _LevelTransform.length) - 1])))));
			_0_c2 = ((100) * (((ScratchVarGetDouble(_SectorDataTransformed.data[iclamp(((1) + (((ScratchVarGetDouble(_LevelTransform.data[iclamp(((5) + (_0_c)), 1, _LevelTransform.length) - 1])) * (4)))), 1, _SectorDataTransformed.length) - 1])) / (double)(ScratchVarGetDouble(_LevelTransform.data[iclamp(((3) + (_0_c)), 1, _LevelTransform.length) - 1])))));
			if(_0_c1 < _0_c2)
			{
				data_addtolist(ScratchSetDouble(_0_c1), _WallBounds);
				data_addtolist(ScratchSetDouble(_0_c2), _WallBounds);
			}
			else
			{
				data_addtolist(ScratchSetDouble(_0_c2), _WallBounds);
				data_addtolist(ScratchSetDouble(_0_c1), _WallBounds);
			}
			_0_c1 = ((100) * (((ScratchVarGetDouble(_SectorDataTransformed.data[iclamp(((2) + (((ScratchVarGetDouble(_LevelTransform.data[iclamp(((5) + (_0_c)), 1, _LevelTransform.length) - 1])) * (4)))), 1, _SectorDataTransformed.length) - 1])) / (double)(ScratchVarGetDouble(_LevelTransform.data[iclamp(((1) + (_0_c)), 1, _LevelTransform.length) - 1])))));
			_0_c2 = ((100) * (((ScratchVarGetDouble(_SectorDataTransformed.data[iclamp(((1) + (((ScratchVarGetDouble(_LevelTransform.data[iclamp(((5) + (_0_c)), 1, _LevelTransform.length) - 1])) * (4)))), 1, _SectorDataTransformed.length) - 1])) / (double)(ScratchVarGetDouble(_LevelTransform.data[iclamp(((1) + (_0_c)), 1, _LevelTransform.length) - 1])))));
			if(_0_c1 < _0_c2)
			{
				data_addtolist(ScratchSetDouble(_0_c1), _WallBounds);
				data_addtolist(ScratchSetDouble(_0_c2), _WallBounds);
			}
			else
			{
				data_addtolist(ScratchSetDouble(_0_c2), _WallBounds);
				data_addtolist(ScratchSetDouble(_0_c1), _WallBounds);
			}
		}
		else
		{
			data_addtolist(ScratchSetDouble(_0_c2), _WallBounds);
			data_addtolist(ScratchSetDouble(_0_c1), _WallBounds);
			_0_c1 = ((100) * (((ScratchVarGetDouble(_SectorDataTransformed.data[iclamp(((2) + (((ScratchVarGetDouble(_LevelTransform.data[iclamp(((5) + (_0_c)), 1, _LevelTransform.length) - 1])) * (4)))), 1, _SectorDataTransformed.length) - 1])) / (double)(ScratchVarGetDouble(_LevelTransform.data[iclamp(((1) + (_0_c)), 1, _LevelTransform.length) - 1])))));
			_0_c2 = ((100) * (((ScratchVarGetDouble(_SectorDataTransformed.data[iclamp(((1) + (((ScratchVarGetDouble(_LevelTransform.data[iclamp(((5) + (_0_c)), 1, _LevelTransform.length) - 1])) * (4)))), 1, _SectorDataTransformed.length) - 1])) / (double)(ScratchVarGetDouble(_LevelTransform.data[iclamp(((1) + (_0_c)), 1, _LevelTransform.length) - 1])))));
			if(_0_c1 < _0_c2)
			{
				data_addtolist(ScratchSetDouble(_0_c1), _WallBounds);
				data_addtolist(ScratchSetDouble(_0_c2), _WallBounds);
			}
			else
			{
				data_addtolist(ScratchSetDouble(_0_c2), _WallBounds);
				data_addtolist(ScratchSetDouble(_0_c1), _WallBounds);
			}
			_0_c1 = ((100) * (((ScratchVarGetDouble(_SectorDataTransformed.data[iclamp(((2) + (((ScratchVarGetDouble(_LevelTransform.data[iclamp(((5) + (_0_c)), 1, _LevelTransform.length) - 1])) * (4)))), 1, _SectorDataTransformed.length) - 1])) / (double)(ScratchVarGetDouble(_LevelTransform.data[iclamp(((3) + (_0_c)), 1, _LevelTransform.length) - 1])))));
			_0_c2 = ((100) * (((ScratchVarGetDouble(_SectorDataTransformed.data[iclamp(((1) + (((ScratchVarGetDouble(_LevelTransform.data[iclamp(((5) + (_0_c)), 1, _LevelTransform.length) - 1])) * (4)))), 1, _SectorDataTransformed.length) - 1])) / (double)(ScratchVarGetDouble(_LevelTransform.data[iclamp(((3) + (_0_c)), 1, _LevelTransform.length) - 1])))));
			if(_0_c1 < _0_c2)
			{
				data_addtolist(ScratchSetDouble(_0_c1), _WallBounds);
				data_addtolist(ScratchSetDouble(_0_c2), _WallBounds);
			}
			else
			{
				data_addtolist(ScratchSetDouble(_0_c2), _WallBounds);
				data_addtolist(ScratchSetDouble(_0_c1), _WallBounds);
			}
		}
		data_addtolist(ScratchSetString(""), _WallBounds);
		_0_c += 7;
		YIELD
	}
#define YIELD TRUE_YIELD
}

void _Set_Sector_Pointers() 
{
	activeSprite = 1;
#define YIELD
	data_deletealloflist(_SectorLengths);
	_0_c = 1;
	for(int i1 = 0; i1 < (int)((_0_SectorCount)); i1++)
	{
		_SectorPointers.data[iclamp(_0_c, 1, _SectorPointers.length) - 1] = ScratchSetDouble(-1);
		data_addtolist(ScratchSetDouble(0), _SectorLengths);
		_0_c++;
		YIELD
	}
	_0_c = 6;
	for(int i1 = 0; i1 < (int)((((_LevelTransform.length) / (double)(7)))); i1++)
	{
		if(operator_equals(_SectorPointers.data[iclamp(((1) + (ScratchVarGetDouble(_LevelTransform.data[iclamp(_0_c, 1, _LevelTransform.length) - 1]))), 1, _SectorPointers.length) - 1], ScratchSetDouble(-1)))
		{
			_SectorPointers.data[iclamp(((1) + (ScratchVarGetDouble(_LevelTransform.data[iclamp(_0_c, 1, _LevelTransform.length) - 1]))), 1, _SectorPointers.length) - 1] = ScratchSetDouble(((_0_c) - (5)));
		}
		_SectorLengths.data[iclamp(((ScratchVarGetDouble(_LevelTransform.data[iclamp(_0_c, 1, _LevelTransform.length) - 1])) + (1)), 1, _SectorLengths.length) - 1] = ScratchSetDouble(((1) + (ScratchVarGetDouble(_SectorLengths.data[iclamp(((ScratchVarGetDouble(_LevelTransform.data[iclamp(_0_c, 1, _LevelTransform.length) - 1])) + (1)), 1, _SectorLengths.length) - 1]))));
		_0_c += 7;
		YIELD
	}
#define YIELD TRUE_YIELD
}

void _Render() 
{
	activeSprite = 1;
#define YIELD
	data_deletealloflist(_DrawCalls);
	data_deletealloflist(_RealDrawCalls);
	pen_clear();
	if(_0_resolution == 1)
	{
		PenSize = 1;
	}
	else
	{
		PenSize = ((_0_resolution) * (1.5));
	}
	_0_c = 0;
	for(int i1 = 0; i1 < (int)ScratchVarGetDouble(_SectorLengths.data[iclamp(((_0_Sector) + (1)), 1, _SectorLengths.length) - 1]); i1++)
	{
		_AddDrawCall_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs(((ScratchVarGetDouble(_SectorPointers.data[iclamp(((_0_Sector) + (1)), 1, _SectorPointers.length) - 1])) + (_0_c)), _0_globalyleft, 181, -181, _0_globalyright, 181, -181, 0);
		_0_c += 7;
		YIELD
	}
	while(!(_DrawCalls.length == 0))
	{
		_Draw_Wall_zfcs_Bounds_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs(ScratchVarGetDouble(_DrawCalls.data[iclamp(1, 1, _DrawCalls.length) - 1]), ScratchVarGetDouble(_DrawCalls.data[iclamp(2, 1, _DrawCalls.length) - 1]), ScratchVarGetDouble(_DrawCalls.data[iclamp(3, 1, _DrawCalls.length) - 1]), ScratchVarGetDouble(_DrawCalls.data[iclamp(4, 1, _DrawCalls.length) - 1]), ScratchVarGetDouble(_DrawCalls.data[iclamp(5, 1, _DrawCalls.length) - 1]), ScratchVarGetDouble(_DrawCalls.data[iclamp(6, 1, _DrawCalls.length) - 1]), ScratchVarGetDouble(_DrawCalls.data[iclamp(7, 1, _DrawCalls.length) - 1]), ScratchVarGetDouble(_DrawCalls.data[iclamp(8, 1, _DrawCalls.length) - 1]));
		data_deleteoflist(ScratchSetDouble(1.0), _DrawCalls);
		data_deleteoflist(ScratchSetDouble(1.0), _DrawCalls);
		data_deleteoflist(ScratchSetDouble(1.0), _DrawCalls);
		data_deleteoflist(ScratchSetDouble(1.0), _DrawCalls);
		data_deleteoflist(ScratchSetDouble(1.0), _DrawCalls);
		data_deleteoflist(ScratchSetDouble(1.0), _DrawCalls);
		data_deleteoflist(ScratchSetDouble(1.0), _DrawCalls);
		data_deleteoflist(ScratchSetDouble(1.0), _DrawCalls);
		YIELD
	}
	_0_lastSpriteSector = -1;
	while(!(_RealDrawCalls.length == 0))
	{
		if(!(operator_equals(_RealDrawCalls.data[iclamp(((_RealDrawCalls.length) - (13)), 1, _RealDrawCalls.length) - 1], ScratchSetDouble(_0_lastSpriteSector))))
		{
			_Draw_Sprites_zfcs(_0_lastSpriteSector);
			_0_lastSpriteSector = ScratchVarGetDouble(_RealDrawCalls.data[iclamp(((_RealDrawCalls.length) - (13)), 1, _RealDrawCalls.length) - 1]);
		}
		_DrawRealWall_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs(ScratchVarGetDouble(_RealDrawCalls.data[iclamp(((_RealDrawCalls.length) - (12)), 1, _RealDrawCalls.length) - 1]), ScratchVarGetDouble(_RealDrawCalls.data[iclamp(((_RealDrawCalls.length) - (11)), 1, _RealDrawCalls.length) - 1]), ScratchVarGetDouble(_RealDrawCalls.data[iclamp(((_RealDrawCalls.length) - (10)), 1, _RealDrawCalls.length) - 1]), ScratchVarGetDouble(_RealDrawCalls.data[iclamp(((_RealDrawCalls.length) - (9)), 1, _RealDrawCalls.length) - 1]), ScratchVarGetDouble(_RealDrawCalls.data[iclamp(((_RealDrawCalls.length) - (8)), 1, _RealDrawCalls.length) - 1]), ScratchVarGetDouble(_RealDrawCalls.data[iclamp(((_RealDrawCalls.length) - (7)), 1, _RealDrawCalls.length) - 1]), ScratchVarGetDouble(_RealDrawCalls.data[iclamp(((_RealDrawCalls.length) - (6)), 1, _RealDrawCalls.length) - 1]), ScratchVarGetDouble(_RealDrawCalls.data[iclamp(((_RealDrawCalls.length) - (5)), 1, _RealDrawCalls.length) - 1]), ScratchVarGetDouble(_RealDrawCalls.data[iclamp(((_RealDrawCalls.length) - (4)), 1, _RealDrawCalls.length) - 1]), ScratchVarGetDouble(_RealDrawCalls.data[iclamp(((_RealDrawCalls.length) - (3)), 1, _RealDrawCalls.length) - 1]), ScratchVarGetDouble(_RealDrawCalls.data[iclamp(((_RealDrawCalls.length) - (2)), 1, _RealDrawCalls.length) - 1]), ScratchVarGetDouble(_RealDrawCalls.data[iclamp(((_RealDrawCalls.length) - (1)), 1, _RealDrawCalls.length) - 1]), ScratchVarGetDouble(_RealDrawCalls.data[iclamp(_RealDrawCalls.length, 1, _RealDrawCalls.length) - 1]));
		data_deleteoflist(ScratchSetDouble(_RealDrawCalls.length), _RealDrawCalls);
		data_deleteoflist(ScratchSetDouble(_RealDrawCalls.length), _RealDrawCalls);
		data_deleteoflist(ScratchSetDouble(_RealDrawCalls.length), _RealDrawCalls);
		data_deleteoflist(ScratchSetDouble(_RealDrawCalls.length), _RealDrawCalls);
		data_deleteoflist(ScratchSetDouble(_RealDrawCalls.length), _RealDrawCalls);
		data_deleteoflist(ScratchSetDouble(_RealDrawCalls.length), _RealDrawCalls);
		data_deleteoflist(ScratchSetDouble(_RealDrawCalls.length), _RealDrawCalls);
		data_deleteoflist(ScratchSetDouble(_RealDrawCalls.length), _RealDrawCalls);
		data_deleteoflist(ScratchSetDouble(_RealDrawCalls.length), _RealDrawCalls);
		data_deleteoflist(ScratchSetDouble(_RealDrawCalls.length), _RealDrawCalls);
		data_deleteoflist(ScratchSetDouble(_RealDrawCalls.length), _RealDrawCalls);
		data_deleteoflist(ScratchSetDouble(_RealDrawCalls.length), _RealDrawCalls);
		data_deleteoflist(ScratchSetDouble(_RealDrawCalls.length), _RealDrawCalls);
		data_deleteoflist(ScratchSetDouble(_RealDrawCalls.length), _RealDrawCalls);
		YIELD
	}
	_Draw_Sprites_zfcs(_0_Sector);
#define YIELD TRUE_YIELD
}

void _AddSector_zfcs_zfcs_zfcs_zfcs(double _top, double _bottom, double _floorColour, double _ceilingColour) 
{
	activeSprite = 1;
#define YIELD FUNCTION_YIELD
	data_addtolist(ScratchSetDouble(_top), _SectorData);
	data_addtolist(ScratchSetDouble(_bottom), _SectorData);
	data_addtolist(ScratchSetDouble(_floorColour), _SectorData);
	data_addtolist(ScratchSetDouble(_ceilingColour), _SectorData);
#define YIELD TRUE_YIELD
}

void _FPS() 
{
	activeSprite = 1;
#define YIELD
	_0_frames++;
	if((clock() / (double)CLOCKS_PER_SEC) > ((_0_lastTime) + (1)))
	{
		_0_lastTime = (clock() / (double)CLOCKS_PER_SEC);
		_0_fps = _0_frames;
		_0_frames = 0;
	}
#define YIELD TRUE_YIELD
}

void _Draw_Wall_zfcs_Bounds_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs(double _wall, double _bx1, double _by1, double _by2, double _bx2, double _by3, double _by4, double _depth) 
{
	activeSprite = 1;
#define YIELD
	if(ceil((ScratchVarGetDouble(_WallBounds.data[iclamp(_wall, 1, _WallBounds.length) - 1]))) < ceil((_bx1)))
	{
		_0_xleft = ceil((_bx1));
	}
	else
	{
		_0_xleft = ceil((ScratchVarGetDouble(_WallBounds.data[iclamp(_wall, 1, _WallBounds.length) - 1])));
	}
	if(ceil((ScratchVarGetDouble(_WallBounds.data[iclamp(((_wall) + (1)), 1, _WallBounds.length) - 1]))) > ceil((_bx2)))
	{
		_0_xright = ceil((_bx2));
	}
	else
	{
		_0_xright = ceil((ScratchVarGetDouble(_WallBounds.data[iclamp(((_wall) + (1)), 1, _WallBounds.length) - 1])));
	}
	_0_topBCounter = _by1;
	_0_topBSlope = ((((_by1) - (_by3))) / (double)(((_bx1) - (_bx2))));
	_0_topBCounter += ((_0_topBSlope) * (((_0_xleft) - (ceil((_bx1))))));
	_0_topBSlope = ((_0_topBSlope) * (_0_resolution));
	_0_bottomBCounter = _by2;
	_0_bottomBSlope = ((((_by2) - (_by4))) / (double)(((_bx1) - (_bx2))));
	_0_bottomBCounter += ((_0_bottomBSlope) * (((_0_xleft) - (ceil((_bx1))))));
	_0_bottomBSlope = ((_0_bottomBSlope) * (_0_resolution));
	_0_topCounter = ScratchVarGetDouble(_WallBounds.data[iclamp(((_wall) + (3)), 1, _WallBounds.length) - 1]);
	_0_topSlope = ((((ScratchVarGetDouble(_WallBounds.data[iclamp(((_wall) + (3)), 1, _WallBounds.length) - 1])) - (ScratchVarGetDouble(_WallBounds.data[iclamp(((_wall) + (5)), 1, _WallBounds.length) - 1])))) / (double)(((ScratchVarGetDouble(_WallBounds.data[iclamp(_wall, 1, _WallBounds.length) - 1])) - (ScratchVarGetDouble(_WallBounds.data[iclamp(((_wall) + (1)), 1, _WallBounds.length) - 1])))));
	_0_topCounter += ((_0_topSlope) * (((_0_xleft) - (ceil((ScratchVarGetDouble(_WallBounds.data[iclamp(_wall, 1, _WallBounds.length) - 1])))))));
	_0_topSlope = ((_0_topSlope) * (_0_resolution));
	_0_bottomCounter = ScratchVarGetDouble(_WallBounds.data[iclamp(((_wall) + (2)), 1, _WallBounds.length) - 1]);
	_0_bottomSlope = ((((ScratchVarGetDouble(_WallBounds.data[iclamp(((_wall) + (2)), 1, _WallBounds.length) - 1])) - (ScratchVarGetDouble(_WallBounds.data[iclamp(((_wall) + (4)), 1, _WallBounds.length) - 1])))) / (double)(((ScratchVarGetDouble(_WallBounds.data[iclamp(_wall, 1, _WallBounds.length) - 1])) - (ScratchVarGetDouble(_WallBounds.data[iclamp(((_wall) + (1)), 1, _WallBounds.length) - 1])))));
	_0_bottomCounter += ((_0_bottomSlope) * (((_0_xleft) - (ceil((ScratchVarGetDouble(_WallBounds.data[iclamp(_wall, 1, _WallBounds.length) - 1])))))));
	_0_bottomSlope = ((_0_bottomSlope) * (_0_resolution));
	if((_depth < _0_maxzpfdepth) && (!(operator_equals(_LevelTransform.data[iclamp(((_wall) + (6)), 1, _LevelTransform.length) - 1], ScratchSetDouble(-1)))))
	{
		_0_bottomzpft = ((ScratchVarGetDouble(_SectorDataTransformed.data[iclamp(((((ScratchVarGetDouble(_LevelTransform.data[iclamp(((_wall) + (6)), 1, _LevelTransform.length) - 1])) * (4))) + (1)), 1, _SectorDataTransformed.length) - 1])) / (double)(ScratchVarGetDouble(_SectorDataTransformed.data[iclamp(((((ScratchVarGetDouble(_LevelTransform.data[iclamp(((_wall) + (5)), 1, _LevelTransform.length) - 1])) * (4))) + (1)), 1, _SectorDataTransformed.length) - 1])));
		_0_topzpft = ((ScratchVarGetDouble(_SectorDataTransformed.data[iclamp(((((ScratchVarGetDouble(_LevelTransform.data[iclamp(((_wall) + (6)), 1, _LevelTransform.length) - 1])) * (4))) + (2)), 1, _SectorDataTransformed.length) - 1])) / (double)(ScratchVarGetDouble(_SectorDataTransformed.data[iclamp(((((ScratchVarGetDouble(_LevelTransform.data[iclamp(((_wall) + (5)), 1, _LevelTransform.length) - 1])) * (4))) + (2)), 1, _SectorDataTransformed.length) - 1])));
		if(_0_topzpft < 1)
		{
			_0_tempy = ((_0_topCounter) * (_0_topzpft));
			_0_tempy3 = ((((_0_topCounter) + (((((_0_xright) - (_0_xleft))) * (_0_topSlope))))) * (_0_topzpft));
		}
		else
		{
			_0_tempy = _0_topCounter;
			_0_tempy3 = ((_0_topCounter) + (((((_0_xright) - (_0_xleft))) * (_0_topSlope))));
		}
		if(_0_bottomzpft < 1)
		{
			_0_tempy2 = ((_0_bottomCounter) * (_0_bottomzpft));
			_0_tempy4 = ((((_0_bottomCounter) + (((((_0_xright) - (_0_xleft))) * (_0_bottomSlope))))) * (_0_bottomzpft));
		}
		else
		{
			_0_tempy2 = _0_bottomCounter;
			_0_tempy4 = ((_0_bottomCounter) + (((((_0_xright) - (_0_xleft))) * (_0_bottomSlope))));
		}
		_0_tempx = ScratchVarGetDouble(ScratchSetBool(((_0_topCounter) * (_0_topzpft)) < _0_topCounter));
		_0_tempx2 = ScratchVarGetDouble(ScratchSetBool(((_0_bottomCounter) * (_0_bottomzpft)) < _0_bottomCounter));
		_AddRealDrawCall_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs(_0_xleft, _0_xright, _0_topSlope, _0_topBSlope, ((((((_0_topSlope) * (_0_topzpft))) * (_0_tempx))) + (((_0_topSlope) * (((1) - (_0_tempx)))))), ((((((_0_topSlope) * (_0_topzpft))) * (_0_tempx))) + (((_0_topSlope) * (((1) - (_0_tempx)))))), ScratchVarGetDouble(_SectorDataTransformed.data[iclamp(((((ScratchVarGetDouble(_LevelTransform.data[iclamp(((_wall) + (5)), 1, _LevelTransform.length) - 1])) * (4))) + (4)), 1, _SectorDataTransformed.length) - 1]), ScratchVarGetDouble(_LevelTransform.data[iclamp(((_wall) + (4)), 1, _LevelTransform.length) - 1]), ScratchVarGetDouble(_SectorDataTransformed.data[iclamp(((((ScratchVarGetDouble(_LevelTransform.data[iclamp(((_wall) + (5)), 1, _LevelTransform.length) - 1])) * (4))) + (3)), 1, _SectorDataTransformed.length) - 1]), _0_topCounter, _0_topBCounter, ((((((_0_topCounter) * (_0_topzpft))) * (_0_tempx))) + (((_0_topCounter) * (((1) - (_0_tempx)))))), ((((((_0_topCounter) * (_0_topzpft))) * (_0_tempx))) + (((_0_topCounter) * (((1) - (_0_tempx)))))), ScratchVarGetDouble(_LevelTransform.data[iclamp(((_wall) + (5)), 1, _LevelTransform.length) - 1]));
		_AddRealDrawCall_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs(_0_xleft, _0_xright, ((((((_0_bottomSlope) * (_0_bottomzpft))) * (_0_tempx))) + (((_0_bottomSlope) * (((1) - (_0_tempx)))))), ((((((_0_bottomSlope) * (_0_bottomzpft))) * (_0_tempx))) + (((_0_bottomSlope) * (((1) - (_0_tempx)))))), _0_bottomSlope, _0_bottomBSlope, ScratchVarGetDouble(_SectorDataTransformed.data[iclamp(((((ScratchVarGetDouble(_LevelTransform.data[iclamp(((_wall) + (5)), 1, _LevelTransform.length) - 1])) * (4))) + (4)), 1, _SectorDataTransformed.length) - 1]), ScratchVarGetDouble(_LevelTransform.data[iclamp(((_wall) + (4)), 1, _LevelTransform.length) - 1]), ScratchVarGetDouble(_SectorDataTransformed.data[iclamp(((((ScratchVarGetDouble(_LevelTransform.data[iclamp(((_wall) + (5)), 1, _LevelTransform.length) - 1])) * (4))) + (3)), 1, _SectorDataTransformed.length) - 1]), ((((((_0_bottomCounter) * (_0_bottomzpft))) * (_0_tempx))) + (((_0_bottomCounter) * (((1) - (_0_tempx)))))), ((((((_0_bottomCounter) * (_0_bottomzpft))) * (_0_tempx))) + (((_0_bottomCounter) * (((1) - (_0_tempx)))))), _0_bottomCounter, _0_bottomBCounter, ScratchVarGetDouble(_LevelTransform.data[iclamp(((_wall) + (5)), 1, _LevelTransform.length) - 1]));
		_0_c = 0;
		for(int i2 = 0; i2 < (int)ScratchVarGetDouble(_SectorLengths.data[iclamp(((ScratchVarGetDouble(_LevelTransform.data[iclamp(((_wall) + (6)), 1, _LevelTransform.length) - 1])) + (1)), 1, _SectorLengths.length) - 1]); i2++)
		{
			_AddDrawCall_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs(((ScratchVarGetDouble(_SectorPointers.data[iclamp(((ScratchVarGetDouble(_LevelTransform.data[iclamp(((_wall) + (6)), 1, _LevelTransform.length) - 1])) + (1)), 1, _SectorPointers.length) - 1])) + (_0_c)), _0_xleft, _0_tempy, _0_tempy2, _0_xright, _0_tempy3, _0_tempy4, ((_depth) + (1)));
			_0_c += 7;
			YIELD
		}
	}
	else
	{
		_AddRealDrawCall_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs(_0_xleft, _0_xright, _0_topSlope, _0_topBSlope, _0_bottomSlope, _0_bottomBSlope, ScratchVarGetDouble(_SectorDataTransformed.data[iclamp(((((ScratchVarGetDouble(_LevelTransform.data[iclamp(((_wall) + (5)), 1, _LevelTransform.length) - 1])) * (4))) + (4)), 1, _SectorDataTransformed.length) - 1]), ScratchVarGetDouble(_LevelTransform.data[iclamp(((_wall) + (4)), 1, _LevelTransform.length) - 1]), ScratchVarGetDouble(_SectorDataTransformed.data[iclamp(((((ScratchVarGetDouble(_LevelTransform.data[iclamp(((_wall) + (5)), 1, _LevelTransform.length) - 1])) * (4))) + (3)), 1, _SectorDataTransformed.length) - 1]), _0_topCounter, _0_topBCounter, _0_bottomCounter, _0_bottomBCounter, ScratchVarGetDouble(_LevelTransform.data[iclamp(((_wall) + (5)), 1, _LevelTransform.length) - 1]));
	}
#define YIELD TRUE_YIELD
}

void _AddDrawCall_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs(double _wall, double _bx1, double _by1, double _by2, double _bx2, double _by3, double _by4, double _depth) 
{
	activeSprite = 1;
#define YIELD
	data_addtolist(ScratchSetDouble(_wall), _DrawCalls);
	data_addtolist(ScratchSetDouble(_bx1), _DrawCalls);
	data_addtolist(ScratchSetDouble(_by1), _DrawCalls);
	data_addtolist(ScratchSetDouble(_by2), _DrawCalls);
	data_addtolist(ScratchSetDouble(_bx2), _DrawCalls);
	data_addtolist(ScratchSetDouble(_by3), _DrawCalls);
	data_addtolist(ScratchSetDouble(_by4), _DrawCalls);
	data_addtolist(ScratchSetDouble(_depth), _DrawCalls);
#define YIELD TRUE_YIELD
}

void _Check_Sector() 
{
	activeSprite = 1;
#define YIELD
	_Get_Sector_zfcs_zfcs(_0_px, _0_py);
	if(!(_0_sectorOut == -1))
	{
		_0_Sector = _0_sectorOut;
	}
#define YIELD TRUE_YIELD
}

void _Frame() 
{
	activeSprite = 1;
#define YIELD
	pen_clear();
	_Input();
	_Check_Sector();
	_Transform_Level();
	_Prepare_Bounds();
	_Set_Sector_Pointers();
	_Prepare_Bounds();
	_Render();
	_FPS();
#define YIELD TRUE_YIELD
}

void _RotateWalls() 
{
	activeSprite = 1;
#define YIELD
	data_deletealloflist(_SectorCentres);
	data_deletealloflist(_LevelTransform);
	_0_c = 0;
	for(int i1 = 0; i1 < (int)((_LevelBase.length)); i1++)
	{
		_0_c++;
		data_addtolist(_LevelBase.data[iclamp(_0_c, 1, _LevelBase.length) - 1], _LevelTransform);
		YIELD
	}
	_Set_Sector_Pointers();
	data_deletealloflist(_DefSectorLengths);
	data_deletealloflist(_DefSectorPointers);
	_0_c = 0;
	for(int i1 = 0; i1 < (int)((_SectorPointers.length)); i1++)
	{
		_0_c++;
		data_addtolist(_SectorPointers.data[iclamp(_0_c, 1, _SectorPointers.length) - 1], _DefSectorPointers);
		YIELD
	}
	_0_c = 0;
	for(int i1 = 0; i1 < (int)((_SectorLengths.length)); i1++)
	{
		_0_c++;
		data_addtolist(_SectorLengths.data[iclamp(_0_c, 1, _SectorLengths.length) - 1], _DefSectorLengths);
		YIELD
	}
	_0_c = 0;
	for(int i1 = 0; i1 < (int)((_0_SectorCount)); i1++)
	{
		_0_tempx = 0;
		_0_tempy = 0;
		_0_c++;
		_0_c1 = ScratchVarGetDouble(_SectorPointers.data[iclamp(_0_c, 1, _SectorPointers.length) - 1]);
		for(int i2 = 0; i2 < (int)ScratchVarGetDouble(_SectorLengths.data[iclamp(_0_c, 1, _SectorLengths.length) - 1]); i2++)
		{
			_0_tempx += ScratchVarGetDouble(_LevelTransform.data[iclamp(_0_c1, 1, _LevelTransform.length) - 1]);
			_0_tempy += ScratchVarGetDouble(_LevelTransform.data[iclamp(((_0_c1) + (1)), 1, _LevelTransform.length) - 1]);
			_0_tempx += ScratchVarGetDouble(_LevelTransform.data[iclamp(((_0_c1) + (2)), 1, _LevelTransform.length) - 1]);
			_0_tempy += ScratchVarGetDouble(_LevelTransform.data[iclamp(((_0_c1) + (3)), 1, _LevelTransform.length) - 1]);
			_0_c1 += 7;
			YIELD
		}
		data_addtolist(ScratchSetDouble(((_0_tempx) / (double)(((ScratchVarGetDouble(_SectorLengths.data[iclamp(_0_c, 1, _SectorLengths.length) - 1])) * (2))))), _SectorCentres);
		data_addtolist(ScratchSetDouble(((_0_tempy) / (double)(((ScratchVarGetDouble(_SectorLengths.data[iclamp(_0_c, 1, _SectorLengths.length) - 1])) * (2))))), _SectorCentres);
		YIELD
	}
	_0_c = 1;
	for(int i1 = 0; i1 < (int)((((_LevelBase.length) / (double)(7)))); i1++)
	{
		if(0 > ((((((ScratchVarGetDouble(_SectorCentres.data[iclamp(((((ScratchVarGetDouble(_LevelBase.data[iclamp(((_0_c) + (5)), 1, _LevelBase.length) - 1])) * (2))) + (1)), 1, _SectorCentres.length) - 1])) - (ScratchVarGetDouble(_LevelBase.data[iclamp(_0_c, 1, _LevelBase.length) - 1])))) * (((ScratchVarGetDouble(_LevelBase.data[iclamp(((_0_c) + (1)), 1, _LevelBase.length) - 1])) - (ScratchVarGetDouble(_LevelBase.data[iclamp(((_0_c) + (3)), 1, _LevelBase.length) - 1])))))) + (((((ScratchVarGetDouble(_SectorCentres.data[iclamp(((((ScratchVarGetDouble(_LevelBase.data[iclamp(((_0_c) + (5)), 1, _LevelBase.length) - 1])) * (2))) + (2)), 1, _SectorCentres.length) - 1])) - (ScratchVarGetDouble(_LevelBase.data[iclamp(((_0_c) + (1)), 1, _LevelBase.length) - 1])))) * (((ScratchVarGetDouble(_LevelBase.data[iclamp(((_0_c) + (2)), 1, _LevelBase.length) - 1])) - (ScratchVarGetDouble(_LevelBase.data[iclamp(_0_c, 1, _LevelBase.length) - 1]))))))))
		{
			_0_tempx = ScratchVarGetDouble(_LevelBase.data[iclamp(_0_c, 1, _LevelBase.length) - 1]);
			_0_tempy = ScratchVarGetDouble(_LevelBase.data[iclamp(((_0_c) + (1)), 1, _LevelBase.length) - 1]);
			_LevelBase.data[iclamp(_0_c, 1, _LevelBase.length) - 1] = _LevelBase.data[iclamp(((_0_c) + (2)), 1, _LevelBase.length) - 1];
			_LevelBase.data[iclamp(((_0_c) + (1)), 1, _LevelBase.length) - 1] = _LevelBase.data[iclamp(((_0_c) + (3)), 1, _LevelBase.length) - 1];
			_LevelBase.data[iclamp(((_0_c) + (2)), 1, _LevelBase.length) - 1] = ScratchSetDouble(_0_tempx);
			_LevelBase.data[iclamp(((_0_c) + (3)), 1, _LevelBase.length) - 1] = ScratchSetDouble(_0_tempy);
		}
		_0_c += 7;
		YIELD
	}
#define YIELD TRUE_YIELD
}

void _DrawRealWall_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs(double _xleft, double _xright, double _topSlope, double _topBSlope, double _bottomSlope, double _bottomBSlope, double _ceilColour, double _wallColour, double _floorColour, double _topCounter, double _topBCounter, double _bottomCounter, double _bottomBCounter) 
{
	activeSprite = 1;
#define YIELD
	_0_bottomCounter = _bottomCounter;
	_0_bottomBCounter = _bottomBCounter;
	_0_topCounter = _topCounter;
	_0_topBCounter = _topBCounter;
	motion_setx(_xleft);
	for(int i1 = 0; i1 < (int)((((((_xright) - (_xleft))) / (double)(_0_resolution)))); i1++)
	{
		motion_sety(round((_0_topBCounter)));
		pen_setPenColorToColor(ScratchSetDouble(_ceilColour));
		pen_penDown();
		if(round((_0_bottomBCounter)) < round((_0_topCounter)))
		{
			motion_sety(round((_0_topCounter)));
			pen_setPenColorToColor(ScratchSetDouble(_wallColour));
		}
		if(round((_0_bottomBCounter)) < round((_0_bottomCounter)))
		{
			motion_sety(round((_0_bottomCounter)));
			pen_setPenColorToColor(ScratchSetDouble(_floorColour));
		}
		motion_sety(round((_0_bottomBCounter)));
		pen_penUp();
		_0_topCounter += _topSlope;
		_0_bottomCounter += _bottomSlope;
		_0_topBCounter += _topBSlope;
		_0_bottomBCounter += _bottomBSlope;
		motion_changexby(_0_resolution);
		YIELD
	}
#define YIELD TRUE_YIELD
}

void _AddRealDrawCall_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs(double _xleft, double _xright, double _topSlope, double _topBSlope, double _bottomSlope, double _bottomBSlope, double _ceilColour, double _wallColour, double _floorColour, double _topCounter, double _topBCounter, double _bottomCounter, double _bottomBCounter, double _sector) 
{
	activeSprite = 1;
#define YIELD
	data_addtolist(ScratchSetDouble(_sector), _RealDrawCalls);
	data_addtolist(ScratchSetDouble(_xleft), _RealDrawCalls);
	data_addtolist(ScratchSetDouble(_xright), _RealDrawCalls);
	data_addtolist(ScratchSetDouble(_topSlope), _RealDrawCalls);
	data_addtolist(ScratchSetDouble(_topBSlope), _RealDrawCalls);
	data_addtolist(ScratchSetDouble(_bottomSlope), _RealDrawCalls);
	data_addtolist(ScratchSetDouble(_bottomBSlope), _RealDrawCalls);
	data_addtolist(ScratchSetDouble(_ceilColour), _RealDrawCalls);
	data_addtolist(ScratchSetDouble(_wallColour), _RealDrawCalls);
	data_addtolist(ScratchSetDouble(_floorColour), _RealDrawCalls);
	data_addtolist(ScratchSetDouble(_topCounter), _RealDrawCalls);
	data_addtolist(ScratchSetDouble(_topBCounter), _RealDrawCalls);
	data_addtolist(ScratchSetDouble(_bottomCounter), _RealDrawCalls);
	data_addtolist(ScratchSetDouble(_bottomBCounter), _RealDrawCalls);
#define YIELD TRUE_YIELD
}

void _Add_Actor_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs(double _x, double _y, double _zkh, double _sizkhe, double _sprite, double _sector) 
{
	activeSprite = 1;
#define YIELD
	data_addtolist(ScratchSetDouble(_x), _Actors);
	data_addtolist(ScratchSetDouble(_y), _Actors);
	data_addtolist(ScratchSetDouble(_zkh), _Actors);
	data_addtolist(ScratchSetDouble(_sizkhe), _Actors);
	data_addtolist(ScratchSetDouble(_sprite), _Actors);
	data_addtolist(ScratchSetDouble(_sector), _Actors);
#define YIELD TRUE_YIELD
}

void _Draw_Sprites_zfcs(double _sector) 
{
	activeSprite = 1;
#define YIELD
	_0_c = 1;
	for(int i1 = 0; i1 < (int)((((_ActorsTransform.length) / (double)(6)))); i1++)
	{
		if((operator_equals(ScratchSetDouble(_sector), _ActorsTransform.data[iclamp(((_0_c) + (5)), 1, _ActorsTransform.length) - 1])) && (_0_NearPlane < ScratchVarGetDouble(_ActorsTransform.data[iclamp(((_0_c) + (1)), 1, _ActorsTransform.length) - 1])))
		{
			looks_setsizeto(INFINITY);
			motion_gotoxy(((((ScratchVarGetDouble(_ActorsTransform.data[iclamp(_0_c, 1, _ActorsTransform.length) - 1])) / (double)(ScratchVarGetDouble(_ActorsTransform.data[iclamp(((_0_c) + (1)), 1, _ActorsTransform.length) - 1])))) * (100)), ((((ScratchVarGetDouble(_ActorsTransform.data[iclamp(((_0_c) + (2)), 1, _ActorsTransform.length) - 1])) / (double)(ScratchVarGetDouble(_ActorsTransform.data[iclamp(((_0_c) + (1)), 1, _ActorsTransform.length) - 1])))) * (100)));
			looks_setsizeto(((((ScratchVarGetDouble(_ActorsTransform.data[iclamp(((_0_c) + (3)), 1, _ActorsTransform.length) - 1])) / (double)(ScratchVarGetDouble(_ActorsTransform.data[iclamp(((_0_c) + (1)), 1, _ActorsTransform.length) - 1])))) * (100)));
			pen_stamp();
			_0_c += 6;
		}
		YIELD
	}
#define YIELD TRUE_YIELD
}

void _Get_Sector_zfcs_zfcs(double _x, double _y) 
{
	activeSprite = 1;
#define YIELD
	_0_sectorOut = -1;
	_0_c6 = 0;
	for(int i1 = 0; i1 < (int)((_DefSectorLengths.length)); i1++)
	{
		_0_c6++;
		_0_c4 = ScratchVarGetDouble(_DefSectorPointers.data[iclamp(_0_c6, 1, _DefSectorPointers.length) - 1]);
		_0_c5 = 0;
		for(int i2 = 0; i2 < (int)ScratchVarGetDouble(_DefSectorLengths.data[iclamp(_0_c6, 1, _DefSectorLengths.length) - 1]); i2++)
		{
			_0_t = ((((_x) - (ScratchVarGetDouble(_LevelBase.data[iclamp(_0_c4, 1, _LevelBase.length) - 1])))) / (double)(((ScratchVarGetDouble(_LevelBase.data[iclamp(((_0_c4) + (2)), 1, _LevelBase.length) - 1])) - (ScratchVarGetDouble(_LevelBase.data[iclamp(_0_c4, 1, _LevelBase.length) - 1])))));
			if(((0 < _0_t) && (!(1 < _0_t))) && (_y < ((((ScratchVarGetDouble(_LevelBase.data[iclamp(((_0_c4) + (3)), 1, _LevelBase.length) - 1])) * (_0_t))) + (((ScratchVarGetDouble(_LevelBase.data[iclamp(((_0_c4) + (1)), 1, _LevelBase.length) - 1])) * (((1) - (_0_t))))))))
			{
				_0_c5++;
			}
			_0_c4 += 7;
			YIELD
		}
		if(fmod((_0_c5), (2)) == 1)
		{
			_0_sectorOut = ((_0_c6) - (1));
		}
		YIELD
	}
#define YIELD TRUE_YIELD
}

