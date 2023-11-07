//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: applyToMultipleDims.cpp
//
// MATLAB Coder version            : 23.2
// C/C++ source code generated on  : 07-Nov-2023 14:21:19
//

// Include Files
#include "applyToMultipleDims.h"
#include "rt_nonfinite.h"
#include "sort.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : const array<double, 2U> &x
// Return Type  : double
//
namespace coder {
namespace internal {
double applyToMultipleDims(const array<double, 2U> &x)
{
  array<double, 1U> b_x;
  double varargout_1;
  if (x.size(1) == 0) {
    varargout_1 = rtNaN;
  } else {
    double mtmp;
    int ftmp;
    int i;
    int loop_ub;
    b_x.set_size(x.size(1));
    loop_ub = x.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_x[i] = x[i];
    }
    sort(b_x);
    varargout_1 = b_x[0];
    loop_ub = 1;
    mtmp = b_x[0];
    ftmp = 1;
    i = b_x.size(0);
    for (int k{0}; k <= i - 2; k++) {
      double d;
      d = b_x[k + 1];
      if (d == mtmp) {
        ftmp++;
      } else {
        if (ftmp > loop_ub) {
          varargout_1 = mtmp;
          loop_ub = ftmp;
        }
        mtmp = d;
        ftmp = 1;
      }
    }
    if (ftmp > loop_ub) {
      varargout_1 = mtmp;
    }
  }
  return varargout_1;
}

} // namespace internal
} // namespace coder

//
// File trailer for applyToMultipleDims.cpp
//
// [EOF]
//
