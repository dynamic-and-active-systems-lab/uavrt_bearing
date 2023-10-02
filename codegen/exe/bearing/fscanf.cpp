//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: fscanf.cpp
//
// MATLAB Coder version            : 5.6
// C/C++ source code generated on  : 02-Oct-2023 13:02:17
//

// Include Files
#include "fscanf.h"
#include "fileManager.h"
#include "rt_nonfinite.h"
#include <algorithm>
#include <cstdio>
#include <cstring>

// Function Definitions
//
// Arguments    : double fileID
//                double A_data[]
//                int A_size[2]
// Return Type  : void
//
namespace coder {
void b_fscanf(double fileID, double A_data[], int A_size[2])
{
  static const char b_cfmt[76]{"%d,%d,%d,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%d,%d,"
                               "%lf,%lf,%lf,%lf,%lf,%lf,%lf\n"};
  std::FILE *f;
  double bigA[20];
  double tmpOut_f10;
  double tmpOut_f11;
  double tmpOut_f14;
  double tmpOut_f15;
  double tmpOut_f16;
  double tmpOut_f17;
  double tmpOut_f18;
  double tmpOut_f19;
  double tmpOut_f20;
  double tmpOut_f4;
  double tmpOut_f5;
  double tmpOut_f6;
  double tmpOut_f7;
  double tmpOut_f8;
  double tmpOut_f9;
  int numRead;
  int numWrittenTotal;
  int tmpOut_f1;
  int tmpOut_f12;
  int tmpOut_f13;
  int tmpOut_f2;
  int tmpOut_f21;
  int tmpOut_f3;
  char cfmt[76];
  boolean_T exitg1;
  boolean_T incompleteRead;
  tmpOut_f1 = 0;
  tmpOut_f2 = 0;
  tmpOut_f3 = 0;
  tmpOut_f4 = 0.0;
  tmpOut_f5 = 0.0;
  tmpOut_f6 = 0.0;
  tmpOut_f7 = 0.0;
  tmpOut_f8 = 0.0;
  tmpOut_f9 = 0.0;
  tmpOut_f10 = 0.0;
  tmpOut_f11 = 0.0;
  tmpOut_f12 = 0;
  tmpOut_f13 = 0;
  tmpOut_f14 = 0.0;
  tmpOut_f15 = 0.0;
  tmpOut_f16 = 0.0;
  tmpOut_f17 = 0.0;
  tmpOut_f18 = 0.0;
  tmpOut_f19 = 0.0;
  tmpOut_f20 = 0.0;
  std::memset(&bigA[0], 0, 20U * sizeof(double));
  numWrittenTotal = 0;
  f = internal::getfilestar(fileID, incompleteRead);
  numRead = 0;
  exitg1 = false;
  while ((!exitg1) && (numRead > 0)) {
    tmpOut_f21 = -1;
    numRead = std::fscanf(
        f,
        "%d,%d,%d,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%d,%d,%lf,%lf,%lf,%lf,%lf,%"
        "lf,%lf\n%n",
        &tmpOut_f1, &tmpOut_f2, &tmpOut_f3, &tmpOut_f4, &tmpOut_f5, &tmpOut_f6,
        &tmpOut_f7, &tmpOut_f8, &tmpOut_f9, &tmpOut_f10, &tmpOut_f11,
        &tmpOut_f12, &tmpOut_f13, &tmpOut_f14, &tmpOut_f15, &tmpOut_f16,
        &tmpOut_f17, &tmpOut_f18, &tmpOut_f19, &tmpOut_f20, &tmpOut_f21);
    if (tmpOut_f21 != -1) {
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
      if (numRead >= 5) {
        bigA[numWrittenTotal] = tmpOut_f5;
        numWrittenTotal++;
      } else {
        incompleteRead = true;
      }
      if (numRead >= 6) {
        bigA[numWrittenTotal] = tmpOut_f6;
        numWrittenTotal++;
      } else {
        incompleteRead = true;
      }
      if (numRead >= 7) {
        bigA[numWrittenTotal] = tmpOut_f7;
        numWrittenTotal++;
      } else {
        incompleteRead = true;
      }
      if (numRead >= 8) {
        bigA[numWrittenTotal] = tmpOut_f8;
        numWrittenTotal++;
      } else {
        incompleteRead = true;
      }
      if (numRead >= 9) {
        bigA[numWrittenTotal] = tmpOut_f9;
        numWrittenTotal++;
      } else {
        incompleteRead = true;
      }
      if (numRead >= 10) {
        bigA[numWrittenTotal] = tmpOut_f10;
        numWrittenTotal++;
      } else {
        incompleteRead = true;
      }
      if (numRead >= 11) {
        bigA[numWrittenTotal] = tmpOut_f11;
        numWrittenTotal++;
      } else {
        incompleteRead = true;
      }
      if (numRead >= 12) {
        bigA[numWrittenTotal] = tmpOut_f12;
        numWrittenTotal++;
      } else {
        incompleteRead = true;
      }
      if (numRead >= 13) {
        bigA[numWrittenTotal] = tmpOut_f13;
        numWrittenTotal++;
      } else {
        incompleteRead = true;
      }
      if (numRead >= 14) {
        bigA[numWrittenTotal] = tmpOut_f14;
        numWrittenTotal++;
      } else {
        incompleteRead = true;
      }
      if (numRead >= 15) {
        bigA[numWrittenTotal] = tmpOut_f15;
        numWrittenTotal++;
      } else {
        incompleteRead = true;
      }
      if (numRead >= 16) {
        bigA[numWrittenTotal] = tmpOut_f16;
        numWrittenTotal++;
      } else {
        incompleteRead = true;
      }
      if (numRead >= 17) {
        bigA[numWrittenTotal] = tmpOut_f17;
        numWrittenTotal++;
      } else {
        incompleteRead = true;
      }
      if (numRead >= 18) {
        bigA[numWrittenTotal] = tmpOut_f18;
        numWrittenTotal++;
      } else {
        incompleteRead = true;
      }
      if (numRead >= 19) {
        bigA[numWrittenTotal] = tmpOut_f19;
        numWrittenTotal++;
      } else {
        incompleteRead = true;
      }
      if (numRead >= 20) {
        bigA[numWrittenTotal] = tmpOut_f20;
        numWrittenTotal++;
      } else {
        incompleteRead = true;
      }
      incompleteRead = ((numRead < 21) || incompleteRead);
    }
    if (incompleteRead || (20 - numWrittenTotal <= 20)) {
      exitg1 = true;
    }
  }
  if (numWrittenTotal < 20) {
    tmpOut_f21 = -1;
    std::copy(&b_cfmt[0], &b_cfmt[76], &cfmt[0]);
    numRead =
        std::fscanf(f, &cfmt[0], &tmpOut_f1, &tmpOut_f2, &tmpOut_f3, &tmpOut_f4,
                    &tmpOut_f5, &tmpOut_f6, &tmpOut_f7, &tmpOut_f8, &tmpOut_f9,
                    &tmpOut_f10, &tmpOut_f11, &tmpOut_f12, &tmpOut_f13,
                    &tmpOut_f14, &tmpOut_f15, &tmpOut_f16, &tmpOut_f17,
                    &tmpOut_f18, &tmpOut_f19, &tmpOut_f20, &tmpOut_f21);
    if (tmpOut_f21 != -1) {
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
    if (numRead >= 5) {
      bigA[numWrittenTotal] = tmpOut_f5;
      numWrittenTotal++;
    }
    if (numRead >= 6) {
      bigA[numWrittenTotal] = tmpOut_f6;
      numWrittenTotal++;
    }
    if (numRead >= 7) {
      bigA[numWrittenTotal] = tmpOut_f7;
      numWrittenTotal++;
    }
    if (numRead >= 8) {
      bigA[numWrittenTotal] = tmpOut_f8;
      numWrittenTotal++;
    }
    if (numRead >= 9) {
      bigA[numWrittenTotal] = tmpOut_f9;
      numWrittenTotal++;
    }
    if (numRead >= 10) {
      bigA[numWrittenTotal] = tmpOut_f10;
      numWrittenTotal++;
    }
    if (numRead >= 11) {
      bigA[numWrittenTotal] = tmpOut_f11;
      numWrittenTotal++;
    }
    if (numRead >= 12) {
      bigA[numWrittenTotal] = tmpOut_f12;
      numWrittenTotal++;
    }
    if (numRead >= 13) {
      bigA[numWrittenTotal] = tmpOut_f13;
      numWrittenTotal++;
    }
    if (numRead >= 14) {
      bigA[numWrittenTotal] = tmpOut_f14;
      numWrittenTotal++;
    }
    if (numRead >= 15) {
      bigA[numWrittenTotal] = tmpOut_f15;
      numWrittenTotal++;
    }
    if (numRead >= 16) {
      bigA[numWrittenTotal] = tmpOut_f16;
      numWrittenTotal++;
    }
    if (numRead >= 17) {
      bigA[numWrittenTotal] = tmpOut_f17;
      numWrittenTotal++;
    }
    if (numRead >= 18) {
      bigA[numWrittenTotal] = tmpOut_f18;
      numWrittenTotal++;
    }
    if (numRead >= 19) {
      bigA[numWrittenTotal] = tmpOut_f19;
      numWrittenTotal++;
    }
    if (numRead >= 20) {
      bigA[numWrittenTotal] = tmpOut_f20;
      numWrittenTotal++;
    }
  }
  if (numWrittenTotal > 0) {
    if (numWrittenTotal > 1) {
      if (numWrittenTotal > 20) {
        tmpOut_f1 = 20;
      } else {
        tmpOut_f1 = numWrittenTotal;
      }
      A_size[0] = 1;
      A_size[1] = tmpOut_f1;
      std::copy(&bigA[0], &bigA[tmpOut_f1], &A_data[0]);
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
