#include<iostream>
#include<conio.h>

using namespace std;

int main( )
{
    int n,sum=0;

    cout<<"Enter Number of Student : ";
    cin >>n;

    int students [n];

    for(int i =0 ; i<n; i++){
        cin >> students[i];
        sum=sum+ students[i];
    }

    cout << "Total marks : "<<sum<<endl;

    float avg = (float) sum/n;

      cout << "Average: "<<sum/n;

    getch();
}
