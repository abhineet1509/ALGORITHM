#include <bits/stdc++.h>
using namespace std;

string countAndSay(int n) {
    if (n == 1) return "1";
    string s = "1";
    for (int i = 2; i <= n; i++) {
        string temp = "";
        int count = 1;
        for (int j = 1; j < s.size(); j++) {
            if (s[j] == s[j - 1]) count++;
            else {
                temp += to_string(count) + s[j - 1];
                count = 1;
            }
        }
        temp += to_string(count) + s.back(); // add last group
        s = temp;
    }
    return s;
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    cout << "Count and Say sequence term: " << countAndSay(n) << endl;
}
