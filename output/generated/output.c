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

ScratchValue _0_sinzocx;
ScratchValue _0_sinzocy;
ScratchValue _0_sinzoczkh;
ScratchValue _0_coszocx;
ScratchValue _0_coszocy;
ScratchValue _0_coszoczkh;
ScratchValue _0_Matx;
ScratchValue _0_Maty;
ScratchValue _0_Matzkh;
ScratchValue _0_c;
ScratchValue _0_c1;
ScratchValue _0_RasterX1;
ScratchValue _0_RasterX2;
ScratchValue _0_RasterX3;
ScratchValue _0_RasterY1;
ScratchValue _0_RasterY2;
ScratchValue _0_RasterY3;
ScratchValue _0_RasterX4;
ScratchValue _0_RasterY4;
ScratchValue _0_t;
ScratchValue _0_dx1;
ScratchValue _0_RasterXLeft;
ScratchValue _0_RasterXRight;
ScratchValue _0_RasterY;
ScratchValue _0_dx2;
ScratchValue _0_RXRound;
ScratchValue _0_Rx2Round;
ScratchValue _0_RasterU1;
ScratchValue _0_RasterU2;
ScratchValue _0_RasterV1;
ScratchValue _0_RasterV2;
ScratchValue _0_RasterU3;
ScratchValue _0_RasterU4;
ScratchValue _0_RasterV3;
ScratchValue _0_RasterV4;
ScratchValue _0_dvx1;
ScratchValue _0_dux1;
ScratchValue _0_RasterULeft;
ScratchValue _0_RasterURight;
ScratchValue _0_RasterVLeft;
ScratchValue _0_RasterVRight;
ScratchValue _0_dvx2;
ScratchValue _0_dux2;
ScratchValue _0_RU1;
ScratchValue _0_RU2;
ScratchValue _0_Rv1;
ScratchValue _0_Rv2;
ScratchValue _0_RasterLineUD;
ScratchValue _0_RasterLineVd;
ScratchValue _0_RasterLineUC;
ScratchValue _0_RasterLineVC;
ScratchValue _0_RasterZ1;
ScratchValue _0_RasterZ2;
ScratchValue _0_RasterZ3;
ScratchValue _0_RasterZ4;
ScratchValue _0_dzkh1;
ScratchValue _0_dzkh2;
ScratchValue _0_RasterZLeft;
ScratchValue _0_RasterZRight;
ScratchValue _0_Rzkh1;
ScratchValue _0_Rzkh2;
ScratchValue _0_RasterLineZC;
ScratchValue _0_RasterLineZD;
ScratchValue _0_Resolution;
ScratchValue _0_TriDrawScaleFactour;
ScratchValue _0_XRes;
ScratchValue _0_YRes;
ScratchValue _0_y_raster;

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
	_0_sinzocx = ScratchSetDouble(0);
	_0_sinzocy = ScratchSetDouble(-0.971632);
	_0_sinzoczkh = ScratchSetDouble(0);
	_0_coszocx = ScratchSetDouble(1);
	_0_coszocy = ScratchSetDouble(-0.236499);
	_0_coszoczkh = ScratchSetDouble(1);
	_0_Matx = ScratchSetDouble(-1.418994);
	_0_Maty = ScratchSetDouble(-5);
	_0_Matzkh = ScratchSetDouble(18.829790);
	_0_c = ScratchSetDouble(172800);
	_0_c1 = ScratchSetDouble(3);
	_0_RasterX1 = ScratchSetDouble(-4.521539);
	_0_RasterX2 = ScratchSetDouble(-24.980308);
	_0_RasterX3 = ScratchSetDouble(-30.203544);
	_0_RasterY1 = ScratchSetDouble(-15.932201);
	_0_RasterY2 = ScratchSetDouble(-17.230688);
	_0_RasterY3 = ScratchSetDouble(-25.904485);
	_0_RasterX4 = ScratchSetDouble(-7.865583);
	_0_RasterY4 = ScratchSetDouble(-17.230688);
	_0_t = ScratchSetDouble(0.869790);
	_0_dx1 = ScratchSetDouble(0.602186);
	_0_RasterXLeft = ScratchSetDouble(-24.783874);
	_0_RasterXRight = ScratchSetDouble(-7.025501);
	_0_RasterY = ScratchSetDouble(0);
	_0_dx2 = ScratchSetDouble(2.575338);
	_0_RXRound = ScratchSetDouble(-25);
	_0_Rx2Round = ScratchSetDouble(-10);
	_0_RasterU1 = ScratchSetDouble(0);
	_0_RasterU2 = ScratchSetDouble(1);
	_0_RasterV1 = ScratchSetDouble(1);
	_0_RasterV2 = ScratchSetDouble(1);
	_0_RasterU3 = ScratchSetDouble(1);
	_0_RasterU4 = ScratchSetDouble(0.130210);
	_0_RasterV3 = ScratchSetDouble(0);
	_0_RasterV4 = ScratchSetDouble(0.869790);
	_0_dvx1 = ScratchSetDouble(0.115290);
	_0_dux1 = ScratchSetDouble(0);
	_0_RasterULeft = ScratchSetDouble(1);
	_0_RasterURight = ScratchSetDouble(0.097499);
	_0_RasterVLeft = ScratchSetDouble(1.037608);
	_0_RasterVRight = ScratchSetDouble(0.902501);
	_0_dvx2 = ScratchSetDouble(0.100278);
	_0_dux2 = ScratchSetDouble(-0.100278);
	_0_RU1 = ScratchSetDouble(1);
	_0_RU2 = ScratchSetDouble(0.197777);
	_0_Rv1 = ScratchSetDouble(0.922318);
	_0_Rv2 = ScratchSetDouble(0.802223);
	_0_RasterLineUD = ScratchSetDouble(-0.053482);
	_0_RasterLineVd = ScratchSetDouble(-0.008006);
	_0_RasterLineUC = ScratchSetDouble(0.197777);
	_0_RasterLineVC = ScratchSetDouble(0.802223);
	_0_RasterZ1 = ScratchSetDouble(18.829790);
	_0_RasterZ2 = ScratchSetDouble(17.410796);
	_0_RasterZ3 = ScratchSetDouble(11.581006);
	_0_RasterZ4 = ScratchSetDouble(17.885929);
	_0_dzkh1 = ScratchSetDouble(0.672115);
	_0_dzkh2 = ScratchSetDouble(0.726893);
	_0_RasterZLeft = ScratchSetDouble(17.630042);
	_0_RasterZRight = ScratchSetDouble(18.123043);
	_0_Rzkh1 = ScratchSetDouble(16.957927);
	_0_Rzkh2 = ScratchSetDouble(17.396150);
	_0_RasterLineZC = ScratchSetDouble(17.396150);
	_0_RasterLineZD = ScratchSetDouble(0.029215);
	_0_Resolution = ScratchSetDouble(1);
	_0_TriDrawScaleFactour = ScratchSetDouble(60);
	_0_XRes = ScratchSetDouble(240);
	_0_YRes = ScratchSetDouble(180);
	_0_y_raster = ScratchSetDouble(-16.904485);
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
		_Set_Model_Matrixzkd_Pos_zfcs_zfcs_zfcs_Scale_zfcs_zfcs_zfcs_Rotation_zfcs_zfcs_zfcs(ScratchSetDouble(0), ScratchSetDouble(-5), ScratchSetDouble(13), ScratchSetDouble(6), ScratchSetDouble(6), ScratchSetDouble(6), ScratchSetDouble(0), operator_multiply(sensing_timer(), ScratchSetDouble(90.0)), ScratchSetDouble(0));
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
		data_setvariableto(operator_divide(ScratchSetDouble(180.0), _0_Resolution), _0_YRes);
		data_setvariableto(operator_divide(ScratchSetDouble(240.0), _0_Resolution), _0_XRes);
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
	data_setvariableto(ScratchSetDouble(operator_mathop_sin((ScratchVarGetDouble(argument_reporter_string_number(_rx))))), _0_sinzocx);
	data_setvariableto(ScratchSetDouble(operator_mathop_sin((ScratchVarGetDouble(argument_reporter_string_number(_ry))))), _0_sinzocy);
	data_setvariableto(ScratchSetDouble(operator_mathop_sin((ScratchVarGetDouble(argument_reporter_string_number(_rzkh))))), _0_sinzoczkh);
	data_setvariableto(ScratchSetDouble(operator_mathop_cos((ScratchVarGetDouble(argument_reporter_string_number(_rx))))), _0_coszocx);
	data_setvariableto(ScratchSetDouble(operator_mathop_cos((ScratchVarGetDouble(argument_reporter_string_number(_ry))))), _0_coszocy);
	data_setvariableto(ScratchSetDouble(operator_mathop_cos((ScratchVarGetDouble(argument_reporter_string_number(_rzkh))))), _0_coszoczkh);
	data_deletealloflist(_Matrix);
	data_addtolist(operator_multiply(operator_multiply(_0_coszocy, _0_coszoczkh), argument_reporter_string_number(_sx)), _Matrix);
	data_addtolist(operator_multiply(argument_reporter_string_number(_sy), operator_subtract(operator_multiply(operator_multiply(_0_sinzocx, _0_sinzocy), _0_coszoczkh), operator_multiply(_0_coszocx, _0_sinzoczkh))), _Matrix);
	data_addtolist(operator_multiply(argument_reporter_string_number(_szkh), operator_add(operator_multiply(operator_multiply(_0_coszocx, _0_sinzocy), _0_coszoczkh), operator_multiply(_0_sinzocx, _0_sinzoczkh))), _Matrix);
	data_addtolist(argument_reporter_string_number(_px), _Matrix);
	data_addtolist(operator_multiply(operator_multiply(_0_coszocy, _0_sinzoczkh), argument_reporter_string_number(_sx)), _Matrix);
	data_addtolist(operator_multiply(argument_reporter_string_number(_sy), operator_add(operator_multiply(operator_multiply(_0_sinzocx, _0_sinzocy), _0_sinzoczkh), operator_multiply(_0_coszocx, _0_coszoczkh))), _Matrix);
	data_addtolist(operator_multiply(argument_reporter_string_number(_szkh), operator_subtract(operator_multiply(operator_multiply(_0_coszocx, _0_sinzocy), _0_sinzoczkh), operator_multiply(_0_sinzocx, _0_coszoczkh))), _Matrix);
	data_addtolist(argument_reporter_string_number(_py), _Matrix);
	data_addtolist(operator_multiply(operator_subtract(ScratchSetDouble(0.0), _0_sinzocy), argument_reporter_string_number(_sx)), _Matrix);
	data_addtolist(operator_multiply(operator_multiply(_0_sinzocx, _0_coszocy), argument_reporter_string_number(_sy)), _Matrix);
	data_addtolist(operator_multiply(operator_multiply(_0_coszocx, _0_coszocy), argument_reporter_string_number(_szkh)), _Matrix);
	data_addtolist(argument_reporter_string_number(_pzkh), _Matrix);
#define YIELD TRUE_YIELD
}

void _Apply_Model_Matrix() 
{
	activeSprite = 1;
#define YIELD
	data_setvariableto(ScratchSetDouble(1), _0_c);
	for(int i1 = 0; i1 < (int)ScratchVarGetDouble(data_lengthoflist(_ModelX)); i1++)
	{
		data_setvariableto(operator_add(operator_add(data_itemoflist(ScratchSetDouble(4.0), _Matrix), operator_multiply(data_itemoflist(ScratchSetDouble(1.0), _Matrix), data_itemoflist(_0_c, _ModelX))), operator_add(operator_multiply(data_itemoflist(ScratchSetDouble(2.0), _Matrix), data_itemoflist(_0_c, _ModelY)), operator_multiply(data_itemoflist(ScratchSetDouble(3.0), _Matrix), data_itemoflist(_0_c, _ModelZ)))), _0_Matx);
		data_setvariableto(operator_add(operator_add(data_itemoflist(ScratchSetDouble(8.0), _Matrix), operator_multiply(data_itemoflist(ScratchSetDouble(5.0), _Matrix), data_itemoflist(_0_c, _ModelX))), operator_add(operator_multiply(data_itemoflist(ScratchSetDouble(6.0), _Matrix), data_itemoflist(_0_c, _ModelY)), operator_multiply(data_itemoflist(ScratchSetDouble(7.0), _Matrix), data_itemoflist(_0_c, _ModelZ)))), _0_Maty);
		data_setvariableto(operator_add(operator_add(data_itemoflist(ScratchSetDouble(12.0), _Matrix), operator_multiply(data_itemoflist(ScratchSetDouble(9.0), _Matrix), data_itemoflist(_0_c, _ModelX))), operator_add(operator_multiply(data_itemoflist(ScratchSetDouble(10.0), _Matrix), data_itemoflist(_0_c, _ModelY)), operator_multiply(data_itemoflist(ScratchSetDouble(11.0), _Matrix), data_itemoflist(_0_c, _ModelZ)))), _0_Matzkh);
		data_replaceitemoflist(_0_c, _0_Matx, _ModelX);
		data_replaceitemoflist(_0_c, _0_Maty, _ModelY);
		data_replaceitemoflist(_0_c, _0_Matzkh, _ModelZ);
		data_changevariableby(ScratchSetDouble(1.0), _0_c);
		YIELD
	}
#define YIELD TRUE_YIELD
}

void _Draw_Triangles() 
{
	activeSprite = 1;
#define YIELD
	data_setvariableto(operator_divide(ScratchSetDouble(60.0), _0_Resolution), _0_TriDrawScaleFactour);
	data_setvariableto(ScratchSetDouble(1), _0_c);
	for(int i1 = 0; i1 < (int)ScratchVarGetDouble(operator_divide(data_lengthoflist(_ModelX), ScratchSetDouble(3.0))); i1++)
	{
		_Rasterise_Triangle_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs_zfcs(operator_multiply(operator_divide(data_itemoflist(operator_add(_0_c, ScratchSetDouble(0.0)), _ModelX), data_itemoflist(operator_add(_0_c, ScratchSetDouble(0.0)), _ModelZ)), _0_TriDrawScaleFactour), operator_multiply(operator_divide(data_itemoflist(operator_add(_0_c, ScratchSetDouble(0.0)), _ModelY), data_itemoflist(operator_add(_0_c, ScratchSetDouble(0.0)), _ModelZ)), _0_TriDrawScaleFactour), operator_multiply(operator_divide(data_itemoflist(operator_add(_0_c, ScratchSetDouble(1.0)), _ModelX), data_itemoflist(operator_add(_0_c, ScratchSetDouble(1.0)), _ModelZ)), _0_TriDrawScaleFactour), operator_multiply(operator_divide(data_itemoflist(operator_add(_0_c, ScratchSetDouble(1.0)), _ModelY), data_itemoflist(operator_add(_0_c, ScratchSetDouble(1.0)), _ModelZ)), _0_TriDrawScaleFactour), operator_multiply(operator_divide(data_itemoflist(operator_add(_0_c, ScratchSetDouble(2.0)), _ModelX), data_itemoflist(operator_add(_0_c, ScratchSetDouble(2.0)), _ModelZ)), _0_TriDrawScaleFactour), operator_multiply(operator_divide(data_itemoflist(operator_add(_0_c, ScratchSetDouble(2.0)), _ModelY), data_itemoflist(operator_add(_0_c, ScratchSetDouble(2.0)), _ModelZ)), _0_TriDrawScaleFactour), data_itemoflist(operator_add(_0_c, ScratchSetDouble(0.0)), _ModelU), data_itemoflist(operator_add(_0_c, ScratchSetDouble(1.0)), _ModelU), data_itemoflist(operator_add(_0_c, ScratchSetDouble(2.0)), _ModelU), data_itemoflist(operator_add(_0_c, ScratchSetDouble(0.0)), _ModelV), data_itemoflist(operator_add(_0_c, ScratchSetDouble(1.0)), _ModelV), data_itemoflist(operator_add(_0_c, ScratchSetDouble(2.0)), _ModelV), data_itemoflist(operator_add(_0_c, ScratchSetDouble(0.0)), _ModelZ), data_itemoflist(operator_add(_0_c, ScratchSetDouble(1.0)), _ModelZ), data_itemoflist(operator_add(_0_c, ScratchSetDouble(2.0)), _ModelZ));
		data_changevariableby(ScratchSetDouble(3.0), _0_c);
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
	if(ScratchVarGetBool(operator_and(operator_lt(argument_reporter_string_number(_y3), argument_reporter_string_number(_y1)), operator_lt(argument_reporter_string_number(_y2), argument_reporter_string_number(_y1)))))
	{
		data_setvariableto(ScratchSetDouble(1), _0_c1);
		data_setvariableto(argument_reporter_string_number(_y1), _0_RasterY1);
		data_setvariableto(argument_reporter_string_number(_x1), _0_RasterX1);
		data_setvariableto(argument_reporter_string_number(_u1), _0_RasterU1);
		data_setvariableto(argument_reporter_string_number(_v1), _0_RasterV1);
		data_setvariableto(argument_reporter_string_number(_zkh1), _0_RasterZ1);
		if(ScratchVarGetBool(operator_lt(argument_reporter_string_number(_y3), argument_reporter_string_number(_y2))))
		{
			data_setvariableto(argument_reporter_string_number(_y2), _0_RasterY2);
			data_setvariableto(argument_reporter_string_number(_x2), _0_RasterX2);
			data_setvariableto(argument_reporter_string_number(_u2), _0_RasterU2);
			data_setvariableto(argument_reporter_string_number(_v2), _0_RasterV2);
			data_setvariableto(argument_reporter_string_number(_zkh2), _0_RasterZ2);
			_();
			data_setvariableto(argument_reporter_string_number(_y3), _0_RasterY3);
			data_setvariableto(argument_reporter_string_number(_x3), _0_RasterX3);
			data_setvariableto(argument_reporter_string_number(_u3), _0_RasterU3);
			data_setvariableto(argument_reporter_string_number(_v3), _0_RasterV3);
			data_setvariableto(argument_reporter_string_number(_zkh3), _0_RasterZ3);
		}
		else
		{
			data_setvariableto(argument_reporter_string_number(_y2), _0_RasterY3);
			data_setvariableto(argument_reporter_string_number(_x2), _0_RasterX3);
			data_setvariableto(argument_reporter_string_number(_u2), _0_RasterU3);
			data_setvariableto(argument_reporter_string_number(_v2), _0_RasterV3);
			data_setvariableto(argument_reporter_string_number(_zkh2), _0_RasterZ3);
			_();
			data_setvariableto(argument_reporter_string_number(_y3), _0_RasterY2);
			data_setvariableto(argument_reporter_string_number(_x3), _0_RasterX2);
			data_setvariableto(argument_reporter_string_number(_u3), _0_RasterU2);
			data_setvariableto(argument_reporter_string_number(_v3), _0_RasterV2);
			data_setvariableto(argument_reporter_string_number(_zkh3), _0_RasterZ2);
		}
	}
	if(ScratchVarGetBool(operator_and(operator_lt(argument_reporter_string_number(_y3), argument_reporter_string_number(_y2)), operator_lt(argument_reporter_string_number(_y1), argument_reporter_string_number(_y2)))))
	{
		data_setvariableto(ScratchSetDouble(2), _0_c1);
		data_setvariableto(argument_reporter_string_number(_y2), _0_RasterY1);
		data_setvariableto(argument_reporter_string_number(_x2), _0_RasterX1);
		data_setvariableto(argument_reporter_string_number(_u2), _0_RasterU1);
		data_setvariableto(argument_reporter_string_number(_v2), _0_RasterV1);
		data_setvariableto(argument_reporter_string_number(_zkh2), _0_RasterZ1);
		if(ScratchVarGetBool(operator_lt(argument_reporter_string_number(_y3), argument_reporter_string_number(_y1))))
		{
			data_setvariableto(argument_reporter_string_number(_y1), _0_RasterY2);
			data_setvariableto(argument_reporter_string_number(_x1), _0_RasterX2);
			data_setvariableto(argument_reporter_string_number(_u1), _0_RasterU2);
			data_setvariableto(argument_reporter_string_number(_v1), _0_RasterV2);
			data_setvariableto(argument_reporter_string_number(_zkh1), _0_RasterZ2);
			_();
			data_setvariableto(argument_reporter_string_number(_y3), _0_RasterY3);
			data_setvariableto(argument_reporter_string_number(_x3), _0_RasterX3);
			data_setvariableto(argument_reporter_string_number(_u3), _0_RasterU3);
			data_setvariableto(argument_reporter_string_number(_v3), _0_RasterV3);
			data_setvariableto(argument_reporter_string_number(_zkh3), _0_RasterZ3);
		}
		else
		{
			data_setvariableto(argument_reporter_string_number(_y1), _0_RasterY3);
			data_setvariableto(argument_reporter_string_number(_x1), _0_RasterX3);
			data_setvariableto(argument_reporter_string_number(_u1), _0_RasterU3);
			data_setvariableto(argument_reporter_string_number(_v1), _0_RasterV3);
			data_setvariableto(argument_reporter_string_number(_zkh1), _0_RasterZ3);
			_();
			data_setvariableto(argument_reporter_string_number(_y3), _0_RasterY2);
			data_setvariableto(argument_reporter_string_number(_x3), _0_RasterX2);
			data_setvariableto(argument_reporter_string_number(_u3), _0_RasterU2);
			data_setvariableto(argument_reporter_string_number(_v3), _0_RasterV2);
			data_setvariableto(argument_reporter_string_number(_zkh3), _0_RasterZ2);
		}
	}
	if(ScratchVarGetBool(operator_and(operator_lt(argument_reporter_string_number(_y2), argument_reporter_string_number(_y3)), operator_lt(argument_reporter_string_number(_y1), argument_reporter_string_number(_y3)))))
	{
		data_setvariableto(ScratchSetDouble(3), _0_c1);
		data_setvariableto(argument_reporter_string_number(_y3), _0_RasterY1);
		data_setvariableto(argument_reporter_string_number(_x3), _0_RasterX1);
		data_setvariableto(argument_reporter_string_number(_u3), _0_RasterU1);
		data_setvariableto(argument_reporter_string_number(_v3), _0_RasterV1);
		data_setvariableto(argument_reporter_string_number(_zkh3), _0_RasterZ1);
		if(ScratchVarGetBool(operator_lt(argument_reporter_string_number(_y2), argument_reporter_string_number(_y1))))
		{
			data_setvariableto(argument_reporter_string_number(_y1), _0_RasterY2);
			data_setvariableto(argument_reporter_string_number(_x1), _0_RasterX2);
			data_setvariableto(argument_reporter_string_number(_u1), _0_RasterU2);
			data_setvariableto(argument_reporter_string_number(_v1), _0_RasterV2);
			data_setvariableto(argument_reporter_string_number(_zkh1), _0_RasterZ2);
			_();
			data_setvariableto(argument_reporter_string_number(_y2), _0_RasterY3);
			data_setvariableto(argument_reporter_string_number(_x2), _0_RasterX3);
			data_setvariableto(argument_reporter_string_number(_u2), _0_RasterU3);
			data_setvariableto(argument_reporter_string_number(_v2), _0_RasterV3);
			data_setvariableto(argument_reporter_string_number(_zkh2), _0_RasterZ3);
		}
		else
		{
			data_setvariableto(argument_reporter_string_number(_y1), _0_RasterY3);
			data_setvariableto(argument_reporter_string_number(_x1), _0_RasterX3);
			data_setvariableto(argument_reporter_string_number(_u1), _0_RasterU3);
			data_setvariableto(argument_reporter_string_number(_v1), _0_RasterV3);
			data_setvariableto(argument_reporter_string_number(_zkh1), _0_RasterZ3);
			_();
			data_setvariableto(argument_reporter_string_number(_y2), _0_RasterY2);
			data_setvariableto(argument_reporter_string_number(_x2), _0_RasterX2);
			data_setvariableto(argument_reporter_string_number(_u2), _0_RasterU2);
			data_setvariableto(argument_reporter_string_number(_v2), _0_RasterV2);
			data_setvariableto(argument_reporter_string_number(_zkh2), _0_RasterZ2);
		}
	}
	data_setvariableto(operator_divide(operator_subtract(_0_RasterY2, _0_RasterY3), operator_subtract(_0_RasterY1, _0_RasterY3)), _0_t);
	data_setvariableto(operator_add(operator_multiply(_0_t, operator_subtract(_0_RasterX1, _0_RasterX3)), _0_RasterX3), _0_RasterX4);
	data_setvariableto(_0_RasterY2, _0_RasterY4);
	data_setvariableto(operator_add(operator_multiply(_0_t, operator_subtract(_0_RasterU1, _0_RasterU3)), _0_RasterU3), _0_RasterU4);
	data_setvariableto(operator_add(operator_multiply(_0_t, operator_subtract(_0_RasterV1, _0_RasterV3)), _0_RasterV3), _0_RasterV4);
	data_setvariableto(operator_add(operator_multiply(_0_t, operator_subtract(_0_RasterZ1, _0_RasterZ3)), _0_RasterZ3), _0_RasterZ4);
	_();
	if(ScratchVarGetBool(operator_not(operator_equals(_0_RasterY2, _0_RasterY1))))
	{
		data_setvariableto(operator_subtract(ScratchSetDouble(0.0), operator_divide(operator_subtract(_0_RasterX2, _0_RasterX1), operator_subtract(_0_RasterY2, _0_RasterY1))), _0_dx1);
		data_setvariableto(operator_subtract(ScratchSetDouble(0.0), operator_divide(operator_subtract(_0_RasterX4, _0_RasterX1), operator_subtract(_0_RasterY4, _0_RasterY1))), _0_dx2);
		data_setvariableto(operator_subtract(ScratchSetDouble(0.0), operator_divide(operator_subtract(_0_RasterV2, _0_RasterV1), operator_subtract(_0_RasterY2, _0_RasterY1))), _0_dvx1);
		data_setvariableto(operator_subtract(ScratchSetDouble(0.0), operator_divide(operator_subtract(_0_RasterU2, _0_RasterU1), operator_subtract(_0_RasterY2, _0_RasterY1))), _0_dux1);
		data_setvariableto(operator_subtract(ScratchSetDouble(0.0), operator_divide(operator_subtract(_0_RasterV4, _0_RasterV1), operator_subtract(_0_RasterY2, _0_RasterY1))), _0_dvx2);
		data_setvariableto(operator_subtract(ScratchSetDouble(0.0), operator_divide(operator_subtract(_0_RasterU4, _0_RasterU1), operator_subtract(_0_RasterY2, _0_RasterY1))), _0_dux2);
		data_setvariableto(operator_subtract(ScratchSetDouble(0.0), operator_divide(operator_subtract(_0_RasterZ2, _0_RasterZ1), operator_subtract(_0_RasterY2, _0_RasterY1))), _0_dzkh1);
		data_setvariableto(operator_subtract(ScratchSetDouble(0.0), operator_divide(operator_subtract(_0_RasterZ4, _0_RasterZ1), operator_subtract(_0_RasterY2, _0_RasterY1))), _0_dzkh2);
		data_setvariableto(_0_RasterX1, _0_RasterXLeft);
		data_setvariableto(_0_RasterX1, _0_RasterXRight);
		data_setvariableto(_0_RasterU1, _0_RasterULeft);
		data_setvariableto(_0_RasterU1, _0_RasterURight);
		data_setvariableto(_0_RasterV1, _0_RasterVLeft);
		data_setvariableto(_0_RasterV1, _0_RasterVRight);
		data_setvariableto(_0_RasterZ1, _0_RasterZLeft);
		data_setvariableto(_0_RasterZ1, _0_RasterZRight);
		data_setvariableto(_0_RasterY1, _0_y_raster);
		for(int i2 = 0; i2 < (int)ScratchVarGetDouble(operator_add(ScratchSetDouble(1.0), operator_subtract(_0_RasterY1, _0_RasterY4))); i2++)
		{
			data_setvariableto(operator_round(_0_RasterXRight), _0_RXRound);
			data_setvariableto(operator_round(_0_RasterXLeft), _0_Rx2Round);
			data_setvariableto(_0_RasterURight, _0_RU1);
			data_setvariableto(_0_RasterULeft, _0_RU2);
			data_setvariableto(_0_RasterVRight, _0_Rv1);
			data_setvariableto(_0_RasterVLeft, _0_Rv2);
			data_setvariableto(_0_RasterZRight, _0_Rzkh1);
			data_setvariableto(_0_RasterZLeft, _0_Rzkh2);
			if(ScratchVarGetBool(operator_lt(_0_Rx2Round, _0_RXRound)))
			{
				data_setvariableto(operator_round(_0_RasterXLeft), _0_RXRound);
				data_setvariableto(operator_round(_0_RasterXRight), _0_Rx2Round);
				data_setvariableto(_0_RasterULeft, _0_RU1);
				data_setvariableto(_0_RasterURight, _0_RU2);
				data_setvariableto(_0_RasterVLeft, _0_Rv1);
				data_setvariableto(_0_RasterVRight, _0_Rv2);
				data_setvariableto(_0_RasterZLeft, _0_Rzkh1);
				data_setvariableto(_0_RasterZRight, _0_Rzkh2);
			}
			data_setvariableto(_0_RU1, _0_RasterLineUC);
			data_setvariableto(operator_divide(operator_subtract(_0_RU2, _0_RU1), operator_subtract(_0_Rx2Round, _0_RXRound)), _0_RasterLineUD);
			data_setvariableto(_0_Rv1, _0_RasterLineVC);
			data_setvariableto(operator_divide(operator_subtract(_0_Rv2, _0_Rv1), operator_subtract(_0_Rx2Round, _0_RXRound)), _0_RasterLineVd);
			data_setvariableto(_0_Rzkh1, _0_RasterLineZC);
			data_setvariableto(operator_divide(operator_subtract(_0_Rzkh2, _0_Rzkh1), operator_subtract(_0_Rx2Round, _0_RXRound)), _0_RasterLineZD);
			motion_gotoxy(ScratchVarGetDouble(operator_round(_0_RXRound)), ScratchVarGetDouble(operator_round(_0_y_raster)));
			for(int i3 = 0; i3 < (int)ScratchVarGetDouble(operator_subtract(_0_Rx2Round, _0_RXRound)); i3++)
			{
				_Set_Colour_zfcs_zfcs(_0_RasterLineUC, _0_RasterLineVC);
				motion_changexby(1);
				data_changevariableby(_0_RasterLineUD, _0_RasterLineUC);
				data_changevariableby(_0_RasterLineVd, _0_RasterLineVC);
				data_changevariableby(_0_RasterLineZD, _0_RasterLineZC);
				if(ScratchVarGetBool(operator_lt(ScratchSetDouble(1), _0_RasterLineUC)))
				{
					data_setvariableto(ScratchSetDouble(1), _0_RasterLineUC);
				}
				if(ScratchVarGetBool(operator_lt(ScratchSetDouble(1), _0_RasterLineVC)))
				{
					data_setvariableto(ScratchSetDouble(1), _0_RasterLineVC);
				}
				YIELD
			}
			data_changevariableby(ScratchSetDouble(-1.0), _0_y_raster);
			data_changevariableby(_0_dx1, _0_RasterXLeft);
			data_changevariableby(_0_dx2, _0_RasterXRight);
			data_changevariableby(_0_dvx1, _0_RasterVLeft);
			data_changevariableby(_0_dux1, _0_RasterULeft);
			data_changevariableby(_0_dvx2, _0_RasterVRight);
			data_changevariableby(_0_dux2, _0_RasterURight);
			data_changevariableby(_0_dzkh1, _0_RasterZLeft);
			data_changevariableby(_0_dzkh2, _0_RasterZRight);
			YIELD
		}
	}
	_();
	if(ScratchVarGetBool(operator_not(operator_equals(_0_RasterY2, _0_RasterY3))))
	{
		data_setvariableto(operator_divide(operator_subtract(_0_RasterX2, _0_RasterX3), operator_subtract(_0_RasterY2, _0_RasterY3)), _0_dx1);
		data_setvariableto(operator_divide(operator_subtract(_0_RasterX4, _0_RasterX3), operator_subtract(_0_RasterY4, _0_RasterY3)), _0_dx2);
		data_setvariableto(operator_divide(operator_subtract(_0_RasterV2, _0_RasterV3), operator_subtract(_0_RasterY2, _0_RasterY3)), _0_dvx1);
		data_setvariableto(operator_divide(operator_subtract(_0_RasterU2, _0_RasterU3), operator_subtract(_0_RasterY2, _0_RasterY3)), _0_dux1);
		data_setvariableto(operator_divide(operator_subtract(_0_RasterV4, _0_RasterV3), operator_subtract(_0_RasterY4, _0_RasterY3)), _0_dvx2);
		data_setvariableto(operator_divide(operator_subtract(_0_RasterU4, _0_RasterU3), operator_subtract(_0_RasterY4, _0_RasterY3)), _0_dux2);
		data_setvariableto(operator_divide(operator_subtract(_0_RasterZ2, _0_RasterZ3), operator_subtract(_0_RasterY2, _0_RasterY3)), _0_dzkh1);
		data_setvariableto(operator_divide(operator_subtract(_0_RasterZ4, _0_RasterZ3), operator_subtract(_0_RasterY4, _0_RasterY3)), _0_dzkh2);
		data_setvariableto(_0_RasterX3, _0_RasterXLeft);
		data_setvariableto(_0_RasterX3, _0_RasterXRight);
		data_setvariableto(_0_RasterU3, _0_RasterULeft);
		data_setvariableto(_0_RasterU3, _0_RasterURight);
		data_setvariableto(_0_RasterV3, _0_RasterVLeft);
		data_setvariableto(_0_RasterV3, _0_RasterVRight);
		data_setvariableto(_0_RasterZ3, _0_RasterZLeft);
		data_setvariableto(_0_RasterZ3, _0_RasterZRight);
		data_setvariableto(_0_RasterY3, _0_y_raster);
		for(int i2 = 0; i2 < (int)ScratchVarGetDouble(operator_add(ScratchSetDouble(0.0), ScratchSetDouble(operator_mathop_ceiling((ScratchVarGetDouble(operator_subtract(_0_RasterY4, _0_RasterY3))))))); i2++)
		{
			data_setvariableto(operator_round(_0_RasterXRight), _0_RXRound);
			data_setvariableto(operator_round(_0_RasterXLeft), _0_Rx2Round);
			data_setvariableto(_0_RasterURight, _0_RU1);
			data_setvariableto(_0_RasterULeft, _0_RU2);
			data_setvariableto(_0_RasterVRight, _0_Rv1);
			data_setvariableto(_0_RasterVLeft, _0_Rv2);
			data_setvariableto(_0_RasterZRight, _0_Rzkh1);
			data_setvariableto(_0_RasterZLeft, _0_Rzkh2);
			if(ScratchVarGetBool(operator_lt(_0_Rx2Round, _0_RXRound)))
			{
				data_setvariableto(operator_round(_0_RasterXLeft), _0_RXRound);
				data_setvariableto(operator_round(_0_RasterXRight), _0_Rx2Round);
				data_setvariableto(_0_RasterULeft, _0_RU1);
				data_setvariableto(_0_RasterURight, _0_RU2);
				data_setvariableto(_0_RasterVLeft, _0_Rv1);
				data_setvariableto(_0_RasterVRight, _0_Rv2);
				data_setvariableto(_0_RasterZLeft, _0_Rzkh1);
				data_setvariableto(_0_RasterZRight, _0_Rzkh2);
			}
			data_setvariableto(_0_RU1, _0_RasterLineUC);
			data_setvariableto(operator_divide(operator_subtract(_0_RU2, _0_RU1), operator_subtract(_0_Rx2Round, _0_RXRound)), _0_RasterLineUD);
			data_setvariableto(_0_Rv1, _0_RasterLineVC);
			data_setvariableto(operator_divide(operator_subtract(_0_Rv2, _0_Rv1), operator_subtract(_0_Rx2Round, _0_RXRound)), _0_RasterLineVd);
			data_setvariableto(_0_Rzkh1, _0_RasterLineZC);
			data_setvariableto(operator_divide(operator_subtract(_0_Rzkh2, _0_Rzkh1), operator_subtract(_0_Rx2Round, _0_RXRound)), _0_RasterLineZD);
			motion_gotoxy(ScratchVarGetDouble(_0_RXRound), ScratchVarGetDouble(operator_round(_0_y_raster)));
			_Set_Colour_zfcs_zfcs(_0_RasterLineUC, _0_RasterLineVC);
			for(int i3 = 0; i3 < (int)ScratchVarGetDouble(operator_subtract(_0_Rx2Round, _0_RXRound)); i3++)
			{
				_Set_Colour_zfcs_zfcs(_0_RasterLineUC, _0_RasterLineVC);
				motion_changexby(1);
				data_changevariableby(_0_RasterLineUD, _0_RasterLineUC);
				data_changevariableby(_0_RasterLineVd, _0_RasterLineVC);
				data_changevariableby(_0_RasterLineZD, _0_RasterLineZC);
				if(ScratchVarGetBool(operator_lt(ScratchSetDouble(1), _0_RasterLineUC)))
				{
					data_setvariableto(ScratchSetDouble(1), _0_RasterLineUC);
				}
				if(ScratchVarGetBool(operator_lt(ScratchSetDouble(1), _0_RasterLineVC)))
				{
					data_setvariableto(ScratchSetDouble(1), _0_RasterLineVC);
				}
				YIELD
			}
			data_changevariableby(_0_dx1, _0_RasterXLeft);
			data_changevariableby(_0_dx2, _0_RasterXRight);
			data_changevariableby(_0_dvx1, _0_RasterVLeft);
			data_changevariableby(_0_dux1, _0_RasterULeft);
			data_changevariableby(_0_dvx2, _0_RasterVRight);
			data_changevariableby(_0_dux2, _0_RasterURight);
			data_changevariableby(_0_dzkh1, _0_RasterZLeft);
			data_changevariableby(_0_dzkh2, _0_RasterZRight);
			data_changevariableby(ScratchSetDouble(1.0), _0_y_raster);
			YIELD
		}
	}
#define YIELD TRUE_YIELD
}

void _Set_Colour_zfcs_zfcs(ScratchValue _u, ScratchValue _v) 
{
	activeSprite = 1;
#define YIELD
	_SetColBuffer_zfcs_zfcs_zfcs(ScratchSetDouble(motion_xposition()), ScratchSetDouble(motion_yposition()), operator_add(operator_multiply(operator_multiply(operator_round(operator_multiply(argument_reporter_string_number(_u), ScratchSetDouble(255.0))), ScratchSetDouble(256.0)), ScratchSetDouble(256.0)), operator_multiply(operator_round(operator_multiply(argument_reporter_string_number(_v), ScratchSetDouble(255.0))), ScratchSetDouble(256.0))));
#define YIELD TRUE_YIELD
}

void _SetColourByDistance_zfcs(ScratchValue _d) 
{
	activeSprite = 1;
#define YIELD
	pen_setPenColorToColor(operator_add(operator_multiply(operator_mod(operator_round(operator_multiply(operator_divide(ScratchSetDouble(4.0), argument_reporter_string_number(_d)), ScratchSetDouble(255.0))), ScratchSetDouble(256.0)), operator_multiply(ScratchSetDouble(256.0), ScratchSetDouble(256.0))), operator_add(operator_multiply(operator_mod(operator_round(operator_multiply(operator_divide(ScratchSetDouble(4.0), argument_reporter_string_number(_d)), ScratchSetDouble(255.0))), ScratchSetDouble(256.0)), ScratchSetDouble(256.0)), operator_mod(operator_round(operator_multiply(operator_divide(ScratchSetDouble(4.0), argument_reporter_string_number(_d)), ScratchSetDouble(255.0))), ScratchSetDouble(256.0)))));
#define YIELD TRUE_YIELD
}

void _SetZBuffer_zfcs_zfcs_zfcs(ScratchValue _x, ScratchValue _y, ScratchValue _zkh) 
{
	activeSprite = 1;
#define YIELD
	data_replaceitemoflist(operator_add(operator_multiply(operator_add(argument_reporter_string_number(_x), _0_XRes), operator_add(_0_YRes, _0_YRes)), operator_add(argument_reporter_string_number(_y), _0_YRes)), argument_reporter_string_number(_zkh), _ColourBuffer);
#define YIELD TRUE_YIELD
}

void _SetColBuffer_zfcs_zfcs_zfcs(ScratchValue _x, ScratchValue _y, ScratchValue _Col) 
{
	activeSprite = 1;
#define YIELD
	data_replaceitemoflist(operator_add(operator_multiply(operator_add(argument_reporter_string_number(_x), _0_XRes), operator_add(_0_YRes, _0_YRes)), operator_add(argument_reporter_string_number(_y), _0_YRes)), argument_reporter_string_number(_Col), _ColourBuffer);
#define YIELD TRUE_YIELD
}

void _Clear_Buffers() 
{
	activeSprite = 1;
#define YIELD
	data_deletealloflist(_ZBuffer);
	data_deletealloflist(_ColourBuffer);
	for(int i1 = 0; i1 < (int)ScratchVarGetDouble(operator_add(_0_XRes, _0_XRes)); i1++)
	{
		for(int i2 = 0; i2 < (int)ScratchVarGetDouble(operator_add(_0_YRes, _0_YRes)); i2++)
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
	if(ScratchVarGetBool(operator_equals(_0_Resolution, ScratchSetDouble(1))))
	{
		pen_setPenSizeTo(ScratchSetDouble(1.0));
	}
	else
	{
		pen_setPenSizeTo(operator_multiply(_0_Resolution, ScratchSetDouble(1.5)));
		motion_changexby(ScratchVarGetDouble(_0_Resolution));
		motion_changeyby(ScratchVarGetDouble(_0_Resolution));
	}
	data_setvariableto(ScratchSetDouble(0), _0_c);
	motion_gotoxy(-240, -180);
	for(int i1 = 0; i1 < (int)ScratchVarGetDouble(operator_add(_0_XRes, _0_XRes)); i1++)
	{
		motion_sety(-180);
		for(int i2 = 0; i2 < (int)ScratchVarGetDouble(operator_add(_0_YRes, _0_YRes)); i2++)
		{
			data_changevariableby(ScratchSetDouble(1.0), _0_c);
			pen_setPenColorToColor(data_itemoflist(_0_c, _ColourBuffer));
			pen_penDown();
			pen_penUp();
			motion_changeyby(ScratchVarGetDouble(_0_Resolution));
			YIELD
		}
		motion_changexby(ScratchVarGetDouble(_0_Resolution));
		YIELD
	}
#define YIELD TRUE_YIELD
}

