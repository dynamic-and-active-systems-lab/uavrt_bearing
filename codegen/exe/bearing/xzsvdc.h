//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xzsvdc.h
//
// MATLAB Coder version            : 23.2
// C/C++ source code generated on  : 07-Nov-2023 14:21:19
//

#ifndef XZSVDC_H
#define XZSVDC_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
namespace internal {
namespace reflapack {
int xzsvdc(array<double, 2U> &A, array<double, 2U> &U, double S_data[],
           double V[4]);

}
} // namespace internal
} // namespace coder

#endif
//
// File trailer for xzsvdc.h
//
// [EOF]
//
