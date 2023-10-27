//Delete middle of linked list
// Created by Sifat Ali on 10/26/2023.
//
#include <iostream>
using namespace std;
 class LL{
     class node {
     public:
         string data;
         node* next;
         node(string data){
             this->data=data;
             this->next= nullptr;
         }
     };
     node* head;
 public:
     LL(){
         this->head= nullptr;
     }
     void AddToHead(string data){
         node* newNode  = new node(data);
         if(head== nullptr){
             head=newNode;
             head->next= nullptr;
             return;
         }
         newNode->next= head;
         head=newNode;
     }

     void AddToTail(string data){
         node* newNode  = new node(data);
         if(head== nullptr){
             head=newNode;
             head->next= nullptr;
             return;
         }

         node* currentNode=head;
         while(currentNode->next!= nullptr) {
             currentNode = currentNode->next;
         }

         currentNode->next=newNode;
         newNode->next= nullptr;
     }

     void DeleteMiddel(){
         if(head== nullptr){
             cout<<"Empty List";
             return;
         }

         int size = 0;
         node* temp = head;
         while (temp != nullptr) {
             size++;
             temp = temp->next;
         }

         int mid =size/2;
         int count=0;
         node* currentNode = head;
         while(count<mid-1){
             currentNode=currentNode->next;
             count++;
         }

         node* todelete = currentNode->next;
         currentNode->next=currentNode->next->next;
         delete todelete;

     }

     void printList(){
         if(head== nullptr){
             cout<<"Empty List";
             return;
         }

         node* currentNode=head;
         while(currentNode!= nullptr) {
             cout<<currentNode->data;
             if(currentNode->next!= nullptr){
                 cout<<"->";
             }
             currentNode = currentNode->next;
         }
         cout<<endl;
     }
 };

int main(){
   LL list;
   list.AddToHead("3");
   list.AddToHead("2");
   list.AddToHead("1");

   list.DeleteMiddel();
   list.printList();
}