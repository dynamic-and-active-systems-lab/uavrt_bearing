//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: fseek.cpp
//
// MATLAB Coder version            : 5.6
// C/C++ source code generated on  : 27-Jun-2023 16:44:57
//

// Include Files
#include "fseek.h"
#include "bearing_data.h"
#include "bearing_rtwutil.h"
#include "bearing_types.h"
#include "fileManager.h"
#include "rt_nonfinite.h"
#include <cmath>
#include <cstdio>

// Function Definitions
//
// Arguments    : double fileID
//                double offset
// Return Type  : double
//
namespace coder {
double cfseek(double fileID, double offset)
{
  int wherefrom;
  std::FILE *f;
  std::FILE *filestar;
  double status;
  boolean_T a;
  wherefrom = SEEK_SET;
  if ((!std::isinf(offset)) && (!std::isnan(offset)) &&
      (std::floor(offset) == offset)) {
    f = internal::getfilestar(fileID, a);
    filestar = f;
    if (f == nullptr) {
      rtErrorWithMessageID(e_emlrtRTEI.fName, e_emlrtRTEI.lineNo);
    }
    if ((!(fileID != 0.0)) || (!(fileID != 1.0)) || (!(fileID != 2.0))) {
      filestar = nullptr;
    }
    if (filestar == nullptr) {
      status = -1.0;
    } else {
      int status_int;
      status_int = std::fseek(filestar, (long int)offset, wherefrom);
      if (status_int == 0) {
        status = 0.0;
      } else {
        status = -1.0;
      }
    }
  } else {
    status = -1.0;
  }
  return status;
}

} // namespace coder

//
// File trailer for fseek.cpp
//
// [EOF]
//
