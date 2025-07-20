#include<bits/stdc++.h>
using namespace std;

int countSubarraysDivByK(vector<int>& nums, int k) {
    unordered_map<int, int> remainderFreq;
    remainderFreq[0] = 1;

    int sum = 0, count = 0;

    for (int num : nums) {
        sum += num;
        int rem = ((sum % k) + k) % k;  // Ensure non-negative remainder

        // ✅ Check using .find()
        if (remainderFreq.find(rem) != remainderFreq.end()) {
            count += remainderFreq[rem];
        }

        remainderFreq[rem]++;
    }

    return count;
}
int main() {
    vector<int> nums = {4, 5, 0, -2, -3, 1};
    int k = 5;

    int result = countSubarraysDivByK(nums, k);
    cout << "Number of subarrays divisible by " << k << ": " << result << endl;

    return 0;
}