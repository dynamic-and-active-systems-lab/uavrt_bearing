//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: PulseStruct.cpp
//
// MATLAB Coder version            : 5.6
// C/C++ source code generated on  : 30-Jun-2023 13:13:27
//

// Include Files
#include "PulseStruct.h"
#include "bearing_internal_types.h"
#include "bearing_rtwutil.h"
#include "bearing_types.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "coder_bounded_array.h"
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
//    strength   Strength metric of received pulse
//    freqMHz    Frequency of received pulse in MHz
//    tagID      Tag ID number of received pulse
//
// Arguments    : const coder::array<struct_T, 2U> &pos
//                const coder::array<d_struct_T, 2U> &euler
//                const coder::array<double, 1U> &b_time
//                const coder::array<double, 1U> &strength
//                const coder::array<double, 1U> &freqMHz
//                const coder::array<double, 1U> &tagID
//                coder::array<e_struct_T, 2U> &pulse
// Return Type  : void
//
void PulseStruct(const coder::array<struct_T, 2U> &pos,
                 const coder::array<d_struct_T, 2U> &euler,
                 const coder::array<double, 1U> &b_time,
                 const coder::array<double, 1U> &strength,
                 const coder::array<double, 1U> &freqMHz,
                 const coder::array<double, 1U> &tagID,
                 coder::array<e_struct_T, 2U> &pulse)
{
  static rtBoundsCheckInfo b_emlrtBCI{
      -1,            // iFirst
      -1,            // iLast
      71,            // lineNo
      19,            // colNo
      "pulse",       // aName
      "PulseStruct", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/uavrt_localization_utils/Pu"
      "lseStruct.m", // pName
      0              // checkKind
  };
  static rtBoundsCheckInfo c_emlrtBCI{
      -1,            // iFirst
      -1,            // iLast
      71,            // lineNo
      13,            // colNo
      "pos",         // aName
      "PulseStruct", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/uavrt_localization_utils/Pu"
      "lseStruct.m", // pName
      0              // checkKind
  };
  static rtBoundsCheckInfo d_emlrtBCI{
      -1,            // iFirst
      -1,            // iLast
      72,            // lineNo
      19,            // colNo
      "pulse",       // aName
      "PulseStruct", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/uavrt_localization_utils/Pu"
      "lseStruct.m", // pName
      0              // checkKind
  };
  static rtBoundsCheckInfo e_emlrtBCI{
      -1,            // iFirst
      -1,            // iLast
      72,            // lineNo
      13,            // colNo
      "euler",       // aName
      "PulseStruct", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/uavrt_localization_utils/Pu"
      "lseStruct.m", // pName
      0              // checkKind
  };
  static rtBoundsCheckInfo f_emlrtBCI{
      -1,            // iFirst
      -1,            // iLast
      73,            // lineNo
      19,            // colNo
      "pulse",       // aName
      "PulseStruct", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/uavrt_localization_utils/Pu"
      "lseStruct.m", // pName
      0              // checkKind
  };
  static rtBoundsCheckInfo g_emlrtBCI{
      -1,            // iFirst
      -1,            // iLast
      73,            // lineNo
      40,            // colNo
      "time",        // aName
      "PulseStruct", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/uavrt_localization_utils/Pu"
      "lseStruct.m", // pName
      0              // checkKind
  };
  static rtBoundsCheckInfo h_emlrtBCI{
      -1,            // iFirst
      -1,            // iLast
      74,            // lineNo
      19,            // colNo
      "pulse",       // aName
      "PulseStruct", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/uavrt_localization_utils/Pu"
      "lseStruct.m", // pName
      0              // checkKind
  };
  static rtBoundsCheckInfo i_emlrtBCI{
      -1,            // iFirst
      -1,            // iLast
      74,            // lineNo
      44,            // colNo
      "strength",    // aName
      "PulseStruct", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/uavrt_localization_utils/Pu"
      "lseStruct.m", // pName
      0              // checkKind
  };
  static rtBoundsCheckInfo j_emlrtBCI{
      -1,            // iFirst
      -1,            // iLast
      75,            // lineNo
      19,            // colNo
      "pulse",       // aName
      "PulseStruct", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/uavrt_localization_utils/Pu"
      "lseStruct.m", // pName
      0              // checkKind
  };
  static rtBoundsCheckInfo k_emlrtBCI{
      -1,            // iFirst
      -1,            // iLast
      75,            // lineNo
      43,            // colNo
      "freqMHz",     // aName
      "PulseStruct", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/uavrt_localization_utils/Pu"
      "lseStruct.m", // pName
      0              // checkKind
  };
  static rtBoundsCheckInfo l_emlrtBCI{
      -1,            // iFirst
      -1,            // iLast
      76,            // lineNo
      19,            // colNo
      "pulse",       // aName
      "PulseStruct", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/uavrt_localization_utils/Pu"
      "lseStruct.m", // pName
      0              // checkKind
  };
  static rtBoundsCheckInfo m_emlrtBCI{
      -1,            // iFirst
      -1,            // iLast
      76,            // lineNo
      39,            // colNo
      "tagID",       // aName
      "PulseStruct", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/uavrt_localization_utils/Pu"
      "lseStruct.m", // pName
      0              // checkKind
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
  //    position  -   n x 1 vector of positions (as PulseStructs)
  //    euler     -   n x 1 vector of eulerangles (as EulerAngleStructs)
  //    strength  -   n x 1 vector of pulse strength metrics (doubles)
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
  pulseInit.time = 0.0;
  pulseInit.strength = 0.0;
  pulseInit.tagID = 0.0;
  pulse.set_size(1, 1);
  pulse[0] = pulseInit;
  x[0] = ((pos.size(0) == euler.size(0)) || (pos.size(0) == b_time.size(0)) ||
          (pos.size(0) == strength.size(0)) ||
          (pos.size(0) == b_time.size(0)) || (pos.size(0) == tagID.size(0)));
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
    for (int itilerow{0}; itilerow < ntilerows; itilerow++) {
      pulse[itilerow] = pulseInit;
    }
    if (pos.size(0) > 2147483646) {
      coder::check_forloop_overflow_error();
    }
    ntilerows = pos.size(0);
    for (int itilerow{0}; itilerow < ntilerows; itilerow++) {
      if (itilerow + 1 > pulse.size(0)) {
        rtDynamicBoundsError(itilerow + 1, 1, pulse.size(0), b_emlrtBCI);
      }
      pulse[itilerow].position.size[0] = 1;
      if (itilerow + 1 > pulse.size(0)) {
        rtDynamicBoundsError(itilerow + 1, 1, pulse.size(0), b_emlrtBCI);
      }
      pulse[itilerow].position.size[1] = 1;
      if (itilerow + 1 > pulse.size(0)) {
        rtDynamicBoundsError(itilerow + 1, 1, pulse.size(0), b_emlrtBCI);
      }
      if (itilerow + 1 > pos.size(0)) {
        rtDynamicBoundsError(itilerow + 1, 1, pos.size(0), c_emlrtBCI);
      }
      pulse[itilerow].position.data[0] = pos[itilerow];
      if (itilerow + 1 > pulse.size(0)) {
        rtDynamicBoundsError(itilerow + 1, 1, pulse.size(0), d_emlrtBCI);
      }
      pulse[itilerow].euler.size[0] = 1;
      if (itilerow + 1 > pulse.size(0)) {
        rtDynamicBoundsError(itilerow + 1, 1, pulse.size(0), d_emlrtBCI);
      }
      pulse[itilerow].euler.size[1] = 1;
      if (itilerow + 1 > pulse.size(0)) {
        rtDynamicBoundsError(itilerow + 1, 1, pulse.size(0), d_emlrtBCI);
      }
      if (itilerow + 1 > euler.size(0)) {
        rtDynamicBoundsError(itilerow + 1, 1, euler.size(0), e_emlrtBCI);
      }
      pulse[itilerow].euler.data[0] = euler[itilerow];
      if (itilerow + 1 > pulse.size(0)) {
        rtDynamicBoundsError(itilerow + 1, 1, pulse.size(0), f_emlrtBCI);
      }
      if (itilerow + 1 > b_time.size(0)) {
        rtDynamicBoundsError(itilerow + 1, 1, b_time.size(0), g_emlrtBCI);
      }
      pulse[itilerow].time = b_time[itilerow];
      if (itilerow + 1 > pulse.size(0)) {
        rtDynamicBoundsError(itilerow + 1, 1, pulse.size(0), h_emlrtBCI);
      }
      if (itilerow + 1 > strength.size(0)) {
        rtDynamicBoundsError(itilerow + 1, 1, strength.size(0), i_emlrtBCI);
      }
      pulse[itilerow].strength = strength[itilerow];
      if (itilerow + 1 > pulse.size(0)) {
        rtDynamicBoundsError(itilerow + 1, 1, pulse.size(0), j_emlrtBCI);
      }
      if (itilerow + 1 > freqMHz.size(0)) {
        rtDynamicBoundsError(itilerow + 1, 1, freqMHz.size(0), k_emlrtBCI);
      }
      if (itilerow + 1 > pulse.size(0)) {
        rtDynamicBoundsError(itilerow + 1, 1, pulse.size(0), l_emlrtBCI);
      }
      if (itilerow + 1 > tagID.size(0)) {
        rtDynamicBoundsError(itilerow + 1, 1, tagID.size(0), m_emlrtBCI);
      }
      pulse[itilerow].tagID = tagID[itilerow];
    }
    //  pulse.position = pos;
    //  pulse.euler    = euler;
    //  pulse.time     = time;
    //  pulse.strength = strength;
    //  pulse.freqMHz  = freqMHz;
  }
}

//
// File trailer for PulseStruct.cpp
//
// [EOF]
//
