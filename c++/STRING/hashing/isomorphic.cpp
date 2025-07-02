#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

bool areIsomorphic(const string& s, const string& t) {
    if (s.length() != t.length()) return false;

    unordered_map<char, char> map1, map2;

    for (int i = 0; i < s.length(); ++i) {
        char c1 = s[i], c2 = t[i];

        // Check if mapping already exists and is consistent
        if ((map1.find(c1) != map1.end() && map1[c1] != c2) ||
            (map2.find(c2) != map2.end() && map2[c2] != c1)) {
            return false;
        }

        // Establish the mapping
        map1[c1] = c2;
        map2[c2] = c1;
    }

    return true;
}

int main() {
    string s = "paper", t = "title";
    cout << (areIsomorphic(s, t) ? "Isomorphic" : "Not Isomorphic") << endl;
}
