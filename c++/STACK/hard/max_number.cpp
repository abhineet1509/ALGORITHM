#include <bits/stdc++.h>
using namespace std;

vector<int> maxSubsequence(vector<int>& nums, int k) {
    vector<int> st;
    int drop = nums.size() - k;

    for (int i = 0; i < nums.size(); i++) {
        while (!st.empty() && drop > 0 && st.back() < nums[i]) {
            st.pop_back();
            drop--;
        }
        st.push_back(nums[i]);
    }

    st.resize(k);
    return st;
}

bool greaterVector(vector<int>& a, int i, vector<int>& b, int j) {
    while (i < a.size() && j < b.size() && a[i] == b[j]) {
        i++;
        j++;
    }
    if (j == b.size()) return true;
    if (i < a.size() && a[i] > b[j]) return true;
    return false;
}

vector<int> mergeVector(vector<int>& a, vector<int>& b) {
    vector<int> res;
    int i = 0, j = 0;

    while (i < a.size() || j < b.size()) {
        if (greaterVector(a, i, b, j))
            res.push_back(a[i++]);
        else
            res.push_back(b[j++]);
    }
    return res;
}

vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
    vector<int> ans(k, 0);

    int start = max(0, k - (int)nums2.size());
    int end = min(k, (int)nums1.size());

    for (int i = start; i <= end; i++) {
        vector<int> a = maxSubsequence(nums1, i);
        vector<int> b = maxSubsequence(nums2, k - i);
        vector<int> cand = mergeVector(a, b);

        if (cand > ans)
            ans = cand;
    }
    return ans;
}

int main() {
    vector<int> nums1 = {3, 4, 6, 5};
    vector<int> nums2 = {9, 1, 2, 5, 8, 3};
    int k = 5;

    vector<int> result = maxNumber(nums1, nums2, k);

    cout << "Maximum Number: ";
    for (int x : result)
        cout << x << " ";
    cout << endl;

    return 0;
}
