//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xrot.cpp
//
// MATLAB Coder version            : 5.6
// C/C++ source code generated on  : 02-Oct-2023 13:02:17
//

// Include Files
#include "xrot.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : double x[4]
//                int iy0
//                double c
//                double s
// Return Type  : void
//
namespace coder {
namespace internal {
namespace blas {
void xrot(double x[4], int iy0, double c, double s)
{
  double temp;
  double temp_tmp;
  temp_tmp = x[iy0 - 1];
  temp = c * x[0] + s * temp_tmp;
  x[iy0 - 1] = c * temp_tmp - s * x[0];
  x[0] = temp;
  temp = c * x[1] + s * x[iy0];
  x[iy0] = c * x[iy0] - s * x[1];
  x[1] = temp;
}

//
// Arguments    : int n
//                ::coder::array<double, 2U> &x
//                int ix0
//                int iy0
//                double c
//                double s
// Return Type  : void
//
void xrot(int n, ::coder::array<double, 2U> &x, int ix0, int iy0, double c,
          double s)
{
  if (n >= 1) {
    if (n > 2147483646) {
      check_forloop_overflow_error();
    }
    for (int k{0}; k < n; k++) {
      double b_temp_tmp;
      double temp_tmp;
      int b_temp_tmp_tmp;
      int temp_tmp_tmp;
      temp_tmp_tmp = (iy0 + k) - 1;
      temp_tmp = x[temp_tmp_tmp];
      b_temp_tmp_tmp = (ix0 + k) - 1;
      b_temp_tmp = x[b_temp_tmp_tmp];
      x[temp_tmp_tmp] = c * temp_tmp - s * b_temp_tmp;
      x[b_temp_tmp_tmp] = c * b_temp_tmp + s * temp_tmp;
    }
  }
}

} // namespace blas
} // namespace internal
} // namespace coder

//
// File trailer for xrot.cpp
//
// [EOF]
//
