#include<iostream>
#define Max 4

using namespace std;

int stack_arr[Max];
int top=-1;

void push(int data){
    if(top==Max-1){
        cout<<"Stack Overflow"<<endl;
        return;
    }

    top = top + 1;
    stack_arr[top] = data;
}

void printStack(){
    int i;
    if(top == -1){
        cout<<"Stack underflow"<<endl;
        return;
    }

    for(i=top; i>=0 ; i--){
        cout<<stack_arr[i]<<" ";
    }
}


int main(){
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);

    printStack();
}