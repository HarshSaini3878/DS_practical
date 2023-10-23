#include <iostream>

using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* insert(TreeNode* root, int value) {
    if (!root) {
        root = new TreeNode{value, nullptr, nullptr};
    } else if (value < root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    return root;
}



TreeNode* minValueNode(TreeNode* node) {
    TreeNode* current = node;
    while (current && current->left) {
        current = current->left;
    }
    return current;
}

TreeNode* deleteNode(TreeNode* root, int key) {
    if (!root) {
        return root;
    }

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        if (!root->left) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        } else if (!root->right) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }

        TreeNode* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}
int main() {
    TreeNode* root = nullptr;


    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

   
    int keyToDelete = 30;
    root = deleteNode(root, keyToDelete);



    return 0;
}
