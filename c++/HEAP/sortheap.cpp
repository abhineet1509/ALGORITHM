#include <iostream>
#include <vector>
using namespace std;

// Heapify a subtree rooted at index i in array of size n
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && arr[left] > arr[largest]) largest = left;
    if (right < n && arr[right] > arr[largest]) largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// Heap Sort function
void heapSort(vector<int>& arr) {
    int n = arr.size();

    // Step 1: Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Step 2: Extract elements from heap
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);      // Move max to end
        heapify(arr, i, 0);        // Heapify reduced heap
    }
}

int main() {
    vector<int> arr = {4, 10, 3, 5, 1};

    heapSort(arr);

    cout << "Sorted array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}
