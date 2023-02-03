#include <cytnx.hpp>
#include <itensor/all.h>
#include "cytnx_converter.h"
 
int main() {
  cytnx::UniTensor cytnx_UT1 = cytnx::UniTensor::Load("U1xZ2_C128.cytnx");
  itensor::ITensor itensor_IT = CytnxConverter::ConvertToITensor(cytnx_UT1);
  cytnx::UniTensor cytnx_UT2 = CytnxConverter::ConvertToCytnx(itensor_IT);
  std::cout << (cytnx_UT1 - cytnx_UT2).Norm() << std::endl;
  return 0;
}
