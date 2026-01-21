#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string orderlyQueue(string s, int k) {
        if (k > 1) {
            sort(s.begin(), s.end());
            return s;
        }

        string ans = s;
        int n = s.size();

        for (int i = 1; i < n; i++) {
            string rotated = s.substr(i) + s.substr(0, i);
            ans = min(ans, rotated);
        }
        return ans;
    }
};

int main() {
    Solution sol;
    cout << sol.orderlyQueue("cba", 1) << endl; // acb
    cout << sol.orderlyQueue("cba", 2) << endl; // abc
}
