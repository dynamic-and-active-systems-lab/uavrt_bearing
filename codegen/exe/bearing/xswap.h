//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xswap.h
//
// MATLAB Coder version            : 23.2
// C/C++ source code generated on  : 07-Nov-2023 14:21:19
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

void xswap(int n, array<double, 2U> &x, int iy0);

} // namespace blas
} // namespace internal
} // namespace coder

#endif
//
// File trailer for xswap.h
//
// [EOF]
//
