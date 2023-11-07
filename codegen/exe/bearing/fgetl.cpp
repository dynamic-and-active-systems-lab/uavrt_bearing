//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: fgetl.cpp
//
// MATLAB Coder version            : 23.2
// C/C++ source code generated on  : 07-Nov-2023 14:21:19
//

// Include Files
#include "fgetl.h"
#include "fgets.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : double fileID
//                array<char, 2U> &out
// Return Type  : void
//
namespace coder {
void fgetl(double fileID, array<char, 2U> &out)
{
  b_fgets(fileID, out);
  if (out.size(1) != 0) {
    char c;
    c = out[out.size(1) - 1];
    if (c == '\n') {
      if ((out.size(1) > 1) && (out[out.size(1) - 2] == '\r')) {
        int loop_ub;
        loop_ub = out.size(1) - 2;
        for (int i{0}; i < loop_ub; i++) {
          out[i] = out[i];
        }
        out.set_size(1, out.size(1) - 2);
      } else {
        int loop_ub;
        loop_ub = out.size(1) - 1;
        for (int i{0}; i < loop_ub; i++) {
          out[i] = out[i];
        }
        out.set_size(1, out.size(1) - 1);
      }
    } else if (c == '\r') {
      int loop_ub;
      loop_ub = out.size(1) - 1;
      for (int i{0}; i < loop_ub; i++) {
        out[i] = out[i];
      }
      out.set_size(1, out.size(1) - 1);
    }
  }
}

} // namespace coder

//
// File trailer for fgetl.cpp
//
// [EOF]
//
