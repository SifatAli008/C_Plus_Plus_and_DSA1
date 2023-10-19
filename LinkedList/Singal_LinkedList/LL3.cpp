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
        if(head==nullptr){
            head=NewNode;
            return;
        }
        NewNode->next=head;
        head=NewNode;
    }

    void AddLast(string data){
        node* NewNode = new node(data);
        if(head==nullptr){
            head=NewNode;
            return;
        }

        node* currentNode =head;
        while (currentNode->next!= nullptr){
            currentNode=currentNode->next;
        }
        currentNode->next=NewNode;
    }

    void headDeletion(){
        node* toDeletNode =head;
        head=head->next;

        delete toDeletNode;
    }

    void Deletion(string value){
        if(head==nullptr){
            return;
        }

        if(head->next== nullptr){
            headDeletion();
        }

        node* currentNode=head;
        while(currentNode->next->data!=value){
            currentNode=currentNode->next;
        }

        node* toDeletNode = currentNode->next;
        currentNode->next=currentNode->next->next;

        delete toDeletNode;
    }

    void printList(){
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
    LL list;
    list.AddFirst("3");
    list.AddFirst("2");
    list.AddFirst("1");
    list.AddLast("4");
    list.AddLast("5");
    list.AddLast("6");
    list.Deletion("5");
    list.headDeletion();
    list.printList();
}
