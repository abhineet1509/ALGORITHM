#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        vector<int> ans(n, 0);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top() < heights[i]) {
                ans[i]++;
                st.pop();
            }
            if (!st.empty()) ans[i]++;
            st.push(heights[i]);
        }
        return ans;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> heights(n);
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }

    Solution sol;
    vector<int> result = sol.canSeePersonsCount(heights);

    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
