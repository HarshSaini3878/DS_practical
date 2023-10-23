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
    int size, position, value;

    // Insertion
    cout << "Enter the size of the array: ";
    cin >> size;

    cout << "Enter elements of the array:" << endl;
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }

    cout << "Enter the position and value to insert: ";
    cin >> position >> value;

    if (position < 0 || position > size) {
        cout << "Invalid position." << endl;
    } else {
        for (int i = size; i > position; --i) {
            arr[i] = arr[i - 1];
        }
        arr[position] = value;
        ++size;

        displayArray(arr, size);
    }

    // Deletion
    cout << "Enter the position to delete: ";
    cin >> position;

    if (position < 0 || position >= size) {
        cout << "Invalid position." << endl;
    } else {
        for (int i = position; i < size - 1; ++i) {
            arr[i] = arr[i + 1];
        }
        --size;

        displayArray(arr, size);
    }

    return 0;
}
