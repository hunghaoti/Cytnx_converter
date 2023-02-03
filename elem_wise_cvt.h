#ifndef _H_elem_wise_cvt
#define _H_elem_wise_cvt

#include "cytnx.hpp"
#include <itensor/all.h>

namespace CytnxConverter {

enum class cvt_case {
  to_cytnx,
  to_itensor
};

void ElemWiseITensorToCytnx(const itensor::ITensor& itensor_T,
                            cytnx::UniTensor* cytnx_T);
void ElemWiseCytnxToITensor(const cytnx::UniTensor& cytnx_T,
                            itensor::ITensor* itensor_T);

}

#endif
