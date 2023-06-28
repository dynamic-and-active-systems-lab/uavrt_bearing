//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: eml_mtimes_helper.cpp
//
// MATLAB Coder version            : 5.6
// C/C++ source code generated on  : 27-Jun-2023 16:44:57
//

// Include Files
#include "eml_mtimes_helper.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : coder::array<double, 1U> &in1
//                const coder::array<double, 1U> &in2
// Return Type  : void
//
void b_binary_expand_op(coder::array<double, 1U> &in1,
                        const coder::array<double, 1U> &in2)
{
  coder::array<double, 1U> r;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  if (in2.size(0) == 1) {
    loop_ub = in1.size(0);
  } else {
    loop_ub = in2.size(0);
  }
  r.set_size(loop_ub);
  stride_0_0 = (in1.size(0) != 1);
  stride_1_0 = (in2.size(0) != 1);
  for (int i{0}; i < loop_ub; i++) {
    r[i] = -2.0 * (in1[i * stride_0_0] - in2[i * stride_1_0]);
  }
  in1.set_size(r.size(0));
  loop_ub = r.size(0);
  for (int i{0}; i < loop_ub; i++) {
    in1[i] = r[i];
  }
}

//
// Arguments    : coder::array<double, 1U> &in1
//                const coder::array<double, 1U> &in2
// Return Type  : void
//
void binary_expand_op(coder::array<double, 1U> &in1,
                      const coder::array<double, 1U> &in2)
{
  coder::array<double, 1U> r;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  if (in2.size(0) == 1) {
    loop_ub = in1.size(0);
  } else {
    loop_ub = in2.size(0);
  }
  r.set_size(loop_ub);
  stride_0_0 = (in1.size(0) != 1);
  stride_1_0 = (in2.size(0) != 1);
  for (int i{0}; i < loop_ub; i++) {
    r[i] = 2.0 * (in1[i * stride_0_0] + in2[i * stride_1_0]);
  }
  in1.set_size(r.size(0));
  loop_ub = r.size(0);
  for (int i{0}; i < loop_ub; i++) {
    in1[i] = r[i];
  }
}

//
// File trailer for eml_mtimes_helper.cpp
//
// [EOF]
//
