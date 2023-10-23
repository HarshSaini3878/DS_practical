#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> findFirstNegativeInWindow(const vector<int>& arr, int k) {
    vector<int> result;

    // Queue to store indices of negative numbers in the current window
    queue<int> negIndices;

    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] < 0) {
            negIndices.push(i);
        }

        // If the front element of the queue is out of the current window, pop it
        while (!negIndices.empty() && negIndices.front() <= i - k) {
            negIndices.pop();
        }

        // Add the first negative integer in the current window to the result
        if (i >= k - 1) {
            result.push_back(negIndices.empty() ? 0 : arr[negIndices.front()]);
        }
    }

    return result;
}

int main() {
    int k = 3;
    vector<int> arr = {12, -1, -7, 8, -15, 30, 16, 28};

    vector<int> result = findFirstNegativeInWindow(arr, k);

    cout << "First negative integer in every window of size " << k << ":\n";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
