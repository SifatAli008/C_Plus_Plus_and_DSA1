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
        this->head = nullptr;
    }

    void addtohead(string data){
        node* NewNode = new node(data);
        if (head==nullptr){
            head=NewNode;
            return;
        }

        NewNode->next=head;
        head=NewNode;
    }

    void addtolast(string data){
        node* NewNode = new node(data);
        if (head==nullptr){
            head=NewNode;
            return;
        }

        node* currentNode = head;
        while(currentNode->next!= nullptr){
            currentNode=currentNode->next;
        }
        currentNode->next=NewNode;
    }

    void deletion(string value){
        node* NewNode = new node(value);
        if(head==nullptr){
            return;
        }

        node* currentNode = head;
        while(currentNode->next->data!=value){
            currentNode=currentNode->next;
        }
        node* toDelet=currentNode->next;
        currentNode->next=currentNode->next->next;

        delete toDelet;
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
    list.addtohead("3");
    list.addtohead("2");
    list.addtohead("1");
    list.addtolast("5");
    list.printList();
    return 0;
}