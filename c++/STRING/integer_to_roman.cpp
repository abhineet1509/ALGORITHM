#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

// ----------------------------
// Roman to Integer
// ----------------------------
int romanToInt(string s) {
    unordered_map<char, int> mp = {
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
        {'C', 100}, {'D', 500}, {'M', 1000}
    };

    int sum = 0;

    for (int i = 0; i < s.length(); i++) {
        if (i + 1 < s.length() && mp[s[i]] < mp[s[i + 1]]) {
            sum -= mp[s[i]];           // subtractive case
        } 
        else {
            sum += mp[s[i]];
        }
    }

    return sum;
}

// ----------------------------
// Integer to Roman
// ----------------------------
string intToRoman(int n) {
    string res = "";
    vector<pair<int, string>> ans = {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
        {100, "C"},  {90, "XC"},  {50, "L"},  {40, "XL"},
        {10, "X"},   {9, "IX"},   {5, "V"},   {4, "IV"}, {1, "I"}
    };

    for (int i = 0; i < ans.size(); i++) {
        while (n >= ans[i].first) {
            res += ans[i].second;
            n -= ans[i].first;
        }
    }
    return res;
}

// ----------------------------
// MAIN PROGRAM
// ----------------------------
int main() {
    cout << "1. Convert Roman to Integer\n";
    cout << "2. Convert Integer to Roman\n";
    cout << "Choose option: ";
    int choice;
    cin >> choice;

    if (choice == 1) {
        string s;
        cout << "Enter Roman numeral: ";
        cin >> s;
        cout << "Integer value: " << romanToInt(s) << endl;
    } 
    else if (choice == 2) {
        int n;
        cout << "Enter Integer: ";
        cin >> n;
        cout << "Roman numeral: " << intToRoman(n) << endl;
    } 
    else {
        cout << "Invalid choice!";
    }

    return 0;
}
