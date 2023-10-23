#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> nextGreaterToRight(const vector<int>& arr) {
    vector<int> result(arr.size(), -1);
    stack<int> s;

    for (int i = 0; i < arr.size(); ++i) {
        while (!s.empty() && arr[i] > arr[s.top()]) {
            result[s.top()] = arr[i];
            s.pop();
        }
        s.push(i);
    }

    return result;
}

vector<int> nextGreaterToLeft(const vector<int>& arr) {
    vector<int> result(arr.size(), -1);
    stack<int> s;

    for (int i = arr.size() - 1; i >= 0; --i) {
        while (!s.empty() && arr[i] > arr[s.top()]) {
            s.pop();
        }
        if (!s.empty()) {
            result[i] = arr[s.top()];
        }
        s.push(i);
    }

    return result;
}

vector<int> nearestSmallerToLeft(const vector<int>& arr) {
    vector<int> result(arr.size(), -1);
    stack<int> s;

    for (int i = 0; i < arr.size(); ++i) {
        while (!s.empty() && arr[i] <= arr[s.top()]) {
            s.pop();
        }
        if (!s.empty()) {
            result[i] = arr[s.top()];
        }
        s.push(i);
    }

    return result;
}

vector<int> nextSmallerToRight(const vector<int>& arr) {
    vector<int> result(arr.size(), -1);
    stack<int> s;

    for (int i = arr.size() - 1; i >= 0; --i) {
        while (!s.empty() && arr[i] <= arr[s.top()]) {
            s.pop();
        }
        if (!s.empty()) {
            result[i] = arr[s.top()];
        }
        s.push(i);
    }

    return result;
}

int main() {
    vector<int> arr = {4, 5, 2, 10, 8};

    vector<int> ngr = nextGreaterToRight(arr);
    vector<int> ngl = nextGreaterToLeft(arr);
    vector<int> nsl = nearestSmallerToLeft(arr);
    vector<int> nsr = nextSmallerToRight(arr);

    cout << "Next Greater to Right: ";
    for (int num : ngr) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Next Greater to Left: ";
    for (int num : ngl) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Nearest Smaller to Left: ";
    for (int num : nsl) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Next Smaller to Right: ";
    for (int num : nsr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
