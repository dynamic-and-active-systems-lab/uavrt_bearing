//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: eye.cpp
//
// MATLAB Coder version            : 5.6
// C/C++ source code generated on  : 27-Jun-2023 16:44:57
//

// Include Files
#include "eye.h"
#include "bearing_data.h"
#include "bearing_rtwutil.h"
#include "bearing_types.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
//
// Arguments    : double varargin_1
//                ::coder::array<double, 2U> &b_I
// Return Type  : void
//
namespace coder {
void eye(double varargin_1, ::coder::array<double, 2U> &b_I)
{
  int loop_ub;
  int m_tmp_tmp_tmp;
  if ((varargin_1 != varargin_1) || std::isinf(varargin_1)) {
    bb_rtErrorWithMessageID(j_emlrtRTEI.fName, j_emlrtRTEI.lineNo);
  }
  m_tmp_tmp_tmp = static_cast<int>(varargin_1);
  b_I.set_size(m_tmp_tmp_tmp, m_tmp_tmp_tmp);
  loop_ub = static_cast<int>(varargin_1) * static_cast<int>(varargin_1);
  for (int i{0}; i < loop_ub; i++) {
    b_I[i] = 0.0;
  }
  if (static_cast<int>(varargin_1) > 0) {
    if (static_cast<int>(varargin_1) > 2147483646) {
      check_forloop_overflow_error();
    }
    for (loop_ub = 0; loop_ub < m_tmp_tmp_tmp; loop_ub++) {
      b_I[loop_ub + b_I.size(0) * loop_ub] = 1.0;
    }
  }
}

} // namespace coder

//
// File trailer for eye.cpp
//
// [EOF]
//
