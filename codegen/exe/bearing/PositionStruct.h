//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: PositionStruct.h
//
// MATLAB Coder version            : 5.6
// C/C++ source code generated on  : 27-Jun-2023 16:44:57
//

#ifndef POSITIONSTRUCT_H
#define POSITIONSTRUCT_H

// Include Files
#include "bearing_internal_types.h"
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
void PositionStruct(const coder::array<double, 1U> &lat,
                    const coder::array<double, 1U> &lon,
                    const coder::array<double, 1U> &altAbs,
                    const coder::array<double, 1U> &altRel,
                    coder::array<struct_T, 2U> &pos);

#endif
//
// File trailer for PositionStruct.h
//
// [EOF]
//