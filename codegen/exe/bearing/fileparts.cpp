//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: fileparts.cpp
//
// MATLAB Coder version            : 23.2
// C/C++ source code generated on  : 07-Nov-2023 14:21:19
//

// Include Files
#include "fileparts.h"
#include "bearing_data.h"
#include "bearing_rtwutil.h"
#include "bearing_types.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "coder_platform.h"

// Function Definitions
//
// Arguments    : const array<char, 2U> &file
//                array<char, 2U> &pathstr
//                array<char, 2U> &name
//                array<char, 2U> &ext
// Return Type  : void
//
namespace coder {
void fileparts(const array<char, 2U> &file, array<char, 2U> &pathstr,
               array<char, 2U> &name, array<char, 2U> &ext)
{
  boolean_T p;
  p = coderIsPC();
  if (p) {
    int ind;
    int j;
    int ncols;
    char x;
    boolean_T exitg1;
    ext.set_size(1, 0);
    pathstr.set_size(1, 0);
    ind = 0;
    ncols = 0;
    exitg1 = false;
    while ((!exitg1) && (ncols <= file.size(1) - 1)) {
      j = file.size(1) - ncols;
      x = file[j - 1];
      if (x == '/') {
        ind = j;
        exitg1 = true;
      } else if (x == '\\') {
        ind = j;
        exitg1 = true;
      } else {
        ncols++;
      }
    }
    if (ind == 0) {
      ncols = 0;
      exitg1 = false;
      while ((!exitg1) && (ncols <= file.size(1) - 1)) {
        j = file.size(1) - ncols;
        if (file[j - 1] == ':') {
          ind = j;
          exitg1 = true;
        } else {
          ncols++;
        }
      }
      if (ind != 0) {
        pathstr.set_size(1, ind);
        for (j = 0; j < ind; j++) {
          pathstr[j] = file[j];
        }
      }
    } else if ((ind == 2) && ((file[0] == '/') || (file[0] == '\\'))) {
      pathstr.set_size(1, file.size(1));
      ncols = file.size(1);
      for (j = 0; j < ncols; j++) {
        pathstr[j] = file[j];
      }
      ind = file.size(1);
    } else {
      if (ind - 1 < 1) {
        ncols = 0;
      } else {
        ncols = ind - 1;
      }
      pathstr.set_size(1, ncols);
      for (j = 0; j < ncols; j++) {
        pathstr[j] = file[j];
      }
    }
    if (ind == 0) {
      name.set_size(1, file.size(1));
      ncols = file.size(1);
      for (j = 0; j < ncols; j++) {
        name[j] = file[j];
      }
    } else {
      if ((pathstr.size(1) != 0) && (pathstr[pathstr.size(1) - 1] == ':')) {
        if (pathstr.size(1) > 2) {
          p = coderIsPC();
          j = pathstr.size(1);
          pathstr.set_size(pathstr.size(0), pathstr.size(1) + 1);
          if (p) {
            pathstr[j] = '\\';
          } else {
            pathstr[j] = '/';
          }
        } else if ((file.size(1) >= 3) &&
                   ((file[2] == '/') || (file[2] == '\\'))) {
          j = pathstr.size(1);
          pathstr.set_size(pathstr.size(0), pathstr.size(1) + 1);
          pathstr[j] = file[2];
        }
      } else {
        ncols = pathstr.size(1);
        exitg1 = false;
        while ((!exitg1) && (ncols > 0)) {
          x = pathstr[ncols - 1];
          if (static_cast<unsigned char>(x) != 0) {
            if (static_cast<unsigned char>(x) > 127) {
              y_rtErrorWithMessageID(l_emlrtRTEI.fName, l_emlrtRTEI.lineNo);
            }
            if (!bv[static_cast<unsigned char>(x) & 127]) {
              exitg1 = true;
            } else {
              ncols--;
            }
          } else {
            ncols--;
          }
        }
        if (ncols == 0) {
          p = coderIsPC();
          pathstr.set_size(1, 1);
          if (p) {
            pathstr[0] = '\\';
          } else {
            pathstr[0] = '/';
          }
        }
      }
      if (static_cast<double>(ind) + 1.0 > file.size(1)) {
        ind = 0;
        j = 0;
      } else {
        j = file.size(1);
      }
      ncols = j - ind;
      name.set_size(1, ncols);
      for (j = 0; j < ncols; j++) {
        name[j] = file[ind + j];
      }
    }
    if (name.size(1) != 0) {
      ind = 0;
      ncols = 0;
      exitg1 = false;
      while ((!exitg1) && (ncols <= name.size(1) - 1)) {
        j = name.size(1) - ncols;
        if (name[j - 1] == '.') {
          ind = j;
          exitg1 = true;
        } else {
          ncols++;
        }
      }
      if (ind != 0) {
        int i;
        if (ind > name.size(1)) {
          j = 0;
          i = 0;
        } else {
          j = ind - 1;
          i = name.size(1);
        }
        ncols = i - j;
        ext.set_size(1, ncols);
        for (i = 0; i < ncols; i++) {
          ext[i] = name[j + i];
        }
        if (ind - 1 < 1) {
          ncols = 0;
        } else {
          ncols = ind - 1;
        }
        for (j = 0; j < ncols; j++) {
          name[j] = name[j];
        }
        name.set_size(1, ncols);
      }
    }
  } else {
    int i;
    int ind;
    int j;
    int ncols;
    boolean_T exitg1;
    ind = 0;
    ncols = 0;
    exitg1 = false;
    while ((!exitg1) && (ncols <= file.size(1) - 1)) {
      j = file.size(1) - ncols;
      if (file[j - 1] == '/') {
        ind = j;
        exitg1 = true;
      } else {
        ncols++;
      }
    }
    if (ind == 0) {
      name.set_size(1, file.size(1));
      ncols = file.size(1);
      for (j = 0; j < ncols; j++) {
        name[j] = file[j];
      }
      pathstr.set_size(1, 0);
    } else {
      if (static_cast<double>(ind) + 1.0 > file.size(1)) {
        j = 0;
        i = 0;
      } else {
        j = ind;
        i = file.size(1);
      }
      ncols = i - j;
      name.set_size(1, ncols);
      for (i = 0; i < ncols; i++) {
        name[i] = file[j + i];
      }
      if (ind == 1) {
        p = coderIsPC();
        pathstr.set_size(1, 1);
        if (p) {
          pathstr[0] = '\\';
        } else {
          pathstr[0] = '/';
        }
      } else {
        pathstr.set_size(1, ind - 1);
        for (j = 0; j <= ind - 2; j++) {
          pathstr[j] = file[j];
        }
      }
    }
    if (name.size(1) != 0) {
      ind = 0;
      ncols = 0;
      exitg1 = false;
      while ((!exitg1) && (ncols <= name.size(1) - 1)) {
        j = name.size(1) - ncols;
        if (name[j - 1] == '.') {
          ind = j;
          exitg1 = true;
        } else {
          ncols++;
        }
      }
      if (ind != 0) {
        if (ind > name.size(1)) {
          j = 0;
          i = 0;
        } else {
          j = ind - 1;
          i = name.size(1);
        }
        ncols = i - j;
        ext.set_size(1, ncols);
        for (i = 0; i < ncols; i++) {
          ext[i] = name[j + i];
        }
        if (ind - 1 < 1) {
          ncols = 0;
        } else {
          ncols = ind - 1;
        }
        for (j = 0; j < ncols; j++) {
          name[j] = name[j];
        }
        name.set_size(1, ncols);
      } else {
        ext.set_size(1, 0);
      }
    } else {
      ext.set_size(1, 0);
    }
  }
}

} // namespace coder

//
// File trailer for fileparts.cpp
//
// [EOF]
//
