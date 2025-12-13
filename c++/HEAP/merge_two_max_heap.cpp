#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int> &arr, int n, int i) {
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

vector<int> mergeHeaps(vector<int> &a, vector<int> &b) {
    vector<int> merged;

    // Step 1: join arrays
    for (int x : a) merged.push_back(x);
    for (int x : b) merged.push_back(x);

    int n = merged.size();

    // Step 2: build max heap
    for (int i = n/2 - 1; i >= 0; i--)
        heapify(merged, n, i);

    return merged;
}

// ------------ Driver ------------
int main() {
    vector<int> a = {10, 5, 6, 2};
    vector<int> b = {12, 7, 9};

    vector<int> result = mergeHeaps(a, b);

    for (int x : result) cout << x << " ";
    return 0;
}
