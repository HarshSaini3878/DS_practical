#include <iostream>

using namespace std;

class Stack {
private:
    static const int MAX_SIZE = 100;
    int arr[MAX_SIZE];
    int top;

public:
    Stack() : top(-1) {}

    void push(int data) {
        if (top == MAX_SIZE - 1) {
            cout << "Stack overflow\n";
            return;
        }
        arr[++top] = data;
    }

    void pop() {
        if (top == -1) {
            cout << "Stack underflow\n";
            return;
        }
        --top;
    }

    int peek() {
        if (top == -1) {
            cout << "Stack is empty\n";
            return -1;
        }
        return arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }
};
