#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void insertToHeap(int arr[], int& n, int value) {
    n++;
    int i = n - 1;
    arr[i] = value;
    while (i != 0 && arr[(i - 1) / 2] < arr[i]) {
        swap(arr[i], arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void buildHeap(int arr[], int n) {
    for (int i = 1; i < n; i++)
        heapify(arr, i + 1, 0);
}

void displayHeap(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int n = 5;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++){
        cin>>arr[i];
    }
    buildHeap(arr, n);

    cout << "Max heap: ";
    displayHeap(arr, n);

    return 0;
}
