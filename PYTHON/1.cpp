#include <bits/stdc++.h>
using namespace std;

int minPatches(const vector<long long>& A, long long B) {
    long long miss = 1;    // smallest sum we cannot form
    int patches = 0;
    size_t i = 0, n = A.size();

    while (miss <= B) {
        if (i < n && A[i] <= miss) {
            miss += A[i++];
        } else {
            miss += miss;
            patches++;
        }
    }
    return patches;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Read the sorted array A from the first line
    string line;
    if (!getline(cin, line)) return 0;
    istringstream iss(line);
    vector<long long> A;
    long long x;
    while (iss >> x) {
        A.push_back(x);
    }

    // Then read B
    long long B;
    if (!(cin >> B)) return 0;

    cout << minPatches(A, B) << "\n";
    return 0;
}
