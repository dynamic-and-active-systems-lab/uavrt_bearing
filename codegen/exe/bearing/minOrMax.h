//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: minOrMax.h
//
// MATLAB Coder version            : 5.6
// C/C++ source code generated on  : 15-Aug-2023 14:31:29
//

#ifndef MINORMAX_H
#define MINORMAX_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
namespace internal {
double maximum(const ::coder::array<double, 1U> &x, int &idx);

double maximum(const ::coder::array<double, 2U> &x);

double minimum(const ::coder::array<double, 1U> &x);

double minimum(const ::coder::array<double, 2U> &x);

} // namespace internal
} // namespace coder

#endif
//
// File trailer for minOrMax.h
//
// [EOF]
//
