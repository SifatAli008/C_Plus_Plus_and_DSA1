//Algorithm Library
// Created by Sifat Ali on 1/7/2024.
//
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main(){
    int arr[]={1,2,3,4,5};
    vector<int>v1(arr,arr+5);
    vector<string>v;
    for(int i=0;i<5;i++){
       string curstr;
        cin>>curstr;//wordinput

        v.push_back(curstr);
    }

    cout<<"------PRINT VICTOR------"<<endl;
    for(int i=0;i<v.size();i++){
           cout<<v[i]<<endl;
    }

    ///min _element
    vector<int>::iterator it= min_element(v1.begin(),v1.end());
      cout<<"Minimum element : "<< *it<<endl;

    return 0;
}
