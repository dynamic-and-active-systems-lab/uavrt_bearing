//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: bearing_rtwutil.h
//
// MATLAB Coder version            : 5.6
// C/C++ source code generated on  : 15-Aug-2023 14:31:29
//

#ifndef BEARING_RTWUTIL_H
#define BEARING_RTWUTIL_H

// Include Files
#include "rtwtypes.h"
#include <cstddef>
#include <cstdlib>
#include <string>

// Type Declarations
struct rtBoundsCheckInfo;

struct rtEqualityCheckInfo;

struct rtDoubleCheckInfo;

// Function Declarations
extern void b_rtErrorWithMessageID(const char *r, const char *aFcnName,
                                   int aLineNum);

extern void b_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

extern void bb_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

extern void c_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

extern void d_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

extern void emlrtDimSizeImpxCheckR2021b(const int aDim1, const int aDim2,
                                        const rtEqualityCheckInfo &aInfo);

extern void f_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

extern void i_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

extern void rtDynamicBoundsError(int aIndexValue, int aLoBound, int aHiBound,
                                 const rtBoundsCheckInfo &aInfo);

extern void rtErrorWithMessageID(const char *aFcnName, int aLineNum);

extern std::string rtGenSizeString(const int aNDims, const int *aDims);

extern void rtIntegerError(const double aInteger,
                           const rtDoubleCheckInfo &aInfo);

extern boolean_T rtIsNullOrEmptyString(const char *aString);

extern void rtNonNegativeError(const double aPositive,
                               const rtDoubleCheckInfo &aInfo);

extern void rtSubAssignSizeCheck(const int *aDims1, const int aNDims1,
                                 const int *aDims2, const int aNDims2,
                                 const rtEqualityCheckInfo &aInfo);

extern double rt_atan2d_snf(double u0, double u1);

extern void v_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

#endif
//
// File trailer for bearing_rtwutil.h
//
// [EOF]
//
