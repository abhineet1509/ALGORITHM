#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int longestSubarrayWithSumAtMostK(vector<int>& nums, int k) {
    bool hasNegative = false;
    for (int num : nums)
        if (num < 0) {
            hasNegative = true;
            break;
        }

    if (!hasNegative) {
        // Sliding window approach (for non-negative elements)
        int left = 0, sum = 0, maxLen = 0;
        for (int right = 0; right < nums.size(); right++) {
            sum += nums[right];
            while (sum > k) sum -= nums[left++];
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen; 
    } else {
        // Prefix sum + deque approach (handles negatives too)
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i)
            prefix[i + 1] = prefix[i] + nums[i];

        deque<int> dq;
        int maxLen = 0;  //minLen = n+1
        for (int i = 0; i <= n; ++i) {
            while (!dq.empty() && prefix[i] - prefix[dq.front()] > k){
                dq.pop_front();
                maxLen = max(maxLen, i - dq.front());
                }
            while (!dq.empty() && prefix[i] <= prefix[dq.back()])
                dq.pop_back();
            dq.push_back(i);
        }
        return maxLen;
    }
}
int main() {
    int n;
    long long k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];  //2 -1 4

    cout << longestSubarrayWithSumAtMostK(a, k);
    return 0;
}