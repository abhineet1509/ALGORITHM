#include <iostream>
using namespace std;

// Recursive Binary Search on Rotated Sorted Array
int searchRecursive(int arr[], int low, int high, int target) {
    if (low > high)
        return -1;

    int mid = (low + high) / 2;

    if (arr[mid] == target)
        return mid;

    // Left half is sorted
    if (arr[low] <= arr[mid]) {
        if (arr[low] <= target && target < arr[mid])
            return searchRecursive(arr, low, mid - 1, target);
        else
            return searchRecursive(arr, mid + 1, high, target);
    }
    // Right half is sorted
    else {
        if (arr[mid] < target && target <= arr[high])
            return searchRecursive(arr, mid + 1, high, target);
        else
            return searchRecursive(arr, low, mid - 1, target);
    }
}

// Iterative Binary Search on Rotated Sorted Array
int searchIterative(int arr[], int n, int target) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == target)
            return mid;

        // Left half is sorted
        if (arr[low] <= arr[mid]) {
            if (arr[low] <= target && target < arr[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        // Right half is sorted
        else {
            if (arr[mid] < target && target <= arr[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }

    return -1;
}

int main() {
    int arr[] = {6, 7, 8, 9, 1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 3;

    // Recursive
    int idxRec = searchRecursive(arr, 0, n - 1, target);
    cout << "Recursive Search: ";
    if (idxRec != -1)
        cout << "Element found at index " << idxRec << endl;
    else
        cout << "Element not found\n";

    // Iterative
    int idxIter = searchIterative(arr, n, target);
    cout << "Iterative Search: ";
    if (idxIter != -1)
        cout << "Element found at index " << idxIter << endl;
    else
        cout << "Element not found\n";

    return 0;
}
