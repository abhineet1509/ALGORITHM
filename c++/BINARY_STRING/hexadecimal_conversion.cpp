#include <bits/stdc++.h>
using namespace std;

int binToDec(string bin) {
    int dec = 0, power = 1;
    int i = bin.size() - 1;
    while (i >= 0) {
        if (bin[i] == '1') dec += power;
        power *= 2;
        i--;
    }
    return dec;
}

string decToHex(int dec) {
    if (dec == 0) return "0";
    string hexDigits = "0123456789ABCDEF", hex = "";
    while (dec > 0) {
        hex = hexDigits[dec % 16] + hex;
        dec /= 16;
    }
    return hex;
}

int hexToDec(string hex) {
    int dec = 0, power = 1;
    int i = hex.size() - 1;
    while (i >= 0) {
        char c = toupper(hex[i]);
        int val = (isdigit(c)) ? c - '0' : c - 'A' + 10;
        dec += val * power;
        power *= 16;
        i--;
    }
    return dec;
}

string decToBin(int dec) {
    if (dec == 0) return "0";
    string bin = "";
    while (dec > 0) {
        bin = char('0' + (dec % 2)) + bin;
        dec /= 2;
    }
    return bin;
}

int main() {
    int choice;
    cout << "1. Binary to Hexadecimal\n2. Hexadecimal to Binary\nChoice: ";
    cin >> choice;

    if (choice == 1) {
        string bin;
        cout << "Enter Binary: ";
        cin >> bin;
        int dec = binToDec(bin);
        cout << "Hexadecimal: " << decToHex(dec) << "\n";
    } 
    else if (choice == 2) {
        string hex;
        cout << "Enter Hexadecimal: ";
        cin >> hex;
        int dec = hexToDec(hex);
        cout << "Binary: " << decToBin(dec) << "\n";
    } 
    else {
        cout << "Invalid choice\n";
    }
}
