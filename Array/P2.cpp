#include<iostream>
#include<conio.h>

using namespace std;

int main()
{
    int n;

    cout<< "Enter the number of Input: ";
    cin>>n;

    int marks[n];

    for(int i=0;i<n;i++){
        cin>>marks[i];
    }

    for(int i=0;i<n;i++){
        cout<<marks[i]<<" ";
    }

    getch();
}
