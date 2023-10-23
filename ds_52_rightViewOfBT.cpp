#include <iostream>

using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
};

void rightView(TreeNode* root) {
    if (!root) return;

    cout << root->data << " ";

    while (root->right) {
        root = root->right;
        cout << root->data << " ";
    }

    root = root->left;
    while (root) {
        cout << root->data << " ";
        root = root->left;
    }
}
