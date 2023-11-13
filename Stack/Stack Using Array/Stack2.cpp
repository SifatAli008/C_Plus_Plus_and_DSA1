#include <iostream>
#define Max 4

using namespace std;

int stack_arr[Max];
int top = -1;

void push(int data){
    if (top == Max - 1)
    {
        cout << "Stack Overflow"<<endl;
        return;
    }
    top = top + 1;
    stack_arr[top] = data;
}

int pop(){
    if(top==-1)
    {
        cout<<"Stack underflow";
        exit(1);
    }
    int value= stack_arr[top];
    top=top-1;
    return value;
}

void printStack()
{
    if(top == -1)
    {
        cout<<"Stack underflow"<<endl;
        return;
    }
    for(int i=top; i>=0; i--)
    {
        cout<<stack_arr[i];
    }

}


int main()
{
    int data;
    push(1);
    push(3);
    push(5);
    push(7);
    pop();
    printStack();

    return 0;
}

