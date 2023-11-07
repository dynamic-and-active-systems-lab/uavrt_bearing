//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: horzcatStructList.cpp
//
// MATLAB Coder version            : 23.2
// C/C++ source code generated on  : 07-Nov-2023 14:21:19
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
// Arguments    : const array<e_struct_T, 1U> &structure
//                array<double, 2U> &result
// Return Type  : void
//
namespace coder {
namespace internal {
void b_horzcatStructList(const array<e_struct_T, 1U> &structure,
                         array<double, 2U> &result)
{
  int n;
  int resultSize_idx_1;
  n = structure.size(0);
  if (structure.size(0) == 0) {
    resultSize_idx_1 = 0;
  } else {
    resultSize_idx_1 = structure.size(0);
    if (structure.size(0) > 2147483646) {
      check_forloop_overflow_error();
    }
  }
  result.set_size(1, resultSize_idx_1);
  for (resultSize_idx_1 = 0; resultSize_idx_1 < n; resultSize_idx_1++) {
    result[resultSize_idx_1] = structure[resultSize_idx_1].snrdB;
  }
}

//
// Arguments    : const array<struct_T, 1U> &structure
//                array<double, 2U> &result
// Return Type  : void
//
void b_horzcatStructList(const array<struct_T, 1U> &structure,
                         array<double, 2U> &result)
{
  int n;
  int resultSize_idx_1;
  n = structure.size(0);
  if (structure.size(0) == 0) {
    resultSize_idx_1 = 0;
  } else {
    resultSize_idx_1 = structure.size(0);
    if (structure.size(0) > 2147483646) {
      check_forloop_overflow_error();
    }
  }
  result.set_size(1, resultSize_idx_1);
  for (resultSize_idx_1 = 0; resultSize_idx_1 < n; resultSize_idx_1++) {
    result[resultSize_idx_1] = structure[resultSize_idx_1].longitude_deg;
  }
}

//
// Arguments    : const array<e_struct_T, 1U> &structure
//                array<double, 2U> &result
// Return Type  : void
//
void c_horzcatStructList(const array<e_struct_T, 1U> &structure,
                         array<double, 2U> &result)
{
  int n;
  int resultSize_idx_1;
  n = structure.size(0);
  if (structure.size(0) == 0) {
    resultSize_idx_1 = 0;
  } else {
    resultSize_idx_1 = structure.size(0);
    if (structure.size(0) > 2147483646) {
      check_forloop_overflow_error();
    }
  }
  result.set_size(1, resultSize_idx_1);
  for (resultSize_idx_1 = 0; resultSize_idx_1 < n; resultSize_idx_1++) {
    result[resultSize_idx_1] = structure[resultSize_idx_1].noisePSD;
  }
}

//
// Arguments    : const array<struct_T, 1U> &structure
//                array<double, 2U> &result
// Return Type  : void
//
void c_horzcatStructList(const array<struct_T, 1U> &structure,
                         array<double, 2U> &result)
{
  int n;
  int resultSize_idx_1;
  n = structure.size(0);
  if (structure.size(0) == 0) {
    resultSize_idx_1 = 0;
  } else {
    resultSize_idx_1 = structure.size(0);
    if (structure.size(0) > 2147483646) {
      check_forloop_overflow_error();
    }
  }
  result.set_size(1, resultSize_idx_1);
  for (resultSize_idx_1 = 0; resultSize_idx_1 < n; resultSize_idx_1++) {
    result[resultSize_idx_1] = structure[resultSize_idx_1].relative_altitude_m;
  }
}

//
// Arguments    : const array<e_struct_T, 1U> &structure
//                array<double, 2U> &result
// Return Type  : void
//
void d_horzcatStructList(const array<e_struct_T, 1U> &structure,
                         array<double, 2U> &result)
{
  int n;
  int resultSize_idx_1;
  n = structure.size(0);
  if (structure.size(0) == 0) {
    resultSize_idx_1 = 0;
  } else {
    resultSize_idx_1 = structure.size(0);
    if (structure.size(0) > 2147483646) {
      check_forloop_overflow_error();
    }
  }
  result.set_size(1, resultSize_idx_1);
  for (resultSize_idx_1 = 0; resultSize_idx_1 < n; resultSize_idx_1++) {
    result[resultSize_idx_1] = structure[resultSize_idx_1].antennaOffset;
  }
}

//
// Arguments    : const array<struct_T, 1U> &structure
//                array<double, 2U> &result
// Return Type  : void
//
void d_horzcatStructList(const array<struct_T, 1U> &structure,
                         array<double, 2U> &result)
{
  int n;
  int resultSize_idx_1;
  n = structure.size(0);
  if (structure.size(0) == 0) {
    resultSize_idx_1 = 0;
  } else {
    resultSize_idx_1 = structure.size(0);
    if (structure.size(0) > 2147483646) {
      check_forloop_overflow_error();
    }
  }
  result.set_size(1, resultSize_idx_1);
  for (resultSize_idx_1 = 0; resultSize_idx_1 < n; resultSize_idx_1++) {
    result[resultSize_idx_1] = structure[resultSize_idx_1].absolute_altitude_m;
  }
}

//
// Arguments    : const array<e_struct_T, 1U> &structure
//                array<double, 2U> &result
// Return Type  : void
//
void e_horzcatStructList(const array<e_struct_T, 1U> &structure,
                         array<double, 2U> &result)
{
  int n;
  int resultSize_idx_1;
  n = structure.size(0);
  if (structure.size(0) == 0) {
    resultSize_idx_1 = 0;
  } else {
    resultSize_idx_1 = structure.size(0);
    if (structure.size(0) > 2147483646) {
      check_forloop_overflow_error();
    }
  }
  result.set_size(1, resultSize_idx_1);
  for (resultSize_idx_1 = 0; resultSize_idx_1 < n; resultSize_idx_1++) {
    result[resultSize_idx_1] = structure[resultSize_idx_1].time;
  }
}

//
// Arguments    : const array<e_struct_T, 1U> &structure
//                array<double, 2U> &result
// Return Type  : void
//
void horzcatStructList(const array<e_struct_T, 1U> &structure,
                       array<double, 2U> &result)
{
  int n;
  int resultSize_idx_1;
  n = structure.size(0);
  if (structure.size(0) == 0) {
    resultSize_idx_1 = 0;
  } else {
    resultSize_idx_1 = structure.size(0);
    if (structure.size(0) > 2147483646) {
      check_forloop_overflow_error();
    }
  }
  result.set_size(1, resultSize_idx_1);
  for (resultSize_idx_1 = 0; resultSize_idx_1 < n; resultSize_idx_1++) {
    result[resultSize_idx_1] = structure[resultSize_idx_1].tagID;
  }
}

//
// Arguments    : const array<e_struct_T, 1U> &structure
//                array<d_struct_T, 2U> &result
// Return Type  : void
//
void horzcatStructList(const array<e_struct_T, 1U> &structure,
                       array<d_struct_T, 2U> &result)
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
// Arguments    : const array<d_struct_T, 1U> &structure
//                array<double, 2U> &result
// Return Type  : void
//
void horzcatStructList(const array<d_struct_T, 1U> &structure,
                       array<double, 2U> &result)
{
  int n;
  int resultSize_idx_1;
  n = structure.size(0);
  if (structure.size(0) == 0) {
    resultSize_idx_1 = 0;
  } else {
    resultSize_idx_1 = structure.size(0);
    if (structure.size(0) > 2147483646) {
      check_forloop_overflow_error();
    }
  }
  result.set_size(1, resultSize_idx_1);
  for (resultSize_idx_1 = 0; resultSize_idx_1 < n; resultSize_idx_1++) {
    result[resultSize_idx_1] = structure[resultSize_idx_1].yaw_deg;
  }
}

//
// Arguments    : const array<e_struct_T, 1U> &structure
//                array<struct_T, 2U> &result
// Return Type  : void
//
void horzcatStructList(const array<e_struct_T, 1U> &structure,
                       array<struct_T, 2U> &result)
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

//
// Arguments    : const array<struct_T, 1U> &structure
//                array<double, 2U> &result
// Return Type  : void
//
void horzcatStructList(const array<struct_T, 1U> &structure,
                       array<double, 2U> &result)
{
  int n;
  int resultSize_idx_1;
  n = structure.size(0);
  if (structure.size(0) == 0) {
    resultSize_idx_1 = 0;
  } else {
    resultSize_idx_1 = structure.size(0);
    if (structure.size(0) > 2147483646) {
      check_forloop_overflow_error();
    }
  }
  result.set_size(1, resultSize_idx_1);
  for (resultSize_idx_1 = 0; resultSize_idx_1 < n; resultSize_idx_1++) {
    result[resultSize_idx_1] = structure[resultSize_idx_1].latitude_deg;
  }
}

} // namespace internal
} // namespace coder

//
// File trailer for horzcatStructList.cpp
//
// [EOF]
//
