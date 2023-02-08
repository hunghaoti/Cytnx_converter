#include "elem_wise_cvt.h"
namespace CytnxConverter {
void ElemCvt_1(cvt_case, itensor::ITensor& itensor_T, cytnx::UniTensor& cytnx_T);
void ElemCvt_2(cvt_case, itensor::ITensor& itensor_T, cytnx::UniTensor& cytnx_T);
void ElemCvt_3(cvt_case, itensor::ITensor& itensor_T, cytnx::UniTensor& cytnx_T);
void ElemCvt_4(cvt_case, itensor::ITensor& itensor_T, cytnx::UniTensor& cytnx_T);
void ElemCvt_5(cvt_case, itensor::ITensor& itensor_T, cytnx::UniTensor& cytnx_T);
void ElemCvt_6(cvt_case, itensor::ITensor& itensor_T, cytnx::UniTensor& cytnx_T);
void ElemCvt_7(cvt_case, itensor::ITensor& itensor_T, cytnx::UniTensor& cytnx_T);
void ElemCvt_8(cvt_case, itensor::ITensor& itensor_T, cytnx::UniTensor& cytnx_T);
void ElemCvt_9(cvt_case, itensor::ITensor& itensor_T, cytnx::UniTensor& cytnx_T);
void ElemCvt_10(cvt_case, itensor::ITensor& itensor_T, cytnx::UniTensor& cytnx_T);
void ElemWiseITensorToCytnx(const itensor::ITensor& itensor_T,
           cytnx::UniTensor* cytnx_T) {
  auto inds = itensor::inds(itensor_T);
  auto bd_num = inds.size();
  switch (bd_num) {
    case 0:
      break;
    case 1:
       ElemCvt_1(cvt_case::to_cytnx,
                 const_cast<itensor::ITensor&>(itensor_T), *cytnx_T);
      break;
    case 2:
       ElemCvt_2(cvt_case::to_cytnx,
                 const_cast<itensor::ITensor&>(itensor_T), *cytnx_T);
      break;
    case 3:
       ElemCvt_3(cvt_case::to_cytnx,
                 const_cast<itensor::ITensor&>(itensor_T), *cytnx_T);
      break;
    case 4:
       ElemCvt_4(cvt_case::to_cytnx,
                 const_cast<itensor::ITensor&>(itensor_T), *cytnx_T);
      break;
    case 5:
       ElemCvt_5(cvt_case::to_cytnx,
                 const_cast<itensor::ITensor&>(itensor_T), *cytnx_T);
      break;
    case 6:
       ElemCvt_6(cvt_case::to_cytnx,
                 const_cast<itensor::ITensor&>(itensor_T), *cytnx_T);
      break;
    case 7:
       ElemCvt_7(cvt_case::to_cytnx,
                 const_cast<itensor::ITensor&>(itensor_T), *cytnx_T);
      break;
    case 8:
       ElemCvt_8(cvt_case::to_cytnx,
                 const_cast<itensor::ITensor&>(itensor_T), *cytnx_T);
      break;
    case 9:
       ElemCvt_9(cvt_case::to_cytnx,
                 const_cast<itensor::ITensor&>(itensor_T), *cytnx_T);
      break;
    case 10:
       ElemCvt_10(cvt_case::to_cytnx,
                 const_cast<itensor::ITensor&>(itensor_T), *cytnx_T);
      break;
    default:
      throw(std::runtime_error("Converter, Not Implement for bond number larger than 10.\n"));
  }
}

void ElemWiseCytnxToITensor(const cytnx::UniTensor& cytnx_T,
           itensor::ITensor* itensor_T) {
  auto bd_num = cytnx_T.bonds().size();
  switch (bd_num) {
    case 0:
      break;
    case 1:
       ElemCvt_1(cvt_case::to_itensor,
                 *itensor_T, const_cast<cytnx::UniTensor&>(cytnx_T));
      break;
    case 2:
       ElemCvt_2(cvt_case::to_itensor,
                 *itensor_T, const_cast<cytnx::UniTensor&>(cytnx_T));
      break;
    case 3:
       ElemCvt_3(cvt_case::to_itensor,
                 *itensor_T, const_cast<cytnx::UniTensor&>(cytnx_T));
      break;
    case 4:
       ElemCvt_4(cvt_case::to_itensor,
                 *itensor_T, const_cast<cytnx::UniTensor&>(cytnx_T));
      break;
    case 5:
       ElemCvt_5(cvt_case::to_itensor,
                 *itensor_T, const_cast<cytnx::UniTensor&>(cytnx_T));
      break;
    case 6:
       ElemCvt_6(cvt_case::to_itensor,
                 *itensor_T, const_cast<cytnx::UniTensor&>(cytnx_T));
      break;
    case 7:
       ElemCvt_7(cvt_case::to_itensor,
                 *itensor_T, const_cast<cytnx::UniTensor&>(cytnx_T));
      break;
    case 8:
       ElemCvt_8(cvt_case::to_itensor,
                 *itensor_T, const_cast<cytnx::UniTensor&>(cytnx_T));
      break;
    case 9:
       ElemCvt_9(cvt_case::to_itensor,
                 *itensor_T, const_cast<cytnx::UniTensor&>(cytnx_T));
      break;
    case 10:
       ElemCvt_10(cvt_case::to_itensor,
                 *itensor_T, const_cast<cytnx::UniTensor&>(cytnx_T));
      break;
    default:
      throw(std::runtime_error("Converter, Not Implement for bond number larger than 10.\n"));
  }
}

void ElemCvt_1(cvt_case cvt_case, itensor::ITensor& itensor_T, cytnx::UniTensor& cytnx_T) {
  auto inds = itensor::inds(itensor_T);
  for(long i1 = 0; i1< itensor::dim(inds[0]); ++i1)
    if (cytnx_T.at({i1}).exists()) {
      switch (cvt_case) {
        case cvt_case::to_cytnx: 
          if (isReal(itensor_T)) {
            cytnx_T.at({i1}) = elt(itensor_T, i1 + 1);
          } else if (isComplex(itensor_T)) {
            cytnx_T.at({i1}) = eltC(itensor_T, i1 + 1);
          } else {
            throw(std::runtime_error("Converter, Check itensor data type (real or complex)"));
          }    
          break;
        case cvt_case::to_itensor: 
          switch (cytnx_T.dtype()) {
            case cytnx::Type.ComplexDouble: {
              auto val_c = static_cast<cytnx::cytnx_complex128>(cytnx_T.at<cytnx::cytnx_complex128>({i1}));
              itensor_T.set(i1 + 1, val_c);
              break;
            }
            case cytnx::Type.ComplexFloat: {
              auto val_c = static_cast<cytnx::cytnx_complex128>(cytnx_T.at<cytnx::cytnx_complex64>({i1}));
              itensor_T.set(i1 + 1, val_c);
              break;
            }
            case cytnx::Type.Double: {
              auto val_r = static_cast<cytnx::cytnx_double>(cytnx_T.at<cytnx::cytnx_double>({i1}));
              itensor_T.set(i1 + 1, val_r);
              break;
            }
            case cytnx::Type.Float: {
              auto val_r = static_cast<cytnx::cytnx_double>(cytnx_T.at<cytnx::cytnx_float>({i1}));
              itensor_T.set(i1 + 1, val_r);
              break;
            }
            case cytnx::Type.Int64: {
              auto val_r = static_cast<cytnx::cytnx_double>(cytnx_T.at<cytnx::cytnx_int64>({i1}));
              itensor_T.set(i1 + 1, val_r);
              break;
            }
            case cytnx::Type.Uint64: {
              auto val_r = static_cast<cytnx::cytnx_double>(cytnx_T.at<cytnx::cytnx_uint64>({i1}));
              itensor_T.set(i1 + 1, val_r);
              break;
            }
            case cytnx::Type.Int32: {
              auto val_r = static_cast<cytnx::cytnx_double>(cytnx_T.at<cytnx::cytnx_int32>({i1}));
              itensor_T.set(i1 + 1, val_r);
              break;
            }
            case cytnx::Type.Uint32: {
              auto val_r = static_cast<cytnx::cytnx_double>(cytnx_T.at<cytnx::cytnx_uint32>({i1}));
              itensor_T.set(i1 + 1, val_r);
              break;
            }
            case cytnx::Type.Int16: {
              auto val_r = static_cast<cytnx::cytnx_double>(cytnx_T.at<cytnx::cytnx_int16>({i1}));
              itensor_T.set(i1 + 1, val_r);
              break;
            }
            case cytnx::Type.Uint16: {
              auto val_r = static_cast<cytnx::cytnx_double>(cytnx_T.at<cytnx::cytnx_uint16>({i1}));
              itensor_T.set(i1 + 1, val_r);
              break;
            }
            default: {
              throw(std::logic_error("Converter:Cannot convert Bool or Void type.\n"));
            } // default
          } // switch type
          break;
      } // switch cvt case
    } // if exist
} // ElemCvt
void ElemCvt_2(cvt_case cvt_case, itensor::ITensor& itensor_T, cytnx::UniTensor& cytnx_T) {
  auto inds = itensor::inds(itensor_T);
  for(long i1 = 0; i1< itensor::dim(inds[0]); ++i1)
  for(long i2 = 0; i2< itensor::dim(inds[1]); ++i2)
    if (cytnx_T.at({i1, i2}).exists()) {
      switch (cvt_case) {
        case cvt_case::to_cytnx: 
          if (isReal(itensor_T)) {
            cytnx_T.at({i1, i2}) = elt(itensor_T, i1 + 1, i2 + 1);
          } else if (isComplex(itensor_T)) {
            cytnx_T.at({i1, i2}) = eltC(itensor_T, i1 + 1, i2 + 1);
          } else {
            throw(std::runtime_error("Converter, Check itensor data type (real or complex)"));
          }    
          break;
        case cvt_case::to_itensor: 
          switch (cytnx_T.dtype()) {
            case cytnx::Type.ComplexDouble: {
              auto val_c = static_cast<cytnx::cytnx_complex128>(cytnx_T.at<cytnx::cytnx_complex128>({i1, i2}));
              itensor_T.set(i1 + 1, i2 + 1, val_c);
              break;
            }
            case cytnx::Type.ComplexFloat: {
              auto val_c = static_cast<cytnx::cytnx_complex128>(cytnx_T.at<cytnx::cytnx_complex64>({i1, i2}));
              itensor_T.set(i1 + 1, i2 + 1, val_c);
              break;
            }
            case cytnx::Type.Double: {
              auto val_r = static_cast<cytnx::cytnx_double>(cytnx_T.at<cytnx::cytnx_double>({i1, i2}));
              itensor_T.set(i1 + 1, i2 + 1, val_r);
              break;
            }
            case cytnx::Type.Float: {
              auto val_r = static_cast<cytnx::cytnx_double>(cytnx_T.at<cytnx::cytnx_float>({i1, i2}));
              itensor_T.set(i1 + 1, i2 + 1, val_r);
              break;
            }
            case cytnx::Type.Int64: {
              auto val_r = static_cast<cytnx::cytnx_double>(cytnx_T.at<cytnx::cytnx_int64>({i1, i2}));
              itensor_T.set(i1 + 1, i2 + 1, val_r);
              break;
            }
            case cytnx::Type.Uint64: {
              auto val_r = static_cast<cytnx::cytnx_double>(cytnx_T.at<cytnx::cytnx_uint64>({i1, i2}));
              itensor_T.set(i1 + 1, i2 + 1, val_r);
              break;
            }
            case cytnx::Type.Int32: {
              auto val_r = static_cast<cytnx::cytnx_double>(cytnx_T.at<cytnx::cytnx_int32>({i1, i2}));
              itensor_T.set(i1 + 1, i2 + 1, val_r);
              break;
            }
            case cytnx::Type.Uint32: {
              auto val_r = static_cast<cytnx::cytnx_double>(cytnx_T.at<cytnx::cytnx_uint32>({i1, i2}));
              itensor_T.set(i1 + 1, i2 + 1, val_r);
              break;
            }
            case cytnx::Type.Int16: {
              auto val_r = static_cast<cytnx::cytnx_double>(cytnx_T.at<cytnx::cytnx_int16>({i1, i2}));
              itensor_T.set(i1 + 1, i2 + 1, val_r);
              break;
            }
            case cytnx::Type.Uint16: {
              auto val_r = static_cast<cytnx::cytnx_double>(cytnx_T.at<cytnx::cytnx_uint16>({i1, i2}));
              itensor_T.set(i1 + 1, i2 + 1, val_r);
              break;
            }
            default: {
              throw(std::logic_error("Converter:Cannot convert Bool or Void type.\n"));
            } // default
          } // switch type
          break;
      } // switch cvt case
    } // if exist
} // ElemCvt
void ElemCvt_3(cvt_case cvt_case, itensor::ITensor& itensor_T, cytnx::UniTensor& cytnx_T) {
  auto inds = itensor::inds(itensor_T);
  for(long i1 = 0; i1< itensor::dim(inds[0]); ++i1)
  for(long i2 = 0; i2< itensor::dim(inds[1]); ++i2)
  for(long i3 = 0; i3< itensor::dim(inds[2]); ++i3)
    if (cytnx_T.at({i1, i2, i3}).exists()) {
      switch (cvt_case) {
        case cvt_case::to_cytnx: 
          if (isReal(itensor_T)) {
            cytnx_T.at({i1, i2, i3}) = elt(itensor_T, i1 + 1, i2 + 1, i3 + 1);
          } else if (isComplex(itensor_T)) {
            cytnx_T.at({i1, i2, i3}) = eltC(itensor_T, i1 + 1, i2 + 1, i3 + 1);
          } else {
            throw(std::runtime_error("Converter, Check itensor data type (real or complex)"));
          }    
          break;
        case cvt_case::to_itensor: 
          switch (cytnx_T.dtype()) {
            case cytnx::Type.ComplexDouble: {
              auto val_c = static_cast<cytnx::cytnx_complex128>(cytnx_T.at<cytnx::cytnx_complex128>({i1, i2, i3}));
              itensor_T.set(i1 + 1, i2 + 1, i3 + 1, val_c);
              break;
            }
            case cytnx::Type.ComplexFloat: {
              auto val_c = static_cast<cytnx::cytnx_complex128>(cytnx_T.at<cytnx::cytnx_complex64>({i1, i2, i3}));
              itensor_T.set(i1 + 1, i2 + 1, i3 + 1, val_c);
              break;
            }
            case cytnx::Type.Double: {
              auto val_r = static_cast<cytnx::cytnx_double>(cytnx_T.at<cytnx::cytnx_double>({i1, i2, i3}));
              itensor_T.set(i1 + 1, i2 + 1, i3 + 1, val_r);
              break;
            }
            case cytnx::Type.Float: {
              auto val_r = static_cast<cytnx::cytnx_double>(cytnx_T.at<cytnx::cytnx_float>({i1, i2, i3}));
              itensor_T.set(i1 + 1, i2 + 1, i3 + 1, val_r);
              break;
            }
            case cytnx::Type.Int64: {
              auto val_r = static_cast<cytnx::cytnx_double>(cytnx_T.at<cytnx::cytnx_int64>({i1, i2, i3}));
              itensor_T.set(i1 + 1, i2 + 1, i3 + 1, val_r);
              break;
            }
            case cytnx::Type.Uint64: {
              auto val_r = static_cast<cytnx::cytnx_double>(cytnx_T.at<cytnx::cytnx_uint64>({i1, i2, i3}));
              itensor_T.set(i1 + 1, i2 + 1, i3 + 1, val_r);
              break;
            }
            case cytnx::Type.Int32: {
              auto val_r = static_cast<cytnx::cytnx_double>(cytnx_T.at<cytnx::cytnx_int32>({i1, i2, i3}));
              itensor_T.set(i1 + 1, i2 + 1, i3 + 1, val_r);
              break;
            }
            case cytnx::Type.Uint32: {
              auto val_r = static_cast<cytnx::cytnx_double>(cytnx_T.at<cytnx::cytnx_uint32>({i1, i2, i3}));
              itensor_T.set(i1 + 1, i2 + 1, i3 + 1, val_r);
              break;
            }
            case cytnx::Type.Int16: {
              auto val_r = static_cast<cytnx::cytnx_double>(cytnx_T.at<cytnx::cytnx_int16>({i1, i2, i3}));
              itensor_T.set(i1 + 1, i2 + 1, i3 + 1, val_r);
              break;
            }
            case cytnx::Type.Uint16: {
              auto val_r = static_cast<cytnx::cytnx_double>(cytnx_T.at<cytnx::cytnx_uint16>({i1, i2, i3}));
              itensor_T.set(i1 + 1, i2 + 1, i3 + 1, val_r);
              break;
            }
            default: {
              throw(std::logic_error("Converter:Cannot convert Bool or Void type.\n"));
            } // default
          } // switch type
          break;
      } // switch cvt case
    } // if exist
} // ElemCvt
void ElemCvt_4(cvt_case cvt_case, itensor::ITensor& itensor_T, cytnx::UniTensor& cytnx_T) {
  auto inds = itensor::inds(itensor_T);
  for(long i1 = 0; i1< itensor::dim(inds[0]); ++i1)
  for(long i2 = 0; i2< itensor::dim(inds[1]); ++i2)
  for(long i3 = 0; i3< itensor::dim(inds[2]); ++i3)
  for(long i4 = 0; i4< itensor::dim(inds[3]); ++i4)
    if (cytnx_T.at({i1, i2, i3, i4}).exists()) {
      switch (cvt_case) {
        case cvt_case::to_cytnx: 
          if (isReal(itensor_T)) {
            cytnx_T.at({i1, i2, i3, i4}) = elt(itensor_T, i1 + 1, i2 + 1, i3 + 1, i4 + 1);
          } else if (isComplex(itensor_T)) {
            cytnx_T.at({i1, i2, i3, i4}) = eltC(itensor_T, i1 + 1, i2 + 1, i3 + 1, i4 + 1);
          } else {
            throw(std::runtime_error("Converter, Check itensor data type (real or complex)"));
          }    
          break;
        case cvt_case::to_itensor: 
          switch (cytnx_T.dtype()) {
            case cytnx::Type.ComplexDouble: {
              auto val_c = static_cast<cytnx::cytnx_complex128>(cytnx_T.at<cytnx::cytnx_complex128>({i1, i2, i3, i4}));
              itensor_T.set(i1 + 1, i2 + 1, i3 + 1, i4 + 1, val_c);
              break;
            }
            case cytnx::Type.ComplexFloat: {
              auto val_c = static_cast<cytnx::cytnx_complex128>(cytnx_T.at<cytnx::cytnx_complex64>({i1, i2, i3, i4}));
              itensor_T.set(i1 + 1, i2 + 1, i3 + 1, i4 + 1, val_c);
              break;
            }
            case cytnx::Type.Double: {
              auto val_r = static_cast<cytnx::cytnx_double>(cytnx_T.at<cytnx::cytnx_double>({i1, i2, i3, i4}));
              itensor_T.set(i1 + 1, i2 + 1, i3 + 1, i4 + 1, val_r);
              break;
            }
            case cytnx::Type.Float: {
              auto val_r = static_cast<cytnx::cytnx_double>(cytnx_T.at<cytnx::cytnx_float>({i1, i2, i3, i4}));
              itensor_T.set(i1 + 1, i2 + 1, i3 + 1, i4 + 1, val_r);
              break;
            }
            case cytnx::Type.Int64: {
              auto val_r = static_cast<cytnx::cytnx_double>(cytnx_T.at<cytnx::cytnx_int64>({i1, i2, i3, i4}));
              itensor_T.set(i1 + 1, i2 + 1, i3 + 1, i4 + 1, val_r);
              break;
            }
            case cytnx::Type.Uint64: {
              auto val_r = static_cast<cytnx::cytnx_double>(cytnx_T.at<cytnx::cytnx_uint64>({i1, i2, i3, i4}));
              itensor_T.set(i1 + 1, i2 + 1, i3 + 1, i4 + 1, val_r);
              break;
            }
            case cytnx::Type.Int32: {
              auto val_r = static_cast<cytnx::cytnx_double>(cytnx_T.at<cytnx::cytnx_int32>({i1, i2, i3, i4}));
              itensor_T.set(i1 + 1, i2 + 1, i3 + 1, i4 + 1, val_r);
              break;
            }
            case cytnx::Type.Uint32: {
              auto val_r = static_cast<cytnx::cytnx_double>(cytnx_T.at<cytnx::cytnx_uint32>({i1, i2, i3, i4}));
              itensor_T.set(i1 + 1, i2 + 1, i3 + 1, i4 + 1, val_r);
              break;
            }
            case cytnx::Type.Int16: {
              auto val_r = static_cast<cytnx::cytnx_double>(cytnx_T.at<cytnx::cytnx_int16>({i1, i2, i3, i4}));
              itensor_T.set(i1 + 1, i2 + 1, i3 + 1, i4 + 1, val_r);
              break;
            }
            case cytnx::Type.Uint16: {
              auto val_r = static_cast<cytnx::cytnx_double>(cytnx_T.at<cytnx::cytnx_uint16>({i1, i2, i3, i4}));
              itensor_T.set(i1 + 1, i2 + 1, i3 + 1, i4 + 1, val_r);
              break;
            }
            default: {
              throw(std::logic_error("Converter:Cannot convert Bool or Void type.\n"));
            } // default
          } // switch type
          break;
      } // switch cvt case
    } // if exist
} // ElemCvt
void ElemCvt_5(cvt_case cvt_case, itensor::ITensor& itensor_T, cytnx::UniTensor& cytnx_T) {
  auto inds = itensor::inds(itensor_T);
  for(long i1 = 0; i1< itensor::dim(inds[0]); ++i1)
  for(long i2 = 0; i2< itensor::dim(inds[1]); ++i2)
  for(long i3 = 0; i3< itensor::dim(inds[2]); ++i3)
  for(long i4 = 0; i4< itensor::dim(inds[3]); ++i4)
  for(long i5 = 0; i5< itensor::dim(inds[4]); ++i5)
    if (cytnx_T.at({i1, i2, i3, i4, i5}).exists()) {
      switch (cvt_case) {
        case cvt_case::to_cytnx: 
          if (isReal(itensor_T)) {
            cytnx_T.at({i1, i2, i3, i4, i5}) = elt(itensor_T, i1 + 1, i2 + 1, i3 + 1, i4 + 1, i5 + 1);
          } else if (isComplex(itensor_T)) {
            cytnx_T.at({i1, i2, i3, i4, i5}) = eltC(itensor_T, i1 + 1, i2 + 1, i3 + 1, i4 + 1, i5 + 1);
          } else {
            throw(std::runtime_error("Converter, Check itensor data type (real or complex)"));
          }    
          break;
        case cvt_case::to_itensor: 
          switch (cytnx_T.dtype()) {
            case cytnx::Type.ComplexDouble: {
              auto val_c = static_cast<cytnx::cytnx_complex128>(cytnx_T.at<cytnx::cytnx_complex128>({i1, i2, i3, i4, i5}));
              itensor_T.set(i1 + 1, i2 + 1, i3 + 1, i4 + 1, i5 + 1, val_c);
              break;
            }
            case cytnx::Type.ComplexFloat: {
              auto val_c = static_cast<cytnx::cytnx_complex128>(cytnx_T.at<cytnx::cytnx_complex64>({i1, i2, i3, i4, i5}));
              itensor_T.set(i1 + 1, i2 + 1, i3 + 1, i4 + 1, i5 + 1, val_c);
              break;
            }
            case cytnx::Type.Double: {
              auto val_r = static_cast<cytnx::cytnx_double>(cytnx_T.at<cytnx::cytnx_double>({i1, i2, i3, i4, i5}));
              itensor_T.set(i1 + 1, i2 + 1, i3 + 1, i4 + 1, i5 + 1, val_r);
              break;
            }
            case cytnx::Type.Float: {
              auto val_r = static_cast<cytnx::cytnx_double>(cytnx_T.at<cytnx::cytnx_float>({i1, i2, i3, i4, i5}));
              itensor_T.set(i1 + 1, i2 + 1, i3 + 1, i4 + 1, i5 + 1, val_r);
              break;
            }
            case cytnx::Type.Int64: {
              auto val_r = static_cast<cytnx::cytnx_double>(cytnx_T.at<cytnx::cytnx_int64>({i1, i2, i3, i4, i5}));
              itensor_T.set(i1 + 1, i2 + 1, i3 + 1, i4 + 1, i5 + 1, val_r);
              break;
            }
            case cytnx::Type.Uint64: {
              auto val_r = static_cast<cytnx::cytnx_double>(cytnx_T.at<cytnx::cytnx_uint64>({i1, i2, i3, i4, i5}));
              itensor_T.set(i1 + 1, i2 + 1, i3 + 1, i4 + 1, i5 + 1, val_r);
              break;
            }
            case cytnx::Type.Int32: {
              auto val_r = static_cast<cytnx::cytnx_double>(cytnx_T.at<cytnx::cytnx_int32>({i1, i2, i3, i4, i5}));
              itensor_T.set(i1 + 1, i2 + 1, i3 + 1, i4 + 1, i5 + 1, val_r);
              break;
            }
            case cytnx::Type.Uint32: {
              auto val_r = static_cast<cytnx::cytnx_double>(cytnx_T.at<cytnx::cytnx_uint32>({i1, i2, i3, i4, i5}));
              itensor_T.set(i1 + 1, i2 + 1, i3 + 1, i4 + 1, i5 + 1, val_r);
              break;
            }
            case cytnx::Type.Int16: {
              auto val_r = static_cast<cytnx::cytnx_double>(cytnx_T.at<cytnx::cytnx_int16>({i1, i2, i3, i4, i5}));
              itensor_T.set(i1 + 1, i2 + 1, i3 + 1, i4 + 1, i5 + 1, val_r);
              break;
            }
            case cytnx::Type.Uint16: {
              auto val_r = static_cast<cytnx::cytnx_double>(cytnx_T.at<cytnx::cytnx_uint16>({i1, i2, i3, i4, i5}));
              itensor_T.set(i1 + 1, i2 + 1, i3 + 1, i4 + 1, i5 + 1, val_r);
              break;
            }
            default: {
              throw(std::logic_error("Converter:Cannot convert Bool or Void type.\n"));
            } // default
          } // switch type
          break;
      } // switch cvt case
    } // if exist
} // ElemCvt
void ElemCvt_6(cvt_case cvt_case, itensor::ITensor& itensor_T, cytnx::UniTensor& cytnx_T) {
  auto inds = itensor::inds(itensor_T);
  for(long i1 = 0; i1< itensor::dim(inds[0]); ++i1)
  for(long i2 = 0; i2< itensor::dim(inds[1]); ++i2)
  for(long i3 = 0; i3< itensor::dim(inds[2]); ++i3)
  for(long i4 = 0; i4< itensor::dim(inds[3]); ++i4)
  for(long i5 = 0; i5< itensor::dim(inds[4]); ++i5)
  for(long i6 = 0; i6< itensor::dim(inds[5]); ++i6)
    if (cytnx_T.at({i1, i2, i3, i4, i5, i6}).exists()) {
      switch (cvt_case) {
        case cvt_case::to_cytnx: 
          if (isReal(itensor_T)) {
            cytnx_T.at({i1, i2, i3, i4, i5, i6}) = elt(itensor_T, i1 + 1, i2 + 1, i3 + 1, i4 + 1, i5 + 1, i6 + 1);
          } else if (isComplex(itensor_T)) {
            cytnx_T.at({i1, i2, i3, i4, i5, i6}) = eltC(itensor_T, i1 + 1, i2 + 1, i3 + 1, i4 + 1, i5 + 1, i6 + 1);
          } else {
            throw(std::runtime_error("Converter, Check itensor data type (real or complex)"));
          }    
          break;
        case cvt_case::to_itensor: 
          switch (cytnx_T.dtype()) {
            case cytnx::Type.ComplexDouble: {
              auto val_c = static_cast<cytnx::cytnx_complex128>(cytnx_T.at<cytnx::cytnx_complex128>({i1, i2, i3, i4, i5, i6}));
              itensor_T.set(i1 + 1, i2 + 1, i3 + 1, i4 + 1, i5 + 1, i6 + 1, val_c);
              break;
            }
            case cytnx::Type.ComplexFloat: {
              auto val_c = static_cast<cytnx::cytnx_complex128>(cytnx_T.at<cytnx::cytnx_complex64>({i1, i2, i3, i4, i5, i6}));
              itensor_T.set(i1 + 1, i2 + 1, i3 + 1, i4 + 1, i5 + 1, i6 + 1, val_c);
              break;
            }
            case cytnx::Type.Double: {
              auto val_r = static_cast<cytnx::cytnx_double>(cytnx_T.at<cytnx::cytnx_double>({i1, i2, i3, i4, i5, i6}));
              itensor_T.set(i1 + 1, i2 + 1, i3 + 1, i4 + 1, i5 + 1, i6 + 1, val_r);
              break;
            }
            case cytnx::Type.Float: {
              auto val_r = static_cast<cytnx::cytnx_double>(cytnx_T.at<cytnx::cytnx_float>({i1, i2, i3, i4, i5, i6}));
              itensor_T.set(i1 + 1, i2 + 1, i3 + 1, i4 + 1, i5 + 1, i6 + 1, val_r);
              break;
            }
            case cytnx::Type.Int64: {
              auto val_r = static_cast<cytnx::cytnx_double>(cytnx_T.at<cytnx::cytnx_int64>({i1, i2, i3, i4, i5, i6}));
              itensor_T.set(i1 + 1, i2 + 1, i3 + 1, i4 + 1, i5 + 1, i6 + 1, val_r);
              break;
            }
            case cytnx::Type.Uint64: {
              auto val_r = static_cast<cytnx::cytnx_double>(cytnx_T.at<cytnx::cytnx_uint64>({i1, i2, i3, i4, i5, i6}));
              itensor_T.set(i1 + 1, i2 + 1, i3 + 1, i4 + 1, i5 + 1, i6 + 1, val_r);
              break;
            }
            case cytnx::Type.Int32: {
              auto val_r = static_cast<cytnx::cytnx_double>(cytnx_T.at<cytnx::cytnx_int32>({i1, i2, i3, i4, i5, i6}));
              itensor_T.set(i1 + 1, i2 + 1, i3 + 1, i4 + 1, i5 + 1, i6 + 1, val_r);
              break;
            }
            case cytnx::Type.Uint32: {
              auto val_r = static_cast<cytnx::cytnx_double>(cytnx_T.at<cytnx::cytnx_uint32>({i1, i2, i3, i4, i5, i6}));
              itensor_T.set(i1 + 1, i2 + 1, i3 + 1, i4 + 1, i5 + 1, i6 + 1, val_r);
              break;
            }
            case cytnx::Type.Int16: {
              auto val_r = static_cast<cytnx::cytnx_double>(cytnx_T.at<cytnx::cytnx_int16>({i1, i2, i3, i4, i5, i6}));
              itensor_T.set(i1 + 1, i2 + 1, i3 + 1, i4 + 1, i5 + 1, i6 + 1, val_r);
              break;
            }
            case cytnx::Type.Uint16: {
              auto val_r = static_cast<cytnx::cytnx_double>(cytnx_T.at<cytnx::cytnx_uint16>({i1, i2, i3, i4, i5, i6}));
              itensor_T.set(i1 + 1, i2 + 1, i3 + 1, i4 + 1, i5 + 1, i6 + 1, val_r);
              break;
            }
            default: {
              throw(std::logic_error("Converter:Cannot convert Bool or Void type.\n"));
            } // default
          } // switch type
          break;
      } // switch cvt case
    } // if exist
} // ElemCvt
void ElemCvt_7(cvt_case cvt_case, itensor::ITensor& itensor_T, cytnx::UniTensor& cytnx_T) {
  auto inds = itensor::inds(itensor_T);
  for(long i1 = 0; i1< itensor::dim(inds[0]); ++i1)
  for(long i2 = 0; i2< itensor::dim(inds[1]); ++i2)
  for(long i3 = 0; i3< itensor::dim(inds[2]); ++i3)
  for(long i4 = 0; i4< itensor::dim(inds[3]); ++i4)
  for(long i5 = 0; i5< itensor::dim(inds[4]); ++i5)
  for(long i6 = 0; i6< itensor::dim(inds[5]); ++i6)
  for(long i7 = 0; i7< itensor::dim(inds[6]); ++i7)
    if (cytnx_T.at({i1, i2, i3, i4, i5, i6, i7}).exists()) {
      switch (cvt_case) {
        case cvt_case::to_cytnx: 
          if (isReal(itensor_T)) {
            cytnx_T.at({i1, i2, i3, i4, i5, i6, i7}) = elt(itensor_T, i1 + 1, i2 + 1, i3 + 1, i4 + 1, i5 + 1, i6 + 1, i7 + 1);
          } else if (isComplex(itensor_T)) {
            cytnx_T.at({i1, i2, i3, i4, i5, i6, i7}) = eltC(itensor_T, i1 + 1, i2 + 1, i3 + 1, i4 + 1, i5 + 1, i6 + 1, i7 + 1);
          } else {
            throw(std::runtime_error("Converter, Check itensor data type (real or complex)"));
          }    
          break;
        case cvt_case::to_itensor: 
          switch (cytnx_T.dtype()) {
            case cytnx::Type.ComplexDouble: {
              auto val_c = static_cast<cytnx::cytnx_complex128>(cytnx_T.at<cytnx::cytnx_complex128>({i1, i2, i3, i4, i5, i6, i7}));
              itensor_T.set(i1 + 1, i2 + 1, i3 + 1, i4 + 1, i5 + 1, i6 + 1, i7 + 1, val_c);
              break;
            }
            case cytnx::Type.ComplexFloat: {
              auto val_c = static_cast<cytnx::cytnx_complex128>(cytnx_T.at<cytnx::cytnx_complex64>({i1, i2, i3, i4, i5, i6, i7}));
              itensor_T.set(i1 + 1, i2 + 1, i3 + 1, i4 + 1, i5 + 1, i6 + 1, i7 + 1, val_c);
              break;
            }
            case cytnx::Type.Double: {
              auto val_r = static_cast<cytnx::cytnx_double>(cytnx_T.at<cytnx::cytnx_double>({i1, i2, i3, i4, i5, i6, i7}));
              itensor_T.set(i1 + 1, i2 + 1, i3 + 1, i4 + 1, i5 + 1, i6 + 1, i7 + 1, val_r);
              break;
            }
            case cytnx::Type.Float: {
              auto val_r = static_cast<cytnx::cytnx_double>(cytnx_T.at<cytnx::cytnx_float>({i1, i2, i3, i4, i5, i6, i7}));
              itensor_T.set(i1 + 1, i2 + 1, i3 + 1, i4 + 1, i5 + 1, i6 + 1, i7 + 1, val_r);
              break;
            }
            case cytnx::Type.Int64: {
              auto val_r = static_cast<cytnx::cytnx_double>(cytnx_T.at<cytnx::cytnx_int64>({i1, i2, i3, i4, i5, i6, i7}));
              itensor_T.set(i1 + 1, i2 + 1, i3 + 1, i4 + 1, i5 + 1, i6 + 1, i7 + 1, val_r);
              break;
            }
            case cytnx::Type.Uint64: {
              auto val_r = static_cast<cytnx::cytnx_double>(cytnx_T.at<cytnx::cytnx_uint64>({i1, i2, i3, i4, i5, i6, i7}));
              itensor_T.set(i1 + 1, i2 + 1, i3 + 1, i4 + 1, i5 + 1, i6 + 1, i7 + 1, val_r);
              break;
            }
            case cytnx::Type.Int32: {
              auto val_r = static_cast<cytnx::cytnx_double>(cytnx_T.at<cytnx::cytnx_int32>({i1, i2, i3, i4, i5, i6, i7}));
              itensor_T.set(i1 + 1, i2 + 1, i3 + 1, i4 + 1, i5 + 1, i6 + 1, i7 + 1, val_r);
              break;
            }
            case cytnx::Type.Uint32: {
              auto val_r = static_cast<cytnx::cytnx_double>(cytnx_T.at<cytnx::cytnx_uint32>({i1, i2, i3, i4, i5, i6, i7}));
              itensor_T.set(i1 + 1, i2 + 1, i3 + 1, i4 + 1, i5 + 1, i6 + 1, i7 + 1, val_r);
              break;
            }
            case cytnx::Type.Int16: {
              auto val_r = static_cast<cytnx::cytnx_double>(cytnx_T.at<cytnx::cytnx_int16>({i1, i2, i3, i4, i5, i6, i7}));
              itensor_T.set(i1 + 1, i2 + 1, i3 + 1, i4 + 1, i5 + 1, i6 + 1, i7 + 1, val_r);
              break;
            }
            case cytnx::Type.Uint16: {
              auto val_r = static_cast<cytnx::cytnx_double>(cytnx_T.at<cytnx::cytnx_uint16>({i1, i2, i3, i4, i5, i6, i7}));
              itensor_T.set(i1 + 1, i2 + 1, i3 + 1, i4 + 1, i5 + 1, i6 + 1, i7 + 1, val_r);
              break;
            }
            default: {
              throw(std::logic_error("Converter:Cannot convert Bool or Void type.\n"));
            } // default
          } // switch type
          break;
      } // switch cvt case
    } // if exist
} // ElemCvt
void ElemCvt_8(cvt_case cvt_case, itensor::ITensor& itensor_T, cytnx::UniTensor& cytnx_T) {
  auto inds = itensor::inds(itensor_T);
  for(long i1 = 0; i1< itensor::dim(inds[0]); ++i1)
  for(long i2 = 0; i2< itensor::dim(inds[1]); ++i2)
  for(long i3 = 0; i3< itensor::dim(inds[2]); ++i3)
  for(long i4 = 0; i4< itensor::dim(inds[3]); ++i4)
  for(long i5 = 0; i5< itensor::dim(inds[4]); ++i5)
  for(long i6 = 0; i6< itensor::dim(inds[5]); ++i6)
  for(long i7 = 0; i7< itensor::dim(inds[6]); ++i7)
  for(long i8 = 0; i8< itensor::dim(inds[7]); ++i8)
    if (cytnx_T.at({i1, i2, i3, i4, i5, i6, i7, i8}).exists()) {
      switch (cvt_case) {
        case cvt_case::to_cytnx: 
          if (isReal(itensor_T)) {
            cytnx_T.at({i1, i2, i3, i4, i5, i6, i7, i8}) = elt(itensor_T, i1 + 1, i2 + 1, i3 + 1, i4 + 1, i5 + 1, i6 + 1, i7 + 1, i8 + 1);
          } else if (isComplex(itensor_T)) {
            cytnx_T.at({i1, i2, i3, i4, i5, i6, i7, i8}) = eltC(itensor_T, i1 + 1, i2 + 1, i3 + 1, i4 + 1, i5 + 1, i6 + 1, i7 + 1, i8 + 1);
          } else {
            throw(std::runtime_error("Converter, Check itensor data type (real or complex)"));
          }    
          break;
        case cvt_case::to_itensor: 
          switch (cytnx_T.dtype()) {
            case cytnx::Type.ComplexDouble: {
              auto val_c = static_cast<cytnx::cytnx_complex128>(cytnx_T.at<cytnx::cytnx_complex128>({i1, i2, i3, i4, i5, i6, i7, i8}));
              itensor_T.set(i1 + 1, i2 + 1, i3 + 1, i4 + 1, i5 + 1, i6 + 1, i7 + 1, i8 + 1, val_c);
              break;
            }
            case cytnx::Type.ComplexFloat: {
              auto val_c = static_cast<cytnx::cytnx_complex128>(cytnx_T.at<cytnx::cytnx_complex64>({i1, i2, i3, i4, i5, i6, i7, i8}));
              itensor_T.set(i1 + 1, i2 + 1, i3 + 1, i4 + 1, i5 + 1, i6 + 1, i7 + 1, i8 + 1, val_c);
              break;
            }
            case cytnx::Type.Double: {
              auto val_r = static_cast<cytnx::cytnx_double>(cytnx_T.at<cytnx::cytnx_double>({i1, i2, i3, i4, i5, i6, i7, i8}));
              itensor_T.set(i1 + 1, i2 + 1, i3 + 1, i4 + 1, i5 + 1, i6 + 1, i7 + 1, i8 + 1, val_r);
              break;
            }
            case cytnx::Type.Float: {
              auto val_r = static_cast<cytnx::cytnx_double>(cytnx_T.at<cytnx::cytnx_float>({i1, i2, i3, i4, i5, i6, i7, i8}));
              itensor_T.set(i1 + 1, i2 + 1, i3 + 1, i4 + 1, i5 + 1, i6 + 1, i7 + 1, i8 + 1, val_r);
              break;
            }
            case cytnx::Type.Int64: {
              auto val_r = static_cast<cytnx::cytnx_double>(cytnx_T.at<cytnx::cytnx_int64>({i1, i2, i3, i4, i5, i6, i7, i8}));
              itensor_T.set(i1 + 1, i2 + 1, i3 + 1, i4 + 1, i5 + 1, i6 + 1, i7 + 1, i8 + 1, val_r);
              break;
            }
            case cytnx::Type.Uint64: {
              auto val_r = static_cast<cytnx::cytnx_double>(cytnx_T.at<cytnx::cytnx_uint64>({i1, i2, i3, i4, i5, i6, i7, i8}));
              itensor_T.set(i1 + 1, i2 + 1, i3 + 1, i4 + 1, i5 + 1, i6 + 1, i7 + 1, i8 + 1, val_r);
              break;
            }
            case cytnx::Type.Int32: {
              auto val_r = static_cast<cytnx::cytnx_double>(cytnx_T.at<cytnx::cytnx_int32>({i1, i2, i3, i4, i5, i6, i7, i8}));
              itensor_T.set(i1 + 1, i2 + 1, i3 + 1, i4 + 1, i5 + 1, i6 + 1, i7 + 1, i8 + 1, val_r);
              break;
            }
            case cytnx::Type.Uint32: {
              auto val_r = static_cast<cytnx::cytnx_double>(cytnx_T.at<cytnx::cytnx_uint32>({i1, i2, i3, i4, i5, i6, i7, i8}));
              itensor_T.set(i1 + 1, i2 + 1, i3 + 1, i4 + 1, i5 + 1, i6 + 1, i7 + 1, i8 + 1, val_r);
              break;
            }
            case cytnx::Type.Int16: {
              auto val_r = static_cast<cytnx::cytnx_double>(cytnx_T.at<cytnx::cytnx_int16>({i1, i2, i3, i4, i5, i6, i7, i8}));
              itensor_T.set(i1 + 1, i2 + 1, i3 + 1, i4 + 1, i5 + 1, i6 + 1, i7 + 1, i8 + 1, val_r);
              break;
            }
            case cytnx::Type.Uint16: {
              auto val_r = static_cast<cytnx::cytnx_double>(cytnx_T.at<cytnx::cytnx_uint16>({i1, i2, i3, i4, i5, i6, i7, i8}));
              itensor_T.set(i1 + 1, i2 + 1, i3 + 1, i4 + 1, i5 + 1, i6 + 1, i7 + 1, i8 + 1, val_r);
              break;
            }
            default: {
              throw(std::logic_error("Converter:Cannot convert Bool or Void type.\n"));
            } // default
          } // switch type
          break;
      } // switch cvt case
    } // if exist
} // ElemCvt
void ElemCvt_9(cvt_case cvt_case, itensor::ITensor& itensor_T, cytnx::UniTensor& cytnx_T) {
  auto inds = itensor::inds(itensor_T);
  for(long i1 = 0; i1< itensor::dim(inds[0]); ++i1)
  for(long i2 = 0; i2< itensor::dim(inds[1]); ++i2)
  for(long i3 = 0; i3< itensor::dim(inds[2]); ++i3)
  for(long i4 = 0; i4< itensor::dim(inds[3]); ++i4)
  for(long i5 = 0; i5< itensor::dim(inds[4]); ++i5)
  for(long i6 = 0; i6< itensor::dim(inds[5]); ++i6)
  for(long i7 = 0; i7< itensor::dim(inds[6]); ++i7)
  for(long i8 = 0; i8< itensor::dim(inds[7]); ++i8)
  for(long i9 = 0; i9< itensor::dim(inds[8]); ++i9)
    if (cytnx_T.at({i1, i2, i3, i4, i5, i6, i7, i8, i9}).exists()) {
      switch (cvt_case) {
        case cvt_case::to_cytnx: 
          if (isReal(itensor_T)) {
            cytnx_T.at({i1, i2, i3, i4, i5, i6, i7, i8, i9}) = elt(itensor_T, i1 + 1, i2 + 1, i3 + 1, i4 + 1, i5 + 1, i6 + 1, i7 + 1, i8 + 1, i9 + 1);
          } else if (isComplex(itensor_T)) {
            cytnx_T.at({i1, i2, i3, i4, i5, i6, i7, i8, i9}) = eltC(itensor_T, i1 + 1, i2 + 1, i3 + 1, i4 + 1, i5 + 1, i6 + 1, i7 + 1, i8 + 1, i9 + 1);
          } else {
            throw(std::runtime_error("Converter, Check itensor data type (real or complex)"));
          }    
          break;
        case cvt_case::to_itensor: 
          switch (cytnx_T.dtype()) {
            case cytnx::Type.ComplexDouble: {
              auto val_c = static_cast<cytnx::cytnx_complex128>(cytnx_T.at<cytnx::cytnx_complex128>({i1, i2, i3, i4, i5, i6, i7, i8, i9}));
              itensor_T.set(i1 + 1, i2 + 1, i3 + 1, i4 + 1, i5 + 1, i6 + 1, i7 + 1, i8 + 1, i9 + 1, val_c);
              break;
            }
            case cytnx::Type.ComplexFloat: {
              auto val_c = static_cast<cytnx::cytnx_complex128>(cytnx_T.at<cytnx::cytnx_complex64>({i1, i2, i3, i4, i5, i6, i7, i8, i9}));
              itensor_T.set(i1 + 1, i2 + 1, i3 + 1, i4 + 1, i5 + 1, i6 + 1, i7 + 1, i8 + 1, i9 + 1, val_c);
              break;
            }
            case cytnx::Type.Double: {
              auto val_r = static_cast<cytnx::cytnx_double>(cytnx_T.at<cytnx::cytnx_double>({i1, i2, i3, i4, i5, i6, i7, i8, i9}));
              itensor_T.set(i1 + 1, i2 + 1, i3 + 1, i4 + 1, i5 + 1, i6 + 1, i7 + 1, i8 + 1, i9 + 1, val_r);
              break;
            }
            case cytnx::Type.Float: {
              auto val_r = static_cast<cytnx::cytnx_double>(cytnx_T.at<cytnx::cytnx_float>({i1, i2, i3, i4, i5, i6, i7, i8, i9}));
              itensor_T.set(i1 + 1, i2 + 1, i3 + 1, i4 + 1, i5 + 1, i6 + 1, i7 + 1, i8 + 1, i9 + 1, val_r);
              break;
            }
            case cytnx::Type.Int64: {
              auto val_r = static_cast<cytnx::cytnx_double>(cytnx_T.at<cytnx::cytnx_int64>({i1, i2, i3, i4, i5, i6, i7, i8, i9}));
              itensor_T.set(i1 + 1, i2 + 1, i3 + 1, i4 + 1, i5 + 1, i6 + 1, i7 + 1, i8 + 1, i9 + 1, val_r);
              break;
            }
            case cytnx::Type.Uint64: {
              auto val_r = static_cast<cytnx::cytnx_double>(cytnx_T.at<cytnx::cytnx_uint64>({i1, i2, i3, i4, i5, i6, i7, i8, i9}));
              itensor_T.set(i1 + 1, i2 + 1, i3 + 1, i4 + 1, i5 + 1, i6 + 1, i7 + 1, i8 + 1, i9 + 1, val_r);
              break;
            }
            case cytnx::Type.Int32: {
              auto val_r = static_cast<cytnx::cytnx_double>(cytnx_T.at<cytnx::cytnx_int32>({i1, i2, i3, i4, i5, i6, i7, i8, i9}));
              itensor_T.set(i1 + 1, i2 + 1, i3 + 1, i4 + 1, i5 + 1, i6 + 1, i7 + 1, i8 + 1, i9 + 1, val_r);
              break;
            }
            case cytnx::Type.Uint32: {
              auto val_r = static_cast<cytnx::cytnx_double>(cytnx_T.at<cytnx::cytnx_uint32>({i1, i2, i3, i4, i5, i6, i7, i8, i9}));
              itensor_T.set(i1 + 1, i2 + 1, i3 + 1, i4 + 1, i5 + 1, i6 + 1, i7 + 1, i8 + 1, i9 + 1, val_r);
              break;
            }
            case cytnx::Type.Int16: {
              auto val_r = static_cast<cytnx::cytnx_double>(cytnx_T.at<cytnx::cytnx_int16>({i1, i2, i3, i4, i5, i6, i7, i8, i9}));
              itensor_T.set(i1 + 1, i2 + 1, i3 + 1, i4 + 1, i5 + 1, i6 + 1, i7 + 1, i8 + 1, i9 + 1, val_r);
              break;
            }
            case cytnx::Type.Uint16: {
              auto val_r = static_cast<cytnx::cytnx_double>(cytnx_T.at<cytnx::cytnx_uint16>({i1, i2, i3, i4, i5, i6, i7, i8, i9}));
              itensor_T.set(i1 + 1, i2 + 1, i3 + 1, i4 + 1, i5 + 1, i6 + 1, i7 + 1, i8 + 1, i9 + 1, val_r);
              break;
            }
            default: {
              throw(std::logic_error("Converter:Cannot convert Bool or Void type.\n"));
            } // default
          } // switch type
          break;
      } // switch cvt case
    } // if exist
} // ElemCvt
void ElemCvt_10(cvt_case cvt_case, itensor::ITensor& itensor_T, cytnx::UniTensor& cytnx_T) {
  auto inds = itensor::inds(itensor_T);
  for(long i1 = 0; i1< itensor::dim(inds[0]); ++i1)
  for(long i2 = 0; i2< itensor::dim(inds[1]); ++i2)
  for(long i3 = 0; i3< itensor::dim(inds[2]); ++i3)
  for(long i4 = 0; i4< itensor::dim(inds[3]); ++i4)
  for(long i5 = 0; i5< itensor::dim(inds[4]); ++i5)
  for(long i6 = 0; i6< itensor::dim(inds[5]); ++i6)
  for(long i7 = 0; i7< itensor::dim(inds[6]); ++i7)
  for(long i8 = 0; i8< itensor::dim(inds[7]); ++i8)
  for(long i9 = 0; i9< itensor::dim(inds[8]); ++i9)
  for(long i10 = 0; i10< itensor::dim(inds[9]); ++i10)
    if (cytnx_T.at({i1, i2, i3, i4, i5, i6, i7, i8, i9, i10}).exists()) {
      switch (cvt_case) {
        case cvt_case::to_cytnx: 
          if (isReal(itensor_T)) {
            cytnx_T.at({i1, i2, i3, i4, i5, i6, i7, i8, i9, i10}) = elt(itensor_T, i1 + 1, i2 + 1, i3 + 1, i4 + 1, i5 + 1, i6 + 1, i7 + 1, i8 + 1, i9 + 1, i10 + 1);
          } else if (isComplex(itensor_T)) {
            cytnx_T.at({i1, i2, i3, i4, i5, i6, i7, i8, i9, i10}) = eltC(itensor_T, i1 + 1, i2 + 1, i3 + 1, i4 + 1, i5 + 1, i6 + 1, i7 + 1, i8 + 1, i9 + 1, i10 + 1);
          } else {
            throw(std::runtime_error("Converter, Check itensor data type (real or complex)"));
          }    
          break;
        case cvt_case::to_itensor: 
          switch (cytnx_T.dtype()) {
            case cytnx::Type.ComplexDouble: {
              auto val_c = static_cast<cytnx::cytnx_complex128>(cytnx_T.at<cytnx::cytnx_complex128>({i1, i2, i3, i4, i5, i6, i7, i8, i9, i10}));
              itensor_T.set(i1 + 1, i2 + 1, i3 + 1, i4 + 1, i5 + 1, i6 + 1, i7 + 1, i8 + 1, i9 + 1, i10 + 1, val_c);
              break;
            }
            case cytnx::Type.ComplexFloat: {
              auto val_c = static_cast<cytnx::cytnx_complex128>(cytnx_T.at<cytnx::cytnx_complex64>({i1, i2, i3, i4, i5, i6, i7, i8, i9, i10}));
              itensor_T.set(i1 + 1, i2 + 1, i3 + 1, i4 + 1, i5 + 1, i6 + 1, i7 + 1, i8 + 1, i9 + 1, i10 + 1, val_c);
              break;
            }
            case cytnx::Type.Double: {
              auto val_r = static_cast<cytnx::cytnx_double>(cytnx_T.at<cytnx::cytnx_double>({i1, i2, i3, i4, i5, i6, i7, i8, i9, i10}));
              itensor_T.set(i1 + 1, i2 + 1, i3 + 1, i4 + 1, i5 + 1, i6 + 1, i7 + 1, i8 + 1, i9 + 1, i10 + 1, val_r);
              break;
            }
            case cytnx::Type.Float: {
              auto val_r = static_cast<cytnx::cytnx_double>(cytnx_T.at<cytnx::cytnx_float>({i1, i2, i3, i4, i5, i6, i7, i8, i9, i10}));
              itensor_T.set(i1 + 1, i2 + 1, i3 + 1, i4 + 1, i5 + 1, i6 + 1, i7 + 1, i8 + 1, i9 + 1, i10 + 1, val_r);
              break;
            }
            case cytnx::Type.Int64: {
              auto val_r = static_cast<cytnx::cytnx_double>(cytnx_T.at<cytnx::cytnx_int64>({i1, i2, i3, i4, i5, i6, i7, i8, i9, i10}));
              itensor_T.set(i1 + 1, i2 + 1, i3 + 1, i4 + 1, i5 + 1, i6 + 1, i7 + 1, i8 + 1, i9 + 1, i10 + 1, val_r);
              break;
            }
            case cytnx::Type.Uint64: {
              auto val_r = static_cast<cytnx::cytnx_double>(cytnx_T.at<cytnx::cytnx_uint64>({i1, i2, i3, i4, i5, i6, i7, i8, i9, i10}));
              itensor_T.set(i1 + 1, i2 + 1, i3 + 1, i4 + 1, i5 + 1, i6 + 1, i7 + 1, i8 + 1, i9 + 1, i10 + 1, val_r);
              break;
            }
            case cytnx::Type.Int32: {
              auto val_r = static_cast<cytnx::cytnx_double>(cytnx_T.at<cytnx::cytnx_int32>({i1, i2, i3, i4, i5, i6, i7, i8, i9, i10}));
              itensor_T.set(i1 + 1, i2 + 1, i3 + 1, i4 + 1, i5 + 1, i6 + 1, i7 + 1, i8 + 1, i9 + 1, i10 + 1, val_r);
              break;
            }
            case cytnx::Type.Uint32: {
              auto val_r = static_cast<cytnx::cytnx_double>(cytnx_T.at<cytnx::cytnx_uint32>({i1, i2, i3, i4, i5, i6, i7, i8, i9, i10}));
              itensor_T.set(i1 + 1, i2 + 1, i3 + 1, i4 + 1, i5 + 1, i6 + 1, i7 + 1, i8 + 1, i9 + 1, i10 + 1, val_r);
              break;
            }
            case cytnx::Type.Int16: {
              auto val_r = static_cast<cytnx::cytnx_double>(cytnx_T.at<cytnx::cytnx_int16>({i1, i2, i3, i4, i5, i6, i7, i8, i9, i10}));
              itensor_T.set(i1 + 1, i2 + 1, i3 + 1, i4 + 1, i5 + 1, i6 + 1, i7 + 1, i8 + 1, i9 + 1, i10 + 1, val_r);
              break;
            }
            case cytnx::Type.Uint16: {
              auto val_r = static_cast<cytnx::cytnx_double>(cytnx_T.at<cytnx::cytnx_uint16>({i1, i2, i3, i4, i5, i6, i7, i8, i9, i10}));
              itensor_T.set(i1 + 1, i2 + 1, i3 + 1, i4 + 1, i5 + 1, i6 + 1, i7 + 1, i8 + 1, i9 + 1, i10 + 1, val_r);
              break;
            }
            default: {
              throw(std::logic_error("Converter:Cannot convert Bool or Void type.\n"));
            } // default
          } // switch type
          break;
      } // switch cvt case
    } // if exist
} // ElemCvt
} // namespace
