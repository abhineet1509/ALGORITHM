#include <iostream>
#include <vector>
using namespace std;

void generateSubsequences(string s, int index, string current, vector<string> &result) {
    if (index == s.size()) {
        result.push_back(current);
        return;
    }
    // Include current character
    generateSubsequences(s, index + 1, current + s[index], result);
    // Exclude current character
    generateSubsequences(s, index + 1, current, result);
}

int main() {
    string s = "abc";
    vector<string> subsequences;
    generateSubsequences(s, 0, "", subsequences);

    cout << "Subsequences:" << endl;
    for (auto sub : subsequences) {
        cout << "\"" << sub << "\" ";
    }
    cout << endl;
    return 0;
}
