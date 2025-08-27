#include <bits/stdc++.h>
using namespace std;

void bitsetMethod(int n) {
    string bin = bitset<32>(n).to_string();
    bin.erase(0, bin.find('1')); // remove leading zeros
    cout << (bin.empty() ? "0" : bin) << "\n";
}

void manualMethod(int n) {
    vector<int> v;
    while (n > 0) {
        v.push_back(n % 2); // s+=n%2 + '0';
        n /= 2;
    }
    if (v.empty()) v.push_back(0);
    reverse(v.begin(), v.end());
    for (int x : v) cout << x;
    cout << "\n";
}

void lsbMethod(int n) {
    vector<int> v;
    while (n > 0) {
        v.push_back(n & 1);
        n >>= 1;
    }
    if (v.empty()) v.push_back(0);
    reverse(v.begin(), v.end());
    for (int x : v) cout << x;
    cout << "\n";
}

int decimalToBinary(int n) {
    int ans = 0, p = 1;
    while (n > 0) {
        int last_bit = (n & 1);
        ans += p * last_bit;
        p *= 10;
        n >>= 1;
    }
    return ans;
}

int main() {
    int n, choice;
    cout << "Enter number: ";
    cin >> n;
    cout << "Choose method:\n1. Bitset\n2. Manual Division\n3. Bitmask\n> ";
    cin >> choice;

    if (choice == 1) bitsetMethod(n);
    else if (choice == 2) manualMethod(n);
    else if (choice == 3) lsbMethod(n);
    else if (choice == 4 ) decimalToBinary(n);
    else cout << "Invalid choice\n";

}
