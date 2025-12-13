#include <bits/stdc++.h>
using namespace std;

vector<string> distinctPalindromicSubstrings(string s) {
    unordered_set<string> st;
    int n = s.size();

    for(int center = 0; center < n; center++){
        // Odd length palindromes
        int l = center, r = center;
        while(l >= 0 && r < n && s[l] == s[r]){
            st.insert(s.substr(l, r - l + 1));
            l--; r++;
        }

        // Even length palindromes
        l = center; r = center + 1;
        while(l >= 0 && r < n && s[l] == s[r]){
            st.insert(s.substr(l, r - l + 1));
            l--; r++;
        }
    }

    vector<string> res(st.begin(), st.end());
    sort(res.begin(), res.end()); // optional, for driver code
    return res;
}

int main() {
    string s = "abaaa";
    vector<string> ans = distinctPalindromicSubstrings(s);

    cout << "[";
    for(int i = 0; i < ans.size(); i++){
        cout << "\"" << ans[i] << "\"";
        if(i != ans.size()-1) cout << ", ";
    }
    cout << "]\n";
}
