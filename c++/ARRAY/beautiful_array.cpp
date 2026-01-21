#include <bits/stdc++.h>
using namespace std;

/* ---------- 932 : Beautiful Array ---------- */
vector<int> beautifulArray(int n) {
    vector<int> res = {1};

    while (res.size() < n) {
        vector<int> temp;
        for (int x : res)
            if (2 * x - 1 <= n)
                temp.push_back(2 * x - 1);

        for (int x : res)
            if (2 * x <= n)
                temp.push_back(2 * x);

        res = temp;
    }
    return res;
}

/* ---------- 667 : Beautiful Arrangement II ---------- */
vector<int> constructArray(int n, int k) {
    vector<int> res;
    int low = 1, high = n;

    while (low <= high) {
        if (k > 0) {
            res.push_back((k % 2 == 1) ? low++ : high--);
            k--;
        } else {
            res.push_back(low++);
        }
    }
    return res;
}

/* ---------- Main ---------- */
int main() {
    // 932
    int n1 = 5;
    vector<int> arr1 = beautifulArray(n1);
    cout << "Beautiful Array (932): ";
    for (int x : arr1) cout << x << " ";
    cout << endl;

    // 667
    int n2 = 5, k = 3;
    vector<int> arr2 = constructArray(n2, k);
    cout << "Beautiful Arrangement II (667): ";
    for (int x : arr2) cout << x << " ";
    cout << endl;

    return 0;
}
