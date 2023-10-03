//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: PositionStruct.cpp
//
// MATLAB Coder version            : 5.6
// C/C++ source code generated on  : 03-Oct-2023 08:03:05
//

// Include Files
#include "PositionStruct.h"
#include "bearing_internal_types.h"
#include "bearing_rtwutil.h"
#include "bearing_types.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cstdio>

// Function Definitions
//
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
// --------------------------------------------------------------------------
//
// Arguments    : const coder::array<double, 1U> &lat
//                const coder::array<double, 1U> &lon
//                const coder::array<double, 1U> &altAbs
//                const coder::array<double, 1U> &altRel
//                coder::array<struct_T, 2U> &pos
// Return Type  : void
//
void PositionStruct(const coder::array<double, 1U> &lat,
                    const coder::array<double, 1U> &lon,
                    const coder::array<double, 1U> &altAbs,
                    const coder::array<double, 1U> &altRel,
                    coder::array<struct_T, 2U> &pos)
{
  static rtBoundsCheckInfo b_emlrtBCI{
      -1,               // iFirst
      -1,               // iLast
      62,               // lineNo
      49,               // colNo
      "lat",            // aName
      "PositionStruct", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/PositionStruct.m", // pName
      0                                                 // checkKind
  };
  static rtBoundsCheckInfo c_emlrtBCI{
      -1,               // iFirst
      -1,               // iLast
      62,               // lineNo
      17,               // colNo
      "pos",            // aName
      "PositionStruct", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/PositionStruct.m", // pName
      0                                                 // checkKind
  };
  static rtBoundsCheckInfo d_emlrtBCI{
      -1,               // iFirst
      -1,               // iLast
      63,               // lineNo
      49,               // colNo
      "lon",            // aName
      "PositionStruct", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/PositionStruct.m", // pName
      0                                                 // checkKind
  };
  static rtBoundsCheckInfo e_emlrtBCI{
      -1,               // iFirst
      -1,               // iLast
      63,               // lineNo
      17,               // colNo
      "pos",            // aName
      "PositionStruct", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/PositionStruct.m", // pName
      0                                                 // checkKind
  };
  static rtBoundsCheckInfo f_emlrtBCI{
      -1,               // iFirst
      -1,               // iLast
      64,               // lineNo
      52,               // colNo
      "altAbs",         // aName
      "PositionStruct", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/PositionStruct.m", // pName
      0                                                 // checkKind
  };
  static rtBoundsCheckInfo g_emlrtBCI{
      -1,               // iFirst
      -1,               // iLast
      64,               // lineNo
      17,               // colNo
      "pos",            // aName
      "PositionStruct", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/PositionStruct.m", // pName
      0                                                 // checkKind
  };
  static rtBoundsCheckInfo h_emlrtBCI{
      -1,               // iFirst
      -1,               // iLast
      65,               // lineNo
      52,               // colNo
      "altRel",         // aName
      "PositionStruct", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/PositionStruct.m", // pName
      0                                                 // checkKind
  };
  static rtBoundsCheckInfo i_emlrtBCI{
      -1,               // iFirst
      -1,               // iLast
      65,               // lineNo
      17,               // colNo
      "pos",            // aName
      "PositionStruct", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/PositionStruct.m", // pName
      0                                                 // checkKind
  };
  int ntilerows;
  boolean_T x[2];
  boolean_T exitg1;
  boolean_T y;
  pos.set_size(1, 1);
  pos[0].latitude_deg = 0.0;
  pos[0].longitude_deg = 0.0;
  pos[0].absolute_altitude_m = 0.0;
  pos[0].relative_altitude_m = 0.0;
  x[0] = ((lat.size(0) == lon.size(0)) || (lat.size(0) == altAbs.size(0)) ||
          (lat.size(0) == altRel.size(0)));
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
    // pos(nRows,nCols) = pos; %Coder doesn't like this
    pos.set_size(lat.size(0), 1);
    ntilerows = lat.size(0);
    for (int itilerow{0}; itilerow < ntilerows; itilerow++) {
      pos[itilerow].latitude_deg = 0.0;
      pos[itilerow].longitude_deg = 0.0;
      pos[itilerow].absolute_altitude_m = 0.0;
      pos[itilerow].relative_altitude_m = 0.0;
    }
    if (lat.size(0) > 2147483646) {
      coder::check_forloop_overflow_error();
    }
    ntilerows = lat.size(0);
    for (int itilerow{0}; itilerow < ntilerows; itilerow++) {
      if (itilerow + 1 > lat.size(0)) {
        rtDynamicBoundsError(itilerow + 1, 1, lat.size(0), b_emlrtBCI);
      }
      if (itilerow + 1 > pos.size(0)) {
        rtDynamicBoundsError(itilerow + 1, 1, pos.size(0), c_emlrtBCI);
      }
      pos[itilerow].latitude_deg = lat[itilerow];
      if (itilerow + 1 > lon.size(0)) {
        rtDynamicBoundsError(itilerow + 1, 1, lon.size(0), d_emlrtBCI);
      }
      if (itilerow + 1 > pos.size(0)) {
        rtDynamicBoundsError(itilerow + 1, 1, pos.size(0), e_emlrtBCI);
      }
      pos[itilerow].longitude_deg = lon[itilerow];
      if (itilerow + 1 > altAbs.size(0)) {
        rtDynamicBoundsError(itilerow + 1, 1, altAbs.size(0), f_emlrtBCI);
      }
      if (itilerow + 1 > pos.size(0)) {
        rtDynamicBoundsError(itilerow + 1, 1, pos.size(0), g_emlrtBCI);
      }
      pos[itilerow].absolute_altitude_m = altAbs[itilerow];
      if (itilerow + 1 > altRel.size(0)) {
        rtDynamicBoundsError(itilerow + 1, 1, altRel.size(0), h_emlrtBCI);
      }
      if (itilerow + 1 > pos.size(0)) {
        rtDynamicBoundsError(itilerow + 1, 1, pos.size(0), i_emlrtBCI);
      }
      pos[itilerow].relative_altitude_m = altRel[itilerow];
    }
    //  pos.latitude_deg         = lat;
    //  pos.longitude_deg        = lon;
    //  pos.absolute_altitude_m  = altAbs;
    //  pos.relative_altitude_m  = altRel;
  }
}

//
// File trailer for PositionStruct.cpp
//
// [EOF]
//
