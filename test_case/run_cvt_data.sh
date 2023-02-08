# this shell run the whole process to generate the test data results.

#1. convert the test data from cytnx to itensor
source activate
conda deactivate
python3 get_files_directly.py src
cd cvt_to_itensor
conda activate cytnx
make -B
./cvt_to_itensor.e
cd ../

#2. use itensor to get test answer in itensor format.
conda deactivate
cd itens_process
make -B
./gen_test_data_main.e
cd ../

#3. convert the answer to cytnx forma.
python3 get_files_directly.py dst
cd cvt_to_cytnx
conda activate cytnx
make -B
./cvt_to_cytnx.e
conda deactivate
