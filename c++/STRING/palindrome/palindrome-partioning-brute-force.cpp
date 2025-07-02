#include <iostream>
#include <string>
#include <climits>
using namespace std;                   // t.c O(2^n*n)

// Check if s[i..j] is a palindrome
bool isPalindrome(const string &s, int i, int j) {
    while (i < j) {
        if (s[i] != s[j]) return false;
        i++;
        j--;
    }
    return true;
}

// Brute force function to find minimum cuts
int minCuts(string s, int start) {
    if (start == s.length()) return 0; // No cut needed if string is empty

    int minCut = INT_MAX;

    for (int end = start; end < s.length(); end++) {
        if (isPalindrome(s, start, end)) {
            int cuts = 1 + minCuts(s, end + 1);
            minCut = min(minCut, cuts);
        }
    }

    return minCut;
}

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;

    // One less cut than total parts
    int result = minCuts(s, 0) - 1;
    cout << "Minimum cuts to partition into palindromes: " << result << endl;

    return 0;
}
