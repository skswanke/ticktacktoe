// Sam Swanke

#include "fileService.hpp"
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

FileService::FileService(){}

void FileService::save(string s){
    // Save board
    int i;
    string out = "";
    for(i=0;i<9;i++){
        if(s.at(i)==' '){
            out.push_back('0');
        } else if (s.at(i)=='x'){
            out.push_back('1');
        } else {
            out.push_back('2');
        }
    }
    ofstream outs("save.txt");
    outs << out;
}

string FileService::load(){
    ifstream file;
    file.open("save.txt");
    string s;
    getline(file, s);
    return s;

}