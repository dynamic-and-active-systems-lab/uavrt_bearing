//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: wrapTo360.cpp
//
// MATLAB Coder version            : 5.6
// C/C++ source code generated on  : 30-Jun-2023 13:13:27
//

// Include Files
#include "wrapTo360.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : coder::array<boolean_T, 1U> &in1
//                const coder::array<boolean_T, 1U> &in2
//                const coder::array<boolean_T, 1U> &in3
// Return Type  : void
//
void b_and(coder::array<boolean_T, 1U> &in1,
           const coder::array<boolean_T, 1U> &in2,
           const coder::array<boolean_T, 1U> &in3)
{
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  if (in3.size(0) == 1) {
    loop_ub = in2.size(0);
  } else {
    loop_ub = in3.size(0);
  }
  in1.set_size(loop_ub);
  stride_0_0 = (in2.size(0) != 1);
  stride_1_0 = (in3.size(0) != 1);
  for (int i{0}; i < loop_ub; i++) {
    in1[i] = (in2[i * stride_0_0] && in3[i * stride_1_0]);
  }
}

//
// File trailer for wrapTo360.cpp
//
// [EOF]
//
