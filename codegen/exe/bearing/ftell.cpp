//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: ftell.cpp
//
// MATLAB Coder version            : 23.2
// C/C++ source code generated on  : 07-Nov-2023 14:21:19
//

// Include Files
#include "ftell.h"
#include "bearing_data.h"
#include "bearing_rtwutil.h"
#include "bearing_types.h"
#include "fileManager.h"
#include "rt_nonfinite.h"
#include <cstdio>

// Function Definitions
//
// Arguments    : double fileID
// Return Type  : double
//
namespace coder {
double b_ftell(double fileID)
{
  std::FILE *f;
  std::FILE *filestar;
  double position;
  boolean_T a;
  f = internal::getfilestar(fileID, a);
  filestar = f;
  if (f == nullptr) {
    b_rtErrorWithMessageID(k_emlrtRTEI.fName, k_emlrtRTEI.lineNo);
  }
  if ((!(fileID != 0.0)) || (!(fileID != 1.0)) || (!(fileID != 2.0))) {
    filestar = nullptr;
  }
  if (filestar == nullptr) {
    position = -1.0;
  } else {
    long position_t;
    position_t = std::ftell(filestar);
    position = (double)position_t;
  }
  return position;
}

} // namespace coder

//
// File trailer for ftell.cpp
//
// [EOF]
//
