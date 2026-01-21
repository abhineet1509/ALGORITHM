#include <bits/stdc++.h>
using namespace std;

string longestWord(vector<string>& words) {
    sort(words.begin(), words.end(),
        [](const string& a, const string& b) {
            if (a.size() == b.size())
                return a < b;
            return a.size() < b.size();
        });

    unordered_set<string> built;
    string ans = "";

    for (const string& w : words) {
        if (w.size() == 1 || built.count(w.substr(0, w.size() - 1))) {
            built.insert(w);
            if (w.size() > ans.size())
                ans = w;
        }
    }
    return ans;
}

int main() {
    vector<string> words = {"w","wo","wor","worl","world"};
    cout << longestWord(words); // Output: world
    return 0;
}
