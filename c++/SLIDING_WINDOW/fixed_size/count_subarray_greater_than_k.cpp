#include <iostream>
#include <vector>
using namespace std;

int countSubarraysWithSumGreaterThanK(vector<int>& arr, int K) {
    int n = arr.size();
    int start = 0, end = 0;
    int sum = 0, count = 0;

    while (end < n) {
        sum += arr[end];

        // Shrink the window while sum is greater than K
        while (sum > K && start <= end) {
            // All subarrays from current start to end will be valid
            count += n - end;
            sum -= arr[start];
            start++;
        }

        end++;
    }

    return count;
}

int main() {
    vector<int> arr = {1, 2, 3, 4};  // Example array
    int K = 4;

    int result = countSubarraysWithSumGreaterThanK(arr, K);
    cout << "Number of subarrays with sum > " << K << " is: " << result << endl;

    return 0;
}
