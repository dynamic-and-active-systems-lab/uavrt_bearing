//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: unique.cpp
//
// MATLAB Coder version            : 5.6
// C/C++ source code generated on  : 03-Oct-2023 08:03:05
//

// Include Files
#include "unique.h"
#include "bearing_rtwutil.h"
#include "bearing_types.h"
#include "eml_int_forloop_overflow_check.h"
#include "indexShapeCheck.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
//
// Arguments    : const ::coder::array<double, 1U> &a
//                ::coder::array<double, 1U> &b
// Return Type  : void
//
namespace coder {
void unique_vector(const ::coder::array<double, 1U> &a,
                   ::coder::array<double, 1U> &b)
{
  static rtRunTimeErrorInfo v_emlrtRTEI{
      241,            // lineNo
      "unique_vector" // fName
  };
  array<int, 1U> idx;
  array<int, 1U> iwork;
  double x;
  int iv[2];
  int b_i;
  int i;
  int i2;
  int j;
  int k;
  int n;
  int na;
  int nb;
  int pEnd;
  int q;
  int qEnd;
  na = a.size(0);
  n = a.size(0) + 1;
  idx.set_size(a.size(0));
  i = a.size(0);
  for (b_i = 0; b_i < i; b_i++) {
    idx[b_i] = 0;
  }
  if (a.size(0) != 0) {
    iwork.set_size(a.size(0));
    i = a.size(0) - 1;
    if (a.size(0) - 1 > 2147483645) {
      check_forloop_overflow_error();
    }
    for (k = 1; k <= i; k += 2) {
      if ((a[k - 1] <= a[k]) || std::isnan(a[k])) {
        idx[k - 1] = k;
        idx[k] = k + 1;
      } else {
        idx[k - 1] = k + 1;
        idx[k] = k;
      }
    }
    if ((a.size(0) & 1) != 0) {
      idx[a.size(0) - 1] = a.size(0);
    }
    i = 2;
    while (i < n - 1) {
      i2 = i << 1;
      j = 1;
      for (pEnd = i + 1; pEnd < n; pEnd = qEnd + i) {
        int kEnd;
        nb = j;
        q = pEnd - 1;
        qEnd = j + i2;
        if (qEnd > n) {
          qEnd = n;
        }
        k = 0;
        kEnd = qEnd - j;
        while (k + 1 <= kEnd) {
          x = a[idx[q] - 1];
          b_i = idx[nb - 1];
          if ((a[b_i - 1] <= x) || std::isnan(x)) {
            iwork[k] = b_i;
            nb++;
            if (nb == pEnd) {
              while (q + 1 < qEnd) {
                k++;
                iwork[k] = idx[q];
                q++;
              }
            }
          } else {
            iwork[k] = idx[q];
            q++;
            if (q + 1 == qEnd) {
              while (nb < pEnd) {
                k++;
                iwork[k] = idx[nb - 1];
                nb++;
              }
            }
          }
          k++;
        }
        for (k = 0; k < kEnd; k++) {
          idx[(j + k) - 1] = iwork[k];
        }
        j = qEnd;
      }
      i = i2;
    }
  }
  b.set_size(a.size(0));
  if (a.size(0) > 2147483646) {
    check_forloop_overflow_error();
  }
  for (k = 0; k < na; k++) {
    b[k] = a[idx[k] - 1];
  }
  k = a.size(0);
  while ((k >= 1) && std::isnan(b[k - 1])) {
    k--;
  }
  pEnd = a.size(0) - k;
  while ((k >= 1) && std::isinf(b[k - 1])) {
    k--;
  }
  i = (a.size(0) - k) - pEnd;
  nb = 0;
  q = 0;
  while (q + 1 <= k) {
    x = b[q];
    i2 = q;
    do {
      q++;
    } while (!((q + 1 > k) || (b[q] != x)));
    nb++;
    b[nb - 1] = x;
    if ((i2 + 1 <= q) && (q > 2147483646)) {
      check_forloop_overflow_error();
    }
  }
  if (i > 0) {
    nb++;
    b[nb - 1] = b[k];
    if (i > 2147483646) {
      check_forloop_overflow_error();
    }
  }
  q = k + i;
  for (j = 0; j < pEnd; j++) {
    b[nb + j] = b[q + j];
  }
  nb += pEnd;
  if (nb > a.size(0)) {
    g_rtErrorWithMessageID(v_emlrtRTEI.fName, v_emlrtRTEI.lineNo);
  }
  if (nb < 1) {
    b_i = 0;
  } else {
    b_i = nb;
  }
  iv[0] = 1;
  iv[1] = b_i;
  internal::indexShapeCheck(b.size(0), iv);
  b.set_size(b_i);
}

} // namespace coder

//
// File trailer for unique.cpp
//
// [EOF]
//
