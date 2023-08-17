//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: doapca.cpp
//
// MATLAB Coder version            : 5.6
// C/C++ source code generated on  : 17-Aug-2023 13:24:38
//

// Include Files
#include "doapca.h"
#include "any1.h"
#include "bearing_internal_types.h"
#include "bearing_rtwutil.h"
#include "bearing_types.h"
#include "diff.h"
#include "eml_int_forloop_overflow_check.h"
#include "eye.h"
#include "horzcatStructList.h"
#include "minOrMax.h"
#include "mtimes.h"
#include "rt_nonfinite.h"
#include "sort.h"
#include "sum.h"
#include "svd.h"
#include "wrapTo360.h"
#include "coder_array.h"
#include "rt_defines.h"
#include <cmath>
#include <cstdio>
#include <sstream>
#include <stdexcept>
#include <string>

// Function Declarations
static void b_times(coder::array<double, 1U> &in1,
                    const coder::array<double, 1U> &in2);

static void binary_expand_op(coder::array<double, 2U> &in1, double in2,
                             int in3);

static void emlrtDimSizeImpxCheckR2021b(const int aDim1, const int aDim2,
                                        const rtEqualityCheckInfo &aInfo);

static void k_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

static void l_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

static void m_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

static void n_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

static void o_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

static double rt_atan2d_snf(double u0, double u1);

static double rt_powd_snf(double u0, double u1);

static void times(coder::array<double, 1U> &in1,
                  const coder::array<double, 1U> &in2);

// Function Definitions
//
// Arguments    : coder::array<double, 1U> &in1
//                const coder::array<double, 1U> &in2
// Return Type  : void
//
static void b_times(coder::array<double, 1U> &in1,
                    const coder::array<double, 1U> &in2)
{
  coder::array<double, 1U> b_in2;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  if (in1.size(0) == 1) {
    loop_ub = in2.size(0);
  } else {
    loop_ub = in1.size(0);
  }
  b_in2.set_size(loop_ub);
  stride_0_0 = (in2.size(0) != 1);
  stride_1_0 = (in1.size(0) != 1);
  for (int i{0}; i < loop_ub; i++) {
    b_in2[i] = in2[i * stride_0_0] * in1[i * stride_1_0];
  }
  in1.set_size(b_in2.size(0));
  loop_ub = b_in2.size(0);
  for (int i{0}; i < loop_ub; i++) {
    in1[i] = b_in2[i];
  }
}

//
// Arguments    : coder::array<double, 2U> &in1
//                double in2
//                int in3
// Return Type  : void
//
static void binary_expand_op(coder::array<double, 2U> &in1, double in2, int in3)
{
  coder::array<double, 2U> b_in1;
  int aux_0_1;
  int b_loop_ub;
  int loop_ub;
  int stride_0_0;
  int stride_0_1;
  if (in3 == 1) {
    loop_ub = in1.size(0);
    b_loop_ub = in1.size(1);
  } else {
    loop_ub = in3;
    b_loop_ub = in3;
  }
  b_in1.set_size(loop_ub, b_loop_ub);
  stride_0_0 = (in1.size(0) != 1);
  stride_0_1 = (in1.size(1) != 1);
  aux_0_1 = 0;
  for (int i{0}; i < b_loop_ub; i++) {
    for (int i1{0}; i1 < loop_ub; i1++) {
      b_in1[i1 + b_in1.size(0) * i] =
          in1[i1 * stride_0_0 + in1.size(0) * aux_0_1] - in2;
    }
    aux_0_1 += stride_0_1;
  }
  in1.set_size(b_in1.size(0), b_in1.size(1));
  loop_ub = b_in1.size(1);
  for (int i{0}; i < loop_ub; i++) {
    b_loop_ub = b_in1.size(0);
    for (int i1{0}; i1 < b_loop_ub; i1++) {
      in1[i1 + in1.size(0) * i] = b_in1[i1 + b_in1.size(0) * i];
    }
  }
}

//
// Arguments    : const int aDim1
//                const int aDim2
//                const rtEqualityCheckInfo &aInfo
// Return Type  : void
//
static void emlrtDimSizeImpxCheckR2021b(const int aDim1, const int aDim2,
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
static void k_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::stringstream outStream;
  outStream << "To RESHAPE the number of elements must not change.";
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
      << "To RESHAPE the number of elements must not change, and if the input "
         "is empty, the maximum dimension length cannot be increased u"
         "nless the output size is fixed.";
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
  outStream << "Dimensions of arrays being concatenated are not consistent.";
  outStream << "\n";
  ((((outStream << "Error in ") << aFcnName) << " (line ") << aLineNum) << ")";
  throw std::runtime_error(outStream.str());
}

//
// Arguments    : const char *aFcnName
//                int aLineNum
// Return Type  : void
//
static void n_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::stringstream outStream;
  outStream
      << "Incorrect dimensions for matrix multiplication. Check that the "
         "number of columns in the first matrix matches the number of rows "
         "in the second matrix. To operate on each element of the matrix "
         "individually, use TIMES (.*) for elementwise multiplication.";
  outStream << "\n";
  ((((outStream << "Error in ") << aFcnName) << " (line ") << aLineNum) << ")";
  throw std::runtime_error(outStream.str());
}

//
// Arguments    : const char *aFcnName
//                int aLineNum
// Return Type  : void
//
static void o_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::stringstream outStream;
  outStream
      << "Inner dimensions must agree. Generated code for a general matrix "
         "multiplication at this call site. If this should have been a sc"
         "alar times a variable-size matrix, the scalar input must be "
         "fixed-size.";
  outStream << "\n";
  ((((outStream << "Error in ") << aFcnName) << " (line ") << aLineNum) << ")";
  throw std::runtime_error(outStream.str());
}

//
// Arguments    : double u0
//                double u1
// Return Type  : double
//
static double rt_atan2d_snf(double u0, double u1)
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
// Arguments    : double u0
//                double u1
// Return Type  : double
//
static double rt_powd_snf(double u0, double u1)
{
  double y;
  if (std::isnan(u0) || std::isnan(u1)) {
    y = rtNaN;
  } else {
    double d;
    double d1;
    d = std::abs(u0);
    d1 = std::abs(u1);
    if (std::isinf(u1)) {
      if (d == 1.0) {
        y = 1.0;
      } else if (d > 1.0) {
        if (u1 > 0.0) {
          y = rtInf;
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = rtInf;
      }
    } else if (d1 == 0.0) {
      y = 1.0;
    } else if (d1 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = std::sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > std::floor(u1))) {
      y = rtNaN;
    } else {
      y = std::pow(u0, u1);
    }
  }
  return y;
}

//
// Arguments    : coder::array<double, 1U> &in1
//                const coder::array<double, 1U> &in2
// Return Type  : void
//
static void times(coder::array<double, 1U> &in1,
                  const coder::array<double, 1U> &in2)
{
  coder::array<double, 1U> b_in1;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  if (in2.size(0) == 1) {
    loop_ub = in1.size(0);
  } else {
    loop_ub = in2.size(0);
  }
  b_in1.set_size(loop_ub);
  stride_0_0 = (in1.size(0) != 1);
  stride_1_0 = (in2.size(0) != 1);
  for (int i{0}; i < loop_ub; i++) {
    b_in1[i] = in1[i * stride_0_0] * in2[i * stride_1_0];
  }
  in1.set_size(b_in1.size(0));
  loop_ub = b_in1.size(0);
  for (int i{0}; i < loop_ub; i++) {
    in1[i] = b_in1[i];
  }
}

//
// DOAPCA developes a bearing estimate for a series of received radio pulses
// based on the principle component analysis method.
//    This function conducts a principle component analysis type bearing
//    estimate on signal pulses in the pulseList vector. Each pulse signal
//    corresponds to a given heading (pulse_yaw). The program uses the SNR in
//    dB for the pulses in the list and does the PCA on those pulses using a
//    the original log scaling or a linear scaling depending on the 'scale'
//    input
//
//
// INPUTS
//    pulseList           a (px1) vector of ReceivedPulse objects
//
//    scale               a char array of 'log' or 'linear' to indicate if
//                        the scaling used in the PCA method should be log or
//                        linear
//
// OUTPUTS
//    DOA                 a (1x1) double containing the bearing estimate
//                        from the PCA method from 0-359 degrees with 0 being
//                        the same as the yaw origin (typically N).
//    tau                 a (1x1) double containing the tau value for
//                        each bearing estimate.
//
// --------------------------------------------------------------------------
//  Author: Michael Shafer
//  Date: 2023-06-12
// --------------------------------------------------------------------------
// --------------------------------------------------------------------------
//
// Arguments    : const coder::array<e_struct_T, 1U> &pulseList
//                double &tau
// Return Type  : double
//
double doapca(const coder::array<e_struct_T, 1U> &pulseList, double &tau)
{
  static rtBoundsCheckInfo b_emlrtBCI{
      -1,                     // iFirst
      -1,                     // iLast
      43,                     // lineNo
      22,                     // colNo
      "curr_pulses_noisePSD", // aName
      "doapca",               // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/uavrt_localization_utils/do"
      "apca.m", // pName
      0         // checkKind
  };
  static rtBoundsCheckInfo c_emlrtBCI{
      -1,                  // iFirst
      -1,                  // iLast
      44,                  // lineNo
      19,                  // colNo
      "curr_pulses_snrdB", // aName
      "doapca",            // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/uavrt_localization_utils/do"
      "apca.m", // pName
      0         // checkKind
  };
  static rtBoundsCheckInfo d_emlrtBCI{
      -1,          // iFirst
      -1,          // iLast
      17,          // lineNo
      5,           // colNo
      "",          // aName
      "wrapTo360", // fName
      "/Applications/MATLAB_R2023a.app/toolbox/shared/maputils/wrapTo360.m", // pName
      0 // checkKind
  };
  static rtBoundsCheckInfo e_emlrtBCI{
      -1,       // iFirst
      -1,       // iLast
      87,       // lineNo
      24,       // colNo
      "angs",   // aName
      "doapca", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/uavrt_localization_utils/do"
      "apca.m", // pName
      0         // checkKind
  };
  static rtBoundsCheckInfo f_emlrtBCI{
      -1,       // iFirst
      -1,       // iLast
      101,      // lineNo
      17,       // colNo
      "SdB",    // aName
      "doapca", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/uavrt_localization_utils/do"
      "apca.m", // pName
      0         // checkKind
  };
  static rtBoundsCheckInfo g_emlrtBCI{
      -1,       // iFirst
      -1,       // iLast
      101,      // lineNo
      28,       // colNo
      "SdB",    // aName
      "doapca", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/uavrt_localization_utils/do"
      "apca.m", // pName
      0         // checkKind
  };
  static rtEqualityCheckInfo b_emlrtECI{
      1,           // nDims
      17,          // lineNo
      5,           // colNo
      "wrapTo360", // fName
      "/Applications/MATLAB_R2023a.app/toolbox/shared/maputils/wrapTo360.m" // pName
  };
  static rtEqualityCheckInfo c_emlrtECI{
      1,        // nDims
      92,       // lineNo
      19,       // colNo
      "doapca", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/uavrt_localization_utils/do"
      "apca.m" // pName
  };
  static rtEqualityCheckInfo d_emlrtECI{
      1,        // nDims
      92,       // lineNo
      40,       // colNo
      "doapca", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/uavrt_localization_utils/do"
      "apca.m" // pName
  };
  static rtEqualityCheckInfo e_emlrtECI{
      1,        // nDims
      94,       // lineNo
      14,       // colNo
      "doapca", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/uavrt_localization_utils/do"
      "apca.m" // pName
  };
  static rtEqualityCheckInfo emlrtECI{
      1,        // nDims
      46,       // lineNo
      22,       // colNo
      "doapca", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/uavrt_localization_utils/do"
      "apca.m" // pName
  };
  static rtEqualityCheckInfo f_emlrtECI{
      2,        // nDims
      94,       // lineNo
      14,       // colNo
      "doapca", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/uavrt_localization_utils/do"
      "apca.m" // pName
  };
  static rtRunTimeErrorInfo ab_emlrtRTEI{
      138,                  // lineNo
      "dynamic_size_checks" // fName
  };
  static rtRunTimeErrorInfo v_emlrtRTEI{
      74,                 // lineNo
      "reshapeSizeChecks" // fName
  };
  static rtRunTimeErrorInfo w_emlrtRTEI{
      81,                 // lineNo
      "reshapeSizeChecks" // fName
  };
  static rtRunTimeErrorInfo x_emlrtRTEI{
      288,                  // lineNo
      "check_non_axis_size" // fName
  };
  static rtRunTimeErrorInfo y_emlrtRTEI{
      133,                  // lineNo
      "dynamic_size_checks" // fName
  };
  coder::array<d_struct_T, 2U> r2;
  coder::array<d_struct_T, 1U> r3;
  coder::array<double, 2U> Pe_dB;
  coder::array<double, 2U> Pe_star_dB;
  coder::array<double, 2U> a;
  coder::array<double, 2U> b_y;
  coder::array<double, 2U> r;
  coder::array<double, 2U> r1;
  coder::array<double, 2U> r4;
  coder::array<double, 1U> P_all_ang_unscaled;
  coder::array<double, 1U> angs;
  coder::array<double, 1U> curr_pulses_noisePSD;
  coder::array<double, 1U> curr_pulses_snrLin;
  coder::array<double, 1U> curr_pulses_snrdB;
  coder::array<boolean_T, 1U> positiveInput;
  coder::array<boolean_T, 1U> r5;
  coder::array<boolean_T, 1U> r6;
  double VdB[4];
  double DOA;
  double totalSweptAngle;
  int end_tmp;
  int maxdimlen;
  int n;
  boolean_T b;
  boolean_T guard1{false};
  boolean_T y;
  n = pulseList.size(0);
  if (pulseList.size(0) == 0) {
    end_tmp = 0;
  } else {
    end_tmp = pulseList.size(0);
  }
  r.set_size(1, end_tmp);
  if (pulseList.size(0) > 2147483646) {
    coder::check_forloop_overflow_error();
  }
  for (maxdimlen = 0; maxdimlen < n; maxdimlen++) {
    r[maxdimlen] = pulseList[maxdimlen].snrdB;
  }
  maxdimlen = 1;
  if (r.size(1) > 1) {
    maxdimlen = r.size(1);
  }
  n = r.size(1);
  if (n >= maxdimlen) {
    maxdimlen = n;
  }
  if (pulseList.size(0) > maxdimlen) {
    l_rtErrorWithMessageID(v_emlrtRTEI.fName, v_emlrtRTEI.lineNo);
  }
  if (pulseList.size(0) != r.size(1)) {
    k_rtErrorWithMessageID(w_emlrtRTEI.fName, w_emlrtRTEI.lineNo);
  }
  curr_pulses_snrdB.set_size(pulseList.size(0));
  maxdimlen = pulseList.size(0);
  curr_pulses_snrLin.set_size(pulseList.size(0));
  for (int k{0}; k < maxdimlen; k++) {
    totalSweptAngle = r[k];
    curr_pulses_snrdB[k] = totalSweptAngle;
    curr_pulses_snrLin[k] = rt_powd_snf(10.0, totalSweptAngle / 10.0);
  }
  coder::internal::horzcatStructList(pulseList, r1);
  maxdimlen = 1;
  if (r1.size(1) > 1) {
    maxdimlen = r1.size(1);
  }
  n = r1.size(1);
  if (n >= maxdimlen) {
    maxdimlen = n;
  }
  if (pulseList.size(0) > maxdimlen) {
    l_rtErrorWithMessageID(v_emlrtRTEI.fName, v_emlrtRTEI.lineNo);
  }
  if (pulseList.size(0) != r1.size(1)) {
    k_rtErrorWithMessageID(w_emlrtRTEI.fName, w_emlrtRTEI.lineNo);
  }
  curr_pulses_noisePSD.set_size(pulseList.size(0));
  maxdimlen = pulseList.size(0);
  for (int k{0}; k < maxdimlen; k++) {
    curr_pulses_noisePSD[k] = r1[k];
  }
  coder::internal::horzcatStructList(pulseList, r2);
  n = r2.size(0) * r2.size(1);
  maxdimlen = r2.size(0);
  if (r2.size(1) > r2.size(0)) {
    maxdimlen = r2.size(1);
  }
  if (n >= maxdimlen) {
    maxdimlen = n;
  }
  if (pulseList.size(0) > maxdimlen) {
    l_rtErrorWithMessageID(v_emlrtRTEI.fName, v_emlrtRTEI.lineNo);
  }
  if (maxdimlen < 1) {
    l_rtErrorWithMessageID(v_emlrtRTEI.fName, v_emlrtRTEI.lineNo);
  }
  if (pulseList.size(0) != n) {
    k_rtErrorWithMessageID(w_emlrtRTEI.fName, w_emlrtRTEI.lineNo);
  }
  maxdimlen = pulseList.size(0);
  r3 = r2.reshape(maxdimlen);
  n = r3.size(0);
  if (r3.size(0) == 0) {
    end_tmp = 0;
  } else {
    end_tmp = r3.size(0);
  }
  r4.set_size(1, end_tmp);
  if (r3.size(0) > 2147483646) {
    coder::check_forloop_overflow_error();
  }
  for (maxdimlen = 0; maxdimlen < n; maxdimlen++) {
    r4[maxdimlen] = r3[maxdimlen].yaw_deg;
  }
  maxdimlen = 1;
  if (r4.size(1) > 1) {
    maxdimlen = r4.size(1);
  }
  n = r4.size(1);
  if (n >= maxdimlen) {
    maxdimlen = n;
  }
  if (pulseList.size(0) > maxdimlen) {
    l_rtErrorWithMessageID(v_emlrtRTEI.fName, v_emlrtRTEI.lineNo);
  }
  if (pulseList.size(0) != r4.size(1)) {
    k_rtErrorWithMessageID(w_emlrtRTEI.fName, w_emlrtRTEI.lineNo);
  }
  // Clear out placeholds for bad data points;
  end_tmp = pulseList.size(0) - 1;
  for (maxdimlen = 0; maxdimlen <= end_tmp; maxdimlen++) {
    if (r1[maxdimlen] == -9999.0) {
      if (maxdimlen > end_tmp) {
        rtDynamicBoundsError(maxdimlen, 0, end_tmp, b_emlrtBCI);
      }
      curr_pulses_noisePSD[maxdimlen] = rtNaN;
    }
  }
  for (maxdimlen = 0; maxdimlen <= end_tmp; maxdimlen++) {
    if (r[maxdimlen] == -9999.0) {
      if (maxdimlen > end_tmp) {
        rtDynamicBoundsError(maxdimlen, 0, end_tmp, c_emlrtBCI);
      }
      curr_pulses_snrdB[maxdimlen] = rtNaN;
    }
  }
  maxdimlen = curr_pulses_snrdB.size(0);
  for (int k{0}; k < maxdimlen; k++) {
    totalSweptAngle = curr_pulses_snrdB[k] / 10.0;
    curr_pulses_snrdB[k] = rt_powd_snf(10.0, totalSweptAngle);
  }
  b = ((curr_pulses_noisePSD.size(0) != curr_pulses_snrdB.size(0)) &&
       ((curr_pulses_noisePSD.size(0) != 1) &&
        (curr_pulses_snrdB.size(0) != 1)));
  if (b) {
    emlrtDimSizeImpxCheckR2021b(curr_pulses_noisePSD.size(0),
                                curr_pulses_snrdB.size(0), emlrtECI);
  }
  if (curr_pulses_noisePSD.size(0) == curr_pulses_snrdB.size(0)) {
    maxdimlen = curr_pulses_noisePSD.size(0);
    for (int k{0}; k < maxdimlen; k++) {
      curr_pulses_noisePSD[k] = curr_pulses_noisePSD[k] * curr_pulses_snrdB[k];
    }
  } else {
    times(curr_pulses_noisePSD, curr_pulses_snrdB);
  }
  // Define for Coder so DOA is defined for all execution paths
  DOA = rtNaN;
  tau = rtNaN;
  positiveInput.set_size(curr_pulses_snrLin.size(0));
  maxdimlen = curr_pulses_snrLin.size(0);
  for (int k{0}; k < maxdimlen; k++) {
    positiveInput[k] = (curr_pulses_snrLin[k] < 0.0);
  }
  y = coder::any(positiveInput);
  guard1 = false;
  if (y) {
    guard1 = true;
  } else {
    n = curr_pulses_snrLin.size(0);
    curr_pulses_snrdB.set_size(curr_pulses_snrLin.size(0));
    for (int k{0}; k < n; k++) {
      curr_pulses_snrdB[k] = std::abs(curr_pulses_snrLin[k]);
    }
    positiveInput.set_size(curr_pulses_snrdB.size(0));
    maxdimlen = curr_pulses_snrdB.size(0);
    for (int k{0}; k < maxdimlen; k++) {
      positiveInput[k] = (curr_pulses_snrdB[k] == rtInf);
    }
    y = coder::any(positiveInput);
    if (y) {
      guard1 = true;
    } else {
      double Pavg_idx_1;
      // P_all_ang_unscaled = (curr_pulses_snrLin./min(curr_pulses_snrLin));
      totalSweptAngle = coder::internal::minimum(curr_pulses_noisePSD);
      P_all_ang_unscaled.set_size(curr_pulses_noisePSD.size(0));
      maxdimlen = curr_pulses_noisePSD.size(0);
      for (int k{0}; k < maxdimlen; k++) {
        P_all_ang_unscaled[k] = curr_pulses_noisePSD[k] / totalSweptAngle;
      }
      angs.set_size(pulseList.size(0));
      maxdimlen = pulseList.size(0);
      positiveInput.set_size(pulseList.size(0));
      curr_pulses_snrdB.set_size(pulseList.size(0));
      for (int k{0}; k < maxdimlen; k++) {
        totalSweptAngle = r4[k];
        angs[k] = totalSweptAngle * 3.1415926535897931 / 180.0;
        positiveInput[k] = (totalSweptAngle > 0.0);
        if (std::isnan(totalSweptAngle) || std::isinf(totalSweptAngle)) {
          Pavg_idx_1 = rtNaN;
        } else if (totalSweptAngle == 0.0) {
          Pavg_idx_1 = 0.0;
        } else {
          Pavg_idx_1 = std::fmod(totalSweptAngle, 360.0);
          if (Pavg_idx_1 == 0.0) {
            Pavg_idx_1 = 0.0;
          } else if (totalSweptAngle < 0.0) {
            Pavg_idx_1 += 360.0;
          }
        }
        curr_pulses_snrdB[k] = Pavg_idx_1;
      }
      r5.set_size(curr_pulses_snrdB.size(0));
      maxdimlen = curr_pulses_snrdB.size(0);
      for (int k{0}; k < maxdimlen; k++) {
        r5[k] = (curr_pulses_snrdB[k] == 0.0);
      }
      if (b) {
        emlrtDimSizeImpxCheckR2021b(r5.size(0), positiveInput.size(0),
                                    b_emlrtECI);
      }
      if (r5.size(0) == positiveInput.size(0)) {
        r6.set_size(r5.size(0));
        maxdimlen = r5.size(0);
        for (int k{0}; k < maxdimlen; k++) {
          r6[k] = (r5[k] && positiveInput[k]);
        }
      } else {
        b_and(r6, r5, positiveInput);
      }
      n = r6.size(0) - 1;
      for (maxdimlen = 0; maxdimlen <= n; maxdimlen++) {
        if (r6[maxdimlen]) {
          if (maxdimlen > end_tmp) {
            rtDynamicBoundsError(maxdimlen, 0, end_tmp, d_emlrtBCI);
          }
          curr_pulses_snrdB[maxdimlen] = 360.0;
        }
      }
      coder::internal::sort(curr_pulses_snrdB);
      coder::diff(curr_pulses_snrdB, curr_pulses_snrLin);
      totalSweptAngle = coder::sum(curr_pulses_snrLin);
      if ((curr_pulses_noisePSD.size(0) < 4) || (totalSweptAngle < 270.0)) {
        std::printf("Only %f pulse(s) detected over swept angle %f degrees. "
                    "Insufficient to perform PCA Method which requires at "
                    "least 270 degrees of"
                    " sweep and 4 pulses received. Returning DOA based on "
                    "maximum signal strength.",
                    static_cast<double>(curr_pulses_noisePSD.size(0)),
                    totalSweptAngle);
        std::fflush(stdout);
        // wp(2) = NaN; wp(1) = NaN;tau = NaN; line_scale = 0;
        coder::internal::maximum(P_all_ang_unscaled, maxdimlen);
        if ((maxdimlen < 1) || (maxdimlen > angs.size(0))) {
          rtDynamicBoundsError(maxdimlen, 1, angs.size(0), e_emlrtBCI);
        }
        totalSweptAngle = angs[maxdimlen - 1];
      } else {
        double absxk;
        double b_scale;
        double c_y;
        double d_y;
        double scale;
        double t;
        curr_pulses_snrdB.set_size(angs.size(0));
        maxdimlen = angs.size(0);
        for (int k{0}; k < maxdimlen; k++) {
          curr_pulses_snrdB[k] = angs[k];
        }
        n = angs.size(0);
        for (int k{0}; k < n; k++) {
          curr_pulses_snrdB[k] = std::cos(curr_pulses_snrdB[k]);
        }
        b = ((P_all_ang_unscaled.size(0) != curr_pulses_snrdB.size(0)) &&
             ((P_all_ang_unscaled.size(0) != 1) &&
              (curr_pulses_snrdB.size(0) != 1)));
        if (b) {
          emlrtDimSizeImpxCheckR2021b(P_all_ang_unscaled.size(0),
                                      curr_pulses_snrdB.size(0), c_emlrtECI);
        }
        n = angs.size(0);
        for (int k{0}; k < n; k++) {
          angs[k] = std::sin(angs[k]);
        }
        if (b) {
          emlrtDimSizeImpxCheckR2021b(P_all_ang_unscaled.size(0), angs.size(0),
                                      d_emlrtECI);
        }
        if (P_all_ang_unscaled.size(0) == curr_pulses_snrdB.size(0)) {
          curr_pulses_snrdB.set_size(P_all_ang_unscaled.size(0));
          maxdimlen = P_all_ang_unscaled.size(0);
          for (int k{0}; k < maxdimlen; k++) {
            curr_pulses_snrdB[k] = P_all_ang_unscaled[k] * curr_pulses_snrdB[k];
          }
        } else {
          b_times(curr_pulses_snrdB, P_all_ang_unscaled);
        }
        if (P_all_ang_unscaled.size(0) == angs.size(0)) {
          maxdimlen = P_all_ang_unscaled.size(0);
          for (int k{0}; k < maxdimlen; k++) {
            P_all_ang_unscaled[k] = P_all_ang_unscaled[k] * angs[k];
          }
        } else {
          times(P_all_ang_unscaled, angs);
        }
        if (P_all_ang_unscaled.size(0) != curr_pulses_snrdB.size(0)) {
          m_rtErrorWithMessageID(x_emlrtRTEI.fName, x_emlrtRTEI.lineNo);
        }
        Pe_star_dB.set_size(curr_pulses_snrdB.size(0), 2);
        maxdimlen = curr_pulses_snrdB.size(0);
        for (int k{0}; k < maxdimlen; k++) {
          Pe_star_dB[k] = curr_pulses_snrdB[k];
        }
        maxdimlen = P_all_ang_unscaled.size(0);
        for (int k{0}; k < maxdimlen; k++) {
          Pe_star_dB[k + Pe_star_dB.size(0)] = P_all_ang_unscaled[k];
        }
        n = Pe_star_dB.size(0);
        if (n < 2) {
          n = 2;
        }
        if (Pe_star_dB.size(0) == 0) {
          n = 0;
        }
        coder::eye(static_cast<double>(n), a);
        totalSweptAngle = 1.0 / static_cast<double>(n);
        if ((a.size(0) != n) && ((a.size(0) != 1) && (n != 1))) {
          emlrtDimSizeImpxCheckR2021b(a.size(0), n, e_emlrtECI);
        }
        if ((a.size(1) != n) && ((a.size(1) != 1) && (n != 1))) {
          emlrtDimSizeImpxCheckR2021b(a.size(1), n, f_emlrtECI);
        }
        if ((a.size(0) == n) && (a.size(1) == n)) {
          maxdimlen = a.size(0) * a.size(1);
          for (int k{0}; k < maxdimlen; k++) {
            a[k] = a[k] - totalSweptAngle;
          }
        } else {
          binary_expand_op(a, totalSweptAngle, n);
        }
        if (Pe_star_dB.size(0) != a.size(1)) {
          if ((a.size(0) == 1) && (a.size(1) == 1)) {
            o_rtErrorWithMessageID(y_emlrtRTEI.fName, y_emlrtRTEI.lineNo);
          } else {
            n_rtErrorWithMessageID(ab_emlrtRTEI.fName, ab_emlrtRTEI.lineNo);
          }
        }
        coder::internal::blas::mtimes(a, Pe_star_dB, Pe_dB);
        b_y.set_size(2, Pe_star_dB.size(0));
        maxdimlen = Pe_star_dB.size(0);
        for (int k{0}; k < maxdimlen; k++) {
          b_y[2 * k] = totalSweptAngle * Pe_star_dB[k];
          b_y[2 * k + 1] = totalSweptAngle * Pe_star_dB[k + Pe_star_dB.size(0)];
        }
        if (b_y.size(1) != n) {
          if (n == 1) {
            o_rtErrorWithMessageID(y_emlrtRTEI.fName, y_emlrtRTEI.lineNo);
          } else {
            n_rtErrorWithMessageID(ab_emlrtRTEI.fName, ab_emlrtRTEI.lineNo);
          }
        }
        n = b_y.size(1);
        totalSweptAngle = 0.0;
        Pavg_idx_1 = 0.0;
        if (b_y.size(1) > 2147483646) {
          coder::check_forloop_overflow_error();
        }
        for (int k{0}; k < n; k++) {
          maxdimlen = k << 1;
          totalSweptAngle += b_y[maxdimlen];
          Pavg_idx_1 += b_y[maxdimlen + 1];
        }
        coder::svd(Pe_dB, a, Pe_star_dB, VdB);
        // w2 = VdB(:,2);
        scale = 3.3121686421112381E-170;
        b_scale = 3.3121686421112381E-170;
        absxk = std::abs(totalSweptAngle);
        if (absxk > 3.3121686421112381E-170) {
          c_y = 1.0;
          scale = absxk;
        } else {
          t = absxk / 3.3121686421112381E-170;
          c_y = t * t;
        }
        absxk = std::abs(VdB[0]);
        if (absxk > 3.3121686421112381E-170) {
          d_y = 1.0;
          b_scale = absxk;
        } else {
          t = absxk / 3.3121686421112381E-170;
          d_y = t * t;
        }
        absxk = std::abs(Pavg_idx_1);
        if (absxk > scale) {
          t = scale / absxk;
          c_y = c_y * t * t + 1.0;
          scale = absxk;
        } else {
          t = absxk / scale;
          c_y += t * t;
        }
        absxk = std::abs(VdB[1]);
        if (absxk > b_scale) {
          t = b_scale / absxk;
          d_y = d_y * t * t + 1.0;
          b_scale = absxk;
        } else {
          t = absxk / b_scale;
          d_y += t * t;
        }
        c_y = scale * std::sqrt(c_y);
        d_y = b_scale * std::sqrt(d_y);
        scale = (totalSweptAngle * VdB[0] + Pavg_idx_1 * VdB[1]) / (c_y * d_y);
        // beta = norm(Pavg)^2/SdB(1,1)^2;
        if (Pe_star_dB.size(0) < 2) {
          rtDynamicBoundsError(2, 1, Pe_star_dB.size(0), f_emlrtBCI);
        }
        if (Pe_star_dB.size(0) < 1) {
          rtDynamicBoundsError(1, 1, Pe_star_dB.size(0), g_emlrtBCI);
        }
        totalSweptAngle = Pe_star_dB[Pe_star_dB.size(0) + 1];
        Pavg_idx_1 = Pe_star_dB[0];
        tau =
            1.0 - totalSweptAngle * totalSweptAngle / (Pavg_idx_1 * Pavg_idx_1);
        // line_scale = max(P_all_ang)/norm(wp);%the wp size changes if w1
        totalSweptAngle = rt_atan2d_snf(scale * VdB[1], scale * VdB[0]);
      }
      DOA = 57.295779513082323 * totalSweptAngle;
      //  %% Now fit the kappa value for the vonMises Distribution
      //  kappaVec = 0:0.001:20;
      //  mu = DOA_calc;
      //  %curr_yaws;
      //  %curr_pulses
      //  %Fit to vonMises by making pulse stength like counts for histogram/PDF
      //  scalingExponent = 4 - round(log10(max(P_all_ang)));
      //  if strcmp(scale,'linear')
      //      counts = P_all_ang * 1*10^(scalingExponent);
      //  elseif strcmp(scale,'log')
      //      counts = (P_all_ang + -min(P_all_ang))/-min(P_all_ang) *
      //      1*10^(scalingExponent);
      //  end
      //
      //  counts = round(counts);
      //  fakeData = zeros(sum(counts),1);
      //  currInd = 1;
      //  tic
      //  for i = 1:numPulses
      //      endInd = currInd + counts(i);
      //      fakeData(currInd : endInd) = curr_yaws(i);
      //      currInd = endInd+1;
      //  end
      //
      //  [probs, binEdges] =
      //  histcounts(fakeData,16,'Normalization','probability'); binwidths =
      //  diff(binEdges); binCenters = binEdges(1:(end-1)) + binwidths(1:end)/2;
      //
      //  sumErrorSquare = zeros(numel(kappaVec),1);
      //  %Sweep kappa values to find that with the least error^2.
      //  for i = 1:numel(kappaVec)
      //      kappa = kappaVec(i);
      //      vonMisesDist =
      //      exp(kappa*cos(binCenters-mu))/(2*pi*besseli(0,kappa));
      //      sumErrorSquare(i) = sum((vonMisesDist - probs).^2);
      //  end
      //
      //  [~, indMinError] = min(sumErrorSquare);
      //
      //  kappaBest = kappaVec(indMinError);
      //
      //  kappa = kappaBest;
    }
  }
  if (guard1) {
    std::printf(
        "UAV-RT: Strength of all input pulses must be finite and positive.");
    std::fflush(stdout);
  }
  return DOA;
}

//
// File trailer for doapca.cpp
//
// [EOF]
//
