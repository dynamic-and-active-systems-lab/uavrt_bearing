//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: readpulsecsv.cpp
//
// MATLAB Coder version            : 5.6
// C/C++ source code generated on  : 02-Oct-2023 13:02:17
//

// Include Files
#include "readpulsecsv.h"
#include "CommandStruct.h"
#include "PositionStruct.h"
#include "PulseStruct.h"
#include "anonymous_function.h"
#include "bearing_data.h"
#include "bearing_internal_types.h"
#include "bearing_rtwutil.h"
#include "bearing_types.h"
#include "cleancsv.h"
#include "eml_int_forloop_overflow_check.h"
#include "feof.h"
#include "fgetl.h"
#include "fgets.h"
#include "fileManager.h"
#include "find.h"
#include "fscanf.h"
#include "fseek.h"
#include "ftell.h"
#include "nullAssignment.h"
#include "onCleanup.h"
#include "repmat.h"
#include "rt_nonfinite.h"
#include "str2double.h"
#include "strcmp.h"
#include "unique.h"
#include "coder_array.h"
#include "coder_bounded_array.h"
#include <cmath>
#include <cstdio>
#include <sstream>
#include <stdexcept>
#include <string>

// Function Declarations
static std::string rtGenSizeString(const int &aDims);

static void rtSubAssignSizeCheck(const int &aDims1, const int &aDims2,
                                 const rtEqualityCheckInfo &aInfo);

// Function Definitions
//
// Arguments    : const int &aDims
// Return Type  : std::string
//
static std::string rtGenSizeString(const int &aDims)
{
  std::stringstream outStream;
  for (int i{0}; i < 2; i++) {
    outStream << "[";
    outStream << (&aDims)[i];
    outStream << "]";
  }
  return outStream.str();
}

//
// Arguments    : const int &aDims1
//                const int &aDims2
//                const rtEqualityCheckInfo &aInfo
// Return Type  : void
//
static void rtSubAssignSizeCheck(const int &aDims1, const int &aDims2,
                                 const rtEqualityCheckInfo &aInfo)
{
  std::stringstream outStream;
  int i;
  int j;
  i = 0;
  j = 0;
  while ((i < 2) && (j < 2)) {
    while ((i < 2) && ((&aDims1)[i] == 1)) {
      i++;
    }
    while ((j < 2) && ((&aDims2)[j] == 1)) {
      j++;
    }
    if (((i < 2) || (j < 2)) &&
        ((i == 2) || ((j == 2) || (((&aDims1)[i] != -1) &&
                                   (((&aDims2)[j] != -1) &&
                                    ((&aDims1)[i] != (&aDims2)[j])))))) {
      std::string dims1Str;
      std::string dims2Str;
      dims1Str = rtGenSizeString(aDims1);
      dims2Str = rtGenSizeString(aDims2);
      ((((outStream << "Subscripted assignment dimension mismatch: ")
         << dims1Str)
        << " ~= ")
       << dims2Str)
          << ".";
      outStream << "\n";
      ((((outStream << "Error in ") << aInfo.fName) << " (line ")
       << aInfo.lineNo)
          << ")";
      throw std::runtime_error(outStream.str());
    }
    i++;
    j++;
  }
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
      -1,             // iFirst
      -1,             // iLast
      111,            // lineNo
      28,             // colNo
      "lineStr",      // aName
      "readpulsecsv", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/readpulsecsv.m", // pName
      0                                               // checkKind
  };
  static rtBoundsCheckInfo c_emlrtBCI{
      -1,               // iFirst
      -1,               // iLast
      113,              // lineNo
      61,               // colNo
      "commaLocations", // aName
      "readpulsecsv",   // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/readpulsecsv.m", // pName
      0                                               // checkKind
  };
  static rtBoundsCheckInfo d_emlrtBCI{
      -1,             // iFirst
      -1,             // iLast
      127,            // lineNo
      28,             // colNo
      "pulseArray",   // aName
      "readpulsecsv", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/readpulsecsv.m", // pName
      0                                               // checkKind
  };
  static rtBoundsCheckInfo e_emlrtBCI{
      -1,             // iFirst
      -1,             // iLast
      133,            // lineNo
      30,             // colNo
      "commandArray", // aName
      "readpulsecsv", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/readpulsecsv.m", // pName
      0                                               // checkKind
  };
  static rtBoundsCheckInfo f_emlrtBCI{
      -1,             // iFirst
      -1,             // iLast
      113,            // lineNo
      41,             // colNo
      "lineStr",      // aName
      "readpulsecsv", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/readpulsecsv.m", // pName
      0                                               // checkKind
  };
  static rtBoundsCheckInfo g_emlrtBCI{
      -1,             // iFirst
      -1,             // iLast
      113,            // lineNo
      46,             // colNo
      "lineStr",      // aName
      "readpulsecsv", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/readpulsecsv.m", // pName
      0                                               // checkKind
  };
  static rtBoundsCheckInfo h_emlrtBCI{
      -1,             // iFirst
      -1,             // iLast
      244,            // lineNo
      57,             // colNo
      "pos_AGL_m",    // aName
      "readpulsecsv", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/readpulsecsv.m", // pName
      0                                               // checkKind
  };
  static rtBoundsCheckInfo i_emlrtBCI{
      -1,                 // iFirst
      -1,                 // iLast
      56,                 // lineNo
      39,                 // colNo
      "roll",             // aName
      "EulerAngleStruct", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/EulerAngleStruct.m", // pName
      0                                                   // checkKind
  };
  static rtBoundsCheckInfo j_emlrtBCI{
      -1,                 // iFirst
      -1,                 // iLast
      56,                 // lineNo
      17,                 // colNo
      "eul",              // aName
      "EulerAngleStruct", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/EulerAngleStruct.m", // pName
      0                                                   // checkKind
  };
  static rtBoundsCheckInfo k_emlrtBCI{
      -1,                 // iFirst
      -1,                 // iLast
      57,                 // lineNo
      40,                 // colNo
      "pitch",            // aName
      "EulerAngleStruct", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/EulerAngleStruct.m", // pName
      0                                                   // checkKind
  };
  static rtBoundsCheckInfo l_emlrtBCI{
      -1,                 // iFirst
      -1,                 // iLast
      57,                 // lineNo
      17,                 // colNo
      "eul",              // aName
      "EulerAngleStruct", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/EulerAngleStruct.m", // pName
      0                                                   // checkKind
  };
  static rtBoundsCheckInfo m_emlrtBCI{
      -1,                 // iFirst
      -1,                 // iLast
      58,                 // lineNo
      38,                 // colNo
      "yaw",              // aName
      "EulerAngleStruct", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/EulerAngleStruct.m", // pName
      0                                                   // checkKind
  };
  static rtBoundsCheckInfo n_emlrtBCI{
      -1,                 // iFirst
      -1,                 // iLast
      58,                 // lineNo
      17,                 // colNo
      "eul",              // aName
      "EulerAngleStruct", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/EulerAngleStruct.m", // pName
      0                                                   // checkKind
  };
  static rtDoubleCheckInfo b_emlrtDCI{
      98,             // lineNo
      29,             // colNo
      "readpulsecsv", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/readpulsecsv.m", // pName
      4                                               // checkKind
  };
  static rtDoubleCheckInfo c_emlrtDCI{
      98,             // lineNo
      29,             // colNo
      "readpulsecsv", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/readpulsecsv.m", // pName
      1                                               // checkKind
  };
  static rtDoubleCheckInfo d_emlrtDCI{
      98,             // lineNo
      5,              // colNo
      "readpulsecsv", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/readpulsecsv.m", // pName
      1                                               // checkKind
  };
  static rtDoubleCheckInfo e_emlrtDCI{
      99,             // lineNo
      5,              // colNo
      "readpulsecsv", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/readpulsecsv.m", // pName
      1                                               // checkKind
  };
  static rtDoubleCheckInfo f_emlrtDCI{
      100,            // lineNo
      29,             // colNo
      "readpulsecsv", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/readpulsecsv.m", // pName
      1                                               // checkKind
  };
  static rtDoubleCheckInfo g_emlrtDCI{
      100,            // lineNo
      5,              // colNo
      "readpulsecsv", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/readpulsecsv.m", // pName
      1                                               // checkKind
  };
  static rtDoubleCheckInfo h_emlrtDCI{
      101,            // lineNo
      5,              // colNo
      "readpulsecsv", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/readpulsecsv.m", // pName
      1                                               // checkKind
  };
  static rtEqualityCheckInfo b_emlrtECI{
      -1,             // nDims
      133,            // lineNo
      17,             // colNo
      "readpulsecsv", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/readpulsecsv.m" // pName
  };
  static rtEqualityCheckInfo emlrtECI{
      -1,             // nDims
      127,            // lineNo
      17,             // colNo
      "readpulsecsv", // fName
      "/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/"
      "CODE_PLAYGROUND/uavrt_bearing/readpulsecsv.m" // pName
  };
  coder::onCleanup x;
  coder::array<d_struct_T, 2U> eulers_deg;
  coder::array<struct_T, 2U> positions;
  coder::array<double, 2U> commandArray;
  coder::array<double, 2U> pulseArray;
  coder::array<double, 1U> c_pulseArray;
  coder::array<double, 1U> commandLineNums;
  coder::array<double, 1U> d_pulseArray;
  coder::array<double, 1U> e_pulseArray;
  coder::array<double, 1U> f_pulseArray;
  coder::array<double, 1U> g_pulseArray;
  coder::array<double, 1U> h_pulseArray;
  coder::array<double, 1U> i_pulseArray;
  coder::array<double, 1U> j_pulseArray;
  coder::array<double, 1U> k_pulseArray;
  coder::array<double, 1U> l_pulseArray;
  coder::array<double, 1U> pulseLineNums;
  coder::array<unsigned int, 2U> commaLocations;
  coder::array<int, 2U> match_out;
  coder::array<int, 2U> matches;
  coder::array<int, 1U> b_ii;
  coder::array<int, 1U> c_ii;
  coder::array<int, 1U> ii;
  coder::array<char, 2U> b_fid;
  coder::array<char, 2U> b_lineStr;
  coder::array<char, 2U> c_fid;
  coder::array<char, 2U> lineStr;
  coder::array<boolean_T, 1U> b_pulseArray;
  d_struct_T eulInit;
  e_struct_T pulseInit;
  struct_T posInit;
  double tmp_data[20];
  double b_tmp_data[4];
  int fid;
  signed char fileid;
  boolean_T b;
  // Initialize outputs so they are defined for all exectution paths.
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
  b = coder::internal::b_strcmp(filepath);
  if (b) {
    e_rtErrorWithMessageID(d_emlrtRTEI.fName, d_emlrtRTEI.lineNo);
  } else {
    fileid = coder::internal::cfopen(filepath, "rb");
    fid = fileid;
  }
  if (fid == -1) {
    std::printf("UAV-RT: Error opening the bearing csv file. Returning empty "
                "pulse and command listings. ");
    std::fflush(stdout);
  } else {
    double b_x;
    double emptyLineCounter;
    double numOfLines;
    unsigned int commandInd;
    unsigned int dataInd;
    int exitg1;
    int i;
    int match_idx;
    signed char b_fileid;
    // Close clean out any bad data, then reopen
    coder::internal::cfclose(static_cast<double>(fid));
    cleancsv(filepath);
    fileid = coder::internal::cfopen(filepath, "rb");
    // d for delimiter
    // COUNTLINES counts the number of lines in a csv file
    //    This function reads in a CSV file and returns to total number of lines
    //    in the file.
    //    Based on
    //    https://stackoverflow.com/questions/12176519/is-there-a-way-in-matlab-to-determine-the-number-of-lines-in-a-file-without-loop
    //    Updated to not count multiple new lines after valid text in a line
    //    Also uses fgetl to read lines so the final line doesn't need a final
    //    \n character to get counted.
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
    b_fileid = coder::internal::cfopen(filepath, "rb");
    x.task.workspace.fid = b_fileid;
    x.matlabCodegenIsDeleted = false;
    numOfLines = 0.0;
    //  while ~feof(fid)
    //      count = count + sum( fread( fid, 16384, 'char' ) == char(10) );
    //  end
    emptyLineCounter = 0.0;
    do {
      exitg1 = 0;
      b_x = coder::b_feof(static_cast<double>(b_fileid));
      if (std::isnan(b_x)) {
        d_rtErrorWithMessageID(c_emlrtRTEI.fName, c_emlrtRTEI.lineNo);
      }
      if (!(b_x != 0.0)) {
        coder::fgetl(static_cast<double>(b_fileid), lineStr);
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
      rtNonNegativeError(numOfLines, b_emlrtDCI);
    }
    if (numOfLines != static_cast<int>(numOfLines)) {
      rtIntegerError(numOfLines, c_emlrtDCI);
    }
    fid = static_cast<int>(numOfLines);
    pulseArray.set_size(static_cast<int>(numOfLines), 20);
    if (numOfLines != static_cast<int>(numOfLines)) {
      rtIntegerError(numOfLines, d_emlrtDCI);
    }
    match_idx = static_cast<int>(numOfLines) * 20;
    for (i = 0; i < match_idx; i++) {
      pulseArray[i] = 0.0;
    }
    if (numOfLines != static_cast<int>(numOfLines)) {
      rtIntegerError(numOfLines, e_emlrtDCI);
    }
    pulseLineNums.set_size(static_cast<int>(numOfLines));
    if (numOfLines != static_cast<int>(numOfLines)) {
      rtIntegerError(numOfLines, e_emlrtDCI);
    }
    for (i = 0; i < fid; i++) {
      pulseLineNums[i] = 0.0;
    }
    if (numOfLines != static_cast<int>(numOfLines)) {
      rtIntegerError(numOfLines, f_emlrtDCI);
    }
    commandArray.set_size(static_cast<int>(numOfLines), 4);
    if (numOfLines != static_cast<int>(numOfLines)) {
      rtIntegerError(numOfLines, g_emlrtDCI);
    }
    match_idx = static_cast<int>(numOfLines) << 2;
    for (i = 0; i < match_idx; i++) {
      commandArray[i] = 0.0;
    }
    if (numOfLines != static_cast<int>(numOfLines)) {
      rtIntegerError(numOfLines, h_emlrtDCI);
    }
    commandLineNums.set_size(static_cast<int>(numOfLines));
    if (numOfLines != static_cast<int>(numOfLines)) {
      rtIntegerError(numOfLines, h_emlrtDCI);
    }
    for (i = 0; i < fid; i++) {
      commandLineNums[i] = 0.0;
    }
    emptyLineCounter = 1.0;
    numOfLines = coder::b_ftell(static_cast<double>(fileid));
    dataInd = 1U;
    commandInd = 1U;
    do {
      exitg1 = 0;
      b_x = coder::b_feof(static_cast<double>(fileid));
      if (std::isnan(b_x)) {
        d_rtErrorWithMessageID(c_emlrtRTEI.fName, c_emlrtRTEI.lineNo);
      }
      if (!(b_x != 0.0)) {
        boolean_T guard1{false};
        coder::fgetl(static_cast<double>(fileid), lineStr);
        if (lineStr.size(1) < 1) {
          rtDynamicBoundsError(1, 1, lineStr.size(1), b_emlrtBCI);
        }
        guard1 = false;
        if (lineStr[0] != '#') {
          creal_T commandID;
          if (lineStr.size(1) == 0) {
            commaLocations.set_size(1, 0);
          } else {
            fid = lineStr.size(1);
            matches.set_size(1, lineStr.size(1));
            match_idx = 0;
            if (lineStr.size(1) > 2147483646) {
              coder::check_forloop_overflow_error();
            }
            for (int b_i{0}; b_i < fid; b_i++) {
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
            fid = match_out.size(1);
            for (i = 0; i < fid; i++) {
              commaLocations[i] = static_cast<unsigned int>(match_out[i]);
            }
          }
          if (commaLocations.size(1) < 1) {
            rtDynamicBoundsError(1, 1, commaLocations.size(1), c_emlrtBCI);
          }
          fid = static_cast<int>(commaLocations[0]) - 1;
          if (fid < 1) {
            fid = 0;
          } else {
            if (lineStr.size(1) < 1) {
              rtDynamicBoundsError(1, 1, lineStr.size(1), f_emlrtBCI);
            }
            if (fid > lineStr.size(1)) {
              rtDynamicBoundsError(fid, 1, lineStr.size(1), g_emlrtBCI);
            }
          }
          b_lineStr.set_size(1, fid);
          for (i = 0; i < fid; i++) {
            b_lineStr[i] = lineStr[i];
          }
          commandID = coder::internal::str2double(b_lineStr);
          numOfLines = coder::cfseek(static_cast<double>(fileid), numOfLines);
          if (std::isnan(numOfLines)) {
            d_rtErrorWithMessageID(c_emlrtRTEI.fName, c_emlrtRTEI.lineNo);
          }
          if (!(numOfLines != 0.0)) {
            if ((commandID.re == 7.0) && (commandID.im == 0.0)) {
              int lineStr_size[2];
              int tmp_size[2];
              b = ((static_cast<int>(dataInd) < 1) ||
                   (static_cast<int>(dataInd) > pulseArray.size(0)));
              if (b) {
                rtDynamicBoundsError(static_cast<int>(dataInd), 1,
                                     pulseArray.size(0), d_emlrtBCI);
              }
              coder::b_fscanf(static_cast<double>(fileid), tmp_data, tmp_size);
              lineStr_size[0] = 1;
              lineStr_size[1] = 20;
              rtSubAssignSizeCheck(lineStr_size[0], tmp_size[0], emlrtECI);
              for (i = 0; i < 20; i++) {
                pulseArray[(static_cast<int>(dataInd) +
                            pulseArray.size(0) * i) -
                           1] = tmp_data[i];
              }
              coder::fgetl(static_cast<double>(fileid), c_fid);
              pulseLineNums[static_cast<int>(dataInd) - 1] = emptyLineCounter;
              dataInd++;
            } else if (((commandID.re == 10.0) && (commandID.im == 0.0)) ||
                       ((commandID.re == 11.0) && (commandID.im == 0.0))) {
              int lineStr_size[2];
              int tmp_size[2];
              b = ((static_cast<int>(commandInd) < 1) ||
                   (static_cast<int>(commandInd) > commandArray.size(0)));
              if (b) {
                rtDynamicBoundsError(static_cast<int>(commandInd), 1,
                                     commandArray.size(0), e_emlrtBCI);
              }
              coder::c_fscanf(static_cast<double>(fileid), b_tmp_data,
                              tmp_size);
              lineStr_size[0] = 1;
              lineStr_size[1] = 4;
              rtSubAssignSizeCheck(lineStr_size[0], tmp_size[0], b_emlrtECI);
              commandArray[static_cast<int>(commandInd) - 1] = b_tmp_data[0];
              commandArray[(static_cast<int>(commandInd) +
                            commandArray.size(0)) -
                           1] = b_tmp_data[1];
              commandArray[(static_cast<int>(commandInd) +
                            commandArray.size(0) * 2) -
                           1] = b_tmp_data[2];
              commandArray[(static_cast<int>(commandInd) +
                            commandArray.size(0) * 3) -
                           1] = b_tmp_data[3];
              commandLineNums[static_cast<int>(commandInd) - 1] =
                  emptyLineCounter;
              commandInd++;
            } else {
              coder::b_fgets(static_cast<double>(fileid), b_fid);
              //  Discard if not commandID 7, 10, or 11
            }
            guard1 = true;
          } else {
            std::printf("UAV-RT: Error with file rewind");
            std::fflush(stdout);
            coder::internal::cfclose(static_cast<double>(fileid));
            exitg1 = 1;
          }
        } else {
          guard1 = true;
        }
        if (guard1) {
          emptyLineCounter++;
          numOfLines = coder::b_ftell(static_cast<double>(fileid));
        }
      } else {
        fid = static_cast<int>(static_cast<double>(pulseArray.size(0)) -
                               static_cast<double>(dataInd));
        match_out.set_size(1, fid + 1);
        for (i = 0; i <= fid; i++) {
          match_out[i] = static_cast<int>(static_cast<double>(dataInd) +
                                          static_cast<double>(i));
        }
        coder::internal::nullAssignment(pulseArray, match_out);
        match_idx = static_cast<int>(static_cast<double>(commandArray.size(0)) -
                                     static_cast<double>(commandInd));
        match_out.set_size(1, match_idx + 1);
        for (i = 0; i <= match_idx; i++) {
          match_out[i] = static_cast<int>(static_cast<double>(commandInd) +
                                          static_cast<double>(i));
        }
        coder::internal::b_nullAssignment(commandArray, match_out);
        match_out.set_size(1, fid + 1);
        for (i = 0; i <= fid; i++) {
          match_out[i] = static_cast<int>(static_cast<double>(dataInd) +
                                          static_cast<double>(i));
        }
        coder::internal::nullAssignment(pulseLineNums, match_out);
        pulseLineNums.set_size(commandLineNums.size(0));
        fid = commandLineNums.size(0);
        for (i = 0; i < fid; i++) {
          pulseLineNums[i] = commandLineNums[i];
        }
        match_out.set_size(1, match_idx + 1);
        for (i = 0; i <= match_idx; i++) {
          match_out[i] = static_cast<int>(static_cast<double>(commandInd) +
                                          static_cast<double>(i));
        }
        coder::internal::nullAssignment(pulseLineNums, match_out);
        coder::internal::cfclose(static_cast<double>(fileid));
        //     %% Now format for table output
        b_pulseArray.set_size(pulseArray.size(0));
        fid = pulseArray.size(0);
        for (i = 0; i < fid; i++) {
          b_pulseArray[i] = (pulseArray[i + pulseArray.size(0) * 5] <= 0.0);
        }
        coder::eml_find(b_pulseArray, ii);
        b_pulseArray.set_size(pulseArray.size(0));
        fid = pulseArray.size(0);
        for (i = 0; i < fid; i++) {
          b_pulseArray[i] = (pulseArray[i + pulseArray.size(0) * 5] == rtInf);
        }
        coder::eml_find(b_pulseArray, b_ii);
        b_pulseArray.set_size(pulseArray.size(0));
        fid = pulseArray.size(0);
        for (i = 0; i < fid; i++) {
          b_pulseArray[i] =
              (pulseArray[i + pulseArray.size(0) * 5] == rtMinusInf);
        }
        coder::eml_find(b_pulseArray, c_ii);
        // Command has the ASL alt when command was issued.
        if (commandArray.size(0) != 0) {
          numOfLines = commandArray[commandArray.size(0) * 3];
        } else {
          numOfLines = rtNaN;
        }
        commandLineNums.set_size((ii.size(0) + b_ii.size(0)) + c_ii.size(0));
        fid = ii.size(0);
        for (i = 0; i < fid; i++) {
          commandLineNums[i] = ii[i];
        }
        fid = b_ii.size(0);
        for (i = 0; i < fid; i++) {
          commandLineNums[i + ii.size(0)] = b_ii[i];
        }
        fid = c_ii.size(0);
        for (i = 0; i < fid; i++) {
          commandLineNums[(i + ii.size(0)) + b_ii.size(0)] = c_ii[i];
        }
        coder::unique_vector(commandLineNums, pulseLineNums);
        ii.set_size(pulseLineNums.size(0));
        fid = pulseLineNums.size(0);
        for (i = 0; i < fid; i++) {
          ii[i] = static_cast<int>(pulseLineNums[i]);
        }
        coder::internal::nullAssignment(pulseArray, ii);
        // latMean = mean(lat);
        // lonMean = mean(lon);
        // origin = [latMean, lonMean];
        // quat = pulseArray(:,[orientation_w_col, orientation_x_col,
        // orientation_y_col, orientation_z_col]); eul_deg = 180/pi *
        // quat2eul(quat); Following the 3-2-1 rotation (z-y'-x'') rotation
        // sequence
        //  yaw_deg = eul_deg(:,1);
        //  pitch_deg = eul_deg(:,2);
        //  roll_deg = eul_deg(:,3);
        if (pulseArray.size(0) < 1) {
          rtDynamicBoundsError(1, 1, pulseArray.size(0), h_emlrtBCI);
        }
        numOfLines -= pulseArray[pulseArray.size(0) * 15];
        commandLineNums.set_size(pulseArray.size(0));
        fid = pulseArray.size(0);
        c_pulseArray.set_size(pulseArray.size(0));
        d_pulseArray.set_size(pulseArray.size(0));
        e_pulseArray.set_size(pulseArray.size(0));
        for (i = 0; i < fid; i++) {
          commandLineNums[i] = pulseArray[i + pulseArray.size(0) * 13];
          c_pulseArray[i] = pulseArray[i + pulseArray.size(0) * 14];
          emptyLineCounter = pulseArray[i + pulseArray.size(0) * 15];
          d_pulseArray[i] = emptyLineCounter + numOfLines;
          e_pulseArray[i] = emptyLineCounter;
        }
        PositionStruct(commandLineNums, c_pulseArray, d_pulseArray,
                       e_pulseArray, positions);
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
        fid = eulers_deg.size(0) * eulers_deg.size(1) - 1;
        for (i = 0; i <= fid; i++) {
          eulInit = eulers_deg[i];
        }
        coder::repmat((const d_struct_T *)&eulInit,
                      static_cast<double>(pulseArray.size(0)), eulers_deg);
        i = pulseArray.size(0);
        for (int b_i{0}; b_i < i; b_i++) {
          if (b_i + 1 > pulseArray.size(0)) {
            rtDynamicBoundsError(b_i + 1, 1, pulseArray.size(0), i_emlrtBCI);
          }
          if (b_i + 1 > eulers_deg.size(0)) {
            rtDynamicBoundsError(b_i + 1, 1, eulers_deg.size(0), j_emlrtBCI);
          }
          if (b_i + 1 > pulseArray.size(0)) {
            rtDynamicBoundsError(b_i + 1, 1, pulseArray.size(0), k_emlrtBCI);
          }
          if (b_i + 1 > eulers_deg.size(0)) {
            rtDynamicBoundsError(b_i + 1, 1, eulers_deg.size(0), l_emlrtBCI);
          }
          if (b_i + 1 > pulseArray.size(0)) {
            rtDynamicBoundsError(b_i + 1, 1, pulseArray.size(0), m_emlrtBCI);
          }
          if (b_i + 1 > eulers_deg.size(0)) {
            rtDynamicBoundsError(b_i + 1, 1, eulers_deg.size(0), n_emlrtBCI);
          }
          eulers_deg[b_i].yaw_deg = pulseArray[b_i + pulseArray.size(0) * 18];
        }
        commandLineNums.set_size(pulseArray.size(0));
        fid = pulseArray.size(0);
        c_pulseArray.set_size(pulseArray.size(0));
        d_pulseArray.set_size(pulseArray.size(0));
        e_pulseArray.set_size(pulseArray.size(0));
        pulseLineNums.set_size(pulseArray.size(0));
        f_pulseArray.set_size(pulseArray.size(0));
        g_pulseArray.set_size(pulseArray.size(0));
        h_pulseArray.set_size(pulseArray.size(0));
        i_pulseArray.set_size(pulseArray.size(0));
        j_pulseArray.set_size(pulseArray.size(0));
        k_pulseArray.set_size(pulseArray.size(0));
        l_pulseArray.set_size(pulseArray.size(0));
        for (i = 0; i < fid; i++) {
          commandLineNums[i] = pulseArray[i + pulseArray.size(0)];
          c_pulseArray[i] = pulseArray[i + pulseArray.size(0) * 2] / 1.0E+6;
          d_pulseArray[i] = pulseArray[i + pulseArray.size(0) * 3];
          e_pulseArray[i] = pulseArray[i + pulseArray.size(0) * 4];
          pulseLineNums[i] = pulseArray[i + pulseArray.size(0) * 5];
          f_pulseArray[i] = pulseArray[i + pulseArray.size(0) * 6];
          g_pulseArray[i] = pulseArray[i + pulseArray.size(0) * 7];
          h_pulseArray[i] = pulseArray[i + pulseArray.size(0) * 8];
          i_pulseArray[i] = pulseArray[i + pulseArray.size(0) * 9];
          j_pulseArray[i] = pulseArray[i + pulseArray.size(0) * 10];
          k_pulseArray[i] = pulseArray[i + pulseArray.size(0) * 11];
          l_pulseArray[i] = pulseArray[i + pulseArray.size(0) * 12];
        }
        PulseStruct(commandLineNums, c_pulseArray, positions, eulers_deg,
                    d_pulseArray, e_pulseArray, pulseLineNums, f_pulseArray,
                    g_pulseArray, h_pulseArray, i_pulseArray, j_pulseArray,
                    k_pulseArray, l_pulseArray, pulses);
        if (commandArray.size(0) != 0) {
          pulseLineNums.set_size(commandArray.size(0));
          fid = commandArray.size(0);
          commandLineNums.set_size(commandArray.size(0));
          c_pulseArray.set_size(commandArray.size(0));
          d_pulseArray.set_size(commandArray.size(0));
          e_pulseArray.set_size(commandArray.size(0));
          for (i = 0; i < fid; i++) {
            pulseLineNums[i] = commandArray[i];
            commandLineNums[i] = commandArray[i + commandArray.size(0)];
            c_pulseArray[i] = commandArray[i + commandArray.size(0) * 2];
            emptyLineCounter = commandArray[i + commandArray.size(0) * 3];
            d_pulseArray[i] = emptyLineCounter;
            e_pulseArray[i] = emptyLineCounter - numOfLines;
          }
          PositionStruct(commandLineNums, c_pulseArray, d_pulseArray,
                         e_pulseArray, positions);
        } else {
          pulseLineNums.set_size(1);
          pulseLineNums[0] = rtNaN;
          // POSITIONSTRUCT Generates a position structure
          //    This function generates a standard position structure with the
          //    following fields:
          //
          //    latitude_deg        Latitude in degrees
          //    latitude_deg        Longitude in degrees
          //    absolute_altitude_m Altitude in meters above ground level
          //    relative_altitude_m Altitude in meters above sea level
          //
          //    If input vectors are provided, they must be the same size size.
          //    In that case, the output is a vector of position structures.
          //
          // INPUTS:
          //    lat    -   n x 1 vector of doubles of latitudes
          //    lon    -   n x 1 vector of doubles of longitudes
          //    altAbs -   n x 1 vector of doubles of altitudes above sea level
          //    in
          //               meters
          //    altRel -   n x 1 vector of doubles of altitudes above ground
          //    level in
          //               meters
          //
          // OUTPUTS:
          //    pos    -   n x 1 vector of position structures
          //
          // --------------------------------------------------------------------------
          //  Author: Michael Shafer
          //  Date: 2023-06-12
          // --------------------------------------------------------------------------
          // pos(nRows,nCols) = pos; %Coder doesn't like this
          posInit.latitude_deg = rtNaN;
          posInit.longitude_deg = rtNaN;
          posInit.absolute_altitude_m = rtNaN;
          posInit.relative_altitude_m = rtNaN;
          //  pos.latitude_deg         = lat;
          //  pos.longitude_deg        = lon;
          //  pos.absolute_altitude_m  = altAbs;
          //  pos.relative_altitude_m  = altRel;
          positions.set_size(1, 1);
          positions[0] = posInit;
        }
        CommandStruct(pulseLineNums, positions, commands);
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
}

//
// File trailer for readpulsecsv.cpp
//
// [EOF]
//
