//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: varNamesDim.h
//
// MATLAB Coder version            : 5.6
// C/C++ source code generated on  : 02-Oct-2023 13:02:17
//

#ifndef VARNAMESDIM_H
#define VARNAMESDIM_H

// Include Files
#include "bearing_internal_types.h"
#include "rtwtypes.h"
#include <cstddef>
#include <cstdlib>

// Type Definitions
namespace coder {
namespace matlab {
namespace internal {
namespace coder {
namespace tabular {
namespace b_private {
class varNamesDim {
public:
  static void createLike(varNamesDim &newobj);
  cell_wrap_3 descrs[10];
  cell_wrap_3 units[10];
  Continuity continuity[10];
  boolean_T hasDescrs;
  boolean_T hasUnits;
  boolean_T hasContinuity;
};

} // namespace b_private
} // namespace tabular
} // namespace coder
} // namespace internal
} // namespace matlab
} // namespace coder

#endif
//
// File trailer for varNamesDim.h
//
// [EOF]
//
