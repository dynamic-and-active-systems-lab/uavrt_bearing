//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xscal.cpp
//
// MATLAB Coder version            : 23.2
// C/C++ source code generated on  : 07-Nov-2023 14:21:19
//

// Include Files
#include "xscal.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : int n
//                double a
//                array<double, 2U> &x
//                int ix0
// Return Type  : void
//
namespace coder {
namespace internal {
namespace blas {
void xscal(int n, double a, array<double, 2U> &x, int ix0)
{
  int b;
  b = (ix0 + n) - 1;
  if ((ix0 <= b) && (b > 2147483646)) {
    check_forloop_overflow_error();
  }
  for (int k{ix0}; k <= b; k++) {
    x[k - 1] = a * x[k - 1];
  }
}

//
// Arguments    : double x[4]
//                int ix0
// Return Type  : void
//
void xscal(double x[4], int ix0)
{
  int b;
  b = ix0 + 1;
  if ((ix0 <= ix0 + 1) && (ix0 + 1 > 2147483646)) {
    check_forloop_overflow_error();
  }
  for (int k{ix0}; k <= b; k++) {
    x[k - 1] = -x[k - 1];
  }
}

} // namespace blas
} // namespace internal
} // namespace coder

//
// File trailer for xscal.cpp
//
// [EOF]
//
