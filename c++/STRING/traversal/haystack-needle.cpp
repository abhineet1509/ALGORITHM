#include <iostream>
#include <string>
using namespace std;
 //O(n*m)
int strStr(string haystack, string needle) {
    int m = haystack.size();
    int n = needle.size();

    if (n == 0) return 0;  // If needle is empty, return 0

    for (int i = 0; i <= m - n; i++) {
        if (haystack.substr(i, n) == needle)
            return i;
    }

    return -1;  // Needle not found
}

int main() {
    string haystack, needle;
    cout << "Enter haystack string: ";
    getline(cin, haystack);
    cout << "Enter needle string: ";
    getline(cin, needle);

    int result = strStr(haystack, needle);
    if (result != -1)
        cout << "Needle found at index: " << result << endl;
    else
        cout << "Needle not found." << endl;

    return 0;
}
