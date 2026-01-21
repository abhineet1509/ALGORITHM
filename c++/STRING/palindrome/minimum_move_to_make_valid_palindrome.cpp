#include <bits/stdc++.h>
using namespace std;


// ---------------- Minimum Moves to Make Palindrome ----------------
// palindrome permutation
bool canFormPalindrome(string s) {
    unordered_map<char, int> freq;
    for (char c : s) freq[c]++;
    int odd = 0;
    for (auto &p : freq) {
        if (p.second % 2) odd++;
        if (odd > 1) return false;
    }
    return true;
}

int minMovesToPalindrome(string s) {
    if (!canFormPalindrome(s)) return -1;

    int moves = 0;
    int n = s.size();
    int left = 0, right = n - 1;

    while (left < right) {
        if (s[left] == s[right]) {
            left++;
            right--;
        } else {
            int r = right;
            while (r > left && s[r] != s[left]) r--;
            if (r == left) { // Unique middle character
                swap(s[left], s[left + 1]);
                moves++;
            } else {
                while (r < right) {
                    swap(s[r], s[r + 1]);
                    moves++;
                    r++;
                }
                left++;
                right--;
            }
        }
    }

    return moves;
}

int main() {
    vector<string> testStrings = {"abca", "mamad", "race", "aabb"};

    for (string s : testStrings) {
        
        int moves = minMovesToPalindrome(s);
        if (moves == -1)
            cout << "Cannot form a palindrome by moves." << endl;
        else
            cout << "Minimum moves to make palindrome: " << moves << endl;

    }

    return 0;
}
