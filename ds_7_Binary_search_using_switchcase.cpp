#include <iostream>
#include <algorithm>
using namespace std;

int binarySearch(int arr[], int size, int key) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key) {
            return mid;  // Key found at index mid
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;  // Key not found
}

int main() {
    const int MAX_SIZE = 100;
    int arr[MAX_SIZE];
    int size, key;

    cout << "Enter the size of the array: ";
    cin >> size;

    cout << "Enter elements of the array (sorted):" << endl;
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }

    cout << "Enter the key to search: ";
    cin >> key;

    int result = binarySearch(arr, size, key);

    if (result != -1) {
        cout << "Key found at index " << result << endl;
    } else {
        cout << "Key not found in the array." << endl;
    }

    return 0;
}
