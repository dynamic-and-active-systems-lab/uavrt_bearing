//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: any1.cpp
//
// MATLAB Coder version            : 5.6
// C/C++ source code generated on  : 30-Jun-2023 13:13:27
//

// Include Files
#include "any1.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : const ::coder::array<boolean_T, 1U> &x
// Return Type  : boolean_T
//
namespace coder {
boolean_T any(const ::coder::array<boolean_T, 1U> &x)
{
  int ix;
  boolean_T exitg1;
  boolean_T y;
  y = false;
  if (x.size(0) > 2147483646) {
    check_forloop_overflow_error();
  }
  ix = 1;
  exitg1 = false;
  while ((!exitg1) && (ix <= x.size(0))) {
    if (x[ix - 1]) {
      y = true;
      exitg1 = true;
    } else {
      ix++;
    }
  }
  return y;
}

} // namespace coder

//
// File trailer for any1.cpp
//
// [EOF]
//
