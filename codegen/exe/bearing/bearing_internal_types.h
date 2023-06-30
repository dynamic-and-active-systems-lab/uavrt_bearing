//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: bearing_internal_types.h
//
// MATLAB Coder version            : 5.6
// C/C++ source code generated on  : 30-Jun-2023 15:05:26
//

#ifndef BEARING_INTERNAL_TYPES_H
#define BEARING_INTERNAL_TYPES_H

// Include Files
#include "bearing_types.h"
#include "rtwtypes.h"
#include "coder_array.h"
#include "coder_bounded_array.h"

// Type Definitions
struct struct_T {
  double latitude_deg;
  double longitude_deg;
  double absolute_altitude_m;
  double relative_altitude_m;
};

struct b_struct_T {
  double fid;
};

namespace coder {
namespace matlab {
namespace internal {
namespace coder {
namespace tabular {
enum class Continuity : int
{
  unset = 0, // Default value
  continuous,
  step,
  event
};

}
} // namespace coder
} // namespace internal
} // namespace matlab
} // namespace coder
struct cell_wrap_4 {
  coder::array<char, 2U> f1;
};

struct cell_5 {
  coder::array<unsigned int, 1U> f1;
  coder::array<cell_wrap_4, 1U> f2;
  coder::array<double, 1U> f3;
  coder::array<double, 1U> f4;
  coder::array<double, 1U> f5;
  coder::array<double, 1U> f6;
  coder::array<double, 1U> f7;
  coder::array<double, 1U> f8;
  coder::array<double, 1U> f9;
  coder::array<double, 1U> f10;
};

struct cell_6 {
  unsigned int f1;
  cell_wrap_4 f2[1];
  double f3;
  double f4;
  double f5;
  double f6;
  double f7;
  double f8;
  double f9;
  double f10;
};

struct cell_wrap_3 {
  coder::empty_bounded_array<char, 2U> f1;
};

struct c_struct_T {
  coder::empty_bounded_array<char, 2U> Description;
};

struct d_struct_T {
  double yaw_deg;
};

struct e_struct_T {
  coder::bounded_array<struct_T, 1U, 2U> position;
  coder::bounded_array<d_struct_T, 1U, 2U> euler;
  double time;
  double strength;
  double tagID;
};

class empty {};

#endif
//
// File trailer for bearing_internal_types.h
//
// [EOF]
//
