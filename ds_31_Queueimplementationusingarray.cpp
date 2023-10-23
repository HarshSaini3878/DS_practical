#include <iostream>

using namespace std;

class Queue {
private:
    static const int MAX_SIZE = 100;
    int arr[MAX_SIZE];
    int front, rear;

public:
    Queue() : front(-1), rear(-1) {}

    void enqueue(int data) {
        if (rear == MAX_SIZE - 1) {
            cout << "Queue overflow\n";
            return;
        }
        if (front == -1) {
            front = 0;
        }
        arr[++rear] = data;
    }

    void dequeue() {
        if (front == -1) {
            cout << "Queue underflow\n";
            return;
        }
        if (front == rear) {
            front = rear = -1;
        } else {
            ++front;
        }
    }

    int peek() {
        if (front == -1) {
            cout << "Queue is empty\n";
            return -1;
        }
        return arr[front];
    }

    bool isEmpty() {
        return front == -1;
    }
};
