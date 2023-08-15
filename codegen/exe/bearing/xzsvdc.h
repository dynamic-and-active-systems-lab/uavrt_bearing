//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xzsvdc.h
//
// MATLAB Coder version            : 5.6
// C/C++ source code generated on  : 15-Aug-2023 14:31:29
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
int xzsvdc(::coder::array<double, 2U> &A, ::coder::array<double, 2U> &U,
           double S_data[], double V[4]);

}
} // namespace internal
} // namespace coder

#endif
//
// File trailer for xzsvdc.h
//
// [EOF]
//
