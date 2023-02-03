# Cytnx_converter
This project is about the converter between 
[cytnx](https://github.com/kaihsin/Cytnx "Title") and
[itensor](https://itensor.org/) in C++ API.

You can see "main.cpp" to see how to use it.

```c
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

```

Before using the tools, please fix the root of the installed libreies (cytnx & itensor) in the *Makefile*.
The API of the converter is in the file 'cyntx_converter.h'.
