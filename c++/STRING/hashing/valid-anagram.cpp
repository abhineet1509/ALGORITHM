#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool areAnagrams(const string& s1, const string& s2) {
    if (s1.length() != s2.length()) return false;

    string a = s1, b = s2;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    return a == b;
}

int main() {
    string s1 = "listen", s2 = "silent";
    cout << (areAnagrams(s1, s2) ? "Anagrams" : "Not Anagrams") << endl;
}