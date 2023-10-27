//Merge a linked list into another linked list at alternate positionserge 2 Sorted Linked List
// Created by Sifat Ali on 10/26/2023.
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
            this->next= nullptr;
        }
    };
public:
    node* head;
    LL(){
        this->head= nullptr;
    }
    void AddToList(string data){
        node *newNode = new node(data);
        if (head == nullptr) {
            head = newNode;
            newNode->next = nullptr;
            return;
        }

        node *currentNode = head;
        while (currentNode->next != nullptr) {
            currentNode = currentNode->next;
        }
        currentNode->next = newNode;
        newNode->next = nullptr;
    }


            static LL MergeLists(LL List1, LL List2) {
                LL mergedList;
                node *p1 = List1.head;
                node *p2 = List2.head;
                node *p3 = mergedList.head;

                int count = 0;
                while (p1 != nullptr && p2 != nullptr) {
                    if (p3 == nullptr) {
                        mergedList.head = p1;
                        p3 = p1;
                        p1 = p1->next;
                    } else {
                        if (count % 2 == 0) {
                            p3->next = p2;
                            p3 = p3->next;
                            p2 = p2->next;
                        }
                        if (count % 2 != 0) {
                            p3->next = p1;
                            p3 = p3->next;
                            p1 = p1->next;
                        }
                    }
                    count++;

                }

                if (p3 == nullptr) {
                    if (p1 != nullptr) {
                        mergedList.head = p1;
                    } else {
                        mergedList.head = p2;
                    }
                } else {
                    while (p1 != nullptr) {
                        p3->next = p1;
                        p1 = p1->next;
                        p3 = p3->next;
                    }
                    while (p2 != nullptr) {
                        p3->next = p2;
                        p2 = p2->next;
                        p3 = p3->next;
                    }
                }


                return mergedList;

            }



    void printList() const{
        if(head==nullptr){
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
    LL List1;
    List1.AddToList("1");
    List1.AddToList("3");
    List1.AddToList("5");

    LL List2;
    List2.AddToList("2");
    List2.AddToList("4");
    List2.AddToList("6");

    LL mergedList = LL::MergeLists(List1, List2);
    mergedList.printList();

    return 0;
}