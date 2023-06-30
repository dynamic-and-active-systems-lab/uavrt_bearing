//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: PulseStruct.h
//
// MATLAB Coder version            : 5.6
// C/C++ source code generated on  : 30-Jun-2023 13:13:27
//

#ifndef PULSESTRUCT_H
#define PULSESTRUCT_H

// Include Files
#include "bearing_internal_types.h"
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
void PulseStruct(const coder::array<struct_T, 2U> &pos,
                 const coder::array<d_struct_T, 2U> &euler,
                 const coder::array<double, 1U> &b_time,
                 const coder::array<double, 1U> &strength,
                 const coder::array<double, 1U> &freqMHz,
                 const coder::array<double, 1U> &tagID,
                 coder::array<e_struct_T, 2U> &pulse);

#endif
//
// File trailer for PulseStruct.h
//
// [EOF]
//
