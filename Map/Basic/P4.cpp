//map print
// Created by Sifat Ali on 1/6/2024.
//
#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(){

    map<char,vector<int>>m;

    vector<int>v1;
    v1.push_back('a');
    v1.push_back('b');
    v1.push_back('c');
    v1.push_back('d');

    m['a']=v1;//a,b,c,d

    vector<int>v2;
    v2.push_back('e');
    v2.push_back('f');
    v2.push_back('g');
    v2.push_back('h');

    m['b']=v2;//e,f,g,h

    map<char,vector<int>>::iterator it;

    for(it=m.begin();it!=m.end();it++){
         cout<<it->first<<endl;

         vector<int>currentvector=it->second;
        for (int i = 0; i < currentvector.size(); ++i) {
            cout<<currentvector[i]<<endl;
        }
    }
}