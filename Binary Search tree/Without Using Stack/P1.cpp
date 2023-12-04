//In order using stack
// Created by Sifat Ali on 12/4/2023.
//

#include <iostream>
#include <stack>
using namespace std;

class Tree {
public:
    class Node {
    public:
        string data;
        Node *left;
        Node *right;

        Node(string data) {
            this->data = data;
            this->left = nullptr;
            this->right = nullptr;
        }
    };

    Node *root;
public:
    Tree() {
        this->root = nullptr;
    }

    void insert(string data) {
        root = insertRec(root, data);
    }

    Node *insertRec(Node *temp, string data) {
        if (temp == nullptr) {
            return new Node(data);
        }

        if (data < temp->data) {
            temp->left = insertRec(temp->left, data);
        } else if (data > temp->data) {
            temp->right = insertRec(temp->right, data);
        }

        return temp;
    }

    void inOrder() {
        if (root == nullptr) {
            return;
        }
        stack<Node*> nodeStack;
        Node *temp = root;

        while (temp != nullptr || !nodeStack.empty()) {
            while (temp != nullptr) {
                nodeStack.push(temp);
                temp = temp->left;
            }

            temp = nodeStack.top();
            nodeStack.pop();
            cout << temp->data << " ";
            temp = temp->right;
        }
    }
};

int main(){
    Tree tree;
    tree.insert("5");
    tree.insert("4");
    tree.insert("3");
    tree.insert("1");
    tree.insert("6");
    tree.insert("7");
    tree.insert("8");

    cout << "In-order : ";
    tree.inOrder();

}
