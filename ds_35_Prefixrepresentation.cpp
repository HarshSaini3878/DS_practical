#include <iostream>
#include <stack>

using namespace std;

int evaluatePrefix(string expression) {
    stack<int> st;

    for (int i = expression.size() - 1; i >= 0; --i) {
        if (isdigit(expression[i])) {
            st.push(expression[i] - '0');
        } else {
            int operand1 = st.top();
            st.pop();
            int operand2 = st.top();
            st.pop();

            switch (expression[i]) {
                case '+':
                    st.push(operand1 + operand2);
                    break;
                case '-':
                    st.push(operand1 - operand2);
                    break;
                case '*':
                    st.push(operand1 * operand2);
                    break;
                case '/':
                    st.push(operand1 / operand2);
                    break;
            }
        }
    }

    return st.top();
}

