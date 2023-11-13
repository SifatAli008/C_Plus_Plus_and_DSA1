#include<iostream>
using namespace std;

#define Max 4
int stack_arr[Max];
int top = -1;

int isFull(){
    if(top == Max-1){
        return 1;
    } else{
        return 0;
    }
}

int isEmpty(){
    if(top ==-1){
        return 1;
    } else{
        return 0;
    }
}

void push(int data)
{
    if (isFull())
    {
        cout << "Stack Overflow"<<endl;
        return;
    }

    top = top + 1;
    stack_arr[top] = data;
}

int pop() {
    int value;
    if (isEmpty()) {
        cout<<"Stack underflow";
        exit(1);
    }
    value = stack_arr[top];
    top = top - 1;
    return value;
}

int peek(){
    if(isEmpty()){
        cout<<"Stack UnderFlow\n";
        exit(1);
    }
    return stack_arr[top];
}

void printStack()
{
    int i;
    if(top == -1)
    {
        cout<<"Stack underflow"<<endl;
        return;
    }
    for(i=top; i>=0; i--)
    {
        cout<<stack_arr[i]<<" ";
    }
}

int main(){
    int choice,data;

    do {
        cout << "\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Print the top element\n";
        cout << "4. Print all the elements of the stack\n";
        cout << "5. Quit\n";
        cout << "Please enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the element to be pushed: ";
                cin >> data;
                push(data);
                break;
            case 2:
                data = pop();
                cout << "Deleted element is " << data << endl;
                break;

            case 3:
                cout << "The topmost element of the stack is " << peek() << endl;
                break;
            case 4:
                printStack();
                break;
            case 5:
                exit(0);
            default:
                cout << "Wrong choice\n";

        }

    }while(choice!=5);


    return 0;
}
