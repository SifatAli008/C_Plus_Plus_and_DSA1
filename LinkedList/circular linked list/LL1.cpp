#include <iostream>
using namespace std;

class LL{
    class node{
    public:
        string data;
        node* next;

        node(string data){
            this->data= data;
            this->next= nullptr;
        }
    };
    node* head;
public:
    LL(){
        this->head= nullptr;
    }

    void AddLast(string data){
        node* NewNode = new node(data);
        if(head==nullptr){
            head=NewNode;
            head->next=head;
            return;
        }

        node* currentNode =head;
        while (currentNode->next!= head){
            currentNode=currentNode->next;
        }
        currentNode->next=NewNode;
        NewNode->next=head;
    }

    void printList(){
        if(head==nullptr){
            cout<<"Empty list"<<endl;
            return;
        }
        node* currentNode =head;
        do{
            cout<<currentNode->data;
            if(currentNode->next!= head){
                cout<<"->";
            }
            currentNode = currentNode->next;
        }while(currentNode!= head);

        cout << endl;
    }
};


int main(){
    LL list;
    list.AddLast("1");
    list.AddLast("2");
    list.AddLast("3");
    list.printList();
}
