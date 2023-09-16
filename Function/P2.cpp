#include<iostream>
#include<conio.h>

using namespace std;

void displayArray(int num[ ],int size)
{
    for(int i=0; i<size; i++)
    {
         cout<<num[i]<<" ";
    }
}
int main()
{
    int number[5] = {10,20,30,40,50};
    displayArray(number,5);
    ;
    getch();
}

