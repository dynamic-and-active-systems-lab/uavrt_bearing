//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: nullAssignment.cpp
//
// MATLAB Coder version            : 23.2
// C/C++ source code generated on  : 03-Oct-2023 13:40:05
//

// Include Files
#include "nullAssignment.h"
#include "bearing_data.h"
#include "bearing_rtwutil.h"
#include "bearing_types.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Variable Definitions
static rtRunTimeErrorInfo t_emlrtRTEI{
    81,               // lineNo
    "validate_inputs" // fName
};

static rtRunTimeErrorInfo u_emlrtRTEI{
    296,          // lineNo
    "delete_rows" // fName
};

// Function Definitions
//
// Arguments    : array<double, 2U> &x
//                const array<int, 2U> &idx
// Return Type  : void
//
namespace coder {
namespace internal {
void b_nullAssignment(array<double, 2U> &x, const array<int, 2U> &idx)
{
  array<boolean_T, 2U> b;
  int k;
  int n;
  int nrows;
  int nrowx;
  boolean_T exitg1;
  boolean_T p;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= idx.size(1) - 1)) {
    if (idx[k] > x.size(0)) {
      p = false;
      exitg1 = true;
    } else {
      k++;
    }
  }
  if (!p) {
    u_rtErrorWithMessageID(t_emlrtRTEI.fName, t_emlrtRTEI.lineNo);
  }
  nrowx = x.size(0);
  if (idx.size(1) == 1) {
    nrows = x.size(0) - 1;
    k = idx[0];
    for (n = 0; n < 4; n++) {
      for (int i{k}; i <= nrows; i++) {
        x[(i + x.size(0) * n) - 1] = x[i + x.size(0) * n];
      }
    }
  } else {
    int i;
    b.set_size(1, x.size(0));
    nrows = x.size(0);
    for (k = 0; k < nrows; k++) {
      b[k] = false;
    }
    nrows = idx.size(1);
    if (idx.size(1) > 2147483646) {
      check_forloop_overflow_error();
    }
    for (k = 0; k < nrows; k++) {
      b[idx[k] - 1] = true;
    }
    n = 0;
    nrows = b.size(1);
    if (b.size(1) > 2147483646) {
      check_forloop_overflow_error();
    }
    for (k = 0; k < nrows; k++) {
      n += b[k];
    }
    nrows = x.size(0) - n;
    i = 0;
    if (x.size(0) > 2147483646) {
      check_forloop_overflow_error();
    }
    for (k = 0; k < nrowx; k++) {
      if ((k + 1 > b.size(1)) || (!b[k])) {
        x[i] = x[k];
        x[i + x.size(0)] = x[k + x.size(0)];
        x[i + x.size(0) * 2] = x[k + x.size(0) * 2];
        x[i + x.size(0) * 3] = x[k + x.size(0) * 3];
        i++;
      }
    }
  }
  if (nrows > x.size(0)) {
    g_rtErrorWithMessageID(u_emlrtRTEI.fName, u_emlrtRTEI.lineNo);
  }
  if (nrows < 1) {
    nrows = 0;
  }
  for (k = 0; k < 4; k++) {
    for (n = 0; n < nrows; n++) {
      x[n + nrows * k] = x[n + x.size(0) * k];
    }
  }
  x.set_size(nrows, 4);
}

//
// Arguments    : array<double, 2U> &x
//                const array<int, 2U> &idx
// Return Type  : void
//
void nullAssignment(array<double, 2U> &x, const array<int, 2U> &idx)
{
  array<boolean_T, 2U> b;
  int i;
  int k;
  int nrows;
  int nrowx;
  boolean_T exitg1;
  boolean_T p;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= idx.size(1) - 1)) {
    if (idx[k] > x.size(0)) {
      p = false;
      exitg1 = true;
    } else {
      k++;
    }
  }
  if (!p) {
    u_rtErrorWithMessageID(t_emlrtRTEI.fName, t_emlrtRTEI.lineNo);
  }
  nrowx = x.size(0);
  if (idx.size(1) == 1) {
    nrows = x.size(0) - 1;
    k = idx[0];
    for (int j{0}; j < 21; j++) {
      for (i = k; i <= nrows; i++) {
        x[(i + x.size(0) * j) - 1] = x[i + x.size(0) * j];
      }
    }
  } else {
    b.set_size(1, x.size(0));
    nrows = x.size(0);
    for (k = 0; k < nrows; k++) {
      b[k] = false;
    }
    nrows = idx.size(1);
    if (idx.size(1) > 2147483646) {
      check_forloop_overflow_error();
    }
    for (k = 0; k < nrows; k++) {
      b[idx[k] - 1] = true;
    }
    i = 0;
    nrows = b.size(1);
    if (b.size(1) > 2147483646) {
      check_forloop_overflow_error();
    }
    for (k = 0; k < nrows; k++) {
      i += b[k];
    }
    nrows = x.size(0) - i;
    i = 0;
    if (x.size(0) > 2147483646) {
      check_forloop_overflow_error();
    }
    for (k = 0; k < nrowx; k++) {
      if ((k + 1 > b.size(1)) || (!b[k])) {
        for (int j{0}; j < 21; j++) {
          x[i + x.size(0) * j] = x[k + x.size(0) * j];
        }
        i++;
      }
    }
  }
  if (nrows > x.size(0)) {
    g_rtErrorWithMessageID(u_emlrtRTEI.fName, u_emlrtRTEI.lineNo);
  }
  if (nrows < 1) {
    nrows = 0;
  }
  for (k = 0; k < 21; k++) {
    for (i = 0; i < nrows; i++) {
      x[i + nrows * k] = x[i + x.size(0) * k];
    }
  }
  x.set_size(nrows, 21);
}

//
// Arguments    : array<double, 1U> &x
//                const array<int, 2U> &idx
// Return Type  : void
//
void nullAssignment(array<double, 1U> &x, const array<int, 2U> &idx)
{
  static rtRunTimeErrorInfo v_emlrtRTEI{
      181,                     // lineNo
      "onearg_null_assignment" // fName
  };
  array<boolean_T, 2U> b;
  int k;
  int k0;
  int nxin;
  int nxout;
  boolean_T exitg1;
  boolean_T p;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= idx.size(1) - 1)) {
    if (idx[k] > x.size(0)) {
      p = false;
      exitg1 = true;
    } else {
      k++;
    }
  }
  if (!p) {
    u_rtErrorWithMessageID(s_emlrtRTEI.fName, s_emlrtRTEI.lineNo);
  }
  nxin = x.size(0);
  b.set_size(1, x.size(0));
  nxout = x.size(0);
  for (k0 = 0; k0 < nxout; k0++) {
    b[k0] = false;
  }
  nxout = idx.size(1);
  if (idx.size(1) > 2147483646) {
    check_forloop_overflow_error();
  }
  for (k = 0; k < nxout; k++) {
    b[idx[k] - 1] = true;
  }
  k0 = 0;
  nxout = b.size(1);
  if (b.size(1) > 2147483646) {
    check_forloop_overflow_error();
  }
  for (k = 0; k < nxout; k++) {
    k0 += b[k];
  }
  nxout = x.size(0) - k0;
  k0 = -1;
  if (x.size(0) > 2147483646) {
    check_forloop_overflow_error();
  }
  for (k = 0; k < nxin; k++) {
    if ((k + 1 > b.size(1)) || (!b[k])) {
      k0++;
      x[k0] = x[k];
    }
  }
  if (nxout > x.size(0)) {
    g_rtErrorWithMessageID(v_emlrtRTEI.fName, v_emlrtRTEI.lineNo);
  }
  if (nxout < 1) {
    nxout = 0;
  }
  x.set_size(nxout);
}

//
// Arguments    : array<double, 2U> &x
//                const array<int, 1U> &idx
// Return Type  : void
//
void nullAssignment(array<double, 2U> &x, const array<int, 1U> &idx)
{
  array<boolean_T, 2U> b;
  int i;
  int k;
  int nrows;
  int nrowx;
  boolean_T exitg1;
  boolean_T p;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= idx.size(0) - 1)) {
    if (idx[k] > x.size(0)) {
      p = false;
      exitg1 = true;
    } else {
      k++;
    }
  }
  if (!p) {
    u_rtErrorWithMessageID(t_emlrtRTEI.fName, t_emlrtRTEI.lineNo);
  }
  nrowx = x.size(0);
  if (idx.size(0) == 1) {
    nrows = x.size(0) - 1;
    k = idx[0];
    for (int j{0}; j < 21; j++) {
      for (i = k; i <= nrows; i++) {
        x[(i + x.size(0) * j) - 1] = x[i + x.size(0) * j];
      }
    }
  } else {
    b.set_size(1, x.size(0));
    nrows = x.size(0);
    for (k = 0; k < nrows; k++) {
      b[k] = false;
    }
    nrows = idx.size(0);
    if (idx.size(0) > 2147483646) {
      check_forloop_overflow_error();
    }
    for (k = 0; k < nrows; k++) {
      b[idx[k] - 1] = true;
    }
    i = 0;
    nrows = b.size(1);
    if (b.size(1) > 2147483646) {
      check_forloop_overflow_error();
    }
    for (k = 0; k < nrows; k++) {
      i += b[k];
    }
    nrows = x.size(0) - i;
    i = 0;
    if (x.size(0) > 2147483646) {
      check_forloop_overflow_error();
    }
    for (k = 0; k < nrowx; k++) {
      if ((k + 1 > b.size(1)) || (!b[k])) {
        for (int j{0}; j < 21; j++) {
          x[i + x.size(0) * j] = x[k + x.size(0) * j];
        }
        i++;
      }
    }
  }
  if (nrows > x.size(0)) {
    g_rtErrorWithMessageID(u_emlrtRTEI.fName, u_emlrtRTEI.lineNo);
  }
  if (nrows < 1) {
    nrows = 0;
  }
  for (k = 0; k < 21; k++) {
    for (i = 0; i < nrows; i++) {
      x[i + nrows * k] = x[i + x.size(0) * k];
    }
  }
  x.set_size(nrows, 21);
}

} // namespace internal
} // namespace coder

//
// File trailer for nullAssignment.cpp
//
// [EOF]
//
