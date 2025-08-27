#include <iostream>
using namespace std;

int searchRecursive(int arr[], int low, int high, int target) {
    if (low > high)
        return -1;

    int mid = (low + high) / 2;

    if (arr[mid] == target)
        return mid;

    if (arr[low] < arr[mid]) {
        if (arr[low] <= target && target < arr[mid])
            return searchRecursive(arr, low, mid - 1, target);
        else
            return searchRecursive(arr, mid + 1, high, target);
    } else if (arr[mid] < arr[high]) {
        if (arr[mid] < target && target <= arr[high])
            return searchRecursive(arr, mid + 1, high, target);
        else
            return searchRecursive(arr, low, mid - 1, target);
    } else {
        int left = searchRecursive(arr, low, mid - 1, target);
        if (left != -1)
            return left;
        return searchRecursive(arr, mid + 1, high, target);
    }
}

int searchIterative(int arr[], int n, int target) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == target)
            return mid;

        if (arr[low] == arr[mid] && arr[mid] == arr[high]) {
            low++;
            high--;
        } else if (arr[low] <= arr[mid]) {
            if (arr[low] <= target && target < arr[mid])
                high = mid - 1;
            else
                low = mid + 1;
        } else {
            if (arr[mid] < target && target <= arr[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }

    return -1;
}

int main() {
    int arr[] = {2, 5, 6, 0, 0, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 0;

    int idxRec = searchRecursive(arr, 0, n - 1, target);
    cout << "Recursive Search: ";
    if (idxRec != -1)
        cout << "Element found at index " << idxRec << endl;
    else
        cout << "Element not found\n";

    int idxIter = searchIterative(arr, n, target);
    cout << "Iterative Search: ";
    if (idxIter != -1)
        cout << "Element found at index " << idxIter << endl;
    else
        cout << "Element not found\n";

    return 0;
}
