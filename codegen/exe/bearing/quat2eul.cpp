//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: quat2eul.cpp
//
// MATLAB Coder version            : 5.6
// C/C++ source code generated on  : 27-Jun-2023 16:44:57
//

// Include Files
#include "quat2eul.h"
#include "bearing_data.h"
#include "bearing_rtwutil.h"
#include "bearing_types.h"
#include "eml_int_forloop_overflow_check.h"
#include "eml_mtimes_helper.h"
#include "ixfun.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>
#include <sstream>
#include <stdexcept>
#include <string>

// Function Declarations
static void b_or(coder::array<boolean_T, 1U> &in1,
                 const coder::array<boolean_T, 1U> &in2,
                 const coder::array<boolean_T, 1U> &in3);

static void j_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

static void minus(coder::array<double, 1U> &in1,
                  const coder::array<double, 1U> &in2);

static void plus(coder::array<double, 1U> &in1,
                 const coder::array<double, 1U> &in2);

static void rtErrorWithMessageID(const char *r, const char *aFcnName,
                                 int aLineNum);

// Function Definitions
//
// Arguments    : coder::array<boolean_T, 1U> &in1
//                const coder::array<boolean_T, 1U> &in2
//                const coder::array<boolean_T, 1U> &in3
// Return Type  : void
//
static void b_or(coder::array<boolean_T, 1U> &in1,
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
    in1[i] = (in2[i * stride_0_0] || in3[i * stride_1_0]);
  }
}

//
// Arguments    : const char *aFcnName
//                int aLineNum
// Return Type  : void
//
static void j_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::stringstream outStream;
  outStream << "Non-singleton dimensions of the two input arrays must match "
               "each other.";
  outStream << "\n";
  ((((outStream << "Error in ") << aFcnName) << " (line ") << aLineNum) << ")";
  throw std::runtime_error(outStream.str());
}

//
// Arguments    : coder::array<double, 1U> &in1
//                const coder::array<double, 1U> &in2
// Return Type  : void
//
static void minus(coder::array<double, 1U> &in1,
                  const coder::array<double, 1U> &in2)
{
  coder::array<double, 1U> b_in1;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  if (in2.size(0) == 1) {
    loop_ub = in1.size(0);
  } else {
    loop_ub = in2.size(0);
  }
  b_in1.set_size(loop_ub);
  stride_0_0 = (in1.size(0) != 1);
  stride_1_0 = (in2.size(0) != 1);
  for (int i{0}; i < loop_ub; i++) {
    b_in1[i] = in1[i * stride_0_0] - in2[i * stride_1_0];
  }
  in1.set_size(b_in1.size(0));
  loop_ub = b_in1.size(0);
  for (int i{0}; i < loop_ub; i++) {
    in1[i] = b_in1[i];
  }
}

//
// Arguments    : coder::array<double, 1U> &in1
//                const coder::array<double, 1U> &in2
// Return Type  : void
//
static void plus(coder::array<double, 1U> &in1,
                 const coder::array<double, 1U> &in2)
{
  coder::array<double, 1U> b_in1;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  if (in2.size(0) == 1) {
    loop_ub = in1.size(0);
  } else {
    loop_ub = in2.size(0);
  }
  b_in1.set_size(loop_ub);
  stride_0_0 = (in1.size(0) != 1);
  stride_1_0 = (in2.size(0) != 1);
  for (int i{0}; i < loop_ub; i++) {
    b_in1[i] = in1[i * stride_0_0] + in2[i * stride_1_0];
  }
  in1.set_size(b_in1.size(0));
  loop_ub = b_in1.size(0);
  for (int i{0}; i < loop_ub; i++) {
    in1[i] = b_in1[i];
  }
}

//
// Arguments    : const char *r
//                const char *aFcnName
//                int aLineNum
// Return Type  : void
//
static void rtErrorWithMessageID(const char *r, const char *aFcnName,
                                 int aLineNum)
{
  std::stringstream outStream;
  ((outStream << "Expected ") << r) << " to be nonempty.";
  outStream << "\n";
  ((((outStream << "Error in ") << aFcnName) << " (line ") << aLineNum) << ")";
  throw std::runtime_error(outStream.str());
}

//
// Arguments    : ::coder::array<double, 2U> &q
//                ::coder::array<double, 2U> &eul
// Return Type  : void
//
namespace coder {
void quat2eul(::coder::array<double, 2U> &q, ::coder::array<double, 2U> &eul)
{
  static rtBoundsCheckInfo b_emlrtBCI{
      -1,         // iFirst
      -1,         // iLast
      71,         // lineNo
      19,         // colNo
      "",         // aName
      "quat2eul", // fName
      "/Applications/MATLAB_R2023a.app/toolbox/shared/robotics/robotutils/"
      "quat2eul.m", // pName
      0             // checkKind
  };
  static rtBoundsCheckInfo c_emlrtBCI{
      -1,         // iFirst
      -1,         // iLast
      72,         // lineNo
      19,         // colNo
      "",         // aName
      "quat2eul", // fName
      "/Applications/MATLAB_R2023a.app/toolbox/shared/robotics/robotutils/"
      "quat2eul.m", // pName
      0             // checkKind
  };
  static rtBoundsCheckInfo d_emlrtBCI{
      -1,         // iFirst
      -1,         // iLast
      78,         // lineNo
      40,         // colNo
      "",         // aName
      "quat2eul", // fName
      "/Applications/MATLAB_R2023a.app/toolbox/shared/robotics/robotutils/"
      "quat2eul.m", // pName
      0             // checkKind
  };
  static rtBoundsCheckInfo e_emlrtBCI{
      -1,         // iFirst
      -1,         // iLast
      78,         // lineNo
      65,         // colNo
      "",         // aName
      "quat2eul", // fName
      "/Applications/MATLAB_R2023a.app/toolbox/shared/robotics/robotutils/"
      "quat2eul.m", // pName
      0             // checkKind
  };
  static rtBoundsCheckInfo f_emlrtBCI{
      -1,         // iFirst
      -1,         // iLast
      78,         // lineNo
      77,         // colNo
      "",         // aName
      "quat2eul", // fName
      "/Applications/MATLAB_R2023a.app/toolbox/shared/robotics/robotutils/"
      "quat2eul.m", // pName
      0             // checkKind
  };
  static rtBoundsCheckInfo g_emlrtBCI{
      -1,         // iFirst
      -1,         // iLast
      78,         // lineNo
      13,         // colNo
      "",         // aName
      "quat2eul", // fName
      "/Applications/MATLAB_R2023a.app/toolbox/shared/robotics/robotutils/"
      "quat2eul.m", // pName
      0             // checkKind
  };
  static rtBoundsCheckInfo h_emlrtBCI{
      -1,         // iFirst
      -1,         // iLast
      79,         // lineNo
      9,          // colNo
      "",         // aName
      "quat2eul", // fName
      "/Applications/MATLAB_R2023a.app/toolbox/shared/robotics/robotutils/"
      "quat2eul.m", // pName
      0             // checkKind
  };
  static rtEqualityCheckInfo b_emlrtECI{
      1,          // nDims
      75,         // lineNo
      43,         // colNo
      "quat2eul", // fName
      "/Applications/MATLAB_R2023a.app/toolbox/shared/robotics/robotutils/"
      "quat2eul.m" // pName
  };
  static rtEqualityCheckInfo c_emlrtECI{
      1,          // nDims
      77,         // lineNo
      43,         // colNo
      "quat2eul", // fName
      "/Applications/MATLAB_R2023a.app/toolbox/shared/robotics/robotutils/"
      "quat2eul.m" // pName
  };
  static rtEqualityCheckInfo d_emlrtECI{
      1,          // nDims
      78,         // lineNo
      24,         // colNo
      "quat2eul", // fName
      "/Applications/MATLAB_R2023a.app/toolbox/shared/robotics/robotutils/"
      "quat2eul.m" // pName
  };
  static rtEqualityCheckInfo e_emlrtECI{
      -1,         // nDims
      78,         // lineNo
      9,          // colNo
      "quat2eul", // fName
      "/Applications/MATLAB_R2023a.app/toolbox/shared/robotics/robotutils/"
      "quat2eul.m" // pName
  };
  static rtEqualityCheckInfo emlrtECI{
      1,          // nDims
      73,         // lineNo
      16,         // colNo
      "quat2eul", // fName
      "/Applications/MATLAB_R2023a.app/toolbox/shared/robotics/robotutils/"
      "quat2eul.m" // pName
  };
  static rtRunTimeErrorInfo r_emlrtRTEI{
      13,                // lineNo
      "validatenonempty" // fName
  };
  static rtRunTimeErrorInfo s_emlrtRTEI{
      14,    // lineNo
      "asin" // fName
  };
  static rtRunTimeErrorInfo t_emlrtRTEI{
      53,      // lineNo
      "bsxfun" // fName
  };
  array<double, 2U> matrix;
  array<double, 2U> y;
  array<double, 1U> aSinInput;
  array<double, 1U> b_varargin_1;
  array<double, 1U> b_x;
  array<double, 1U> b_y;
  array<double, 1U> c_y;
  array<double, 1U> r;
  array<double, 1U> varargin_2;
  array<double, 1U> varargin_3;
  array<double, 1U> x;
  array<int, 1U> r2;
  array<boolean_T, 1U> mask1;
  array<boolean_T, 1U> mask2;
  array<boolean_T, 1U> r1;
  double b_varargin_2;
  double varargin_1;
  int csz_idx_0;
  int i;
  int vstride;
  int xoffset;
  boolean_T p;
  if (q.size(0) == 0) {
    rtErrorWithMessageID("q", r_emlrtRTEI.fName, r_emlrtRTEI.lineNo);
  }
  matrix.set_size(q.size(0), 4);
  vstride = q.size(0) << 2;
  for (i = 0; i < vstride; i++) {
    matrix[i] = q[i];
  }
  y.set_size(q.size(0), 4);
  for (i = 0; i < vstride; i++) {
    varargin_1 = q[i];
    y[i] = varargin_1 * varargin_1;
  }
  vstride = y.size(0);
  b_y.set_size(y.size(0));
  if (y.size(0) > 2147483646) {
    check_forloop_overflow_error();
  }
  for (int xj{0}; xj < vstride; xj++) {
    b_y[xj] = y[xj];
  }
  for (int k{0}; k < 3; k++) {
    xoffset = (k + 1) * vstride;
    for (int xj{0}; xj < vstride; xj++) {
      b_y[xj] = b_y[xj] + y[xoffset + xj];
    }
  }
  p = false;
  i = b_y.size(0);
  for (int k{0}; k < i; k++) {
    if (p || (b_y[k] < 0.0)) {
      p = true;
    }
  }
  if (p) {
    b_rtErrorWithMessageID("sqrt", i_emlrtRTEI.fName, i_emlrtRTEI.lineNo);
  }
  vstride = b_y.size(0);
  if (b_y.size(0) > 2147483646) {
    check_forloop_overflow_error();
  }
  for (int k{0}; k < vstride; k++) {
    b_y[k] = std::sqrt(b_y[k]);
  }
  vstride = b_y.size(0);
  for (i = 0; i < vstride; i++) {
    b_y[i] = 1.0 / b_y[i];
  }
  if (b_y.size(0) == 1) {
    csz_idx_0 = q.size(0);
  } else if (q.size(0) == 1) {
    csz_idx_0 = b_y.size(0);
  } else if (q.size(0) == b_y.size(0)) {
    csz_idx_0 = q.size(0);
  } else {
    j_rtErrorWithMessageID(t_emlrtRTEI.fName, t_emlrtRTEI.lineNo);
  }
  q.set_size(csz_idx_0, 4);
  vstride = (matrix.size(0) != 1);
  for (int k{0}; k < 4; k++) {
    i = q.size(0) - 1;
    for (int xj{0}; xj <= i; xj++) {
      xoffset = vstride * xj;
      q[xj + q.size(0) * k] =
          matrix[xoffset + matrix.size(0) * k] * b_y[xoffset];
    }
  }
  aSinInput.set_size(q.size(0));
  vstride = q.size(0);
  varargin_3.set_size(q.size(0));
  for (i = 0; i < vstride; i++) {
    aSinInput[i] = q[i + q.size(0)] * q[i + q.size(0) * 3];
    varargin_3[i] = q[i] * q[i + q.size(0) * 2];
  }
  if (aSinInput.size(0) == varargin_3.size(0)) {
    vstride = aSinInput.size(0);
    for (i = 0; i < vstride; i++) {
      aSinInput[i] = -2.0 * (aSinInput[i] - varargin_3[i]);
    }
  } else {
    b_binary_expand_op(aSinInput, varargin_3);
  }
  mask1.set_size(aSinInput.size(0));
  vstride = aSinInput.size(0);
  mask2.set_size(aSinInput.size(0));
  for (i = 0; i < vstride; i++) {
    mask1[i] = (aSinInput[i] >= 0.99999999999999778);
    mask2[i] = (aSinInput[i] <= -0.99999999999999778);
  }
  csz_idx_0 = mask1.size(0) - 1;
  for (int xj{0}; xj <= csz_idx_0; xj++) {
    if (mask1[xj]) {
      if (xj > csz_idx_0) {
        rtDynamicBoundsError(xj, 0, csz_idx_0, b_emlrtBCI);
      }
      aSinInput[xj] = 1.0;
    }
  }
  for (int xj{0}; xj <= csz_idx_0; xj++) {
    if (mask2[xj]) {
      if (xj > csz_idx_0) {
        rtDynamicBoundsError(xj, 0, csz_idx_0, c_emlrtBCI);
      }
      aSinInput[xj] = -1.0;
    }
  }
  if ((mask1.size(0) != mask2.size(0)) &&
      ((mask1.size(0) != 1) && (mask2.size(0) != 1))) {
    emlrtDimSizeImpxCheckR2021b(mask1.size(0), mask2.size(0), emlrtECI);
  }
  b_y.set_size(q.size(0));
  vstride = q.size(0);
  varargin_3.set_size(q.size(0));
  for (i = 0; i < vstride; i++) {
    b_y[i] = q[i + q.size(0)] * q[i + q.size(0) * 2];
    varargin_3[i] = q[i] * q[i + q.size(0) * 3];
  }
  x.set_size(q.size(0));
  vstride = q.size(0);
  varargin_2.set_size(q.size(0));
  for (i = 0; i < vstride; i++) {
    varargin_1 = q[i];
    x[i] = varargin_1 * varargin_1;
    varargin_1 = q[i + q.size(0)];
    varargin_2[i] = varargin_1 * varargin_1;
  }
  if (x.size(0) == varargin_2.size(0)) {
    vstride = x.size(0);
    for (i = 0; i < vstride; i++) {
      x[i] = x[i] + varargin_2[i];
    }
  } else {
    plus(x, varargin_2);
  }
  varargin_2.set_size(q.size(0));
  vstride = q.size(0);
  for (i = 0; i < vstride; i++) {
    varargin_1 = q[i + q.size(0) * 2];
    varargin_2[i] = varargin_1 * varargin_1;
  }
  if ((x.size(0) != varargin_2.size(0)) &&
      ((x.size(0) != 1) && (varargin_2.size(0) != 1))) {
    emlrtDimSizeImpxCheckR2021b(x.size(0), varargin_2.size(0), b_emlrtECI);
  }
  if (x.size(0) == varargin_2.size(0)) {
    vstride = x.size(0);
    for (i = 0; i < vstride; i++) {
      x[i] = x[i] - varargin_2[i];
    }
  } else {
    minus(x, varargin_2);
  }
  varargin_2.set_size(q.size(0));
  vstride = q.size(0);
  for (i = 0; i < vstride; i++) {
    varargin_1 = q[i + q.size(0) * 3];
    varargin_2[i] = varargin_1 * varargin_1;
  }
  if ((x.size(0) != varargin_2.size(0)) &&
      ((x.size(0) != 1) && (varargin_2.size(0) != 1))) {
    emlrtDimSizeImpxCheckR2021b(x.size(0), varargin_2.size(0), b_emlrtECI);
  }
  c_y.set_size(q.size(0));
  vstride = q.size(0);
  b_varargin_1.set_size(q.size(0));
  for (i = 0; i < vstride; i++) {
    c_y[i] = q[i + q.size(0) * 2] * q[i + q.size(0) * 3];
    b_varargin_1[i] = q[i] * q[i + q.size(0)];
  }
  b_x.set_size(q.size(0));
  vstride = q.size(0);
  r.set_size(q.size(0));
  for (i = 0; i < vstride; i++) {
    varargin_1 = q[i];
    b_x[i] = varargin_1 * varargin_1;
    varargin_1 = q[i + q.size(0)];
    r[i] = varargin_1 * varargin_1;
  }
  if (b_x.size(0) == r.size(0)) {
    vstride = b_x.size(0);
    for (i = 0; i < vstride; i++) {
      b_x[i] = b_x[i] - r[i];
    }
  } else {
    minus(b_x, r);
  }
  r.set_size(q.size(0));
  vstride = q.size(0);
  for (i = 0; i < vstride; i++) {
    varargin_1 = q[i + q.size(0) * 2];
    r[i] = varargin_1 * varargin_1;
  }
  if ((b_x.size(0) != r.size(0)) && ((b_x.size(0) != 1) && (r.size(0) != 1))) {
    emlrtDimSizeImpxCheckR2021b(b_x.size(0), r.size(0), c_emlrtECI);
  }
  if (b_x.size(0) == r.size(0)) {
    vstride = b_x.size(0);
    for (i = 0; i < vstride; i++) {
      b_x[i] = b_x[i] - r[i];
    }
  } else {
    minus(b_x, r);
  }
  r.set_size(q.size(0));
  vstride = q.size(0);
  for (i = 0; i < vstride; i++) {
    varargin_1 = q[i + q.size(0) * 3];
    r[i] = varargin_1 * varargin_1;
  }
  if ((b_x.size(0) != r.size(0)) && ((b_x.size(0) != 1) && (r.size(0) != 1))) {
    emlrtDimSizeImpxCheckR2021b(b_x.size(0), r.size(0), c_emlrtECI);
  }
  if (b_y.size(0) == varargin_3.size(0)) {
    vstride = b_y.size(0);
    for (i = 0; i < vstride; i++) {
      b_y[i] = 2.0 * (b_y[i] + varargin_3[i]);
    }
  } else {
    binary_expand_op(b_y, varargin_3);
  }
  if (c_y.size(0) == b_varargin_1.size(0)) {
    vstride = c_y.size(0);
    for (i = 0; i < vstride; i++) {
      c_y[i] = 2.0 * (c_y[i] + b_varargin_1[i]);
    }
  } else {
    binary_expand_op(c_y, b_varargin_1);
  }
  if (x.size(0) == varargin_2.size(0)) {
    vstride = x.size(0);
    for (i = 0; i < vstride; i++) {
      x[i] = x[i] - varargin_2[i];
    }
  } else {
    minus(x, varargin_2);
  }
  if (b_y.size(0) == x.size(0)) {
    b_varargin_1.set_size(b_y.size(0));
    vstride = b_y.size(0);
    for (i = 0; i < vstride; i++) {
      varargin_1 = b_y[i];
      b_varargin_2 = x[i];
      b_varargin_1[i] = rt_atan2d_snf(varargin_1, b_varargin_2);
    }
  } else {
    internal::expand_atan2(b_y, x, b_varargin_1);
  }
  varargin_2.set_size(aSinInput.size(0));
  vstride = aSinInput.size(0);
  p = false;
  for (int k{0}; k < vstride; k++) {
    varargin_2[k] = aSinInput[k];
    if (p || ((aSinInput[k] < -1.0) || (aSinInput[k] > 1.0))) {
      p = true;
    }
  }
  if (p) {
    b_rtErrorWithMessageID("asin", s_emlrtRTEI.fName, s_emlrtRTEI.lineNo);
  }
  vstride = aSinInput.size(0);
  if (aSinInput.size(0) > 2147483646) {
    check_forloop_overflow_error();
  }
  for (int k{0}; k < vstride; k++) {
    varargin_2[k] = std::asin(varargin_2[k]);
  }
  if (b_x.size(0) == r.size(0)) {
    vstride = b_x.size(0);
    for (i = 0; i < vstride; i++) {
      b_x[i] = b_x[i] + r[i];
    }
  } else {
    plus(b_x, r);
  }
  if (c_y.size(0) == b_x.size(0)) {
    varargin_3.set_size(c_y.size(0));
    vstride = c_y.size(0);
    for (i = 0; i < vstride; i++) {
      varargin_1 = c_y[i];
      b_varargin_2 = b_x[i];
      varargin_3[i] = rt_atan2d_snf(varargin_1, b_varargin_2);
    }
  } else {
    internal::expand_atan2(c_y, b_x, varargin_3);
  }
  if (varargin_2.size(0) != b_varargin_1.size(0)) {
    i_rtErrorWithMessageID(h_emlrtRTEI.fName, h_emlrtRTEI.lineNo);
  }
  if (varargin_3.size(0) != b_varargin_1.size(0)) {
    i_rtErrorWithMessageID(h_emlrtRTEI.fName, h_emlrtRTEI.lineNo);
  }
  eul.set_size(b_varargin_1.size(0), 3);
  vstride = b_varargin_1.size(0);
  for (i = 0; i < vstride; i++) {
    eul[i] = b_varargin_1[i];
  }
  vstride = varargin_2.size(0);
  for (i = 0; i < vstride; i++) {
    eul[i + eul.size(0)] = varargin_2[i];
  }
  vstride = varargin_3.size(0);
  for (i = 0; i < vstride; i++) {
    eul[i + eul.size(0) * 2] = varargin_3[i];
  }
  if (mask1.size(0) == mask2.size(0)) {
    r1.set_size(mask1.size(0));
    vstride = mask1.size(0);
    for (i = 0; i < vstride; i++) {
      r1[i] = (mask1[i] || mask2[i]);
    }
  } else {
    b_or(r1, mask1, mask2);
  }
  xoffset = r1.size(0) - 1;
  vstride = 0;
  for (int xj{0}; xj <= xoffset; xj++) {
    if (r1[xj]) {
      vstride++;
    }
  }
  r2.set_size(vstride);
  vstride = 0;
  for (int xj{0}; xj <= xoffset; xj++) {
    if (r1[xj]) {
      r2[vstride] = xj;
      vstride++;
    }
  }
  x.set_size(r2.size(0));
  vstride = r2.size(0);
  for (i = 0; i < vstride; i++) {
    if (r2[i] > csz_idx_0) {
      rtDynamicBoundsError(r2[i], 0, csz_idx_0, d_emlrtBCI);
    }
    x[i] = aSinInput[r2[i]];
  }
  vstride = r2.size(0);
  if (r2.size(0) > 2147483646) {
    check_forloop_overflow_error();
  }
  for (int k{0}; k < vstride; k++) {
    if (std::isnan(x[k])) {
      x[k] = rtNaN;
    } else if (x[k] < 0.0) {
      x[k] = -1.0;
    } else {
      x[k] = (x[k] > 0.0);
    }
  }
  vstride = x.size(0);
  for (i = 0; i < vstride; i++) {
    x[i] = -x[i] * 2.0;
  }
  vstride = r2.size(0);
  for (i = 0; i < vstride; i++) {
    if (r2[i] > q.size(0) - 1) {
      rtDynamicBoundsError(r2[i], 0, q.size(0) - 1, e_emlrtBCI);
    }
  }
  vstride = r2.size(0);
  for (i = 0; i < vstride; i++) {
    if (r2[i] > q.size(0) - 1) {
      rtDynamicBoundsError(r2[i], 0, q.size(0) - 1, f_emlrtBCI);
    }
  }
  varargin_3.set_size(r2.size(0));
  vstride = r2.size(0);
  for (int k{0}; k < vstride; k++) {
    varargin_3[k] = rt_atan2d_snf(q[r2[k] + q.size(0)], q[r2[k]]);
  }
  if ((x.size(0) != varargin_3.size(0)) &&
      ((x.size(0) != 1) && (varargin_3.size(0) != 1))) {
    emlrtDimSizeImpxCheckR2021b(x.size(0), varargin_3.size(0), d_emlrtECI);
  }
  vstride = r2.size(0);
  for (i = 0; i < vstride; i++) {
    if (r2[i] > eul.size(0) - 1) {
      rtDynamicBoundsError(r2[i], 0, eul.size(0) - 1, g_emlrtBCI);
    }
  }
  if (x.size(0) == varargin_3.size(0)) {
    vstride = x.size(0);
    for (i = 0; i < vstride; i++) {
      x[i] = x[i] * varargin_3[i];
    }
  } else {
    times(x, varargin_3);
  }
  rtSubAssignSizeCheck(r2.size(), 1, x.size(), 1, e_emlrtECI);
  vstride = x.size(0);
  for (i = 0; i < vstride; i++) {
    eul[r2[i]] = x[i];
  }
  vstride = r2.size(0);
  for (i = 0; i < vstride; i++) {
    if (r2[i] > eul.size(0) - 1) {
      rtDynamicBoundsError(r2[i], 0, eul.size(0) - 1, h_emlrtBCI);
    }
    eul[r2[i] + eul.size(0) * 2] = 0.0;
  }
}

//
// Arguments    : coder::array<double, 1U> &in1
//                const coder::array<double, 1U> &in2
// Return Type  : void
//
} // namespace coder
void times(coder::array<double, 1U> &in1, const coder::array<double, 1U> &in2)
{
  coder::array<double, 1U> b_in1;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  if (in2.size(0) == 1) {
    loop_ub = in1.size(0);
  } else {
    loop_ub = in2.size(0);
  }
  b_in1.set_size(loop_ub);
  stride_0_0 = (in1.size(0) != 1);
  stride_1_0 = (in2.size(0) != 1);
  for (int i{0}; i < loop_ub; i++) {
    b_in1[i] = in1[i * stride_0_0] * in2[i * stride_1_0];
  }
  in1.set_size(b_in1.size(0));
  loop_ub = b_in1.size(0);
  for (int i{0}; i < loop_ub; i++) {
    in1[i] = b_in1[i];
  }
}

//
// File trailer for quat2eul.cpp
//
// [EOF]
//
