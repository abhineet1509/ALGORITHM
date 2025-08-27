#include <iostream>
using namespace std;

// Recursive Binary Search
int binarySearchRecursive(int arr[], int low, int high, int target) {
    if (low > high)
        return -1; // Not found

    int mid = (low + high) / 2;

    if (arr[mid] == target)
        return mid;
    else if (arr[mid] > target)
        return binarySearchRecursive(arr, low, mid - 1, target);
    else
        return binarySearchRecursive(arr, mid + 1, high, target);
}

// Iterative Binary Search
int binarySearchIterative(int arr[], int n, int target) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1; // Not found
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 7;

    // Recursive search
    int indexRec = binarySearchRecursive(arr, 0, n - 1, target);
    cout << "Recursive Binary Search: ";
    if (indexRec != -1)
        cout << "Element found at index " << indexRec << endl;
    else
        cout << "Element not found\n";

    // Iterative search
    int indexIter = binarySearchIterative(arr, n, target);
    cout << "Iterative Binary Search: ";
    if (indexIter != -1)
        cout << "Element found at index " << indexIter << endl;
    else
        cout << "Element not found\n";

    return 0;
}
