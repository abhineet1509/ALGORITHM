#include <bits/stdc++.h>
using namespace std;

// 1️⃣ Find frequency of each character
void charFrequency(const string &s) {
    unordered_map<char, int> freq;
    for (char c : s) freq[c]++;
    cout << "\nCharacter frequencies:\n";
    for (auto p : freq)
        cout << p.first << " → " << p.second << "\n";
}

// 2️⃣ Remove duplicates
string removeDuplicates(const string &s) {
    string res = "";
    unordered_set<char> seen;
    for (char c : s)
        if (!seen.count(c)) {
            res += c;
            seen.insert(c);
        }
    return res;
}

// 3️⃣ Check if one string is rotation of another
bool isRotation(const string &s1, const string &s2) {
    if (s1.size() != s2.size()) return false;
    string temp = s1 + s1;
    return temp.find(s2) != string::npos;
}

// 4️⃣ Find first non-repeating character
char firstNonRepeating(const string &s) {
    unordered_map<char, int> freq;
    for (char c : s) freq[c]++;
    for (char c : s)
        if (freq[c] == 1)
            return c;
    return '\0';
}

// 🔹 Menu
int main() {
    int choice;
    string s, s1, s2;

    cout << "\n=== STRING OPERATIONS MENU ===\n";
    cout << "1. Find frequency of characters\n";
    cout << "2. Remove duplicates\n";
    cout << "3. Check if one string is rotation of another\n";
    cout << "4. Find first non-repeating character\n";
    cout << "Enter your choice: ";
    cin >> choice;
    cin.ignore(); // for getline safety

    switch (choice) {
        case 1:
            cout << "Enter string: ";
            getline(cin, s);
            charFrequency(s);
            break;

        case 2:
            cout << "Enter string: ";
            cin >> s;
            cout << "Without duplicates: " << removeDuplicates(s) << "\n";
            break;

        case 3:
            cout << "Enter first string: ";
            cin >> s1;
            cout << "Enter second string: ";
            cin >> s2;
            cout << (isRotation(s1, s2) ? "Rotation" : "Not rotation") << "\n";
            break;

        case 4:
            cout << "Enter string: ";
            cin >> s;
            {
                char ans = firstNonRepeating(s);
                if (ans == '\0') cout << "No non-repeating character\n";
                else cout << "First non-repeating character: " << ans << "\n";
            }
            break;

        default:
            cout << "Invalid choice!\n";
    }

    return 0;
}
