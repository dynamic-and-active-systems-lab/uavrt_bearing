//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: bearing_rtwutil.cpp
//
// MATLAB Coder version            : 5.6
// C/C++ source code generated on  : 30-Jun-2023 15:05:26
//

// Include Files
#include "bearing_rtwutil.h"
#include "bearing_types.h"
#include "rt_nonfinite.h"
#include "rt_defines.h"
#include <cmath>
#include <sstream>
#include <stdexcept>
#include <string>

// Function Definitions
//
// Arguments    : const char *r
//                const char *aFcnName
//                int aLineNum
// Return Type  : void
//
void b_rtErrorWithMessageID(const char *r, const char *aFcnName, int aLineNum)
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
void b_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::stringstream outStream;
  outStream << "Operation is not implemented for requested file identifier.";
  outStream << "\n";
  ((((outStream << "Error in ") << aFcnName) << " (line ") << aLineNum) << ")";
  throw std::runtime_error(outStream.str());
}

//
// Arguments    : const char *aFcnName
//                int aLineNum
// Return Type  : void
//
void bb_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::stringstream outStream;
  ((((outStream << "Size argument must be an integer in the range: ")
     << MIN_int32_T)
    << " to ")
   << MAX_int32_T)
      << ".";
  outStream << "\n";
  ((((outStream << "Error in ") << aFcnName) << " (line ") << aLineNum) << ")";
  throw std::runtime_error(outStream.str());
}

//
// Arguments    : const int aDim1
//                const int aDim2
//                const rtEqualityCheckInfo &aInfo
// Return Type  : void
//
void emlrtDimSizeImpxCheckR2021b(const int aDim1, const int aDim2,
                                 const rtEqualityCheckInfo &aInfo)
{
  std::stringstream outStream;
  ((((((outStream << "Size mismatch error on dimension ") << aInfo.nDims)
      << ": expected ")
     << aDim1)
    << " or a singleton, but actual size is ")
   << aDim2)
      << ".";
  outStream << "\n";
  ((((outStream << "Error in ") << aInfo.fName) << " (line ") << aInfo.lineNo)
      << ")";
  throw std::runtime_error(outStream.str());
}

//
// Arguments    : const char *aFcnName
//                int aLineNum
// Return Type  : void
//
void g_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::stringstream outStream;
  outStream << "Assertion failed.";
  outStream << "\n";
  ((((outStream << "Error in ") << aFcnName) << " (line ") << aLineNum) << ")";
  throw std::runtime_error(outStream.str());
}

//
// Arguments    : const char *aFcnName
//                int aLineNum
// Return Type  : void
//
void i_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::stringstream outStream;
  outStream << "Dimensions of arrays being concatenated are not consistent.";
  outStream << "\n";
  ((((outStream << "Error in ") << aFcnName) << " (line ") << aLineNum) << ")";
  throw std::runtime_error(outStream.str());
}

//
// Arguments    : int aIndexValue
//                int aLoBound
//                int aHiBound
//                const rtBoundsCheckInfo &aInfo
// Return Type  : void
//
void rtDynamicBoundsError(int aIndexValue, int aLoBound, int aHiBound,
                          const rtBoundsCheckInfo &aInfo)
{
  std::stringstream b_outStream;
  std::stringstream outStream;
  if (aLoBound == 0) {
    aIndexValue++;
    aLoBound = 1;
    aHiBound++;
  }
  if (rtIsNullOrEmptyString(aInfo.aName)) {
    ((((((b_outStream << "Index exceeds array dimensions. Index value ")
         << aIndexValue)
        << " exceeds valid range [")
       << aLoBound)
      << "-")
     << aHiBound)
        << "].";
    b_outStream << "\n";
    ((((b_outStream << "Error in ") << aInfo.fName) << " (line ")
     << aInfo.lineNo)
        << ")";
    throw std::runtime_error(b_outStream.str());
  } else {
    ((((((((outStream << "Index exceeds array dimensions. Index value ")
           << aIndexValue)
          << " exceeds valid range [")
         << aLoBound)
        << "-")
       << aHiBound)
      << "] for array \'")
     << aInfo.aName)
        << "\'.";
    outStream << "\n";
    ((((outStream << "Error in ") << aInfo.fName) << " (line ") << aInfo.lineNo)
        << ")";
    throw std::runtime_error(outStream.str());
  }
}

//
// Arguments    : const char *aFcnName
//                int aLineNum
// Return Type  : void
//
void rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::stringstream outStream;
  outStream << "Invalid file identifier. Use fopen to generate a valid file "
               "identifier.";
  outStream << "\n";
  ((((outStream << "Error in ") << aFcnName) << " (line ") << aLineNum) << ")";
  throw std::runtime_error(outStream.str());
}

//
// Arguments    : const int aNDims
//                const int *aDims
// Return Type  : std::string
//
std::string rtGenSizeString(const int aNDims, const int *aDims)
{
  std::stringstream outStream;
  for (int i{0}; i < aNDims; i++) {
    outStream << "[";
    outStream << aDims[i];
    outStream << "]";
  }
  return outStream.str();
}

//
// Arguments    : const double aInteger
//                const rtDoubleCheckInfo &aInfo
// Return Type  : void
//
void rtIntegerError(const double aInteger, const rtDoubleCheckInfo &aInfo)
{
  std::stringstream outStream;
  ((outStream << "Expected a value representable in the C type \'int\'. Found ")
   << aInteger)
      << " instead.";
  outStream << "\n";
  ((((outStream << "Error in ") << aInfo.fName) << " (line ") << aInfo.lineNo)
      << ")";
  throw std::runtime_error(outStream.str());
}

//
// Arguments    : const char *aString
// Return Type  : boolean_T
//
boolean_T rtIsNullOrEmptyString(const char *aString)
{
  return (aString == nullptr) || (*aString == '\x00');
}

//
// Arguments    : const double aPositive
//                const rtDoubleCheckInfo &aInfo
// Return Type  : void
//
void rtNonNegativeError(const double aPositive, const rtDoubleCheckInfo &aInfo)
{
  std::stringstream outStream;
  ((outStream << "Value ") << aPositive)
      << " is not greater than or equal to zero.\nExiting to prevent memory "
         "corruption.";
  outStream << "\n";
  ((((outStream << "Error in ") << aInfo.fName) << " (line ") << aInfo.lineNo)
      << ")";
  throw std::runtime_error(outStream.str());
}

//
// Arguments    : const int *aDims1
//                const int aNDims1
//                const int *aDims2
//                const int aNDims2
//                const rtEqualityCheckInfo &aInfo
// Return Type  : void
//
void rtSubAssignSizeCheck(const int *aDims1, const int aNDims1,
                          const int *aDims2, const int aNDims2,
                          const rtEqualityCheckInfo &aInfo)
{
  std::stringstream outStream;
  int i;
  int j;
  i = 0;
  j = 0;
  while ((i < aNDims1) && (j < aNDims2)) {
    while ((i < aNDims1) && (aDims1[i] == 1)) {
      i++;
    }
    while ((j < aNDims2) && (aDims2[j] == 1)) {
      j++;
    }
    if (((i < aNDims1) || (j < aNDims2)) &&
        ((i == aNDims1) || ((j == aNDims2) || ((aDims1[i] != -1) &&
                                               ((aDims2[j] != -1) &&
                                                (aDims1[i] != aDims2[j])))))) {
      std::string dims1Str;
      std::string dims2Str;
      dims1Str = rtGenSizeString(aNDims1, aDims1);
      dims2Str = rtGenSizeString(aNDims1, aDims2);
      ((((outStream << "Subscripted assignment dimension mismatch: ")
         << dims1Str)
        << " ~= ")
       << dims2Str)
          << ".";
      outStream << "\n";
      ((((outStream << "Error in ") << aInfo.fName) << " (line ")
       << aInfo.lineNo)
          << ")";
      throw std::runtime_error(outStream.str());
    }
    i++;
    j++;
  }
}

//
// Arguments    : double u0
//                double u1
// Return Type  : double
//
double rt_atan2d_snf(double u0, double u1)
{
  double y;
  if (std::isnan(u0) || std::isnan(u1)) {
    y = rtNaN;
  } else if (std::isinf(u0) && std::isinf(u1)) {
    int i;
    int i1;
    if (u0 > 0.0) {
      i = 1;
    } else {
      i = -1;
    }
    if (u1 > 0.0) {
      i1 = 1;
    } else {
      i1 = -1;
    }
    y = std::atan2(static_cast<double>(i), static_cast<double>(i1));
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = std::atan2(u0, u1);
  }
  return y;
}

//
// Arguments    : const char *aFcnName
//                int aLineNum
// Return Type  : void
//
void v_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::stringstream outStream;
  outStream << "Matrix index is out of range for deletion.";
  outStream << "\n";
  ((((outStream << "Error in ") << aFcnName) << " (line ") << aLineNum) << ")";
  throw std::runtime_error(outStream.str());
}

//
// File trailer for bearing_rtwutil.cpp
//
// [EOF]
//
