#include <bits/stdc++.h>
using namespace std;

string smallestPalindrome(string s) {
    int n = s.size();
    vector<int> count(26, 0);

    for (char c : s)
        count[c - 'a']++;

    int oddCount = 0;
    char middle = 0;

    for (int i = 0; i < 26; i++) {
        if (count[i] % 2 != 0) {
            oddCount++;
            middle = 'a' + i;
        }
    }

    // More than one odd character → not possible
    if (oddCount > 1)
        return "Not Possible";

    string half = "";
    for (int i = 0; i < 26; i++) {
        half += string(count[i] / 2, 'a' + i);
    }

    string revHalf = half;
    reverse(revHalf.begin(), revHalf.end());

    return oddCount == 1 ? half + middle + revHalf : half + revHalf;
}
