#include <iostream>
#include <map>

using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
};

void bottomView(TreeNode* root) {
    if (!root) return;

    map<int, int> bottomViewMap;

    int horizontalDistance = 0;
    while (root->left) {
        root = root->left;
        --horizontalDistance;
    }

    while (root) {
        bottomViewMap[horizontalDistance] = root->data;
        root = root->right;
        ++horizontalDistance;
    }

    for (const auto& pair : bottomViewMap) cout << pair.second << " ";
}
