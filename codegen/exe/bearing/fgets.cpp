//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: fgets.cpp
//
// MATLAB Coder version            : 5.6
// C/C++ source code generated on  : 20-Sep-2023 13:03:40
//

// Include Files
#include "fgets.h"
#include "bearing_data.h"
#include "bearing_rtwutil.h"
#include "bearing_types.h"
#include "eml_int_forloop_overflow_check.h"
#include "fileManager.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdio>
#include <sstream>
#include <stdexcept>
#include <string>

// Function Declarations
static void h_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

static void rtErrorWithMessageID(const int i, const char *aFcnName,
                                 int aLineNum);

// Function Definitions
//
// Arguments    : const char *aFcnName
//                int aLineNum
// Return Type  : void
//
static void h_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::stringstream outStream;
  outStream
      << "File has nothing left to read. To avoid this error, call \'feof\' to "
         "check if you have reached the end of the file before using "
         "\'fgets\' or \'fgetl\'.";
  outStream << "\n";
  ((((outStream << "Error in ") << aFcnName) << " (line ") << aLineNum) << ")";
  throw std::runtime_error(outStream.str());
}

//
// Arguments    : const int i
//                const char *aFcnName
//                int aLineNum
// Return Type  : void
//
static void rtErrorWithMessageID(const int i, const char *aFcnName,
                                 int aLineNum)
{
  std::stringstream outStream;
  ((outStream << "Read illegal non-ASCII character with integer value ") << i)
      << ". For code generation, all characters must have value less than 128.";
  outStream << "\n";
  ((((outStream << "Error in ") << aFcnName) << " (line ") << aLineNum) << ")";
  throw std::runtime_error(outStream.str());
}

//
// Arguments    : double fileID
//                ::coder::array<char, 2U> &b_line
// Return Type  : void
//
namespace coder {
void b_fgets(double fileID, ::coder::array<char, 2U> &b_line)
{
  static rtRunTimeErrorInfo v_emlrtRTEI{
      124,     // lineNo
      "cFgets" // fName
  };
  static rtRunTimeErrorInfo w_emlrtRTEI{
      145,     // lineNo
      "cFgets" // fName
  };
  static rtRunTimeErrorInfo x_emlrtRTEI{
      106,     // lineNo
      "cFgets" // fName
  };
  std::FILE *b_filestar;
  std::FILE *f;
  std::FILE *filestar;
  int b_i;
  int i3;
  int reachedEndOfFile;
  boolean_T newLineAfterCarriageReturn;
  f = internal::getfilestar(fileID, newLineAfterCarriageReturn);
  filestar = f;
  if (f == nullptr) {
    b_rtErrorWithMessageID(i_emlrtRTEI.fName, i_emlrtRTEI.lineNo);
  }
  if ((!(fileID != 0.0)) || (!(fileID != 1.0)) || (!(fileID != 2.0))) {
    filestar = nullptr;
  }
  b_line.set_size(1, 0);
  if (!(filestar == nullptr)) {
    char *cOut;
    int st;
    int wherefrom;
    int exitg1;
    char ReadBuff[1024];
    boolean_T readNewline;
    do {
      exitg1 = 0;
      cOut = std::fgets(&ReadBuff[0], 1024, filestar);
      readNewline = false;
      f = internal::getfilestar(fileID, newLineAfterCarriageReturn);
      if (f == nullptr) {
        b_rtErrorWithMessageID(j_emlrtRTEI.fName, j_emlrtRTEI.lineNo);
      } else {
        st = std::feof(f);
        reachedEndOfFile = ((int)st != 0);
      }
      if ((cOut == nullptr) && (b_line.size(1) == 0)) {
        h_rtErrorWithMessageID(x_emlrtRTEI.fName, x_emlrtRTEI.lineNo);
      }
      if (cOut == nullptr) {
        exitg1 = 1;
      } else {
        int carriageReturnAt;
        int i;
        int i1;
        int idx;
        boolean_T fileEndAfterCarriageReturn;
        idx = 0;
        carriageReturnAt = 0;
        if (reachedEndOfFile != 0) {
          boolean_T exitg2;
          i = 0;
          exitg2 = false;
          while ((!exitg2) && (i < 1024)) {
            if (ReadBuff[i] == '\x00') {
              idx = i;
              exitg2 = true;
            } else {
              if (carriageReturnAt == 0) {
                i1 = static_cast<unsigned char>(ReadBuff[i]);
                if (i1 > 127) {
                  rtErrorWithMessageID(i1, v_emlrtRTEI.fName,
                                       v_emlrtRTEI.lineNo);
                }
              }
              if ((carriageReturnAt == 0) && (ReadBuff[i] == '\r')) {
                carriageReturnAt = i + 1;
              }
              i++;
            }
          }
          if (ReadBuff[idx] == '\x00') {
            idx--;
          }
        } else {
          boolean_T exitg2;
          i = 0;
          exitg2 = false;
          while ((!exitg2) && (i < 1025)) {
            if (i + 1 > 1024) {
              idx = 1022;
              exitg2 = true;
            } else if (ReadBuff[i] == '\n') {
              idx = i;
              exitg2 = true;
            } else {
              if (carriageReturnAt == 0) {
                i1 = static_cast<unsigned char>(ReadBuff[i]);
                if (i1 > 127) {
                  rtErrorWithMessageID(i1, w_emlrtRTEI.fName,
                                       w_emlrtRTEI.lineNo);
                }
              }
              if ((carriageReturnAt == 0) && (ReadBuff[i] == '\r')) {
                carriageReturnAt = i + 1;
              }
              i++;
            }
          }
          readNewline = (ReadBuff[idx] == '\n');
        }
        if ((carriageReturnAt > 0) && (carriageReturnAt < 1024)) {
          newLineAfterCarriageReturn = (ReadBuff[carriageReturnAt] == '\n');
          if ((reachedEndOfFile != 0) &&
              (ReadBuff[carriageReturnAt] == '\x00')) {
            fileEndAfterCarriageReturn = true;
          } else {
            fileEndAfterCarriageReturn = false;
          }
        } else {
          newLineAfterCarriageReturn = false;
          fileEndAfterCarriageReturn = false;
        }
        if ((carriageReturnAt == 0) || newLineAfterCarriageReturn ||
            fileEndAfterCarriageReturn) {
          if (idx + 1 < 1) {
            i = 0;
          } else {
            i = idx + 1;
          }
          i1 = b_line.size(1);
          b_line.set_size(b_line.size(0), b_line.size(1) + i);
          for (int i2{0}; i2 < i; i2++) {
            b_line[i1 + i2] = ReadBuff[i2];
          }
        } else {
          i1 = b_line.size(1);
          b_line.set_size(b_line.size(0), b_line.size(1) + carriageReturnAt);
          for (int i2{0}; i2 < carriageReturnAt; i2++) {
            b_line[i1 + i2] = ReadBuff[i2];
          }
          wherefrom = SEEK_CUR;
          f = internal::getfilestar(fileID, newLineAfterCarriageReturn);
          b_filestar = f;
          if (f == nullptr) {
            b_rtErrorWithMessageID(k_emlrtRTEI.fName, k_emlrtRTEI.lineNo);
          }
          if ((!(fileID != 0.0)) || (!(fileID != 1.0)) || (!(fileID != 2.0))) {
            b_filestar = nullptr;
          }
          if (!(b_filestar == nullptr)) {
            std::fseek(b_filestar, (long int)((carriageReturnAt - idx) - 1),
                       wherefrom);
          }
        }
        if (readNewline || (reachedEndOfFile != 0) || (carriageReturnAt > 0)) {
          exitg1 = 1;
        }
      }
    } while (exitg1 == 0);
    f = internal::getfilestar(fileID, newLineAfterCarriageReturn);
    if (f == nullptr) {
      b_rtErrorWithMessageID(j_emlrtRTEI.fName, j_emlrtRTEI.lineNo);
    } else {
      st = std::feof(f);
      b_i = ((int)st != 0);
    }
    if (b_i == 0) {
      if ((!(fileID != 0.0)) || (!(fileID != 1.0)) || (!(fileID != 2.0))) {
        c_rtErrorWithMessageID(h_emlrtRTEI.fName, h_emlrtRTEI.lineNo);
      }
      f = internal::getfilestar(fileID, newLineAfterCarriageReturn);
      filestar = f;
      if (f == nullptr) {
        b_rtErrorWithMessageID(i_emlrtRTEI.fName, i_emlrtRTEI.lineNo);
      }
      if ((!(fileID != 0.0)) || (!(fileID != 1.0)) || (!(fileID != 2.0))) {
        filestar = nullptr;
      }
      if (!(filestar == nullptr)) {
        size_t numReadSizeT;
        unsigned char buf;
        numReadSizeT =
            std::fread(&buf, sizeof(unsigned char), (size_t)1, filestar);
        if ((int)numReadSizeT > 2147483646) {
          check_forloop_overflow_error();
        }
      }
      f = internal::getfilestar(fileID, newLineAfterCarriageReturn);
      if (f == nullptr) {
        b_rtErrorWithMessageID(j_emlrtRTEI.fName, j_emlrtRTEI.lineNo);
      } else {
        st = std::feof(f);
        i3 = ((int)st != 0);
      }
      if (i3 == 0) {
        wherefrom = SEEK_CUR;
        f = internal::getfilestar(fileID, newLineAfterCarriageReturn);
        filestar = f;
        if (f == nullptr) {
          b_rtErrorWithMessageID(k_emlrtRTEI.fName, k_emlrtRTEI.lineNo);
        }
        if ((!(fileID != 0.0)) || (!(fileID != 1.0)) || (!(fileID != 2.0))) {
          filestar = nullptr;
        }
        if (!(filestar == nullptr)) {
          std::fseek(filestar, (long int)-1.0, wherefrom);
        }
      }
    }
  }
}

} // namespace coder

//
// File trailer for fgets.cpp
//
// [EOF]
//
