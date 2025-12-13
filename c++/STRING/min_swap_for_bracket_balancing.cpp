#include <bits/stdc++.h>
using namespace std;

int minimumSwaps(string s) {
    vector<int> pos;
    for (int i = 0; i < s.size(); i++)
        if (s[i] == '[') pos.push_back(i);

    int p = 0;           // pointer to next '['
    int count = 0;       // imbalance count
    long long swaps = 0; // total swaps

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '[') {
            count++; 
            p++;
        }
        else {
            count--;
            if (count < 0) {           // imbalance found
                swaps += pos[p] - i;   // distance to swap
                swap(s[i], s[pos[p]]);
                p++;
                count = 1;
            }
        }
    }
    return swaps;
}

int main() {
    string s = "[]][][";
    cout << minimumSwaps(s);
    return 0;
}
