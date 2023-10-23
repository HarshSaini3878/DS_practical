#include <iostream>
#include <map>

using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
};

void topView(TreeNode* root) {
    if (!root) return;

    map<int, int> topViewMap;
    topViewMap[0] = root->data;

    int horizontalDistance = 0;
    while (root->left) {
        root = root->left;
        --horizontalDistance;
        topViewMap[horizontalDistance] = root->data;
    }

    root = root->right;
    horizontalDistance = 1;
    while (root) {
        topViewMap[horizontalDistance] = root->data;
        root = root->right;
        ++horizontalDistance;
    }

    for (const auto& pair : topViewMap) cout << pair.second << " ";
}
