//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: isfile.cpp
//
// MATLAB Coder version            : 5.6
// C/C++ source code generated on  : 15-Aug-2023 14:31:29
//

// Include Files
#include "isfile.h"
#include "bearing_types.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "coder_filestats.h"
#include "coder_platform.h"
#include <sstream>
#include <stdexcept>
#include <string>

// Function Declarations
static void u_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

// Function Definitions
//
// Arguments    : const char *aFcnName
//                int aLineNum
// Return Type  : void
//
static void u_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::stringstream outStream;
  outStream << "{0} must be text.";
  outStream << "\n";
  ((((outStream << "Error in ") << aFcnName) << " (line ") << aLineNum) << ")";
  throw std::runtime_error(outStream.str());
}

//
// Arguments    : const ::coder::array<char, 2U> &fileName
// Return Type  : boolean_T
//
namespace coder {
boolean_T isfile(const ::coder::array<char, 2U> &fileName)
{
  static rtRunTimeErrorInfo x_emlrtRTEI{
      65,                                 // lineNo
      "CoderFileStatsAPI/hIsFileOrFolder" // fName
  };
  array<char, 2U> cFileName;
  int cevalIsFileFolder;
  boolean_T f;
  cFileName.set_size(1, fileName.size(1) + 1);
  cevalIsFileFolder = fileName.size(1);
  for (int i{0}; i < cevalIsFileFolder; i++) {
    cFileName[i] = fileName[i];
  }
  cFileName[fileName.size(1)] = '\x00';
  cevalIsFileFolder = coderIsFileOrFolder(&cFileName[0], 1);
  if (cevalIsFileFolder == -1) {
    f = false;
  } else if (cevalIsFileFolder == 22) {
    u_rtErrorWithMessageID(x_emlrtRTEI.fName, x_emlrtRTEI.lineNo);
  } else {
    f = (cevalIsFileFolder != 0);
  }
  if (!f) {
    char fs;
    boolean_T exitg1;
    boolean_T ipc;
    boolean_T p;
    cevalIsFileFolder = cFileName.size(1) - 1;
    ipc = coderIsPC();
    p = coderIsPC();
    if (p) {
      fs = '\\';
    } else {
      fs = '/';
    }
    exitg1 = false;
    while ((!exitg1) && (cevalIsFileFolder >= 1)) {
      if (ipc) {
        char c;
        c = cFileName[cevalIsFileFolder - 1];
        if ((c != fs) && (c != '/')) {
          exitg1 = true;
        } else {
          cevalIsFileFolder--;
        }
      } else if (cFileName[cevalIsFileFolder - 1] != fs) {
        exitg1 = true;
      } else {
        cevalIsFileFolder--;
      }
    }
    if (cevalIsFileFolder > 0) {
      cFileName[cevalIsFileFolder] = '\x00';
      cevalIsFileFolder = coderIsFileOrFolder(&cFileName[0], 1);
      if (cevalIsFileFolder != -1) {
        if (cevalIsFileFolder == 22) {
          u_rtErrorWithMessageID(x_emlrtRTEI.fName, x_emlrtRTEI.lineNo);
        } else {
          f = (cevalIsFileFolder != 0);
        }
      }
    }
  }
  return f;
}

} // namespace coder

//
// File trailer for isfile.cpp
//
// [EOF]
//
