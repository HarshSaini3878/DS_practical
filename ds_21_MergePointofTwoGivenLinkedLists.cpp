#include <iostream>
#include <unordered_set>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

Node* findMergePoint(Node* head1, Node* head2) {
    unordered_set<Node*> nodesSet;

    while (head1 != nullptr) {
        nodesSet.insert(head1);
        head1 = head1->next;
    }

    while (head2 != nullptr) {
        if (nodesSet.find(head2) != nodesSet.end()) {
            return head2;  // Found merge point
        }
        head2 = head2->next;
    }

    return nullptr;  // No merge point found
}

void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* commonNode = new Node(7);
    
    Node* head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);
    head1->next->next->next = commonNode;

    Node* head2 = new Node(4);
    head2->next = new Node(5);
    head2->next->next = commonNode;

    cout << "Linked List 1: ";
    printList(head1);

    cout << "Linked List 2: ";
    printList(head2);

    Node* mergePoint = findMergePoint(head1, head2);

    if (mergePoint != nullptr) {
        cout << "Merge Point: " << mergePoint->data << endl;
    } else {
        cout << "No Merge Point found." << endl;
    }

    return 0;
}

