#include "types.h"

#define DEG_TO_RAD 0.0174532925199
#define RAD_TO_DEG 57.295779513082

inline ScratchValue operator_add(ScratchValue a, ScratchValue b) { return ScratchSetDouble(ScratchVarGetDouble(a) + ScratchVarGetDouble(b)); }
inline ScratchValue operator_subtract(ScratchValue a, ScratchValue b) { return ScratchSetDouble(ScratchVarGetDouble(a) - ScratchVarGetDouble(b)); }
inline ScratchValue operator_multiply(ScratchValue a, ScratchValue b) { return ScratchSetDouble(ScratchVarGetDouble(a) * ScratchVarGetDouble(b)); }
inline ScratchValue operator_divide(ScratchValue a, ScratchValue b) { return ScratchSetDouble(ScratchVarGetDouble(a) / ScratchVarGetDouble(b)); }
ScratchValue operator_random(ScratchValue min, ScratchValue max); 
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
inline ScratchValue operator_mathopYaabas(ScratchValue a) { return ScratchSetDouble(fabs(ScratchVarGetDouble(a))); }
inline ScratchValue operator_mathopYfalaoaoar(ScratchValue a) { return ScratchSetDouble(floor(ScratchVarGetDouble(a))); }
inline ScratchValue operator_mathopYcaeaialaianag(ScratchValue a) { return ScratchSetDouble(ceil(ScratchVarGetDouble(a))); }
inline ScratchValue operator_mathopYsaqarat(ScratchValue a) { return ScratchSetDouble(sqrt(ScratchVarGetDouble(a))); }
inline ScratchValue operator_mathopYsaian(ScratchValue a) { return ScratchSetDouble(sin(ScratchVarGetDouble(a) * DEG_TO_RAD)); }
inline ScratchValue operator_mathopYcaoas(ScratchValue a) { return ScratchSetDouble(cos(ScratchVarGetDouble(a) * DEG_TO_RAD)); }
inline ScratchValue operator_mathopYtaaan(ScratchValue a) { return ScratchSetDouble(tan(ScratchVarGetDouble(a) * DEG_TO_RAD)); }
inline ScratchValue operator_mathopYaasaian(ScratchValue a) { return ScratchSetDouble(asin(ScratchVarGetDouble(a)) * RAD_TO_DEG); }
inline ScratchValue operator_mathopYaacaoas(ScratchValue a) { return ScratchSetDouble(acos(ScratchVarGetDouble(a)) * RAD_TO_DEG); }
inline ScratchValue operator_mathopYaataaan(ScratchValue a) { return ScratchSetDouble(atan(ScratchVarGetDouble(a)) * RAD_TO_DEG); }
inline ScratchValue operator_mathopYlan(ScratchValue a) { return ScratchSetDouble(log(ScratchVarGetDouble(a))); }
inline ScratchValue operator_mathopYlaoag(ScratchValue a) { return ScratchSetDouble(log10(ScratchVarGetDouble(a))); }
inline ScratchValue operator_mathopYeibpb(ScratchValue a) { return ScratchSetDouble(exp(ScratchVarGetDouble(a))); }
inline ScratchValue operator_mathopY1a0ibpb(ScratchValue a) { return ScratchSetDouble(pow(10.0, ScratchVarGetDouble(a))); }