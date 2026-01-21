#include <bits/stdc++.h>
using namespace std;

string decodeAtIndex(string s, int K) {
    long long size = 0;
    int n = s.size();

    for (int i = 0; i < n; i++) {
        if (isdigit(s[i]))
            size *= (s[i] - '0');
        else
            size++;
    }

    for (int i = n - 1; i >= 0; i--) {
        K %= size;

        if (K == 0 && isalpha(s[i]))
            return string(1, s[i]);

        if (isdigit(s[i]))
            size /= (s[i] - '0');
        else
            size--;
    }

    return "";
}

int main() {
    string s;
    int K;

    cout << "Enter encoded string: ";
    cin >> s;
    cout << "Enter K: ";
    cin >> K;

    cout << "Character at position " << K << ": " << decodeAtIndex(s, K) << endl;

    return 0;
}
