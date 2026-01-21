#include <bits/stdc++.h>
using namespace std;

bool validUtf8(vector<int>& data) {
    int remainingBytes = 0;
    
    for (int byte : data) {
        if (remainingBytes == 0) {
            if ((byte >> 5) == 0b110) remainingBytes = 1;       // 2-byte char
            else if ((byte >> 4) == 0b1110) remainingBytes = 2; // 3-byte char
            else if ((byte >> 3) == 0b11110) remainingBytes = 3; // 4-byte char
            else if ((byte >> 7) != 0) return false;            // 1-byte char must start with 0
        } else {
            if ((byte >> 6) != 0b10) return false; // continuation byte must start with 10
            remainingBytes--;
        }
    }
    
    return remainingBytes == 0;
}

int main() {
    vector<int> data1 = {197, 130, 1};      // valid
    vector<int> data2 = {235, 140, 4};      // invalid
    
    cout << (validUtf8(data1) ? "true" : "false") << endl; // true
    cout << (validUtf8(data2) ? "true" : "false") << endl; // false
    
    return 0;
}
