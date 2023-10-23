#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

void displayArray(int arr[], int size) {
    cout << "Array: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[MAX_SIZE];
    int size, value;

    // Insertion at Beginning
    cout << "Enter the size of the array: ";
    cin >> size;

    cout << "Enter elements of the array:" << endl;
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }

    cout << "Enter the value to insert at the beginning: ";
    cin >> value;

    if (size >= MAX_SIZE) {
        cout << "Array overflow." << endl;
    } else {
        for (int i = size; i > 0; --i) {
            arr[i] = arr[i - 1];
        }
        arr[0] = value;
        ++size;

        displayArray(arr, size);
    }

    // Deletion at Beginning
    if (size <= 0) {
        cout << "Array underflow." << endl;
    } else {
        for (int i = 0; i < size - 1; ++i) {
            arr[i] = arr[i + 1];
        }
        --size;

        displayArray(arr, size);
    }

    return 0;
}
