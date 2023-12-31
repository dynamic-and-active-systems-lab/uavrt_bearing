//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: mtimes.cpp
//
// MATLAB Coder version            : 23.2
// C/C++ source code generated on  : 07-Nov-2023 14:21:19
//

// Include Files
#include "mtimes.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : const array<double, 2U> &A
//                const array<double, 2U> &B
//                array<double, 2U> &C
// Return Type  : void
//
namespace coder {
namespace internal {
namespace blas {
void mtimes(const array<double, 2U> &A, const array<double, 2U> &B,
            array<double, 2U> &C)
{
  int inner;
  int mc;
  boolean_T b_overflow;
  boolean_T overflow;
  mc = A.size(0);
  inner = A.size(1);
  C.set_size(A.size(0), 2);
  overflow = (A.size(0) > 2147483646);
  b_overflow = (A.size(1) > 2147483646);
  for (int j{0}; j < 2; j++) {
    int boffset;
    int coffset;
    coffset = j * mc;
    boffset = j * B.size(0);
    if (overflow) {
      check_forloop_overflow_error();
    }
    for (int i{0}; i < mc; i++) {
      C[coffset + i] = 0.0;
    }
    if (b_overflow) {
      check_forloop_overflow_error();
    }
    for (int k{0}; k < inner; k++) {
      double bkj;
      int aoffset;
      aoffset = k * A.size(0);
      bkj = B[boffset + k];
      if (mc > 2147483646) {
        check_forloop_overflow_error();
      }
      for (int i{0}; i < mc; i++) {
        int b_i;
        b_i = coffset + i;
        C[b_i] = C[b_i] + A[aoffset + i] * bkj;
      }
    }
  }
}

//
// Arguments    : const array<double, 2U> &A
//                double C[2]
// Return Type  : void
//
void mtimes(const array<double, 2U> &A, double C[2])
{
  int inner;
  inner = A.size(1);
  C[0] = 0.0;
  C[1] = 0.0;
  if (A.size(1) > 2147483646) {
    check_forloop_overflow_error();
  }
  for (int k{0}; k < inner; k++) {
    int aoffset;
    aoffset = k << 1;
    C[0] += A[aoffset];
    C[1] += A[aoffset + 1];
  }
}

} // namespace blas
} // namespace internal
} // namespace coder

//
// File trailer for mtimes.cpp
//
// [EOF]
//
