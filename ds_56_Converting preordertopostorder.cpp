#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> convertPreToPostBST(const vector<int>& preOrder) {
    vector<int> postOrder;
    stack<int> s;
    int n = preOrder.size();

    for (int i = n - 1; i >= 0; --i) {
        while (!s.empty() && s.top() < preOrder[i]) {
            postOrder.push_back(s.top());
            s.pop();
        }
        s.push(preOrder[i]);
    }

    while (!s.empty()) {
        postOrder.push_back(s.top());
        s.pop();
    }

   reverse(postOrder.begin(), postOrder.end());

    return postOrder;
}

int main() {
    vector<int> preOrderBST = {50, 30, 20, 40, 70, 60, 80};
    vector<int> postOrderBST = convertPreToPostBST(preOrderBST);

    cout << "Postorder for BST: ";
    for (int num : postOrderBST) {
        cout << num << " ";
    }

    return 0;
}
