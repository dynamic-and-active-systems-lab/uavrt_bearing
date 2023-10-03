//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xswap.cpp
//
// MATLAB Coder version            : 5.6
// C/C++ source code generated on  : 03-Oct-2023 08:03:05
//

// Include Files
#include "xswap.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : double x[4]
// Return Type  : void
//
namespace coder {
namespace internal {
namespace blas {
void xswap(double x[4])
{
  double temp;
  temp = x[0];
  x[0] = x[2];
  x[2] = temp;
  temp = x[1];
  x[1] = x[3];
  x[3] = temp;
}

//
// Arguments    : int n
//                ::coder::array<double, 2U> &x
//                int iy0
// Return Type  : void
//
void xswap(int n, ::coder::array<double, 2U> &x, int iy0)
{
  if (n > 2147483646) {
    check_forloop_overflow_error();
  }
  for (int k{0}; k < n; k++) {
    double temp;
    int i;
    temp = x[k];
    i = (iy0 + k) - 1;
    x[k] = x[i];
    x[i] = temp;
  }
}

} // namespace blas
} // namespace internal
} // namespace coder

//
// File trailer for xswap.cpp
//
// [EOF]
//
