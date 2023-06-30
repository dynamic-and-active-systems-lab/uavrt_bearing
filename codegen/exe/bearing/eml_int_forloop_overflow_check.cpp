//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: eml_int_forloop_overflow_check.cpp
//
// MATLAB Coder version            : 5.6
// C/C++ source code generated on  : 30-Jun-2023 15:05:26
//

// Include Files
#include "eml_int_forloop_overflow_check.h"
#include "bearing_types.h"
#include "rt_nonfinite.h"
#include <sstream>
#include <stdexcept>
#include <string>

// Function Declarations
static void d_rtErrorWithMessageID(const char *r, const char *aFcnName,
                                   int aLineNum);

// Function Definitions
//
// Arguments    : const char *r
//                const char *aFcnName
//                int aLineNum
// Return Type  : void
//
static void d_rtErrorWithMessageID(const char *r, const char *aFcnName,
                                   int aLineNum)
{
  std::stringstream outStream;
  ((outStream << "The loop variable of class ") << r)
      << " might overflow on the last iteration of the for loop. This could "
         "lead to an infinite loop.";
  outStream << "\n";
  ((((outStream << "Error in ") << aFcnName) << " (line ") << aLineNum) << ")";
  throw std::runtime_error(outStream.str());
}

//
// Arguments    : void
// Return Type  : void
//
namespace coder {
void check_forloop_overflow_error()
{
  static rtRunTimeErrorInfo r_emlrtRTEI{
      87,                            // lineNo
      "check_forloop_overflow_error" // fName
  };
  d_rtErrorWithMessageID("int32", r_emlrtRTEI.fName, r_emlrtRTEI.lineNo);
}

} // namespace coder

//
// File trailer for eml_int_forloop_overflow_check.cpp
//
// [EOF]
//
