#include <bits/stdc++.h>
using namespace std;

pair<int, vector<int>> longestHarmonicSubsequence(vector<int>& nums) {
    unordered_map<int, int> freq;
    for (int num : nums) freq[num]++;
    
    int maxLen = 0;
    int num1 = 0, num2 = 0;
    
  for (auto it = freq.begin(); it != freq.end(); ++it) {
    int key = it->first;
    int val = it->second;

    if (freq.count(key + 1)) {
        int len = val + freq[key + 1];
        if (len > maxLen) {
            maxLen = len;
            num1 = key;
            num2 = key + 1;
        }
    }
}

    vector<int> subseq;
    for (int num : nums) {
        if (num == num1 || num == num2) subseq.push_back(num);
    }

    return make_pair(maxLen, subseq);
}

int main() {
    vector<int> nums = {1,3,2,2,5,2,3,7};
    pair<int, vector<int>> result = longestHarmonicSubsequence(nums);

    cout << "Length: " << result.first << endl;
    cout << "Subsequence: ";
    for (int x : result.second) cout << x << " ";
    cout << endl;

    return 0;
}

