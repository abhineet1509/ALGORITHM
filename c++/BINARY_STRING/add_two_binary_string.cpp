#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string addBinary(string a, string b) {
    string res;
    int carry = 0, i = a.size() - 1, j = b.size() - 1;

    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';
        carry = sum / 2;
        res.push_back((sum % 2) + '0');
    }

    reverse(res.begin(), res.end());
    return res;
}

int main() {
    cout << addBinary("11", "1");  // Output: 100
}
