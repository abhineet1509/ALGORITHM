#include <bits/stdc++.h>
using namespace std;

class Solution {
    unordered_map<string,bool> memo;
public:
    bool isScramble(string s1, string s2) {
        string key = s1 + "#" + s2;
        if(memo.count(key)) return memo[key];

        if(s1 == s2) return memo[key] = true;
        if(s1.size() != s2.size()) return memo[key] = false;

        string t1 = s1, t2 = s2;
        sort(t1.begin(), t1.end());
        sort(t2.begin(), t2.end());
        if(t1 != t2) return memo[key] = false; // characters mismatch

        int n = s1.size();
        for(int i=1;i<n;i++){
            // Without swap
            if(isScramble(s1.substr(0,i), s2.substr(0,i)) && 
               isScramble(s1.substr(i), s2.substr(i)))
                return memo[key]=true;
            // With swap
            if(isScramble(s1.substr(0,i), s2.substr(n-i)) &&
               isScramble(s1.substr(i), s2.substr(0,n-i)))
                return memo[key]=true;
        }
        return memo[key]=false;
    }
};

int main() {
    Solution sol;
    string s1 = "great", s2 = "rgeat";
    cout << (sol.isScramble(s1,s2) ? "true" : "false") << endl; // Output: true
}
