//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: nullAssignment.h
//
// MATLAB Coder version            : 23.2
// C/C++ source code generated on  : 03-Oct-2023 13:40:05
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
void b_nullAssignment(array<double, 2U> &x, const array<int, 2U> &idx);

void nullAssignment(array<double, 2U> &x, const array<int, 2U> &idx);

void nullAssignment(array<double, 1U> &x, const array<int, 2U> &idx);

void nullAssignment(array<double, 2U> &x, const array<int, 1U> &idx);

} // namespace internal
} // namespace coder

#endif
//
// File trailer for nullAssignment.h
//
// [EOF]
//
