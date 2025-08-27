#include <bits/stdc++.h>
using namespace std;

// Method 1: Using stoi with base 2
int method_stoi(string bin) {
    return stoi(bin, 0, 2);
}

// Method 2: Manual power-of-2 multiplication
int method_powerMultiply(string bin) {
    int dec = 0, power = 1;
    int i = bin.size() - 1;
    while (i >= 0) {
        if (bin[i] == '1') dec += power;
        power *= 2;
        i--;
    }
    return dec;
}

// Method 3: Bitwise shift method
int method_bitwise(string bin) {
    int dec_num = 0, power = 0;
    int i = bin.size() - 1;
    while (i >= 0) {
        if (bin[i] == '1') {
            dec_num += (1 << power); // add 2^power
        }
        power++;
        i--;
    }
    return dec_num;
}

int main() {
    string bin;
    cout << "Enter binary number: ";
    cin >> bin;

    cout << "Method 1 (stoi):            " << method_stoi(bin) << endl;
    cout << "Method 2 (power multiply):  " << method_powerMultiply(bin) << endl;
    cout << "Method 3 (bitwise shift):   " << method_bitwise(bin) << endl;

    return 0;
}
