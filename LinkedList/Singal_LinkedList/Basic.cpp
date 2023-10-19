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
    node* head;
public:
    LL(){
        this->head= nullptr;
    }

    void AddFirst(string data){
        node* NewNode = new node(data);
        if(head== nullptr){
            head=NewNode;
            return;
        }
        NewNode->next=head;
        head=NewNode;
    }

    void headDeletion(){
        node*  toDeletNode = head;
        head=head->next;

        delete toDeletNode;
    }

    void Deletion(string value){
        if (head == nullptr) {
            return;
        }
        if(head->next== nullptr){
            headDeletion();
        }
        node *currentNode = head;
        while (currentNode->next->data!= value) {
            currentNode = currentNode->next;
        }

        node* toDeletNode = currentNode->next;
        currentNode->next = currentNode->next->next;

        delete toDeletNode ;
    }

    void AddAnyPos(string data,int postion){
        node* NewNode = new node(data);
        if (head == nullptr) {
            head = NewNode;
            return;
        }
        else{
            cout<<"Invalid Position"<<endl;
        };


        int size=0;

        node *currentNode=head;
        while (size<postion-1 && currentNode->next!= nullptr) {
            currentNode = currentNode->next;
            size++;
        }

        if(size<postion-1){
            cout<<"Invalid Position"<<endl;
        }

        NewNode->next=currentNode->next;
        currentNode->next=NewNode;
    }

    void AddMiddel(string data){
        node* NewNode = new node(data);
        if (head == nullptr) {
            head = NewNode;
            return;
        }
        node *currentNode=head;
        int size=0;
        while (currentNode->next!= nullptr) {
            currentNode = currentNode->next;
            size++;
        }
        int mid=size/2;
        int count=0;
        currentNode=head;
        while(count<mid){
            currentNode = currentNode->next;
            count++;
        }
        NewNode->next=currentNode->next;
        currentNode->next=NewNode;
    }

    void AddLast(string data) {
        node *NewNode = new node(data);
        if (head == nullptr) {
            head = NewNode;
            return;
        }
        node *currentNode = head;
        while (currentNode->next != nullptr) {
            currentNode = currentNode->next;
        }
        currentNode->next=NewNode;
    }

    void printList(){
        if(head== nullptr){
            cout<<"Empty LinkedList"<<endl;
            return;
        }
        node* currentNode = head;
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
    list.AddFirst("5");
    list.AddFirst("4");
    list.AddFirst("2");
    list.AddFirst("1");
    list.AddAnyPos("3",2);
    list.printList();

    return 0;
}
