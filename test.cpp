#include <cytnx.hpp>
#include <itensor/all.h>
#include "cytnx_converter.h"
 
int main() {
  enum class test_case {
    bond,
    tensor
  };
  std::vector<test_case> test_case_list = {
    test_case::bond,
    test_case::tensor
  };
  for (auto test_case : test_case_list) {
    switch (test_case) {
      case test_case::bond: {
          std::vector<std::vector<cytnx::cytnx_int64>> qnums1 = {
            {0}, {1}, {0}, {1}, {2}
          };
          std::vector<cytnx::cytnx_uint64> degs = {1, 2, 3, 4, 5};
          auto syms = std::vector<cytnx::Symmetry>(
            qnums1[0].size(), cytnx::Symmetry(cytnx::SymType.U)
          );
          auto cytnx_bd = cytnx::Bond(cytnx::BD_KET, qnums1, degs, syms);
	  std::cout << cytnx_bd << std::endl;
	  itensor::Index itens_index = CytnxConverter::ConvertToITensor(cytnx_bd);
	  itensor::PrintData(itens_index);
	  cytnx::Bond cytnx_bd2 = CytnxConverter::ConvertToCytnx(itens_index);
	  std::cout << cytnx_bd2 << std::endl;
        break;
      }

      case test_case::tensor: {
        //construct bonds
        std::vector<std::vector<cytnx::cytnx_int64>> qnums1 = {
          {0, 1}, {1, 0}, {0, 0}, {2, 1}
        };
        std::vector<cytnx::cytnx_uint64> degs = {1, 2, 3, 4};
        int n;//Zn
        auto syms = std::vector<cytnx::Symmetry>(  //U1xZ2
            {cytnx::Symmetry(cytnx::SymType.U), cytnx::Symmetry(cytnx::SymType.Z, n=2)}
        );
        auto bond_ket = cytnx::Bond(cytnx::BD_KET, qnums1, degs, syms);
        std::vector<std::vector<cytnx::cytnx_int64>> qnums2 = {
          {2, 0}, {1, 1}, {1, 1}
        };
        degs = {2, 1, 3};
        auto bond_bra = cytnx::Bond(cytnx::BD_BRA, qnums2, degs, syms);
        std::vector<cytnx::Bond> bonds = {bond_ket, bond_ket, bond_bra, bond_bra};
	cytnx::cytnx_int64 row_rank = -1;
        std::vector<std::string> labels = {};
        auto cytnx_T = cytnx::UniTensor(bonds, labels, row_rank, cytnx::Type.ComplexDouble, 
                                        cytnx::Device.cpu, false);
	cytnx::random::Make_uniform(cytnx_T, -100, 100, 0);
	cytnx_T.print_diagram();
	itensor::ITensor itensor_T = CytnxConverter::ConvertToITensor(cytnx_T);
	//itensor::PrintData(itensor_T);
	cytnx::UniTensor cytnx_T2 = CytnxConverter::ConvertToCytnx(itensor_T);
	std::cout << cytnx_T.Norm() << std::endl;
	std::cout << cytnx_T2.Norm() << std::endl;
	std::cout << (cytnx_T - cytnx_T2).Norm() << std::endl;
        break;
      }
      default: {
        assert(false);
      }
    }
  }
  return 0;
}
