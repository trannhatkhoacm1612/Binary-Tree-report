import numpy as np
import os


for i in range(10):
    path_root = "D:\DTA\Tree\data"
    path_file = str(i + 1) + ".txt"
    path_name = os.path.join(path_root,path_file)
    with open(path_name,"w") as file:
       data = np.random.randint(1,10000000,10**6)
       for number in data:
           num = str(number) + "\n"
           file.write(num)
