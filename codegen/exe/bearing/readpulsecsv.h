//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: readpulsecsv.h
//
// MATLAB Coder version            : 5.6
// C/C++ source code generated on  : 20-Sep-2023 13:03:40
//

#ifndef READPULSECSV_H
#define READPULSECSV_H

// Include Files
#include "bearing_internal_types.h"
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
void readpulsecsv(const coder::array<char, 2U> &filepath,
                  coder::array<e_struct_T, 2U> &pulses,
                  coder::array<empty, 2U> &commands);

#endif
//
// File trailer for readpulsecsv.h
//
// [EOF]
//
