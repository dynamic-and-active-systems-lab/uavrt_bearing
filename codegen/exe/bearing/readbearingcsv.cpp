//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: readbearingcsv.cpp
//
// MATLAB Coder version            : 5.6
// C/C++ source code generated on  : 17-Aug-2023 13:24:38
//

// Include Files
#include "readbearingcsv.h"
#include "anonymous_function.h"
#include "bearing_data.h"
#include "bearing_internal_types.h"
#include "bearing_rtwutil.h"
#include "bearing_types.h"
#include "eml_int_forloop_overflow_check.h"
#include "fgetl.h"
#include "fileManager.h"
#include "fseek.h"
#include "ftell.h"
#include "onCleanup.h"
#include "rt_nonfinite.h"
#include "str2double.h"
#include "table.h"
#include "coder_array.h"
#include <cmath>
#include <cstdio>

// Function Definitions
//
// READBEARINGCSV Reads in a bearing csv file and outputs the file as a
// MATLAB table.
//    This function reads a bearing csv file and converts the file to a
//    MATLAB table wit the following headings:
//
//    1 - TagID
//    2 - Filename of parent pulse file
//    3 - Bearing angle in degrees
//    4 - Tau value
//    5 - lat in deg
//    6 - lon in deg
//    7 - alt AGL in m
//    8 - alt ASL in m
//    9 - start time of bearing measurements in s
//    10 - end time of bearing measurements in s
//
// INPUTS:
//    filePath - char array of the path to the file
//
// OUPUTS:
//    tableOut - Matlab table with the columns specified above.
//
// --------------------------------------------------------------------------
//  Author: Michael Shafer
//  Date: 2023-06-12
// --------------------------------------------------------------------------
// --------------------------------------------------------------------------
//
// Arguments    : const coder::array<char, 2U> &filePath
//                coder::table &tableOut
// Return Type  : void
//
void readbearingcsv(const coder::array<char, 2U> &filePath,
                    coder::table &tableOut)
{
  static rtBoundsCheckInfo ab_emlrtBCI{
      -1,               // iFirst
      -1,               // iLast
      72,               // lineNo
      37,               // colNo
      "lineStr",        // aName
      "readbearingcsv", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/uavrt_localization_utils/re"
      "adbearingcsv.m", // pName
      0                 // checkKind
  };
  static rtBoundsCheckInfo b_emlrtBCI{
      -1,               // iFirst
      -1,               // iLast
      87,               // lineNo
      22,               // colNo
      "parentFileName", // aName
      "readbearingcsv", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/uavrt_localization_utils/re"
      "adbearingcsv.m", // pName
      0                 // checkKind
  };
  static rtBoundsCheckInfo bb_emlrtBCI{
      -1,               // iFirst
      -1,               // iLast
      72,               // lineNo
      9,                // colNo
      "parentFileName", // aName
      "readbearingcsv", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/uavrt_localization_utils/re"
      "adbearingcsv.m", // pName
      0                 // checkKind
  };
  static rtBoundsCheckInfo c_emlrtBCI{
      -1,               // iFirst
      -1,               // iLast
      41,               // lineNo
      24,               // colNo
      "parentFileName", // aName
      "readbearingcsv", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/uavrt_localization_utils/re"
      "adbearingcsv.m", // pName
      0                 // checkKind
  };
  static rtBoundsCheckInfo cb_emlrtBCI{
      -1,               // iFirst
      -1,               // iLast
      73,               // lineNo
      53,               // colNo
      "lineStr",        // aName
      "readbearingcsv", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/uavrt_localization_utils/re"
      "adbearingcsv.m", // pName
      0                 // checkKind
  };
  static rtBoundsCheckInfo d_emlrtBCI{
      -1,               // iFirst
      -1,               // iLast
      55,               // lineNo
      29,               // colNo
      "lineLocs",       // aName
      "readbearingcsv", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/uavrt_localization_utils/re"
      "adbearingcsv.m", // pName
      0                 // checkKind
  };
  static rtBoundsCheckInfo db_emlrtBCI{
      -1,               // iFirst
      -1,               // iLast
      73,               // lineNo
      17,               // colNo
      "bearing",        // aName
      "readbearingcsv", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/uavrt_localization_utils/re"
      "adbearingcsv.m", // pName
      0                 // checkKind
  };
  static rtBoundsCheckInfo e_emlrtBCI{
      -1,               // iFirst
      -1,               // iLast
      60,               // lineNo
      45,               // colNo
      "commaInds",      // aName
      "readbearingcsv", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/uavrt_localization_utils/re"
      "adbearingcsv.m", // pName
      0                 // checkKind
  };
  static rtBoundsCheckInfo eb_emlrtBCI{
      -1,               // iFirst
      -1,               // iLast
      74,               // lineNo
      53,               // colNo
      "lineStr",        // aName
      "readbearingcsv", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/uavrt_localization_utils/re"
      "adbearingcsv.m", // pName
      0                 // checkKind
  };
  static rtBoundsCheckInfo f_emlrtBCI{
      -1,               // iFirst
      -1,               // iLast
      61,               // lineNo
      41,               // colNo
      "commaInds",      // aName
      "readbearingcsv", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/uavrt_localization_utils/re"
      "adbearingcsv.m", // pName
      0                 // checkKind
  };
  static rtBoundsCheckInfo fb_emlrtBCI{
      -1,               // iFirst
      -1,               // iLast
      74,               // lineNo
      13,               // colNo
      "tau",            // aName
      "readbearingcsv", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/uavrt_localization_utils/re"
      "adbearingcsv.m", // pName
      0                 // checkKind
  };
  static rtBoundsCheckInfo g_emlrtBCI{
      -1,               // iFirst
      -1,               // iLast
      61,               // lineNo
      58,               // colNo
      "commaInds",      // aName
      "readbearingcsv", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/uavrt_localization_utils/re"
      "adbearingcsv.m", // pName
      0                 // checkKind
  };
  static rtBoundsCheckInfo gb_emlrtBCI{
      -1,               // iFirst
      -1,               // iLast
      75,               // lineNo
      53,               // colNo
      "lineStr",        // aName
      "readbearingcsv", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/uavrt_localization_utils/re"
      "adbearingcsv.m", // pName
      0                 // checkKind
  };
  static rtBoundsCheckInfo h_emlrtBCI{
      -1,               // iFirst
      -1,               // iLast
      62,               // lineNo
      41,               // colNo
      "commaInds",      // aName
      "readbearingcsv", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/uavrt_localization_utils/re"
      "adbearingcsv.m", // pName
      0                 // checkKind
  };
  static rtBoundsCheckInfo hb_emlrtBCI{
      -1,               // iFirst
      -1,               // iLast
      75,               // lineNo
      22,               // colNo
      "latitude_deg",   // aName
      "readbearingcsv", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/uavrt_localization_utils/re"
      "adbearingcsv.m", // pName
      0                 // checkKind
  };
  static rtBoundsCheckInfo i_emlrtBCI{
      -1,               // iFirst
      -1,               // iLast
      62,               // lineNo
      58,               // colNo
      "commaInds",      // aName
      "readbearingcsv", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/uavrt_localization_utils/re"
      "adbearingcsv.m", // pName
      0                 // checkKind
  };
  static rtBoundsCheckInfo ib_emlrtBCI{
      -1,               // iFirst
      -1,               // iLast
      76,               // lineNo
      53,               // colNo
      "lineStr",        // aName
      "readbearingcsv", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/uavrt_localization_utils/re"
      "adbearingcsv.m", // pName
      0                 // checkKind
  };
  static rtBoundsCheckInfo j_emlrtBCI{
      -1,               // iFirst
      -1,               // iLast
      63,               // lineNo
      41,               // colNo
      "commaInds",      // aName
      "readbearingcsv", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/uavrt_localization_utils/re"
      "adbearingcsv.m", // pName
      0                 // checkKind
  };
  static rtBoundsCheckInfo jb_emlrtBCI{
      -1,               // iFirst
      -1,               // iLast
      76,               // lineNo
      23,               // colNo
      "longitude_deg",  // aName
      "readbearingcsv", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/uavrt_localization_utils/re"
      "adbearingcsv.m", // pName
      0                 // checkKind
  };
  static rtBoundsCheckInfo k_emlrtBCI{
      -1,               // iFirst
      -1,               // iLast
      63,               // lineNo
      58,               // colNo
      "commaInds",      // aName
      "readbearingcsv", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/uavrt_localization_utils/re"
      "adbearingcsv.m", // pName
      0                 // checkKind
  };
  static rtBoundsCheckInfo kb_emlrtBCI{
      -1,               // iFirst
      -1,               // iLast
      77,               // lineNo
      53,               // colNo
      "lineStr",        // aName
      "readbearingcsv", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/uavrt_localization_utils/re"
      "adbearingcsv.m", // pName
      0                 // checkKind
  };
  static rtBoundsCheckInfo l_emlrtBCI{
      -1,               // iFirst
      -1,               // iLast
      64,               // lineNo
      41,               // colNo
      "commaInds",      // aName
      "readbearingcsv", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/uavrt_localization_utils/re"
      "adbearingcsv.m", // pName
      0                 // checkKind
  };
  static rtBoundsCheckInfo lb_emlrtBCI{
      -1,               // iFirst
      -1,               // iLast
      77,               // lineNo
      19,               // colNo
      "alt_AGL_m",      // aName
      "readbearingcsv", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/uavrt_localization_utils/re"
      "adbearingcsv.m", // pName
      0                 // checkKind
  };
  static rtBoundsCheckInfo m_emlrtBCI{
      -1,               // iFirst
      -1,               // iLast
      64,               // lineNo
      58,               // colNo
      "commaInds",      // aName
      "readbearingcsv", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/uavrt_localization_utils/re"
      "adbearingcsv.m", // pName
      0                 // checkKind
  };
  static rtBoundsCheckInfo mb_emlrtBCI{
      -1,               // iFirst
      -1,               // iLast
      78,               // lineNo
      53,               // colNo
      "lineStr",        // aName
      "readbearingcsv", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/uavrt_localization_utils/re"
      "adbearingcsv.m", // pName
      0                 // checkKind
  };
  static rtBoundsCheckInfo n_emlrtBCI{
      -1,               // iFirst
      -1,               // iLast
      65,               // lineNo
      41,               // colNo
      "commaInds",      // aName
      "readbearingcsv", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/uavrt_localization_utils/re"
      "adbearingcsv.m", // pName
      0                 // checkKind
  };
  static rtBoundsCheckInfo nb_emlrtBCI{
      -1,               // iFirst
      -1,               // iLast
      78,               // lineNo
      19,               // colNo
      "alt_ASL_m",      // aName
      "readbearingcsv", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/uavrt_localization_utils/re"
      "adbearingcsv.m", // pName
      0                 // checkKind
  };
  static rtBoundsCheckInfo o_emlrtBCI{
      -1,               // iFirst
      -1,               // iLast
      65,               // lineNo
      58,               // colNo
      "commaInds",      // aName
      "readbearingcsv", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/uavrt_localization_utils/re"
      "adbearingcsv.m", // pName
      0                 // checkKind
  };
  static rtBoundsCheckInfo ob_emlrtBCI{
      -1,               // iFirst
      -1,               // iLast
      79,               // lineNo
      53,               // colNo
      "lineStr",        // aName
      "readbearingcsv", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/uavrt_localization_utils/re"
      "adbearingcsv.m", // pName
      0                 // checkKind
  };
  static rtBoundsCheckInfo p_emlrtBCI{
      -1,               // iFirst
      -1,               // iLast
      66,               // lineNo
      41,               // colNo
      "commaInds",      // aName
      "readbearingcsv", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/uavrt_localization_utils/re"
      "adbearingcsv.m", // pName
      0                 // checkKind
  };
  static rtBoundsCheckInfo pb_emlrtBCI{
      -1,               // iFirst
      -1,               // iLast
      79,               // lineNo
      22,               // colNo
      "time_start_s",   // aName
      "readbearingcsv", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/uavrt_localization_utils/re"
      "adbearingcsv.m", // pName
      0                 // checkKind
  };
  static rtBoundsCheckInfo q_emlrtBCI{
      -1,               // iFirst
      -1,               // iLast
      66,               // lineNo
      58,               // colNo
      "commaInds",      // aName
      "readbearingcsv", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/uavrt_localization_utils/re"
      "adbearingcsv.m", // pName
      0                 // checkKind
  };
  static rtBoundsCheckInfo qb_emlrtBCI{
      -1,               // iFirst
      -1,               // iLast
      80,               // lineNo
      53,               // colNo
      "lineStr",        // aName
      "readbearingcsv", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/uavrt_localization_utils/re"
      "adbearingcsv.m", // pName
      0                 // checkKind
  };
  static rtBoundsCheckInfo r_emlrtBCI{
      -1,               // iFirst
      -1,               // iLast
      67,               // lineNo
      41,               // colNo
      "commaInds",      // aName
      "readbearingcsv", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/uavrt_localization_utils/re"
      "adbearingcsv.m", // pName
      0                 // checkKind
  };
  static rtBoundsCheckInfo rb_emlrtBCI{
      -1,               // iFirst
      -1,               // iLast
      80,               // lineNo
      20,               // colNo
      "time_end_s",     // aName
      "readbearingcsv", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/uavrt_localization_utils/re"
      "adbearingcsv.m", // pName
      0                 // checkKind
  };
  static rtBoundsCheckInfo s_emlrtBCI{
      -1,               // iFirst
      -1,               // iLast
      67,               // lineNo
      58,               // colNo
      "commaInds",      // aName
      "readbearingcsv", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/uavrt_localization_utils/re"
      "adbearingcsv.m", // pName
      0                 // checkKind
  };
  static rtBoundsCheckInfo t_emlrtBCI{
      -1,               // iFirst
      -1,               // iLast
      68,               // lineNo
      41,               // colNo
      "commaInds",      // aName
      "readbearingcsv", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/uavrt_localization_utils/re"
      "adbearingcsv.m", // pName
      0                 // checkKind
  };
  static rtBoundsCheckInfo u_emlrtBCI{
      -1,               // iFirst
      -1,               // iLast
      68,               // lineNo
      58,               // colNo
      "commaInds",      // aName
      "readbearingcsv", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/uavrt_localization_utils/re"
      "adbearingcsv.m", // pName
      0                 // checkKind
  };
  static rtBoundsCheckInfo v_emlrtBCI{
      -1,               // iFirst
      -1,               // iLast
      69,               // lineNo
      41,               // colNo
      "commaInds",      // aName
      "readbearingcsv", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/uavrt_localization_utils/re"
      "adbearingcsv.m", // pName
      0                 // checkKind
  };
  static rtBoundsCheckInfo w_emlrtBCI{
      -1,               // iFirst
      -1,               // iLast
      71,               // lineNo
      60,               // colNo
      "lineStr",        // aName
      "readbearingcsv", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/uavrt_localization_utils/re"
      "adbearingcsv.m", // pName
      0                 // checkKind
  };
  static rtBoundsCheckInfo x_emlrtBCI{
      -1,               // iFirst
      -1,               // iLast
      71,               // lineNo
      15,               // colNo
      "tagID",          // aName
      "readbearingcsv", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/uavrt_localization_utils/re"
      "adbearingcsv.m", // pName
      0                 // checkKind
  };
  static rtBoundsCheckInfo y_emlrtBCI{
      -1,               // iFirst
      -1,               // iLast
      72,               // lineNo
      24,               // colNo
      "parentFileName", // aName
      "readbearingcsv", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/uavrt_localization_utils/re"
      "adbearingcsv.m", // pName
      0                 // checkKind
  };
  static rtDoubleCheckInfo b_emlrtDCI{
      72,               // lineNo
      37,               // colNo
      "readbearingcsv", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/uavrt_localization_utils/re"
      "adbearingcsv.m", // pName
      1                 // checkKind
  };
  static rtDoubleCheckInfo c_emlrtDCI{
      73,               // lineNo
      53,               // colNo
      "readbearingcsv", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/uavrt_localization_utils/re"
      "adbearingcsv.m", // pName
      1                 // checkKind
  };
  static rtDoubleCheckInfo d_emlrtDCI{
      74,               // lineNo
      53,               // colNo
      "readbearingcsv", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/uavrt_localization_utils/re"
      "adbearingcsv.m", // pName
      1                 // checkKind
  };
  static rtDoubleCheckInfo e_emlrtDCI{
      75,               // lineNo
      53,               // colNo
      "readbearingcsv", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/uavrt_localization_utils/re"
      "adbearingcsv.m", // pName
      1                 // checkKind
  };
  static rtDoubleCheckInfo f_emlrtDCI{
      76,               // lineNo
      53,               // colNo
      "readbearingcsv", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/uavrt_localization_utils/re"
      "adbearingcsv.m", // pName
      1                 // checkKind
  };
  static rtDoubleCheckInfo g_emlrtDCI{
      77,               // lineNo
      53,               // colNo
      "readbearingcsv", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/uavrt_localization_utils/re"
      "adbearingcsv.m", // pName
      1                 // checkKind
  };
  static rtDoubleCheckInfo h_emlrtDCI{
      78,               // lineNo
      53,               // colNo
      "readbearingcsv", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/uavrt_localization_utils/re"
      "adbearingcsv.m", // pName
      1                 // checkKind
  };
  static rtDoubleCheckInfo i_emlrtDCI{
      79,               // lineNo
      53,               // colNo
      "readbearingcsv", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/uavrt_localization_utils/re"
      "adbearingcsv.m", // pName
      1                 // checkKind
  };
  static rtDoubleCheckInfo j_emlrtDCI{
      80,               // lineNo
      53,               // colNo
      "readbearingcsv", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/uavrt_localization_utils/re"
      "adbearingcsv.m", // pName
      1                 // checkKind
  };
  static const char cv[14]{'F', 'i', 'l', 'e', ' ', 'n', 'o',
                           't', ' ', 'f', 'o', 'u', 'n', 'd'};
  std::FILE *f;
  coder::onCleanup x;
  coder::array<cell_wrap_4, 1U> parentFileName;
  coder::array<double, 2U> alt_AGL_inds;
  coder::array<double, 2U> alt_ASL_inds;
  coder::array<double, 2U> bearing_inds;
  coder::array<double, 2U> lat_inds;
  coder::array<double, 2U> lineLocs;
  coder::array<double, 2U> lon_inds;
  coder::array<double, 2U> parentFileName_inds;
  coder::array<double, 2U> tau_inds;
  coder::array<double, 2U> time_end_inds;
  coder::array<double, 2U> time_start_inds;
  coder::array<double, 1U> alt_AGL_m;
  coder::array<double, 1U> alt_ASL_m;
  coder::array<double, 1U> b_bearing;
  coder::array<double, 1U> latitude_deg;
  coder::array<double, 1U> longitude_deg;
  coder::array<double, 1U> tau;
  coder::array<double, 1U> time_end_s;
  coder::array<double, 1U> time_start_s;
  coder::array<unsigned int, 2U> commaInds;
  coder::array<int, 2U> matches;
  coder::array<int, 2U> tagID_inds;
  coder::array<unsigned int, 1U> tagID;
  coder::array<char, 2U> b_lineStr;
  coder::array<char, 2U> lineStr;
  cell_wrap_4 r;
  int i;
  signed char fileid;
  boolean_T a;
  fileid = coder::internal::cfopen(filePath, "rb");
  if (fileid != -1) {
    double b_i;
    double d;
    int c_i;
    int i1;
    int match_idx;
    int text_len;
    signed char b_fileid;
    // nLines = countlines(filePath);
    // GETTEXTFILELINELOCS returns the locations in the a text file of the
    // beginning of each line. Empty lines are not included in the listing.
    //
    // INPUTS:
    //    fname - char array of file path to be read
    // OUTPUTS:
    //    lineLocRecord - 1 x n vector of locations of lines with text
    //
    // --------------------------------------------------------------------------
    //  Author: Michael Shafer
    //  Date: 2023-06-12
    // --------------------------------------------------------------------------
    b_fileid = coder::internal::cfopen(filePath, "rb");
    x.task.workspace.fid = b_fileid;
    x.matlabCodegenIsDeleted = false;
    lineLocs.set_size(1, 0);
    b_i = 1.0;
    int exitg1;
    do {
      exitg1 = 0;
      f = coder::internal::getfilestar(static_cast<double>(b_fileid), a);
      if (f == nullptr) {
        rtErrorWithMessageID(j_emlrtRTEI.fName, j_emlrtRTEI.lineNo);
      } else {
        int st;
        st = std::feof(f);
        i = ((int)st != 0);
      }
      if (i == 0) {
        d = coder::b_ftell(static_cast<double>(b_fileid));
        c_i = lineLocs.size(1);
        lineLocs.set_size(1, lineLocs.size(1) + 1);
        lineLocs[c_i] = d;
        coder::fgetl(static_cast<double>(b_fileid), lineStr);
        if (lineStr.size(1) == 0) {
          text_len = static_cast<int>(b_i);
          if (static_cast<int>(b_i) > lineLocs.size(1)) {
            t_rtErrorWithMessageID(s_emlrtRTEI.fName, s_emlrtRTEI.lineNo);
          }
          match_idx = lineLocs.size(1) - 1;
          for (c_i = text_len; c_i <= match_idx; c_i++) {
            lineLocs[c_i - 1] = lineLocs[c_i];
          }
          if (lineLocs.size(1) - 1 < 1) {
            i1 = 0;
          } else {
            i1 = lineLocs.size(1) - 1;
          }
          lineLocs.set_size(lineLocs.size(0), i1);
        } else {
          b_i++;
        }
      } else {
        exitg1 = 1;
      }
    } while (exitg1 == 0);
    x.handle_matlabCodegenDestructor();
    text_len = lineLocs.size(1);
    parentFileName.set_size(lineLocs.size(1));
    for (i = 0; i < text_len; i++) {
      if (i > parentFileName.size(0) - 1) {
        rtDynamicBoundsError(i, 0, parentFileName.size(0) - 1, b_emlrtBCI);
      }
      parentFileName[i].f1.set_size(1, parentFileName[i].f1.size(1));
      if (i > parentFileName.size(0) - 1) {
        rtDynamicBoundsError(i, 0, parentFileName.size(0) - 1, b_emlrtBCI);
      }
      parentFileName[i].f1.set_size(parentFileName[i].f1.size(0), 0);
    }
    // Initialize for coder
    i = lineLocs.size(1);
    parentFileName.set_size(lineLocs.size(1));
    for (int d_i{0}; d_i < i; d_i++) {
      if (d_i > parentFileName.size(0) - 1) {
        rtDynamicBoundsError(d_i, 0, parentFileName.size(0) - 1, c_emlrtBCI);
      }
      parentFileName[d_i].f1.set_size(1, parentFileName[d_i].f1.size(1));
      if (d_i > parentFileName.size(0) - 1) {
        rtDynamicBoundsError(d_i, 0, parentFileName.size(0) - 1, c_emlrtBCI);
      }
      parentFileName[d_i].f1.set_size(parentFileName[d_i].f1.size(0), 0);
      if (d_i > parentFileName.size(0) - 1) {
        rtDynamicBoundsError(d_i, 0, parentFileName.size(0) - 1, c_emlrtBCI);
      }
    }
    // while ~feof(fid)
    i = lineLocs.size(1);
    tagID.set_size(lineLocs.size(1));
    parentFileName.set_size(lineLocs.size(1));
    b_bearing.set_size(lineLocs.size(1));
    tau.set_size(lineLocs.size(1));
    latitude_deg.set_size(lineLocs.size(1));
    longitude_deg.set_size(lineLocs.size(1));
    alt_AGL_m.set_size(lineLocs.size(1));
    alt_ASL_m.set_size(lineLocs.size(1));
    time_start_s.set_size(lineLocs.size(1));
    time_end_s.set_size(lineLocs.size(1));
    for (int d_i{0}; d_i < i; d_i++) {
      creal_T b_x;
      unsigned int u;
      if (d_i + 1 > lineLocs.size(1)) {
        rtDynamicBoundsError(d_i + 1, 1, lineLocs.size(1), d_emlrtBCI);
      }
      coder::cfseek(static_cast<double>(fileid), lineLocs[d_i]);
      coder::fgetl(static_cast<double>(fileid), lineStr);
      if (lineStr.size(1) == 0) {
        commaInds.set_size(1, 0);
      } else {
        text_len = lineStr.size(1);
        matches.set_size(1, lineStr.size(1));
        match_idx = 0;
        if (lineStr.size(1) > 2147483646) {
          coder::check_forloop_overflow_error();
        }
        for (c_i = 0; c_i < text_len; c_i++) {
          if (lineStr[c_i] == ',') {
            matches[match_idx] = c_i + 1;
            match_idx++;
          }
        }
        tagID_inds.set_size(1, match_idx);
        if (match_idx > 2147483646) {
          coder::check_forloop_overflow_error();
        }
        for (c_i = 0; c_i < match_idx; c_i++) {
          tagID_inds[c_i] = matches[c_i];
        }
        commaInds.set_size(1, tagID_inds.size(1));
        text_len = tagID_inds.size(1);
        for (c_i = 0; c_i < text_len; c_i++) {
          commaInds[c_i] = static_cast<unsigned int>(tagID_inds[c_i]);
        }
      }
      if (commaInds.size(1) < 1) {
        rtDynamicBoundsError(1, 1, commaInds.size(1), e_emlrtBCI);
      }
      if (static_cast<int>(commaInds[0]) - 1 < 1) {
        tagID_inds.set_size(1, 0);
      } else {
        text_len = static_cast<int>(commaInds[0]) - 2;
        tagID_inds.set_size(1, text_len + 1);
        for (c_i = 0; c_i <= text_len; c_i++) {
          tagID_inds[c_i] = c_i + 1;
        }
      }
      if (commaInds.size(1) < 1) {
        rtDynamicBoundsError(1, 1, commaInds.size(1), f_emlrtBCI);
      }
      if (commaInds.size(1) < 2) {
        rtDynamicBoundsError(2, 1, commaInds.size(1), g_emlrtBCI);
      }
      if (static_cast<unsigned int>(static_cast<int>(commaInds[1]) - 1) <
          commaInds[0] + 1U) {
        parentFileName_inds.set_size(1, 0);
      } else {
        d = static_cast<double>(commaInds[0]) + 1.0;
        text_len =
            static_cast<int>((static_cast<double>(commaInds[1]) - 1.0) - d);
        parentFileName_inds.set_size(1, text_len + 1);
        for (c_i = 0; c_i <= text_len; c_i++) {
          parentFileName_inds[c_i] = d + static_cast<double>(c_i);
        }
      }
      if (commaInds.size(1) < 2) {
        rtDynamicBoundsError(2, 1, commaInds.size(1), h_emlrtBCI);
      }
      if (commaInds.size(1) < 3) {
        rtDynamicBoundsError(3, 1, commaInds.size(1), i_emlrtBCI);
      }
      if (static_cast<unsigned int>(static_cast<int>(commaInds[2]) - 1) <
          commaInds[1] + 1U) {
        bearing_inds.set_size(1, 0);
      } else {
        d = static_cast<double>(commaInds[1]) + 1.0;
        text_len =
            static_cast<int>((static_cast<double>(commaInds[2]) - 1.0) - d);
        bearing_inds.set_size(1, text_len + 1);
        for (c_i = 0; c_i <= text_len; c_i++) {
          bearing_inds[c_i] = d + static_cast<double>(c_i);
        }
      }
      if (commaInds.size(1) < 3) {
        rtDynamicBoundsError(3, 1, commaInds.size(1), j_emlrtBCI);
      }
      if (commaInds.size(1) < 4) {
        rtDynamicBoundsError(4, 1, commaInds.size(1), k_emlrtBCI);
      }
      if (static_cast<unsigned int>(static_cast<int>(commaInds[3]) - 1) <
          commaInds[2] + 1U) {
        tau_inds.set_size(1, 0);
      } else {
        d = static_cast<double>(commaInds[2]) + 1.0;
        text_len =
            static_cast<int>((static_cast<double>(commaInds[3]) - 1.0) - d);
        tau_inds.set_size(1, text_len + 1);
        for (c_i = 0; c_i <= text_len; c_i++) {
          tau_inds[c_i] = d + static_cast<double>(c_i);
        }
      }
      if (commaInds.size(1) < 4) {
        rtDynamicBoundsError(4, 1, commaInds.size(1), l_emlrtBCI);
      }
      if (commaInds.size(1) < 5) {
        rtDynamicBoundsError(5, 1, commaInds.size(1), m_emlrtBCI);
      }
      if (static_cast<unsigned int>(static_cast<int>(commaInds[4]) - 1) <
          commaInds[3] + 1U) {
        lat_inds.set_size(1, 0);
      } else {
        d = static_cast<double>(commaInds[3]) + 1.0;
        text_len =
            static_cast<int>((static_cast<double>(commaInds[4]) - 1.0) - d);
        lat_inds.set_size(1, text_len + 1);
        for (c_i = 0; c_i <= text_len; c_i++) {
          lat_inds[c_i] = d + static_cast<double>(c_i);
        }
      }
      if (commaInds.size(1) < 5) {
        rtDynamicBoundsError(5, 1, commaInds.size(1), n_emlrtBCI);
      }
      if (commaInds.size(1) < 6) {
        rtDynamicBoundsError(6, 1, commaInds.size(1), o_emlrtBCI);
      }
      if (static_cast<unsigned int>(static_cast<int>(commaInds[5]) - 1) <
          commaInds[4] + 1U) {
        lon_inds.set_size(1, 0);
      } else {
        d = static_cast<double>(commaInds[4]) + 1.0;
        text_len =
            static_cast<int>((static_cast<double>(commaInds[5]) - 1.0) - d);
        lon_inds.set_size(1, text_len + 1);
        for (c_i = 0; c_i <= text_len; c_i++) {
          lon_inds[c_i] = d + static_cast<double>(c_i);
        }
      }
      if (commaInds.size(1) < 6) {
        rtDynamicBoundsError(6, 1, commaInds.size(1), p_emlrtBCI);
      }
      if (commaInds.size(1) < 7) {
        rtDynamicBoundsError(7, 1, commaInds.size(1), q_emlrtBCI);
      }
      if (static_cast<unsigned int>(static_cast<int>(commaInds[6]) - 1) <
          commaInds[5] + 1U) {
        alt_AGL_inds.set_size(1, 0);
      } else {
        d = static_cast<double>(commaInds[5]) + 1.0;
        text_len =
            static_cast<int>((static_cast<double>(commaInds[6]) - 1.0) - d);
        alt_AGL_inds.set_size(1, text_len + 1);
        for (c_i = 0; c_i <= text_len; c_i++) {
          alt_AGL_inds[c_i] = d + static_cast<double>(c_i);
        }
      }
      if (commaInds.size(1) < 7) {
        rtDynamicBoundsError(7, 1, commaInds.size(1), r_emlrtBCI);
      }
      if (commaInds.size(1) < 8) {
        rtDynamicBoundsError(8, 1, commaInds.size(1), s_emlrtBCI);
      }
      if (static_cast<unsigned int>(static_cast<int>(commaInds[7]) - 1) <
          commaInds[6] + 1U) {
        alt_ASL_inds.set_size(1, 0);
      } else {
        d = static_cast<double>(commaInds[6]) + 1.0;
        text_len =
            static_cast<int>((static_cast<double>(commaInds[7]) - 1.0) - d);
        alt_ASL_inds.set_size(1, text_len + 1);
        for (c_i = 0; c_i <= text_len; c_i++) {
          alt_ASL_inds[c_i] = d + static_cast<double>(c_i);
        }
      }
      if (commaInds.size(1) < 8) {
        rtDynamicBoundsError(8, 1, commaInds.size(1), t_emlrtBCI);
      }
      if (commaInds.size(1) < 9) {
        rtDynamicBoundsError(9, 1, commaInds.size(1), u_emlrtBCI);
      }
      if (static_cast<unsigned int>(static_cast<int>(commaInds[8]) - 1) <
          commaInds[7] + 1U) {
        time_start_inds.set_size(1, 0);
      } else {
        d = static_cast<double>(commaInds[7]) + 1.0;
        text_len =
            static_cast<int>((static_cast<double>(commaInds[8]) - 1.0) - d);
        time_start_inds.set_size(1, text_len + 1);
        for (c_i = 0; c_i <= text_len; c_i++) {
          time_start_inds[c_i] = d + static_cast<double>(c_i);
        }
      }
      if (commaInds.size(1) < 9) {
        rtDynamicBoundsError(9, 1, commaInds.size(1), v_emlrtBCI);
      }
      if (static_cast<unsigned int>(lineStr.size(1)) < commaInds[8] + 1U) {
        time_end_inds.set_size(1, 0);
      } else {
        u = commaInds[8] + 1U;
        text_len = lineStr.size(1) - static_cast<int>(u);
        time_end_inds.set_size(1, text_len + 1);
        for (c_i = 0; c_i <= text_len; c_i++) {
          time_end_inds[c_i] = u + static_cast<unsigned int>(c_i);
        }
      }
      text_len = tagID_inds.size(1);
      for (c_i = 0; c_i < text_len; c_i++) {
        i1 = tagID_inds[c_i];
        if (i1 > lineStr.size(1)) {
          rtDynamicBoundsError(i1, 1, lineStr.size(1), w_emlrtBCI);
        }
      }
      b_lineStr.set_size(1, tagID_inds.size(1));
      text_len = tagID_inds.size(1);
      for (c_i = 0; c_i < text_len; c_i++) {
        b_lineStr[c_i] = lineStr[tagID_inds[c_i] - 1];
      }
      b_x = coder::internal::str2double(b_lineStr);
      if (d_i + 1 > tagID.size(0)) {
        rtDynamicBoundsError(d_i + 1, 1, tagID.size(0), x_emlrtBCI);
      }
      d = std::round(b_x.re);
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
      tagID[d_i] = u;
      c_i = parentFileName.size(0) - 1;
      if (d_i > parentFileName.size(0) - 1) {
        rtDynamicBoundsError(d_i, 0, parentFileName.size(0) - 1, y_emlrtBCI);
      }
      parentFileName[d_i].f1.set_size(1, parentFileName[d_i].f1.size(1));
      if (d_i > parentFileName.size(0) - 1) {
        rtDynamicBoundsError(d_i, 0, parentFileName.size(0) - 1, y_emlrtBCI);
      }
      parentFileName[d_i].f1.set_size(parentFileName[d_i].f1.size(0),
                                      parentFileName_inds.size(1));
      if (d_i > parentFileName.size(0) - 1) {
        rtDynamicBoundsError(d_i, 0, parentFileName.size(0) - 1, y_emlrtBCI);
      }
      text_len = parentFileName_inds.size(1);
      for (i1 = 0; i1 < text_len; i1++) {
        match_idx = static_cast<int>(parentFileName_inds[i1]);
        if (parentFileName_inds[i1] != match_idx) {
          rtIntegerError(parentFileName_inds[i1], b_emlrtDCI);
        }
        if ((match_idx < 1) || (match_idx > lineStr.size(1))) {
          rtDynamicBoundsError(match_idx, 1, lineStr.size(1), ab_emlrtBCI);
        }
        if (d_i > c_i) {
          rtDynamicBoundsError(d_i, 0, c_i, bb_emlrtBCI);
        }
        parentFileName[d_i].f1[i1] = lineStr[match_idx - 1];
      }
      text_len = bearing_inds.size(1);
      for (c_i = 0; c_i < text_len; c_i++) {
        i1 = static_cast<int>(bearing_inds[c_i]);
        if (bearing_inds[c_i] != i1) {
          rtIntegerError(bearing_inds[c_i], c_emlrtDCI);
        }
        if ((i1 < 1) || (i1 > lineStr.size(1))) {
          rtDynamicBoundsError(i1, 1, lineStr.size(1), cb_emlrtBCI);
        }
      }
      b_lineStr.set_size(1, bearing_inds.size(1));
      text_len = bearing_inds.size(1);
      for (c_i = 0; c_i < text_len; c_i++) {
        b_lineStr[c_i] = lineStr[static_cast<int>(bearing_inds[c_i]) - 1];
      }
      b_x = coder::internal::str2double(b_lineStr);
      if (d_i + 1 > b_bearing.size(0)) {
        rtDynamicBoundsError(d_i + 1, 1, b_bearing.size(0), db_emlrtBCI);
      }
      b_bearing[d_i] = b_x.re;
      text_len = tau_inds.size(1);
      for (c_i = 0; c_i < text_len; c_i++) {
        i1 = static_cast<int>(tau_inds[c_i]);
        if (tau_inds[c_i] != i1) {
          rtIntegerError(tau_inds[c_i], d_emlrtDCI);
        }
        if ((i1 < 1) || (i1 > lineStr.size(1))) {
          rtDynamicBoundsError(i1, 1, lineStr.size(1), eb_emlrtBCI);
        }
      }
      b_lineStr.set_size(1, tau_inds.size(1));
      text_len = tau_inds.size(1);
      for (c_i = 0; c_i < text_len; c_i++) {
        b_lineStr[c_i] = lineStr[static_cast<int>(tau_inds[c_i]) - 1];
      }
      b_x = coder::internal::str2double(b_lineStr);
      if (d_i + 1 > tau.size(0)) {
        rtDynamicBoundsError(d_i + 1, 1, tau.size(0), fb_emlrtBCI);
      }
      tau[d_i] = b_x.re;
      text_len = lat_inds.size(1);
      for (c_i = 0; c_i < text_len; c_i++) {
        i1 = static_cast<int>(lat_inds[c_i]);
        if (lat_inds[c_i] != i1) {
          rtIntegerError(lat_inds[c_i], e_emlrtDCI);
        }
        if ((i1 < 1) || (i1 > lineStr.size(1))) {
          rtDynamicBoundsError(i1, 1, lineStr.size(1), gb_emlrtBCI);
        }
      }
      b_lineStr.set_size(1, lat_inds.size(1));
      text_len = lat_inds.size(1);
      for (c_i = 0; c_i < text_len; c_i++) {
        b_lineStr[c_i] = lineStr[static_cast<int>(lat_inds[c_i]) - 1];
      }
      b_x = coder::internal::str2double(b_lineStr);
      if (d_i + 1 > latitude_deg.size(0)) {
        rtDynamicBoundsError(d_i + 1, 1, latitude_deg.size(0), hb_emlrtBCI);
      }
      latitude_deg[d_i] = b_x.re;
      text_len = lon_inds.size(1);
      for (c_i = 0; c_i < text_len; c_i++) {
        i1 = static_cast<int>(lon_inds[c_i]);
        if (lon_inds[c_i] != i1) {
          rtIntegerError(lon_inds[c_i], f_emlrtDCI);
        }
        if ((i1 < 1) || (i1 > lineStr.size(1))) {
          rtDynamicBoundsError(i1, 1, lineStr.size(1), ib_emlrtBCI);
        }
      }
      b_lineStr.set_size(1, lon_inds.size(1));
      text_len = lon_inds.size(1);
      for (c_i = 0; c_i < text_len; c_i++) {
        b_lineStr[c_i] = lineStr[static_cast<int>(lon_inds[c_i]) - 1];
      }
      b_x = coder::internal::str2double(b_lineStr);
      if (d_i + 1 > longitude_deg.size(0)) {
        rtDynamicBoundsError(d_i + 1, 1, longitude_deg.size(0), jb_emlrtBCI);
      }
      longitude_deg[d_i] = b_x.re;
      text_len = alt_AGL_inds.size(1);
      for (c_i = 0; c_i < text_len; c_i++) {
        i1 = static_cast<int>(alt_AGL_inds[c_i]);
        if (alt_AGL_inds[c_i] != i1) {
          rtIntegerError(alt_AGL_inds[c_i], g_emlrtDCI);
        }
        if ((i1 < 1) || (i1 > lineStr.size(1))) {
          rtDynamicBoundsError(i1, 1, lineStr.size(1), kb_emlrtBCI);
        }
      }
      b_lineStr.set_size(1, alt_AGL_inds.size(1));
      text_len = alt_AGL_inds.size(1);
      for (c_i = 0; c_i < text_len; c_i++) {
        b_lineStr[c_i] = lineStr[static_cast<int>(alt_AGL_inds[c_i]) - 1];
      }
      b_x = coder::internal::str2double(b_lineStr);
      if (d_i + 1 > alt_AGL_m.size(0)) {
        rtDynamicBoundsError(d_i + 1, 1, alt_AGL_m.size(0), lb_emlrtBCI);
      }
      alt_AGL_m[d_i] = b_x.re;
      text_len = alt_ASL_inds.size(1);
      for (c_i = 0; c_i < text_len; c_i++) {
        i1 = static_cast<int>(alt_ASL_inds[c_i]);
        if (alt_ASL_inds[c_i] != i1) {
          rtIntegerError(alt_ASL_inds[c_i], h_emlrtDCI);
        }
        if ((i1 < 1) || (i1 > lineStr.size(1))) {
          rtDynamicBoundsError(i1, 1, lineStr.size(1), mb_emlrtBCI);
        }
      }
      b_lineStr.set_size(1, alt_ASL_inds.size(1));
      text_len = alt_ASL_inds.size(1);
      for (c_i = 0; c_i < text_len; c_i++) {
        b_lineStr[c_i] = lineStr[static_cast<int>(alt_ASL_inds[c_i]) - 1];
      }
      b_x = coder::internal::str2double(b_lineStr);
      if (d_i + 1 > alt_ASL_m.size(0)) {
        rtDynamicBoundsError(d_i + 1, 1, alt_ASL_m.size(0), nb_emlrtBCI);
      }
      alt_ASL_m[d_i] = b_x.re;
      text_len = time_start_inds.size(1);
      for (c_i = 0; c_i < text_len; c_i++) {
        i1 = static_cast<int>(time_start_inds[c_i]);
        if (time_start_inds[c_i] != i1) {
          rtIntegerError(time_start_inds[c_i], i_emlrtDCI);
        }
        if ((i1 < 1) || (i1 > lineStr.size(1))) {
          rtDynamicBoundsError(i1, 1, lineStr.size(1), ob_emlrtBCI);
        }
      }
      b_lineStr.set_size(1, time_start_inds.size(1));
      text_len = time_start_inds.size(1);
      for (c_i = 0; c_i < text_len; c_i++) {
        b_lineStr[c_i] = lineStr[static_cast<int>(time_start_inds[c_i]) - 1];
      }
      b_x = coder::internal::str2double(b_lineStr);
      if (d_i + 1 > time_start_s.size(0)) {
        rtDynamicBoundsError(d_i + 1, 1, time_start_s.size(0), pb_emlrtBCI);
      }
      time_start_s[d_i] = b_x.re;
      text_len = time_end_inds.size(1);
      for (c_i = 0; c_i < text_len; c_i++) {
        i1 = static_cast<int>(time_end_inds[c_i]);
        if (time_end_inds[c_i] != i1) {
          rtIntegerError(time_end_inds[c_i], j_emlrtDCI);
        }
        if ((i1 < 1) || (i1 > lineStr.size(1))) {
          rtDynamicBoundsError(i1, 1, lineStr.size(1), qb_emlrtBCI);
        }
      }
      b_lineStr.set_size(1, time_end_inds.size(1));
      text_len = time_end_inds.size(1);
      for (c_i = 0; c_i < text_len; c_i++) {
        b_lineStr[c_i] = lineStr[static_cast<int>(time_end_inds[c_i]) - 1];
      }
      b_x = coder::internal::str2double(b_lineStr);
      if (d_i + 1 > time_end_s.size(0)) {
        rtDynamicBoundsError(d_i + 1, 1, time_end_s.size(0), rb_emlrtBCI);
      }
      time_end_s[d_i] = b_x.re;
      // i = i+1;
    }
  } else {
    std::printf("UAV-RT: Error opening the bearing csv file.");
    std::fflush(stdout);
    tagID.set_size(1);
    tagID[0] = 0U;
    r.f1.set_size(1, 14);
    for (i = 0; i < 14; i++) {
      r.f1[i] = cv[i];
    }
    parentFileName.set_size(1);
    parentFileName[0] = r;
    b_bearing.set_size(1);
    b_bearing[0] = rtNaN;
    tau.set_size(1);
    tau[0] = rtNaN;
    latitude_deg.set_size(1);
    latitude_deg[0] = rtNaN;
    longitude_deg.set_size(1);
    longitude_deg[0] = rtNaN;
    alt_AGL_m.set_size(1);
    alt_AGL_m[0] = rtNaN;
    alt_ASL_m.set_size(1);
    alt_ASL_m[0] = rtNaN;
    time_start_s.set_size(1);
    time_start_s[0] = rtNaN;
    time_end_s.set_size(1);
    time_end_s[0] = rtNaN;
  }
  tableOut.init(tagID, parentFileName, b_bearing, tau, latitude_deg,
                longitude_deg, alt_AGL_m, alt_ASL_m, time_start_s, time_end_s);
}

//
// File trailer for readbearingcsv.cpp
//
// [EOF]
//
