#include <iostream>
using namespace std;

void printPointer(int *arr, int n) {
    for (int i = 0; i < n; i++) cout << *(arr + i) << " ";
    cout << endl;
}

void printArrayNotation(int arr[], int n) {
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int staticArr[5];
    cout << "Enter 5 elements (static): ";
    for (int i = 0; i < 5; i++) cin >> staticArr[i];
    printPointer(staticArr, 5);
    printArrayNotation(staticArr, 5);

    int n;
    cout << "Enter size (dynamic): ";
    cin >> n;
    int *dynamicArr = new int[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) cin >> *(dynamicArr + i);
    printPointer(dynamicArr, n);
    printArrayNotation(dynamicArr, n);

    delete[] dynamicArr;
    return 0;
}
