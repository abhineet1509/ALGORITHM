#include <iostream>
using namespace std;

string reverseString(string str) {
    if (str.empty()) return "";  // base case
    return reverseString(str.substr(1)) + str[0];
}

int main() {
    string s = "hello";
    string reversed = reverseString(s);
    cout << "Reversed string: " << reversed << endl;
    return 0;
}
