//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: fscanf.cpp
//
// MATLAB Coder version            : 23.2
// C/C++ source code generated on  : 03-Oct-2023 13:40:05
//

// Include Files
#include "fscanf.h"
#include "fileManager.h"
#include "rt_nonfinite.h"
#include <algorithm>
#include <cstdio>
#include <cstring>

// Type Definitions
struct cell_10 {
  int f1;
  int f2;
  int f3;
  double f4;
  double f5;
  double f6;
  double f7;
  double f8;
  double f9;
  double f10;
  double f11;
  int f12;
  int f13;
  double f14;
  double f15;
  double f16;
  double f17;
  double f18;
  double f19;
  double f20;
  double f21;
  int f22;
};

// Function Declarations
namespace coder {
static int b_callCeval(std::FILE *filestar, cell_10 &outCell);

static int callCeval(std::FILE *filestar, cell_10 &outCell);

} // namespace coder

// Function Definitions
//
// Arguments    : std::FILE *filestar
//                cell_10 &outCell
// Return Type  : int
//
namespace coder {
static int b_callCeval(std::FILE *filestar, cell_10 &outCell)
{
  static const char b_cfmt[80]{"%d,%d,%d,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%d,%d,"
                               "%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf\n"};
  int numRead;
  char cfmt[80];
  outCell.f22 = -1;
  std::copy(&b_cfmt[0], &b_cfmt[80], &cfmt[0]);
  numRead = std::fscanf(filestar, &cfmt[0], &outCell.f1, &outCell.f2,
                        &outCell.f3, &outCell.f4, &outCell.f5, &outCell.f6,
                        &outCell.f7, &outCell.f8, &outCell.f9, &outCell.f10,
                        &outCell.f11, &outCell.f12, &outCell.f13, &outCell.f14,
                        &outCell.f15, &outCell.f16, &outCell.f17, &outCell.f18,
                        &outCell.f19, &outCell.f20, &outCell.f21, &outCell.f22);
  if (outCell.f22 != -1) {
    numRead++;
  }
  return numRead;
}

//
// Arguments    : std::FILE *filestar
//                cell_10 &outCell
// Return Type  : int
//
static int callCeval(std::FILE *filestar, cell_10 &outCell)
{
  int numRead;
  outCell.f22 = -1;
  numRead = std::fscanf(filestar,
                        "%d,%d,%d,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%d,%d,%lf,%"
                        "lf,%lf,%lf,%lf,%lf,%lf,%lf\n%n",
                        &outCell.f1, &outCell.f2, &outCell.f3, &outCell.f4,
                        &outCell.f5, &outCell.f6, &outCell.f7, &outCell.f8,
                        &outCell.f9, &outCell.f10, &outCell.f11, &outCell.f12,
                        &outCell.f13, &outCell.f14, &outCell.f15, &outCell.f16,
                        &outCell.f17, &outCell.f18, &outCell.f19, &outCell.f20,
                        &outCell.f21, &outCell.f22);
  if (outCell.f22 != -1) {
    numRead++;
  }
  return numRead;
}

//
// Arguments    : double fileID
//                double A_data[]
//                int A_size[2]
// Return Type  : void
//
void b_fscanf(double fileID, double A_data[], int A_size[2])
{
  std::FILE *f;
  cell_10 tmpOut;
  double bigA[21];
  int numRead;
  int numWrittenTotal;
  boolean_T exitg1;
  boolean_T incompleteRead;
  tmpOut.f1 = 0;
  tmpOut.f2 = 0;
  tmpOut.f3 = 0;
  tmpOut.f4 = 0.0;
  tmpOut.f5 = 0.0;
  tmpOut.f6 = 0.0;
  tmpOut.f7 = 0.0;
  tmpOut.f8 = 0.0;
  tmpOut.f9 = 0.0;
  tmpOut.f10 = 0.0;
  tmpOut.f11 = 0.0;
  tmpOut.f12 = 0;
  tmpOut.f13 = 0;
  tmpOut.f14 = 0.0;
  tmpOut.f15 = 0.0;
  tmpOut.f16 = 0.0;
  tmpOut.f17 = 0.0;
  tmpOut.f18 = 0.0;
  tmpOut.f19 = 0.0;
  tmpOut.f20 = 0.0;
  tmpOut.f21 = 0.0;
  tmpOut.f22 = -1;
  std::memset(&bigA[0], 0, 21U * sizeof(double));
  numWrittenTotal = 0;
  f = internal::getfilestar(fileID, incompleteRead);
  numRead = 0;
  exitg1 = false;
  while ((!exitg1) && (numRead > 0)) {
    numRead = callCeval(f, tmpOut);
    incompleteRead = (numRead == 0);
    if (numRead > 0) {
      bigA[numWrittenTotal] = tmpOut.f1;
      numWrittenTotal++;
      if (numRead >= 2) {
        bigA[numWrittenTotal] = tmpOut.f2;
        numWrittenTotal++;
      } else {
        incompleteRead = true;
      }
      if (numRead >= 3) {
        bigA[numWrittenTotal] = tmpOut.f3;
        numWrittenTotal++;
      } else {
        incompleteRead = true;
      }
      if (numRead >= 4) {
        bigA[numWrittenTotal] = tmpOut.f4;
        numWrittenTotal++;
      } else {
        incompleteRead = true;
      }
      if (numRead >= 5) {
        bigA[numWrittenTotal] = tmpOut.f5;
        numWrittenTotal++;
      } else {
        incompleteRead = true;
      }
      if (numRead >= 6) {
        bigA[numWrittenTotal] = tmpOut.f6;
        numWrittenTotal++;
      } else {
        incompleteRead = true;
      }
      if (numRead >= 7) {
        bigA[numWrittenTotal] = tmpOut.f7;
        numWrittenTotal++;
      } else {
        incompleteRead = true;
      }
      if (numRead >= 8) {
        bigA[numWrittenTotal] = tmpOut.f8;
        numWrittenTotal++;
      } else {
        incompleteRead = true;
      }
      if (numRead >= 9) {
        bigA[numWrittenTotal] = tmpOut.f9;
        numWrittenTotal++;
      } else {
        incompleteRead = true;
      }
      if (numRead >= 10) {
        bigA[numWrittenTotal] = tmpOut.f10;
        numWrittenTotal++;
      } else {
        incompleteRead = true;
      }
      if (numRead >= 11) {
        bigA[numWrittenTotal] = tmpOut.f11;
        numWrittenTotal++;
      } else {
        incompleteRead = true;
      }
      if (numRead >= 12) {
        bigA[numWrittenTotal] = tmpOut.f12;
        numWrittenTotal++;
      } else {
        incompleteRead = true;
      }
      if (numRead >= 13) {
        bigA[numWrittenTotal] = tmpOut.f13;
        numWrittenTotal++;
      } else {
        incompleteRead = true;
      }
      if (numRead >= 14) {
        bigA[numWrittenTotal] = tmpOut.f14;
        numWrittenTotal++;
      } else {
        incompleteRead = true;
      }
      if (numRead >= 15) {
        bigA[numWrittenTotal] = tmpOut.f15;
        numWrittenTotal++;
      } else {
        incompleteRead = true;
      }
      if (numRead >= 16) {
        bigA[numWrittenTotal] = tmpOut.f16;
        numWrittenTotal++;
      } else {
        incompleteRead = true;
      }
      if (numRead >= 17) {
        bigA[numWrittenTotal] = tmpOut.f17;
        numWrittenTotal++;
      } else {
        incompleteRead = true;
      }
      if (numRead >= 18) {
        bigA[numWrittenTotal] = tmpOut.f18;
        numWrittenTotal++;
      } else {
        incompleteRead = true;
      }
      if (numRead >= 19) {
        bigA[numWrittenTotal] = tmpOut.f19;
        numWrittenTotal++;
      } else {
        incompleteRead = true;
      }
      if (numRead >= 20) {
        bigA[numWrittenTotal] = tmpOut.f20;
        numWrittenTotal++;
      } else {
        incompleteRead = true;
      }
      if (numRead >= 21) {
        bigA[numWrittenTotal] = tmpOut.f21;
        numWrittenTotal++;
      } else {
        incompleteRead = true;
      }
      incompleteRead = ((numRead < 22) || incompleteRead);
    }
    if (incompleteRead || (21 - numWrittenTotal <= 21)) {
      exitg1 = true;
    }
  }
  if (numWrittenTotal < 21) {
    numRead = b_callCeval(f, tmpOut);
    if (numRead >= 1) {
      bigA[numWrittenTotal] = tmpOut.f1;
      numWrittenTotal++;
    }
    if (numRead >= 2) {
      bigA[numWrittenTotal] = tmpOut.f2;
      numWrittenTotal++;
    }
    if (numRead >= 3) {
      bigA[numWrittenTotal] = tmpOut.f3;
      numWrittenTotal++;
    }
    if (numRead >= 4) {
      bigA[numWrittenTotal] = tmpOut.f4;
      numWrittenTotal++;
    }
    if (numRead >= 5) {
      bigA[numWrittenTotal] = tmpOut.f5;
      numWrittenTotal++;
    }
    if (numRead >= 6) {
      bigA[numWrittenTotal] = tmpOut.f6;
      numWrittenTotal++;
    }
    if (numRead >= 7) {
      bigA[numWrittenTotal] = tmpOut.f7;
      numWrittenTotal++;
    }
    if (numRead >= 8) {
      bigA[numWrittenTotal] = tmpOut.f8;
      numWrittenTotal++;
    }
    if (numRead >= 9) {
      bigA[numWrittenTotal] = tmpOut.f9;
      numWrittenTotal++;
    }
    if (numRead >= 10) {
      bigA[numWrittenTotal] = tmpOut.f10;
      numWrittenTotal++;
    }
    if (numRead >= 11) {
      bigA[numWrittenTotal] = tmpOut.f11;
      numWrittenTotal++;
    }
    if (numRead >= 12) {
      bigA[numWrittenTotal] = tmpOut.f12;
      numWrittenTotal++;
    }
    if (numRead >= 13) {
      bigA[numWrittenTotal] = tmpOut.f13;
      numWrittenTotal++;
    }
    if (numRead >= 14) {
      bigA[numWrittenTotal] = tmpOut.f14;
      numWrittenTotal++;
    }
    if (numRead >= 15) {
      bigA[numWrittenTotal] = tmpOut.f15;
      numWrittenTotal++;
    }
    if (numRead >= 16) {
      bigA[numWrittenTotal] = tmpOut.f16;
      numWrittenTotal++;
    }
    if (numRead >= 17) {
      bigA[numWrittenTotal] = tmpOut.f17;
      numWrittenTotal++;
    }
    if (numRead >= 18) {
      bigA[numWrittenTotal] = tmpOut.f18;
      numWrittenTotal++;
    }
    if (numRead >= 19) {
      bigA[numWrittenTotal] = tmpOut.f19;
      numWrittenTotal++;
    }
    if (numRead >= 20) {
      bigA[numWrittenTotal] = tmpOut.f20;
      numWrittenTotal++;
    }
    if (numRead >= 21) {
      bigA[numWrittenTotal] = tmpOut.f21;
      numWrittenTotal++;
    }
  }
  if (numWrittenTotal > 0) {
    if (numWrittenTotal > 1) {
      if (numWrittenTotal > 21) {
        numWrittenTotal = 21;
      }
      A_size[0] = 1;
      A_size[1] = numWrittenTotal;
      std::copy(&bigA[0], &bigA[numWrittenTotal], &A_data[0]);
    } else {
      A_size[0] = 1;
      A_size[1] = 1;
      A_data[0] = bigA[0];
    }
  } else {
    A_size[0] = 0;
    A_size[1] = 1;
  }
}

//
// Arguments    : double fileID
//                double A_data[]
//                int A_size[2]
// Return Type  : void
//
void c_fscanf(double fileID, double A_data[], int A_size[2])
{
  static const char b_cfmt[16]{"%d,%lf,%lf,%lf\n"};
  std::FILE *f;
  double bigA[4];
  double tmpOut_f2;
  double tmpOut_f3;
  double tmpOut_f4;
  int numRead;
  int numWrittenTotal;
  int tmpOut_f1;
  int tmpOut_f5;
  boolean_T exitg1;
  boolean_T incompleteRead;
  tmpOut_f1 = 0;
  tmpOut_f2 = 0.0;
  tmpOut_f3 = 0.0;
  tmpOut_f4 = 0.0;
  bigA[0] = 0.0;
  bigA[1] = 0.0;
  bigA[2] = 0.0;
  bigA[3] = 0.0;
  numWrittenTotal = 0;
  f = internal::getfilestar(fileID, incompleteRead);
  numRead = 0;
  exitg1 = false;
  while ((!exitg1) && (numRead > 0)) {
    tmpOut_f5 = -1;
    numRead = std::fscanf(f, "%d,%lf,%lf,%lf\n%n", &tmpOut_f1, &tmpOut_f2,
                          &tmpOut_f3, &tmpOut_f4, &tmpOut_f5);
    if (tmpOut_f5 != -1) {
      numRead++;
    }
    incompleteRead = (numRead == 0);
    if (numRead > 0) {
      bigA[numWrittenTotal] = tmpOut_f1;
      numWrittenTotal++;
      if (numRead >= 2) {
        bigA[numWrittenTotal] = tmpOut_f2;
        numWrittenTotal++;
      } else {
        incompleteRead = true;
      }
      if (numRead >= 3) {
        bigA[numWrittenTotal] = tmpOut_f3;
        numWrittenTotal++;
      } else {
        incompleteRead = true;
      }
      if (numRead >= 4) {
        bigA[numWrittenTotal] = tmpOut_f4;
        numWrittenTotal++;
      } else {
        incompleteRead = true;
      }
      incompleteRead = ((numRead < 5) || incompleteRead);
    }
    if (incompleteRead || (4 - numWrittenTotal <= 4)) {
      exitg1 = true;
    }
  }
  if (numWrittenTotal < 4) {
    char cfmt[16];
    tmpOut_f5 = -1;
    for (numRead = 0; numRead < 16; numRead++) {
      cfmt[numRead] = b_cfmt[numRead];
    }
    numRead = std::fscanf(f, &cfmt[0], &tmpOut_f1, &tmpOut_f2, &tmpOut_f3,
                          &tmpOut_f4, &tmpOut_f5);
    if (tmpOut_f5 != -1) {
      numRead++;
    }
    if (numRead >= 1) {
      bigA[numWrittenTotal] = tmpOut_f1;
      numWrittenTotal++;
    }
    if (numRead >= 2) {
      bigA[numWrittenTotal] = tmpOut_f2;
      numWrittenTotal++;
    }
    if (numRead >= 3) {
      bigA[numWrittenTotal] = tmpOut_f3;
      numWrittenTotal++;
    }
    if (numRead >= 4) {
      bigA[numWrittenTotal] = tmpOut_f4;
      numWrittenTotal++;
    }
  }
  if (numWrittenTotal > 0) {
    if (numWrittenTotal > 1) {
      if (numWrittenTotal > 4) {
        numRead = 4;
      } else {
        numRead = numWrittenTotal;
      }
      A_size[0] = 1;
      A_size[1] = numRead;
      std::copy(&bigA[0], &bigA[numRead], &A_data[0]);
    } else {
      A_size[0] = 1;
      A_size[1] = 1;
      A_data[0] = bigA[0];
    }
  } else {
    A_size[0] = 0;
    A_size[1] = 1;
  }
}

} // namespace coder

//
// File trailer for fscanf.cpp
//
// [EOF]
//
