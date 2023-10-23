#include <iostream>
#include <vector>

using namespace std;

// Function to find the floor of a target in a sorted rotated array
int findFloor(const vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size() - 1;
    int floor = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            return arr[mid];
        } else if (arr[mid] > target) {
            high = mid - 1;
        } else {
            floor = arr[mid];
            low = mid + 1;
        }
    }

    return floor;
}

// Function to find the ceil of a target in a sorted rotated array
int findCeil(const vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size() - 1;
    int ceil = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            return arr[mid];
        } else if (arr[mid] > target) {
            ceil = arr[mid];
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return ceil;
}

// Function to find the peak element in a sorted rotated array
int findPeak(const vector<int>& arr) {
    int low = 0;
    int high = arr.size() - 1;

    while (low < high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] > arr[mid + 1]) {
            return arr[mid];
        }

        if (arr[mid] < arr[mid + 1]) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }

    return arr[low]; // or arr[high]
}

// Function to find the minimum element in a sorted rotated array
int findMinimum(const vector<int>& arr) {
    int low = 0;
    int high = arr.size() - 1;

    while (low < high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] > arr[high]) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }

    return arr[low];
}

int main() {
    vector<int> rotatedArray = {11, 12, 15, 18, 2, 5, 6, 8};
    int target = 16;

    int floorValue = findFloor(rotatedArray, target);
    int ceilValue = findCeil(rotatedArray, target);
    int peakValue = findPeak(rotatedArray);
    int minValue = findMinimum(rotatedArray);

    cout << "Floor of " << target << ": " << floorValue << endl;
    cout << "Ceil of " << target << ": " << ceilValue << endl;
    cout << "Peak element: " << peakValue << endl;
    cout << "Minimum element: " << minValue << endl;

    return 0;
}
