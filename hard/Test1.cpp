//
// Created by User on 11/30/2023.
// Write a function to get the intersection point of two Linked Lists
//
# include <iostream>
using namespace std ;

class SinglyLinkedList{
    class node {
    public:
        int data ;
        node* next ;
        node(int data){
            this->data = data;
            this->next = NULL ;
        }
    };
    node* head;
public:
    SinglyLinkedList(){
        this->head = NULL ;
    }


    void AddLast(int data){
        node* newNode = new node(data);
        if(head == NULL){
            head = newNode;
            return;
        }
        node* cur = head ;
        while( cur->next != NULL ){
            cur =  cur->next ;
        }
        cur->next = newNode  ;
    }

    int intersection(SinglyLinkedList list2){

        node* cur1=  head;
        while(cur1->next != nullptr){
            node* cur2 = list2.head;
            while((cur2->data != cur1->data) && (cur2->next != nullptr)){
                cur2 = cur2->next;
            }
            if(cur2->data == cur1->data){
                cur2->next = cur1->next;
                return cur1->data ;
            }
            cur1 = cur1->next ;
        }
        return 0 ;

    }

    void display_LL(){
        if(head == NULL){
            cout << " empty Linked list." ;
        }
        node* currentNode = head;
        while(currentNode != NULL ){
            cout << currentNode->data ;
            if(currentNode->next != nullptr ){
                cout << " -> " ;
            }
            currentNode = currentNode->next ;
        }
        cout << endl << endl ;
    }
};

int main () {

    SinglyLinkedList L1;

    L1.AddLast(1);
    L1.AddLast(2);
    L1.AddLast(3);
    L1.AddLast(4);
    L1.AddLast(5);


    SinglyLinkedList L2;
    L2.AddLast(10);
    L2.AddLast(3);

    L1.display_LL();
    L2.display_LL();

    int point = L1.intersection(L2);
    if(point != 0)
        cout << "intersecting point: " << point << endl;
    else
        cout << "no intersecting point\n" ;

    L2.display_LL();
    return 0;
}