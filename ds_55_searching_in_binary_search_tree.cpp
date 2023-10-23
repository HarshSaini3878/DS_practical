#include <iostream>
using namespace std;

// Define a structure for a tree node
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

TreeNode* insert(TreeNode* root, int val) {
    if (root == nullptr) {
        return new TreeNode(val);
    }

    if (val < root->data) {
        root->left = insert(root->left, val);
    } else if (val > root->data) {
        root->right = insert(root->right, val);
    }

    return root;
}

// Function to search for a value in a binary search tree
bool search(TreeNode* root, int val) {
    if (root == nullptr)
        return false;

    if (root->data == val)
        return true;

    if (val < root->data)
        return search(root->left, val);
    else
        return search(root->right, val);
}

int main() {
    // Create a binary search tree
    TreeNode* root = nullptr;

    // Insert values into the BST
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    int target = 30;

    // Search for a value in the BST
    bool found = search(root, target);

    if (found) {
        cout << target << " is found in the BST." << endl;
    } else {
        cout << target << " is not found in the BST." << endl;
    }

    return 0;
}
