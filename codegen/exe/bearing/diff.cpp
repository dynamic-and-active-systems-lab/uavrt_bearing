//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: diff.cpp
//
// MATLAB Coder version            : 5.6
// C/C++ source code generated on  : 30-Jun-2023 15:05:26
//

// Include Files
#include "diff.h"
#include "bearing_types.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <sstream>
#include <stdexcept>
#include <string>

// Function Declarations
static void s_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

// Function Definitions
//
// Arguments    : const char *aFcnName
//                int aLineNum
// Return Type  : void
//
static void s_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::stringstream outStream;
  outStream
      << "The dimension to operate along was selected automatically, is "
         "variable-length, and has length 1 at run time. This is not support"
         "ed. Manually select the dimension to operate along by supplying the "
         "DIM argument.";
  outStream << "\n";
  ((((outStream << "Error in ") << aFcnName) << " (line ") << aLineNum) << ")";
  throw std::runtime_error(outStream.str());
}

//
// Arguments    : const ::coder::array<double, 1U> &x
//                ::coder::array<double, 1U> &y
// Return Type  : void
//
namespace coder {
void diff(const ::coder::array<double, 1U> &x, ::coder::array<double, 1U> &y)
{
  static rtRunTimeErrorInfo r_emlrtRTEI{
      51,    // lineNo
      "diff" // fName
  };
  int dimSize;
  dimSize = x.size(0);
  if (x.size(0) == 0) {
    y.set_size(0);
  } else {
    int u0;
    u0 = x.size(0) - 1;
    if (u0 > 1) {
      u0 = 1;
    }
    if (u0 < 1) {
      y.set_size(0);
    } else {
      double work_data;
      if (x.size(0) == 1) {
        s_rtErrorWithMessageID(r_emlrtRTEI.fName, r_emlrtRTEI.lineNo);
      }
      y.set_size(x.size(0) - 1);
      work_data = x[0];
      if (x.size(0) > 2147483646) {
        check_forloop_overflow_error();
      }
      for (u0 = 2; u0 <= dimSize; u0++) {
        double tmp2;
        tmp2 = work_data;
        work_data = x[u0 - 1];
        y[u0 - 2] = work_data - tmp2;
      }
    }
  }
}

} // namespace coder

//
// File trailer for diff.cpp
//
// [EOF]
//
