//
// Created by Sifat Ali on 11/12/2023.
//
#include<iostream>
using namespace std;
const int Size = 3;
int QueueList[Size];
int front=-1,rear =-1;

void enqueue(int data){
 if(rear == Size-1 ) {
       cout << "Queue is full."<<endl;
         }
 else{
    if(front==-1){
        front=0;
    }
    rear ++;
    QueueList[rear ]=data;
     }
}
void dequeue(){
    if(front==-1){
        cout<<"Empty list"<<endl;
    }
     else{
        front++;
        if(front>rear ){
            front==0;
        }
     }
}

void display(){
    if(front==-1){
        cout<<"Empty list"<<endl;
    }
    else{
        for (int i = front; i <=rear  ; ++i) {
            cout<< QueueList[i]<<" ";
        }
    }
}


int main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    display();

}