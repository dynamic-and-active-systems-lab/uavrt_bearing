//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: fgetl.cpp
//
// MATLAB Coder version            : 5.6
// C/C++ source code generated on  : 27-Jun-2023 16:44:57
//

// Include Files
#include "fgetl.h"
#include "fgets.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : double fileID
//                ::coder::array<char, 2U> &out
// Return Type  : void
//
namespace coder {
void fgetl(double fileID, ::coder::array<char, 2U> &out)
{
  b_fgets(fileID, out);
  if (out.size(1) != 0) {
    char c;
    c = out[out.size(1) - 1];
    if (c == '\n') {
      if ((out.size(1) > 1) && (out[out.size(1) - 2] == '\r')) {
        int loop_ub;
        if (out.size(1) - 2 < 1) {
          loop_ub = 0;
        } else {
          loop_ub = out.size(1) - 2;
        }
        for (int i{0}; i < loop_ub; i++) {
          out[i] = out[i];
        }
        out.set_size(1, loop_ub);
      } else {
        int loop_ub;
        if (out.size(1) - 1 < 1) {
          loop_ub = 0;
        } else {
          loop_ub = out.size(1) - 1;
        }
        for (int i{0}; i < loop_ub; i++) {
          out[i] = out[i];
        }
        out.set_size(1, loop_ub);
      }
    } else if (c == '\r') {
      int loop_ub;
      if (out.size(1) - 1 < 1) {
        loop_ub = 0;
      } else {
        loop_ub = out.size(1) - 1;
      }
      for (int i{0}; i < loop_ub; i++) {
        out[i] = out[i];
      }
      out.set_size(1, loop_ub);
    }
  }
}

} // namespace coder

//
// File trailer for fgetl.cpp
//
// [EOF]
//
