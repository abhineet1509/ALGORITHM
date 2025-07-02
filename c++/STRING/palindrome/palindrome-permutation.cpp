#include <iostream>
#include <unordered_map>
using namespace std;

bool canFormPalindrome(string s) {
    unordered_map<char, int> freq;

    // Count frequency of each character
    for (char c : s) {
        freq[c]++;
    }

    int oddCount = 0;
    for (auto it : freq) {
        if (it.second % 2 != 0)
            oddCount++;
    }

    // At most one odd frequency allowed
    return oddCount <= 1;
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;

    if (canFormPalindrome(s))
        cout << "Yes, a palindrome permutation is possible.\n";
    else
        cout << "No, palindrome permutation not possible.\n";

    return 0;
}
