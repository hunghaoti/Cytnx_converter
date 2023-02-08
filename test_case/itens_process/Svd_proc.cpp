#include <itensor/all.h>
#include <gtest/gtest.h>

namespace SvdAns {

std::string src_path = "../data/test_data_base_itensor/common/";
std::string dst_path = "../data/test_data_base_itensor/linalg/Svd/";

itensor::ITensor GetSvd_S(const itensor::ITensor& M);

TEST(Svd, common_sym_test) {
  std::vector<std::string> case_list = {
    // U1
    "sym_UT_U1_C128.itensor",
    "sym_UT_U1_F64.itensor",
    // Z2
    "sym_UT_Z2_C128.itensor",
    "sym_UT_Z2_F64.itensor",
    // Z3
    "sym_UT_Z3_C128.itensor",
    "sym_UT_Z3_F64.itensor",
    // U1xZ2
    "sym_UT_U1xZ2_C128.itensor",
    "sym_UT_U1xZ2_C64.itensor",
    "sym_UT_U1xZ2_F64.itensor",
    "sym_UT_U1xZ2_F32.itensor",
    "sym_UT_U1xZ2_I64.itensor",
    "sym_UT_U1xZ2_U64.itensor",
    "sym_UT_U1xZ2_I32.itensor",
    "sym_UT_U1xZ2_U32.itensor",
    "sym_UT_U1xZ2_I16.itensor",
    "sym_UT_U1xZ2_U16.itensor",
    // others
    "sym_UT_U1_zeros_F64.itensor",
    "sym_UT_U1_one_elem_F64.itensor"
  };
  for (const auto& case_name : case_list) {
    std::string file_name = src_path + case_name;
    itensor::ITensor itensor_T = itensor::readFromFile<itensor::ITensor>(file_name);
    itensor::ITensor S = GetSvd_S(itensor_T);
    itensor::writeToFile(dst_path + case_name, S);
  }
}

std::vector<itensor::Index> GetIndex_In(const itensor::ITensor& itensor_T) {
  std::vector<itensor::Index> in_index;
  auto inds = itensor::inds(itensor_T);
  for (auto& index : inds) {
    itensor::Arrow dir_type = itensor::dir(index);
    if (dir_type == itensor::In) {
      in_index.push_back(index);
    }
  }
  return in_index;
}

itensor::ITensor GetSvd_S(const itensor::ITensor& M) {
  std::vector<itensor::Index> index_in = GetIndex_In(M);
  auto [U, S, V] = itensor::svd(M, index_in);
  return S;
}

} //namespace
