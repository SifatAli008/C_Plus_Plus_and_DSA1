//
// Created by Sifat Ali on 1/6/2024.
//
#include <iostream>
#include <map>
#include <string>
using namespace std;
int main(){

    string word="aaabbbbbccdddd";
     // a=3 b=5 c=2 c=4

    map<char,int>m;

    for(int i=0;i<word.size();i++){
           char current_char=word[i];

           if(m.find(current_char)==m.end()){
               //doesn't exsits
               m[current_char]=1;
           } else{
               //key already exsits
               m[current_char]+=1;
           }
    }


    map<char,int>::iterator it;
    for(it= m.begin();it!=m.end();it++){
        cout<<it->first<<"->"<<it->second<<endl;
    }


}