//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: bearing_rtwutil.h
//
// MATLAB Coder version            : 23.2
// C/C++ source code generated on  : 07-Nov-2023 14:21:19
//

#ifndef BEARING_RTWUTIL_H
#define BEARING_RTWUTIL_H

// Include Files
#include "rtwtypes.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
struct rtBoundsCheckInfo;

struct rtDoubleCheckInfo;

// Function Declarations
extern void ab_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

extern void b_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

extern void c_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

extern void d_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

extern void e_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

extern void g_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

extern void rtDynamicBoundsError(int aIndexValue, int aLoBound, int aHiBound,
                                 const rtBoundsCheckInfo &aInfo);

extern void rtIntegerError(const double aInteger,
                           const rtDoubleCheckInfo &aInfo);

extern boolean_T rtIsNullOrEmptyString(const char *aString);

extern void rtNonNegativeError(const double aPositive,
                               const rtDoubleCheckInfo &aInfo);

extern void u_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

extern void y_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

#endif
//
// File trailer for bearing_rtwutil.h
//
// [EOF]
//
