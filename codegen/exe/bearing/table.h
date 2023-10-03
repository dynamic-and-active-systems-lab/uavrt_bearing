//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: table.h
//
// MATLAB Coder version            : 5.6
// C/C++ source code generated on  : 03-Oct-2023 08:03:05
//

#ifndef TABLE_H
#define TABLE_H

// Include Files
#include "bearing_internal_types.h"
#include "metaDim.h"
#include "rowNamesDim.h"
#include "rtwtypes.h"
#include "varNamesDim.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Type Definitions
namespace coder {
class table {
public:
  matlab::internal::coder::tabular::b_private::varNamesDim varDim;
  cell_6 data;
  c_struct_T arrayProps;

protected:
  matlab::internal::coder::tabular::b_private::metaDim b_metaDim;
};

class b_table {
public:
  void init(const ::coder::array<unsigned int, 1U> &varargin_1,
            const ::coder::array<cell_wrap_4, 1U> &varargin_2,
            const ::coder::array<double, 1U> &varargin_3,
            const ::coder::array<double, 1U> &varargin_4,
            const ::coder::array<double, 1U> &varargin_5,
            const ::coder::array<double, 1U> &varargin_6,
            const ::coder::array<double, 1U> &varargin_7,
            const ::coder::array<double, 1U> &varargin_8,
            const ::coder::array<double, 1U> &varargin_9,
            const ::coder::array<double, 1U> &varargin_10);
  void vertcat(const table &varargin_2, b_table &t) const;
  void parenReference(const ::coder::array<boolean_T, 1U> &varargin_1,
                      b_table &b) const;
  cell_5 data;

protected:
  matlab::internal::coder::tabular::b_private::metaDim b_metaDim;
  matlab::internal::coder::tabular::b_private::rowNamesDim rowDim;
  matlab::internal::coder::tabular::b_private::varNamesDim varDim;
  c_struct_T arrayProps;
};

} // namespace coder

#endif
//
// File trailer for table.h
//
// [EOF]
//
