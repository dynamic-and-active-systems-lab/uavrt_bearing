//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: bearing.cpp
//
// MATLAB Coder version            : 5.6
// C/C++ source code generated on  : 17-Aug-2023 13:24:38
//

// Include Files
#include "bearing.h"
#include "bearing_data.h"
#include "bearing_initialize.h"
#include "bearing_internal_types.h"
#include "bearing_rtwutil.h"
#include "bearing_types.h"
#include "doapca.h"
#include "eml_int_forloop_overflow_check.h"
#include "fileManager.h"
#include "horzcatStructList.h"
#include "indexShapeCheck.h"
#include "isfile.h"
#include "median.h"
#include "minOrMax.h"
#include "readbearingcsv.h"
#include "readpulsecsv.h"
#include "rt_nonfinite.h"
#include "sort.h"
#include "sprintf.h"
#include "table.h"
#include "varNamesDim.h"
#include "coder_array.h"
#include "coder_bounded_array.h"
#include "coder_platform.h"
#include "cstdio"
#include <algorithm>
#include <cmath>
#include <cstddef>
#include <cstdio>

// Function Definitions
//
// BEARING generates bearing estimates from pulse files
//    This function generates bearing estimates from pulses within a pulse
//    file provided by the file path. If a bearing.csv file doesn't exists in
//    the same directory as the provided file path, it will generate the
//    bearing file. If a bearing file already exists, this function will read
//    the file and determine if a bearing estimate has already been made for
//    the provided filePath. If so, the function will replace that bearing in
//    the file. If not, the new bearing will be appended to the file.
//
// INPUTS
//    filePath - a char array of the path the pulse file
// OUTPUTS
//    bearing - double of the bearing estimate in degrees from North
//
//    Note that this program also generates/modifies bearings.csv
//
//
// --------------------------------------------------------------------------
//  Author: Michael Shafer
//  Date: 2023-06-12
// --------------------------------------------------------------------------
// --------------------------------------------------------------------------
//
// Arguments    : const coder::array<char, 2U> &filePath
// Return Type  : double
//
double bearing(const coder::array<char, 2U> &filePath)
{
  static rtBoundsCheckInfo b_emlrtBCI{
      -1,               // iFirst
      -1,               // iLast
      36,               // lineNo
      33,               // colNo
      "pulseStructVec", // aName
      "bearing",        // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/bearing.m", // pName
      0                                          // checkKind
  };
  static rtBoundsCheckInfo c_emlrtBCI{
      -1,        // iFirst
      -1,        // iLast
      61,        // lineNo
      29,        // colNo
      "sepInds", // aName
      "bearing", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/bearing.m", // pName
      0                                          // checkKind
  };
  static rtBoundsCheckInfo d_emlrtBCI{
      -1,                       // iFirst
      -1,                       // iLast
      136,                      // lineNo
      85,                       // colNo
      "tableIn.parentFileName", // aName
      "bearing",                // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/bearing.m", // pName
      0                                          // checkKind
  };
  static rtBoundsCheckInfo e_emlrtBCI{
      -1,                     // iFirst
      -1,                     // iLast
      136,                    // lineNo
      30,                     // colNo
      "alreadyInBearingList", // aName
      "bearing",              // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/bearing.m", // pName
      0                                          // checkKind
  };
  static rtBoundsCheckInfo f_emlrtBCI{
      -1,               // iFirst
      -1,               // iLast
      171,              // lineNo
      50,               // colNo
      "tableOut.tagID", // aName
      "bearing",        // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/bearing.m", // pName
      0                                          // checkKind
  };
  static rtBoundsCheckInfo g_emlrtBCI{
      -1,                        // iFirst
      -1,                        // iLast
      172,                       // lineNo
      59,                        // colNo
      "tableOut.parentFileName", // aName
      "bearing",                 // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/bearing.m", // pName
      0                                          // checkKind
  };
  static rtBoundsCheckInfo h_emlrtBCI{
      -1,                 // iFirst
      -1,                 // iLast
      173,                // lineNo
      52,                 // colNo
      "tableOut.bearing", // aName
      "bearing",          // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/bearing.m", // pName
      0                                          // checkKind
  };
  static rtBoundsCheckInfo i_emlrtBCI{
      -1,             // iFirst
      -1,             // iLast
      174,            // lineNo
      48,             // colNo
      "tableOut.tau", // aName
      "bearing",      // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/bearing.m", // pName
      0                                          // checkKind
  };
  static rtBoundsCheckInfo j_emlrtBCI{
      -1,                      // iFirst
      -1,                      // iLast
      175,                     // lineNo
      57,                      // colNo
      "tableOut.latitude_deg", // aName
      "bearing",               // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/bearing.m", // pName
      0                                          // checkKind
  };
  static rtBoundsCheckInfo k_emlrtBCI{
      -1,                       // iFirst
      -1,                       // iLast
      176,                      // lineNo
      58,                       // colNo
      "tableOut.longitude_deg", // aName
      "bearing",                // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/bearing.m", // pName
      0                                          // checkKind
  };
  static rtBoundsCheckInfo l_emlrtBCI{
      -1,                   // iFirst
      -1,                   // iLast
      177,                  // lineNo
      54,                   // colNo
      "tableOut.alt_AGL_m", // aName
      "bearing",            // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/bearing.m", // pName
      0                                          // checkKind
  };
  static rtBoundsCheckInfo m_emlrtBCI{
      -1,                   // iFirst
      -1,                   // iLast
      178,                  // lineNo
      54,                   // colNo
      "tableOut.alt_ASL_m", // aName
      "bearing",            // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/bearing.m", // pName
      0                                          // checkKind
  };
  static rtBoundsCheckInfo n_emlrtBCI{
      -1,                      // iFirst
      -1,                      // iLast
      179,                     // lineNo
      57,                      // colNo
      "tableOut.time_start_s", // aName
      "bearing",               // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/bearing.m", // pName
      0                                          // checkKind
  };
  static rtBoundsCheckInfo o_emlrtBCI{
      -1,                    // iFirst
      -1,                    // iLast
      180,                   // lineNo
      55,                    // colNo
      "tableOut.time_end_s", // aName
      "bearing",             // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/bearing.m", // pName
      0                                          // checkKind
  };
  static rtBoundsCheckInfo p_emlrtBCI{
      -1,         // iFirst
      -1,         // iLast
      63,         // lineNo
      26,         // colNo
      "filePath", // aName
      "bearing",  // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/bearing.m", // pName
      0                                          // checkKind
  };
  static rtBoundsCheckInfo q_emlrtBCI{
      -1,         // iFirst
      -1,         // iLast
      63,         // lineNo
      28,         // colNo
      "filePath", // aName
      "bearing",  // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/bearing.m", // pName
      0                                          // checkKind
  };
  static rtBoundsCheckInfo r_emlrtBCI{
      -1,         // iFirst
      -1,         // iLast
      61,         // lineNo
      21,         // colNo
      "filePath", // aName
      "bearing",  // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/bearing.m", // pName
      0                                          // checkKind
  };
  static rtBoundsCheckInfo s_emlrtBCI{
      -1,         // iFirst
      -1,         // iLast
      61,         // lineNo
      36,         // colNo
      "filePath", // aName
      "bearing",  // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/bearing.m", // pName
      0                                          // checkKind
  };
  static const char b_msg2[85]{
      'U', 'A', 'V', '-', 'R', 'T', ':', ' ', 'U', 'n', 'a', 'b', 'l', 'e', ' ',
      't', 'o', ' ', 'r', 'e', 'n', 'a', 'm', 'e', ' ', 't', 'e', 'm', 'p', ' ',
      'b', 'e', 'a', 'r', 'i', 'n', 'g', ' ', 'f', 'i', 'l', 'e', ' ', 'a', 's',
      ' ', 'p', 'r', 'i', 'm', 'a', 'r', 'y', ' ', 'b', 'e', 'a', 'r', 'i', 'n',
      'g', ' ', 'f', 'i', 'l', 'e', '.', ' ', 'S', 'y', 's', 't', 'e', 'm', ' ',
      'r', 'e', 'p', 'o', 'r', 't', 'e', 'd', ':', ' '};
  static const char b_msg3[80]{
      'U', 'A', 'V', '-', 'R', 'T', ':', ' ', 'E', 'r', 'r', 'o', 'r', ' ',
      'o', 'p', 'e', 'n', 'i', 'n', 'g', ' ', 'o', 'r', ' ', 'c', 'l', 'o',
      's', 'i', 'n', 'g', ' ', 't', 'e', 'm', 'p', 'o', 'r', 'a', 'r', 'y',
      ' ', 'b', 'e', 'a', 'r', 'i', 'n', 'g', ' ', 'f', 'i', 'l', 'e', ' ',
      'd', 'u', 'r', 'i', 'n', 'g', ' ', 'w', 'r', 'i', 't', 'e', ' ', 'o',
      'p', 'e', 'r', 'a', 't', 'i', 'o', 'n', '.', ' '};
  static const char b_msg4[71]{
      'U', 'A', 'V', '-', 'R', 'T', ':', ' ', 'E', 'r', 'r', 'o', 'r', ' ', 'c',
      'r', 'e', 'a', 't', 'i', 'n', 'g', ' ', 'o', 'r', ' ', 'c', 'l', 'o', 's',
      'i', 'n', 'g', ' ', 'b', 'e', 'a', 'r', 'i', 'n', 'g', ' ', 'f', 'i', 'l',
      'e', ' ', 'd', 'u', 'r', 'i', 'n', 'g', ' ', 'w', 'r', 'i', 't', 'e', ' ',
      'o', 'p', 'e', 'r', 'a', 't', 'i', 'o', 'n', '.', ' '};
  static const char b_msg0[68]{
      'U', 'A', 'V', '-', 'R', 'T', ':', ' ', 'U', 'n', 'a', 'b', 'l', 'e',
      ' ', 't', 'o', ' ', 'd', 'e', 'l', 'e', 't', 'e', ' ', 'e', 'x', 'i',
      's', 't', 'i', 'n', 'g', ' ', 't', 'e', 'm', 'p', ' ', 'b', 'e', 'a',
      'r', 'i', 'n', 'g', ' ', 'f', 'i', 'l', 'e', '.', ' ', 'S', 'y', 's',
      't', 'e', 'm', ' ', 'r', 'e', 'p', 'o', 'r', 't', 'e', 'd'};
  static const char b_msg1[65]{
      'U', 'A', 'V', '-', 'R', 'T', ':', ' ', 'U', 'n', 'a', 'b', 'l',
      'e', ' ', 't', 'o', ' ', 'd', 'e', 'l', 'e', 't', 'e', ' ', 'o',
      'r', 'i', 'g', 'i', 'n', 'a', 'l', ' ', 'b', 'e', 'a', 'r', 'i',
      'n', 'g', ' ', 'f', 'i', 'l', 'e', '.', ' ', 'S', 'y', 's', 't',
      'e', 'm', ' ', 'r', 'e', 'p', 'o', 'r', 't', 'e', 'd', ':', ' '};
  static const char cv1[17]{'b', 'e', 'a', 'r', 'i', 'n', 'g', 's', '_',
                            't', 'e', 'm', 'p', '.', 'c', 's', 'v'};
  static const char cv[12]{'b', 'e', 'a', 'r', 'i', 'n',
                           'g', 's', '.', 'c', 's', 'v'};
  std::FILE *f;
  coder::b_table tableTemp;
  coder::table tableIn;
  coder::table tableOut;
  coder::array<empty, 2U> a__1;
  coder::array<e_struct_T, 2U> pulseStructVec;
  coder::array<e_struct_T, 1U> b_pulseStructVec;
  coder::array<struct_T, 2U> posVec;
  coder::array<struct_T, 1U> b_posVec;
  coder::array<double, 2U> tagIDs;
  coder::array<double, 2U> varargin_1;
  coder::array<double, 1U> x;
  coder::array<int, 2U> match_out;
  coder::array<int, 2U> matches;
  coder::array<char, 2U> b_status2;
  coder::array<char, 2U> bearingFilePath;
  coder::array<char, 2U> newTempFilePath_1;
  coder::array<char, 2U> newbearingFilePath;
  coder::array<char, 2U> status1;
  coder::array<char, 2U> tempBearingFilePath;
  coder::array<boolean_T, 1U> alreadyInBearingList;
  coder::array<boolean_T, 1U> b_alreadyInBearingList;
  double M;
  double alt_AGL_m;
  double alt_ASL_m;
  double b_bearing;
  double d;
  double longitude_deg;
  double mtmp;
  double time_end_s;
  double time_start_s;
  int iv[2];
  int iv1[2];
  int ftmp;
  int i;
  int i1;
  int k;
  int n;
  unsigned int u;
  char msg2[85];
  char msg3[80];
  char msg4[71];
  char msg0[68];
  char msg1[65];
  char pattern;
  signed char status0;
  boolean_T bearingFileAlreadyExists;
  boolean_T tempbearingFileAlreadyExists;
  if (!isInitialized_bearing) {
    bearing_initialize();
  }
  // When using C code generation
  // coder.cinclude('stdio.h');%Needed for remove and move file commands
  // Needed for remove and move file commands
  readpulsecsv(filePath, pulseStructVec, a__1);
  n = pulseStructVec.size(0);
  if (pulseStructVec.size(0) == 0) {
    i = 0;
  } else {
    i = pulseStructVec.size(0);
  }
  tagIDs.set_size(1, i);
  if (pulseStructVec.size(0) > 2147483646) {
    coder::check_forloop_overflow_error();
  }
  for (int b_i{0}; b_i < n; b_i++) {
    tagIDs[b_i] = pulseStructVec[b_i].tagID;
  }
  // Define so coder knows types.
  if (tagIDs.size(1) == 0) {
    M = rtNaN;
  } else {
    x.set_size(tagIDs.size(1));
    n = tagIDs.size(1);
    for (i = 0; i < n; i++) {
      x[i] = tagIDs[i];
    }
    coder::internal::sort(x);
    M = x[0];
    n = 1;
    mtmp = x[0];
    ftmp = 1;
    i = x.size(0);
    for (k = 0; k <= i - 2; k++) {
      d = x[k + 1];
      if (d == mtmp) {
        ftmp++;
      } else {
        if (ftmp > n) {
          M = mtmp;
          n = ftmp;
        }
        mtmp = d;
        ftmp = 1;
      }
    }
    if (ftmp > n) {
      M = mtmp;
    }
  }
  d = std::round(M);
  if (d < 4.294967296E+9) {
    if (d >= 0.0) {
      u = static_cast<unsigned int>(d);
    } else {
      u = 0U;
    }
  } else if (d >= 4.294967296E+9) {
    u = MAX_uint32_T;
  } else {
    u = 0U;
  }
  // In case some other tags' pulses got into the dataset somehow.
  iv[0] = 1;
  iv[1] = tagIDs.size(1);
  iv1[0] = (*(int(*)[2])pulseStructVec.size())[0];
  iv1[1] = (*(int(*)[2])pulseStructVec.size())[1];
  coder::internal::indexShapeCheck(iv1, iv);
  ftmp = tagIDs.size(1) - 1;
  n = 0;
  for (int b_i{0}; b_i <= ftmp; b_i++) {
    if (!(tagIDs[b_i] != u)) {
      n++;
    }
  }
  b_pulseStructVec.set_size(n);
  n = 0;
  for (int b_i{0}; b_i <= ftmp; b_i++) {
    if (!(tagIDs[b_i] != u)) {
      if (b_i > pulseStructVec.size(0) - 1) {
        rtDynamicBoundsError(b_i, 0, pulseStructVec.size(0) - 1, b_emlrtBCI);
      }
      b_pulseStructVec[n] = pulseStructVec[b_i];
      n++;
    }
  }
  b_bearing = doapca(b_pulseStructVec, M);
  //  if any(tagIDs ~= tagIDs(1))
  //      fprintf('UAV-RT: All tags in pulse list file path must have the same
  //      tag ID integer') bearing = NaN; return
  //  else
  //      tagID = tagIDs(1);
  //  end
  coder::internal::horzcatStructList(b_pulseStructVec, posVec);
  n = b_pulseStructVec.size(0);
  if (b_pulseStructVec.size(0) == 0) {
    i = 0;
  } else {
    i = b_pulseStructVec.size(0);
  }
  tagIDs.set_size(1, i);
  if (b_pulseStructVec.size(0) > 2147483646) {
    coder::check_forloop_overflow_error();
  }
  for (int b_i{0}; b_i < n; b_i++) {
    tagIDs[b_i] = b_pulseStructVec[b_i].time;
  }
  ftmp = posVec.size(0) * posVec.size(1);
  b_posVec = posVec.reshape(ftmp);
  n = b_posVec.size(0);
  if (b_posVec.size(0) == 0) {
    i = 0;
  } else {
    i = b_posVec.size(0);
  }
  varargin_1.set_size(1, i);
  if (b_posVec.size(0) > 2147483646) {
    coder::check_forloop_overflow_error();
  }
  for (int b_i{0}; b_i < n; b_i++) {
    varargin_1[b_i] = b_posVec[b_i].latitude_deg;
  }
  mtmp = coder::median(varargin_1);
  b_posVec = posVec.reshape(ftmp);
  n = b_posVec.size(0);
  if (b_posVec.size(0) == 0) {
    i = 0;
  } else {
    i = b_posVec.size(0);
  }
  varargin_1.set_size(1, i);
  if (b_posVec.size(0) > 2147483646) {
    coder::check_forloop_overflow_error();
  }
  for (int b_i{0}; b_i < n; b_i++) {
    varargin_1[b_i] = b_posVec[b_i].longitude_deg;
  }
  longitude_deg = coder::median(varargin_1);
  b_posVec = posVec.reshape(ftmp);
  n = b_posVec.size(0);
  if (b_posVec.size(0) == 0) {
    i = 0;
  } else {
    i = b_posVec.size(0);
  }
  varargin_1.set_size(1, i);
  if (b_posVec.size(0) > 2147483646) {
    coder::check_forloop_overflow_error();
  }
  for (int b_i{0}; b_i < n; b_i++) {
    varargin_1[b_i] = b_posVec[b_i].relative_altitude_m;
  }
  alt_AGL_m = coder::median(varargin_1);
  b_posVec = posVec.reshape(ftmp);
  n = b_posVec.size(0);
  if (b_posVec.size(0) == 0) {
    i = 0;
  } else {
    i = b_posVec.size(0);
  }
  varargin_1.set_size(1, i);
  if (b_posVec.size(0) > 2147483646) {
    coder::check_forloop_overflow_error();
  }
  for (int b_i{0}; b_i < n; b_i++) {
    varargin_1[b_i] = b_posVec[b_i].absolute_altitude_m;
  }
  alt_ASL_m = coder::median(varargin_1);
  time_start_s = coder::internal::minimum(tagIDs);
  time_end_s = coder::internal::maximum(tagIDs);
  bearingFileAlreadyExists = coderIsPC();
  if (bearingFileAlreadyExists) {
    pattern = '\\';
  } else {
    pattern = '/';
  }
  if (filePath.size(1) == 0) {
    tagIDs.set_size(1, 0);
  } else {
    n = filePath.size(1);
    matches.set_size(1, filePath.size(1));
    ftmp = 0;
    if (filePath.size(1) > 2147483646) {
      coder::check_forloop_overflow_error();
    }
    for (int b_i{0}; b_i < n; b_i++) {
      if (filePath[b_i] == pattern) {
        matches[ftmp] = b_i + 1;
        ftmp++;
      }
    }
    match_out.set_size(1, ftmp);
    if (ftmp > 2147483646) {
      coder::check_forloop_overflow_error();
    }
    for (int b_i{0}; b_i < ftmp; b_i++) {
      match_out[b_i] = matches[b_i];
    }
    tagIDs.set_size(1, match_out.size(1));
    n = match_out.size(1);
    for (i = 0; i < n; i++) {
      tagIDs[i] = match_out[i];
    }
  }
  bearingFileAlreadyExists = (tagIDs.size(1) < 1);
  if (bearingFileAlreadyExists) {
    rtDynamicBoundsError(tagIDs.size(1), 1, tagIDs.size(1), c_emlrtBCI);
  }
  d = tagIDs[tagIDs.size(1) - 1];
  if (static_cast<unsigned int>(d) + 1U >
      static_cast<unsigned int>(filePath.size(1))) {
    i = 0;
    i1 = 0;
  } else {
    if ((static_cast<int>(static_cast<unsigned int>(d) + 1U) < 1) ||
        (static_cast<int>(static_cast<unsigned int>(d) + 1U) >
         filePath.size(1))) {
      rtDynamicBoundsError(static_cast<int>(static_cast<unsigned int>(d) + 1U),
                           1, filePath.size(1), r_emlrtBCI);
    }
    i = static_cast<int>(static_cast<unsigned int>(d));
    if (filePath.size(1) < 1) {
      rtDynamicBoundsError(filePath.size(1), 1, filePath.size(1), s_emlrtBCI);
    }
    i1 = filePath.size(1);
  }
  n = static_cast<int>(d) - 1;
  if (n < 1) {
    n = 0;
  } else {
    if (filePath.size(1) < 1) {
      rtDynamicBoundsError(1, 1, filePath.size(1), p_emlrtBCI);
    }
    if (n > filePath.size(1)) {
      rtDynamicBoundsError(n, 1, filePath.size(1), q_emlrtBCI);
    }
  }
  bearingFileAlreadyExists = coderIsPC();
  bearingFilePath.set_size(1, n + 13);
  for (k = 0; k < n; k++) {
    bearingFilePath[k] = filePath[k];
  }
  if (bearingFileAlreadyExists) {
    bearingFilePath[n] = '\\';
  } else {
    bearingFilePath[n] = '/';
  }
  for (k = 0; k < 12; k++) {
    bearingFilePath[(k + n) + 1] = cv[k];
  }
  bearingFileAlreadyExists = coderIsPC();
  tempBearingFilePath.set_size(1, n + 18);
  for (k = 0; k < n; k++) {
    tempBearingFilePath[k] = filePath[k];
  }
  if (bearingFileAlreadyExists) {
    tempBearingFilePath[n] = '\\';
  } else {
    tempBearingFilePath[n] = '/';
  }
  for (k = 0; k < 17; k++) {
    tempBearingFilePath[(k + n) + 1] = cv1[k];
  }
  bearingFileAlreadyExists = coder::isfile(bearingFilePath);
  tempbearingFileAlreadyExists = coder::isfile(tempBearingFilePath);
  // Remove old temp bearing file if it wasn't deleted properly previously
  std::copy(&b_msg0[0], &b_msg0[68], &msg0[0]);
  // See note below near the rename command for why this sprintf command is
  // needed. The intermittent error described there would occasionally occur
  // here as well.
  coder::b_sprintf(tempBearingFilePath, newTempFilePath_1);
  if (tempbearingFileAlreadyExists) {
    // Assigned so coder knowns expected data type.
    // Causes intermittent error.
    // status0 = coder.ceval('remove', coder.ref(tempBearingFilePath));
    status0 = remove(&newTempFilePath_1[0]);
    if (status0 != 0) {
      perror(&msg0[0]);
    }
  }
  if (bearingFileAlreadyExists) {
    signed char status2;
    // Read bearing file and see if a bearing for this parent file has already
    // been written If so, append new estimate and remove the old ones - then
    // rewrite the bearing file contents If not, simply append new bearing to
    // the end of the entries.
    readbearingcsv(bearingFilePath, tableIn);
    // Logical vector - true for all entries with the same parent file as
    // filepath
    alreadyInBearingList.set_size(tableIn.data.f1.size(0));
    k = tableIn.data.f1.size(0);
    for (int b_i{0}; b_i < k; b_i++) {
      if (b_i > tableIn.data.f2.size(0) - 1) {
        rtDynamicBoundsError(b_i, 0, tableIn.data.f2.size(0) - 1, d_emlrtBCI);
      }
      if (b_i + 1 > alreadyInBearingList.size(0)) {
        rtDynamicBoundsError(b_i + 1, 1, alreadyInBearingList.size(0),
                             e_emlrtBCI);
      }
      alreadyInBearingList[b_i] = false;
      ftmp = tableIn.data.f2[b_i].f1.size(1);
      n = i1 - i;
      bearingFileAlreadyExists = (n == 0);
      if (bearingFileAlreadyExists && (tableIn.data.f2[b_i].f1.size(1) == 0)) {
        if (b_i + 1 > alreadyInBearingList.size(0)) {
          rtDynamicBoundsError(b_i + 1, 1, alreadyInBearingList.size(0),
                               e_emlrtBCI);
        }
        alreadyInBearingList[b_i] = true;
      } else if (n == tableIn.data.f2[b_i].f1.size(1)) {
        if (ftmp > 2147483646) {
          coder::check_forloop_overflow_error();
        }
        n = 0;
        int exitg1;
        do {
          exitg1 = 0;
          if (n <= ftmp - 1) {
            if (filePath[i + n] != tableIn.data.f2[b_i].f1[n]) {
              exitg1 = 1;
            } else {
              n++;
            }
          } else {
            if (b_i + 1 > alreadyInBearingList.size(0)) {
              rtDynamicBoundsError(b_i + 1, 1, alreadyInBearingList.size(0),
                                   e_emlrtBCI);
            }
            alreadyInBearingList[b_i] = true;
            exitg1 = 1;
          }
        } while (exitg1 == 0);
      }
    }
    // Build temp table with new entry and append to old table
    // So coder knows the type
    n = i1 - i;
    tableTemp.data.f2[0].f1.set_size(1, n);
    for (i1 = 0; i1 < n; i1++) {
      tableTemp.data.f2[0].f1[i1] = filePath[i + i1];
    }
    tableTemp.arrayProps.Description.size[0] = 1;
    tableTemp.arrayProps.Description.size[1] = 0;
    coder::matlab::internal::coder::tabular::b_private::varNamesDim::createLike(
        tableTemp.varDim);
    tableTemp.data.f1 = u;
    tableTemp.data.f3 = b_bearing;
    tableTemp.data.f4 = M;
    tableTemp.data.f5 = mtmp;
    tableTemp.data.f6 = longitude_deg;
    tableTemp.data.f7 = alt_AGL_m;
    tableTemp.data.f8 = alt_ASL_m;
    tableTemp.data.f9 = time_start_s;
    tableTemp.data.f10 = time_end_s;
    tableIn.vertcat(tableTemp, tableOut);
    // Delete any entries that were from this file
    // Append false so we don't delete the entry we just added
    b_alreadyInBearingList.set_size(alreadyInBearingList.size(0) + 1);
    n = alreadyInBearingList.size(0);
    for (i = 0; i < n; i++) {
      b_alreadyInBearingList[i] = !alreadyInBearingList[i];
    }
    b_alreadyInBearingList[alreadyInBearingList.size(0)] = true;
    tableOut.parenReference(b_alreadyInBearingList, tableIn);
    //      if any([alreadyInBearingList; false])
    //          tableOut(alreadyInBearingList,:) = [];
    //      end
    // Write out the table to the temp bearing file.
    // We use a temp file so that if there is an error or system shutdown
    // during the write, we don't lose the original file.
    status0 = coder::internal::cfopen(tempBearingFilePath, "wb");
    i = tableIn.data.f1.size(0);
    for (int b_i{0}; b_i < i; b_i++) {
      if (b_i + 1 > tableIn.data.f1.size(0)) {
        rtDynamicBoundsError(b_i + 1, 1, tableIn.data.f1.size(0), f_emlrtBCI);
      }
      if (b_i > tableIn.data.f2.size(0) - 1) {
        rtDynamicBoundsError(b_i, 0, tableIn.data.f2.size(0) - 1, g_emlrtBCI);
      }
      if (b_i + 1 > tableIn.data.f3.size(0)) {
        rtDynamicBoundsError(b_i + 1, 1, tableIn.data.f3.size(0), h_emlrtBCI);
      }
      if (b_i + 1 > tableIn.data.f4.size(0)) {
        rtDynamicBoundsError(b_i + 1, 1, tableIn.data.f4.size(0), i_emlrtBCI);
      }
      if (b_i + 1 > tableIn.data.f5.size(0)) {
        rtDynamicBoundsError(b_i + 1, 1, tableIn.data.f5.size(0), j_emlrtBCI);
      }
      if (b_i + 1 > tableIn.data.f6.size(0)) {
        rtDynamicBoundsError(b_i + 1, 1, tableIn.data.f6.size(0), k_emlrtBCI);
      }
      if (b_i + 1 > tableIn.data.f7.size(0)) {
        rtDynamicBoundsError(b_i + 1, 1, tableIn.data.f7.size(0), l_emlrtBCI);
      }
      if (b_i + 1 > tableIn.data.f8.size(0)) {
        rtDynamicBoundsError(b_i + 1, 1, tableIn.data.f8.size(0), m_emlrtBCI);
      }
      if (b_i + 1 > tableIn.data.f9.size(0)) {
        rtDynamicBoundsError(b_i + 1, 1, tableIn.data.f9.size(0), n_emlrtBCI);
      }
      if (b_i + 1 > tableIn.data.f10.size(0)) {
        rtDynamicBoundsError(b_i + 1, 1, tableIn.data.f10.size(0), o_emlrtBCI);
      }
      if (status0 == 0) {
        b_rtErrorWithMessageID(b_emlrtRTEI.fName, b_emlrtRTEI.lineNo);
      }
      newTempFilePath_1.set_size(1, tableIn.data.f2[b_i].f1.size(1) + 1);
      n = tableIn.data.f2[b_i].f1.size(1);
      for (i1 = 0; i1 < n; i1++) {
        newTempFilePath_1[i1] = tableIn.data.f2[b_i].f1[i1];
      }
      newTempFilePath_1[tableIn.data.f2[b_i].f1.size(1)] = '\x00';
      f = coder::internal::getfilestar(static_cast<double>(status0),
                                       bearingFileAlreadyExists);
      if (f == nullptr) {
        rtErrorWithMessageID(emlrtRTEI.fName, emlrtRTEI.lineNo);
      } else {
        std::fprintf(
            f, "%u,%s,%f,%f,%f,%f,%f,%f,%f,%f\n", tableIn.data.f1[b_i],
            &newTempFilePath_1[0], tableIn.data.f3[b_i], tableIn.data.f4[b_i],
            tableIn.data.f5[b_i], tableIn.data.f6[b_i], tableIn.data.f7[b_i],
            tableIn.data.f8[b_i], tableIn.data.f9[b_i], tableIn.data.f10[b_i]);
        if (bearingFileAlreadyExists) {
          std::fflush(f);
        }
      }
    }
    n = coder::internal::cfclose(static_cast<double>(status0));
    std::copy(&b_msg3[0], &b_msg3[80], &msg3[0]);
    if ((status0 == -1) || (n == -1)) {
      perror(&msg3[0]);
    }
    // Delete the original bearing file, then rename the temp as the primary
    // file
    // retVal = coder.ceval('getcwd', coder.ref(untokenizedDir), 200);
    // Assigned so coder knowns expected data type.
    // status1 = coder.ceval('remove',
    // coder.ref(originalBearingPathStringinQuotes));
    std::copy(&b_msg1[0], &b_msg1[65], &msg1[0]);
    // Print out bearing file name to new variable. This is a patch to
    // fix problems in generated code where the rename operation was
    // producing filenames like bearing.csvmpl.csv, which was garble of
    // the bearing.csv and the rotation_example.csv filenames. I couldn't
    // figure out why this was happening (only occured on Linux - not
    // Mac), but assumed it was related to the intermittent rename errors
    // I was getting on the Mac with the rename operation.
    coder::b_sprintf(bearingFilePath, newbearingFilePath);
    // fprintf('attempting to delete original bearing file...\n')
    status0 = remove(&newbearingFilePath[0]);
    if (status0 != 0) {
      perror(&msg1[0]);
    }
    // Debugging code for intermittent rename errors
    // fprintf('%s\n', tempBearingFilePath)
    // fprintf('%s\n', bearingFilePath)
    //  fprintf('PAUSING.....\n')
    //  pause(10);
    //  if isfile(bearingFilePath)
    //      fprintf('Bearing file path is valid\n')
    //  else
    //      fprintf('Bearing file path is NOT valid\n')
    //  end
    //
    //  if isfile(tempBearingFilePath)
    //      fprintf('Temp bearing file path is valid\n')
    //  else
    //      fprintf('Temp bearing file path is NOT valid\n')
    //  end
    std::copy(&b_msg2[0], &b_msg2[85], &msg2[0]);
    // For reasons I can't determine, using tempBearingFilePath in the
    // rename commands below would occasionally fail at run time with the
    // error 'No such file or directory'. I excluded issues with
    // temporary write access by looping the rename command if it failed.
    // I also showed that a static path with the same data held in
    // tempBearingFilePath did not reproduce the error. I was unable to
    // determine the cause after looking through bearing.cpp after code
    // gen. Running the sprintf command extracts the text of
    // tempBearingFilePath and the error doesn't reoccur. I don't know
    // why this happen.
    // newTempFilePath =
    // '/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/CODE_PLAYGROUND/uavrt_bearing/bearings_temp.csv';
    coder::b_sprintf(tempBearingFilePath, newTempFilePath_1);
    // fprintf('%s\n', tempBearingFilePath) %To show these contain the same
    // string fprintf('%s\n', newTempFilePath) Line below will intermittently
    // cause a runtime error. status2 = coder.ceval('rename',
    // coder.ref(tempBearingFilePath) , coder.ref(bearingFilePath));
    status2 = rename(&newTempFilePath_1[0], &newbearingFilePath[0]);
    if (status2 != 0) {
      perror(&msg2[0]);
    }
    n = std::snprintf(nullptr, 0, "%d", status0);
    if (n + 1 < 0) {
      rtNonNegativeError(static_cast<double>(n + 1), emlrtDCI);
    }
    status1.set_size(1, n + 1);
    std::snprintf(&status1[0], (size_t)(n + 1), "%d", status0);
    if (n < 1) {
      n = 0;
    }
    status1.set_size(status1.size(0), n);
    n = std::snprintf(nullptr, 0, "%d", status2);
    if (n + 1 < 0) {
      rtNonNegativeError(static_cast<double>(n + 1), emlrtDCI);
    }
    b_status2.set_size(1, n + 1);
    std::snprintf(&b_status2[0], (size_t)(n + 1), "%d", status2);
    if (n < 1) {
      n = 0;
    }
    b_status2.set_size(b_status2.size(0), n);
    //  if status1~=0 | status2~=0
    //      if status1~=0
    //          fprintf('UAV-RT: Unable to delete original bearing file. System
    //          reported: %s \n ', cmdout1);
    //      end
    //      if status2~=0
    //          fprintf('UAV-RT: Unable to rename temp bearing file as primary
    //          bearing file. System reported: %s \n', cmdout2);
    //      end
    //  end
  } else {
    // Create the bearing file and print the data
    status0 = coder::internal::cfopen(bearingFilePath, "ab");
    if (status0 == 0) {
      b_rtErrorWithMessageID(b_emlrtRTEI.fName, b_emlrtRTEI.lineNo);
    }
    n = i1 - i;
    newTempFilePath_1.set_size(1, n + 1);
    for (i1 = 0; i1 < n; i1++) {
      newTempFilePath_1[i1] = filePath[i + i1];
    }
    newTempFilePath_1[n] = '\x00';
    f = coder::internal::getfilestar(static_cast<double>(status0),
                                     bearingFileAlreadyExists);
    if (f == nullptr) {
      rtErrorWithMessageID(emlrtRTEI.fName, emlrtRTEI.lineNo);
    } else {
      std::fprintf(f, "%u,%s,%f,%f,%f,%f,%f,%f,%f,%f\n", u,
                   &newTempFilePath_1[0], b_bearing, M, mtmp, longitude_deg,
                   alt_AGL_m, alt_ASL_m, time_start_s, time_end_s);
      if (bearingFileAlreadyExists) {
        std::fflush(f);
      }
    }
    n = coder::internal::cfclose(static_cast<double>(status0));
    std::copy(&b_msg4[0], &b_msg4[71], &msg4[0]);
    if ((status0 == -1) || (n == -1)) {
      perror(&msg4[0]);
    }
  }
  return b_bearing;
}

//
// File trailer for bearing.cpp
//
// [EOF]
//
