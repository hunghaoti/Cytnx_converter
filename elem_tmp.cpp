enum class cvt_case {
  to_cytnx,
  to_itensor
};
void ElemWiseITensorToCytnx(const itensor::ITensor& itensor_T, 
                            *cytnx::UniTensor cytnx_T) {
  auto inds = itensor::inds(itensor_T);
  auto bd_num = inds.size();
  switch (bd_num) {
    case 2:
      ElemCvt_2(cvt_case::to_cytnx, itensor_T, *cytnx_T);
      break;
    default:
      assert(false);
  }
}

void ElemCvt_2(cvt_case, itensor::ITensor& itensor_T, cytnx::UniTensor cutnx_T) {
  for (long i1 = 0; i1 < dim(inds[1]); ++i1) {
    for (long i2 = 0; i2 < dim(inds[2]); ++i2) {
      if (cytnx_T.at({i1, i2}).exists()) {
          cytnx_T.at({i1, i2}) = elt(itensor_T, i1 + 1, i2 + 1);
      }
    }
  }
}
