#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

bool hasCycle(Node* head) {
    if (!head || !head->next) {
        return false;
    }

    Node* slow = head;
    Node* fast = head->next;

    while (fast && fast->next) {
        if (slow == fast) {
            return true;
        }
        slow = slow->next;
        fast = fast->next->next;
    }

    return false;
}

void removeCycle(Node* head) {
    if (!head || !head->next) {
        return;
    }

    Node* slow = head;
    Node* fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            break;
        }
    }

    if (slow != fast) {
        return; // No cycle
    }

    slow = head;

    while (slow->next != fast->next) {
        slow = slow->next;
        fast = fast->next;
    }

    fast->next = nullptr;
}
