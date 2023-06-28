//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: doapca.cpp
//
// MATLAB Coder version            : 5.6
// C/C++ source code generated on  : 27-Jun-2023 16:44:57
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
// DOAPCA developes a bearing estimate for a series of received radio pulses
// based on the principle component analysis method.
//    This function conducts a principle component analysis type bearing
//    estimate on signal pulses in the pulseList vector. Each pulse signal
//    corresponds to a given heading (pulse_yaw). The function assumes the
//    output of the PCA method to be the mean of a vonMises distribution
//    and then finds the associated kappa value for that distribution that
//    best fits the data.
//
//
//
// INPUTS
//    pulseList           a (px1) vector of ReceivedPulse objects
//    strengthtype        a char array of 'power' or 'amplitude' indicating
//                        the strength used in the PCA method should use the
//                        signal amplitude or power. If power is used, the
//                        square of the inputs pulse signal is used. If
//                        amplitude if fed as pulse_sig and power is
//                        selected, the inputs to the PCA is power. If power
//                        is fed as pulse_sig and amplitude is selected as
//                        strength type, the input to the PCA is power. See
//                        table below
//                             pulse_sig           strengthtype        PCA input
//                        ------------------------------------------------------
//                             pulse amplitudes    amplitude           signal
//                             amplitude pulse amplitudes    power signal power
//                             pulse power         amplitude           signal
//                             power pulse power         power power of signal
//                             power (power^2) -  this shouldn't likely be used.
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
//    kappa               a (1x1) double containing the kappa value fitted
//                        vonMises distribution
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
      102,      // lineNo
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
      116,      // lineNo
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
      116,      // lineNo
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
      107,      // lineNo
      19,       // colNo
      "doapca", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/uavrt_localization_utils/do"
      "apca.m" // pName
  };
  static rtEqualityCheckInfo d_emlrtECI{
      1,        // nDims
      107,      // lineNo
      40,       // colNo
      "doapca", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/uavrt_localization_utils/do"
      "apca.m" // pName
  };
  static rtEqualityCheckInfo e_emlrtECI{
      2,        // nDims
      109,      // lineNo
      14,       // colNo
      "doapca", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/uavrt_localization_utils/do"
      "apca.m" // pName
  };
  static rtEqualityCheckInfo emlrtECI{
      1,        // nDims
      109,      // lineNo
      14,       // colNo
      "doapca", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/uavrt_localization_utils/do"
      "apca.m" // pName
  };
  static rtRunTimeErrorInfo r_emlrtRTEI{
      74,                 // lineNo
      "reshapeSizeChecks" // fName
  };
  static rtRunTimeErrorInfo s_emlrtRTEI{
      81,                 // lineNo
      "reshapeSizeChecks" // fName
  };
  static rtRunTimeErrorInfo t_emlrtRTEI{
      133,                  // lineNo
      "dynamic_size_checks" // fName
  };
  static rtRunTimeErrorInfo u_emlrtRTEI{
      138,                  // lineNo
      "dynamic_size_checks" // fName
  };
  coder::array<d_struct_T, 2U> r1;
  coder::array<double, 2U> Pe_dB;
  coder::array<double, 2U> Pe_star_dB;
  coder::array<double, 2U> a;
  coder::array<double, 2U> c_y;
  coder::array<double, 2U> r;
  coder::array<double, 2U> r2;
  coder::array<double, 1U> P_all_ang_unscaled;
  coder::array<double, 1U> angs;
  coder::array<double, 1U> b_curr_yaws;
  coder::array<double, 1U> diffAngsDeg;
  coder::array<double, 1U> r3;
  coder::array<boolean_T, 1U> curr_yaws;
  coder::array<boolean_T, 1U> positiveInput;
  coder::array<boolean_T, 1U> r4;
  double VdB[4];
  double DOA;
  int k;
  int n;
  int nx;
  boolean_T guard1{false};
  boolean_T y;
  n = pulseList.size(0);
  if (pulseList.size(0) == 0) {
    k = 0;
  } else {
    k = pulseList.size(0);
  }
  r.set_size(1, k);
  if (pulseList.size(0) > 2147483646) {
    coder::check_forloop_overflow_error();
  }
  for (nx = 0; nx < n; nx++) {
    r[nx] = pulseList[nx].strength;
  }
  n = 1;
  if (r.size(1) > 1) {
    n = r.size(1);
  }
  nx = r.size(1);
  if (nx >= n) {
    n = nx;
  }
  if (pulseList.size(0) > n) {
    o_rtErrorWithMessageID(r_emlrtRTEI.fName, r_emlrtRTEI.lineNo);
  }
  if (pulseList.size(0) != r.size(1)) {
    n_rtErrorWithMessageID(s_emlrtRTEI.fName, s_emlrtRTEI.lineNo);
  }
  coder::internal::horzcatStructList(pulseList, r1);
  nx = r1.size(0) * r1.size(1);
  n = r1.size(0);
  if (r1.size(1) > r1.size(0)) {
    n = r1.size(1);
  }
  if (nx >= n) {
    n = nx;
  }
  if (pulseList.size(0) > n) {
    o_rtErrorWithMessageID(r_emlrtRTEI.fName, r_emlrtRTEI.lineNo);
  }
  if (n < 1) {
    o_rtErrorWithMessageID(r_emlrtRTEI.fName, r_emlrtRTEI.lineNo);
  }
  if (pulseList.size(0) != nx) {
    n_rtErrorWithMessageID(s_emlrtRTEI.fName, s_emlrtRTEI.lineNo);
  }
  n = pulseList.size(0);
  r2.set_size(1, k);
  for (nx = 0; nx < n; nx++) {
    r2[nx] = r1[nx].yaw_deg;
  }
  n = 1;
  if (r2.size(1) > 1) {
    n = r2.size(1);
  }
  nx = r2.size(1);
  if (nx >= n) {
    n = nx;
  }
  if (pulseList.size(0) > n) {
    o_rtErrorWithMessageID(r_emlrtRTEI.fName, r_emlrtRTEI.lineNo);
  }
  if (pulseList.size(0) != r2.size(1)) {
    n_rtErrorWithMessageID(s_emlrtRTEI.fName, s_emlrtRTEI.lineNo);
  }
  // Define for Coder so DOA is defined for all execution paths
  DOA = rtNaN;
  tau = rtNaN;
  curr_yaws.set_size(pulseList.size(0));
  nx = pulseList.size(0);
  for (k = 0; k < nx; k++) {
    curr_yaws[k] = (r[k] < 0.0);
  }
  y = coder::any(curr_yaws);
  guard1 = false;
  if (y) {
    guard1 = true;
  } else {
    nx = pulseList.size(0);
    b_curr_yaws.set_size(pulseList.size(0));
    for (k = 0; k < nx; k++) {
      b_curr_yaws[k] = std::abs(r[k]);
    }
    curr_yaws.set_size(b_curr_yaws.size(0));
    nx = b_curr_yaws.size(0);
    for (k = 0; k < nx; k++) {
      curr_yaws[k] = (b_curr_yaws[k] == rtInf);
    }
    y = coder::any(curr_yaws);
    if (y) {
      guard1 = true;
    } else {
      double Pavg_idx_1;
      double b_y;
      double scale;
      double totalSweptAngle;
      n = pulseList.size(0);
      r3 = r.reshape(n);
      Pavg_idx_1 = coder::internal::minimum(r3);
      b_y = Pavg_idx_1 * Pavg_idx_1;
      P_all_ang_unscaled.set_size(pulseList.size(0));
      nx = pulseList.size(0);
      angs.set_size(pulseList.size(0));
      positiveInput.set_size(pulseList.size(0));
      b_curr_yaws.set_size(pulseList.size(0));
      for (k = 0; k < nx; k++) {
        totalSweptAngle = r[k];
        P_all_ang_unscaled[k] = totalSweptAngle * totalSweptAngle / b_y;
        totalSweptAngle = r2[k];
        angs[k] = totalSweptAngle * 3.1415926535897931 / 180.0;
        positiveInput[k] = (totalSweptAngle > 0.0);
        if (std::isnan(totalSweptAngle) || std::isinf(totalSweptAngle)) {
          scale = rtNaN;
        } else if (totalSweptAngle == 0.0) {
          scale = 0.0;
        } else {
          scale = std::fmod(totalSweptAngle, 360.0);
          if (scale == 0.0) {
            scale = 0.0;
          } else if (totalSweptAngle < 0.0) {
            scale += 360.0;
          }
        }
        b_curr_yaws[k] = scale;
      }
      curr_yaws.set_size(b_curr_yaws.size(0));
      nx = b_curr_yaws.size(0);
      for (k = 0; k < nx; k++) {
        curr_yaws[k] = (b_curr_yaws[k] == 0.0);
      }
      y = ((curr_yaws.size(0) != positiveInput.size(0)) &&
           ((curr_yaws.size(0) != 1) && (positiveInput.size(0) != 1)));
      if (y) {
        emlrtDimSizeImpxCheckR2021b(curr_yaws.size(0), positiveInput.size(0),
                                    b_emlrtECI);
      }
      if (curr_yaws.size(0) == positiveInput.size(0)) {
        r4.set_size(curr_yaws.size(0));
        nx = curr_yaws.size(0);
        for (k = 0; k < nx; k++) {
          r4[k] = (curr_yaws[k] && positiveInput[k]);
        }
      } else {
        b_and(r4, curr_yaws, positiveInput);
      }
      n = r4.size(0) - 1;
      for (nx = 0; nx <= n; nx++) {
        if (r4[nx]) {
          if (nx > b_curr_yaws.size(0) - 1) {
            rtDynamicBoundsError(nx, 0, b_curr_yaws.size(0) - 1, b_emlrtBCI);
          }
          b_curr_yaws[nx] = 360.0;
        }
      }
      coder::internal::sort(b_curr_yaws);
      coder::diff(b_curr_yaws, diffAngsDeg);
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
        coder::internal::maximum(P_all_ang_unscaled, n);
        if ((n < 1) || (n > angs.size(0))) {
          rtDynamicBoundsError(n, 1, angs.size(0), c_emlrtBCI);
        }
        totalSweptAngle = angs[n - 1];
      } else {
        double absxk;
        double b_scale;
        double d_y;
        double t;
        b_curr_yaws.set_size(angs.size(0));
        nx = angs.size(0);
        for (k = 0; k < nx; k++) {
          b_curr_yaws[k] = angs[k];
        }
        nx = angs.size(0);
        for (k = 0; k < nx; k++) {
          b_curr_yaws[k] = std::cos(b_curr_yaws[k]);
        }
        if (y) {
          emlrtDimSizeImpxCheckR2021b(P_all_ang_unscaled.size(0),
                                      b_curr_yaws.size(0), c_emlrtECI);
        }
        nx = angs.size(0);
        for (k = 0; k < nx; k++) {
          angs[k] = std::sin(angs[k]);
        }
        if (y) {
          emlrtDimSizeImpxCheckR2021b(P_all_ang_unscaled.size(0), angs.size(0),
                                      d_emlrtECI);
        }
        if (P_all_ang_unscaled.size(0) == b_curr_yaws.size(0)) {
          b_curr_yaws.set_size(P_all_ang_unscaled.size(0));
          nx = P_all_ang_unscaled.size(0);
          for (k = 0; k < nx; k++) {
            b_curr_yaws[k] = P_all_ang_unscaled[k] * b_curr_yaws[k];
          }
        } else {
          b_times(b_curr_yaws, P_all_ang_unscaled);
        }
        if (P_all_ang_unscaled.size(0) == angs.size(0)) {
          nx = P_all_ang_unscaled.size(0);
          for (k = 0; k < nx; k++) {
            P_all_ang_unscaled[k] = P_all_ang_unscaled[k] * angs[k];
          }
        } else {
          times(P_all_ang_unscaled, angs);
        }
        if (P_all_ang_unscaled.size(0) != b_curr_yaws.size(0)) {
          i_rtErrorWithMessageID(h_emlrtRTEI.fName, h_emlrtRTEI.lineNo);
        }
        Pe_star_dB.set_size(b_curr_yaws.size(0), 2);
        nx = b_curr_yaws.size(0);
        for (k = 0; k < nx; k++) {
          Pe_star_dB[k] = b_curr_yaws[k];
        }
        nx = P_all_ang_unscaled.size(0);
        for (k = 0; k < nx; k++) {
          Pe_star_dB[k + Pe_star_dB.size(0)] = P_all_ang_unscaled[k];
        }
        nx = Pe_star_dB.size(0);
        if (nx < 2) {
          nx = 2;
        }
        if (Pe_star_dB.size(0) == 0) {
          n = 0;
        } else {
          n = nx;
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
          nx = a.size(0) * a.size(1);
          for (k = 0; k < nx; k++) {
            a[k] = a[k] - totalSweptAngle;
          }
        } else {
          binary_expand_op(a, totalSweptAngle, n);
        }
        if (Pe_star_dB.size(0) != a.size(1)) {
          if ((a.size(0) == 1) && (a.size(1) == 1)) {
            q_rtErrorWithMessageID(t_emlrtRTEI.fName, t_emlrtRTEI.lineNo);
          } else {
            p_rtErrorWithMessageID(u_emlrtRTEI.fName, u_emlrtRTEI.lineNo);
          }
        }
        coder::internal::blas::mtimes(a, Pe_star_dB, Pe_dB);
        c_y.set_size(2, Pe_star_dB.size(0));
        nx = Pe_star_dB.size(0);
        for (k = 0; k < nx; k++) {
          c_y[2 * k] = totalSweptAngle * Pe_star_dB[k];
          c_y[2 * k + 1] = totalSweptAngle * Pe_star_dB[k + Pe_star_dB.size(0)];
        }
        if (c_y.size(1) != n) {
          if (n == 1) {
            q_rtErrorWithMessageID(t_emlrtRTEI.fName, t_emlrtRTEI.lineNo);
          } else {
            p_rtErrorWithMessageID(u_emlrtRTEI.fName, u_emlrtRTEI.lineNo);
          }
        }
        nx = c_y.size(1);
        totalSweptAngle = 0.0;
        Pavg_idx_1 = 0.0;
        if (c_y.size(1) > 2147483646) {
          coder::check_forloop_overflow_error();
        }
        for (k = 0; k < nx; k++) {
          n = k << 1;
          totalSweptAngle += c_y[n];
          Pavg_idx_1 += c_y[n + 1];
        }
        coder::svd(Pe_dB, a, Pe_star_dB, VdB);
        // w2 = VdB(:,2);
        scale = 3.3121686421112381E-170;
        b_scale = 3.3121686421112381E-170;
        absxk = std::abs(totalSweptAngle);
        if (absxk > 3.3121686421112381E-170) {
          b_y = 1.0;
          scale = absxk;
        } else {
          t = absxk / 3.3121686421112381E-170;
          b_y = t * t;
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
          b_y = b_y * t * t + 1.0;
          scale = absxk;
        } else {
          t = absxk / scale;
          b_y += t * t;
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
        b_y = scale * std::sqrt(b_y);
        d_y = b_scale * std::sqrt(d_y);
        Pavg_idx_1 =
            (totalSweptAngle * VdB[0] + Pavg_idx_1 * VdB[1]) / (b_y * d_y);
        // beta = norm(Pavg)^2/SdB(1,1)^2;
        if (Pe_star_dB.size(0) < 2) {
          rtDynamicBoundsError(2, 1, Pe_star_dB.size(0), d_emlrtBCI);
        }
        if (Pe_star_dB.size(0) < 1) {
          rtDynamicBoundsError(1, 1, Pe_star_dB.size(0), e_emlrtBCI);
        }
        totalSweptAngle = Pe_star_dB[Pe_star_dB.size(0) + 1];
        scale = Pe_star_dB[0];
        tau = 1.0 - totalSweptAngle * totalSweptAngle / (scale * scale);
        // line_scale = max(P_all_ang)/norm(wp);%the wp size changes if w1
        totalSweptAngle =
            rt_atan2d_snf(Pavg_idx_1 * VdB[1], Pavg_idx_1 * VdB[0]);
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
