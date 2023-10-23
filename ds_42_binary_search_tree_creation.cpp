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

// Function to insert a value into the binary search tree
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

// Function to perform an in-order traversal of the binary search tree
void inOrderTraversal(TreeNode* root) {
    if (root == nullptr) return;

    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

int main() {
    // Create a binary search tree
    TreeNode* root = nullptr;

    int values[] = {50, 30, 70, 20, 40, 60, 80};

    for (int val : values) {
        root = insert(root, val);
    }

    // In-order traversal to verify the tree
    cout << "In-order traversal: ";
    inOrderTraversal(root); // Output: 20 30 40 50 60 70 80

    return 0;
}
