//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: fileManager.cpp
//
// MATLAB Coder version            : 23.2
// C/C++ source code generated on  : 07-Nov-2023 14:21:19
//

// Include Files
#include "fileManager.h"
#include "bearing_data.h"
#include "bearing_rtwutil.h"
#include "bearing_types.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cstdio>
#include <sstream>
#include <stdexcept>
#include <string>

// Variable Definitions
static std::FILE *eml_openfiles[20];

static boolean_T eml_autoflush[20];

static rtRunTimeErrorInfo e_emlrtRTEI{
    293,                    // lineNo
    "cast_and_validate_fid" // fName
};

static rtRunTimeErrorInfo f_emlrtRTEI{
    147,          // lineNo
    "getfilestar" // fName
};

static rtRunTimeErrorInfo g_emlrtRTEI{
    297,                    // lineNo
    "cast_and_validate_fid" // fName
};

// Function Declarations
namespace coder {
namespace internal {
static signed char filedata();

}
} // namespace coder
static void f_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

static void x_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

// Function Definitions
//
// Arguments    : void
// Return Type  : signed char
//
namespace coder {
namespace internal {
static signed char filedata()
{
  int k;
  signed char f;
  boolean_T exitg1;
  f = 0;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 20)) {
    if (eml_openfiles[k] == nullptr) {
      f = static_cast<signed char>(k + 1);
      exitg1 = true;
    } else {
      k++;
    }
  }
  return f;
}

//
// Arguments    : const char *aFcnName
//                int aLineNum
// Return Type  : void
//
} // namespace internal
} // namespace coder
static void f_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::stringstream outStream;
  outStream << "Invalid file identifier.  Use fopen to generate a valid file "
               "identifier.";
  outStream << "\n";
  ((((outStream << "Error in ") << aFcnName) << " (line ") << aLineNum) << ")";
  throw std::runtime_error(outStream.str());
}

//
// Arguments    : const char *aFcnName
//                int aLineNum
// Return Type  : void
//
static void x_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::stringstream outStream;
  ((outStream << "For code generation, maximum number of open files is ") << 20)
      << ".";
  outStream << "\n";
  ((((outStream << "Error in ") << aFcnName) << " (line ") << aLineNum) << ")";
  throw std::runtime_error(outStream.str());
}

//
// Arguments    : double fid
// Return Type  : int
//
namespace coder {
namespace internal {
int cfclose(double fid)
{
  static rtRunTimeErrorInfo v_emlrtRTEI{
      168,                // lineNo
      "conditionalAssert" // fName
  };
  std::FILE *f;
  std::FILE *f_tmp;
  int cst;
  int st;
  signed char fileid;
  st = -1;
  if ((fid < 0.0) || (fid > 22.0)) {
    b_rtErrorWithMessageID(e_emlrtRTEI.fName, e_emlrtRTEI.lineNo);
  }
  fileid = static_cast<signed char>(fid);
  if (fid != static_cast<signed char>(fid)) {
    b_rtErrorWithMessageID(g_emlrtRTEI.fName, g_emlrtRTEI.lineNo);
  }
  if (static_cast<int>(fid) != static_cast<signed char>(fid)) {
    fileid = -1;
  }
  if (fileid < 0) {
    b_rtErrorWithMessageID(e_emlrtRTEI.fName, e_emlrtRTEI.lineNo);
  }
  if (fileid >= 3) {
    f_tmp = eml_openfiles[fileid - 3];
    f = f_tmp;
    if (f_tmp == nullptr) {
      f_rtErrorWithMessageID(f_emlrtRTEI.fName, f_emlrtRTEI.lineNo);
    }
  } else if (fileid == 0) {
    f = stdin;
  } else if (fileid == 1) {
    f = stdout;
  } else {
    f = stderr;
  }
  if ((!(f != nullptr)) || (fileid < 3)) {
    b_rtErrorWithMessageID(v_emlrtRTEI.fName, v_emlrtRTEI.lineNo);
  }
  cst = std::fclose(f);
  if (cst == 0) {
    st = 0;
    eml_openfiles[fileid - 3] = nullptr;
    eml_autoflush[fileid - 3] = true;
  }
  return st;
}

//
// Arguments    : const array<char, 2U> &cfilename
//                const char *cpermission
// Return Type  : signed char
//
signed char cfopen(const array<char, 2U> &cfilename, const char *cpermission)
{
  static rtRunTimeErrorInfo v_emlrtRTEI{
      111,     // lineNo
      "cfopen" // fName
  };
  std::FILE *filestar;
  array<char, 2U> ccfilename;
  signed char fileid;
  signed char j;
  fileid = -1;
  j = filedata();
  if (j < 1) {
    x_rtErrorWithMessageID(v_emlrtRTEI.fName, v_emlrtRTEI.lineNo);
  } else {
    int i;
    int loop_ub;
    ccfilename.set_size(1, cfilename.size(1) + 1);
    loop_ub = cfilename.size(1);
    for (i = 0; i < loop_ub; i++) {
      ccfilename[i] = cfilename[i];
    }
    ccfilename[cfilename.size(1)] = '\x00';
    filestar = std::fopen(&ccfilename[0], cpermission);
    if (filestar != nullptr) {
      eml_openfiles[j - 1] = filestar;
      eml_autoflush[j - 1] = true;
      i = j + 2;
      if (j + 2 > 127) {
        i = 127;
      }
      fileid = static_cast<signed char>(i);
    }
  }
  return fileid;
}

//
// Arguments    : double fid
//                boolean_T &autoflush
// Return Type  : std::FILE *
//
std::FILE *getfilestar(double fid, boolean_T &autoflush)
{
  std::FILE *filestar;
  std::FILE *filestar_tmp;
  signed char fileid;
  if ((fid < 0.0) || (fid > 22.0)) {
    b_rtErrorWithMessageID(e_emlrtRTEI.fName, e_emlrtRTEI.lineNo);
  }
  fileid = static_cast<signed char>(fid);
  if (fid != static_cast<signed char>(fid)) {
    b_rtErrorWithMessageID(g_emlrtRTEI.fName, g_emlrtRTEI.lineNo);
  }
  if (static_cast<int>(fid) != static_cast<signed char>(fid)) {
    fileid = -1;
  }
  if (fileid >= 3) {
    autoflush = eml_autoflush[fileid - 3];
    filestar_tmp = eml_openfiles[fileid - 3];
    filestar = filestar_tmp;
    if (filestar_tmp == nullptr) {
      f_rtErrorWithMessageID(f_emlrtRTEI.fName, f_emlrtRTEI.lineNo);
    }
  } else if (fileid == 0) {
    filestar = stdin;
    autoflush = true;
  } else if (fileid == 1) {
    filestar = stdout;
    autoflush = true;
  } else if (fileid == 2) {
    filestar = stderr;
    autoflush = true;
  } else {
    filestar = nullptr;
    autoflush = true;
  }
  return filestar;
}

//
// Arguments    : void
// Return Type  : void
//
} // namespace internal
} // namespace coder
void filedata_init()
{
  for (int i{0}; i < 20; i++) {
    eml_autoflush[i] = false;
  }
  for (int i{0}; i < 20; i++) {
    eml_openfiles[i] = nullptr;
  }
}

//
// File trailer for fileManager.cpp
//
// [EOF]
//
