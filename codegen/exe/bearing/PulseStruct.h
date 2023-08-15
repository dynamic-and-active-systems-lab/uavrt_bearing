//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: PulseStruct.h
//
// MATLAB Coder version            : 5.6
// C/C++ source code generated on  : 15-Aug-2023 14:31:29
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
void PulseStruct(const coder::array<double, 1U> &tagID,
                 const coder::array<double, 1U> &freqMHz,
                 const coder::array<struct_T, 2U> &pos,
                 const coder::array<d_struct_T, 2U> &euler,
                 const coder::array<double, 1U> &b_time,
                 const coder::array<double, 1U> &timeNext,
                 const coder::array<double, 1U> &snrdB,
                 const coder::array<double, 1U> &stftMag2,
                 const coder::array<double, 1U> &groupSeqCount,
                 const coder::array<double, 1U> &groupIndex,
                 const coder::array<double, 1U> &groupsnrdB,
                 const coder::array<double, 1U> &noisePSD,
                 const coder::array<double, 1U> &detectStatus,
                 const coder::array<double, 1U> &confirmStatus,
                 coder::array<e_struct_T, 2U> &pulse);

#endif
//
// File trailer for PulseStruct.h
//
// [EOF]
//
