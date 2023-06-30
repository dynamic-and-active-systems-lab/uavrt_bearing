//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: onCleanup.cpp
//
// MATLAB Coder version            : 5.6
// C/C++ source code generated on  : 30-Jun-2023 13:13:27
//

// Include Files
#include "onCleanup.h"
#include "anonymous_function.h"
#include "bearing_internal_types.h"
#include "fileManager.h"
#include "rt_nonfinite.h"

// Function Definitions
//
// Arguments    : void
// Return Type  : onCleanup
//
namespace coder {
onCleanup::onCleanup()
{
  matlabCodegenIsDeleted = true;
}

//
// Arguments    : void
// Return Type  : void
//
onCleanup::~onCleanup()
{
  matlabCodegenDestructor();
}

//
// Arguments    : void
// Return Type  : void
//
void onCleanup::handle_matlabCodegenDestructor()
{
  if (!matlabCodegenIsDeleted) {
    anonymous_function b_this;
    matlabCodegenIsDeleted = true;
    b_this = task;
    internal::cfclose(b_this.workspace.fid);
  }
}

//
// Arguments    : void
// Return Type  : void
//
void onCleanup::matlabCodegenDestructor()
{
  if (!matlabCodegenIsDeleted) {
    anonymous_function b_this;
    matlabCodegenIsDeleted = true;
    b_this = task;
    internal::cfclose(b_this.workspace.fid);
  }
}

} // namespace coder

//
// File trailer for onCleanup.cpp
//
// [EOF]
//
