//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: mtimes.h
//
// MATLAB Coder version            : 5.6
// C/C++ source code generated on  : 27-Jun-2023 16:44:57
//

#ifndef MTIMES_H
#define MTIMES_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
namespace internal {
namespace blas {
void mtimes(const ::coder::array<double, 2U> &A,
            const ::coder::array<double, 2U> &B, ::coder::array<double, 2U> &C);

}
} // namespace internal
} // namespace coder

#endif
//
// File trailer for mtimes.h
//
// [EOF]
//