//Function to check if a singly linked list is palindrome
// Created by Sifat Ali on 10/28/2023.
//
#include <iostream>
using namespace std;

class LL{
    class node{
    public:
        string data;
        node* next;
        node(string data){
            this->data=data;
            this->next=nullptr;
        }
    };
    node* head;

public:
    LL(){
        this->head= nullptr;
    }

    void AddToList(string data){
        node* newNode =new node(data);
        if(head== nullptr){
            head=newNode;
            return;
        }
        node* currentNode=head;
        while(currentNode->next!= nullptr){
            currentNode=currentNode->next;
        }
        currentNode->next=newNode;
    }

    bool palindrom(){
        if(head== nullptr){
            cout<<"Empty List";
            return false;
        }

        int count=0;
        node* currentNode=head;
        while(currentNode!= nullptr){
            count++;
            currentNode=currentNode->next;
        }

        int mid=count/2;
        currentNode=head;
        for (int i = 0; i < mid; i++) {
            currentNode = currentNode->next;
        }

        node* prev = nullptr;
        node* next = nullptr;
        while (currentNode != nullptr) {
            next = currentNode->next;
            currentNode->next = prev;
            prev = currentNode;
            currentNode = next;
        }

        node* firstHalf = head;
        node* secondHalf = prev;

        while (secondHalf != nullptr) {
            if (firstHalf->data != secondHalf->data) {
                return false;
            }
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }


        return true;
    }


    void PrintList(){
        if(head== nullptr){
            cout<<"Empty List";
            return;
        }
        node* currentNode=head;
        while(currentNode!= nullptr){
            cout<<currentNode->data;
            if(currentNode->next!= nullptr){
                cout<<"->";
            }
            currentNode=currentNode->next;
        }
        cout<<endl;
    }
};

int main(){
    LL list;
    list.AddToList("1");
    list.AddToList("2");
    list.AddToList("3");
    list.AddToList("2");
    list.AddToList("1");
    list.PrintList();
    cout<<list.palindrom();

}