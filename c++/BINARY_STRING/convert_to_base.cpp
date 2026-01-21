#include <bits/stdc++.h>
using namespace std;

// Convert to any positive base
string toBase(int n, int base) {
    if (n == 0) return "0";
    string res = "";
    while (n > 0) {
        res = char(n % base + '0') + res;
        n /= base;
    }
    return res;
}

// Convert to negative base (-2)
string toNegativeBase(int n, int base) {
    if (n == 0) return "0";
    string res = "";
    while (n != 0) {
        int rem = n % base;
        n /= base;
        if (rem < 0) {  // adjust
            rem += (-base);
            n += 1;
        }
        res = char(rem + '0') + res;
    }
    return res;
}

int main() {
    int n;
    cin >> n;

    cout << "Base -2: " << toNegativeBase(n, -2) << endl;
    cout << "Base 3: " << toBase(n, 3) << endl;
    cout << "Base 5: " << toBase(n, 5) << endl;
    cout << "Base 7: " << toBase(n, 7) << endl;

    return 0;
}
