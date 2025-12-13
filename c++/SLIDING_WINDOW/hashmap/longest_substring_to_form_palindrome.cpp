#include <bits/stdc++.h>
using namespace std;
//longest substring that can be rearranged to form a palindrome
int longestSubstringPalindrome(string s) {
    int n = s.length();
    int ans = 0;

    for (int i = 0; i < n; i++) {
        unordered_map<char, int> freq;
        int odd = 0;

        for (int j = i; j < n; j++) {
            char c = s[j];
            freq[c]++;

            // update odd count
            if (freq[c] % 2 == 1) odd++;
            else odd--;

            // valid substring if at most 1 odd
            if (odd <= 1)
                ans = max(ans, j - i + 1);
        }
    }

    return ans;
}

bool isGoodPalindrome(const multiset<char>& s) {
    
    unordered_map<char,int> freq;
    for(char c : s) freq[c]++;
    
    int odd = 0;
    for(auto &p : freq) 
        if(p.second % 2) odd++;

    return odd <= 1;
}

int main() {
    string s;
    cin >> s;

  
    cout << longestSubstringPalindrome(s);
    return 0;
}
