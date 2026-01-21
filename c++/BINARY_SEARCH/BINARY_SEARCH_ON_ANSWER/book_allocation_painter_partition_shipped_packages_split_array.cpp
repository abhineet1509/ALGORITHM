#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int>& arr, int n, int m, int maxPages) {
    int students = 1, pages = 0;

    for (int i = 0; i < n; i++) {
        if (pages + arr[i] <= maxPages) {
            pages += arr[i];
        } else {
            students++;
            pages = arr[i];
            if (students > m) return false;
        }
    }
    return true;
}
 // O(n×log(sum of boards))
int allocateBooksOptimised(vector<int>& arr, int n, int m) {
    if (m > n) return -1;

    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    int ans = -1;  //high

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (isPossible(arr, n, m, mid)) {
            ans = mid;
            high = mid - 1;   // minimize max pages
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int allocateBooksBrute(vector<int>& arr, int n, int m) {
    if (m > n) return -1;

    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);

    for (int pages = low; pages <= high; pages++) {
        if (isPossible(arr, n, m, pages))
            return pages;
    }
    return -1;
}
int main(){
    vector<int> ans = {10,20,30,40};
    int n = ans.size();
    int m = 2;
   cout<< allocateBooksOptimised(ans,n,m);
}