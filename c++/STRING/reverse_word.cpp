#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords_extraSpace(string s) {
        stringstream ss(s);
        string word, res;

        while (ss >> word) {
            if (res.empty())
                res = word;
            else
                res = word + " " + res;
        }
        return res;
    }
      string reverseWords_extraSpace(string s) {
        int n = s.size();
        string res = "", word = "";

        for (int i = 0; i <= n; i++) {
            if (i == n || s[i] == ' ') {
                if (!word.empty()) {
                    if (res.empty())
                        res = word;
                    else
                        res = word + " " + res;
                    word.clear();
                }
            } else {
                word += s[i];
            }
        }
        return res;
    }
    string reverseWords_inPlace(string s) {
        reverse(s.begin(), s.end());

        int idx = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ' ') {
                if (idx > 0) s[idx++] = ' ';

                int j = i;
                while (j < s.size() && s[j] != ' ') j++;
                reverse(s.begin() + i, s.begin() + j);

                while (i < j)
                    s[idx++] = s[i++];
            }
        }
        s.resize(idx);
        return s;
    }

    string reverseEachWord(string s) {
        int start = 0;
        for (int i = 0; i <= s.size(); i++) {
            if (i == s.size() || s[i] == ' ') {
                reverse(s.begin() + start, s.begin() + i);
                start = i + 1;
            }
        }
        return s;
    }
};

int main() {
    Solution obj;

    string s = "  the sky   is blue  ";

    cout << obj.reverseWords_extraSpace(s) << endl;
    cout << obj.reverseWords_inPlace(s) << endl;
    cout << obj.reverseEachWord("the sky is blue") << endl;

    return 0;
}
