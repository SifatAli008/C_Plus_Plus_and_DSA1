#include<iostream>
using namespace std;

#define Max 4
int stack_arr[Max];
int top = -1;

int isEmpty(){
    if(top ==-1){
        return 1;
    } else{
        return 0;
    }
}

void push(int data)
{
    if (top == Max-1)
    {
        cout << "Stack Overflow"<<endl;
        return;
    }

    top = top + 1;
    stack_arr[top] = data;
}

int pop() {
    int value;
    if ( isEmpty()) {
        cout<<"Stack underflow";
        exit(1);
    }
    value = stack_arr[top];
    top = top - 1;
    return value;
}

int peek(){
    if( isEmpty()){
        cout<<"Stack UnderFlow\n";
        exit(1);
    }
    return stack_arr[top];
}

void printStack()
{
    int i;
    if( isEmpty())
    {
        cout<<"Stack underflow"<<endl;
        return;
    }
    for(i=top; i>=0; i--)
    {
        cout<<stack_arr[i]<<endl;
    }
}

int main(){

   int A[]={10,20,30,40,50};
    int size =sizeof(A)/sizeof(A[0]);
    for(int i=0;i<=size;i++){
        push(A[i]);
    }
    printStack();


    return 0;
}
