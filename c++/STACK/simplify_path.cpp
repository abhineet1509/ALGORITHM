#include <bits/stdc++.h>
using namespace std;

string simplifyPath(string path) {
    vector<string> st;
    string cur = "";

    for (int i = 0; i <= path.size(); i++) {
        if (i == path.size() || path[i] == '/') {
            if (cur == "..") {
                if (!st.empty())
                    st.pop_back();
            } else if (!cur.empty() && cur != ".") {
                st.push_back(cur);
            }
            cur = "";
        } else {
            cur.push_back(path[i]);
        }
    }

    if (st.empty()) return "/";

    string res = "";
    for (int i = 0; i < st.size(); i++) {
        res += "/" + st[i];
    }
    return res;
}

int main() {
    string path;
    cout << "Enter path: ";
    cin >> path;

    cout << "Simplified path: " << simplifyPath(path) << endl;

    return 0;
}

