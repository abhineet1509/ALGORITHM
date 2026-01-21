#include <bits/stdc++.h>
using namespace std;

bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    stack<int> st;
    int j = 0;

    for (int i = 0; i < pushed.size(); i++) {
        st.push(pushed[i]);

        while (!st.empty() && j < popped.size() && st.top() == popped[j]) {
            st.pop();
            j++;
        }
    }
    return st.empty();
}

int main() {
    vector<int> pushed = {1,2,3,4,5};
    vector<int> popped = {4,5,3,2,1};

    cout << validateStackSequences(pushed, popped); // Output: 1 (true)
    return 0;
}
