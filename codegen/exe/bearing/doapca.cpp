//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: doapca.cpp
//
// MATLAB Coder version            : 5.6
// C/C++ source code generated on  : 15-Aug-2023 14:31:29
//

// Include Files
#include "doapca.h"
#include "any1.h"
#include "bearing_data.h"
#include "bearing_internal_types.h"
#include "bearing_rtwutil.h"
#include "bearing_types.h"
#include "diff.h"
#include "eml_int_forloop_overflow_check.h"
#include "eye.h"
#include "horzcatStructList.h"
#include "minOrMax.h"
#include "mtimes.h"
#include "quat2eul.h"
#include "rt_nonfinite.h"
#include "sort.h"
#include "sum.h"
#include "svd.h"
#include "wrapTo360.h"
#include "coder_array.h"
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

static void n_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

static void o_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

static void p_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

static void q_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

static double rt_powd_snf(double u0, double u1);

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
// Arguments    : const char *aFcnName
//                int aLineNum
// Return Type  : void
//
static void n_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
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
static void o_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
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
static void p_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
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
static void q_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
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
      -1,          // iFirst
      -1,          // iLast
      17,          // lineNo
      5,           // colNo
      "",          // aName
      "wrapTo360", // fName
      "/Applications/MATLAB_R2023a.app/toolbox/shared/maputils/wrapTo360.m", // pName
      0 // checkKind
  };
  static rtBoundsCheckInfo c_emlrtBCI{
      -1,       // iFirst
      -1,       // iLast
      77,       // lineNo
      24,       // colNo
      "angs",   // aName
      "doapca", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/uavrt_localization_utils/do"
      "apca.m", // pName
      0         // checkKind
  };
  static rtBoundsCheckInfo d_emlrtBCI{
      -1,       // iFirst
      -1,       // iLast
      91,       // lineNo
      17,       // colNo
      "SdB",    // aName
      "doapca", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/uavrt_localization_utils/do"
      "apca.m", // pName
      0         // checkKind
  };
  static rtBoundsCheckInfo e_emlrtBCI{
      -1,       // iFirst
      -1,       // iLast
      91,       // lineNo
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
      82,       // lineNo
      19,       // colNo
      "doapca", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/uavrt_localization_utils/do"
      "apca.m" // pName
  };
  static rtEqualityCheckInfo d_emlrtECI{
      1,        // nDims
      82,       // lineNo
      40,       // colNo
      "doapca", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/uavrt_localization_utils/do"
      "apca.m" // pName
  };
  static rtEqualityCheckInfo e_emlrtECI{
      2,        // nDims
      84,       // lineNo
      14,       // colNo
      "doapca", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/uavrt_localization_utils/do"
      "apca.m" // pName
  };
  static rtEqualityCheckInfo emlrtECI{
      1,        // nDims
      84,       // lineNo
      14,       // colNo
      "doapca", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/uavrt_localization_utils/do"
      "apca.m" // pName
  };
  static rtRunTimeErrorInfo ab_emlrtRTEI{
      133,                  // lineNo
      "dynamic_size_checks" // fName
  };
  static rtRunTimeErrorInfo bb_emlrtRTEI{
      138,                  // lineNo
      "dynamic_size_checks" // fName
  };
  static rtRunTimeErrorInfo x_emlrtRTEI{
      74,                 // lineNo
      "reshapeSizeChecks" // fName
  };
  static rtRunTimeErrorInfo y_emlrtRTEI{
      81,                 // lineNo
      "reshapeSizeChecks" // fName
  };
  coder::array<d_struct_T, 2U> r1;
  coder::array<double, 2U> Pe_dB;
  coder::array<double, 2U> Pe_star_dB;
  coder::array<double, 2U> a;
  coder::array<double, 2U> b_y;
  coder::array<double, 2U> r;
  coder::array<double, 2U> r2;
  coder::array<double, 1U> angs;
  coder::array<double, 1U> curr_pulses_snrLin;
  coder::array<double, 1U> curr_yaws;
  coder::array<double, 1U> diffAngsDeg;
  coder::array<boolean_T, 1U> positiveInput;
  coder::array<boolean_T, 1U> r3;
  coder::array<boolean_T, 1U> r4;
  double VdB[4];
  double DOA;
  double totalSweptAngle;
  int i;
  int maxdimlen;
  int n;
  boolean_T guard1{false};
  boolean_T y;
  n = pulseList.size(0);
  if (pulseList.size(0) == 0) {
    i = 0;
  } else {
    i = pulseList.size(0);
  }
  r.set_size(1, i);
  if (pulseList.size(0) > 2147483646) {
    coder::check_forloop_overflow_error();
  }
  for (int b_i{0}; b_i < n; b_i++) {
    r[b_i] = pulseList[b_i].snrdB;
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
    o_rtErrorWithMessageID(x_emlrtRTEI.fName, x_emlrtRTEI.lineNo);
  }
  if (pulseList.size(0) != r.size(1)) {
    n_rtErrorWithMessageID(y_emlrtRTEI.fName, y_emlrtRTEI.lineNo);
  }
  curr_pulses_snrLin.set_size(pulseList.size(0));
  maxdimlen = pulseList.size(0);
  for (n = 0; n < maxdimlen; n++) {
    totalSweptAngle = r[n] / 10.0;
    curr_pulses_snrLin[n] = rt_powd_snf(10.0, totalSweptAngle);
  }
  coder::internal::horzcatStructList(pulseList, r1);
  n = r1.size(0) * r1.size(1);
  maxdimlen = r1.size(0);
  if (r1.size(1) > r1.size(0)) {
    maxdimlen = r1.size(1);
  }
  if (n >= maxdimlen) {
    maxdimlen = n;
  }
  if (pulseList.size(0) > maxdimlen) {
    o_rtErrorWithMessageID(x_emlrtRTEI.fName, x_emlrtRTEI.lineNo);
  }
  if (maxdimlen < 1) {
    o_rtErrorWithMessageID(x_emlrtRTEI.fName, x_emlrtRTEI.lineNo);
  }
  if (pulseList.size(0) != n) {
    n_rtErrorWithMessageID(y_emlrtRTEI.fName, y_emlrtRTEI.lineNo);
  }
  n = pulseList.size(0);
  r2.set_size(1, i);
  for (int b_i{0}; b_i < n; b_i++) {
    r2[b_i] = r1[b_i].yaw_deg;
  }
  maxdimlen = 1;
  if (r2.size(1) > 1) {
    maxdimlen = r2.size(1);
  }
  n = r2.size(1);
  if (n >= maxdimlen) {
    maxdimlen = n;
  }
  if (pulseList.size(0) > maxdimlen) {
    o_rtErrorWithMessageID(x_emlrtRTEI.fName, x_emlrtRTEI.lineNo);
  }
  if (pulseList.size(0) != r2.size(1)) {
    n_rtErrorWithMessageID(y_emlrtRTEI.fName, y_emlrtRTEI.lineNo);
  }
  // Define for Coder so DOA is defined for all execution paths
  DOA = rtNaN;
  tau = rtNaN;
  positiveInput.set_size(curr_pulses_snrLin.size(0));
  maxdimlen = curr_pulses_snrLin.size(0);
  for (i = 0; i < maxdimlen; i++) {
    positiveInput[i] = (curr_pulses_snrLin[i] < 0.0);
  }
  y = coder::any(positiveInput);
  guard1 = false;
  if (y) {
    guard1 = true;
  } else {
    n = curr_pulses_snrLin.size(0);
    curr_yaws.set_size(curr_pulses_snrLin.size(0));
    for (int b_i{0}; b_i < n; b_i++) {
      curr_yaws[b_i] = std::abs(curr_pulses_snrLin[b_i]);
    }
    positiveInput.set_size(curr_yaws.size(0));
    maxdimlen = curr_yaws.size(0);
    for (i = 0; i < maxdimlen; i++) {
      positiveInput[i] = (curr_yaws[i] == rtInf);
    }
    y = coder::any(positiveInput);
    if (y) {
      guard1 = true;
    } else {
      double Pavg_idx_1;
      double scale;
      totalSweptAngle = coder::internal::minimum(curr_pulses_snrLin);
      maxdimlen = curr_pulses_snrLin.size(0);
      angs.set_size(pulseList.size(0));
      positiveInput.set_size(pulseList.size(0));
      curr_yaws.set_size(pulseList.size(0));
      for (i = 0; i < maxdimlen; i++) {
        curr_pulses_snrLin[i] = curr_pulses_snrLin[i] / totalSweptAngle;
        Pavg_idx_1 = r2[i];
        angs[i] = Pavg_idx_1 * 3.1415926535897931 / 180.0;
        positiveInput[i] = (Pavg_idx_1 > 0.0);
        if (std::isnan(Pavg_idx_1) || std::isinf(Pavg_idx_1)) {
          scale = rtNaN;
        } else if (Pavg_idx_1 == 0.0) {
          scale = 0.0;
        } else {
          scale = std::fmod(Pavg_idx_1, 360.0);
          if (scale == 0.0) {
            scale = 0.0;
          } else if (Pavg_idx_1 < 0.0) {
            scale += 360.0;
          }
        }
        curr_yaws[i] = scale;
      }
      r3.set_size(curr_yaws.size(0));
      maxdimlen = curr_yaws.size(0);
      for (i = 0; i < maxdimlen; i++) {
        r3[i] = (curr_yaws[i] == 0.0);
      }
      y = ((r3.size(0) != positiveInput.size(0)) &&
           ((r3.size(0) != 1) && (positiveInput.size(0) != 1)));
      if (y) {
        emlrtDimSizeImpxCheckR2021b(r3.size(0), positiveInput.size(0),
                                    b_emlrtECI);
      }
      if (r3.size(0) == positiveInput.size(0)) {
        r4.set_size(r3.size(0));
        maxdimlen = r3.size(0);
        for (i = 0; i < maxdimlen; i++) {
          r4[i] = (r3[i] && positiveInput[i]);
        }
      } else {
        b_and(r4, r3, positiveInput);
      }
      maxdimlen = r4.size(0) - 1;
      for (int b_i{0}; b_i <= maxdimlen; b_i++) {
        if (r4[b_i]) {
          if (b_i > curr_yaws.size(0) - 1) {
            rtDynamicBoundsError(b_i, 0, curr_yaws.size(0) - 1, b_emlrtBCI);
          }
          curr_yaws[b_i] = 360.0;
        }
      }
      coder::internal::sort(curr_yaws);
      coder::diff(curr_yaws, diffAngsDeg);
      totalSweptAngle = coder::sum(diffAngsDeg);
      if ((pulseList.size(0) < 4) || (totalSweptAngle < 270.0)) {
        std::printf("Only %f pulse(s) detected over swept angle %f degrees. "
                    "Insufficient to perform PCA Method which requires at "
                    "least 270 degrees of"
                    " sweep and 4 pulses received. Returning DOA based on "
                    "maximum signal strength.",
                    static_cast<double>(pulseList.size(0)), totalSweptAngle);
        std::fflush(stdout);
        // wp(2) = NaN; wp(1) = NaN;tau = NaN; line_scale = 0;
        coder::internal::maximum(curr_pulses_snrLin, maxdimlen);
        if ((maxdimlen < 1) || (maxdimlen > angs.size(0))) {
          rtDynamicBoundsError(maxdimlen, 1, angs.size(0), c_emlrtBCI);
        }
        totalSweptAngle = angs[maxdimlen - 1];
      } else {
        double absxk;
        double b_scale;
        double c_y;
        double d_y;
        double t;
        curr_yaws.set_size(angs.size(0));
        maxdimlen = angs.size(0);
        for (i = 0; i < maxdimlen; i++) {
          curr_yaws[i] = angs[i];
        }
        n = angs.size(0);
        for (int b_i{0}; b_i < n; b_i++) {
          curr_yaws[b_i] = std::cos(curr_yaws[b_i]);
        }
        if (y) {
          emlrtDimSizeImpxCheckR2021b(curr_pulses_snrLin.size(0),
                                      curr_yaws.size(0), c_emlrtECI);
        }
        n = angs.size(0);
        for (int b_i{0}; b_i < n; b_i++) {
          angs[b_i] = std::sin(angs[b_i]);
        }
        if (y) {
          emlrtDimSizeImpxCheckR2021b(curr_pulses_snrLin.size(0), angs.size(0),
                                      d_emlrtECI);
        }
        if (curr_pulses_snrLin.size(0) == curr_yaws.size(0)) {
          curr_yaws.set_size(curr_pulses_snrLin.size(0));
          maxdimlen = curr_pulses_snrLin.size(0);
          for (i = 0; i < maxdimlen; i++) {
            curr_yaws[i] = curr_pulses_snrLin[i] * curr_yaws[i];
          }
        } else {
          b_times(curr_yaws, curr_pulses_snrLin);
        }
        if (curr_pulses_snrLin.size(0) == angs.size(0)) {
          maxdimlen = curr_pulses_snrLin.size(0);
          for (i = 0; i < maxdimlen; i++) {
            curr_pulses_snrLin[i] = curr_pulses_snrLin[i] * angs[i];
          }
        } else {
          times(curr_pulses_snrLin, angs);
        }
        if (curr_pulses_snrLin.size(0) != curr_yaws.size(0)) {
          i_rtErrorWithMessageID(n_emlrtRTEI.fName, n_emlrtRTEI.lineNo);
        }
        Pe_star_dB.set_size(curr_yaws.size(0), 2);
        maxdimlen = curr_yaws.size(0);
        for (i = 0; i < maxdimlen; i++) {
          Pe_star_dB[i] = curr_yaws[i];
        }
        maxdimlen = curr_pulses_snrLin.size(0);
        for (i = 0; i < maxdimlen; i++) {
          Pe_star_dB[i + Pe_star_dB.size(0)] = curr_pulses_snrLin[i];
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
          emlrtDimSizeImpxCheckR2021b(a.size(0), n, emlrtECI);
        }
        if ((a.size(1) != n) && ((a.size(1) != 1) && (n != 1))) {
          emlrtDimSizeImpxCheckR2021b(a.size(1), n, e_emlrtECI);
        }
        if ((a.size(0) == n) && (a.size(1) == n)) {
          maxdimlen = a.size(0) * a.size(1);
          for (i = 0; i < maxdimlen; i++) {
            a[i] = a[i] - totalSweptAngle;
          }
        } else {
          binary_expand_op(a, totalSweptAngle, n);
        }
        if (Pe_star_dB.size(0) != a.size(1)) {
          if ((a.size(0) == 1) && (a.size(1) == 1)) {
            q_rtErrorWithMessageID(ab_emlrtRTEI.fName, ab_emlrtRTEI.lineNo);
          } else {
            p_rtErrorWithMessageID(bb_emlrtRTEI.fName, bb_emlrtRTEI.lineNo);
          }
        }
        coder::internal::blas::mtimes(a, Pe_star_dB, Pe_dB);
        b_y.set_size(2, Pe_star_dB.size(0));
        maxdimlen = Pe_star_dB.size(0);
        for (i = 0; i < maxdimlen; i++) {
          b_y[2 * i] = totalSweptAngle * Pe_star_dB[i];
          b_y[2 * i + 1] = totalSweptAngle * Pe_star_dB[i + Pe_star_dB.size(0)];
        }
        if (b_y.size(1) != n) {
          if (n == 1) {
            q_rtErrorWithMessageID(ab_emlrtRTEI.fName, ab_emlrtRTEI.lineNo);
          } else {
            p_rtErrorWithMessageID(bb_emlrtRTEI.fName, bb_emlrtRTEI.lineNo);
          }
        }
        n = b_y.size(1);
        totalSweptAngle = 0.0;
        Pavg_idx_1 = 0.0;
        if (b_y.size(1) > 2147483646) {
          coder::check_forloop_overflow_error();
        }
        for (int b_i{0}; b_i < n; b_i++) {
          maxdimlen = b_i << 1;
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
          rtDynamicBoundsError(2, 1, Pe_star_dB.size(0), d_emlrtBCI);
        }
        if (Pe_star_dB.size(0) < 1) {
          rtDynamicBoundsError(1, 1, Pe_star_dB.size(0), e_emlrtBCI);
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
