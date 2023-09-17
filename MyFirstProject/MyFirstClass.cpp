#include "MyFirstClass.h"
#include <iostream>
using namespace std;

MyFirstClass::MyFirstClass()
{
    cout << "Inside the constructor" << endl;
}

MyFirstClass::~MyFirstClass()
{
    cout << "Inside the distructor" << endl;
}
void MyFirstClass::display()
{
cout<<"Inside the display method"<<endl;
}

