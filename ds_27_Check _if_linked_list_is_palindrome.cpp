#include <iostream>
#include <stack>

using namespace std;

struct Node {
    int data;
    Node* next;
};

bool isPalindrome(Node* head) {
    if (!head || !head->next) {
        return true;
    }

    stack<int> s;
    Node* slow = head;
    Node* fast = head;

    while (fast && fast->next) {
        s.push(slow->data);
        slow = slow->next;
        fast = fast->next->next;
    }

    
    if (fast) {
        slow = slow->next;
    }

    while (slow) {
        if (slow->data != s.top()) {
            return false;
        }
        slow = slow->next;
        s.pop();
    }

    return true;
}
