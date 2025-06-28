#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextGreaterRight(vector<int>& arr) {
    int n = arr.size();
    vector<int> res(n);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && st.top() <= arr[i]) {
            st.pop();
        }

        res[i] = st.empty() ? -1 : st.top();
        st.push(arr[i]);
    }

    return res;
}

int main() {
    vector<int> arr = {4, 5, 2, 10, 8};
    vector<int> result = nextGreaterRight(arr);

    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
