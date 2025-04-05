#include <iostream>
#include <vector>
using namespace std;
int partition(vector<int>& arr, int low, int high) {
    int pivot = low;
    for (int i = low; i <= high; i++) {
        if (arr[i] <= arr[high]) {
            swap(arr[i], arr[pivot]);
            pivot++;
        }
    }
    return pivot - 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n;
    cout <<"Enter the number of elements in the array:";
    cin >> n;
    vector<int> arr(n);

    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    quickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    return 0;
}
