#include <iostream>
#include <string>
#include <algorithm> // for reverse, sort
using namespace std;

int main() {
    string s = "hello world";

    // Length of string
    int len = s.length();      // or s.size()

    // Check if string is empty
    bool isEmpty = s.empty();

    // Access characters
    char ch = s[2];            // 'l'
    char first = s.front();    // 'h'
    char last = s.back();      // 'd'

    // Substring
    string sub = s.substr(0, 5);       // "hello"

    // Find substring
    int pos = s.find("world");         // returns 6
    int rpos = s.rfind("l");           // rightmost 'l'

    // Append and Concatenate
    s.append("!!!");                   // "hello world!!!"
    s += " test";                      // "hello world!!! test"

    // Insert and Erase
    s.insert(5, "___");                // "hello___ world!!! test"
    s.erase(5, 3);                     // "hello world!!! test"

    // Replace
    s.replace(6, 5, "there");          // replaces "world" with "there"

    // Reverse and Sort
    reverse(s.begin(), s.end());       // reverse the string
    sort(s.begin(), s.end());          // sort characters

    // Case Conversion
    char lower = tolower('A');         // 'a'
    char upper = toupper('b');         // 'B'

    // String to Int and vice versa
    int num = stoi("123");             // 123
    string numStr = to_string(456);    // "456"

    // Read input including spaces
    string input;
    getline(cin, input);               // reads full line with spaces

    return 0;
}
