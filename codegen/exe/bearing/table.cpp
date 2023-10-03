//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: table.cpp
//
// MATLAB Coder version            : 5.6
// C/C++ source code generated on  : 03-Oct-2023 08:03:05
//

// Include Files
#include "table.h"
#include "bearing_internal_types.h"
#include "bearing_rtwutil.h"
#include "bearing_types.h"
#include "eml_int_forloop_overflow_check.h"
#include "find.h"
#include "metaDim.h"
#include "rowNamesDim.h"
#include "rt_nonfinite.h"
#include "varNamesDim.h"
#include "coder_array.h"
#include "coder_bounded_array.h"
#include <sstream>
#include <stdexcept>
#include <string>

// Variable Definitions
static rtBoundsCheckInfo emlrtBCI{
    -1,                           // iFirst
    -1,                           // iLast
    231,                          // lineNo
    29,                           // colNo
    "",                           // aName
    "tabularDimension/setLabels", // fName
    "/Applications/MATLAB_R2023a.app/toolbox/matlab/datatypes/codegen/tabular/"
    "+matlab/+internal/+coder/+tabular/+private/tabularDimen"
    "sion.m", // pName
    0         // checkKind
};

// Function Declarations
static void b_rtErrorWithMessageID(const char *r, const char *aFcnName,
                                   int aLineNum);

static void v_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

static void w_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

// Function Definitions
//
// Arguments    : const char *r
//                const char *aFcnName
//                int aLineNum
// Return Type  : void
//
static void b_rtErrorWithMessageID(const char *r, const char *aFcnName,
                                   int aLineNum)
{
  std::stringstream outStream;
  ((outStream << "Concatenating the table variable \'") << r)
      << "\' using VERTCAT resulted in a variable of the wrong length.";
  outStream << "\n";
  ((((outStream << "Error in ") << aFcnName) << " (line ") << aLineNum) << ")";
  throw std::runtime_error(outStream.str());
}

//
// Arguments    : const char *aFcnName
//                int aLineNum
// Return Type  : void
//
static void v_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::stringstream outStream;
  outStream << "All table variables must have the same number of rows.";
  outStream << "\n";
  ((((outStream << "Error in ") << aFcnName) << " (line ") << aLineNum) << ")";
  throw std::runtime_error(outStream.str());
}

//
// Arguments    : const char *aFcnName
//                int aLineNum
// Return Type  : void
//
static void w_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::stringstream outStream;
  outStream << "Row index exceeds table dimensions.";
  outStream << "\n";
  ((((outStream << "Error in ") << aFcnName) << " (line ") << aLineNum) << ")";
  throw std::runtime_error(outStream.str());
}

//
// Arguments    : const ::coder::array<unsigned int, 1U> &varargin_1
//                const ::coder::array<cell_wrap_4, 1U> &varargin_2
//                const ::coder::array<double, 1U> &varargin_3
//                const ::coder::array<double, 1U> &varargin_4
//                const ::coder::array<double, 1U> &varargin_5
//                const ::coder::array<double, 1U> &varargin_6
//                const ::coder::array<double, 1U> &varargin_7
//                const ::coder::array<double, 1U> &varargin_8
//                const ::coder::array<double, 1U> &varargin_9
//                const ::coder::array<double, 1U> &varargin_10
// Return Type  : void
//
namespace coder {
void b_table::init(const ::coder::array<unsigned int, 1U> &varargin_1,
                   const ::coder::array<cell_wrap_4, 1U> &varargin_2,
                   const ::coder::array<double, 1U> &varargin_3,
                   const ::coder::array<double, 1U> &varargin_4,
                   const ::coder::array<double, 1U> &varargin_5,
                   const ::coder::array<double, 1U> &varargin_6,
                   const ::coder::array<double, 1U> &varargin_7,
                   const ::coder::array<double, 1U> &varargin_8,
                   const ::coder::array<double, 1U> &varargin_9,
                   const ::coder::array<double, 1U> &varargin_10)
{
  static rtRunTimeErrorInfo v_emlrtRTEI{
      329,                     // lineNo
      "tabular/countVarInputs" // fName
  };
  array<unsigned int, 2U> indices;
  int b_i;
  int i;
  arrayProps.Description.size[0] = 1;
  arrayProps.Description.size[1] = 0;
  if (varargin_2.size(0) != varargin_1.size(0)) {
    v_rtErrorWithMessageID(v_emlrtRTEI.fName, v_emlrtRTEI.lineNo);
  }
  if (varargin_3.size(0) != varargin_1.size(0)) {
    v_rtErrorWithMessageID(v_emlrtRTEI.fName, v_emlrtRTEI.lineNo);
  }
  if (varargin_4.size(0) != varargin_1.size(0)) {
    v_rtErrorWithMessageID(v_emlrtRTEI.fName, v_emlrtRTEI.lineNo);
  }
  if (varargin_5.size(0) != varargin_1.size(0)) {
    v_rtErrorWithMessageID(v_emlrtRTEI.fName, v_emlrtRTEI.lineNo);
  }
  if (varargin_6.size(0) != varargin_1.size(0)) {
    v_rtErrorWithMessageID(v_emlrtRTEI.fName, v_emlrtRTEI.lineNo);
  }
  if (varargin_7.size(0) != varargin_1.size(0)) {
    v_rtErrorWithMessageID(v_emlrtRTEI.fName, v_emlrtRTEI.lineNo);
  }
  if (varargin_8.size(0) != varargin_1.size(0)) {
    v_rtErrorWithMessageID(v_emlrtRTEI.fName, v_emlrtRTEI.lineNo);
  }
  if (varargin_9.size(0) != varargin_1.size(0)) {
    v_rtErrorWithMessageID(v_emlrtRTEI.fName, v_emlrtRTEI.lineNo);
  }
  if (varargin_10.size(0) != varargin_1.size(0)) {
    v_rtErrorWithMessageID(v_emlrtRTEI.fName, v_emlrtRTEI.lineNo);
  }
  rowDim.length = varargin_1.size(0);
  indices.set_size(1, varargin_1.size(0));
  i = varargin_1.size(0);
  for (b_i = 0; b_i < i; b_i++) {
    if (b_i + 1 > indices.size(1)) {
      rtDynamicBoundsError(b_i + 1, 1, indices.size(1), emlrtBCI);
    }
    indices[b_i] = static_cast<unsigned int>(b_i + 1);
  }
  matlab::internal::coder::tabular::b_private::varNamesDim::createLike(varDim);
  data.f1.set_size(varargin_1.size(0));
  b_i = varargin_1.size(0);
  for (i = 0; i < b_i; i++) {
    data.f1[i] = varargin_1[i];
  }
  data.f2.set_size(varargin_2.size(0));
  b_i = varargin_2.size(0);
  for (i = 0; i < b_i; i++) {
    data.f2[i] = varargin_2[i];
  }
  data.f3.set_size(varargin_3.size(0));
  b_i = varargin_3.size(0);
  for (i = 0; i < b_i; i++) {
    data.f3[i] = varargin_3[i];
  }
  data.f4.set_size(varargin_4.size(0));
  b_i = varargin_4.size(0);
  for (i = 0; i < b_i; i++) {
    data.f4[i] = varargin_4[i];
  }
  data.f5.set_size(varargin_5.size(0));
  b_i = varargin_5.size(0);
  for (i = 0; i < b_i; i++) {
    data.f5[i] = varargin_5[i];
  }
  data.f6.set_size(varargin_6.size(0));
  b_i = varargin_6.size(0);
  for (i = 0; i < b_i; i++) {
    data.f6[i] = varargin_6[i];
  }
  data.f7.set_size(varargin_7.size(0));
  b_i = varargin_7.size(0);
  for (i = 0; i < b_i; i++) {
    data.f7[i] = varargin_7[i];
  }
  data.f8.set_size(varargin_8.size(0));
  b_i = varargin_8.size(0);
  for (i = 0; i < b_i; i++) {
    data.f8[i] = varargin_8[i];
  }
  data.f9.set_size(varargin_9.size(0));
  b_i = varargin_9.size(0);
  for (i = 0; i < b_i; i++) {
    data.f9[i] = varargin_9[i];
  }
  data.f10.set_size(varargin_10.size(0));
  b_i = varargin_10.size(0);
  for (i = 0; i < b_i; i++) {
    data.f10[i] = varargin_10[i];
  }
}

//
// Arguments    : const ::coder::array<boolean_T, 1U> &varargin_1
//                b_table &b
// Return Type  : void
//
void b_table::parenReference(const ::coder::array<boolean_T, 1U> &varargin_1,
                             b_table &b) const
{
  static rtBoundsCheckInfo b_emlrtBCI{
      -1,                           // iFirst
      -1,                           // iLast
      302,                          // lineNo
      36,                           // colNo
      "",                           // aName
      "tabularDimension/subs2inds", // fName
      "/Applications/MATLAB_R2023a.app/toolbox/matlab/datatypes/codegen/"
      "tabular/+matlab/+internal/+coder/+tabular/+private/tabularDimen"
      "sion.m", // pName
      0         // checkKind
  };
  static rtBoundsCheckInfo c_emlrtBCI{
      -1,                       // iFirst
      -1,                       // iLast
      69,                       // lineNo
      31,                       // colNo
      "",                       // aName
      "tabular/parenReference", // fName
      "/Applications/MATLAB_R2023a.app/toolbox/matlab/datatypes/codegen/"
      "tabular/+matlab/+internal/+coder/@tabular/parenReference.m", // pName
      0                                                             // checkKind
  };
  static rtBoundsCheckInfo d_emlrtBCI{
      -1,                       // iFirst
      -1,                       // iLast
      63,                       // lineNo
      33,                       // colNo
      "",                       // aName
      "tabular/parenReference", // fName
      "/Applications/MATLAB_R2023a.app/toolbox/matlab/datatypes/codegen/"
      "tabular/+matlab/+internal/+coder/@tabular/parenReference.m", // pName
      0                                                             // checkKind
  };
  static rtBoundsCheckInfo e_emlrtBCI{
      -1,                       // iFirst
      -1,                       // iLast
      63,                       // lineNo
      71,                       // colNo
      "",                       // aName
      "tabular/parenReference", // fName
      "/Applications/MATLAB_R2023a.app/toolbox/matlab/datatypes/codegen/"
      "tabular/+matlab/+internal/+coder/@tabular/parenReference.m", // pName
      0                                                             // checkKind
  };
  static rtBoundsCheckInfo f_emlrtBCI{
      -1,                       // iFirst
      -1,                       // iLast
      63,                       // lineNo
      53,                       // colNo
      "",                       // aName
      "tabular/parenReference", // fName
      "/Applications/MATLAB_R2023a.app/toolbox/matlab/datatypes/codegen/"
      "tabular/+matlab/+internal/+coder/@tabular/parenReference.m", // pName
      0                                                             // checkKind
  };
  static rtBoundsCheckInfo g_emlrtBCI{
      -1,                       // iFirst
      -1,                       // iLast
      63,                       // lineNo
      41,                       // colNo
      "",                       // aName
      "tabular/parenReference", // fName
      "/Applications/MATLAB_R2023a.app/toolbox/matlab/datatypes/codegen/"
      "tabular/+matlab/+internal/+coder/@tabular/parenReference.m", // pName
      0                                                             // checkKind
  };
  static rtBoundsCheckInfo h_emlrtBCI{
      -1,                       // iFirst
      -1,                       // iLast
      63,                       // lineNo
      25,                       // colNo
      "",                       // aName
      "tabular/parenReference", // fName
      "/Applications/MATLAB_R2023a.app/toolbox/matlab/datatypes/codegen/"
      "tabular/+matlab/+internal/+coder/@tabular/parenReference.m", // pName
      0                                                             // checkKind
  };
  static rtRunTimeErrorInfo v_emlrtRTEI{
      316,                         // lineNo
      "tabularDimension/subs2inds" // fName
  };
  array<unsigned int, 2U> indices;
  array<int, 1U> ii;
  int a__1;
  int b_i;
  int i;
  int k;
  int nz;
  boolean_T exitg1;
  if (varargin_1.size(0) > 2147483646) {
    check_forloop_overflow_error();
  }
  a__1 = 0;
  i = varargin_1.size(0);
  b_i = 0;
  exitg1 = false;
  while ((!exitg1) && (b_i <= i - 1)) {
    nz = i - b_i;
    if ((nz < 1) || (nz > varargin_1.size(0))) {
      rtDynamicBoundsError(nz, 1, varargin_1.size(0), b_emlrtBCI);
    }
    if (varargin_1[nz - 1]) {
      a__1 = nz;
      exitg1 = true;
    } else {
      b_i++;
    }
  }
  if (a__1 > rowDim.length) {
    w_rtErrorWithMessageID(v_emlrtRTEI.fName, v_emlrtRTEI.lineNo);
  }
  a__1 = varargin_1.size(0);
  nz = varargin_1[0];
  for (k = 2; k <= a__1; k++) {
    nz += varargin_1[k - 1];
  }
  b.rowDim.length = nz;
  indices.set_size(1, nz);
  for (b_i = 0; b_i < nz; b_i++) {
    if (b_i + 1 > indices.size(1)) {
      rtDynamicBoundsError(b_i + 1, 1, indices.size(1), emlrtBCI);
    }
    indices[b_i] = static_cast<unsigned int>(b_i + 1);
  }
  matlab::internal::coder::tabular::b_private::varNamesDim::createLike(
      b.varDim);
  if (varDim.hasUnits) {
    for (b_i = 0; b_i < 10; b_i++) {
      b.varDim.units[b_i].f1.size[0] = varDim.units[b_i].f1.size[0];
      b.varDim.units[b_i].f1.size[1] = 0;
    }
    b.varDim.hasUnits = true;
  }
  if (varDim.hasDescrs) {
    for (b_i = 0; b_i < 10; b_i++) {
      b.varDim.descrs[b_i].f1.size[0] = varDim.descrs[b_i].f1.size[0];
      b.varDim.descrs[b_i].f1.size[1] = 0;
    }
    b.varDim.hasDescrs = true;
  }
  if (varDim.hasContinuity) {
    for (i = 0; i < 10; i++) {
      b.varDim.continuity[i] = varDim.continuity[i];
    }
    b.varDim.hasContinuity = true;
  }
  k = varargin_1.size(0) - 1;
  a__1 = 0;
  for (b_i = 0; b_i <= k; b_i++) {
    if (varargin_1[b_i]) {
      a__1++;
    }
  }
  b.data.f1.set_size(a__1);
  a__1 = 0;
  for (b_i = 0; b_i <= k; b_i++) {
    if (varargin_1[b_i]) {
      if (b_i > data.f1.size(0) - 1) {
        rtDynamicBoundsError(b_i, 0, data.f1.size(0) - 1, c_emlrtBCI);
      }
      b.data.f1[a__1] = data.f1[b_i];
      a__1++;
    }
  }
  eml_find(varargin_1, ii);
  b.data.f2.set_size(ii.size(0));
  i = ii.size(0);
  for (b_i = 0; b_i < i; b_i++) {
    boolean_T b_b;
    if (b_i > b.data.f2.size(0) - 1) {
      rtDynamicBoundsError(b_i, 0, b.data.f2.size(0) - 1, d_emlrtBCI);
    }
    b.data.f2[b_i].f1.set_size(1, b.data.f2[b_i].f1.size(1));
    if (b_i + 1 > ii.size(0)) {
      rtDynamicBoundsError(b_i + 1, 1, ii.size(0), e_emlrtBCI);
    }
    a__1 = ii[b_i] - 1;
    b_b = ((a__1 < 0) || (a__1 > data.f2.size(0) - 1));
    if (b_b) {
      rtDynamicBoundsError(a__1, 0, data.f2.size(0) - 1, f_emlrtBCI);
    }
    if (b_i > b.data.f2.size(0) - 1) {
      rtDynamicBoundsError(b_i, 0, b.data.f2.size(0) - 1, d_emlrtBCI);
    }
    b.data.f2[b_i].f1.set_size(b.data.f2[b_i].f1.size(0),
                               data.f2[ii[b_i] - 1].f1.size(1));
    if (b_i + 1 > ii.size(0)) {
      rtDynamicBoundsError(b_i + 1, 1, ii.size(0), e_emlrtBCI);
    }
    if (b_i + 1 > ii.size(0)) {
      rtDynamicBoundsError(b_i + 1, 1, ii.size(0), e_emlrtBCI);
    }
    if (b_i > b.data.f2.size(0) - 1) {
      rtDynamicBoundsError(b_i, 0, b.data.f2.size(0) - 1, d_emlrtBCI);
    }
    if (b_i > b.data.f2.size(0) - 1) {
      rtDynamicBoundsError(b_i, 0, b.data.f2.size(0) - 1, d_emlrtBCI);
    }
    nz = data.f2[ii[b_i] - 1].f1.size(1);
    for (int i1{0}; i1 < nz; i1++) {
      if (b_i + 1 > ii.size(0)) {
        rtDynamicBoundsError(b_i + 1, 1, ii.size(0), g_emlrtBCI);
      }
      if (b_i > b.data.f2.size(0) - 1) {
        rtDynamicBoundsError(b_i, 0, b.data.f2.size(0) - 1, h_emlrtBCI);
      }
      b.data.f2[b_i].f1[i1] = data.f2[a__1].f1[i1];
    }
  }
  a__1 = 0;
  for (b_i = 0; b_i <= k; b_i++) {
    if (varargin_1[b_i]) {
      a__1++;
    }
  }
  b.data.f3.set_size(a__1);
  a__1 = 0;
  for (b_i = 0; b_i <= k; b_i++) {
    if (varargin_1[b_i]) {
      if (b_i > data.f3.size(0) - 1) {
        rtDynamicBoundsError(b_i, 0, data.f3.size(0) - 1, c_emlrtBCI);
      }
      b.data.f3[a__1] = data.f3[b_i];
      a__1++;
    }
  }
  a__1 = 0;
  for (b_i = 0; b_i <= k; b_i++) {
    if (varargin_1[b_i]) {
      a__1++;
    }
  }
  b.data.f4.set_size(a__1);
  a__1 = 0;
  for (b_i = 0; b_i <= k; b_i++) {
    if (varargin_1[b_i]) {
      if (b_i > data.f4.size(0) - 1) {
        rtDynamicBoundsError(b_i, 0, data.f4.size(0) - 1, c_emlrtBCI);
      }
      b.data.f4[a__1] = data.f4[b_i];
      a__1++;
    }
  }
  a__1 = 0;
  for (b_i = 0; b_i <= k; b_i++) {
    if (varargin_1[b_i]) {
      a__1++;
    }
  }
  b.data.f5.set_size(a__1);
  a__1 = 0;
  for (b_i = 0; b_i <= k; b_i++) {
    if (varargin_1[b_i]) {
      if (b_i > data.f5.size(0) - 1) {
        rtDynamicBoundsError(b_i, 0, data.f5.size(0) - 1, c_emlrtBCI);
      }
      b.data.f5[a__1] = data.f5[b_i];
      a__1++;
    }
  }
  a__1 = 0;
  for (b_i = 0; b_i <= k; b_i++) {
    if (varargin_1[b_i]) {
      a__1++;
    }
  }
  b.data.f6.set_size(a__1);
  a__1 = 0;
  for (b_i = 0; b_i <= k; b_i++) {
    if (varargin_1[b_i]) {
      if (b_i > data.f6.size(0) - 1) {
        rtDynamicBoundsError(b_i, 0, data.f6.size(0) - 1, c_emlrtBCI);
      }
      b.data.f6[a__1] = data.f6[b_i];
      a__1++;
    }
  }
  a__1 = 0;
  for (b_i = 0; b_i <= k; b_i++) {
    if (varargin_1[b_i]) {
      a__1++;
    }
  }
  b.data.f7.set_size(a__1);
  a__1 = 0;
  for (b_i = 0; b_i <= k; b_i++) {
    if (varargin_1[b_i]) {
      if (b_i > data.f7.size(0) - 1) {
        rtDynamicBoundsError(b_i, 0, data.f7.size(0) - 1, c_emlrtBCI);
      }
      b.data.f7[a__1] = data.f7[b_i];
      a__1++;
    }
  }
  a__1 = 0;
  for (b_i = 0; b_i <= k; b_i++) {
    if (varargin_1[b_i]) {
      a__1++;
    }
  }
  b.data.f8.set_size(a__1);
  a__1 = 0;
  for (b_i = 0; b_i <= k; b_i++) {
    if (varargin_1[b_i]) {
      if (b_i > data.f8.size(0) - 1) {
        rtDynamicBoundsError(b_i, 0, data.f8.size(0) - 1, c_emlrtBCI);
      }
      b.data.f8[a__1] = data.f8[b_i];
      a__1++;
    }
  }
  a__1 = 0;
  for (b_i = 0; b_i <= k; b_i++) {
    if (varargin_1[b_i]) {
      a__1++;
    }
  }
  b.data.f9.set_size(a__1);
  a__1 = 0;
  for (b_i = 0; b_i <= k; b_i++) {
    if (varargin_1[b_i]) {
      if (b_i > data.f9.size(0) - 1) {
        rtDynamicBoundsError(b_i, 0, data.f9.size(0) - 1, c_emlrtBCI);
      }
      b.data.f9[a__1] = data.f9[b_i];
      a__1++;
    }
  }
  a__1 = 0;
  for (b_i = 0; b_i <= k; b_i++) {
    if (varargin_1[b_i]) {
      a__1++;
    }
  }
  b.data.f10.set_size(a__1);
  a__1 = 0;
  for (b_i = 0; b_i <= k; b_i++) {
    if (varargin_1[b_i]) {
      if (b_i > data.f10.size(0) - 1) {
        rtDynamicBoundsError(b_i, 0, data.f10.size(0) - 1, c_emlrtBCI);
      }
      b.data.f10[a__1] = data.f10[b_i];
      a__1++;
    }
  }
  b.b_metaDim = b_metaDim;
  b.arrayProps = arrayProps;
}

//
// Arguments    : const table &varargin_2
//                b_table &t
// Return Type  : void
//
void b_table::vertcat(const table &varargin_2, b_table &t) const
{
  static rtBoundsCheckInfo b_emlrtBCI{
      -1,                // iFirst
      -1,                // iLast
      364,               // lineNo
      35,                // colNo
      "",                // aName
      "tabular/vertcat", // fName
      "/Applications/MATLAB_R2023a.app/toolbox/matlab/datatypes/codegen/"
      "tabular/+matlab/+internal/+coder/@tabular/vertcat.m", // pName
      0                                                      // checkKind
  };
  static rtBoundsCheckInfo c_emlrtBCI{
      -1,                // iFirst
      -1,                // iLast
      364,               // lineNo
      62,                // colNo
      "",                // aName
      "tabular/vertcat", // fName
      "/Applications/MATLAB_R2023a.app/toolbox/matlab/datatypes/codegen/"
      "tabular/+matlab/+internal/+coder/@tabular/vertcat.m", // pName
      0                                                      // checkKind
  };
  static rtBoundsCheckInfo d_emlrtBCI{
      -1,                // iFirst
      -1,                // iLast
      364,               // lineNo
      53,                // colNo
      "",                // aName
      "tabular/vertcat", // fName
      "/Applications/MATLAB_R2023a.app/toolbox/matlab/datatypes/codegen/"
      "tabular/+matlab/+internal/+coder/@tabular/vertcat.m", // pName
      0                                                      // checkKind
  };
  static rtBoundsCheckInfo e_emlrtBCI{
      -1,                // iFirst
      -1,                // iLast
      364,               // lineNo
      25,                // colNo
      "",                // aName
      "tabular/vertcat", // fName
      "/Applications/MATLAB_R2023a.app/toolbox/matlab/datatypes/codegen/"
      "tabular/+matlab/+internal/+coder/@tabular/vertcat.m", // pName
      0                                                      // checkKind
  };
  static rtDoubleCheckInfo b_emlrtDCI{
      364,               // lineNo
      35,                // colNo
      "tabular/vertcat", // fName
      "/Applications/MATLAB_R2023a.app/toolbox/matlab/datatypes/codegen/"
      "tabular/+matlab/+internal/+coder/@tabular/vertcat.m", // pName
      1                                                      // checkKind
  };
  static rtDoubleCheckInfo c_emlrtDCI{
      364,               // lineNo
      25,                // colNo
      "tabular/vertcat", // fName
      "/Applications/MATLAB_R2023a.app/toolbox/matlab/datatypes/codegen/"
      "tabular/+matlab/+internal/+coder/@tabular/vertcat.m", // pName
      1                                                      // checkKind
  };
  static rtDoubleCheckInfo d_emlrtDCI{
      229,                          // lineNo
      35,                           // colNo
      "tabularDimension/setLabels", // fName
      "/Applications/MATLAB_R2023a.app/toolbox/matlab/datatypes/codegen/"
      "tabular/+matlab/+internal/+coder/+tabular/+private/tabularDimen"
      "sion.m", // pName
      1         // checkKind
  };
  static rtRunTimeErrorInfo v_emlrtRTEI{
      377,              // lineNo
      "tabular/vertcat" // fName
  };
  array<unsigned int, 2U> indices;
  double d;
  int i;
  int loop_ub;
  boolean_T b;
  matlab::internal::coder::tabular::b_private::varNamesDim::createLike(
      t.varDim);
  t.arrayProps.Description.size[0] = arrayProps.Description.size[0];
  t.arrayProps.Description.size[1] = 0;
  t.data.f1.set_size(data.f1.size(0) + 1);
  loop_ub = data.f1.size(0);
  for (i = 0; i < loop_ub; i++) {
    t.data.f1[i] = data.f1[i];
  }
  t.data.f1[data.f1.size(0)] = varargin_2.data.f1;
  if (static_cast<unsigned int>(t.data.f1.size(0)) !=
      static_cast<unsigned int>(data.f1.size(0)) + 1U) {
    b_rtErrorWithMessageID("tagID", v_emlrtRTEI.fName, v_emlrtRTEI.lineNo);
  }
  t.data.f2.set_size(data.f1.size(0) + 1);
  i = data.f2.size(0);
  for (int k{0}; k < i; k++) {
    int i1;
    if (k > t.data.f2.size(0) - 1) {
      rtDynamicBoundsError(k, 0, t.data.f2.size(0) - 1, b_emlrtBCI);
    }
    t.data.f2[k].f1.set_size(1, t.data.f2[k].f1.size(1));
    i1 = data.f2.size(0) - 1;
    if (k > data.f2.size(0) - 1) {
      rtDynamicBoundsError(k, 0, data.f2.size(0) - 1, c_emlrtBCI);
    }
    if (k > t.data.f2.size(0) - 1) {
      rtDynamicBoundsError(k, 0, t.data.f2.size(0) - 1, b_emlrtBCI);
    }
    t.data.f2[k].f1.set_size(t.data.f2[k].f1.size(0), data.f2[k].f1.size(1));
    if (k > data.f2.size(0) - 1) {
      rtDynamicBoundsError(k, 0, data.f2.size(0) - 1, c_emlrtBCI);
    }
    if (k > t.data.f2.size(0) - 1) {
      rtDynamicBoundsError(k, 0, t.data.f2.size(0) - 1, b_emlrtBCI);
    }
    if (k > t.data.f2.size(0) - 1) {
      rtDynamicBoundsError(k, 0, t.data.f2.size(0) - 1, b_emlrtBCI);
    }
    loop_ub = data.f2[k].f1.size(1);
    for (int i2{0}; i2 < loop_ub; i2++) {
      if (k > i1) {
        rtDynamicBoundsError(k, 0, i1, d_emlrtBCI);
      }
      if (k > t.data.f2.size(0) - 1) {
        rtDynamicBoundsError(k, 0, t.data.f2.size(0) - 1, e_emlrtBCI);
      }
      t.data.f2[k].f1[i2] = data.f2[k].f1[i2];
    }
  }
  d = static_cast<double>(data.f2.size(0)) + 1.0;
  if (static_cast<double>(data.f2.size(0)) + 1.0 != data.f2.size(0) + 1) {
    rtIntegerError(static_cast<double>(data.f2.size(0)) + 1.0, b_emlrtDCI);
  }
  if ((data.f2.size(0) < 0) || (data.f2.size(0) > t.data.f2.size(0) - 1)) {
    rtDynamicBoundsError(data.f2.size(0), 0, t.data.f2.size(0) - 1, b_emlrtBCI);
  }
  t.data.f2[data.f2.size(0)].f1.set_size(1,
                                         t.data.f2[data.f2.size(0)].f1.size(1));
  if (static_cast<double>(data.f2.size(0)) + 1.0 != data.f2.size(0) + 1) {
    rtIntegerError(static_cast<double>(data.f2.size(0)) + 1.0, b_emlrtDCI);
  }
  if ((data.f2.size(0) < 0) || (data.f2.size(0) > t.data.f2.size(0) - 1)) {
    rtDynamicBoundsError(data.f2.size(0), 0, t.data.f2.size(0) - 1, b_emlrtBCI);
  }
  t.data.f2[data.f2.size(0)].f1.set_size(t.data.f2[data.f2.size(0)].f1.size(0),
                                         varargin_2.data.f2[0].f1.size(1));
  if (static_cast<double>(data.f2.size(0)) + 1.0 != data.f2.size(0) + 1) {
    rtIntegerError(static_cast<double>(data.f2.size(0)) + 1.0, b_emlrtDCI);
  }
  b = ((data.f2.size(0) < 0) || (data.f2.size(0) > t.data.f2.size(0) - 1));
  if (b) {
    rtDynamicBoundsError(data.f2.size(0), 0, t.data.f2.size(0) - 1, b_emlrtBCI);
  }
  if (static_cast<double>(data.f2.size(0)) + 1.0 != data.f2.size(0) + 1) {
    rtIntegerError(static_cast<double>(data.f2.size(0)) + 1.0, b_emlrtDCI);
  }
  loop_ub = varargin_2.data.f2[0].f1.size(1);
  for (i = 0; i < loop_ub; i++) {
    if (d != static_cast<int>(d)) {
      rtIntegerError(d, c_emlrtDCI);
    }
    if ((static_cast<int>(d) - 1 < 0) ||
        (static_cast<int>(d) - 1 > t.data.f2.size(0) - 1)) {
      rtDynamicBoundsError(static_cast<int>(d) - 1, 0, t.data.f2.size(0) - 1,
                           e_emlrtBCI);
    }
    t.data.f2[static_cast<int>(d) - 1].f1[i] = varargin_2.data.f2[0].f1[i];
  }
  t.data.f3.set_size(data.f3.size(0) + 1);
  loop_ub = data.f3.size(0);
  for (i = 0; i < loop_ub; i++) {
    t.data.f3[i] = data.f3[i];
  }
  t.data.f3[data.f3.size(0)] = varargin_2.data.f3;
  if (static_cast<unsigned int>(t.data.f3.size(0)) !=
      static_cast<unsigned int>(data.f1.size(0)) + 1U) {
    b_rtErrorWithMessageID("bearing", v_emlrtRTEI.fName, v_emlrtRTEI.lineNo);
  }
  t.data.f4.set_size(data.f4.size(0) + 1);
  loop_ub = data.f4.size(0);
  for (i = 0; i < loop_ub; i++) {
    t.data.f4[i] = data.f4[i];
  }
  t.data.f4[data.f4.size(0)] = varargin_2.data.f4;
  if (static_cast<unsigned int>(t.data.f4.size(0)) !=
      static_cast<unsigned int>(data.f1.size(0)) + 1U) {
    b_rtErrorWithMessageID("tau", v_emlrtRTEI.fName, v_emlrtRTEI.lineNo);
  }
  t.data.f5.set_size(data.f5.size(0) + 1);
  loop_ub = data.f5.size(0);
  for (i = 0; i < loop_ub; i++) {
    t.data.f5[i] = data.f5[i];
  }
  t.data.f5[data.f5.size(0)] = varargin_2.data.f5;
  if (static_cast<unsigned int>(t.data.f5.size(0)) !=
      static_cast<unsigned int>(data.f1.size(0)) + 1U) {
    b_rtErrorWithMessageID("latitude_deg", v_emlrtRTEI.fName,
                           v_emlrtRTEI.lineNo);
  }
  t.data.f6.set_size(data.f6.size(0) + 1);
  loop_ub = data.f6.size(0);
  for (i = 0; i < loop_ub; i++) {
    t.data.f6[i] = data.f6[i];
  }
  t.data.f6[data.f6.size(0)] = varargin_2.data.f6;
  if (static_cast<unsigned int>(t.data.f6.size(0)) !=
      static_cast<unsigned int>(data.f1.size(0)) + 1U) {
    b_rtErrorWithMessageID("longitude_deg", v_emlrtRTEI.fName,
                           v_emlrtRTEI.lineNo);
  }
  t.data.f7.set_size(data.f7.size(0) + 1);
  loop_ub = data.f7.size(0);
  for (i = 0; i < loop_ub; i++) {
    t.data.f7[i] = data.f7[i];
  }
  t.data.f7[data.f7.size(0)] = varargin_2.data.f7;
  if (static_cast<unsigned int>(t.data.f7.size(0)) !=
      static_cast<unsigned int>(data.f1.size(0)) + 1U) {
    b_rtErrorWithMessageID("alt_AGL_m", v_emlrtRTEI.fName, v_emlrtRTEI.lineNo);
  }
  t.data.f8.set_size(data.f8.size(0) + 1);
  loop_ub = data.f8.size(0);
  for (i = 0; i < loop_ub; i++) {
    t.data.f8[i] = data.f8[i];
  }
  t.data.f8[data.f8.size(0)] = varargin_2.data.f8;
  if (static_cast<unsigned int>(t.data.f8.size(0)) !=
      static_cast<unsigned int>(data.f1.size(0)) + 1U) {
    b_rtErrorWithMessageID("alt_ASL_m", v_emlrtRTEI.fName, v_emlrtRTEI.lineNo);
  }
  t.data.f9.set_size(data.f9.size(0) + 1);
  loop_ub = data.f9.size(0);
  for (i = 0; i < loop_ub; i++) {
    t.data.f9[i] = data.f9[i];
  }
  t.data.f9[data.f9.size(0)] = varargin_2.data.f9;
  if (static_cast<unsigned int>(t.data.f9.size(0)) !=
      static_cast<unsigned int>(data.f1.size(0)) + 1U) {
    b_rtErrorWithMessageID("time_start_s", v_emlrtRTEI.fName,
                           v_emlrtRTEI.lineNo);
  }
  t.data.f10.set_size(data.f10.size(0) + 1);
  loop_ub = data.f10.size(0);
  for (i = 0; i < loop_ub; i++) {
    t.data.f10[i] = data.f10[i];
  }
  t.data.f10[data.f10.size(0)] = varargin_2.data.f10;
  if (static_cast<unsigned int>(t.data.f10.size(0)) !=
      static_cast<unsigned int>(data.f1.size(0)) + 1U) {
    b_rtErrorWithMessageID("time_end_s", v_emlrtRTEI.fName, v_emlrtRTEI.lineNo);
  }
  t.b_metaDim = b_metaDim;
  t.rowDim.length = static_cast<double>(data.f1.size(0)) + 1.0;
  indices.set_size(1, indices.size(1));
  if (static_cast<double>(data.f1.size(0)) + 1.0 != data.f1.size(0) + 1) {
    rtIntegerError(static_cast<double>(data.f1.size(0)) + 1.0, d_emlrtDCI);
  }
  indices.set_size(indices.size(0), data.f1.size(0) + 1);
  i = data.f1.size(0);
  for (loop_ub = 0; loop_ub <= i; loop_ub++) {
    if ((static_cast<int>(static_cast<unsigned int>(loop_ub) + 1U) < 1) ||
        (static_cast<int>(static_cast<unsigned int>(loop_ub) + 1U) >
         indices.size(1))) {
      rtDynamicBoundsError(
          static_cast<int>(static_cast<unsigned int>(loop_ub) + 1U), 1,
          indices.size(1), emlrtBCI);
    }
    indices[loop_ub] = static_cast<unsigned int>(loop_ub) + 1U;
  }
}

} // namespace coder

//
// File trailer for table.cpp
//
// [EOF]
//
