#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = 0;
        int i = s.size() - 1;

        // Skip trailing spaces
        while (i >= 0 && s[i] == ' ') i--;

        // Count characters of the last word
        while (i >= 0 && s[i] != ' ') {
            length++;
            i--;
        }

        return length;
    }
};

int main() {
    Solution solution;
    string input = "Hello World";
    cout << "Length of last word: " << solution.lengthOfLastWord(input) << endl;

    input = "   fly me   to   the moon  ";
    cout << "Length of last word: " << solution.lengthOfLastWord(input) << endl;

    input = "luffy is still joyboy";
    cout << "Length of last word: " << solution.lengthOfLastWord(input) << endl;

    return 0;
}