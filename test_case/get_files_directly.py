import sys
from pathlib import Path

arg_src_dst = sys.argv[1]

if arg_src_dst == 'src':
    file_name_list = list(Path("./data/test_data_base_cytnx/src").rglob("*.cytnx"))
    list_file = 'file_list_src.txt'
else:
    file_name_list = list(Path("./data/test_data_base_itensor/").rglob("*.itensor"))
    list_file = 'file_list_dst.txt'

fp = open(list_file, "w")
for file_name in file_name_list: 
    fp.write(str(file_name) + '\n')
fp.close()

