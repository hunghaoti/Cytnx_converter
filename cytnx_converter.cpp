#include "cytnx_converter.h"
#include "elem_wise_cvt.h"

namespace CytnxConverter {

cytnx::Bond ToCytnxBond (const itensor::Index& itens_index);
itensor::Index ToITensorIndex (const cytnx::Bond& cytnx_bd, std::string label = "");
cytnx::UniTensor ToCytnxUniTensor (const itensor::ITensor& tens_itensor);
itensor::ITensor ToITensorITensor (const cytnx::UniTensor& cytnx_UniTensor);

cytnx::Bond ConvertToCytnx (const itensor::Index& itens_index) {
  return ToCytnxBond(itens_index);
}
cytnx::UniTensor ConvertToCytnx (const itensor::ITensor& tens_itensor) {
  return ToCytnxUniTensor(tens_itensor);
}
itensor::Index ConvertToITensor (const cytnx::Bond& cytnx_bd, std::string label) {
  return ToITensorIndex(cytnx_bd, label);
}
itensor::ITensor ConvertToITensor (const cytnx::UniTensor& cytnx_UniTensor) {
  return ToITensorITensor(cytnx_UniTensor);
}


//itensor always return 4 when call the member function size of the class QN. It may be the bug of 
//  the itensor. So why I create the function to get the size of QN by ourself.
int GetQNSize(const itensor::QN& qn) {
  int cnt = 1;
  while (qn.mod(cnt) != 0) { cnt++; }
  return cnt - 1;
}

cytnx::Bond ToCytnxBond (const itensor::Index& itens_index) {
  itensor::Arrow dir_type = itensor::dir(itens_index);
  if (dir_type == itensor::Neither) {
    throw(std::logic_error( "error:" + std::string(__FUNCTION__) + 
        "converter still not implement for regular (non symmetry) index.\n"));
  }
  //qunatum number and degeneracy
  auto fst_qn = itensor::qn(itens_index, 1);
  auto fst_qn_size = GetQNSize(fst_qn);
  std::vector<std::vector<cytnx::cytnx_int64>> qnums;
  std::vector<cytnx::cytnx_uint64> degs;
  for (int i = 0; i < nblock(itens_index); ++i) {
    degs.push_back(itensor::blocksize(itens_index, i + 1));
    itensor::QN qn = itensor::qn(itens_index, i + 1);
    std::vector<cytnx::cytnx_int64> qnums_sub;
    auto qn_size = GetQNSize(qn);
    if (qn_size != fst_qn_size) {
      throw(std::logic_error("error:" + std::string(__FUNCTION__) + 
          "converter cannot convert QN with different size in the same "
	   "index to cytnx bond"));
    }
    for (int qnum_idx = 0; qnum_idx < qn_size; ++qnum_idx) {
      qnums_sub.push_back(qn.val(qnum_idx + 1));
    }
    qnums.push_back(qnums_sub);
  }
  //symmteries
  auto syms = std::vector<cytnx::Symmetry>();
  for (int i = 0; i < qnums[0].size(); ++i) {
    if (fst_qn.num(i + 1).mod() <= 0) {
      throw(std::logic_error( "error:" + std::string(__FUNCTION__) + 
           "converter not implement for symmetry mod < 0 case. (Fermion).\n"));
    }
    auto mod = fst_qn.num(i + 1).mod();
    cytnx::Symmetry sym = mod == 1 ? 
        cytnx::Symmetry(cytnx::SymType.U) : cytnx::Symmetry(cytnx::SymType.Z, mod);
    syms.push_back(sym);
  }
  //direction (ket or bra)
  cytnx::bondType bd_type = dir_type == itensor::Out ? cytnx::BD_BRA : cytnx::BD_KET;
  //construct Bond
  cytnx::Bond cytnx_bd = cytnx::Bond(bd_type, qnums, degs, syms);
  return cytnx_bd;
}

itensor::Index ToITensorIndex (const cytnx::Bond& cytnx_bd, std::string label) {
  const cytnx::bondType bd_type = cytnx_bd.type();
  if (bd_type == cytnx::BD_REG) {
    throw(std::logic_error( "error:" + std::string(__FUNCTION__) + 
        "converter still not implement for regular (non symmetry) bond.\n"));
  }

  //colect cytnx info
  const std::vector<std::vector<cytnx::cytnx_int64>> qnums = cytnx_bd.qnums();
  const std::vector<cytnx::Symmetry> syms = cytnx_bd.syms();
  const std::vector<cytnx::cytnx_uint64> degs = cytnx_bd.getDegeneracies();

  //construct Index
  std::vector<itensor::QNInt> qnstorage;
  auto sym_num = cytnx_bd.Nsym(); //syms.size()
  for (size_t i = 0; i < qnums.size(); ++i) {
    auto fst_qn = qnums[0];
    itensor::QN qn;
    for (size_t qnum_idx = 0; qnum_idx < fst_qn.size(); ++qnum_idx) {
      //notice that the name of the Qnum only 7 characters.
      std::string qnum_name = std::to_string(qnum_idx + 1); 
      int mod = syms[qnum_idx].n();
      auto qnum = itensor::QNum(qnum_name, qnums[i][qnum_idx], mod);
      qn.addNum(qnum);
    }
    auto deg = degs[i];
    itensor::QNInt qn_deg (qn, deg);//std::pair<QN, long>
    qnstorage.push_back(qn_deg);
  }
  itensor::Arrow dir = cytnx_bd.type() == cytnx::BD_BRA ? itensor::Out : itensor::In;
  auto index = itensor::Index(std::vector<itensor::QNInt>(qnstorage), dir, label);
  return index;
}

cytnx::UniTensor ToCytnxUniTensor (const itensor::ITensor& itensor_T) {
  if(!itensor::hasQNs(itensor_T)) {
    throw(std::logic_error( "error:" + std::string(__FUNCTION__) + 
        "converter still not implement for not QN itensor.\n"));
  }
  std::vector<cytnx::Bond> bonds;
  std::vector<std::string> labels;
  for (const auto& index : inds(itensor_T)) {
    bonds.push_back(ToCytnxBond(index));
    labels.push_back(std::string(index.tags()));
  }
  cytnx::cytnx_int64 row_rank = -1;
  auto dtype = itensor::isReal(itensor_T) ? 
               cytnx::Type.Double : cytnx::Type.ComplexDouble;
  auto cytnx_T = cytnx::UniTensor(bonds, labels, row_rank, dtype, 
                                  cytnx::Device.cpu, false);
  CytnxConverter::ElemWiseITensorToCytnx(itensor_T, &cytnx_T);
  return cytnx_T;
}

itensor::ITensor ToITensorITensor (const cytnx::UniTensor& cytnx_T) {
  int cytnx_T_type = cytnx_T.uten_type();
  switch (cytnx_T_type) {
    case cytnx::UTenType.Block:
      break;
    default:
      throw(std::logic_error( "error:" + std::string(__FUNCTION__) + 
          "converter still not implement for not block unitensor.\n"));
  }
  std::vector<cytnx::Bond> bonds = cytnx_T.bonds();
  const std::vector<std::string> labels = cytnx_T.labels();
  std::vector<itensor::Index> indices;
  int i = 0;
  for (auto bond : bonds) {
    itensor::Index index = ToITensorIndex(bond, labels[i]);
    indices.push_back(index);
    i++;
  }
  auto itensor_T = itensor::ITensor(indices);
  CytnxConverter::ElemWiseCytnxToITensor(cytnx_T, &itensor_T);
  return itensor_T;
}

}
