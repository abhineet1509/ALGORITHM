#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> arr;
        for (int n : nums) arr.push_back(to_string(n));

        // Custom comparator: choose bigger combined form
        sort(arr.begin(), arr.end(), [](string &a, string &b) {
            return a + b > b + a;
        });

        // If largest number is 0, then entire number is 0
        if (arr[0] == "0") return "0";

        string ans = "";
        for (string &s : arr) ans += s;

        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3, 30, 34, 5, 9};
    cout << sol.largestNumber(nums);
    return 0;
}
