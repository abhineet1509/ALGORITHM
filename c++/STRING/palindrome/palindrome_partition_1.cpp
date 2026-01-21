#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {     // tc O(2^n*n), sc O(n^2)
                    // where n is the length of the string
public:
    vector<vector<string>> result;

    bool isPalindrome(string& s, int left, int right) {
        while (left < right) {
            if (s[left++] != s[right--]) return false;
        }
        return true;
    }

    void backtrack(string& s, int start, vector<string>& path) {
        if (start == s.size()) {
            result.push_back(path);
            return;
        }

        for (int end = start; end < s.size(); ++end) {
            if (isPalindrome(s, start, end)) {
                path.push_back(s.substr(start, end - start + 1));
                backtrack(s, end + 1, path);
                path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> path;
        backtrack(s, 0, path);
        return result;
    }
};

// Example usage
int main() {
    Solution sol;
    string s = "aaab";
    vector<vector<string>> partitions = sol.partition(s);
    
    for (auto& part : partitions) {
        for (auto& str : part) cout << str << " ";
        cout << endl;
    }

    return 0;
}
