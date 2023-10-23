#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (head == nullptr || m == n) {
            return head;
        }

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* pre = dummy;
        for (int i = 0; i < m - 1; ++i) {
            pre = pre->next;
        }

        ListNode* start = pre->next;
        ListNode* then = start->next;

        for (int i = 0; i < n - m; ++i) {
            start->next = then->next;
            then->next = pre->next;
            pre->next = then;
            then = start->next;
        }

        return dummy->next;
    }
};

void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Example usage
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original Linked List: ";
    printList(head);

    Solution solution;
    ListNode* reversedList = solution.reverseBetween(head, 2, 4);

    cout << "Reversed Linked List between positions 2 and 4: ";
    printList(reversedList);

    return 0;
}
