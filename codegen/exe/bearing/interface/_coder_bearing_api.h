//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: _coder_bearing_api.h
//
// MATLAB Coder version            : 5.6
// C/C++ source code generated on  : 30-Jun-2023 13:13:27
//

#ifndef _CODER_BEARING_API_H
#define _CODER_BEARING_API_H

// Include Files
#include "coder_array_mex.h"
#include "emlrt.h"
#include "tmwtypes.h"
#include <algorithm>
#include <cstring>

// Variable Declarations
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

// Function Declarations
real_T bearing(coder::array<char_T, 2U> *filePath);

void bearing_api(const mxArray *prhs, const mxArray **plhs);

void bearing_atexit();

void bearing_initialize();

void bearing_terminate();

void bearing_xil_shutdown();

void bearing_xil_terminate();

#endif
//
// File trailer for _coder_bearing_api.h
//
// [EOF]
//
