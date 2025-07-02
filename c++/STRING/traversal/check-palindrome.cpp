#include<bits/stdc++.h>
using namespace std;
bool checkpalindrome(string str) {
    int n = str.length();
    for (int i = 0; i < n / 2; i++) {
        if (str[i] != str[n - i - 1]) {
            return false; // Not a palindrome
        }
    }
    return true; // Is a palindrome
}
int main (){
    string str;
    cin >> str;
    if(checkpalindrome(str)) cout << "Yes, it is a palindrome." << endl;
    else cout << "No, it is not a palindrome." << endl;
}