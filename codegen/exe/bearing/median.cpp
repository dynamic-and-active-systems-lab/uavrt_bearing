//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: median.cpp
//
// MATLAB Coder version            : 23.2
// C/C++ source code generated on  : 03-Oct-2023 13:40:05
//

// Include Files
#include "median.h"
#include "eml_int_forloop_overflow_check.h"
#include "quickselect.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
//
// Arguments    : const array<double, 2U> &x
// Return Type  : double
//
namespace coder {
double median(const array<double, 2U> &x)
{
  array<double, 1U> a__4;
  double y;
  int a__6;
  int k;
  int vlen;
  vlen = x.size(1);
  if (x.size(1) == 0) {
    y = rtNaN;
  } else {
    if (x.size(1) > 2147483646) {
      check_forloop_overflow_error();
    }
    k = 0;
    int exitg1;
    do {
      exitg1 = 0;
      if (k <= vlen - 1) {
        if (std::isnan(x[k])) {
          y = rtNaN;
          exitg1 = 1;
        } else {
          k++;
        }
      } else {
        if (vlen <= 4) {
          if (vlen == 0) {
            y = rtNaN;
          } else if (vlen == 1) {
            y = x[0];
          } else if (vlen == 2) {
            if (((x[0] < 0.0) != (x[1] < 0.0)) || std::isinf(x[0])) {
              y = (x[0] + x[1]) / 2.0;
            } else {
              y = x[0] + (x[1] - x[0]) / 2.0;
            }
          } else if (vlen == 3) {
            if (x[0] < x[1]) {
              if (x[1] < x[2]) {
                a__6 = 1;
              } else if (x[0] < x[2]) {
                a__6 = 2;
              } else {
                a__6 = 0;
              }
            } else if (x[0] < x[2]) {
              a__6 = 0;
            } else if (x[1] < x[2]) {
              a__6 = 2;
            } else {
              a__6 = 1;
            }
            y = x[a__6];
          } else {
            if (x[0] < x[1]) {
              if (x[1] < x[2]) {
                k = 0;
                a__6 = 1;
                vlen = 2;
              } else if (x[0] < x[2]) {
                k = 0;
                a__6 = 2;
                vlen = 1;
              } else {
                k = 2;
                a__6 = 0;
                vlen = 1;
              }
            } else if (x[0] < x[2]) {
              k = 1;
              a__6 = 0;
              vlen = 2;
            } else if (x[1] < x[2]) {
              k = 1;
              a__6 = 2;
              vlen = 0;
            } else {
              k = 2;
              a__6 = 1;
              vlen = 0;
            }
            if (x[k] < x[3]) {
              if (x[3] < x[vlen]) {
                if (((x[a__6] < 0.0) != (x[3] < 0.0)) || std::isinf(x[a__6])) {
                  y = (x[a__6] + x[3]) / 2.0;
                } else {
                  y = x[a__6] + (x[3] - x[a__6]) / 2.0;
                }
              } else if (((x[a__6] < 0.0) != (x[vlen] < 0.0)) ||
                         std::isinf(x[a__6])) {
                y = (x[a__6] + x[vlen]) / 2.0;
              } else {
                y = x[a__6] + (x[vlen] - x[a__6]) / 2.0;
              }
            } else if (((x[k] < 0.0) != (x[a__6] < 0.0)) || std::isinf(x[k])) {
              y = (x[k] + x[a__6]) / 2.0;
            } else {
              y = x[k] + (x[a__6] - x[k]) / 2.0;
            }
          }
        } else {
          int midm1;
          midm1 = vlen >> 1;
          if ((vlen & 1) == 0) {
            a__4.set_size(x.size(1));
            k = x.size(1);
            for (a__6 = 0; a__6 < k; a__6++) {
              a__4[a__6] = x[a__6];
            }
            y = internal::quickselect(a__4, midm1 + 1, vlen, k, a__6);
            if (midm1 < k) {
              double b;
              b = internal::quickselect(a__4, midm1, a__6 - 1, k, vlen);
              if (((y < 0.0) != (b < 0.0)) || std::isinf(y)) {
                y = (y + b) / 2.0;
              } else {
                y += (b - y) / 2.0;
              }
            }
          } else {
            a__4.set_size(x.size(1));
            k = x.size(1);
            for (a__6 = 0; a__6 < k; a__6++) {
              a__4[a__6] = x[a__6];
            }
            y = internal::quickselect(a__4, midm1 + 1, vlen, k, a__6);
          }
        }
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  return y;
}

} // namespace coder

//
// File trailer for median.cpp
//
// [EOF]
//
