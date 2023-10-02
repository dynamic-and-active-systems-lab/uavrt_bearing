//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xscal.h
//
// MATLAB Coder version            : 5.6
// C/C++ source code generated on  : 02-Oct-2023 13:02:17
//

#ifndef XSCAL_H
#define XSCAL_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
namespace internal {
namespace blas {
void xscal(int n, double a, ::coder::array<double, 2U> &x, int ix0);

void xscal(double a, double x[4], int ix0);

} // namespace blas
} // namespace internal
} // namespace coder

#endif
//
// File trailer for xscal.h
//
// [EOF]
//
