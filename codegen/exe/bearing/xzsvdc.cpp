//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xzsvdc.cpp
//
// MATLAB Coder version            : 23.2
// C/C++ source code generated on  : 03-Oct-2023 13:40:05
//

// Include Files
#include "xzsvdc.h"
#include "bearing_types.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "xaxpy.h"
#include "xdotc.h"
#include "xnrm2.h"
#include "xrot.h"
#include "xrotg.h"
#include "xscal.h"
#include "xswap.h"
#include "coder_array.h"
#include <algorithm>
#include <cmath>
#include <cstring>
#include <sstream>
#include <stdexcept>
#include <string>

// Function Declarations
static void b_rtErrorWithMessageID(const char *r, const char *aFcnName,
                                   int aLineNum);

static void s_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

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
  ((outStream << "Domain error. To compute complex results from real x, use \'")
   << r)
      << "(complex(x))\'.";
  outStream << "\n";
  ((((outStream << "Error in ") << aFcnName) << " (line ") << aLineNum) << ")";
  throw std::runtime_error(outStream.str());
}

//
// Arguments    : const char *aFcnName
//                int aLineNum
// Return Type  : void
//
static void s_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::stringstream outStream;
  outStream << "SVD fails to converge";
  outStream << "\n";
  ((((outStream << "Error in ") << aFcnName) << " (line ") << aLineNum) << ")";
  throw std::runtime_error(outStream.str());
}

//
// Arguments    : array<double, 2U> &A
//                array<double, 2U> &U
//                double S_data[]
//                double V[4]
// Return Type  : int
//
namespace coder {
namespace internal {
namespace reflapack {
int xzsvdc(array<double, 2U> &A, array<double, 2U> &U, double S_data[],
           double V[4])
{
  static rtRunTimeErrorInfo v_emlrtRTEI{
      269,     // lineNo
      "xzsvdc" // fName
  };
  static rtRunTimeErrorInfo w_emlrtRTEI{
      13,    // lineNo
      "sqrt" // fName
  };
  double e[2];
  double s_data[2];
  double f;
  double nrm;
  double sm;
  int S_size;
  int n;
  int ns;
  int qp1;
  n = A.size(0);
  if (A.size(0) + 1 <= 2) {
    ns = A.size(0);
  } else {
    ns = 1;
  }
  S_size = A.size(0);
  if (S_size > 2) {
    S_size = 2;
  }
  std::memset(&s_data[0], 0,
              static_cast<unsigned int>(ns + 1) * sizeof(double));
  e[0] = 0.0;
  e[1] = 0.0;
  U.set_size(A.size(0), A.size(0));
  ns = A.size(0) * A.size(0);
  for (qp1 = 0; qp1 < ns; qp1++) {
    U[qp1] = 0.0;
  }
  V[0] = 0.0;
  V[1] = 0.0;
  V[2] = 0.0;
  V[3] = 0.0;
  if (A.size(0) == 0) {
    V[0] = 1.0;
    V[3] = 1.0;
  } else {
    double b;
    double rt;
    double snorm;
    int ii;
    int m;
    int nct;
    int nctp1;
    int nmq;
    int qq;
    boolean_T exitg1;
    nct = A.size(0) - 1;
    if (nct > 2) {
      nct = 2;
    }
    nctp1 = nct + 1;
    for (int q{0}; q < nct; q++) {
      boolean_T apply_transform;
      qp1 = q + 2;
      qq = (q + n * q) + 1;
      nmq = n - q;
      apply_transform = false;
      if (q + 1 <= nct) {
        nrm = blas::xnrm2(nmq, A, qq);
        if (nrm > 0.0) {
          apply_transform = true;
          if (A[qq - 1] < 0.0) {
            b = -nrm;
          } else {
            b = nrm;
          }
          s_data[q] = b;
          if (std::abs(b) >= 1.0020841800044864E-292) {
            blas::xscal(nmq, 1.0 / b, A, qq);
          } else {
            ns = ((qq + n) - q) - 1;
            if ((qq <= ns) && (ns > 2147483646)) {
              check_forloop_overflow_error();
            }
            for (int k{qq}; k <= ns; k++) {
              A[k - 1] = A[k - 1] / s_data[q];
            }
          }
          A[qq - 1] = A[qq - 1] + 1.0;
          s_data[q] = -s_data[q];
        } else {
          s_data[q] = 0.0;
        }
      }
      for (int k{qp1}; k < 3; k++) {
        ns = q + n;
        if (apply_transform) {
          nrm = blas::xdotc(nmq, A, qq, A, ns + 1);
          nrm = -(nrm / A[q + A.size(0) * q]);
          blas::xaxpy(nmq, nrm, qq, A, ns + 1);
        }
        e[1] = A[ns];
      }
      if (q + 1 <= nct) {
        if ((q + 1 <= n) && (n > 2147483646)) {
          check_forloop_overflow_error();
        }
        for (ii = q + 1; ii <= n; ii++) {
          U[(ii + U.size(0) * q) - 1] = A[(ii + A.size(0) * q) - 1];
        }
      }
    }
    if (A.size(0) + 1 >= 2) {
      m = 2;
    } else {
      m = A.size(0) + 1;
    }
    if (nct < 2) {
      s_data[nct] = A[nct + A.size(0) * nct];
    }
    if (A.size(0) < m) {
      s_data[m - 1] = 0.0;
    }
    if (m > 1) {
      e[0] = A[A.size(0)];
    }
    e[m - 1] = 0.0;
    if (nct + 1 <= A.size(0)) {
      if ((nct + 1 <= A.size(0)) && (A.size(0) > 2147483646)) {
        check_forloop_overflow_error();
      }
      for (int k{nctp1}; k <= n; k++) {
        if (n > 2147483646) {
          check_forloop_overflow_error();
        }
        for (ii = 0; ii < n; ii++) {
          U[ii + U.size(0) * (k - 1)] = 0.0;
        }
        U[(k + U.size(0) * (k - 1)) - 1] = 1.0;
      }
    }
    for (int q{nct}; q >= 1; q--) {
      qp1 = q + 1;
      nmq = (n - q) + 1;
      qq = (q + n * (q - 1)) - 1;
      if (s_data[q - 1] != 0.0) {
        if ((q + 1 <= n) && (n > 2147483646)) {
          check_forloop_overflow_error();
        }
        for (int k{qp1}; k <= n; k++) {
          ns = q + n * (k - 1);
          nrm = blas::xdotc(nmq, U, qq + 1, U, ns);
          nrm = -(nrm / U[qq]);
          blas::xaxpy(nmq, nrm, qq + 1, U, ns);
        }
        for (ii = q; ii <= n; ii++) {
          U[(ii + U.size(0) * (q - 1)) - 1] =
              -U[(ii + U.size(0) * (q - 1)) - 1];
        }
        U[qq] = U[qq] + 1.0;
        if (q - 2 >= 0) {
          U[U.size(0) * (q - 1)] = 0.0;
        }
      } else {
        if (n > 2147483646) {
          check_forloop_overflow_error();
        }
        for (ii = 0; ii < n; ii++) {
          U[ii + U.size(0) * (q - 1)] = 0.0;
        }
        U[qq] = 1.0;
      }
    }
    V[2] = 0.0;
    V[3] = 1.0;
    V[1] = 0.0;
    V[0] = 1.0;
    qp1 = static_cast<unsigned char>(m);
    for (int q{0}; q < qp1; q++) {
      b = s_data[q];
      if (b != 0.0) {
        rt = std::abs(b);
        nrm = b / rt;
        s_data[q] = rt;
        if (q + 1 < m) {
          e[0] /= nrm;
        }
        if (q + 1 <= n) {
          blas::xscal(n, nrm, U, n * q + 1);
        }
      }
      if ((q + 1 < m) && (e[0] != 0.0)) {
        rt = std::abs(e[0]);
        nrm = rt / e[0];
        e[0] = rt;
        s_data[1] *= nrm;
        V[2] *= nrm;
        V[3] *= nrm;
      }
    }
    nct = m;
    nctp1 = 0;
    snorm = 0.0;
    for (ii = 0; ii < qp1; ii++) {
      snorm =
          std::fmax(snorm, std::fmax(std::abs(s_data[ii]), std::abs(e[ii])));
    }
    exitg1 = false;
    while ((!exitg1) && (m > 0)) {
      if (nctp1 >= 75) {
        s_rtErrorWithMessageID(v_emlrtRTEI.fName, v_emlrtRTEI.lineNo);
      } else {
        boolean_T exitg2;
        nmq = m - 1;
        ii = m - 1;
        exitg2 = false;
        while (!(exitg2 || (ii == 0))) {
          nrm = std::abs(e[0]);
          if ((nrm <= 2.2204460492503131E-16 *
                          (std::abs(s_data[0]) + std::abs(s_data[1]))) ||
              (nrm <= 1.0020841800044864E-292) ||
              ((nctp1 > 20) && (nrm <= 2.2204460492503131E-16 * snorm))) {
            e[0] = 0.0;
            exitg2 = true;
          } else {
            ii = 0;
          }
        }
        if (ii == m - 1) {
          ns = 4;
        } else {
          qp1 = m;
          ns = m;
          exitg2 = false;
          while ((!exitg2) && (ns >= ii)) {
            qp1 = ns;
            if (ns == ii) {
              exitg2 = true;
            } else {
              nrm = 0.0;
              if (ns < m) {
                nrm = std::abs(e[0]);
              }
              if (ns > ii + 1) {
                nrm += std::abs(e[0]);
              }
              rt = std::abs(s_data[ns - 1]);
              if ((rt <= 2.2204460492503131E-16 * nrm) ||
                  (rt <= 1.0020841800044864E-292)) {
                s_data[ns - 1] = 0.0;
                exitg2 = true;
              } else {
                ns--;
              }
            }
          }
          if (qp1 == ii) {
            ns = 3;
          } else if (qp1 == m) {
            ns = 1;
          } else {
            ns = 2;
            ii = qp1;
          }
        }
        switch (ns) {
        case 1:
          f = e[0];
          e[0] = 0.0;
          for (int k{nmq}; k >= ii + 1; k--) {
            rt = blas::xrotg(s_data[0], f, sm);
            blas::xrot(V, ((m - 1) << 1) + 1, rt, sm);
          }
          break;
        case 2:
          f = e[ii - 1];
          e[ii - 1] = 0.0;
          for (int k{ii + 1}; k <= m; k++) {
            rt = blas::xrotg(s_data[k - 1], f, sm);
            nrm = e[k - 1];
            f = -sm * nrm;
            e[k - 1] = nrm * rt;
            blas::xrot(n, U, n * (k - 1) + 1, n * (ii - 1) + 1, rt, sm);
          }
          break;
        case 3: {
          double scale;
          double sqds;
          nrm = s_data[m - 1];
          scale = std::fmax(
              std::fmax(std::fmax(std::fmax(std::abs(nrm), std::abs(s_data[0])),
                                  std::abs(e[0])),
                        std::abs(s_data[ii])),
              std::abs(e[ii]));
          sm = nrm / scale;
          nrm = s_data[0] / scale;
          rt = e[0] / scale;
          sqds = s_data[ii] / scale;
          b = ((nrm + sm) * (nrm - sm) + rt * rt) / 2.0;
          nrm = sm * rt;
          nrm *= nrm;
          if ((b != 0.0) || (nrm != 0.0)) {
            rt = b * b + nrm;
            if (rt < 0.0) {
              b_rtErrorWithMessageID("sqrt", w_emlrtRTEI.fName,
                                     w_emlrtRTEI.lineNo);
            }
            rt = std::sqrt(rt);
            if (b < 0.0) {
              rt = -rt;
            }
            rt = nrm / (b + rt);
          } else {
            rt = 0.0;
          }
          f = (sqds + sm) * (sqds - sm) + rt;
          nrm = sqds * (e[ii] / scale);
          for (int k{ii + 1}; k < 2; k++) {
            rt = blas::xrotg(f, nrm, sm);
            f = rt * s_data[0] + sm * e[0];
            b = rt * e[0] - sm * s_data[0];
            e[0] = b;
            nrm = sm * s_data[1];
            s_data[1] *= rt;
            blas::xrot(V, 3, rt, sm);
            s_data[0] = f;
            rt = blas::xrotg(s_data[0], nrm, sm);
            f = rt * b + sm * s_data[1];
            s_data[1] = -sm * b + rt * s_data[1];
            nrm = sm * e[1];
            e[1] *= rt;
            if (n > 1) {
              blas::xrot(n, U, 1, n + 1, rt, sm);
            }
          }
          e[0] = f;
          nctp1++;
        } break;
        default:
          if (s_data[ii] < 0.0) {
            s_data[ii] = -s_data[ii];
            blas::xscal(V, (ii << 1) + 1);
          }
          while ((ii + 1 < nct) && (s_data[0] < s_data[1])) {
            rt = s_data[0];
            s_data[0] = s_data[1];
            s_data[1] = rt;
            blas::xswap(V);
            if (n > 1) {
              blas::xswap(n, U, n + 1);
            }
            ii = 1;
          }
          nctp1 = 0;
          m--;
          break;
        }
      }
    }
  }
  if (S_size - 1 >= 0) {
    std::copy(&s_data[0], &s_data[S_size], &S_data[0]);
  }
  return S_size;
}

} // namespace reflapack
} // namespace internal
} // namespace coder

//
// File trailer for xzsvdc.cpp
//
// [EOF]
//
