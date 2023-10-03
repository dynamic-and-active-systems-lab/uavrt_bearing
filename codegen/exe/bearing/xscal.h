//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xscal.h
//
// MATLAB Coder version            : 23.2
// C/C++ source code generated on  : 03-Oct-2023 13:40:05
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
void xscal(int n, double a, array<double, 2U> &x, int ix0);

void xscal(double x[4], int ix0);

} // namespace blas
} // namespace internal
} // namespace coder

#endif
//
// File trailer for xscal.h
//
// [EOF]
//
