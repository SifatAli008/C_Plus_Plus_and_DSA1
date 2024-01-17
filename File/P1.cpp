//File write,read
// Created by Sifat Ali on 1/5/2024.
//
#include <iostream>
#include <fstream>
using namespace std;
int main(){
    //File Write
    ofstream wfile;
  wfile.open("File/Output",ios::out|ios::app);
  if(wfile.is_open()){
      wfile<<"Line 1"<<endl;
      wfile.close();
      cout << "File successfully written." << endl;
  } else{
      cout<<"File can't be Opened";
  }


    return 0;
}