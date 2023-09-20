//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: horzcatStructList.cpp
//
// MATLAB Coder version            : 5.6
// C/C++ source code generated on  : 20-Sep-2023 13:03:40
//

// Include Files
#include "horzcatStructList.h"
#include "bearing_internal_types.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "coder_bounded_array.h"

// Function Definitions
//
// Arguments    : const ::coder::array<e_struct_T, 1U> &structure
//                ::coder::array<double, 2U> &result
// Return Type  : void
//
namespace coder {
namespace internal {
void horzcatStructList(const ::coder::array<e_struct_T, 1U> &structure,
                       ::coder::array<double, 2U> &result)
{
  int i;
  int n;
  n = structure.size(0);
  if (structure.size(0) == 0) {
    i = 0;
  } else {
    i = structure.size(0);
  }
  result.set_size(1, i);
  if (structure.size(0) > 2147483646) {
    check_forloop_overflow_error();
  }
  for (i = 0; i < n; i++) {
    result[i] = structure[i].noisePSD;
  }
}

//
// Arguments    : const ::coder::array<e_struct_T, 1U> &structure
//                ::coder::array<d_struct_T, 2U> &result
// Return Type  : void
//
void horzcatStructList(const ::coder::array<e_struct_T, 1U> &structure,
                       ::coder::array<d_struct_T, 2U> &result)
{
  int n;
  int resultRowSize;
  int resultSize_idx_0;
  n = structure.size(0);
  if (structure.size(0) == 0) {
    resultSize_idx_0 = 0;
    resultRowSize = 0;
  } else {
    resultSize_idx_0 = 1;
    resultRowSize = 1;
    if (structure.size(0) > 2147483646) {
      check_forloop_overflow_error();
    }
    for (int j{2}; j <= n; j++) {
      resultRowSize++;
    }
  }
  result.set_size(resultSize_idx_0, resultRowSize);
  for (resultSize_idx_0 = 0; resultSize_idx_0 < n; resultSize_idx_0++) {
    result[result.size(0) * resultSize_idx_0] =
        structure[resultSize_idx_0].euler.data[0];
  }
}

//
// Arguments    : const ::coder::array<e_struct_T, 1U> &structure
//                ::coder::array<struct_T, 2U> &result
// Return Type  : void
//
void horzcatStructList(const ::coder::array<e_struct_T, 1U> &structure,
                       ::coder::array<struct_T, 2U> &result)
{
  int n;
  int resultRowSize;
  int resultSize_idx_0;
  n = structure.size(0);
  if (structure.size(0) == 0) {
    resultSize_idx_0 = 0;
    resultRowSize = 0;
  } else {
    resultSize_idx_0 = 1;
    resultRowSize = 1;
    if (structure.size(0) > 2147483646) {
      check_forloop_overflow_error();
    }
    for (int j{2}; j <= n; j++) {
      resultRowSize++;
    }
  }
  result.set_size(resultSize_idx_0, resultRowSize);
  for (resultSize_idx_0 = 0; resultSize_idx_0 < n; resultSize_idx_0++) {
    result[result.size(0) * resultSize_idx_0] =
        structure[resultSize_idx_0].position.data[0];
  }
}

} // namespace internal
} // namespace coder

//
// File trailer for horzcatStructList.cpp
//
// [EOF]
//
