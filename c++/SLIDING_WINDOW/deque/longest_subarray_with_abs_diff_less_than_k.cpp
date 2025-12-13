#include <bits/stdc++.h>
using namespace std;

// 1️⃣ Brute Force O(n^2)
int longestSubarrayBruteForce(vector<int>& nums, int K) {
    int n = nums.size();
    int maxLen = 0;

    for (int i = 0; i < n; i++) {    // 1 3 2 2 5 
           for (int j = i; j < n; j++) {  // contradition 1 5 2
            int subMax = *max_element(nums.begin() + i, nums.begin() + j + 1);
            int subMin = *min_element(nums.begin() + i, nums.begin() + j + 1);

            if (subMax - subMin <= K)
                maxLen = max(maxLen, j - i + 1);
            else
                break; // optional: stop expanding
        }
    }

    return maxLen;
}


// 2️⃣ Multiset Sliding Window O(n log n)
int longestSubarrayMultiset(vector<int>& nums, int K) {
    multiset<int> s;
    int l = 0, ans = 0;

    for (int r = 0; r < nums.size(); r++) {
        s.insert(nums[r]);

        while (*s.rbegin() - *s.begin() > K) {
            s.erase(s.find(nums[l]));
            l++;
        }
        ans = max(ans, r - l + 1);
    }
    return ans;
}

// 3️⃣ Deque / Monotonic Queue O(n)
int longestSubarrayDeque(vector<int>& nums, int K) {
    int n = nums.size(), l = 0, ans = 0;
    deque<int> maxq, minq;

    for (int r = 0; r < n; r++) {
        // maintain decreasing max queue
        while (!maxq.empty() && nums[r] > nums[maxq.back()]) maxq.pop_back();
        maxq.push_back(r);

        // maintain increasing min queue
        while (!minq.empty() && nums[r] < nums[minq.back()]) minq.pop_back();
        minq.push_back(r);

        // shrink window if diff > K
        while (nums[maxq.front()] - nums[minq.front()] > K) {
            if (maxq.front() == l) maxq.pop_front();
            if (minq.front() == l) minq.pop_front();
            l++;
        }

        ans = max(ans, r - l + 1);
    }

    return ans;
}

int main() {
    vector<int> nums = {1, 3, 2, 2, 5, 2, 3, 7};
    int K = 2;

    cout << "Brute Force: " << longestSubarrayBruteForce(nums, K) << endl;
    cout << "Multiset: " << longestSubarrayMultiset(nums, K) << endl;
    cout << "Deque: " << longestSubarrayDeque(nums, K) << endl;
}
