#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        if (nums1.empty() || nums2.empty() || k == 0) return ans;

        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<>
        > pq;

        for (int i = 0; i < min((int)nums1.size(), k); i++)
            pq.push({nums1[i] + nums2[0], {i, 0}});

        while (!pq.empty() && k--) {
            auto cur = pq.top();
            pq.pop();

            int i = cur.second.first;
            int j = cur.second.second;

            ans.push_back({nums1[i], nums2[j]});

            if (j + 1 < nums2.size())
                pq.push({nums1[i] + nums2[j + 1], {i, j + 1}});
        }
        return ans;
    }
};

int main() {
    int n, m, k;
    cin >> n >> m;

    vector<int> nums1(n), nums2(m);
    for (int i = 0; i < n; i++) cin >> nums1[i];
    for (int i = 0; i < m; i++) cin >> nums2[i];

    cin >> k;

    Solution sol;
    auto res = sol.kSmallestPairs(nums1, nums2, k);

    for (auto &p : res)
        cout << "[" << p[0] << "," << p[1] << "] ";

    return 0;
}
