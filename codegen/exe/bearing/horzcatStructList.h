//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: horzcatStructList.h
//
// MATLAB Coder version            : 5.6
// C/C++ source code generated on  : 20-Sep-2023 13:03:40
//

#ifndef HORZCATSTRUCTLIST_H
#define HORZCATSTRUCTLIST_H

// Include Files
#include "bearing_internal_types.h"
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
namespace internal {
void horzcatStructList(const ::coder::array<e_struct_T, 1U> &structure,
                       ::coder::array<double, 2U> &result);

void horzcatStructList(const ::coder::array<e_struct_T, 1U> &structure,
                       ::coder::array<d_struct_T, 2U> &result);

void horzcatStructList(const ::coder::array<e_struct_T, 1U> &structure,
                       ::coder::array<struct_T, 2U> &result);

} // namespace internal
} // namespace coder

#endif
//
// File trailer for horzcatStructList.h
//
// [EOF]
//
