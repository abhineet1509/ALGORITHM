#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeOccurrences(string s, string part) {
        // Repeat until 'part' is not found in 's'
        while (s.find(part) != string::npos) {
            s.erase(s.find(part), part.length());
        }
        return s;
    }
};

int main() {
    Solution obj;

    string s = "daabcbaabcbc";
    string part = "abc";

    cout << obj.removeOccurrences(s, part);
    return 0;
}
