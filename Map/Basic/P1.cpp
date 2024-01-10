//declaration
// Created by Sifat Ali on 1/5/2024.
//
#include <iostream>
#include <map>
#include <string>
using namespace std;



int main(){
  map<string,int>m;
  map<string,int>m1(m);

  m["Labib"]=100;
  m["Habib"]=50;
  m["Imam"]=0;

  m["Habib"]=89;

  cout<<m["Habib"]<<endl;

  m.erase("Imam");

  cout<<m.size()<<endl;


map<string,int>::iterator it;
  it=m.find("Habib");

  if(it==m.end()){
         cout<<"Not excsist";
  }
  else{
      cout<<it->first;
  }
}