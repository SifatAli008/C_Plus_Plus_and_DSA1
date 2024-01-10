//Adjacency list
// Created by Sifat Ali on 1/8/2024.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(){
    map<int,vector<int>>m;

//0->2
    vector<int>v1;
    v1.push_back(2);
    m[0]=v1;

//1->2,3
    vector<int>v2;
    v2.push_back(2);
    v2.push_back(3);
    m[1]=v2;

//2->0,1,3
    vector<int>v3;
    v3.push_back(0);
    v3.push_back(1);
    v3.push_back(3);
    m[2]=v3;

//3->1,2
    vector<int>v4;
    v4.push_back(1);
    v4.push_back(2);
    m[3]=v4;

    map<int,vector<int>>::iterator it;

    for( it=m.begin();it!=m.end();it++){
        cout<<it->first<<"->";


        vector<int>currentvector=it->second;

        for(int i=0;i<currentvector.size();i++){
            cout<<currentvector[i]<<" ";
        }
     cout<<endl;
    }
}