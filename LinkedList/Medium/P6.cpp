//Delete all occurrences of a given key in a linked list
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
        this->head=nullptr;
    }

    void AddToList(string data){
        node* newNode = new node(data);
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

    void RemoveOccurrences(string value){
        if(head== nullptr){
            cout<<"Empty List";
            return;
        }

        if(head->data==value){
            node* toDelete=head;
            head=head->next;
            delete toDelete;
        }


        node* currentNode=head;
        while(currentNode->next!= nullptr){
           if(currentNode->next->data==value){
               node* toDelete=currentNode->next;
               currentNode->next=currentNode->next->next;
               delete toDelete;
           }else {
               currentNode = currentNode->next;
           }
        }
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
    }
};

int main(){
    LL list;
    list.AddToList("1");
    list.AddToList("2");
    list.AddToList("3");
    list.AddToList("4");
    list.AddToList("3");
    list.AddToList("3");
    list.AddToList("3");
    list.AddToList("4");
    list.RemoveOccurrences("3");
    list.PrintList();
}