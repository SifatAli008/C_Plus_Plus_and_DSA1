#include<iostream>

using namespace std;

int main(){
    int n=4;
    int arr[]={5,9,4,1};

    cout<<"Befor sort : ";
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }

    for(int i =1;i<n;i++){
        int current=arr[i];
        int j=i-1;
        while(j>=0&&current>arr[j]){
            arr[j+1]=arr[j];
            j--;
        }
        j++;
        arr[j]=current;
    }

    cout<<endl<<"After sort : ";
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }

    return 0;
}