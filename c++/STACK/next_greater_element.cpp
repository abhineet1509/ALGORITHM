#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextgreaterElement(const vector<int>& arr) {
    int n = arr.size();
    vector<int> ans(n, -1);
    stack<int> s;
    for (int i = 0; i < n; i++) {
        while (!s.empty() && arr[s.top()] < arr[i]) {
            ans[s.top()] = arr[i];
            s.pop();
        }
        s.push(i);
    }
    return ans;
}

int main() {
    int n, data;
    cout << "Enter the number of elements in the stack: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> ans = nextgreaterElement(arr);

    cout << "Next greater elements: ";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    return 0;
}

