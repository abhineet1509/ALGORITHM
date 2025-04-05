#include <iostream>
#include <vector>
using namespace std;

void subsequence(string str, string curr, int index, vector<string> &result) {
    if (index == str.length()) {
        result.push_back(curr);
        return;
    }
    subsequence(str, curr, index + 1, result);
    subsequence(str, curr + str[index], index + 1, result);
}
int main() {
    string str;
    cin>>str;
    vector<string> result;
    subsequence(str, "", 0, result);
    cout << "All Subsequences of " << str<<"are:";
    for (string subseq : result) {
        cout << subseq << " ";
    }
    return 0;
}