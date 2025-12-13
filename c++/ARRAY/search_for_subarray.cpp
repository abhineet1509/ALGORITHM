#include <bits/stdc++.h>
using namespace std;

vector<int> searchSubarray(vector<int>& a, vector<int>& b) {
    vector<int> res;
    int n = a.size(), m = b.size();
    if (m > n) return res;

    for (int i = 0; i <= n - m; i++) {
        bool match = true;
        for (int j = 0; j < m; j++) {
            if (a[i + j] != b[j]) {
                match = false;
                break;
            }
        }
        if (match) res.push_back(i);
    }
    return res;
}

int main() {
    vector<int> a = {2, 4, 1, 0, 4, 1, 1};
    vector<int> b = {4, 1};

    vector<int> ans = searchSubarray(a, b);

    if (ans.empty()) cout << "[]";
    else {
        cout << "[";
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i];
            if (i != ans.size() - 1) cout << ", ";
        }
        cout << "]";
    }
}
