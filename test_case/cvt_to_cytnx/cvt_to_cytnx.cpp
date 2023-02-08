#include <iostream>
#include <fstream>
#include <vector>
#include <cytnx_converter.h>

void replaceAll(std::string& str, const std::string& from, const std::string& to) {
//ref:https://stackoverflow.com/questions/3418231/replace-part-of-a-string-with-another-string
  if(from.empty())
      return;
  size_t start_pos = 0;
  while((start_pos = str.find(from, start_pos)) != std::string::npos) {
      str.replace(start_pos, from.length(), to);
      start_pos += to.length(); // In case 'to' contains 'from', like replacing 'x' with 'yx'
  }
}


std::string CorrectFile(const std::string src_name) {
  std::string dst_name = src_name;
  replaceAll(dst_name, "cytnx", "itensor");
  replaceAll(dst_name, "/src", "");
  return "../" + dst_name;
}

std::string GetDstFileName(const std::string src_name) {
  std::string dst_name = src_name;
  replaceAll(dst_name, "itensor", "cytnx");
  replaceAll(dst_name, "test_data_base_cytnx", "test_data_base_cytnx/dst");
  replaceAll(dst_name, "\.cytnx", "");
  return dst_name;
}

std::vector<std::string> GetFileList() {
  std::vector<std::string> file_name_list;
  std::ifstream f_in("../file_list_dst.txt");
  std::string file_name;
  while (f_in >> file_name) {
    file_name = CorrectFile(file_name);
    file_name_list.push_back(file_name);
  }
  return file_name_list;
}


int main(){
  std::vector<std::string> file_name_list = GetFileList();
  for(const auto& file_name : file_name_list) {
    itensor::ITensor itensor_T = itensor::readFromFile<itensor::ITensor>(file_name);
    cytnx::UniTensor cytnx_T = CytnxConverter::ConvertToCytnx(itensor_T);
    std::string dst_file_name = GetDstFileName(file_name);
    cytnx_T.Save(dst_file_name);
  }
  return 0;
}
