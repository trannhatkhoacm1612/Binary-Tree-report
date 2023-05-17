#include <iostream>
#include<bits/stdc++.h>
#include "BR.h"


int main(){
    string evaluate = "";
    for(int i = 1; i <= 10; i++){
        string path_file = "D:\\DTA\\Tree\\data\\" + to_string(i) + ".txt"; // input file
        
        // Đọc file
        ifstream input_file(path_file);
        string line;
        int number;
        RedBlackTree bst; // Tạo cây
        // Đọc từng dòng và ghi vào file
        while(getline(input_file, line) && line != ""){
            number = stoi(line);

            bst.insert(number);
        }
        int h = bst.getTreeHeight(); // Chiều cao của cây
        // string AVL_file = "D:\\DTA\\Tree\\result\\AVL.txt";
        // ofstream result_file(AVL_file,std::ios::out | std::ios::trunc);
        evaluate += to_string(h) + " ";
    }
    string AVL_file = "D:\\DTA\\Tree\\result\\BR.txt";
    ofstream result_file(AVL_file,std::ios::out);
    result_file << evaluate;
    result_file.close();
}