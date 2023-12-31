//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: find.cpp
//
// MATLAB Coder version            : 23.2
// C/C++ source code generated on  : 07-Nov-2023 14:21:19
//

// Include Files
#include "find.h"
#include "bearing_rtwutil.h"
#include "bearing_types.h"
#include "eml_int_forloop_overflow_check.h"
#include "indexShapeCheck.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : const array<boolean_T, 1U> &x
//                array<int, 1U> &i
// Return Type  : void
//
namespace coder {
void eml_find(const array<boolean_T, 1U> &x, array<int, 1U> &i)
{
  static rtRunTimeErrorInfo v_emlrtRTEI{
      392,                 // lineNo
      "find_first_indices" // fName
  };
  int idx;
  int ii;
  int nx;
  boolean_T exitg1;
  nx = x.size(0);
  idx = 0;
  i.set_size(x.size(0));
  if (x.size(0) > 2147483646) {
    check_forloop_overflow_error();
  }
  ii = 0;
  exitg1 = false;
  while ((!exitg1) && (ii <= nx - 1)) {
    if (x[ii]) {
      idx++;
      i[idx - 1] = ii + 1;
      if (idx >= nx) {
        exitg1 = true;
      } else {
        ii++;
      }
    } else {
      ii++;
    }
  }
  if (idx > x.size(0)) {
    g_rtErrorWithMessageID(v_emlrtRTEI.fName, v_emlrtRTEI.lineNo);
  }
  if (x.size(0) == 1) {
    if (idx == 0) {
      i.set_size(0);
    }
  } else {
    int iv[2];
    if (idx < 1) {
      nx = 0;
    } else {
      nx = idx;
    }
    iv[0] = 1;
    iv[1] = nx;
    internal::indexShapeCheck(i.size(0), iv);
    i.set_size(nx);
  }
}

} // namespace coder

//
// File trailer for find.cpp
//
// [EOF]
//
