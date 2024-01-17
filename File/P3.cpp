//
// Created by Sifat Ali on 1/5/2024.
//
#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ofstream wfile;
    wfile.open("File/Output1",ios::out | ios::app);

    if(wfile.is_open()){
        wfile<<"Sifat"<<endl;
        wfile.close();
    } else{
        cout<<"File can't be opend"<<endl;
    }

    ifstream rfile;
    rfile.open("File/Output1");

    if(rfile.is_open()){
        string line;
        while (getline(rfile,line)){
            cout<<line<<endl;
        }
        cout<<"-----End Of Line-----"<<endl;
    }
    else{
        cout<<"Unable to openFile";
    }
}