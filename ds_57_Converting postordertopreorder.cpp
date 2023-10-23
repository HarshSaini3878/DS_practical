#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> convertPostToPreBST(const vector<int>& postOrder) {
    vector<int> preOrder;
    stack<int> s;
    int n = postOrder.size();

    for (int i = 0; i < n; ++i) {
        while (!s.empty() && s.top() < postOrder[i]) {
            s.pop();
        }
        s.push(postOrder[i]);
    }

    while (!s.empty()) {
        preOrder.push_back(s.top());
        s.pop();
    }

    reverse(preOrder.begin(), preOrder.end());

    return preOrder;
}

int main() {
    vector<int> postOrderBST = {20, 40, 30, 60, 80, 70, 50};
    vector<int> preOrderBST = convertPostToPreBST(postOrderBST);

    cout << "Preorder for BST: ";
    for (int num : preOrderBST) {
        cout << num << " ";
    }

    return 0;
}
