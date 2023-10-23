#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Define a structure for a tree node
struct TreeNode {
    string data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(string val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Function to check if a string is an operator
bool isOperator(string s) {
    return (s == "+" || s == "-" || s == "*" || s == "/");
}

// Function to build a binary expression tree from a postfix expression
TreeNode* buildExpressionTree(string postfix) {
    stack<TreeNode*> st;

    for (char c : postfix) {
        string symbol(1, c);

        if (!isOperator(symbol)) {
            TreeNode* operandNode = new TreeNode(symbol);
            st.push(operandNode);
        } else {
            TreeNode* operatorNode = new TreeNode(symbol);
            operatorNode->right = st.top();
            st.pop();
            operatorNode->left = st.top();
            st.pop();

            st.push(operatorNode);
        }
    }

    return st.top();
}

// Function to evaluate a binary expression tree
int evaluate(TreeNode* root) {
    if (root == nullptr) return 0;

    if (!isOperator(root->data)) {
        return stoi(root->data);
    } else {
        int leftOperand = evaluate(root->left);
        int rightOperand = evaluate(root->right);

        if (root->data == "+")
            return leftOperand + rightOperand;
        else if (root->data == "-")
            return leftOperand - rightOperand;
        else if (root->data == "*")
            return leftOperand * rightOperand;
        else if (root->data == "/")
            return leftOperand / rightOperand;
    }

    return 0;
}

int main() {
    string postfixExpression = "42*3+";
    TreeNode* root = buildExpressionTree(postfixExpression);

    cout << "Postfix Expression: " << postfixExpression << endl;
    cout << "Result: " << evaluate(root) << endl;

    return 0;
}
