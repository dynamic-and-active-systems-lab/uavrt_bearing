//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: readpulsecsv.cpp
//
// MATLAB Coder version            : 5.6
// C/C++ source code generated on  : 27-Jun-2023 16:44:57
//

// Include Files
#include "readpulsecsv.h"
#include "PositionStruct.h"
#include "PulseStruct.h"
#include "anonymous_function.h"
#include "bearing_data.h"
#include "bearing_internal_types.h"
#include "bearing_rtwutil.h"
#include "bearing_types.h"
#include "eml_int_forloop_overflow_check.h"
#include "fgetl.h"
#include "fgets.h"
#include "fileManager.h"
#include "find.h"
#include "fscanf.h"
#include "fseek.h"
#include "ftell.h"
#include "nullAssignment.h"
#include "onCleanup.h"
#include "quat2eul.h"
#include "repmat.h"
#include "rt_nonfinite.h"
#include "str2double.h"
#include "unique.h"
#include "coder_array.h"
#include "coder_bounded_array.h"
#include <cmath>
#include <cstdio>
#include <sstream>
#include <stdexcept>
#include <string>

// Function Declarations
static void c_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

static void d_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

// Function Definitions
//
// Arguments    : const char *aFcnName
//                int aLineNum
// Return Type  : void
//
static void c_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::stringstream outStream;
  outStream << "NaN values cannot be converted to logicals.";
  outStream << "\n";
  ((((outStream << "Error in ") << aFcnName) << " (line ") << aLineNum) << ")";
  throw std::runtime_error(outStream.str());
}

//
// Arguments    : const char *aFcnName
//                int aLineNum
// Return Type  : void
//
static void d_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::stringstream outStream;
  outStream << "fopen(\'all\') is not supported for code generation.";
  outStream << "\n";
  ((((outStream << "Error in ") << aFcnName) << " (line ") << aLineNum) << ")";
  throw std::runtime_error(outStream.str());
}

//
// READPULSECSV Reads in a pulse csv file and outputs a vector of pulses in
// the file and any commands in the file.
//    This function reads a pulse csv file and converts the pulses and
//    commands in the csv to PulseStruct and CommandStructs. It returns a
//    vector of these structures.
//
// INPUTS:
//    filePath - char array of the path to the file
//
// OUPUTS:
//    pusles   - n x 1 vector of PulseStructs from the file
//    commands - n x 1 vector of CommandStructs from the file
//
// --------------------------------------------------------------------------
//  Author: Michael Shafer
//  Date: 2023-06-12
// --------------------------------------------------------------------------
// --------------------------------------------------------------------------
//
// Arguments    : const coder::array<char, 2U> &filepath
//                coder::array<e_struct_T, 2U> &pulses
//                coder::array<empty, 2U> &commands
// Return Type  : void
//
void readpulsecsv(const coder::array<char, 2U> &filepath,
                  coder::array<e_struct_T, 2U> &pulses,
                  coder::array<empty, 2U> &commands)
{
  static rtBoundsCheckInfo b_emlrtBCI{
      -1,               // iFirst
      -1,               // iLast
      101,              // lineNo
      57,               // colNo
      "commaLocations", // aName
      "readpulsecsv",   // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/uavrt_localization_utils/re"
      "adpulsecsv.m", // pName
      0               // checkKind
  };
  static rtBoundsCheckInfo c_emlrtBCI{
      -1,             // iFirst
      -1,             // iLast
      115,            // lineNo
      24,             // colNo
      "pulseArray",   // aName
      "readpulsecsv", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/uavrt_localization_utils/re"
      "adpulsecsv.m", // pName
      0               // checkKind
  };
  static rtBoundsCheckInfo d_emlrtBCI{
      -1,             // iFirst
      -1,             // iLast
      119,            // lineNo
      26,             // colNo
      "commandArray", // aName
      "readpulsecsv", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/uavrt_localization_utils/re"
      "adpulsecsv.m", // pName
      0               // checkKind
  };
  static rtBoundsCheckInfo e_emlrtBCI{
      -1,             // iFirst
      -1,             // iLast
      101,            // lineNo
      37,             // colNo
      "lineStr",      // aName
      "readpulsecsv", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/uavrt_localization_utils/re"
      "adpulsecsv.m", // pName
      0               // checkKind
  };
  static rtBoundsCheckInfo f_emlrtBCI{
      -1,             // iFirst
      -1,             // iLast
      101,            // lineNo
      42,             // colNo
      "lineStr",      // aName
      "readpulsecsv", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/uavrt_localization_utils/re"
      "adpulsecsv.m", // pName
      0               // checkKind
  };
  static rtBoundsCheckInfo g_emlrtBCI{
      -1,             // iFirst
      -1,             // iLast
      171,            // lineNo
      35,             // colNo
      "commandArray", // aName
      "readpulsecsv", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/uavrt_localization_utils/re"
      "adpulsecsv.m", // pName
      0               // checkKind
  };
  static rtBoundsCheckInfo h_emlrtBCI{
      -1,             // iFirst
      -1,             // iLast
      204,            // lineNo
      53,             // colNo
      "pos_AGL_m",    // aName
      "readpulsecsv", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/uavrt_localization_utils/re"
      "adpulsecsv.m", // pName
      0               // checkKind
  };
  static rtBoundsCheckInfo i_emlrtBCI{
      -1,                 // iFirst
      -1,                 // iLast
      56,                 // lineNo
      39,                 // colNo
      "roll",             // aName
      "EulerAngleStruct", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/uavrt_localization_utils/Eu"
      "lerAngleStruct.m", // pName
      0                   // checkKind
  };
  static rtBoundsCheckInfo j_emlrtBCI{
      -1,                 // iFirst
      -1,                 // iLast
      56,                 // lineNo
      17,                 // colNo
      "eul",              // aName
      "EulerAngleStruct", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/uavrt_localization_utils/Eu"
      "lerAngleStruct.m", // pName
      0                   // checkKind
  };
  static rtBoundsCheckInfo k_emlrtBCI{
      -1,                 // iFirst
      -1,                 // iLast
      57,                 // lineNo
      40,                 // colNo
      "pitch",            // aName
      "EulerAngleStruct", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/uavrt_localization_utils/Eu"
      "lerAngleStruct.m", // pName
      0                   // checkKind
  };
  static rtBoundsCheckInfo l_emlrtBCI{
      -1,                 // iFirst
      -1,                 // iLast
      57,                 // lineNo
      17,                 // colNo
      "eul",              // aName
      "EulerAngleStruct", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/uavrt_localization_utils/Eu"
      "lerAngleStruct.m", // pName
      0                   // checkKind
  };
  static rtBoundsCheckInfo m_emlrtBCI{
      -1,                 // iFirst
      -1,                 // iLast
      58,                 // lineNo
      38,                 // colNo
      "yaw",              // aName
      "EulerAngleStruct", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/uavrt_localization_utils/Eu"
      "lerAngleStruct.m", // pName
      0                   // checkKind
  };
  static rtBoundsCheckInfo n_emlrtBCI{
      -1,                 // iFirst
      -1,                 // iLast
      58,                 // lineNo
      17,                 // colNo
      "eul",              // aName
      "EulerAngleStruct", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/uavrt_localization_utils/Eu"
      "lerAngleStruct.m", // pName
      0                   // checkKind
  };
  static rtBoundsCheckInfo o_emlrtBCI{
      -1,              // iFirst
      -1,              // iLast
      54,              // lineNo
      21,              // colNo
      "command",       // aName
      "CommandStruct", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/uavrt_localization_utils/Co"
      "mmandStruct.m", // pName
      0                // checkKind
  };
  static rtBoundsCheckInfo p_emlrtBCI{
      -1,              // iFirst
      -1,              // iLast
      54,              // lineNo
      13,              // colNo
      "pos",           // aName
      "CommandStruct", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/uavrt_localization_utils/Co"
      "mmandStruct.m", // pName
      0                // checkKind
  };
  static rtBoundsCheckInfo q_emlrtBCI{
      -1,              // iFirst
      -1,              // iLast
      56,              // lineNo
      21,              // colNo
      "command",       // aName
      "CommandStruct", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/uavrt_localization_utils/Co"
      "mmandStruct.m", // pName
      0                // checkKind
  };
  static rtBoundsCheckInfo r_emlrtBCI{
      -1,              // iFirst
      -1,              // iLast
      56,              // lineNo
      48,              // colNo
      "commandID",     // aName
      "CommandStruct", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/uavrt_localization_utils/Co"
      "mmandStruct.m", // pName
      0                // checkKind
  };
  static rtDoubleCheckInfo b_emlrtDCI{
      87,             // lineNo
      25,             // colNo
      "readpulsecsv", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/uavrt_localization_utils/re"
      "adpulsecsv.m", // pName
      1               // checkKind
  };
  static rtDoubleCheckInfo c_emlrtDCI{
      87,             // lineNo
      1,              // colNo
      "readpulsecsv", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/uavrt_localization_utils/re"
      "adpulsecsv.m", // pName
      1               // checkKind
  };
  static rtDoubleCheckInfo d_emlrtDCI{
      88,             // lineNo
      1,              // colNo
      "readpulsecsv", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/uavrt_localization_utils/re"
      "adpulsecsv.m", // pName
      1               // checkKind
  };
  static rtDoubleCheckInfo e_emlrtDCI{
      89,             // lineNo
      25,             // colNo
      "readpulsecsv", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/uavrt_localization_utils/re"
      "adpulsecsv.m", // pName
      1               // checkKind
  };
  static rtDoubleCheckInfo emlrtDCI{
      87,             // lineNo
      25,             // colNo
      "readpulsecsv", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/uavrt_localization_utils/re"
      "adpulsecsv.m", // pName
      4               // checkKind
  };
  static rtDoubleCheckInfo f_emlrtDCI{
      89,             // lineNo
      1,              // colNo
      "readpulsecsv", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/uavrt_localization_utils/re"
      "adpulsecsv.m", // pName
      1               // checkKind
  };
  static rtDoubleCheckInfo g_emlrtDCI{
      90,             // lineNo
      1,              // colNo
      "readpulsecsv", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/uavrt_localization_utils/re"
      "adpulsecsv.m", // pName
      1               // checkKind
  };
  static rtEqualityCheckInfo b_emlrtECI{
      -1,             // nDims
      119,            // lineNo
      13,             // colNo
      "readpulsecsv", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/uavrt_localization_utils/re"
      "adpulsecsv.m" // pName
  };
  static rtEqualityCheckInfo emlrtECI{
      -1,             // nDims
      115,            // lineNo
      13,             // colNo
      "readpulsecsv", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/uavrt_localization_utils/re"
      "adpulsecsv.m" // pName
  };
  static rtRunTimeErrorInfo r_emlrtRTEI{
      37,     // lineNo
      "fopen" // fName
  };
  static rtRunTimeErrorInfo s_emlrtRTEI{
      13,              // lineNo
      "toLogicalCheck" // fName
  };
  static const signed char iv[4]{18, 15, 16, 17};
  static const char cv[3]{'a', 'l', 'l'};
  int st;
  std::FILE *f;
  coder::onCleanup x;
  coder::array<d_struct_T, 2U> eulers_deg;
  coder::array<struct_T, 2U> positions;
  coder::array<double, 2U> c_pulseArray;
  coder::array<double, 2U> commandArray;
  coder::array<double, 2U> eul_deg;
  coder::array<double, 2U> pulseArray;
  coder::array<double, 1U> commandLineNums;
  coder::array<double, 1U> d_pulseArray;
  coder::array<double, 1U> e_pulseArray;
  coder::array<double, 1U> pulseLineNums;
  coder::array<unsigned int, 2U> commaLocations;
  coder::array<int, 2U> match_out;
  coder::array<int, 2U> matches;
  coder::array<int, 1U> b_ii;
  coder::array<int, 1U> c_ii;
  coder::array<int, 1U> ii;
  coder::array<char, 2U> b_fid;
  coder::array<char, 2U> b_lineStr;
  coder::array<char, 2U> lineStr;
  coder::array<boolean_T, 1U> b_pulseArray;
  d_struct_T eulInit;
  e_struct_T pulseInit;
  struct_T posInit;
  double tmp_data[19];
  double b_tmp_data[4];
  double emptyLineCounter;
  double numOfLines;
  int lineStr_size[2];
  int tmp_size[2];
  int b_x;
  unsigned int commandInd;
  unsigned int dataInd;
  int exitg1;
  int fid;
  int i;
  int match_idx;
  int text_len;
  signed char fileid;
  boolean_T b_bool;
  // Initialize outputs so they are defined for all exectution paths.
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
  pulses.set_size(1, 1);
  pulses[0] = pulseInit;
  // COMMANDSTRUCT Generates a command structure
  //    This function generates a standard command structure with the
  //    following fields:
  //
  //    commandID    CommandID
  //    position     Position (PositionStruct)
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
  commands.set_size(1, 1);
  b_bool = false;
  if (filepath.size(1) == 3) {
    text_len = 0;
    do {
      exitg1 = 0;
      if (text_len < 3) {
        if (filepath[text_len] != cv[text_len]) {
          exitg1 = 1;
        } else {
          text_len++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  if (b_bool) {
    d_rtErrorWithMessageID(r_emlrtRTEI.fName, r_emlrtRTEI.lineNo);
  } else {
    fileid = coder::internal::cfopen(filepath, "rb");
    fid = fileid;
  }
  // d for delimiter
  // COUNTLINES counts the number of lines in a csv file
  //    This function reads in a CSV file and returns to total number of lines
  //    in the file.
  //    Based on
  //    https://stackoverflow.com/questions/12176519/is-there-a-way-in-matlab-to-determine-the-number-of-lines-in-a-file-without-loop
  //    Updated to not count multiple new lines after valid text in a line
  //    Also uses fgetl to read lines so the final line doesn't need a final \n
  //    character to get counted.
  //
  // INPUTS:
  //    fname - char array of path to file
  //
  // OUTPUTS:
  //    count - number of lines in the file
  //
  // --------------------------------------------------------------------------
  //  Author: Michael Shafer
  //  Date: 2023-06-12
  // --------------------------------------------------------------------------
  fileid = coder::internal::cfopen(filepath, "rb");
  x.task.workspace.fid = fileid;
  x.matlabCodegenIsDeleted = false;
  numOfLines = 0.0;
  //  while ~feof(fid)
  //      count = count + sum( fread( fid, 16384, 'char' ) == char(10) );
  //  end
  emptyLineCounter = 0.0;
  do {
    exitg1 = 0;
    f = coder::internal::getfilestar(static_cast<double>(fileid), b_bool);
    if (f == nullptr) {
      rtErrorWithMessageID(emlrtRTEI.fName, emlrtRTEI.lineNo);
    } else {
      st = std::feof(f);
      match_idx = ((int)st != 0);
    }
    if (match_idx == 0) {
      coder::fgetl(static_cast<double>(fileid), lineStr);
      if (lineStr.size(1) == 0) {
        emptyLineCounter++;
      } else {
        emptyLineCounter = 0.0;
      }
      numOfLines++;
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);
  numOfLines -= emptyLineCounter;
  x.matlabCodegenDestructor();
  //  lineLocs = gettextfilelinelocs(filepath);
  //  nLines = numel(lineLocs);
  if (!(numOfLines >= 0.0)) {
    rtNonNegativeError(numOfLines, emlrtDCI);
  }
  if (numOfLines != static_cast<int>(numOfLines)) {
    rtIntegerError(numOfLines, b_emlrtDCI);
  }
  match_idx = static_cast<int>(numOfLines);
  pulseArray.set_size(static_cast<int>(numOfLines), 19);
  if (numOfLines != static_cast<int>(numOfLines)) {
    rtIntegerError(numOfLines, c_emlrtDCI);
  }
  text_len = static_cast<int>(numOfLines) * 19;
  for (i = 0; i < text_len; i++) {
    pulseArray[i] = 0.0;
  }
  if (numOfLines != static_cast<int>(numOfLines)) {
    rtIntegerError(numOfLines, d_emlrtDCI);
  }
  pulseLineNums.set_size(static_cast<int>(numOfLines));
  if (numOfLines != static_cast<int>(numOfLines)) {
    rtIntegerError(numOfLines, d_emlrtDCI);
  }
  for (i = 0; i < match_idx; i++) {
    pulseLineNums[i] = 0.0;
  }
  if (numOfLines != static_cast<int>(numOfLines)) {
    rtIntegerError(numOfLines, e_emlrtDCI);
  }
  commandArray.set_size(static_cast<int>(numOfLines), 4);
  if (numOfLines != static_cast<int>(numOfLines)) {
    rtIntegerError(numOfLines, f_emlrtDCI);
  }
  text_len = static_cast<int>(numOfLines) << 2;
  for (i = 0; i < text_len; i++) {
    commandArray[i] = 0.0;
  }
  if (numOfLines != static_cast<int>(numOfLines)) {
    rtIntegerError(numOfLines, g_emlrtDCI);
  }
  commandLineNums.set_size(static_cast<int>(numOfLines));
  if (numOfLines != static_cast<int>(numOfLines)) {
    rtIntegerError(numOfLines, g_emlrtDCI);
  }
  for (i = 0; i < match_idx; i++) {
    commandLineNums[i] = 0.0;
  }
  emptyLineCounter = 1.0;
  numOfLines = coder::b_ftell(static_cast<double>(fid));
  dataInd = 1U;
  commandInd = 1U;
  do {
    exitg1 = 0;
    f = coder::internal::getfilestar(static_cast<double>(fid), b_bool);
    if (f == nullptr) {
      rtErrorWithMessageID(emlrtRTEI.fName, emlrtRTEI.lineNo);
    } else {
      st = std::feof(f);
      b_x = ((int)st != 0);
    }
    if (b_x == 0) {
      creal_T commandID;
      coder::fgetl(static_cast<double>(fid), lineStr);
      if (lineStr.size(1) == 0) {
        commaLocations.set_size(1, 0);
      } else {
        text_len = lineStr.size(1);
        matches.set_size(1, lineStr.size(1));
        match_idx = 0;
        if (lineStr.size(1) > 2147483646) {
          coder::check_forloop_overflow_error();
        }
        for (int b_i{0}; b_i < text_len; b_i++) {
          if (lineStr[b_i] == ',') {
            matches[match_idx] = b_i + 1;
            match_idx++;
          }
        }
        match_out.set_size(1, match_idx);
        if (match_idx > 2147483646) {
          coder::check_forloop_overflow_error();
        }
        for (int b_i{0}; b_i < match_idx; b_i++) {
          match_out[b_i] = matches[b_i];
        }
        commaLocations.set_size(1, match_out.size(1));
        match_idx = match_out.size(1);
        for (i = 0; i < match_idx; i++) {
          commaLocations[i] = static_cast<unsigned int>(match_out[i]);
        }
      }
      if (commaLocations.size(1) < 1) {
        rtDynamicBoundsError(1, 1, commaLocations.size(1), b_emlrtBCI);
      }
      match_idx = static_cast<int>(commaLocations[0]) - 1;
      if (match_idx < 1) {
        match_idx = 0;
      } else {
        if (lineStr.size(1) < 1) {
          rtDynamicBoundsError(1, 1, lineStr.size(1), e_emlrtBCI);
        }
        if (match_idx > lineStr.size(1)) {
          rtDynamicBoundsError(match_idx, 1, lineStr.size(1), f_emlrtBCI);
        }
      }
      b_lineStr.set_size(1, match_idx);
      for (i = 0; i < match_idx; i++) {
        b_lineStr[i] = lineStr[i];
      }
      commandID = coder::internal::str2double(b_lineStr);
      numOfLines = coder::cfseek(static_cast<double>(fid), numOfLines);
      if (std::isnan(numOfLines)) {
        c_rtErrorWithMessageID(s_emlrtRTEI.fName, s_emlrtRTEI.lineNo);
      }
      if (!(numOfLines != 0.0)) {
        if ((commandID.re == 7.0) && (commandID.im == 0.0)) {
          b_bool = ((static_cast<int>(dataInd) < 1) ||
                    (static_cast<int>(dataInd) > pulseArray.size(0)));
          if (b_bool) {
            rtDynamicBoundsError(static_cast<int>(dataInd), 1,
                                 pulseArray.size(0), c_emlrtBCI);
          }
          coder::b_fscanf(static_cast<double>(fid), tmp_data, tmp_size);
          lineStr_size[0] = 1;
          lineStr_size[1] = 19;
          rtSubAssignSizeCheck(&lineStr_size[0], 2, &tmp_size[0], 2, emlrtECI);
          for (i = 0; i < 19; i++) {
            pulseArray[(static_cast<int>(dataInd) + pulseArray.size(0) * i) -
                       1] = tmp_data[i];
          }
          pulseLineNums[static_cast<int>(dataInd) - 1] = emptyLineCounter;
          dataInd++;
        } else if (((commandID.re == 10.0) && (commandID.im == 0.0)) ||
                   ((commandID.re == 11.0) && (commandID.im == 0.0))) {
          b_bool = ((static_cast<int>(commandInd) < 1) ||
                    (static_cast<int>(commandInd) > commandArray.size(0)));
          if (b_bool) {
            rtDynamicBoundsError(static_cast<int>(commandInd), 1,
                                 commandArray.size(0), d_emlrtBCI);
          }
          coder::c_fscanf(static_cast<double>(fid), b_tmp_data, tmp_size);
          lineStr_size[0] = 1;
          lineStr_size[1] = 4;
          rtSubAssignSizeCheck(&lineStr_size[0], 2, &tmp_size[0], 2,
                               b_emlrtECI);
          commandArray[static_cast<int>(commandInd) - 1] = b_tmp_data[0];
          commandArray[(static_cast<int>(commandInd) + commandArray.size(0)) -
                       1] = b_tmp_data[1];
          commandArray[(static_cast<int>(commandInd) +
                        commandArray.size(0) * 2) -
                       1] = b_tmp_data[2];
          commandArray[(static_cast<int>(commandInd) +
                        commandArray.size(0) * 3) -
                       1] = b_tmp_data[3];
          commandLineNums[static_cast<int>(commandInd) - 1] = emptyLineCounter;
          commandInd++;
        } else {
          coder::b_fgets(static_cast<double>(fid), b_fid);
          //  Discard if not commandID 7, 10, or 11
        }
        emptyLineCounter++;
        numOfLines = coder::b_ftell(static_cast<double>(fid));
      } else {
        std::printf("UAV-RT: Error with file rewind");
        std::fflush(stdout);
        coder::internal::cfclose(static_cast<double>(fid));
        exitg1 = 1;
      }
    } else {
      boolean_T c_x[2];
      boolean_T exitg2;
      match_idx = static_cast<int>(static_cast<double>(pulseArray.size(0)) -
                                   static_cast<double>(dataInd));
      match_out.set_size(1, match_idx + 1);
      for (i = 0; i <= match_idx; i++) {
        match_out[i] = static_cast<int>(static_cast<double>(dataInd) +
                                        static_cast<double>(i));
      }
      coder::internal::nullAssignment(pulseArray, match_out);
      text_len = static_cast<int>(static_cast<double>(commandArray.size(0)) -
                                  static_cast<double>(commandInd));
      match_out.set_size(1, text_len + 1);
      for (i = 0; i <= text_len; i++) {
        match_out[i] = static_cast<int>(static_cast<double>(commandInd) +
                                        static_cast<double>(i));
      }
      coder::internal::b_nullAssignment(commandArray, match_out);
      match_out.set_size(1, match_idx + 1);
      for (i = 0; i <= match_idx; i++) {
        match_out[i] = static_cast<int>(static_cast<double>(dataInd) +
                                        static_cast<double>(i));
      }
      coder::internal::nullAssignment(pulseLineNums, match_out);
      pulseLineNums.set_size(commandLineNums.size(0));
      match_idx = commandLineNums.size(0);
      for (i = 0; i < match_idx; i++) {
        pulseLineNums[i] = commandLineNums[i];
      }
      match_out.set_size(1, text_len + 1);
      for (i = 0; i <= text_len; i++) {
        match_out[i] = static_cast<int>(static_cast<double>(commandInd) +
                                        static_cast<double>(i));
      }
      coder::internal::nullAssignment(pulseLineNums, match_out);
      coder::internal::cfclose(static_cast<double>(fid));
      //  Now format for table output
      b_pulseArray.set_size(pulseArray.size(0));
      match_idx = pulseArray.size(0);
      for (i = 0; i < match_idx; i++) {
        b_pulseArray[i] = (pulseArray[i + pulseArray.size(0) * 5] <= 0.0);
      }
      coder::eml_find(b_pulseArray, ii);
      b_pulseArray.set_size(pulseArray.size(0));
      match_idx = pulseArray.size(0);
      for (i = 0; i < match_idx; i++) {
        b_pulseArray[i] = (pulseArray[i + pulseArray.size(0) * 5] == rtInf);
      }
      coder::eml_find(b_pulseArray, b_ii);
      b_pulseArray.set_size(pulseArray.size(0));
      match_idx = pulseArray.size(0);
      for (i = 0; i < match_idx; i++) {
        b_pulseArray[i] =
            (pulseArray[i + pulseArray.size(0) * 5] == rtMinusInf);
      }
      coder::eml_find(b_pulseArray, c_ii);
      // Command has the ASL alt when command was issued.
      if (commandArray.size(0) < 1) {
        rtDynamicBoundsError(1, 1, commandArray.size(0), g_emlrtBCI);
      }
      commandLineNums.set_size((ii.size(0) + b_ii.size(0)) + c_ii.size(0));
      match_idx = ii.size(0);
      for (i = 0; i < match_idx; i++) {
        commandLineNums[i] = ii[i];
      }
      match_idx = b_ii.size(0);
      for (i = 0; i < match_idx; i++) {
        commandLineNums[i + ii.size(0)] = b_ii[i];
      }
      match_idx = c_ii.size(0);
      for (i = 0; i < match_idx; i++) {
        commandLineNums[(i + ii.size(0)) + b_ii.size(0)] = c_ii[i];
      }
      coder::unique_vector(commandLineNums, pulseLineNums);
      ii.set_size(pulseLineNums.size(0));
      match_idx = pulseLineNums.size(0);
      for (i = 0; i < match_idx; i++) {
        ii[i] = static_cast<int>(pulseLineNums[i]);
      }
      coder::internal::nullAssignment(pulseArray, ii);
      // latMean = mean(lat);
      // lonMean = mean(lon);
      // origin = [latMean, lonMean];
      c_pulseArray.set_size(pulseArray.size(0), 4);
      match_idx = pulseArray.size(0);
      for (i = 0; i < 4; i++) {
        for (text_len = 0; text_len < match_idx; text_len++) {
          c_pulseArray[text_len + c_pulseArray.size(0) * i] =
              pulseArray[text_len + pulseArray.size(0) * iv[i]];
        }
      }
      coder::quat2eul(c_pulseArray, eul_deg);
      match_idx = eul_deg.size(0) * 3;
      eul_deg.set_size(eul_deg.size(0), 3);
      for (i = 0; i < match_idx; i++) {
        eul_deg[i] = 57.295779513082323 * eul_deg[i];
      }
      // Following the 3-2-1 rotation (z-y'-x'') rotation sequence
      if (pulseArray.size(0) < 1) {
        rtDynamicBoundsError(1, 1, pulseArray.size(0), h_emlrtBCI);
      }
      numOfLines = commandArray[commandArray.size(0) * 3] -
                   pulseArray[pulseArray.size(0) * 14];
      commandLineNums.set_size(pulseArray.size(0));
      match_idx = pulseArray.size(0);
      pulseLineNums.set_size(pulseArray.size(0));
      d_pulseArray.set_size(pulseArray.size(0));
      e_pulseArray.set_size(pulseArray.size(0));
      for (i = 0; i < match_idx; i++) {
        commandLineNums[i] = pulseArray[i + pulseArray.size(0) * 12];
        pulseLineNums[i] = pulseArray[i + pulseArray.size(0) * 13];
        emptyLineCounter = pulseArray[i + pulseArray.size(0) * 14];
        d_pulseArray[i] = emptyLineCounter + numOfLines;
        e_pulseArray[i] = emptyLineCounter;
      }
      PositionStruct(commandLineNums, pulseLineNums, d_pulseArray, e_pulseArray,
                     positions);
      // EULERANGLESTRUCT Generates a Euler Angle structure
      //    This function generates a standard Euler angle structure with the
      //    following fields:
      //
      //    roll_deg    Roll angle in degrees
      //    pitch_deg   Pitch angle in degrees
      //    yaw_deg     Yaw angle in degrees
      //    If input vectors are provided, they must be the same size size. In
      //    that case, the output is a vector of structures.
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
      eulers_deg.set_size(1, 1);
      eulers_deg[0].yaw_deg = 0.0;
      // eul(nRows,nCols) = eul; %Coder doesn't like this
      match_idx = eulers_deg.size(0) * eulers_deg.size(1) - 1;
      for (i = 0; i <= match_idx; i++) {
        eulInit = eulers_deg[i];
      }
      coder::repmat((const d_struct_T *)&eulInit,
                    static_cast<double>(eul_deg.size(0)), eulers_deg);
      i = eul_deg.size(0);
      for (int b_i{0}; b_i < i; b_i++) {
        if (b_i + 1 > eul_deg.size(0)) {
          rtDynamicBoundsError(b_i + 1, 1, eul_deg.size(0), i_emlrtBCI);
        }
        if (b_i + 1 > eulers_deg.size(0)) {
          rtDynamicBoundsError(b_i + 1, 1, eulers_deg.size(0), j_emlrtBCI);
        }
        if (b_i + 1 > eul_deg.size(0)) {
          rtDynamicBoundsError(b_i + 1, 1, eul_deg.size(0), k_emlrtBCI);
        }
        if (b_i + 1 > eulers_deg.size(0)) {
          rtDynamicBoundsError(b_i + 1, 1, eulers_deg.size(0), l_emlrtBCI);
        }
        if (b_i + 1 > eul_deg.size(0)) {
          rtDynamicBoundsError(b_i + 1, 1, eul_deg.size(0), m_emlrtBCI);
        }
        if (b_i + 1 > eulers_deg.size(0)) {
          rtDynamicBoundsError(b_i + 1, 1, eulers_deg.size(0), n_emlrtBCI);
        }
        eulers_deg[b_i].yaw_deg = eul_deg[b_i];
      }
      commandLineNums.set_size(pulseArray.size(0));
      match_idx = pulseArray.size(0);
      pulseLineNums.set_size(pulseArray.size(0));
      d_pulseArray.set_size(pulseArray.size(0));
      e_pulseArray.set_size(pulseArray.size(0));
      for (i = 0; i < match_idx; i++) {
        commandLineNums[i] = pulseArray[i + pulseArray.size(0) * 3];
        pulseLineNums[i] = pulseArray[i + pulseArray.size(0) * 5];
        d_pulseArray[i] = pulseArray[i + pulseArray.size(0) * 2] / 1.0E+6;
        e_pulseArray[i] = pulseArray[i + pulseArray.size(0)];
      }
      PulseStruct(positions, eulers_deg, commandLineNums, pulseLineNums,
                  d_pulseArray, e_pulseArray, pulses);
      commandLineNums.set_size(commandArray.size(0));
      match_idx = commandArray.size(0);
      pulseLineNums.set_size(commandArray.size(0));
      d_pulseArray.set_size(commandArray.size(0));
      e_pulseArray.set_size(commandArray.size(0));
      for (i = 0; i < match_idx; i++) {
        commandLineNums[i] = commandArray[i + commandArray.size(0)];
        pulseLineNums[i] = commandArray[i + commandArray.size(0) * 2];
        emptyLineCounter = commandArray[i + commandArray.size(0) * 3];
        d_pulseArray[i] = emptyLineCounter;
        e_pulseArray[i] = emptyLineCounter - numOfLines;
      }
      PositionStruct(commandLineNums, pulseLineNums, d_pulseArray, e_pulseArray,
                     positions);
      // COMMANDSTRUCT Generates a command structure
      //    This function generates a standard command structure with the
      //    following fields:
      //
      //    commandID    CommandID
      //    position     Position (PositionStruct)
      //    If input vectors are provided, they must be the same size size. In
      //    that case, the output is a vector of position structures.
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
      //    If input vectors are provided, they must be the same size size. In
      //    that case, the output is a vector of position structures.
      //
      // INPUTS:
      //    lat    -   n x 1 vector of doubles of latitudes
      //    lon    -   n x 1 vector of doubles of longitudes
      //    altAbs -   n x 1 vector of doubles of altitudes above sea level in
      //               meters
      //    altRel -   n x 1 vector of doubles of altitudes above ground level
      //    in
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
      commands.set_size(1, 1);
      c_x[0] = (positions.size(0) == commandArray.size(0));
      c_x[1] = true;
      b_bool = true;
      text_len = 0;
      exitg2 = false;
      while ((!exitg2) && (text_len < 2)) {
        if (!c_x[text_len]) {
          b_bool = false;
          exitg2 = true;
        } else {
          text_len++;
        }
      }
      if (!b_bool) {
        std::printf("UAV-RT: All inputs must be the same size. ");
        std::fflush(stdout);
      } else {
        // command(nRows,nCols) = command; %Coder doesn't like this
        coder::repmat(static_cast<double>(positions.size(0)), commands);
        i = positions.size(0);
        for (int b_i{0}; b_i < i; b_i++) {
          if (b_i + 1 > commands.size(0)) {
            rtDynamicBoundsError(b_i + 1, 1, commands.size(0), o_emlrtBCI);
          }
          if (b_i + 1 > commands.size(0)) {
            rtDynamicBoundsError(b_i + 1, 1, commands.size(0), o_emlrtBCI);
          }
          if (b_i + 1 > commands.size(0)) {
            rtDynamicBoundsError(b_i + 1, 1, commands.size(0), o_emlrtBCI);
          }
          if (b_i + 1 > positions.size(0)) {
            rtDynamicBoundsError(b_i + 1, 1, positions.size(0), p_emlrtBCI);
          }
          // command(i,j).time     = time(i,j);
          if (b_i + 1 > commands.size(0)) {
            rtDynamicBoundsError(b_i + 1, 1, commands.size(0), q_emlrtBCI);
          }
          if (b_i + 1 > commandArray.size(0)) {
            rtDynamicBoundsError(b_i + 1, 1, commandArray.size(0), r_emlrtBCI);
          }
        }
      }
      exitg1 = 1;
    }
  } while (exitg1 == 0);
}

//
// File trailer for readpulsecsv.cpp
//
// [EOF]
//
