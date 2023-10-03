//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: svd.cpp
//
// MATLAB Coder version            : 5.6
// C/C++ source code generated on  : 03-Oct-2023 08:03:05
//

// Include Files
#include "svd.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "svd1.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
//
// Arguments    : const ::coder::array<double, 2U> &A
//                ::coder::array<double, 2U> &U
//                ::coder::array<double, 2U> &S
//                double V[4]
// Return Type  : void
//
namespace coder {
void svd(const ::coder::array<double, 2U> &A, ::coder::array<double, 2U> &U,
         ::coder::array<double, 2U> &S, double V[4])
{
  array<double, 2U> U1;
  array<double, 2U> r;
  double V1[4];
  double s_data[2];
  int i;
  int k;
  int nx;
  boolean_T p;
  nx = A.size(0) << 1;
  p = true;
  if (nx > 2147483646) {
    check_forloop_overflow_error();
  }
  for (k = 0; k < nx; k++) {
    if ((!p) || (std::isinf(A[k]) || std::isnan(A[k]))) {
      p = false;
    }
  }
  if (p) {
    k = internal::b_svd(A, U, s_data, V);
  } else {
    r.set_size(A.size(0), 2);
    nx = A.size(0) << 1;
    for (i = 0; i < nx; i++) {
      r[i] = 0.0;
    }
    k = internal::b_svd(r, U1, s_data, V1);
    U.set_size(U1.size(0), U1.size(1));
    nx = U1.size(0) * U1.size(1);
    for (i = 0; i < nx; i++) {
      U[i] = rtNaN;
    }
    for (i = 0; i < k; i++) {
      s_data[i] = rtNaN;
    }
    V[0] = rtNaN;
    V[1] = rtNaN;
    V[2] = rtNaN;
    V[3] = rtNaN;
  }
  S.set_size(U.size(1), 2);
  nx = U.size(1) << 1;
  for (i = 0; i < nx; i++) {
    S[i] = 0.0;
  }
  i = k - 1;
  for (k = 0; k <= i; k++) {
    S[k + S.size(0) * k] = s_data[k];
  }
}

} // namespace coder

//
// File trailer for svd.cpp
//
// [EOF]
//
