//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: main.cpp
//
// MATLAB Coder version            : 5.6
// C/C++ source code generated on  : 28-Jun-2023 15:11:34
//

/*************************************************************************/
/* This automatically generated example C++ main file shows how to call  */
/* entry-point functions that MATLAB Coder generated. You must customize */
/* this file for your application. Do not modify this file directly.     */
/* Instead, make a copy of this file, modify it, and integrate it into   */
/* your development environment.                                         */
/*                                                                       */
/* This file initializes entry-point function arguments to a default     */
/* size and value before calling the entry-point functions. It does      */
/* not store or use any values returned from the entry-point functions.  */
/* If necessary, it does pre-allocate memory for returned values.        */
/* You can use this file as a starting point for a main function that    */
/* you can deploy in your application.                                   */
/*                                                                       */
/* After you copy the file, and before you deploy it, you must make the  */
/* following changes:                                                    */
/* * For variable-size function arguments, change the example sizes to   */
/* the sizes that your application requires.                             */
/* * Change the example values of function arguments to the values that  */
/* your application requires.                                            */
/* * If the entry-point functions return values, store these values or   */
/* otherwise use them as required by your application.                   */
/*                                                                       */
/*************************************************************************/

// Include Files
#include "main.h"
#include "bearing.h"
#include "bearing_terminate.h"
#include "bearing_types.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <sstream>
#include <stdexcept>
#include <string>

// Function Declarations
static coder::array<char, 2U> argInit_1xUnbounded_char_T();

static char argInit_char_T();

// static void y_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

// Function Definitions
//
// Arguments    : void
// Return Type  : coder::array<char, 2U>
//
static coder::array<char, 2U> argInit_1xUnbounded_char_T()
{
  coder::array<char, 2U> result;
  // Set the size of the array.
  // Change this size to the value that the application requires.
  result.set_size(1, 2);
  // Loop over the array to initialize each element.
  for (int idx0{0}; idx0 < 1; idx0++) {
    for (int idx1{0}; idx1 < result.size(1); idx1++) {
      // Set the value of the array element.
      // Change this value to the value that the application requires.
      result[idx1] = argInit_char_T();
    }
  }
  return result;
}

//
// Arguments    : void
// Return Type  : char
//
static char argInit_char_T()
{
  return '?';
}

//
// Arguments    : const char *aFcnName
//                int aLineNum
// Return Type  : void
//
/*
static void y_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::stringstream outStream;
  outStream << "Example main does not support command line arguments.";
  outStream << "\n";
  ((((outStream << "Error in ") << aFcnName) << " (line ") << aLineNum) << ")";
  throw std::runtime_error(outStream.str());
}
 */

//
// Arguments    : int argc
//                char **argv
// Return Type  : int
//
int main(int argc, char **argv)
{
  static rtRunTimeErrorInfo r_emlrtRTEI{
      1,        // lineNo
      "bearing" // fName
  };
  //if (argc > 1) {
  //  y_rtErrorWithMessageID(r_emlrtRTEI.fName, r_emlrtRTEI.lineNo);
  //}
  // The initialize function is being called automatically from your entry-point
  // function. So, a call to initialize is not included here. Invoke the
  // entry-point functions.
  // You can call entry-point functions multiple times.
 
  if (argc != 2 ) {
      printf("Error: Must provide exactly one input string, e.g.\n");
      exit(-1);
  }

  main_bearing(argv[1]);
  // Terminate the application.
  // You do not need to do this more than one time.
  bearing_terminate();
  return 0;
}

//
// Arguments    : void
// Return Type  : void
//
void main_bearing(char *inStr)
{
  
  coder::array<char, 2U> filePath(inStr);

  double b_bearing;
  // Initialize function 'bearing' input arguments.
  // Initialize function input argument 'filePath'.
  //filePath = argInit_1xUnbounded_char_T();
  // Call the entry-point 'bearing'.
  b_bearing = bearing(filePath);
  printf("%f\n", b_bearing);
}

//
// File trailer for main.cpp
//
// [EOF]
//
