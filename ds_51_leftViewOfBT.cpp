#include <iostream>

using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
};

void leftView(TreeNode* root) {
    if (!root) return;

    cout << root->data << " ";

    while (root->left) {
        root = root->left;
        cout << root->data << " ";
    }

    root = root->right;
    while (root) {
        cout << root->data << " ";
        root = root->right;
    }
}
