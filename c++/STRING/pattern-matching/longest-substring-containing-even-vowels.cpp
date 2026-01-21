#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<string, int> mp;

        string state = "00000";

        mp[state] = -1;   // base case
        int ans = 0;

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];

            if (c == 'a') state[0] = (state[0] == '0' ? '1' : '0');
            else if (c == 'e') state[1] = (state[1] == '0' ? '1' : '0');
            else if (c == 'i') state[2] = (state[2] == '0' ? '1' : '0');
            else if (c == 'o') state[3] = (state[3] == '0' ? '1' : '0');
            else if (c == 'u') state[4] = (state[4] == '0' ? '1' : '0');

            if (mp.find(state) != mp.end()) {
                ans = max(ans, i - mp[state]);
            } else {
                mp[state] = i;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    string s = "eleetminicoworoep";
    cout << sol.findTheLongestSubstring(s); // Output: 13
    return 0;
}
