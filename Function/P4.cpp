#include<iostream>
#include<conio.h>

using namespace std;

void display(int &num) // pass by reference
{
    num = 20;
}

void display(int *num) // pass by value
{
    *num = 20;
}

int main()
{
    int x = 10;
    cout << "Before calling the function x = " << x << endl;

    display(x);
    cout << "After pass by reference the function x = " << x << endl;

    x = 10;
    cout << "Before calling the function x = " << x << endl;

    display(&x);
    cout << "After calling the function x = " << x << endl;

    getch();
}
