#include "types.h"

#define DEG_TO_RAD 0.0174532925199
#define RAD_TO_DEG 57.295779513082

inline ScratchValue operator_add(ScratchValue a, ScratchValue b) { return ScratchSetDouble(ScratchVarGetDouble(a) + ScratchVarGetDouble(b)); }
inline ScratchValue operator_subtract(ScratchValue a, ScratchValue b) { return ScratchSetDouble(ScratchVarGetDouble(a) - ScratchVarGetDouble(b)); }
inline ScratchValue operator_multiply(ScratchValue a, ScratchValue b) { return ScratchSetDouble(ScratchVarGetDouble(a) * ScratchVarGetDouble(b)); }
inline ScratchValue operator_divide(ScratchValue a, ScratchValue b) { return ScratchSetDouble(ScratchVarGetDouble(a) / ScratchVarGetDouble(b)); }
double operator_random(double min, double max);
inline ScratchValue operator_gt(ScratchValue a, ScratchValue b) { return ScratchSetBool(ScratchVarGetDouble(a) > ScratchVarGetDouble(b)); }
inline ScratchValue operator_lt(ScratchValue a, ScratchValue b) { return ScratchSetBool(ScratchVarGetDouble(a) < ScratchVarGetDouble(b)); }
ScratchValue operator_equals(ScratchValue a, ScratchValue b);
inline ScratchValue operator_and(ScratchValue a, ScratchValue b) { return ScratchSetBool(ScratchVarGetBool(a) && ScratchVarGetBool(b)); }
inline ScratchValue operator_or(ScratchValue a, ScratchValue b) { return ScratchSetBool(ScratchVarGetBool(a) || ScratchVarGetBool(b)); }
inline ScratchValue operator_not(ScratchValue a) { return ScratchSetBool(!ScratchVarGetBool(a)); }
ScratchValue operator_join(ScratchValue a, ScratchValue b);
ScratchValue operator_letter_of(ScratchValue index, ScratchValue string);
ScratchValue operator_length(ScratchValue string);
ScratchValue operator_contains(ScratchValue string, ScratchValue substring);
ScratchValue operator_mod(ScratchValue a, ScratchValue b);
inline ScratchValue operator_length(ScratchValue string) { return ScratchSetDouble(strlen(ScratchVarGetString(string))); }
inline ScratchValue operator_contains(ScratchValue string, ScratchValue substring) { return ScratchSetBool(strstr(ScratchVarGetString(string), ScratchVarGetString(substring)) != NULL); }
inline ScratchValue operator_mod(ScratchValue a, ScratchValue b) { return ScratchSetDouble(fmod(ScratchVarGetDouble(a), ScratchVarGetDouble(b))); }
inline ScratchValue operator_round(ScratchValue a) { return ScratchSetDouble(round(ScratchVarGetDouble(a))); }
inline double operator_mathop_abs(double a) { return (fabs((a))); }
inline double operator_mathop_floor(double a) { return (floor((a))); }
inline double operator_mathop_ceiling(double a) { return (ceil((a))); }
inline double operator_mathop_sqrt(double a) { return (sqrt((a))); }
inline double operator_mathop_sin(double a) { return (sin((a) * DEG_TO_RAD)); }
inline double operator_mathop_cos(double a) { return (cos((a) * DEG_TO_RAD)); }
inline double operator_mathop_tan(double a) { return (tan((a) * DEG_TO_RAD)); }
inline double operator_mathop_asin(double a) { return (asin((a)) * RAD_TO_DEG); }
inline double operator_mathop_acos(double a) { return (acos((a)) * RAD_TO_DEG); }
inline double operator_mathop_atan(double a) { return (atan((a)) * RAD_TO_DEG); }
inline double operator_mathop_ln(double a) { return (log((a))); }
inline double operator_mathop_log(double a) { return (log10((a))); }
inline double operator_mathop_e_zof(double a) { return (exp((a))); }
inline double operator_mathop_10_zof(double a) { return (pow(10.0, (a))); }