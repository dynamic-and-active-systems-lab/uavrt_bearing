//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xswap.h
//
// MATLAB Coder version            : 5.6
// C/C++ source code generated on  : 20-Sep-2023 13:03:40
//

#ifndef XSWAP_H
#define XSWAP_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
namespace internal {
namespace blas {
void xswap(double x[4]);

void xswap(int n, ::coder::array<double, 2U> &x, int iy0);

} // namespace blas
} // namespace internal
} // namespace coder

#endif
//
// File trailer for xswap.h
//
// [EOF]
//
