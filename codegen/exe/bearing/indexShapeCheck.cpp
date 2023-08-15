//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: indexShapeCheck.cpp
//
// MATLAB Coder version            : 5.6
// C/C++ source code generated on  : 15-Aug-2023 14:31:29
//

// Include Files
#include "indexShapeCheck.h"
#include "bearing_types.h"
#include "rt_nonfinite.h"
#include <sstream>
#include <stdexcept>
#include <string>

// Variable Definitions
static rtRunTimeErrorInfo m_emlrtRTEI{
    122,          // lineNo
    "errOrWarnIf" // fName
};

// Function Declarations
static void h_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

static void l_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

static void m_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

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
      << "Compile-time size assumption violated. At run-time, a vector indexes "
         "a scalar, but the compile-time assumption is that the vecto"
         "r is indexed by a vector of the same size.";
  outStream << "\n";
  ((((outStream << "Error in ") << aFcnName) << " (line ") << aLineNum) << ")";
  throw std::runtime_error(outStream.str());
}

//
// Arguments    : const char *aFcnName
//                int aLineNum
// Return Type  : void
//
static void l_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::stringstream outStream;
  outStream
      << "Compile-time size assumption violated. At run-time, a row vector "
         "logical indexes a matrix, but the compile-time assumption is lo"
         "gical indexing for the matrix by a matrix of the same size.";
  outStream << "\n";
  ((((outStream << "Error in ") << aFcnName) << " (line ") << aLineNum) << ")";
  throw std::runtime_error(outStream.str());
}

//
// Arguments    : const char *aFcnName
//                int aLineNum
// Return Type  : void
//
static void m_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::stringstream outStream;
  outStream
      << "Compile-time size assumption violated. At run-time, a matrix logical "
         "indexes a row vector, but the compile-time assumption is lo"
         "gical indexing for the matrix by a matrix of the same size.";
  outStream << "\n";
  ((((outStream << "Error in ") << aFcnName) << " (line ") << aLineNum) << ")";
  throw std::runtime_error(outStream.str());
}

//
// Arguments    : const int matrixSize[2]
//                const int indexSize[2]
// Return Type  : void
//
namespace coder {
namespace internal {
void indexShapeCheck(const int matrixSize[2], const int indexSize[2])
{
  boolean_T nonSingletonDimFound;
  nonSingletonDimFound = (matrixSize[0] != 1);
  if (matrixSize[1] != 1) {
    if (nonSingletonDimFound) {
      nonSingletonDimFound = false;
    } else {
      nonSingletonDimFound = true;
    }
  }
  if (nonSingletonDimFound) {
    nonSingletonDimFound = (matrixSize[0] == 1);
    if (nonSingletonDimFound || (matrixSize[1] != 1)) {
      nonSingletonDimFound = true;
    }
    if (nonSingletonDimFound) {
      l_rtErrorWithMessageID(m_emlrtRTEI.fName, m_emlrtRTEI.lineNo);
    }
  } else {
    nonSingletonDimFound = (indexSize[0] != 1);
    if (indexSize[1] != 1) {
      if (nonSingletonDimFound) {
        nonSingletonDimFound = false;
      } else {
        nonSingletonDimFound = true;
      }
    }
    if (nonSingletonDimFound) {
      nonSingletonDimFound = (indexSize[0] == 1);
      if (nonSingletonDimFound || (indexSize[1] != 1)) {
        nonSingletonDimFound = true;
      }
      if (nonSingletonDimFound) {
        m_rtErrorWithMessageID(m_emlrtRTEI.fName, m_emlrtRTEI.lineNo);
      }
    }
  }
}

//
// Arguments    : int matrixSize
//                const int indexSize[2]
// Return Type  : void
//
void indexShapeCheck(int matrixSize, const int indexSize[2])
{
  if ((matrixSize == 1) && (indexSize[1] != 1)) {
    h_rtErrorWithMessageID(m_emlrtRTEI.fName, m_emlrtRTEI.lineNo);
  }
}

} // namespace internal
} // namespace coder

//
// File trailer for indexShapeCheck.cpp
//
// [EOF]
//
