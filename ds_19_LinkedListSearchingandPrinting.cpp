#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

bool searchInList(Node* head, int key) {
    while (head != nullptr) {
        if (head->data == key) {
            return true;  // Key found
        }
        head = head->next;
    }
    return false;  // Key not found
}

void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;

    // Insert elements into the linked list
    for (int i = 1; i <= 5; ++i) {
        Node* newNode = new Node(i);
        newNode->next = head;
        head = newNode;
    }

    cout << "Linked List: ";
    printList(head);

    int keyToSearch = 3;
    if (searchInList(head, keyToSearch)) {
        cout << keyToSearch << " is present in the linked list." << endl;
    } else {
        cout << keyToSearch << " is not present in the linked list." << endl;
    }

    return 0;
}
