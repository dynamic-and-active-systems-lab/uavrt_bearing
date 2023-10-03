//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: PulseStruct.cpp
//
// MATLAB Coder version            : 23.2
// C/C++ source code generated on  : 03-Oct-2023 13:40:05
//

// Include Files
#include "PulseStruct.h"
#include "bearing_data.h"
#include "bearing_internal_types.h"
#include "bearing_rtwutil.h"
#include "bearing_types.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "coder_bounded_array.h"
#include <cmath>
#include <cstdio>

// Function Definitions
//
// PULSESTRUCT Generates a Pulse structure
//    This function generates a standard pulse structure with the
//    following fields:
//
//    position   Position as a PositionStruct
//    euler      Euler angles as a EulerAngleStruct
//    time       Time of received pulse in seconds
//    time_next  Expected time of next pulse
//    snrdB        Pulse signal to noise ratio in dB
//    freqMHz    Frequency of received pulse in MHz
//    tagID      Tag ID number of received pulse
//
// Arguments    : const coder::array<double, 1U> &tagID
//                const coder::array<double, 1U> &freqMHz
//                const coder::array<struct_T, 2U> &pos
//                const coder::array<d_struct_T, 2U> &euler
//                const coder::array<double, 1U> &b_time
//                const coder::array<double, 1U> &timeNext
//                const coder::array<double, 1U> &snrdB
//                const coder::array<double, 1U> &stftMag2
//                const coder::array<double, 1U> &groupSeqCount
//                const coder::array<double, 1U> &groupIndex
//                const coder::array<double, 1U> &groupsnrdB
//                const coder::array<double, 1U> &noisePSD
//                const coder::array<double, 1U> &detectStatus
//                const coder::array<double, 1U> &confirmStatus
//                const coder::array<double, 1U> &antennaOffset
//                coder::array<e_struct_T, 2U> &pulse
// Return Type  : void
//
void PulseStruct(const coder::array<double, 1U> &tagID,
                 const coder::array<double, 1U> &freqMHz,
                 const coder::array<struct_T, 2U> &pos,
                 const coder::array<d_struct_T, 2U> &euler,
                 const coder::array<double, 1U> &b_time,
                 const coder::array<double, 1U> &timeNext,
                 const coder::array<double, 1U> &snrdB,
                 const coder::array<double, 1U> &stftMag2,
                 const coder::array<double, 1U> &groupSeqCount,
                 const coder::array<double, 1U> &groupIndex,
                 const coder::array<double, 1U> &groupsnrdB,
                 const coder::array<double, 1U> &noisePSD,
                 const coder::array<double, 1U> &detectStatus,
                 const coder::array<double, 1U> &confirmStatus,
                 const coder::array<double, 1U> &antennaOffset,
                 coder::array<e_struct_T, 2U> &pulse)
{
  static rtBoundsCheckInfo ab_emlrtBCI{
      -1,            // iFirst
      -1,            // iLast
      116,           // lineNo
      19,            // colNo
      "pulse",       // aName
      "PulseStruct", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/PulseStruct.m", // pName
      0                                              // checkKind
  };
  static rtBoundsCheckInfo b_emlrtBCI{
      -1,            // iFirst
      -1,            // iLast
      114,           // lineNo
      19,            // colNo
      "pulse",       // aName
      "PulseStruct", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/PulseStruct.m", // pName
      0                                              // checkKind
  };
  static rtBoundsCheckInfo bb_emlrtBCI{
      -1,            // iFirst
      -1,            // iLast
      116,           // lineNo
      13,            // colNo
      "pos",         // aName
      "PulseStruct", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/PulseStruct.m", // pName
      0                                              // checkKind
  };
  static rtBoundsCheckInfo c_emlrtBCI{
      -1,            // iFirst
      -1,            // iLast
      104,           // lineNo
      19,            // colNo
      "pulse",       // aName
      "PulseStruct", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/PulseStruct.m", // pName
      0                                              // checkKind
  };
  static rtBoundsCheckInfo cb_emlrtBCI{
      -1,            // iFirst
      -1,            // iLast
      117,           // lineNo
      19,            // colNo
      "pulse",       // aName
      "PulseStruct", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/PulseStruct.m", // pName
      0                                              // checkKind
  };
  static rtBoundsCheckInfo d_emlrtBCI{
      -1,            // iFirst
      -1,            // iLast
      104,           // lineNo
      39,            // colNo
      "tagID",       // aName
      "PulseStruct", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/PulseStruct.m", // pName
      0                                              // checkKind
  };
  static rtBoundsCheckInfo db_emlrtBCI{
      -1,            // iFirst
      -1,            // iLast
      117,           // lineNo
      13,            // colNo
      "euler",       // aName
      "PulseStruct", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/PulseStruct.m", // pName
      0                                              // checkKind
  };
  static rtBoundsCheckInfo e_emlrtBCI{
      -1,            // iFirst
      -1,            // iLast
      105,           // lineNo
      19,            // colNo
      "pulse",       // aName
      "PulseStruct", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/PulseStruct.m", // pName
      0                                              // checkKind
  };
  static rtBoundsCheckInfo eb_emlrtBCI{
      -1,            // iFirst
      -1,            // iLast
      118,           // lineNo
      19,            // colNo
      "pulse",       // aName
      "PulseStruct", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/PulseStruct.m", // pName
      0                                              // checkKind
  };
  static rtBoundsCheckInfo f_emlrtBCI{
      -1,            // iFirst
      -1,            // iLast
      105,           // lineNo
      43,            // colNo
      "freqMHz",     // aName
      "PulseStruct", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/PulseStruct.m", // pName
      0                                              // checkKind
  };
  static rtBoundsCheckInfo fb_emlrtBCI{
      -1,              // iFirst
      -1,              // iLast
      118,             // lineNo
      55,              // colNo
      "antennaOffset", // aName
      "PulseStruct",   // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/PulseStruct.m", // pName
      0                                              // checkKind
  };
  static rtBoundsCheckInfo g_emlrtBCI{
      -1,            // iFirst
      -1,            // iLast
      106,           // lineNo
      19,            // colNo
      "pulse",       // aName
      "PulseStruct", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/PulseStruct.m", // pName
      0                                              // checkKind
  };
  static rtBoundsCheckInfo h_emlrtBCI{
      -1,            // iFirst
      -1,            // iLast
      106,           // lineNo
      40,            // colNo
      "time",        // aName
      "PulseStruct", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/PulseStruct.m", // pName
      0                                              // checkKind
  };
  static rtBoundsCheckInfo i_emlrtBCI{
      -1,            // iFirst
      -1,            // iLast
      107,           // lineNo
      19,            // colNo
      "pulse",       // aName
      "PulseStruct", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/PulseStruct.m", // pName
      0                                              // checkKind
  };
  static rtBoundsCheckInfo j_emlrtBCI{
      -1,            // iFirst
      -1,            // iLast
      107,           // lineNo
      44,            // colNo
      "timeNext",    // aName
      "PulseStruct", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/PulseStruct.m", // pName
      0                                              // checkKind
  };
  static rtBoundsCheckInfo k_emlrtBCI{
      -1,            // iFirst
      -1,            // iLast
      108,           // lineNo
      19,            // colNo
      "pulse",       // aName
      "PulseStruct", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/PulseStruct.m", // pName
      0                                              // checkKind
  };
  static rtBoundsCheckInfo l_emlrtBCI{
      -1,            // iFirst
      -1,            // iLast
      108,           // lineNo
      41,            // colNo
      "snrdB",       // aName
      "PulseStruct", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/PulseStruct.m", // pName
      0                                              // checkKind
  };
  static rtBoundsCheckInfo m_emlrtBCI{
      -1,            // iFirst
      -1,            // iLast
      109,           // lineNo
      19,            // colNo
      "pulse",       // aName
      "PulseStruct", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/PulseStruct.m", // pName
      0                                              // checkKind
  };
  static rtBoundsCheckInfo n_emlrtBCI{
      -1,            // iFirst
      -1,            // iLast
      109,           // lineNo
      47,            // colNo
      "stftMag2",    // aName
      "PulseStruct", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/PulseStruct.m", // pName
      0                                              // checkKind
  };
  static rtBoundsCheckInfo o_emlrtBCI{
      -1,            // iFirst
      -1,            // iLast
      110,           // lineNo
      19,            // colNo
      "pulse",       // aName
      "PulseStruct", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/PulseStruct.m", // pName
      0                                              // checkKind
  };
  static rtBoundsCheckInfo p_emlrtBCI{
      -1,              // iFirst
      -1,              // iLast
      110,             // lineNo
      57,              // colNo
      "groupSeqCount", // aName
      "PulseStruct",   // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/PulseStruct.m", // pName
      0                                              // checkKind
  };
  static rtBoundsCheckInfo q_emlrtBCI{
      -1,            // iFirst
      -1,            // iLast
      111,           // lineNo
      19,            // colNo
      "pulse",       // aName
      "PulseStruct", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/PulseStruct.m", // pName
      0                                              // checkKind
  };
  static rtBoundsCheckInfo r_emlrtBCI{
      -1,            // iFirst
      -1,            // iLast
      111,           // lineNo
      51,            // colNo
      "groupIndex",  // aName
      "PulseStruct", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/PulseStruct.m", // pName
      0                                              // checkKind
  };
  static rtBoundsCheckInfo s_emlrtBCI{
      -1,            // iFirst
      -1,            // iLast
      112,           // lineNo
      19,            // colNo
      "pulse",       // aName
      "PulseStruct", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/PulseStruct.m", // pName
      0                                              // checkKind
  };
  static rtBoundsCheckInfo t_emlrtBCI{
      -1,            // iFirst
      -1,            // iLast
      112,           // lineNo
      51,            // colNo
      "groupsnrdB",  // aName
      "PulseStruct", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/PulseStruct.m", // pName
      0                                              // checkKind
  };
  static rtBoundsCheckInfo u_emlrtBCI{
      -1,            // iFirst
      -1,            // iLast
      113,           // lineNo
      19,            // colNo
      "pulse",       // aName
      "PulseStruct", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/PulseStruct.m", // pName
      0                                              // checkKind
  };
  static rtBoundsCheckInfo v_emlrtBCI{
      -1,            // iFirst
      -1,            // iLast
      113,           // lineNo
      47,            // colNo
      "noisePSD",    // aName
      "PulseStruct", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/PulseStruct.m", // pName
      0                                              // checkKind
  };
  static rtBoundsCheckInfo w_emlrtBCI{
      -1,             // iFirst
      -1,             // iLast
      114,            // lineNo
      61,             // colNo
      "detectStatus", // aName
      "PulseStruct",  // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/PulseStruct.m", // pName
      0                                              // checkKind
  };
  static rtBoundsCheckInfo x_emlrtBCI{
      -1,              // iFirst
      -1,              // iLast
      115,             // lineNo
      62,              // colNo
      "confirmStatus", // aName
      "PulseStruct",   // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/PulseStruct.m", // pName
      0                                              // checkKind
  };
  static rtBoundsCheckInfo y_emlrtBCI{
      -1,            // iFirst
      -1,            // iLast
      115,           // lineNo
      19,            // colNo
      "pulse",       // aName
      "PulseStruct", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/PulseStruct.m", // pName
      0                                              // checkKind
  };
  d_struct_T eulInit;
  e_struct_T pulseInit;
  struct_T posInit;
  int ntilerows;
  boolean_T x[2];
  boolean_T exitg1;
  boolean_T y;
  //    If input vectors are provided, they must be the same size size. In that
  //    case, the output is a vector of structures.
  //
  // INPUTS:
  //    pos       -   n x 1 vector of positions (as PulseStructs)
  //    euler     -   n x 1 vector of eulerangles (as EulerAngleStructs)
  //    time      -   n x 1 vector of time of arrival of pulse
  //    timeNext  -   n x 1 vector of predicted time of arrival of next pulse
  //    snrdB     -   n x 1 vector of pulse snr  (doubles)
  //    freqMHz   -   n x 1 vector of pulse frequencies in MHz (doubles)
  //    tagID     -   n x 1 vector of pulse tag IDs (doubles)
  //
  // OUTPUTS:
  //    pulse   -   n x 1 vector of pulse structures
  //
  // --------------------------------------------------------------------------
  //  Author: Michael Shafer
  //  Date: 2023-06-12
  // --------------------------------------------------------------------------
  // POSITIONSTRUCT Generates a position structure
  //    This function generates a standard position structure with the
  //    following fields:
  //
  //    latitude_deg        Latitude in degrees
  //    latitude_deg        Longitude in degrees
  //    absolute_altitude_m Altitude in meters above ground level
  //    relative_altitude_m Altitude in meters above sea level
  //
  //    If input vectors are provided, they must be the same size size. In that
  //    case, the output is a vector of position structures.
  //
  // INPUTS:
  //    lat    -   n x 1 vector of doubles of latitudes
  //    lon    -   n x 1 vector of doubles of longitudes
  //    altAbs -   n x 1 vector of doubles of altitudes above sea level in
  //               meters
  //    altRel -   n x 1 vector of doubles of altitudes above ground level in
  //               meters
  //
  // OUTPUTS:
  //    pos    -   n x 1 vector of position structures
  //
  // --------------------------------------------------------------------------
  //  Author: Michael Shafer
  //  Date: 2023-06-12
  // --------------------------------------------------------------------------
  posInit.latitude_deg = 0.0;
  posInit.longitude_deg = 0.0;
  posInit.absolute_altitude_m = 0.0;
  posInit.relative_altitude_m = 0.0;
  pulseInit.position.size[0] = 1;
  pulseInit.position.size[1] = 1;
  pulseInit.position.data[0] = posInit;
  // EULERANGLESTRUCT Generates a Euler Angle structure
  //    This function generates a standard Euler angle structure with the
  //    following fields:
  //
  //    roll_deg    Roll angle in degrees
  //    pitch_deg   Pitch angle in degrees
  //    yaw_deg     Yaw angle in degrees
  //    If input vectors are provided, they must be the same size size. In that
  //    case, the output is a vector of structures.
  //
  // INPUTS:
  //    roll  -   n x 1 vector of roll angles (doubles)
  //    pitch -   n x 1 vector of pitch angles (doubles)
  //    yaw   -   n x 1 vector of yaw angles (doubles)
  //
  // OUTPUTS:
  //    eul    -   n x 1 vector of Euler angle structures
  //
  // --------------------------------------------------------------------------
  //  Author: Michael Shafer
  //  Date: 2023-06-12
  // --------------------------------------------------------------------------
  eulInit.yaw_deg = 0.0;
  pulseInit.euler.size[0] = 1;
  pulseInit.euler.size[1] = 1;
  pulseInit.euler.data[0] = eulInit;
  pulseInit.tagID = 0.0;
  pulseInit.time = 0.0;
  pulseInit.snrdB = 0.0;
  pulseInit.noisePSD = 0.0;
  pulseInit.antennaOffset = 0.0;
  pulse.set_size(1, 1);
  pulse[0] = pulseInit;
  x[0] = ((pos.size(0) == freqMHz.size(0)) || (pos.size(0) == tagID.size(0)) ||
          (pos.size(0) == euler.size(0)) || (pos.size(0) == b_time.size(0)) ||
          (pos.size(0) == timeNext.size(0)) || (pos.size(0) == snrdB.size(0)) ||
          (pos.size(0) == stftMag2.size(0)) ||
          (pos.size(0) == groupSeqCount.size(0)) ||
          (pos.size(0) == groupIndex.size(0)) ||
          (pos.size(0) == groupsnrdB.size(0)) ||
          (pos.size(0) == noisePSD.size(0)) ||
          (pos.size(0) == detectStatus.size(0)) ||
          (pos.size(0) == detectStatus.size(0)) ||
          (pos.size(0) == confirmStatus.size(0)) ||
          (pos.size(0) == antennaOffset.size(0)));
  x[1] = true;
  y = true;
  ntilerows = 0;
  exitg1 = false;
  while ((!exitg1) && (ntilerows < 2)) {
    if (!x[ntilerows]) {
      y = false;
      exitg1 = true;
    } else {
      ntilerows++;
    }
  }
  if (!y) {
    std::printf("UAV-RT: All inputs must be the same size. ");
    std::fflush(stdout);
  } else {
    // pulse(nRows,nCols) = pulse; %Coder doesn't like this
    pulse.set_size(pos.size(0), 1);
    ntilerows = pos.size(0);
    if (pos.size(0) > 2147483646) {
      coder::check_forloop_overflow_error();
    }
    for (int itilerow{0}; itilerow < ntilerows; itilerow++) {
      pulse[itilerow] = pulseInit;
    }
    ntilerows = pos.size(0);
    for (int itilerow{0}; itilerow < ntilerows; itilerow++) {
      if (itilerow + 1 > pulse.size(0)) {
        rtDynamicBoundsError(itilerow + 1, 1, pulse.size(0), c_emlrtBCI);
      }
      if (itilerow + 1 > tagID.size(0)) {
        rtDynamicBoundsError(itilerow + 1, 1, tagID.size(0), d_emlrtBCI);
      }
      pulse[itilerow].tagID = tagID[itilerow];
      if (itilerow + 1 > pulse.size(0)) {
        rtDynamicBoundsError(itilerow + 1, 1, pulse.size(0), e_emlrtBCI);
      }
      if (itilerow + 1 > freqMHz.size(0)) {
        rtDynamicBoundsError(itilerow + 1, 1, freqMHz.size(0), f_emlrtBCI);
      }
      if (itilerow + 1 > pulse.size(0)) {
        rtDynamicBoundsError(itilerow + 1, 1, pulse.size(0), g_emlrtBCI);
      }
      if (itilerow + 1 > b_time.size(0)) {
        rtDynamicBoundsError(itilerow + 1, 1, b_time.size(0), h_emlrtBCI);
      }
      pulse[itilerow].time = b_time[itilerow];
      if (itilerow + 1 > pulse.size(0)) {
        rtDynamicBoundsError(itilerow + 1, 1, pulse.size(0), i_emlrtBCI);
      }
      if (itilerow + 1 > timeNext.size(0)) {
        rtDynamicBoundsError(itilerow + 1, 1, timeNext.size(0), j_emlrtBCI);
      }
      if (itilerow + 1 > pulse.size(0)) {
        rtDynamicBoundsError(itilerow + 1, 1, pulse.size(0), k_emlrtBCI);
      }
      if (itilerow + 1 > snrdB.size(0)) {
        rtDynamicBoundsError(itilerow + 1, 1, snrdB.size(0), l_emlrtBCI);
      }
      pulse[itilerow].snrdB = snrdB[itilerow];
      if (itilerow + 1 > pulse.size(0)) {
        rtDynamicBoundsError(itilerow + 1, 1, pulse.size(0), m_emlrtBCI);
      }
      if (itilerow + 1 > stftMag2.size(0)) {
        rtDynamicBoundsError(itilerow + 1, 1, stftMag2.size(0), n_emlrtBCI);
      }
      if (itilerow + 1 > pulse.size(0)) {
        rtDynamicBoundsError(itilerow + 1, 1, pulse.size(0), o_emlrtBCI);
      }
      if (itilerow + 1 > groupSeqCount.size(0)) {
        rtDynamicBoundsError(itilerow + 1, 1, groupSeqCount.size(0),
                             p_emlrtBCI);
      }
      if (itilerow + 1 > pulse.size(0)) {
        rtDynamicBoundsError(itilerow + 1, 1, pulse.size(0), q_emlrtBCI);
      }
      if (itilerow + 1 > groupIndex.size(0)) {
        rtDynamicBoundsError(itilerow + 1, 1, groupIndex.size(0), r_emlrtBCI);
      }
      if (itilerow + 1 > pulse.size(0)) {
        rtDynamicBoundsError(itilerow + 1, 1, pulse.size(0), s_emlrtBCI);
      }
      if (itilerow + 1 > groupsnrdB.size(0)) {
        rtDynamicBoundsError(itilerow + 1, 1, groupsnrdB.size(0), t_emlrtBCI);
      }
      if (itilerow + 1 > pulse.size(0)) {
        rtDynamicBoundsError(itilerow + 1, 1, pulse.size(0), u_emlrtBCI);
      }
      if (itilerow + 1 > noisePSD.size(0)) {
        rtDynamicBoundsError(itilerow + 1, 1, noisePSD.size(0), v_emlrtBCI);
      }
      pulse[itilerow].noisePSD = noisePSD[itilerow];
      if (itilerow + 1 > detectStatus.size(0)) {
        rtDynamicBoundsError(itilerow + 1, 1, detectStatus.size(0), w_emlrtBCI);
      }
      if (std::isnan(detectStatus[itilerow])) {
        d_rtErrorWithMessageID(c_emlrtRTEI.fName, c_emlrtRTEI.lineNo);
      }
      if (itilerow + 1 > pulse.size(0)) {
        rtDynamicBoundsError(itilerow + 1, 1, pulse.size(0), b_emlrtBCI);
      }
      if (itilerow + 1 > confirmStatus.size(0)) {
        rtDynamicBoundsError(itilerow + 1, 1, confirmStatus.size(0),
                             x_emlrtBCI);
      }
      if (std::isnan(confirmStatus[itilerow])) {
        d_rtErrorWithMessageID(c_emlrtRTEI.fName, c_emlrtRTEI.lineNo);
      }
      if (itilerow + 1 > pulse.size(0)) {
        rtDynamicBoundsError(itilerow + 1, 1, pulse.size(0), y_emlrtBCI);
      }
      if (itilerow + 1 > pulse.size(0)) {
        rtDynamicBoundsError(itilerow + 1, 1, pulse.size(0), ab_emlrtBCI);
      }
      pulse[itilerow].position.size[0] = 1;
      if (itilerow + 1 > pulse.size(0)) {
        rtDynamicBoundsError(itilerow + 1, 1, pulse.size(0), ab_emlrtBCI);
      }
      pulse[itilerow].position.size[1] = 1;
      if (itilerow + 1 > pulse.size(0)) {
        rtDynamicBoundsError(itilerow + 1, 1, pulse.size(0), ab_emlrtBCI);
      }
      if (itilerow + 1 > pos.size(0)) {
        rtDynamicBoundsError(itilerow + 1, 1, pos.size(0), bb_emlrtBCI);
      }
      pulse[itilerow].position.data[0] = pos[itilerow];
      if (itilerow + 1 > pulse.size(0)) {
        rtDynamicBoundsError(itilerow + 1, 1, pulse.size(0), cb_emlrtBCI);
      }
      pulse[itilerow].euler.size[0] = 1;
      if (itilerow + 1 > pulse.size(0)) {
        rtDynamicBoundsError(itilerow + 1, 1, pulse.size(0), cb_emlrtBCI);
      }
      pulse[itilerow].euler.size[1] = 1;
      if (itilerow + 1 > pulse.size(0)) {
        rtDynamicBoundsError(itilerow + 1, 1, pulse.size(0), cb_emlrtBCI);
      }
      if (itilerow + 1 > euler.size(0)) {
        rtDynamicBoundsError(itilerow + 1, 1, euler.size(0), db_emlrtBCI);
      }
      pulse[itilerow].euler.data[0] = euler[itilerow];
      if (itilerow + 1 > pulse.size(0)) {
        rtDynamicBoundsError(itilerow + 1, 1, pulse.size(0), eb_emlrtBCI);
      }
      if (itilerow + 1 > antennaOffset.size(0)) {
        rtDynamicBoundsError(itilerow + 1, 1, antennaOffset.size(0),
                             fb_emlrtBCI);
      }
      pulse[itilerow].antennaOffset = antennaOffset[itilerow];
    }
  }
}

//
// File trailer for PulseStruct.cpp
//
// [EOF]
//
