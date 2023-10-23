#include <iostream>

using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
};

int levels(TreeNode* root){
    if(root==NULL) return 0;
    return 1+max(levels(root->right),levels(root->left));
}
void helper(TreeNode* root , int &maxDia){
    if(root==NULL) return ;
    int Dia=levels(root->right)+levels(root->left);
    
    maxDia=max(maxDia,Dia);
    helper(root->right,maxDia);
    helper(root->left,maxDia);
}
    int diameterOfBinaryTree(TreeNode* root) {
        int maxDia=0;
        helper(root,maxDia);
        return maxDia;
        
    }