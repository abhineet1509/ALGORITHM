#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> ans;
    vector<string> mp = {
        "", "", "abc", "def", "ghi", 
        "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    void backtrack(int idx, string &digits, string &curr) {
        if (idx == digits.size()) {
            ans.push_back(curr);
            return;
        }

        string letters = mp[digits[idx] - '0'];

        for (char ch : letters) {
            curr.push_back(ch);
            backtrack(idx + 1, digits, curr);
            curr.pop_back();        // backtrack
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        string curr = "";
        backtrack(0, digits, curr);
        return ans;
    }
};

int main() {
    Solution obj;
    string digits;
    cout << "Enter digits (2-9): ";
    cin >> digits;

    vector<string> result = obj.letterCombinations(digits);

    cout << "\nLetter combinations:\n";
    for (string &s : result) cout << s << " ";
    cout << endl;

    return 0;
}
