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

double _0_sinzocx;
double _0_sinzocy;
double _0_sinzoczkh;
double _0_coszocx;
double _0_coszocy;
double _0_coszoczkh;
double _0_Matx;
double _0_Maty;
double _0_Matzkh;
double _0_c;
double _0_c1;
double _0_RasterX1;
double _0_RasterX2;
double _0_RasterX3;
double _0_RasterY1;
double _0_RasterY2;
double _0_RasterY3;
double _0_RasterX4;
double _0_RasterY4;
double _0_t;
double _0_dx1;
double _0_RasterXLeft;
double _0_RasterXRight;
double _0_RasterY;
double _0_dx2;
double _0_RXRound;
double _0_Rx2Round;
double _0_RasterU1;
double _0_RasterU2;
double _0_RasterV1;
double _0_RasterV2;
double _0_RasterU3;
double _0_RasterU4;
double _0_RasterV3;
double _0_RasterV4;
double _0_dvx1;
double _0_dux1;
double _0_RasterULeft;
double _0_RasterURight;
double _0_RasterVLeft;
double _0_RasterVRight;
double _0_dvx2;
double _0_dux2;
double _0_RU1;
double _0_RU2;
double _0_Rv1;
double _0_Rv2;
double _0_RasterLineUD;
double _0_RasterLineVd;
double _0_RasterLineUC;
double _0_RasterLineVC;
double _0_RasterZ1;
double _0_RasterZ2;
double _0_RasterZ3;
double _0_RasterZ4;
double _0_dzkh1;
double _0_dzkh2;
double _0_RasterZLeft;
double _0_RasterZRight;
double _0_Rzkh1;
double _0_Rzkh2;
double _0_RasterLineZC;
double _0_RasterLineZD;
double _0_Resolution;
double _0_TriDrawScaleFactour;
double _0_XRes;
double _0_YRes;
double _0_y_raster;

ScratchValue* vars[] = 
{	&_0_sinzocx,
	&_0_sinzocy,
	&_0_sinzoczkh,
	&_0_coszocx,
	&_0_coszocy,
	&_0_coszoczkh,
	&_0_Matx,
	&_0_Maty,
	&_0_Matzkh,
	&_0_c,
	&_0_c1,
	&_0_RasterX1,
	&_0_RasterX2,
	&_0_RasterX3,
	&_0_RasterY1,
	&_0_RasterY2,
	&_0_RasterY3,
	&_0_RasterX4,
	&_0_RasterY4,
	&_0_t,
	&_0_dx1,
	&_0_RasterXLeft,
	&_0_RasterXRight,
	&_0_RasterY,
	&_0_dx2,
	&_0_RXRound,
	&_0_Rx2Round,
	&_0_RasterU1,
	&_0_RasterU2,
	&_0_RasterV1,
	&_0_RasterV2,
	&_0_RasterU3,
	&_0_RasterU4,
	&_0_RasterV3,
	&_0_RasterV4,
	&_0_dvx1,
	&_0_dux1,
	&_0_RasterULeft,
	&_0_RasterURight,
	&_0_RasterVLeft,
	&_0_RasterVRight,
	&_0_dvx2,
	&_0_dux2,
	&_0_RU1,
	&_0_RU2,
	&_0_Rv1,
	&_0_Rv2,
	&_0_RasterLineUD,
	&_0_RasterLineVd,
	&_0_RasterLineUC,
	&_0_RasterLineVC,
	&_0_RasterZ1,
	&_0_RasterZ2,
	&_0_RasterZ3,
	&_0_RasterZ4,
	&_0_dzkh1,
	&_0_dzkh2,
	&_0_RasterZLeft,
	&_0_RasterZRight,
	&_0_Rzkh1,
	&_0_Rzkh2,
	&_0_RasterLineZC,
	&_0_RasterLineZD,
	&_0_Resolution,
	&_0_TriDrawScaleFactour,
	&_0_XRes,
	&_0_YRes,
	&_0_y_raster,
};

ScratchList _ModelX;
ScratchList _ModelY;
ScratchList _ModelZ;
ScratchList _Matrix;
ScratchList _ModelU;
ScratchList _ModelV;
ScratchList _ZBuffer;
ScratchList _ColourBuffer;

ScratchList* lists[] = 
{	&_ModelX,
	&_ModelY,
	&_ModelZ,
	&_Matrix,
	&_ModelU,
	&_ModelV,
	&_ZBuffer,
	&_ColourBuffer,
};

int vars_length = 68, lists_length = 8;

void _0_Init()
{
	_0_sinzocx = 0.000000;
	_0_sinzocy = -0.971632;
	_0_sinzoczkh = 0.000000;
	_0_coszocx = 1.000000;
	_0_coszocy = -0.236499;
	_0_coszoczkh = 1.000000;
	_0_Matx = -1.418994;
	_0_Maty = -5.000000;
	_0_Matzkh = 18.829790;
	_0_c = 172800.000000;
	_0_c1 = 3.000000;
	_0_RasterX1 = -4.521539;
	_0_RasterX2 = -24.980308;
	_0_RasterX3 = -30.203544;
	_0_RasterY1 = -15.932201;
	_0_RasterY2 = -17.230688;
	_0_RasterY3 = -25.904485;
	_0_RasterX4 = -7.865583;
	_0_RasterY4 = -17.230688;
	_0_t = 0.869790;
	_0_dx1 = 0.602186;
	_0_RasterXLeft = -24.783874;
	_0_RasterXRight = -7.025501;
	_0_RasterY = 0.000000;
	_0_dx2 = 2.575338;
	_0_RXRound = -25.000000;
	_0_Rx2Round = -10.000000;
	_0_RasterU1 = 0.000000;
	_0_RasterU2 = 1.000000;
	_0_RasterV1 = 1.000000;
	_0_RasterV2 = 1.000000;
	_0_RasterU3 = 1.000000;
	_0_RasterU4 = 0.130210;
	_0_RasterV3 = 0.000000;
	_0_RasterV4 = 0.869790;
	_0_dvx1 = 0.115290;
	_0_dux1 = 0.000000;
	_0_RasterULeft = 1.000000;
	_0_RasterURight = 0.097499;
	_0_RasterVLeft = 1.037608;
	_0_RasterVRight = 0.902501;
	_0_dvx2 = 0.100278;
	_0_dux2 = -0.100278;
	_0_RU1 = 1.000000;
	_0_RU2 = 0.197777;
	_0_Rv1 = 0.922318;
	_0_Rv2 = 0.802223;
	_0_RasterLineUD = -0.053482;
	_0_RasterLineVd = -0.008006;
	_0_RasterLineUC = 0.197777;
	_0_RasterLineVC = 0.802223;
	_0_RasterZ1 = 18.829790;
	_0_RasterZ2 = 17.410796;
	_0_RasterZ3 = 11.581006;
	_0_RasterZ4 = 17.885929;
	_0_dzkh1 = 0.672115;
	_0_dzkh2 = 0.726893;
	_0_RasterZLeft = 17.630042;
	_0_RasterZRight = 18.123043;
	_0_Rzkh1 = 16.957927;
	_0_Rzkh2 = 17.396150;
	_0_RasterLineZC = 17.396150;
	_0_RasterLineZD = 0.029215;
	_0_Resolution = 1.000000;
	_0_TriDrawScaleFactour = 60.000000;
	_0_XRes = 240.000000;
	_0_YRes = 180.000000;
	_0_y_raster = -16.904485;
	_ModelX = initialiseList();
	_ModelY = initialiseList();
	_ModelZ = initialiseList();
	_Matrix = initialiseList();
	_ModelU = initialiseList();
	_ModelV = initialiseList();
	_ZBuffer = initialiseList();
	_ColourBuffer = initialiseList();
}



void _1_Init()
{
}

void _1__fWevent_whenflagclicked();
void _Set_Model_Matrixzkd_Pos_zfcs_zfcs_zfcs_Scale_zfcs_zfcs_zfcs_Rotation_zfcs_zfcs_zfcs(ScratchValue _px, ScratchValue _py, ScratchValue _pzkh, ScratchValue _sx, ScratchValue _sy, ScratchValue _szkh, ScratchValue _rx, ScratchValue _ry, ScratchValue _rzkh);
void _Apply_Model_Matrix();
void _Draw_Triangles();
void _();
void _Rasterise_Triangle_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs(ScratchValue _x1, ScratchValue _y1, ScratchValue _x2, ScratchValue _y2, ScratchValue _x3, ScratchValue _y3, ScratchValue _u1, ScratchValue _u2, ScratchValue _u3, ScratchValue _v1, ScratchValue _v2, ScratchValue _v3, ScratchValue _zkh1, ScratchValue _zkh2, ScratchValue _zkh3);
void _Set_Colour_zfcs_zfcs(ScratchValue _u, ScratchValue _v);
void _SetColourByDistance_zfcs(ScratchValue _d);
void _SetZBuffer_zfcs_zfcs_zfcs(ScratchValue _x, ScratchValue _y, ScratchValue _zkh);
void _SetColBuffer_zfcs_zfcs_zfcs(ScratchValue _x, ScratchValue _y, ScratchValue _Col);
void _Clear_Buffers();
void _DrawRaster();

void _1__fWevent_whenflagclicked() 
{
	activeSprite = 1;
	while(1)
	{
		data_deletealloflist(_Matrix);
		data_deletealloflist(_ModelX);
		data_deletealloflist(_ModelY);
		data_deletealloflist(_ModelZ);
		data_deletealloflist(_ModelU);
		data_deletealloflist(_ModelV);
		_Set_Model_Matrixzkd_Pos_zfcs_zfcs_zfcs_Scale_zfcs_zfcs_zfcs_Rotation_zfcs_zfcs_zfcs(ScratchSetDouble(0), ScratchSetDouble(-5), ScratchSetDouble(13), ScratchSetDouble(6), ScratchSetDouble(6), ScratchSetDouble(6), ScratchSetDouble(0), ScratchSetDouble(((ScratchVarGetDouble(sensing_timer())) * (90))), ScratchSetDouble(0));
		data_addtolist(ScratchSetDouble(0), _ModelX);
		data_addtolist(ScratchSetDouble(0), _ModelY);
		data_addtolist(ScratchSetDouble(0), _ModelZ);
		data_addtolist(ScratchSetDouble(1), _ModelU);
		data_addtolist(ScratchSetDouble(1), _ModelV);
		data_addtolist(ScratchSetDouble(0), _ModelX);
		data_addtolist(ScratchSetDouble(0), _ModelY);
		data_addtolist(ScratchSetDouble(1), _ModelZ);
		data_addtolist(ScratchSetDouble(1), _ModelU);
		data_addtolist(ScratchSetDouble(0), _ModelV);
		data_addtolist(ScratchSetDouble(1), _ModelX);
		data_addtolist(ScratchSetDouble(0), _ModelY);
		data_addtolist(ScratchSetDouble(0), _ModelZ);
		data_addtolist(ScratchSetDouble(0), _ModelU);
		data_addtolist(ScratchSetDouble(1), _ModelV);
		_();
		data_addtolist(ScratchSetDouble(1), _ModelX);
		data_addtolist(ScratchSetDouble(0), _ModelY);
		data_addtolist(ScratchSetDouble(1), _ModelZ);
		data_addtolist(ScratchSetDouble(1), _ModelU);
		data_addtolist(ScratchSetDouble(1), _ModelV);
		data_addtolist(ScratchSetDouble(0), _ModelX);
		data_addtolist(ScratchSetDouble(0), _ModelY);
		data_addtolist(ScratchSetDouble(1), _ModelZ);
		data_addtolist(ScratchSetDouble(1), _ModelU);
		data_addtolist(ScratchSetDouble(0), _ModelV);
		data_addtolist(ScratchSetDouble(1), _ModelX);
		data_addtolist(ScratchSetDouble(0), _ModelY);
		data_addtolist(ScratchSetDouble(0), _ModelZ);
		data_addtolist(ScratchSetDouble(0), _ModelU);
		data_addtolist(ScratchSetDouble(1), _ModelV);
		_();
		_Apply_Model_Matrix();
		_0_YRes = ((180) / (double)(_0_Resolution));
		_0_XRes = ((240) / (double)(_0_Resolution));
		_Clear_Buffers();
		_Draw_Triangles();
		_DrawRaster();
		YIELD
	}
#define YIELD TRUE_YIELD
	END_THREAD
}

void _Set_Model_Matrixzkd_Pos_zfcs_zfcs_zfcs_Scale_zfcs_zfcs_zfcs_Rotation_zfcs_zfcs_zfcs(ScratchValue _px, ScratchValue _py, ScratchValue _pzkh, ScratchValue _sx, ScratchValue _sy, ScratchValue _szkh, ScratchValue _rx, ScratchValue _ry, ScratchValue _rzkh) 
{
	activeSprite = 1;
#define YIELD
	_0_sinzocx = sin((ScratchVarGetDouble(_rx)) * DEG_TO_RAD);
	_0_sinzocy = sin((ScratchVarGetDouble(_ry)) * DEG_TO_RAD);
	_0_sinzoczkh = sin((ScratchVarGetDouble(_rzkh)) * DEG_TO_RAD);
	_0_coszocx = cos((ScratchVarGetDouble(_rx)) * DEG_TO_RAD);
	_0_coszocy = cos((ScratchVarGetDouble(_ry)) * DEG_TO_RAD);
	_0_coszoczkh = cos((ScratchVarGetDouble(_rzkh)) * DEG_TO_RAD);
	data_deletealloflist(_Matrix);
	data_addtolist(ScratchSetDouble(((((_0_coszocy) * (_0_coszoczkh))) * (ScratchVarGetDouble(_sx)))), _Matrix);
	data_addtolist(ScratchSetDouble(((ScratchVarGetDouble(_sy)) * (((((((_0_sinzocx) * (_0_sinzocy))) * (_0_coszoczkh))) - (((_0_coszocx) * (_0_sinzoczkh))))))), _Matrix);
	data_addtolist(ScratchSetDouble(((ScratchVarGetDouble(_szkh)) * (((((((_0_coszocx) * (_0_sinzocy))) * (_0_coszoczkh))) + (((_0_sinzocx) * (_0_sinzoczkh))))))), _Matrix);
	data_addtolist(_px, _Matrix);
	data_addtolist(ScratchSetDouble(((((_0_coszocy) * (_0_sinzoczkh))) * (ScratchVarGetDouble(_sx)))), _Matrix);
	data_addtolist(ScratchSetDouble(((ScratchVarGetDouble(_sy)) * (((((((_0_sinzocx) * (_0_sinzocy))) * (_0_sinzoczkh))) + (((_0_coszocx) * (_0_coszoczkh))))))), _Matrix);
	data_addtolist(ScratchSetDouble(((ScratchVarGetDouble(_szkh)) * (((((((_0_coszocx) * (_0_sinzocy))) * (_0_sinzoczkh))) - (((_0_sinzocx) * (_0_coszoczkh))))))), _Matrix);
	data_addtolist(_py, _Matrix);
	data_addtolist(ScratchSetDouble(((((0) - (_0_sinzocy))) * (ScratchVarGetDouble(_sx)))), _Matrix);
	data_addtolist(ScratchSetDouble(((((_0_sinzocx) * (_0_coszocy))) * (ScratchVarGetDouble(_sy)))), _Matrix);
	data_addtolist(ScratchSetDouble(((((_0_coszocx) * (_0_coszocy))) * (ScratchVarGetDouble(_szkh)))), _Matrix);
	data_addtolist(_pzkh, _Matrix);
#define YIELD TRUE_YIELD
}

void _Apply_Model_Matrix() 
{
	activeSprite = 1;
#define YIELD
	_0_c = 1;
	for(int i1 = 0; i1 < (int)((_ModelX.length)); i1++)
	{
		_0_Matx = ((((ScratchVarGetDouble(data_itemoflist((int)4, _Matrix))) + (((ScratchVarGetDouble(data_itemoflist((int)1, _Matrix))) * (ScratchVarGetDouble(data_itemoflist((int)_0_c, _ModelX))))))) + (((((ScratchVarGetDouble(data_itemoflist((int)2, _Matrix))) * (ScratchVarGetDouble(data_itemoflist((int)_0_c, _ModelY))))) + (((ScratchVarGetDouble(data_itemoflist((int)3, _Matrix))) * (ScratchVarGetDouble(data_itemoflist((int)_0_c, _ModelZ))))))));
		_0_Maty = ((((ScratchVarGetDouble(data_itemoflist((int)8, _Matrix))) + (((ScratchVarGetDouble(data_itemoflist((int)5, _Matrix))) * (ScratchVarGetDouble(data_itemoflist((int)_0_c, _ModelX))))))) + (((((ScratchVarGetDouble(data_itemoflist((int)6, _Matrix))) * (ScratchVarGetDouble(data_itemoflist((int)_0_c, _ModelY))))) + (((ScratchVarGetDouble(data_itemoflist((int)7, _Matrix))) * (ScratchVarGetDouble(data_itemoflist((int)_0_c, _ModelZ))))))));
		_0_Matzkh = ((((ScratchVarGetDouble(data_itemoflist((int)12, _Matrix))) + (((ScratchVarGetDouble(data_itemoflist((int)9, _Matrix))) * (ScratchVarGetDouble(data_itemoflist((int)_0_c, _ModelX))))))) + (((((ScratchVarGetDouble(data_itemoflist((int)10, _Matrix))) * (ScratchVarGetDouble(data_itemoflist((int)_0_c, _ModelY))))) + (((ScratchVarGetDouble(data_itemoflist((int)11, _Matrix))) * (ScratchVarGetDouble(data_itemoflist((int)_0_c, _ModelZ))))))));
		_ModelX.data[(int)_0_c - 1] = ScratchSetDouble(_0_Matx);
		_ModelY.data[(int)_0_c - 1] = ScratchSetDouble(_0_Maty);
		_ModelZ.data[(int)_0_c - 1] = ScratchSetDouble(_0_Matzkh);
		_0_c++;
		YIELD
	}
#define YIELD TRUE_YIELD
}

void _Draw_Triangles() 
{
	activeSprite = 1;
#define YIELD
	_0_TriDrawScaleFactour = ((60) / (double)(_0_Resolution));
	_0_c = 1;
	for(int i1 = 0; i1 < (int)((((_ModelX.length) / (double)(3)))); i1++)
	{
		_Rasterise_Triangle_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs(ScratchSetDouble(((((ScratchVarGetDouble(data_itemoflist((int)((_0_c) + (0)), _ModelX))) / (double)(ScratchVarGetDouble(data_itemoflist((int)((_0_c) + (0)), _ModelZ))))) * (_0_TriDrawScaleFactour))), ScratchSetDouble(((((ScratchVarGetDouble(data_itemoflist((int)((_0_c) + (0)), _ModelY))) / (double)(ScratchVarGetDouble(data_itemoflist((int)((_0_c) + (0)), _ModelZ))))) * (_0_TriDrawScaleFactour))), ScratchSetDouble(((((ScratchVarGetDouble(data_itemoflist((int)((_0_c) + (1)), _ModelX))) / (double)(ScratchVarGetDouble(data_itemoflist((int)((_0_c) + (1)), _ModelZ))))) * (_0_TriDrawScaleFactour))), ScratchSetDouble(((((ScratchVarGetDouble(data_itemoflist((int)((_0_c) + (1)), _ModelY))) / (double)(ScratchVarGetDouble(data_itemoflist((int)((_0_c) + (1)), _ModelZ))))) * (_0_TriDrawScaleFactour))), ScratchSetDouble(((((ScratchVarGetDouble(data_itemoflist((int)((_0_c) + (2)), _ModelX))) / (double)(ScratchVarGetDouble(data_itemoflist((int)((_0_c) + (2)), _ModelZ))))) * (_0_TriDrawScaleFactour))), ScratchSetDouble(((((ScratchVarGetDouble(data_itemoflist((int)((_0_c) + (2)), _ModelY))) / (double)(ScratchVarGetDouble(data_itemoflist((int)((_0_c) + (2)), _ModelZ))))) * (_0_TriDrawScaleFactour))), data_itemoflist((int)((_0_c) + (0)), _ModelU), data_itemoflist((int)((_0_c) + (1)), _ModelU), data_itemoflist((int)((_0_c) + (2)), _ModelU), data_itemoflist((int)((_0_c) + (0)), _ModelV), data_itemoflist((int)((_0_c) + (1)), _ModelV), data_itemoflist((int)((_0_c) + (2)), _ModelV), data_itemoflist((int)((_0_c) + (0)), _ModelZ), data_itemoflist((int)((_0_c) + (1)), _ModelZ), data_itemoflist((int)((_0_c) + (2)), _ModelZ));
		_0_c += 3;
		YIELD
	}
#define YIELD TRUE_YIELD
}

void _() 
{
	activeSprite = 1;
#define YIELD FUNCTION_YIELD
#define YIELD TRUE_YIELD
}

void _Rasterise_Triangle_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs(ScratchValue _x1, ScratchValue _y1, ScratchValue _x2, ScratchValue _y2, ScratchValue _x3, ScratchValue _y3, ScratchValue _u1, ScratchValue _u2, ScratchValue _u3, ScratchValue _v1, ScratchValue _v2, ScratchValue _v3, ScratchValue _zkh1, ScratchValue _zkh2, ScratchValue _zkh3) 
{
	activeSprite = 1;
#define YIELD
	if((ScratchVarGetDouble(_y3) < ScratchVarGetDouble(_y1)) && (ScratchVarGetDouble(_y2) < ScratchVarGetDouble(_y1)))
	{
		_0_c1 = 1;
		_0_RasterY1 = ScratchVarGetDouble(_y1);
		_0_RasterX1 = ScratchVarGetDouble(_x1);
		_0_RasterU1 = ScratchVarGetDouble(_u1);
		_0_RasterV1 = ScratchVarGetDouble(_v1);
		_0_RasterZ1 = ScratchVarGetDouble(_zkh1);
		if(ScratchVarGetDouble(_y3) < ScratchVarGetDouble(_y2))
		{
			_0_RasterY2 = ScratchVarGetDouble(_y2);
			_0_RasterX2 = ScratchVarGetDouble(_x2);
			_0_RasterU2 = ScratchVarGetDouble(_u2);
			_0_RasterV2 = ScratchVarGetDouble(_v2);
			_0_RasterZ2 = ScratchVarGetDouble(_zkh2);
			_();
			_0_RasterY3 = ScratchVarGetDouble(_y3);
			_0_RasterX3 = ScratchVarGetDouble(_x3);
			_0_RasterU3 = ScratchVarGetDouble(_u3);
			_0_RasterV3 = ScratchVarGetDouble(_v3);
			_0_RasterZ3 = ScratchVarGetDouble(_zkh3);
		}
		else
		{
			_0_RasterY3 = ScratchVarGetDouble(_y2);
			_0_RasterX3 = ScratchVarGetDouble(_x2);
			_0_RasterU3 = ScratchVarGetDouble(_u2);
			_0_RasterV3 = ScratchVarGetDouble(_v2);
			_0_RasterZ3 = ScratchVarGetDouble(_zkh2);
			_();
			_0_RasterY2 = ScratchVarGetDouble(_y3);
			_0_RasterX2 = ScratchVarGetDouble(_x3);
			_0_RasterU2 = ScratchVarGetDouble(_u3);
			_0_RasterV2 = ScratchVarGetDouble(_v3);
			_0_RasterZ2 = ScratchVarGetDouble(_zkh3);
		}
	}
	if((ScratchVarGetDouble(_y3) < ScratchVarGetDouble(_y2)) && (ScratchVarGetDouble(_y1) < ScratchVarGetDouble(_y2)))
	{
		_0_c1 = 2;
		_0_RasterY1 = ScratchVarGetDouble(_y2);
		_0_RasterX1 = ScratchVarGetDouble(_x2);
		_0_RasterU1 = ScratchVarGetDouble(_u2);
		_0_RasterV1 = ScratchVarGetDouble(_v2);
		_0_RasterZ1 = ScratchVarGetDouble(_zkh2);
		if(ScratchVarGetDouble(_y3) < ScratchVarGetDouble(_y1))
		{
			_0_RasterY2 = ScratchVarGetDouble(_y1);
			_0_RasterX2 = ScratchVarGetDouble(_x1);
			_0_RasterU2 = ScratchVarGetDouble(_u1);
			_0_RasterV2 = ScratchVarGetDouble(_v1);
			_0_RasterZ2 = ScratchVarGetDouble(_zkh1);
			_();
			_0_RasterY3 = ScratchVarGetDouble(_y3);
			_0_RasterX3 = ScratchVarGetDouble(_x3);
			_0_RasterU3 = ScratchVarGetDouble(_u3);
			_0_RasterV3 = ScratchVarGetDouble(_v3);
			_0_RasterZ3 = ScratchVarGetDouble(_zkh3);
		}
		else
		{
			_0_RasterY3 = ScratchVarGetDouble(_y1);
			_0_RasterX3 = ScratchVarGetDouble(_x1);
			_0_RasterU3 = ScratchVarGetDouble(_u1);
			_0_RasterV3 = ScratchVarGetDouble(_v1);
			_0_RasterZ3 = ScratchVarGetDouble(_zkh1);
			_();
			_0_RasterY2 = ScratchVarGetDouble(_y3);
			_0_RasterX2 = ScratchVarGetDouble(_x3);
			_0_RasterU2 = ScratchVarGetDouble(_u3);
			_0_RasterV2 = ScratchVarGetDouble(_v3);
			_0_RasterZ2 = ScratchVarGetDouble(_zkh3);
		}
	}
	if((ScratchVarGetDouble(_y2) < ScratchVarGetDouble(_y3)) && (ScratchVarGetDouble(_y1) < ScratchVarGetDouble(_y3)))
	{
		_0_c1 = 3;
		_0_RasterY1 = ScratchVarGetDouble(_y3);
		_0_RasterX1 = ScratchVarGetDouble(_x3);
		_0_RasterU1 = ScratchVarGetDouble(_u3);
		_0_RasterV1 = ScratchVarGetDouble(_v3);
		_0_RasterZ1 = ScratchVarGetDouble(_zkh3);
		if(ScratchVarGetDouble(_y2) < ScratchVarGetDouble(_y1))
		{
			_0_RasterY2 = ScratchVarGetDouble(_y1);
			_0_RasterX2 = ScratchVarGetDouble(_x1);
			_0_RasterU2 = ScratchVarGetDouble(_u1);
			_0_RasterV2 = ScratchVarGetDouble(_v1);
			_0_RasterZ2 = ScratchVarGetDouble(_zkh1);
			_();
			_0_RasterY3 = ScratchVarGetDouble(_y2);
			_0_RasterX3 = ScratchVarGetDouble(_x2);
			_0_RasterU3 = ScratchVarGetDouble(_u2);
			_0_RasterV3 = ScratchVarGetDouble(_v2);
			_0_RasterZ3 = ScratchVarGetDouble(_zkh2);
		}
		else
		{
			_0_RasterY3 = ScratchVarGetDouble(_y1);
			_0_RasterX3 = ScratchVarGetDouble(_x1);
			_0_RasterU3 = ScratchVarGetDouble(_u1);
			_0_RasterV3 = ScratchVarGetDouble(_v1);
			_0_RasterZ3 = ScratchVarGetDouble(_zkh1);
			_();
			_0_RasterY2 = ScratchVarGetDouble(_y2);
			_0_RasterX2 = ScratchVarGetDouble(_x2);
			_0_RasterU2 = ScratchVarGetDouble(_u2);
			_0_RasterV2 = ScratchVarGetDouble(_v2);
			_0_RasterZ2 = ScratchVarGetDouble(_zkh2);
		}
	}
	_0_t = ((((_0_RasterY2) - (_0_RasterY3))) / (double)(((_0_RasterY1) - (_0_RasterY3))));
	_0_RasterX4 = ((((_0_t) * (((_0_RasterX1) - (_0_RasterX3))))) + (_0_RasterX3));
	_0_RasterY4 = _0_RasterY2;
	_0_RasterU4 = ((((_0_t) * (((_0_RasterU1) - (_0_RasterU3))))) + (_0_RasterU3));
	_0_RasterV4 = ((((_0_t) * (((_0_RasterV1) - (_0_RasterV3))))) + (_0_RasterV3));
	_0_RasterZ4 = ((((_0_t) * (((_0_RasterZ1) - (_0_RasterZ3))))) + (_0_RasterZ3));
	_();
	if(!(_0_RasterY2 == _0_RasterY1))
	{
		_0_dx1 = ((0.0) - (((((_0_RasterX2) - (_0_RasterX1))) / (double)(((_0_RasterY2) - (_0_RasterY1))))));
		_0_dx2 = ((0.0) - (((((_0_RasterX4) - (_0_RasterX1))) / (double)(((_0_RasterY4) - (_0_RasterY1))))));
		_0_dvx1 = ((0.0) - (((((_0_RasterV2) - (_0_RasterV1))) / (double)(((_0_RasterY2) - (_0_RasterY1))))));
		_0_dux1 = ((0.0) - (((((_0_RasterU2) - (_0_RasterU1))) / (double)(((_0_RasterY2) - (_0_RasterY1))))));
		_0_dvx2 = ((0.0) - (((((_0_RasterV4) - (_0_RasterV1))) / (double)(((_0_RasterY2) - (_0_RasterY1))))));
		_0_dux2 = ((0.0) - (((((_0_RasterU4) - (_0_RasterU1))) / (double)(((_0_RasterY2) - (_0_RasterY1))))));
		_0_dzkh1 = ((0.0) - (((((_0_RasterZ2) - (_0_RasterZ1))) / (double)(((_0_RasterY2) - (_0_RasterY1))))));
		_0_dzkh2 = ((0.0) - (((((_0_RasterZ4) - (_0_RasterZ1))) / (double)(((_0_RasterY2) - (_0_RasterY1))))));
		_0_RasterXLeft = _0_RasterX1;
		_0_RasterXRight = _0_RasterX1;
		_0_RasterULeft = _0_RasterU1;
		_0_RasterURight = _0_RasterU1;
		_0_RasterVLeft = _0_RasterV1;
		_0_RasterVRight = _0_RasterV1;
		_0_RasterZLeft = _0_RasterZ1;
		_0_RasterZRight = _0_RasterZ1;
		_0_y_raster = _0_RasterY1;
		for(int i2 = 0; i2 < (int)((((1) + (((_0_RasterY1) - (_0_RasterY4)))))); i2++)
		{
			_0_RXRound = round((_0_RasterXRight));
			_0_Rx2Round = round((_0_RasterXLeft));
			_0_RU1 = _0_RasterURight;
			_0_RU2 = _0_RasterULeft;
			_0_Rv1 = _0_RasterVRight;
			_0_Rv2 = _0_RasterVLeft;
			_0_Rzkh1 = _0_RasterZRight;
			_0_Rzkh2 = _0_RasterZLeft;
			if(_0_Rx2Round < _0_RXRound)
			{
				_0_RXRound = round((_0_RasterXLeft));
				_0_Rx2Round = round((_0_RasterXRight));
				_0_RU1 = _0_RasterULeft;
				_0_RU2 = _0_RasterURight;
				_0_Rv1 = _0_RasterVLeft;
				_0_Rv2 = _0_RasterVRight;
				_0_Rzkh1 = _0_RasterZLeft;
				_0_Rzkh2 = _0_RasterZRight;
			}
			_0_RasterLineUC = _0_RU1;
			_0_RasterLineUD = ((((_0_RU2) - (_0_RU1))) / (double)(((_0_Rx2Round) - (_0_RXRound))));
			_0_RasterLineVC = _0_Rv1;
			_0_RasterLineVd = ((((_0_Rv2) - (_0_Rv1))) / (double)(((_0_Rx2Round) - (_0_RXRound))));
			_0_RasterLineZC = _0_Rzkh1;
			_0_RasterLineZD = ((((_0_Rzkh2) - (_0_Rzkh1))) / (double)(((_0_Rx2Round) - (_0_RXRound))));
			motion_gotoxy(round((_0_RXRound)), round((_0_y_raster)));
			for(int i3 = 0; i3 < (int)((((_0_Rx2Round) - (_0_RXRound)))); i3++)
			{
				_Set_Colour_zfcs_zfcs(ScratchSetDouble(_0_RasterLineUC), ScratchSetDouble(_0_RasterLineVC));
				motion_changexby(1);
				_0_RasterLineUC += _0_RasterLineUD;
				_0_RasterLineVC += _0_RasterLineVd;
				_0_RasterLineZC += _0_RasterLineZD;
				if(1 < _0_RasterLineUC)
				{
					_0_RasterLineUC = 1;
				}
				if(1 < _0_RasterLineVC)
				{
					_0_RasterLineVC = 1;
				}
				YIELD
			}
			_0_y_raster += -1;
			_0_RasterXLeft += _0_dx1;
			_0_RasterXRight += _0_dx2;
			_0_RasterVLeft += _0_dvx1;
			_0_RasterULeft += _0_dux1;
			_0_RasterVRight += _0_dvx2;
			_0_RasterURight += _0_dux2;
			_0_RasterZLeft += _0_dzkh1;
			_0_RasterZRight += _0_dzkh2;
			YIELD
		}
	}
	_();
	if(!(_0_RasterY2 == _0_RasterY3))
	{
		_0_dx1 = ((((_0_RasterX2) - (_0_RasterX3))) / (double)(((_0_RasterY2) - (_0_RasterY3))));
		_0_dx2 = ((((_0_RasterX4) - (_0_RasterX3))) / (double)(((_0_RasterY4) - (_0_RasterY3))));
		_0_dvx1 = ((((_0_RasterV2) - (_0_RasterV3))) / (double)(((_0_RasterY2) - (_0_RasterY3))));
		_0_dux1 = ((((_0_RasterU2) - (_0_RasterU3))) / (double)(((_0_RasterY2) - (_0_RasterY3))));
		_0_dvx2 = ((((_0_RasterV4) - (_0_RasterV3))) / (double)(((_0_RasterY4) - (_0_RasterY3))));
		_0_dux2 = ((((_0_RasterU4) - (_0_RasterU3))) / (double)(((_0_RasterY4) - (_0_RasterY3))));
		_0_dzkh1 = ((((_0_RasterZ2) - (_0_RasterZ3))) / (double)(((_0_RasterY2) - (_0_RasterY3))));
		_0_dzkh2 = ((((_0_RasterZ4) - (_0_RasterZ3))) / (double)(((_0_RasterY4) - (_0_RasterY3))));
		_0_RasterXLeft = _0_RasterX3;
		_0_RasterXRight = _0_RasterX3;
		_0_RasterULeft = _0_RasterU3;
		_0_RasterURight = _0_RasterU3;
		_0_RasterVLeft = _0_RasterV3;
		_0_RasterVRight = _0_RasterV3;
		_0_RasterZLeft = _0_RasterZ3;
		_0_RasterZRight = _0_RasterZ3;
		_0_y_raster = _0_RasterY3;
		for(int i2 = 0; i2 < (int)((((0) + (ceil((((_0_RasterY4) - (_0_RasterY3)))))))); i2++)
		{
			_0_RXRound = round((_0_RasterXRight));
			_0_Rx2Round = round((_0_RasterXLeft));
			_0_RU1 = _0_RasterURight;
			_0_RU2 = _0_RasterULeft;
			_0_Rv1 = _0_RasterVRight;
			_0_Rv2 = _0_RasterVLeft;
			_0_Rzkh1 = _0_RasterZRight;
			_0_Rzkh2 = _0_RasterZLeft;
			if(_0_Rx2Round < _0_RXRound)
			{
				_0_RXRound = round((_0_RasterXLeft));
				_0_Rx2Round = round((_0_RasterXRight));
				_0_RU1 = _0_RasterULeft;
				_0_RU2 = _0_RasterURight;
				_0_Rv1 = _0_RasterVLeft;
				_0_Rv2 = _0_RasterVRight;
				_0_Rzkh1 = _0_RasterZLeft;
				_0_Rzkh2 = _0_RasterZRight;
			}
			_0_RasterLineUC = _0_RU1;
			_0_RasterLineUD = ((((_0_RU2) - (_0_RU1))) / (double)(((_0_Rx2Round) - (_0_RXRound))));
			_0_RasterLineVC = _0_Rv1;
			_0_RasterLineVd = ((((_0_Rv2) - (_0_Rv1))) / (double)(((_0_Rx2Round) - (_0_RXRound))));
			_0_RasterLineZC = _0_Rzkh1;
			_0_RasterLineZD = ((((_0_Rzkh2) - (_0_Rzkh1))) / (double)(((_0_Rx2Round) - (_0_RXRound))));
			motion_gotoxy(_0_RXRound, round((_0_y_raster)));
			_Set_Colour_zfcs_zfcs(ScratchSetDouble(_0_RasterLineUC), ScratchSetDouble(_0_RasterLineVC));
			for(int i3 = 0; i3 < (int)((((_0_Rx2Round) - (_0_RXRound)))); i3++)
			{
				_Set_Colour_zfcs_zfcs(ScratchSetDouble(_0_RasterLineUC), ScratchSetDouble(_0_RasterLineVC));
				motion_changexby(1);
				_0_RasterLineUC += _0_RasterLineUD;
				_0_RasterLineVC += _0_RasterLineVd;
				_0_RasterLineZC += _0_RasterLineZD;
				if(1 < _0_RasterLineUC)
				{
					_0_RasterLineUC = 1;
				}
				if(1 < _0_RasterLineVC)
				{
					_0_RasterLineVC = 1;
				}
				YIELD
			}
			_0_RasterXLeft += _0_dx1;
			_0_RasterXRight += _0_dx2;
			_0_RasterVLeft += _0_dvx1;
			_0_RasterULeft += _0_dux1;
			_0_RasterVRight += _0_dvx2;
			_0_RasterURight += _0_dux2;
			_0_RasterZLeft += _0_dzkh1;
			_0_RasterZRight += _0_dzkh2;
			_0_y_raster++;
			YIELD
		}
	}
#define YIELD TRUE_YIELD
}

void _Set_Colour_zfcs_zfcs(ScratchValue _u, ScratchValue _v) 
{
	activeSprite = 1;
#define YIELD
	_SetColBuffer_zfcs_zfcs_zfcs(ScratchSetDouble(motion_xposition()), ScratchSetDouble(motion_yposition()), ScratchSetDouble(((((((round((((ScratchVarGetDouble(_u)) * (255))))) * (256))) * (256))) + (((round((((ScratchVarGetDouble(_v)) * (255))))) * (256))))));
#define YIELD TRUE_YIELD
}

void _SetColourByDistance_zfcs(ScratchValue _d) 
{
	activeSprite = 1;
#define YIELD
	pen_setPenColorToColor(ScratchSetDouble(((((ScratchVarGetDouble(operator_mod(ScratchSetDouble(round((((((4) / (double)(ScratchVarGetDouble(_d)))) * (255))))), ScratchSetDouble(256.0)))) * (((256) * (256))))) + (((((ScratchVarGetDouble(operator_mod(ScratchSetDouble(round((((((4) / (double)(ScratchVarGetDouble(_d)))) * (255))))), ScratchSetDouble(256.0)))) * (256))) + (ScratchVarGetDouble(operator_mod(ScratchSetDouble(round((((((4) / (double)(ScratchVarGetDouble(_d)))) * (255))))), ScratchSetDouble(256.0)))))))));
#define YIELD TRUE_YIELD
}

void _SetZBuffer_zfcs_zfcs_zfcs(ScratchValue _x, ScratchValue _y, ScratchValue _zkh) 
{
	activeSprite = 1;
#define YIELD
	_ColourBuffer.data[(int)((((((ScratchVarGetDouble(_x)) + (_0_XRes))) * (((_0_YRes) + (_0_YRes))))) + (((ScratchVarGetDouble(_y)) + (_0_YRes)))) - 1] = _zkh;
#define YIELD TRUE_YIELD
}

void _SetColBuffer_zfcs_zfcs_zfcs(ScratchValue _x, ScratchValue _y, ScratchValue _Col) 
{
	activeSprite = 1;
#define YIELD
	_ColourBuffer.data[(int)((((((ScratchVarGetDouble(_x)) + (_0_XRes))) * (((_0_YRes) + (_0_YRes))))) + (((ScratchVarGetDouble(_y)) + (_0_YRes)))) - 1] = _Col;
#define YIELD TRUE_YIELD
}

void _Clear_Buffers() 
{
	activeSprite = 1;
#define YIELD
	data_deletealloflist(_ZBuffer);
	data_deletealloflist(_ColourBuffer);
	for(int i1 = 0; i1 < (int)((((_0_XRes) + (_0_XRes)))); i1++)
	{
		for(int i2 = 0; i2 < (int)((((_0_YRes) + (_0_YRes)))); i2++)
		{
			data_addtolist(ScratchSetDouble(0), _ColourBuffer);
			data_addtolist(ScratchSetDouble(INFINITY), _ZBuffer);
			YIELD
		}
		YIELD
	}
#define YIELD TRUE_YIELD
}

void _DrawRaster() 
{
	activeSprite = 1;
#define YIELD
	pen_clear();
	pen_setPenColorToColor(ScratchSetString("#000000"));
	pen_setPenSizeTo(ScratchSetDouble(1000.0));
	pen_penDown();
	pen_penUp();
	if(_0_Resolution == 1)
	{
		pen_setPenSizeTo(ScratchSetDouble(1.0));
	}
	else
	{
		pen_setPenSizeTo(ScratchSetDouble(((_0_Resolution) * (1.5))));
		motion_changexby(_0_Resolution);
		motion_changeyby(_0_Resolution);
	}
	_0_c = 0;
	motion_gotoxy(-240, -180);
	for(int i1 = 0; i1 < (int)((((_0_XRes) + (_0_XRes)))); i1++)
	{
		motion_sety(-180);
		for(int i2 = 0; i2 < (int)((((_0_YRes) + (_0_YRes)))); i2++)
		{
			_0_c++;
			pen_setPenColorToColor(data_itemoflist((int)_0_c, _ColourBuffer));
			pen_penDown();
			pen_penUp();
			motion_changeyby(_0_Resolution);
			YIELD
		}
		motion_changexby(_0_Resolution);
		YIELD
	}
#define YIELD TRUE_YIELD
}

