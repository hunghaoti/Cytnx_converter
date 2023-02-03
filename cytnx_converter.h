#ifndef _H_cytnx_converter
#define _H_cytnx_converter

#include "cytnx.hpp"
#include <itensor/all.h>

namespace CytnxConverter {

cytnx::Bond ConvertToCytnx (const itensor::Index& itens_index);
cytnx::UniTensor ConvertToCytnx (const itensor::ITensor& tens_itensor);
itensor::Index ConvertToITensor (const cytnx::Bond& cytnx_bd, std::string label = "");
itensor::ITensor ConvertToITensor (const cytnx::UniTensor& cytnx_UniTensor);

}

#endif
