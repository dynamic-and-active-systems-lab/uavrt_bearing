//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: cleancsv.cpp
//
// MATLAB Coder version            : 23.2
// C/C++ source code generated on  : 07-Nov-2023 14:21:19
//

// Include Files
#include "cleancsv.h"
#include "bearing_data.h"
#include "bearing_rtwutil.h"
#include "bearing_types.h"
#include "fileManager.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdio>

// Function Definitions
//
// CLEANCSV Looks for bad data in a file numeric csv file and inserts -99999
// in those locations that have text but should have a number.
//
// Arguments    : const coder::array<char, 2U> &filePath
// Return Type  : void
//
void cleancsv(const coder::array<char, 2U> &filePath)
{
  static rtRunTimeErrorInfo v_emlrtRTEI{
      86,                     // lineNo
      "compute_str_or_length" // fName
  };
  static const char cv1[6]{'#', 'N', 'A', 'M', 'E', '?'};
  static const char cv2[5]{'-', '9', '9', '9', '9'};
  static const char cv[3]{'a', 'l', 'l'};
  size_t nBytes;
  std::FILE *f;
  std::FILE *filestar;
  coder::array<char, 2U> charRow;
  coder::array<char, 2U> varargin_1;
  coder::array<char, 1U> At;
  int c;
  int fid;
  int in_idx;
  int patt_idx;
  int str_len;
  int tmp_in_idx;
  signed char fileid;
  boolean_T b_bool;
  b_bool = false;
  if (filePath.size(1) == 3) {
    in_idx = 0;
    int exitg1;
    do {
      exitg1 = 0;
      if (in_idx < 3) {
        if (filePath[in_idx] != cv[in_idx]) {
          exitg1 = 1;
        } else {
          in_idx++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  if (b_bool) {
    e_rtErrorWithMessageID(d_emlrtRTEI.fName, d_emlrtRTEI.lineNo);
  } else {
    fileid = coder::internal::cfopen(filePath, "rb");
    fid = fileid;
  }
  // Putting in cell array in case there are others later
  if ((fid == 0) || (fid == 1) || (fid == 2)) {
    c_rtErrorWithMessageID(h_emlrtRTEI.fName, h_emlrtRTEI.lineNo);
  }
  nBytes = sizeof(char);
  f = coder::internal::getfilestar(static_cast<double>(fid), b_bool);
  filestar = f;
  if (f == nullptr) {
    b_rtErrorWithMessageID(i_emlrtRTEI.fName, i_emlrtRTEI.lineNo);
  }
  if ((fid == 0) || (fid == 1) || (fid == 2)) {
    filestar = nullptr;
  }
  At.set_size(0);
  if (!(filestar == nullptr)) {
    c = 1;
    while (c > 0) {
      char tbuf[1024];
      c = 0;
      in_idx = 1;
      while ((c < 1024) && (in_idx > 0)) {
        size_t numReadSizeT;
        numReadSizeT =
            std::fread(&tbuf[c], nBytes, (size_t)(1024 - c), filestar);
        in_idx = (int)numReadSizeT;
        c += (int)numReadSizeT;
      }
      if (c < 1) {
        in_idx = 0;
      } else {
        in_idx = c;
      }
      patt_idx = At.size(0);
      At.set_size(At.size(0) + in_idx);
      for (tmp_in_idx = 0; tmp_in_idx < in_idx; tmp_in_idx++) {
        At[patt_idx + tmp_in_idx] = tbuf[tmp_in_idx];
      }
    }
  }
  charRow.set_size(1, At.size(0));
  in_idx = At.size(0);
  for (patt_idx = 0; patt_idx < in_idx; patt_idx++) {
    charRow[patt_idx] = At[patt_idx];
  }
  // Force to be a single row
  str_len = At.size(0);
  if (At.size(0) == 0) {
    charRow.set_size(1, 0);
  } else {
    int b_in_idx;
    int copyfrom;
    int out_idx;
    int out_len;
    b_in_idx = 0;
    copyfrom = 1;
    out_idx = 0;
    in_idx = 0;
    c = 1;
    out_len = 0;
    while (in_idx < str_len) {
      in_idx++;
      patt_idx = 1;
      tmp_in_idx = in_idx;
      while ((patt_idx <= 6) && (tmp_in_idx <= str_len) &&
             (At[tmp_in_idx - 1] == cv1[patt_idx - 1])) {
        tmp_in_idx++;
        patt_idx++;
      }
      if (patt_idx > 6) {
        out_len += 5;
        c = tmp_in_idx;
      } else if (in_idx >= c) {
        out_len++;
      }
    }
    in_idx = At.size(0);
    c = At.size(0) * 5;
    if (in_idx >= c) {
      c = in_idx;
    }
    if (out_len > c) {
      g_rtErrorWithMessageID(v_emlrtRTEI.fName, v_emlrtRTEI.lineNo);
    }
    if (out_len < 0) {
      rtNonNegativeError(static_cast<double>(out_len), emlrtDCI);
    }
    charRow.set_size(1, out_len);
    while (b_in_idx < str_len) {
      b_in_idx++;
      patt_idx = 1;
      tmp_in_idx = b_in_idx;
      while ((patt_idx <= 6) && (tmp_in_idx <= str_len) &&
             (At[tmp_in_idx - 1] == cv1[patt_idx - 1])) {
        tmp_in_idx++;
        patt_idx++;
      }
      if (patt_idx > 6) {
        for (in_idx = 0; in_idx < 5; in_idx++) {
          charRow[out_idx + in_idx] = cv2[in_idx];
        }
        out_idx += 5;
        copyfrom = tmp_in_idx;
      } else if (b_in_idx >= copyfrom) {
        charRow[out_idx] = At[b_in_idx - 1];
        out_idx++;
      }
    }
  }
  coder::internal::cfclose(static_cast<double>(fid));
  fileid = coder::internal::cfopen(filePath, "wb");
  if (fileid == 0) {
    c_rtErrorWithMessageID(b_emlrtRTEI.fName, b_emlrtRTEI.lineNo);
  }
  varargin_1.set_size(1, charRow.size(1) + 1);
  in_idx = charRow.size(1);
  for (patt_idx = 0; patt_idx < in_idx; patt_idx++) {
    varargin_1[patt_idx] = charRow[patt_idx];
  }
  varargin_1[charRow.size(1)] = '\x00';
  f = coder::internal::getfilestar(static_cast<double>(fileid), b_bool);
  if (f == nullptr) {
    b_rtErrorWithMessageID(emlrtRTEI.fName, emlrtRTEI.lineNo);
  } else {
    std::fprintf(f, "%s", &varargin_1[0]);
    if (b_bool) {
      std::fflush(f);
    }
  }
  coder::internal::cfclose(static_cast<double>(fileid));
}

//
// File trailer for cleancsv.cpp
//
// [EOF]
//
