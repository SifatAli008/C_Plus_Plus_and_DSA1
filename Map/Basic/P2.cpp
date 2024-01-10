//
// Created by Sifat Ali on 1/6/2024.
//
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(){
    map<string,int>m;

    m["A"]=10;
    m["B"]=20;
    m["C"]=30;
    m["E"]=40;
    m["F"]=50;
    m["G"]=30;

    map<string,int>::iterator it;
    for(it=m.begin();it!=m.end();it++){
        cout<<it->first<<" "<<it->second<<endl;
    }
}