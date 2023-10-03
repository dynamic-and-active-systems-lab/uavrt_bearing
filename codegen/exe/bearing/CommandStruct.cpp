//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: CommandStruct.cpp
//
// MATLAB Coder version            : 23.2
// C/C++ source code generated on  : 03-Oct-2023 13:40:05
//

// Include Files
#include "CommandStruct.h"
#include "bearing_internal_types.h"
#include "bearing_rtwutil.h"
#include "bearing_types.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cstdio>

// Function Definitions
//
// COMMANDSTRUCT Generates a command structure
//    This function generates a standard command structure with the
//    following fields:
//
//    commandID    CommandID
//    position     Position (PositionStruct)
//
// Arguments    : const coder::array<double, 1U> &commandID
//                const coder::array<struct_T, 2U> &pos
//                coder::array<empty, 2U> &command
// Return Type  : void
//
void CommandStruct(const coder::array<double, 1U> &commandID,
                   const coder::array<struct_T, 2U> &pos,
                   coder::array<empty, 2U> &command)
{
  static rtBoundsCheckInfo b_emlrtBCI{
      -1,              // iFirst
      -1,              // iLast
      54,              // lineNo
      21,              // colNo
      "command",       // aName
      "CommandStruct", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/CommandStruct.m", // pName
      0                                                // checkKind
  };
  static rtBoundsCheckInfo c_emlrtBCI{
      -1,              // iFirst
      -1,              // iLast
      54,              // lineNo
      13,              // colNo
      "pos",           // aName
      "CommandStruct", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/CommandStruct.m", // pName
      0                                                // checkKind
  };
  static rtBoundsCheckInfo d_emlrtBCI{
      -1,              // iFirst
      -1,              // iLast
      56,              // lineNo
      21,              // colNo
      "command",       // aName
      "CommandStruct", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/CommandStruct.m", // pName
      0                                                // checkKind
  };
  static rtBoundsCheckInfo e_emlrtBCI{
      -1,              // iFirst
      -1,              // iLast
      56,              // lineNo
      48,              // colNo
      "commandID",     // aName
      "CommandStruct", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/CommandStruct.m", // pName
      0                                                // checkKind
  };
  int ntilerows;
  boolean_T x[2];
  boolean_T exitg1;
  boolean_T y;
  //    If input vectors are provided, they must be the same size size. In that
  //    case, the output is a vector of position structures.
  //
  // INPUTS:
  //    commandID  -   n x 1 vector of command IDs (double)
  //    pos        -   n x 1 vector of positions (PositionStruct)
  //
  // OUTPUTS:
  //    command    -   n x 1 vector of command structures
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
  // localTime     = 0;
  // commandInit.time      = localTime;
  command.set_size(1, 1);
  x[0] = (pos.size(0) == commandID.size(0));
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
    // command(nRows,nCols) = command; %Coder doesn't like this
    command.set_size(pos.size(0), 1);
    if (pos.size(0) > 2147483646) {
      coder::check_forloop_overflow_error();
    }
    ntilerows = pos.size(0);
    for (int itilerow{0}; itilerow < ntilerows; itilerow++) {
      if (itilerow + 1 > command.size(0)) {
        rtDynamicBoundsError(itilerow + 1, 1, command.size(0), b_emlrtBCI);
      }
      if (itilerow + 1 > command.size(0)) {
        rtDynamicBoundsError(itilerow + 1, 1, command.size(0), b_emlrtBCI);
      }
      if (itilerow + 1 > command.size(0)) {
        rtDynamicBoundsError(itilerow + 1, 1, command.size(0), b_emlrtBCI);
      }
      if (itilerow + 1 > pos.size(0)) {
        rtDynamicBoundsError(itilerow + 1, 1, pos.size(0), c_emlrtBCI);
      }
      // command(i,j).time     = time(i,j);
      if (itilerow + 1 > command.size(0)) {
        rtDynamicBoundsError(itilerow + 1, 1, command.size(0), d_emlrtBCI);
      }
      if (itilerow + 1 > commandID.size(0)) {
        rtDynamicBoundsError(itilerow + 1, 1, commandID.size(0), e_emlrtBCI);
      }
    }
  }
}

//
// File trailer for CommandStruct.cpp
//
// [EOF]
//
