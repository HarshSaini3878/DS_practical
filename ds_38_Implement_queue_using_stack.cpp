#include <iostream>
#include <stack>

using namespace std;

class QueueUsingStacks {
private:
    stack<int> stack1;  // Used for enqueue operation
    stack<int> stack2;  // Used for dequeue operation

public:
    // Function to enqueue an element into the queue
    void enqueue(int value) {
        stack1.push(value);
    }

    // Function to dequeue an element from the queue
    int dequeue() {
        if (stack1.empty() && stack2.empty()) {
            cout << "Queue is empty. Dequeue operation not possible.\n";
            return -1;  // Assuming -1 represents an error or an invalid value
        }

        if (stack2.empty()) {
            // Transfer elements from stack1 to stack2 for dequeue operation
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }

        int frontElement = stack2.top();
        stack2.pop();
        return frontElement;
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return stack1.empty() && stack2.empty();
    }
};

int main() {
    QueueUsingStacks myQueue;

    myQueue.enqueue(1);
    myQueue.enqueue(2);
    myQueue.enqueue(3);

    cout << "Dequeue: " << myQueue.dequeue() << endl;
    cout << "Dequeue: " << myQueue.dequeue() << endl;

    myQueue.enqueue(4);

    cout << "Dequeue: " << myQueue.dequeue() << endl;
    cout << "Dequeue: " << myQueue.dequeue() << endl;

    if (myQueue.isEmpty()) {
        cout << "Queue is empty.\n";
    } else {
        cout << "Queue is not empty.\n";
    }

    return 0;
}
