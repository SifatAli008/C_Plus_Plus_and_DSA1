//Reverse a doubly linked list in groups of given size in cpp
// Created by Sifat Ali on 12/2/2023.
//
#include <iostream>

struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

Node* reverseInGroups(Node* head, int k) {
    Node* current = head;
    Node* next = nullptr;
    Node* prev = nullptr;
    int count = 0;

    // Reverse k nodes of the linked list
    while (current != nullptr && count < k) {
        next = current->next;
        current->next = prev;
        current->prev = next;
        prev = current;
        current = next;
        count++;
    }

    // If next group exists, recursively call for the next group
    if (next != nullptr) {
        head->next = reverseInGroups(next, k);
        head->next->prev = head;
    }

    // 'prev' now points to the new head of the reversed group
    return prev;
}

void printList(Node* head) {
    while (head != nullptr) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    // Create a sample doubly linked list
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(4);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->prev = head->next->next->next;

    std::cout << "Original List: ";
    printList(head);

    int k = 2; // Group size
    head = reverseInGroups(head, k);

    std::cout << "Reversed List in Groups of " << k << ": ";
    printList(head);

    return 0;
}
