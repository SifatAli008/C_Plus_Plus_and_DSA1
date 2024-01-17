//
// Created by Sifat Ali on 1/5/2024.
//
#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ifstream rfile;
    rfile.open("File/Output");
    if (rfile.is_open()){
        string line;
        while(getline(rfile, line)){
            cout << line << endl;
        }
        cout << "______End of File----" << endl; // Added endline for separation
    } else {
        cout << "Unable to Open File" << endl;
    }
    return 0;
}
