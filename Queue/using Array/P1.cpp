//
// Created by Sifat Ali on 11/12/2023.
//
#include<iostream>
using namespace std;
const int Size = 3;
int QueueList[Size];
int front=-1,rare=-1;

void enqueue(int data){
        if(front==-1){
            front=0;
        }
          rare++;
        QueueList[rare]=data;
}


void display(){
    if(front==-1){
           cout<<"Empty list"<<endl;
    }
    else{
        for (int i = front; i <=rare ; ++i) {
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