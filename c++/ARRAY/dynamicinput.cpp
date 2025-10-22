#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v;
    cout << "1: stop on non-num | 2: stop at -1 | 3: one-line\nChoice: ";
    int c; cin >> c;

    if (c == 1) {
        int x; cout << "Enter numbers (non-num to stop): ";
        while (cin >> x) v.push_back(x);
    } 
    else if (c == 2) {
        int x; cout << "Enter numbers (-1 to stop): ";
        while (cin >> x && x != -1) v.push_back(x);
    } 
    else if (c == 3) {
        cin.ignore();
        cout << "Enter numbers in one line: ";
        string s; getline(cin, s);
        stringstream ss(s); int x;
        while (ss >> x) v.push_back(x);
    }

    cout << "\nData: ";
    for (int i : v) cout << i << " ";
    cout << "\nCount: " << v.size() << endl;
}
