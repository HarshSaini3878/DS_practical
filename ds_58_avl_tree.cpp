#include <iostream>
using namespace std;

// Define a structure for a tree node
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    int height;

    TreeNode(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
        height = 1;
    }
};

// Function to get the height of a node
int getHeight(TreeNode* node) {
    if (node == nullptr)
        return 0;
    return node->height;
}

// Function to update the height of a node
void updateHeight(TreeNode* node) {
    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
}

// Function to perform a right rotation
TreeNode* rightRotate(TreeNode* y) {
    TreeNode* x = y->left;
    TreeNode* T = x->right;

    x->right = y;
    y->left = T;

    updateHeight(y);
    updateHeight(x);

    return x;
}

// Function to perform a left rotation
TreeNode* leftRotate(TreeNode* x) {
    TreeNode* y = x->right;
    TreeNode* T = y->left;

    y->left = x;
    x->right = T;

    updateHeight(x);
    updateHeight(y);

    return y;
}

// Function to balance a node
TreeNode* balanceNode(TreeNode* node) {
    int balanceFactor = getHeight(node->left) - getHeight(node->right);

    if (balanceFactor > 1) {
        if (getHeight(node->left->left) >= getHeight(node->left->right))
            return rightRotate(node);
        else {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
    }
    if (balanceFactor < -1) {
        if (getHeight(node->right->right) >= getHeight(node->right->left))
            return leftRotate(node);
        else {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
    }

    return node;
}

// Function to insert a value into an AVL tree
TreeNode* insert(TreeNode* root, int val) {
    if (root == nullptr) return new TreeNode(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else if (val > root->data)
        root->right = insert(root->right, val);
    else
        return root; // Duplicate values not allowed in BST

    updateHeight(root);

    return balanceNode(root);
}

// Function to perform an in-order traversal of the AVL tree
void inOrderTraversal(TreeNode* root) {
    if (root == nullptr) return;

    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

int main() {
    TreeNode* root = nullptr;

    int values[] = {10, 5, 15, 3, 7, 12, 17};

    for (int val : values) {
        root = insert(root, val);
    }

    cout << "In-order traversal of AVL tree: ";
    inOrderTraversal(root); // Output: 3 5 7 10 12 15 17

    return 0;
}
