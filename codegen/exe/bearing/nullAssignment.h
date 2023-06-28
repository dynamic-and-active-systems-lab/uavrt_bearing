//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: nullAssignment.h
//
// MATLAB Coder version            : 5.6
// C/C++ source code generated on  : 27-Jun-2023 16:44:57
//

#ifndef NULLASSIGNMENT_H
#define NULLASSIGNMENT_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
namespace internal {
void b_nullAssignment(::coder::array<double, 2U> &x,
                      const ::coder::array<int, 2U> &idx);

void nullAssignment(::coder::array<double, 2U> &x,
                    const ::coder::array<int, 2U> &idx);

void nullAssignment(::coder::array<double, 1U> &x,
                    const ::coder::array<int, 2U> &idx);

void nullAssignment(::coder::array<double, 2U> &x,
                    const ::coder::array<int, 1U> &idx);

} // namespace internal
} // namespace coder

#endif
//
// File trailer for nullAssignment.h
//
// [EOF]
//