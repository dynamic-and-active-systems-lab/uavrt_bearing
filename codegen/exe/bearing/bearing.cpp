//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: bearing.cpp
//
// MATLAB Coder version            : 23.2
// C/C++ source code generated on  : 07-Nov-2023 14:21:19
//

// Include Files
#include "bearing.h"
#include "applyToMultipleDims.h"
#include "bearing_data.h"
#include "bearing_initialize.h"
#include "bearing_internal_types.h"
#include "bearing_rtwutil.h"
#include "bearing_types.h"
#include "doapca.h"
#include "eml_int_forloop_overflow_check.h"
#include "fileManager.h"
#include "fileparts.h"
#include "horzcatStructList.h"
#include "indexShapeCheck.h"
#include "isfile.h"
#include "median.h"
#include "minOrMax.h"
#include "readbearingcsv.h"
#include "readpulsecsv.h"
#include "rt_nonfinite.h"
#include "sprintf.h"
#include "table.h"
#include "varNamesDim.h"
#include "coder_array.h"
#include "coder_bounded_array.h"
#include "coder_fileops.h"
#include "coder_platform.h"
#include "cstdio"
#include <algorithm>
#include <cmath>
#include <cstddef>
#include <cstdio>
#include <sstream>
#include <stdexcept>
#include <string>

// Function Declarations
static void rtErrorWithMessageID(const char *aFcnName, int aLineNum);

static void rtErrorWithMessageID(const char *r, const char *aFcnName,
                                 int aLineNum);

// Function Definitions
//
// Arguments    : const char *aFcnName
//                int aLineNum
// Return Type  : void
//
static void rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::stringstream outStream;
  outStream
      << "Unable to access current directory or directory no longer exists.";
  outStream << "\n";
  ((((outStream << "Error in ") << aFcnName) << " (line ") << aLineNum) << ")";
  throw std::runtime_error(outStream.str());
}

//
// Arguments    : const char *r
//                const char *aFcnName
//                int aLineNum
// Return Type  : void
//
static void rtErrorWithMessageID(const char *r, const char *aFcnName,
                                 int aLineNum)
{
  std::stringstream outStream;
  ((outStream << "To generate code remove \'") << r)
      << "\' function or set \'DynamicMemoryAllocation\' configuration option "
         "to either \'AllVariableSizeArrays\' or \'Threshold\'.";
  outStream << "\n";
  ((((outStream << "Error in ") << aFcnName) << " (line ") << aLineNum) << ")";
  throw std::runtime_error(outStream.str());
}

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
      -1,                       // iFirst
      -1,                       // iLast
      74,                       // lineNo
      85,                       // colNo
      "tableIn.parentFileName", // aName
      "writeToBearingFile",     // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/writeToBearingFile.m", // pName
      0                                                     // checkKind
  };
  static rtBoundsCheckInfo d_emlrtBCI{
      -1,                     // iFirst
      -1,                     // iLast
      74,                     // lineNo
      30,                     // colNo
      "alreadyInBearingList", // aName
      "writeToBearingFile",   // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/writeToBearingFile.m", // pName
      0                                                     // checkKind
  };
  static rtBoundsCheckInfo e_emlrtBCI{
      -1,                   // iFirst
      -1,                   // iLast
      109,                  // lineNo
      50,                   // colNo
      "tableOut.tagID",     // aName
      "writeToBearingFile", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/writeToBearingFile.m", // pName
      0                                                     // checkKind
  };
  static rtBoundsCheckInfo f_emlrtBCI{
      -1,                        // iFirst
      -1,                        // iLast
      110,                       // lineNo
      59,                        // colNo
      "tableOut.parentFileName", // aName
      "writeToBearingFile",      // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/writeToBearingFile.m", // pName
      0                                                     // checkKind
  };
  static rtBoundsCheckInfo g_emlrtBCI{
      -1,                   // iFirst
      -1,                   // iLast
      111,                  // lineNo
      52,                   // colNo
      "tableOut.bearing",   // aName
      "writeToBearingFile", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/writeToBearingFile.m", // pName
      0                                                     // checkKind
  };
  static rtBoundsCheckInfo h_emlrtBCI{
      -1,                   // iFirst
      -1,                   // iLast
      112,                  // lineNo
      48,                   // colNo
      "tableOut.tau",       // aName
      "writeToBearingFile", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/writeToBearingFile.m", // pName
      0                                                     // checkKind
  };
  static rtBoundsCheckInfo i_emlrtBCI{
      -1,                      // iFirst
      -1,                      // iLast
      113,                     // lineNo
      57,                      // colNo
      "tableOut.latitude_deg", // aName
      "writeToBearingFile",    // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/writeToBearingFile.m", // pName
      0                                                     // checkKind
  };
  static rtBoundsCheckInfo j_emlrtBCI{
      -1,                       // iFirst
      -1,                       // iLast
      114,                      // lineNo
      58,                       // colNo
      "tableOut.longitude_deg", // aName
      "writeToBearingFile",     // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/writeToBearingFile.m", // pName
      0                                                     // checkKind
  };
  static rtBoundsCheckInfo k_emlrtBCI{
      -1,                   // iFirst
      -1,                   // iLast
      115,                  // lineNo
      54,                   // colNo
      "tableOut.alt_AGL_m", // aName
      "writeToBearingFile", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/writeToBearingFile.m", // pName
      0                                                     // checkKind
  };
  static rtBoundsCheckInfo l_emlrtBCI{
      -1,                   // iFirst
      -1,                   // iLast
      116,                  // lineNo
      54,                   // colNo
      "tableOut.alt_ASL_m", // aName
      "writeToBearingFile", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/writeToBearingFile.m", // pName
      0                                                     // checkKind
  };
  static rtBoundsCheckInfo m_emlrtBCI{
      -1,                      // iFirst
      -1,                      // iLast
      117,                     // lineNo
      57,                      // colNo
      "tableOut.time_start_s", // aName
      "writeToBearingFile",    // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/writeToBearingFile.m", // pName
      0                                                     // checkKind
  };
  static rtBoundsCheckInfo n_emlrtBCI{
      -1,                    // iFirst
      -1,                    // iLast
      118,                   // lineNo
      55,                    // colNo
      "tableOut.time_end_s", // aName
      "writeToBearingFile",  // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/writeToBearingFile.m", // pName
      0                                                     // checkKind
  };
  static rtBoundsCheckInfo o_emlrtBCI{
      -1,         // iFirst
      -1,         // iLast
      64,         // lineNo
      30,         // colNo
      "filePath", // aName
      "bearing",  // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/bearing.m", // pName
      0                                          // checkKind
  };
  static rtBoundsCheckInfo p_emlrtBCI{
      -1,         // iFirst
      -1,         // iLast
      64,         // lineNo
      32,         // colNo
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
      25,         // colNo
      "filePath", // aName
      "bearing",  // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/bearing.m", // pName
      0                                          // checkKind
  };
  static rtBoundsCheckInfo r_emlrtBCI{
      -1,         // iFirst
      -1,         // iLast
      63,         // lineNo
      40,         // colNo
      "filePath", // aName
      "bearing",  // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/bearing.m", // pName
      0                                          // checkKind
  };
  static rtRunTimeErrorInfo v_emlrtRTEI{
      23,                          // lineNo
      "CoderFileOperationsAPI/pwd" // fName
  };
  static rtRunTimeErrorInfo w_emlrtRTEI{
      30,                          // lineNo
      "CoderFileOperationsAPI/pwd" // fName
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
  coder::b_table tableIn;
  coder::b_table tableOut;
  coder::table tableTemp;
  coder::array<empty, 2U> a__1;
  coder::array<e_struct_T, 2U> pulseStructVec;
  coder::array<e_struct_T, 1U> b_pulseStructVec;
  coder::array<e_struct_T, 1U> c_pulseStructVec;
  coder::array<struct_T, 2U> posVec;
  coder::array<struct_T, 1U> b_posVec;
  coder::array<double, 2U> tagIDs;
  coder::array<double, 2U> varargin_1;
  coder::array<int, 2U> match_out;
  coder::array<int, 2U> matches;
  coder::array<char, 2U> b_status2;
  coder::array<char, 2U> bearingFilePath;
  coder::array<char, 2U> fileDirectory;
  coder::array<char, 2U> newbearingFilePath;
  coder::array<char, 2U> status1;
  coder::array<char, 2U> tempBearingFilePath;
  coder::array<char, 2U> wdTemp;
  coder::array<boolean_T, 1U> alreadyInBearingList;
  coder::array<boolean_T, 1U> b_alreadyInBearingList;
  double M;
  double alt_AGL_m;
  double alt_ASL_m;
  double bearing_deg;
  double latitude_deg;
  double longitude_deg;
  double tau;
  double time_end_s;
  double time_start_s;
  int iv[2];
  int iv1[2];
  int b_i;
  int match_idx;
  int text_len;
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
  text_len = pulseStructVec.size(0);
  b_pulseStructVec = pulseStructVec.reshape(text_len);
  coder::internal::horzcatStructList(b_pulseStructVec, tagIDs);
  // Define so coder knows types.
  M = coder::internal::applyToMultipleDims(tagIDs);
  M = std::round(M);
  if (M < 4.294967296E+9) {
    if (M >= 0.0) {
      u = static_cast<unsigned int>(M);
    } else {
      u = 0U;
    }
  } else if (M >= 4.294967296E+9) {
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
  match_idx = tagIDs.size(1) - 1;
  text_len = 0;
  for (int i{0}; i <= match_idx; i++) {
    if (!(tagIDs[i] != u)) {
      text_len++;
    }
  }
  c_pulseStructVec.set_size(text_len);
  text_len = 0;
  for (int i{0}; i <= match_idx; i++) {
    if (!(tagIDs[i] != u)) {
      if (i > pulseStructVec.size(0) - 1) {
        rtDynamicBoundsError(i, 0, pulseStructVec.size(0) - 1, b_emlrtBCI);
      }
      c_pulseStructVec[text_len] = pulseStructVec[i];
      text_len++;
    }
  }
  bearing_deg = doapca(c_pulseStructVec, tau);
  //  if any(tagIDs ~= tagIDs(1))
  //      fprintf('UAV-RT: All tags in pulse list file path must have the same
  //      tag ID integer') bearing = NaN; return
  //  else
  //      tagID = tagIDs(1);
  //  end
  coder::internal::horzcatStructList(c_pulseStructVec, posVec);
  coder::internal::e_horzcatStructList(c_pulseStructVec, tagIDs);
  text_len = posVec.size(0) * posVec.size(1);
  b_posVec = posVec.reshape(text_len);
  coder::internal::horzcatStructList(b_posVec, varargin_1);
  latitude_deg = coder::median(varargin_1);
  b_posVec = posVec.reshape(text_len);
  coder::internal::b_horzcatStructList(b_posVec, varargin_1);
  longitude_deg = coder::median(varargin_1);
  b_posVec = posVec.reshape(text_len);
  coder::internal::c_horzcatStructList(b_posVec, varargin_1);
  alt_AGL_m = coder::median(varargin_1);
  b_posVec = posVec.reshape(text_len);
  coder::internal::d_horzcatStructList(b_posVec, varargin_1);
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
    text_len = filePath.size(1);
    matches.set_size(1, filePath.size(1));
    match_idx = 0;
    if (filePath.size(1) > 2147483646) {
      coder::check_forloop_overflow_error();
    }
    for (int i{0}; i < text_len; i++) {
      if (filePath[i] == pattern) {
        matches[match_idx] = i + 1;
        match_idx++;
      }
    }
    match_out.set_size(1, match_idx);
    if (match_idx > 2147483646) {
      coder::check_forloop_overflow_error();
    }
    for (int i{0}; i < match_idx; i++) {
      match_out[i] = matches[i];
    }
    tagIDs.set_size(1, match_out.size(1));
    text_len = match_out.size(1);
    for (b_i = 0; b_i < text_len; b_i++) {
      tagIDs[b_i] = match_out[b_i];
    }
  }
  if (tagIDs.size(1) != 0) {
    M = tagIDs[tagIDs.size(1) - 1];
    if (static_cast<unsigned int>(M) + 1U >
        static_cast<unsigned int>(filePath.size(1))) {
      b_i = 0;
      match_idx = 0;
    } else {
      if ((static_cast<int>(static_cast<unsigned int>(M) + 1U) < 1) ||
          (static_cast<int>(static_cast<unsigned int>(M) + 1U) >
           filePath.size(1))) {
        rtDynamicBoundsError(
            static_cast<int>(static_cast<unsigned int>(M) + 1U), 1,
            filePath.size(1), q_emlrtBCI);
      }
      b_i = static_cast<int>(static_cast<unsigned int>(M));
      if (filePath.size(1) < 1) {
        rtDynamicBoundsError(filePath.size(1), 1, filePath.size(1), r_emlrtBCI);
      }
      match_idx = filePath.size(1);
    }
    text_len = match_idx - b_i;
    tableTemp.data.f2[0].f1.set_size(1, text_len);
    for (match_idx = 0; match_idx < text_len; match_idx++) {
      tableTemp.data.f2[0].f1[match_idx] = filePath[b_i + match_idx];
    }
    text_len = static_cast<int>(M) - 1;
    if (text_len < 1) {
      text_len = 0;
    } else {
      if (filePath.size(1) < 1) {
        rtDynamicBoundsError(1, 1, filePath.size(1), o_emlrtBCI);
      }
      if (text_len > filePath.size(1)) {
        rtDynamicBoundsError(text_len, 1, filePath.size(1), p_emlrtBCI);
      }
    }
    fileDirectory.set_size(1, text_len);
    for (b_i = 0; b_i < text_len; b_i++) {
      fileDirectory[b_i] = filePath[b_i];
    }
  } else {
    tableTemp.data.f2[0].f1.set_size(1, filePath.size(1));
    text_len = filePath.size(1);
    for (b_i = 0; b_i < text_len; b_i++) {
      tableTemp.data.f2[0].f1[b_i] = filePath[b_i];
    }
    text_len = coderGetLenghtOfCwd();
    if (text_len == -2) {
      rtErrorWithMessageID(v_emlrtRTEI.fName, v_emlrtRTEI.lineNo);
    }
    if (text_len + 1 < 0) {
      rtNonNegativeError(static_cast<double>(text_len + 1), emlrtDCI);
    }
    wdTemp.set_size(1, text_len + 1);
    text_len = coderGetCurrentDirectory(&wdTemp[0], text_len + 1);
    if (text_len == -1) {
      rtErrorWithMessageID("pwd", w_emlrtRTEI.fName, w_emlrtRTEI.lineNo);
    }
    if (text_len < 1) {
      text_len = 0;
    }
    fileDirectory.set_size(1, text_len);
    for (b_i = 0; b_i < text_len; b_i++) {
      fileDirectory[b_i] = wdTemp[b_i];
    }
  }
  bearingFileAlreadyExists = coderIsPC();
  bearingFilePath.set_size(1, fileDirectory.size(1) + 13);
  text_len = fileDirectory.size(1);
  for (b_i = 0; b_i < text_len; b_i++) {
    bearingFilePath[b_i] = fileDirectory[b_i];
  }
  if (bearingFileAlreadyExists) {
    bearingFilePath[fileDirectory.size(1)] = '\\';
  } else {
    bearingFilePath[fileDirectory.size(1)] = '/';
  }
  for (b_i = 0; b_i < 12; b_i++) {
    bearingFilePath[(b_i + fileDirectory.size(1)) + 1] = cv[b_i];
  }
  coder::fileparts(bearingFilePath, fileDirectory, wdTemp, newbearingFilePath);
  bearingFileAlreadyExists = coderIsPC();
  tempBearingFilePath.set_size(1, fileDirectory.size(1) + 18);
  text_len = fileDirectory.size(1);
  for (b_i = 0; b_i < text_len; b_i++) {
    tempBearingFilePath[b_i] = fileDirectory[b_i];
  }
  if (bearingFileAlreadyExists) {
    tempBearingFilePath[fileDirectory.size(1)] = '\\';
  } else {
    tempBearingFilePath[fileDirectory.size(1)] = '/';
  }
  for (b_i = 0; b_i < 17; b_i++) {
    tempBearingFilePath[(b_i + fileDirectory.size(1)) + 1] = cv1[b_i];
  }
  bearingFileAlreadyExists = coder::isfile(bearingFilePath);
  tempbearingFileAlreadyExists = coder::isfile(tempBearingFilePath);
  // Remove old temp bearing file if it wasn't deleted properly previously
  std::copy(&b_msg0[0], &b_msg0[68], &msg0[0]);
  // See note below near the rename command for why this sprintf command is
  // needed. The intermittent error described there would occasionally occur
  // here as well.
  coder::b_sprintf(tempBearingFilePath, wdTemp);
  if (tempbearingFileAlreadyExists) {
    // Assigned so coder knowns expected data type.
    // Causes intermittent error.
    // status0 = coder.ceval('remove', coder.ref(tempBearingFilePath));
    status0 = remove(&wdTemp[0]);
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
    b_i = tableIn.data.f1.size(0);
    for (int i{0}; i < b_i; i++) {
      if (i > tableIn.data.f2.size(0) - 1) {
        rtDynamicBoundsError(i, 0, tableIn.data.f2.size(0) - 1, c_emlrtBCI);
      }
      if (i + 1 > alreadyInBearingList.size(0)) {
        rtDynamicBoundsError(i + 1, 1, alreadyInBearingList.size(0),
                             d_emlrtBCI);
      }
      alreadyInBearingList[i] = false;
      text_len = tableIn.data.f2[i].f1.size(1);
      bearingFileAlreadyExists = (tableTemp.data.f2[0].f1.size(1) == 0);
      if (bearingFileAlreadyExists && (tableIn.data.f2[i].f1.size(1) == 0)) {
        if (i + 1 > alreadyInBearingList.size(0)) {
          rtDynamicBoundsError(i + 1, 1, alreadyInBearingList.size(0),
                               d_emlrtBCI);
        }
        alreadyInBearingList[i] = true;
      } else if (tableTemp.data.f2[0].f1.size(1) ==
                 tableIn.data.f2[i].f1.size(1)) {
        if (text_len > 2147483646) {
          coder::check_forloop_overflow_error();
        }
        match_idx = 0;
        int exitg1;
        do {
          exitg1 = 0;
          if (match_idx <= text_len - 1) {
            if (tableTemp.data.f2[0].f1[match_idx] !=
                tableIn.data.f2[i].f1[match_idx]) {
              exitg1 = 1;
            } else {
              match_idx++;
            }
          } else {
            if (i + 1 > alreadyInBearingList.size(0)) {
              rtDynamicBoundsError(i + 1, 1, alreadyInBearingList.size(0),
                                   d_emlrtBCI);
            }
            alreadyInBearingList[i] = true;
            exitg1 = 1;
          }
        } while (exitg1 == 0);
      }
    }
    // Build temp table with new entry and append to old table
    // So coder knows the type
    tableTemp.arrayProps.Description.size[0] = 1;
    tableTemp.arrayProps.Description.size[1] = 0;
    coder::matlab::internal::coder::tabular::b_private::varNamesDim::createLike(
        tableTemp.varDim);
    tableTemp.data.f1 = u;
    tableTemp.data.f3 = bearing_deg;
    tableTemp.data.f4 = tau;
    tableTemp.data.f5 = latitude_deg;
    tableTemp.data.f6 = longitude_deg;
    tableTemp.data.f7 = alt_AGL_m;
    tableTemp.data.f8 = alt_ASL_m;
    tableTemp.data.f9 = time_start_s;
    tableTemp.data.f10 = time_end_s;
    tableIn.vertcat(tableTemp, tableOut);
    // Delete any entries that were from this file
    // Append false so we don't delete the entry we just added
    b_alreadyInBearingList.set_size(alreadyInBearingList.size(0) + 1);
    text_len = alreadyInBearingList.size(0);
    for (b_i = 0; b_i < text_len; b_i++) {
      b_alreadyInBearingList[b_i] = !alreadyInBearingList[b_i];
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
    b_i = tableIn.data.f1.size(0);
    for (int i{0}; i < b_i; i++) {
      if (i + 1 > tableIn.data.f1.size(0)) {
        rtDynamicBoundsError(i + 1, 1, tableIn.data.f1.size(0), e_emlrtBCI);
      }
      if (i > tableIn.data.f2.size(0) - 1) {
        rtDynamicBoundsError(i, 0, tableIn.data.f2.size(0) - 1, f_emlrtBCI);
      }
      if (i + 1 > tableIn.data.f3.size(0)) {
        rtDynamicBoundsError(i + 1, 1, tableIn.data.f3.size(0), g_emlrtBCI);
      }
      if (i + 1 > tableIn.data.f4.size(0)) {
        rtDynamicBoundsError(i + 1, 1, tableIn.data.f4.size(0), h_emlrtBCI);
      }
      if (i + 1 > tableIn.data.f5.size(0)) {
        rtDynamicBoundsError(i + 1, 1, tableIn.data.f5.size(0), i_emlrtBCI);
      }
      if (i + 1 > tableIn.data.f6.size(0)) {
        rtDynamicBoundsError(i + 1, 1, tableIn.data.f6.size(0), j_emlrtBCI);
      }
      if (i + 1 > tableIn.data.f7.size(0)) {
        rtDynamicBoundsError(i + 1, 1, tableIn.data.f7.size(0), k_emlrtBCI);
      }
      if (i + 1 > tableIn.data.f8.size(0)) {
        rtDynamicBoundsError(i + 1, 1, tableIn.data.f8.size(0), l_emlrtBCI);
      }
      if (i + 1 > tableIn.data.f9.size(0)) {
        rtDynamicBoundsError(i + 1, 1, tableIn.data.f9.size(0), m_emlrtBCI);
      }
      if (i + 1 > tableIn.data.f10.size(0)) {
        rtDynamicBoundsError(i + 1, 1, tableIn.data.f10.size(0), n_emlrtBCI);
      }
      if (status0 == 0) {
        c_rtErrorWithMessageID(b_emlrtRTEI.fName, b_emlrtRTEI.lineNo);
      }
      wdTemp.set_size(1, tableIn.data.f2[i].f1.size(1) + 1);
      text_len = tableIn.data.f2[i].f1.size(1);
      for (match_idx = 0; match_idx < text_len; match_idx++) {
        wdTemp[match_idx] = tableIn.data.f2[i].f1[match_idx];
      }
      wdTemp[tableIn.data.f2[i].f1.size(1)] = '\x00';
      f = coder::internal::getfilestar(static_cast<double>(status0),
                                       bearingFileAlreadyExists);
      if (f == nullptr) {
        b_rtErrorWithMessageID(emlrtRTEI.fName, emlrtRTEI.lineNo);
      } else {
        std::fprintf(f, "%u,%s,%f,%f,%f,%f,%f,%f,%f,%f\n", tableIn.data.f1[i],
                     &wdTemp[0], tableIn.data.f3[i], tableIn.data.f4[i],
                     tableIn.data.f5[i], tableIn.data.f6[i], tableIn.data.f7[i],
                     tableIn.data.f8[i], tableIn.data.f9[i],
                     tableIn.data.f10[i]);
        if (bearingFileAlreadyExists) {
          std::fflush(f);
        }
      }
    }
    text_len = coder::internal::cfclose(static_cast<double>(status0));
    std::copy(&b_msg3[0], &b_msg3[80], &msg3[0]);
    if ((status0 == -1) || (text_len == -1)) {
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
    coder::b_sprintf(tempBearingFilePath, wdTemp);
    // fprintf('%s\n', tempBearingFilePath) %To show these contain the same
    // string fprintf('%s\n', newTempFilePath) Line below will intermittently
    // cause a runtime error. status2 = coder.ceval('rename',
    // coder.ref(tempBearingFilePath) , coder.ref(bearingFilePath));
    status2 = rename(&wdTemp[0], &newbearingFilePath[0]);
    if (status2 != 0) {
      perror(&msg2[0]);
    }
    text_len = std::snprintf(nullptr, 0, "%d", status0);
    if (text_len + 1 < 0) {
      rtNonNegativeError(static_cast<double>(text_len + 1), emlrtDCI);
    }
    status1.set_size(1, text_len + 1);
    std::snprintf(&status1[0], (size_t)(text_len + 1), "%d", status0);
    if (text_len < 1) {
      text_len = 0;
    }
    status1.set_size(status1.size(0), text_len);
    text_len = std::snprintf(nullptr, 0, "%d", status2);
    if (text_len + 1 < 0) {
      rtNonNegativeError(static_cast<double>(text_len + 1), emlrtDCI);
    }
    b_status2.set_size(1, text_len + 1);
    std::snprintf(&b_status2[0], (size_t)(text_len + 1), "%d", status2);
    if (text_len < 1) {
      text_len = 0;
    }
    b_status2.set_size(b_status2.size(0), text_len);
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
      c_rtErrorWithMessageID(b_emlrtRTEI.fName, b_emlrtRTEI.lineNo);
    }
    wdTemp.set_size(1, tableTemp.data.f2[0].f1.size(1) + 1);
    text_len = tableTemp.data.f2[0].f1.size(1);
    for (b_i = 0; b_i < text_len; b_i++) {
      wdTemp[b_i] = tableTemp.data.f2[0].f1[b_i];
    }
    wdTemp[tableTemp.data.f2[0].f1.size(1)] = '\x00';
    f = coder::internal::getfilestar(static_cast<double>(status0),
                                     bearingFileAlreadyExists);
    if (f == nullptr) {
      b_rtErrorWithMessageID(emlrtRTEI.fName, emlrtRTEI.lineNo);
    } else {
      std::fprintf(f, "%u,%s,%f,%f,%f,%f,%f,%f,%f,%f\n", u, &wdTemp[0],
                   bearing_deg, tau, latitude_deg, longitude_deg, alt_AGL_m,
                   alt_ASL_m, time_start_s, time_end_s);
      if (bearingFileAlreadyExists) {
        std::fflush(f);
      }
    }
    text_len = coder::internal::cfclose(static_cast<double>(status0));
    std::copy(&b_msg4[0], &b_msg4[71], &msg4[0]);
    if ((status0 == -1) || (text_len == -1)) {
      perror(&msg4[0]);
    }
  }
  return bearing_deg;
}

//
// File trailer for bearing.cpp
//
// [EOF]
//
