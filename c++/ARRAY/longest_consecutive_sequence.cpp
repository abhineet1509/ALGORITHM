#include <bits/stdc++.h>
using namespace std;

vector<int> longestConsecutiveSequence(vector<int>& nums) {
    unordered_set<int> s(nums.begin(), nums.end());
    int maxLen = 0;
    int startNum = 0;

    for (int num : nums) {
        if (!s.count(num - 1)) { // start of a sequence
            int curr = num;
            int len = 1;
            while (s.count(curr + 1)) {
                curr++;
                len++;
            }
            if (len > maxLen) {
                maxLen = len;
                startNum = num;
            }
        }
    }

    vector<int> res;
    for (int i = 0; i < maxLen; i++)
        res.push_back(startNum + i);

    return res;
}

int main() {
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    vector<int> seq = longestConsecutiveSequence(nums);

    for (int x : seq) cout << x << " "; // Output: 1 2 3 4
    cout << endl;
    return 0;
}
