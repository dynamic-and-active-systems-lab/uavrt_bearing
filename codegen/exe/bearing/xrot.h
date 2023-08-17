//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xrot.h
//
// MATLAB Coder version            : 5.6
// C/C++ source code generated on  : 17-Aug-2023 13:24:38
//

#ifndef XROT_H
#define XROT_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
namespace internal {
namespace blas {
void xrot(double x[4], int iy0, double c, double s);

void xrot(int n, ::coder::array<double, 2U> &x, int ix0, int iy0, double c,
          double s);

} // namespace blas
} // namespace internal
} // namespace coder

#endif
//
// File trailer for xrot.h
//
// [EOF]
//
