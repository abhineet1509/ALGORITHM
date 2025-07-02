#include <iostream>
using namespace std;

bool isPalindrome(string s, int left, int right) {
    while (left < right) {
        if (s[left] != s[right])
            return false;
        left++;
        right--;
    }
    return true;
}

bool validPalindrome(string s) {
    int left = 0, right = s.size() - 1;

    while (left < right) {
        if (s[left] == s[right]) {
            left++;
            right--;
        } else {
            // Try removing one character
            return isPalindrome(s, left + 1, right) || isPalindrome(s, left, right - 1);
        }
    }
    return true;
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;

    if (validPalindrome(s))
        cout << "Yes, it can be a palindrome by removing at most one character.\n";
    else
        cout << "No, it can't be made into a palindrome.\n";

    return 0;
}
