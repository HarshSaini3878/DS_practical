#include <iostream>
using namespace std;


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


TreeNode* lowestCommonAncestor(TreeNode* root, int p, int q) {
    if (root == nullptr) return nullptr;

  
    if (root->data == p || root->data == q) return root;

    TreeNode* leftLCA = lowestCommonAncestor(root->left, p, q);
    TreeNode* rightLCA = lowestCommonAncestor(root->right, p, q);


    if (leftLCA != nullptr && rightLCA != nullptr) return root;

    return (leftLCA != nullptr) ? leftLCA : rightLCA;
}

int main() {
   
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

  

    int p = 5; 
    int q = 1; 

    TreeNode* lca = lowestCommonAncestor(root, p, q);

    cout << "Lowest Common Ancestor of " << p << " and " << q << " is: " << lca->data << endl; // Output: 3

    return 0;
}
