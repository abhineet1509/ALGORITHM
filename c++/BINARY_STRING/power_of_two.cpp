#include <bits/stdc++.h>
using namespace std;

bool isPow2_and(long long n) {
    return (n > 0) && ((n & (n - 1)) == 0);
}

bool isPow2_logFC(long long n) {
    return n > 0 && floor(log2(n)) == ceil(log2(n));
}

bool isPow2_div(long long n) {
    if (n <= 0) return false;
    while (n % 2 == 0) n /= 2;
    return n == 1;
}

bool isPow4_rec(int n) {
    if (n == 1) return true;
    if (n <= 0 || n % 4 != 0) return false;
    return isPow4_rec(n / 4);
}

bool isPow4_log(int n) {
    if (n <= 0) return false;
    double logRes = log2(n);
    return floor(logRes) == ceil(logRes) && ((int)logRes % 2 == 0);
}

bool isPow4_div(int n) {
    if (n <= 0) return false;
    while (n % 4 == 0) n /= 4;
    return n == 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    while (cin >> n) {
        cout << n << ":\n";
        cout << "  AND trick        : " << (isPow2_and(n) ? "YES" : "NO") << '\n';
        cout << "  log2 floor/ceil  : " << (isPow2_logFC(n) ? "YES" : "NO") << '\n';
        cout << "  divide-by-2 loop : " << (isPow2_div(n) ? "YES" : "NO") << '\n';
    }
}
