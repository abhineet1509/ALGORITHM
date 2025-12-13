#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(),
             [](auto &a, auto &b){ return a[1] < b[1]; });

        int cnt = 1;
        int last = pairs[0][1];

        for (int i = 1; i < pairs.size(); i++) {
            if (pairs[i][0] > last) {
                cnt++;
                last = pairs[i][1];
            }
        }
        return cnt;
    }
};

int main() {
    int n;
    cin >> n;

    vector<vector<int>> pairs(n, vector<int>(2));
    for (int i = 0; i < n; i++)
        cin >> pairs[i][0] >> pairs[i][1];

    Solution ob;
    cout << ob.findLongestChain(pairs);
}
