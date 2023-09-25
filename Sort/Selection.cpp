#include<iostream>
using namespace std;

int main(){
    int arr[]={8,10,7,5,};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout<<"Befor sort : ";

    for(int i=0;i<n;i++){
        cout<<arr[i];
    }

    for(int i = 0; i < n-1; i++)
    {
        int min = i;

        for(int j = i+1; j < n; j++)
        {
            if(arr[j] < arr[min])
                min = j;
        }

        if(min != i)
        {

            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }

    cout << endl << "After sort: ";
    for(int i = 0; i < n; i++){
        cout << arr[i];
    }

    return 0;
}
