#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

void insertAtPosition(Node*& head, int value, int position) {
    Node* newNode = new Node(value);

    if (position == 0 || head == nullptr) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* temp = head;
    for (int i = 0; i < position - 1 && temp != nullptr; ++i) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Invalid position. Insertion not possible." << endl;
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteAtPosition(Node*& head, int position) {
    if (head == nullptr) {
        cout << "List is empty. Deletion not possible." << endl;
        return;
    }

    if (position == 0) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* temp = head;
    for (int i = 0; i < position - 1 && temp != nullptr; ++i) {
        temp = temp->next;
    }

    if (temp == nullptr || temp->next == nullptr) {
        cout << "Invalid position. Deletion not possible." << endl;
        return;
    }

    Node* toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
}

void displayList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;

    insertAtPosition(head, 1, 0);
    insertAtPosition(head, 3, 1);
    insertAtPosition(head, 2, 1);

    cout << "Linked List: ";
    displayList(head);

    deleteAtPosition(head, 1);

    cout << "Linked List after deletion at position 1: ";
    displayList(head);

    return 0;
}
