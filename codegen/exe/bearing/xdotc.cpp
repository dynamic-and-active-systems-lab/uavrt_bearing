//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xdotc.cpp
//
// MATLAB Coder version            : 23.2
// C/C++ source code generated on  : 03-Oct-2023 13:40:05
//

// Include Files
#include "xdotc.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : int n
//                const array<double, 2U> &x
//                int ix0
//                const array<double, 2U> &y
//                int iy0
// Return Type  : double
//
namespace coder {
namespace internal {
namespace blas {
double xdotc(int n, const array<double, 2U> &x, int ix0,
             const array<double, 2U> &y, int iy0)
{
  double d;
  d = 0.0;
  if (n >= 1) {
    if (n > 2147483646) {
      check_forloop_overflow_error();
    }
    for (int k{0}; k < n; k++) {
      d += x[(ix0 + k) - 1] * y[(iy0 + k) - 1];
    }
  }
  return d;
}

} // namespace blas
} // namespace internal
} // namespace coder

//
// File trailer for xdotc.cpp
//
// [EOF]
//
