#include<iostream>
#include<conio.h>
#include<iomanip>
using namespace std;

int main()
{
    float num1 ,num2;


    cout<<"Enter 2 Numbers : ";
    cin>>num1>>num2;


    cout << showpoint;
    cout<<fixed;
    cout<<setprecision(2);

    cout << noshowpoint;
    float sum = num1 + num2;
    cout<<setw(20)<<"Sum is : "<<sum<<endl;

    cout << noshowpoint;
    float sub = num1 - num2;
    cout<<"Subtraction is : "<<sub<<endl;

   cout << showpoint;

    float mul = num1 * num2;
    cout<<"Multiplication is : "<<mul<<endl;


    double div = (float) num1 / num2;
    cout<<"Divison is : "<<div<<endl;

    cout<<showpoint;



    getch();
}
