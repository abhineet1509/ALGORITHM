#include<iostream> 
#include<vector>
using namespace std;

int countAnagrams(string text, string pattern) {
    int n = text.length();
    int k = pattern.length();
    int count = 0;

    vector<int> freq_pat(26, 0);
    vector<int> freq_win(26, 0);

    // Build frequency of pattern
    for (char ch : pattern)
        freq_pat[ch - 'a']++;

    for (int i = 0; i < n; i++) {
        // Add current char to window
        freq_win[text[i] - 'a']++;

        // Remove leftmost char when window exceeds size k
        if (i >= k)
            freq_win[text[i - k] - 'a']--;

        // Compare frequency arrays
        if (i >= k - 1 && freq_win == freq_pat)
            count++;   // result.push_back(s.substr(i - k + 1, k)); word
                       // res.push_back(i - k + 1);  starting index of current window
    }

    return count;
}
int main(){
    string s,p;
    cin >> s>>p;
    cout<<countAnagrams(s,p)<<endl;


}