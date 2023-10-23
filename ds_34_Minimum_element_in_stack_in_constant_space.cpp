#include <iostream>
#include <stack>

using namespace std;

class MinStack {
private:
    stack<int> st;
    int minElement;

public:
    MinStack() : minElement(INT_MAX) {}

    void push(int data) {
        if (data <= minElement) {
            st.push(minElement);
            minElement = data;
        }
        st.push(data);
    }

    void pop() {
        if (st.empty()) {
            cout << "Stack underflow\n";
            return;
        }
        if (st.top() == minElement) {
            st.pop();
            minElement = st.top();
            st.pop();
        } else {
            st.pop();
        }
    }

    int top() {
        if (st.empty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        return st.top();
    }

    int getMin() {
        if (st.empty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        return minElement;
    }
};

