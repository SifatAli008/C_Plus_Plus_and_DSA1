#include<iostream>
using namespace std;

int main(){
    int arr[]={7,9,2,6,};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout<<"Befor sort : ";

    for(int i=0;i<n;i++){
        cout<<arr[i];
    }

    for(int i = 0; i < n-1; i++)
    {
        int MAX = i;

        for(int j = i+1; j < n; j++)
        {
            if(arr[j] > arr[MAX])
                MAX = j;
        }

        if(MAX != i)
        {

            int temp = arr[i];
            arr[i] = arr[MAX];
            arr[MAX] = temp;
        }
    }

    cout << endl << "After sort: ";
    for(int i = 0; i < n; i++){
        cout << arr[i];
    }

    return 0;
}
