//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: feof.cpp
//
// MATLAB Coder version            : 23.2
// C/C++ source code generated on  : 07-Nov-2023 14:21:19
//

// Include Files
#include "feof.h"
#include "bearing_data.h"
#include "bearing_rtwutil.h"
#include "bearing_types.h"
#include "fileManager.h"
#include "rt_nonfinite.h"
#include <cstdio>

// Function Definitions
//
// Arguments    : double fileID
// Return Type  : double
//
namespace coder {
double b_feof(double fileID)
{
  std::FILE *f;
  double st;
  boolean_T a;
  f = internal::getfilestar(fileID, a);
  if (f == nullptr) {
    b_rtErrorWithMessageID(j_emlrtRTEI.fName, j_emlrtRTEI.lineNo);
  } else {
    int b_st;
    b_st = std::feof(f);
    st = ((int)b_st != 0);
  }
  return st;
}

} // namespace coder

//
// File trailer for feof.cpp
//
// [EOF]
//
