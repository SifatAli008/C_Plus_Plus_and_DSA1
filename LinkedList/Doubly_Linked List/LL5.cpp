//
// Created by Sifat Ali on 10/17/2023.
//
#include <iostream>
using namespace std;

int main(){

    int n,count,count1;
    cin>>n;

    for(int i=0;i<n;i++){
        printf("hello\n");
    }

    for(int i=0;i<n;i++){
        count1++;
        for(int j=n;j>0;j=j/2){
            count++;
            printf("world\n");
        }
    }
    cout<<count<<endl;
    cout<<count1;
}