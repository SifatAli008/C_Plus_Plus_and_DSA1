//  min , max ,sort,revers,search,occurence
// Created by Sifat Ali on 1/7/2024.
//
#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

bool sortprocess(int a,int b){
  //for ascending
     //if(a<b)return true;
     //else return false;

  //for descinding
    if(a>b) return true;
    else return false;

}

int main(){
    int arr[]={5,1,18,3,4,3,20,7};
    vector<int>v1(arr,arr+7);
    vector<int>v2(v1);


    //min _element
    vector<int>::iterator it= min_element(v1.begin(),v1.end());
    cout<<"Minimum element : "<< *it<<endl;

    //max-element
    vector<int>::iterator it1=max_element(v1.begin(),v1.end());
    cout<<"Minimum element : "<< *it1<<endl;

    //sort
    sort(v1.begin(),v1.end());

    cout<<"Ascending sort : ";
    for (int i = 0; i < v1.size(); ++i) {
        cout<<v1[i]<<" ";
    }
   cout<<endl;

    //sort on personal need
    //sort(v1.begin(),v1.end(),howtosort);
    cout<<"Descending sort : ";
    sort(v1.begin(),v1.end(),sortprocess);

    for (int i = 0; i < v1.size(); ++i) {
        cout<<v1[i]<<" ";
    }
    cout<<endl;

    //revers
    reverse(v2.begin(),v2.end());
    cout<<"Revers sort : ";

    for (int i = 0; i < v2.size(); ++i) {
        cout<<v2[i]<<" ";
    }

    cout<<endl;

    //search
    vector<int>::iterator i=find(v2.begin(),v2.end(),3);

    if(i==v2.end()){
     cout<<"Not Exists"<<endl;
    }
    else{
        cout<<"Found"<<endl;
    }


    //ocurence
    cout<<"Number of occerence  : ";
    int result= count(v2.begin(), v2.end(),3);
    cout<<result<<endl;

    return 0;
}
