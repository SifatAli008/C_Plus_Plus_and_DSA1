//Write a function to get the intersection point of two Linked Lists
// Created by Sifat Ali on 11/30/2023.
//
#include <iostream>
using namespace std;

class LL{
public:
    class node{
    public:
        int data;
        node* next;
        node(int data){
            this->data=data;
            this->next= nullptr;
        }
    };
    node* head;

    LL(){
        this->head= nullptr;
    }

    void Push(int x){
        node* NewNode =new node(x);
        if(head== nullptr){
            head=NewNode;
            return;
        }

        node* temp=head;
        while (temp->next!= nullptr){
            temp= temp->next;
        }
        temp->next=NewNode;
    }

    int IntersectionPoint(LL list2) {
            node* ptr1 = head;
            while (ptr1 != nullptr) {

                node *ptr2 = list2.head;
                while (ptr2 != nullptr) {

                    if (ptr1->data == ptr2->data) {
                       ptr2=ptr2->next;
                        while (ptr2 != nullptr) {
                            Push(ptr2->data);
                            ptr2 = ptr2->next;
                        }
                        return ptr1->data;
                    }

                        ptr2 = ptr2->next;
                }
                ptr1=ptr1->next;
            }

        return 0;
    }

    void PrintList(){
        if(head==nullptr){
            cout<<"Empty list"<<endl;
            return;
        }
        node* currentNode =head;
        while(currentNode!= nullptr){
            cout<<currentNode->data;
            if(currentNode->next!= nullptr){
                cout<<"->";
            }
            currentNode = currentNode->next;
        }
        cout << endl;
    }
};

int main(){
    LL list1,list2;
    list1.Push(3);
    list1.Push(7);
    list1.Push(6);


    list2.Push(1);
    list2.Push(2);
    list2.Push(3);
    list2.Push(9);
    list2.Push(8);



    int intersection = list1.IntersectionPoint(list2);
    if (intersection != 0) {
        cout << "Intersection point found at: " << intersection << endl;
    } else {
        cout << "No intersection point found." << endl;
    }

    list1.PrintList();
    list2.PrintList();
}
