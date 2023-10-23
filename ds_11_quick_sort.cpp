#include <iostream>
using namespace std;

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Partition the array into two halves
        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j <= high - 1; ++j) {
            if (arr[j] < pivot) {
                // Swap arr[i] and arr[j]
                ++i;
                swap(arr[i], arr[j]);
            }
        }

        // Swap arr[i+1] and arr[high]
        swap(arr[i + 1], arr[high]);

        int partitionIndex = i + 1;

        // Recursively sort the elements before and after partition
        quickSort(arr, low, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, high);
    }
}

int main() {
    const int MAX_SIZE = 100;
    int arr[MAX_SIZE];
    int size;

    cout << "Enter the size of the array: ";
    cin >> size;

    cout << "Enter elements of the array:" << endl;
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }

    quickSort(arr, 0, size - 1);

    cout << "Sorted array using Quick Sort: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
