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

// Function to insert a value into a binary search tree
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

    // Insert values into the BST
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    // In-order traversal to verify the tree
    cout << "In-order traversal: ";
    inOrderTraversal(root); // Output: 20 30 40 50 60 70 80

    return 0;
}
