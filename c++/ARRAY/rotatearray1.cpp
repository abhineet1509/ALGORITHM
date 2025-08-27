#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void rotateExtraArray(vector<int>& arr, int k) {
    int n = arr.size();
    k %= n;
    vector<int> temp(n);
    for (int i = 0; i < n; i++)
        temp[(i + k) % n] = arr[i];
    arr = temp;
}



// 3. Reverse Method
void rotateReverse(vector<int>& arr, int k) {
    int n = arr.size();
    k %= n;
    reverse(arr.begin(), arr.end());
    reverse(arr.begin(), arr.begin() + k);
    reverse(arr.begin() + k, arr.end());
}

// 4. STL rotate Method
void rotateSTL(vector<int>& arr, int k) {
    int n = arr.size();
    k %= n;
    rotate(arr.rbegin(), arr.rbegin() + k, arr.rend()); 
}

// Utility function to print array
void printArray(const vector<int>& arr) {
    for (int x : arr) cout << x << " ";
    cout << endl;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;

    vector<int> a1 = arr;
    rotateExtraArray(a1, k);
    cout << "Extra Array: "; printArray(a1);

    vector<int> a3 = arr;
    rotateReverse(a3, k);
    cout << "Reverse Method: "; printArray(a3);

    vector<int> a4 = arr;
    rotateSTL(a4, k);
    cout << "STL rotate: "; printArray(a4);

    return 0;
}
