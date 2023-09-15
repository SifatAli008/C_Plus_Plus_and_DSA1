#include<iostream>
#include<conio.h>

using namespace std;

int main()
{
    int A[2][3];

    A[0][0] = 10;
    A[0][1] = 20;
    A[0][2] = 30;

    A[1][0] = 40;
    A[1][1] = 50;
    A[1][2] = 60;


    for(int row = 0 ; row<2 ; row++)
    {
        for(int col = 0; col<3 ;col++)
        {
            cout << A[row][col] << " ";
        }
        cout<<endl;
    }



    getch();
}


