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
        this->head=nullptr;
    }

    void addFirst(string data){
        node* nodeNew = new node(data);
        if(head == nullptr){
            head=nodeNew;
            nodeNew->next=head;
            return;
        }

        node* currentnode = head;
        while(currentnode->next!=head){
            currentnode=currentnode->next;
        }
        currentnode->next=nodeNew;
        nodeNew->next=head;
        head=nodeNew;
    }

    void addlast(string data){
        node* nodeNew = new node(data);
        if(head == nullptr){
            head=nodeNew;
            nodeNew->next=head;
            return;
        }

        node* currentnode = head;
        while(currentnode->next!=head){
            currentnode=currentnode->next;
        }
        currentnode->next=nodeNew;
        nodeNew->next=head;
    }

    void headDelection(){
        node* currentnode=head;
        while(currentnode->next!=head){
            currentnode=currentnode->next;
        }

        node* todelet = head;
        currentnode->next=head->next;

        delete todelet;
    }

    void Delection(string value) {
        if(head == nullptr){
            cout<<"Empty List"<<endl;
            return;
        }

        node* currentNode = head;
        while (currentNode->next!=head && currentNode->next->data != value){
            currentNode=currentNode->next;

            if(currentNode->next == head){
                cout << "Value not found in the list." << endl;
                return;
            }

            node* todelete = currentNode->next;
            currentNode->next = todelete->next;
            delete todelete;
        }


    }

    void PrintList(){
        if(head == nullptr){
            cout<<"Empty List"<<endl;
            return;
        }

        node* currentnode = head;
        do{
            cout<<currentnode->data;
            if(currentnode->next!=head){
                cout<<"->";
            }
            currentnode=currentnode->next;
        }
        while(currentnode!=head);
    }

};

int main(){
    LL list;
    list.addlast("2");
    list.addlast("3");
    list.addlast("4");
    list.addFirst("1");
    list.Delection("3");
    list.PrintList();
}