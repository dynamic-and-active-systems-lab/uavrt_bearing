//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: repmat.cpp
//
// MATLAB Coder version            : 5.6
// C/C++ source code generated on  : 03-Oct-2023 08:03:05
//

// Include Files
#include "repmat.h"
#include "bearing_data.h"
#include "bearing_internal_types.h"
#include "bearing_rtwutil.h"
#include "bearing_types.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
//
// Arguments    : const d_struct_T a_data[]
//                double varargin_1
//                ::coder::array<d_struct_T, 2U> &b
// Return Type  : void
//
namespace coder {
void repmat(const d_struct_T a_data[], double varargin_1,
            ::coder::array<d_struct_T, 2U> &b)
{
  int i;
  if ((varargin_1 != varargin_1) || std::isinf(varargin_1)) {
    ab_rtErrorWithMessageID(n_emlrtRTEI.fName, n_emlrtRTEI.lineNo);
  }
  i = static_cast<int>(varargin_1);
  b.set_size(i, 1);
  for (int itilerow{0}; itilerow < i; itilerow++) {
    b[itilerow] = a_data[0];
  }
  if (static_cast<int>(varargin_1) > 2147483646) {
    check_forloop_overflow_error();
  }
}

} // namespace coder

//
// File trailer for repmat.cpp
//
// [EOF]
//
