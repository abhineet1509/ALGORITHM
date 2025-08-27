#include <bits/stdc++.h>
using namespace std;

int longestIncreasingSubstringOptimized(vector<int>& arr) {
    int maxLen = 1, currLen = 1;
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] > arr[i - 1]) {
            currLen++;
            maxLen = max(maxLen, currLen);
        } else {
            currLen = 1;
        }
    }
    return maxLen;
}
int main(){
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int result = longestIncreasingSubstringOptimized(arr);
    cout << "Length of the longest increasing substring: " << result << endl;

    return 0;
}