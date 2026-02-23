void pen_clear();
void pen_penDown();
void pen_penUp();
void penDrawLine(double x1, double y1, double x2, double y2);
void pen_stamp();
void pen_setPenColorToColor(ScratchValue color);
void pen_setPenSizeTo(ScratchValue size);
void pen_setPenColorParamTo(ScratchValue param, ScratchValue value);

#pragma once

extern double PenSize;

#define pen_menu_colorParamYataraaanasapaaaraeanacay() ScratchSetDouble(3)