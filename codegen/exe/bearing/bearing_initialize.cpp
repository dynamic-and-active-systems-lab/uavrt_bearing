//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: bearing_initialize.cpp
//
// MATLAB Coder version            : 5.6
// C/C++ source code generated on  : 03-Oct-2023 08:03:05
//

// Include Files
#include "bearing_initialize.h"
#include "bearing_data.h"
#include "fileManager.h"
#include "rt_nonfinite.h"

// Function Definitions
//
// Arguments    : void
// Return Type  : void
//
void bearing_initialize()
{
  filedata_init();
  isInitialized_bearing = true;
}

//
// File trailer for bearing_initialize.cpp
//
// [EOF]
//
