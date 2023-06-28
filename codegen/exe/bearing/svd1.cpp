//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: svd1.cpp
//
// MATLAB Coder version            : 5.6
// C/C++ source code generated on  : 27-Jun-2023 16:44:57
//

// Include Files
#include "svd1.h"
#include "rt_nonfinite.h"
#include "xzsvdc.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : const ::coder::array<double, 2U> &A
//                ::coder::array<double, 2U> &U
//                double s_data[]
//                double V[4]
// Return Type  : int
//
namespace coder {
namespace internal {
int b_svd(const ::coder::array<double, 2U> &A, ::coder::array<double, 2U> &U,
          double s_data[], double V[4])
{
  array<double, 2U> b_A;
  int s_size;
  if (A.size(0) == 0) {
    U.set_size(0, 0);
    s_size = 0;
    V[0] = 1.0;
    V[1] = 0.0;
    V[2] = 0.0;
    V[3] = 1.0;
  } else {
    int loop_ub;
    b_A.set_size(A.size(0), 2);
    loop_ub = A.size(0) * A.size(1) - 1;
    for (int i{0}; i <= loop_ub; i++) {
      b_A[i] = A[i];
    }
    s_size = reflapack::xzsvdc(b_A, U, s_data, V);
  }
  return s_size;
}

} // namespace internal
} // namespace coder

//
// File trailer for svd1.cpp
//
// [EOF]
//
