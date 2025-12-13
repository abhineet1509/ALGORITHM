#include <bits/stdc++.h>
using namespace std;

string nextPalindrome(string num) {
    int n = num.size();
    string res = num;
    int mid = n / 2;
    int i = mid - 1;
    int j = (n % 2 == 0) ? mid : mid + 1;

    // Mirror left to right
    while (i >= 0) {
        res[j++] = res[i--];
    }

    // If mirrored number > original, return
    if (res > num) return res;

    // Otherwise, increment the middle and handle carry
    i = mid - 1;
    j = (n % 2 == 0) ? mid : mid + 1;

    int carry = 1;
    if (n % 2 == 1) {
        int val = (res[mid] - '0') + carry;
        carry = val / 10;
        res[mid] = (val % 10) + '0';
    }

    while (i >= 0) {
        int val = (res[i] - '0') + carry;
        carry = val / 10;
        res[i] = (val % 10) + '0';
        res[j++] = res[i--];
    }

    if (carry) {
        res = "1" + string(n - 1, '0') + "1";
    }

    return res;
}

int main() {
    vector<string> tests = {"23545", "999", "1234", "808", "2133"};

    for (auto s : tests) {
        cout << "Next palindrome after " << s << " is " << nextPalindrome(s) << endl;
    }

    return 0;
}
