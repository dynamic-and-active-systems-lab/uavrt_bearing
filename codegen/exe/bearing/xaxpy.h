//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xaxpy.h
//
// MATLAB Coder version            : 5.6
// C/C++ source code generated on  : 30-Jun-2023 15:05:26
//

#ifndef XAXPY_H
#define XAXPY_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
namespace internal {
namespace blas {
void xaxpy(int n, double a, int ix0, ::coder::array<double, 2U> &y, int iy0);

}
} // namespace internal
} // namespace coder

#endif
//
// File trailer for xaxpy.h
//
// [EOF]
//
