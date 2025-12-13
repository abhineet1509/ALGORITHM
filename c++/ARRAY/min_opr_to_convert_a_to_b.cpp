#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minInsAndDel(int A[], int B[], int N, int M) {

        // Step 1: Map elements of B to their index (B is sorted & distinct)
        unordered_map<int, int> pos;
        for (int i = 0; i < M; i++)
            pos[B[i]] = i;

        // Step 2: Build mapped sequence from A (only if element exists in B)
        vector<int> seq;
        for (int i = 0; i < N; i++) {
            if (pos.count(A[i])) 
                seq.push_back(pos[A[i]]);
        }

        // Step 3: Find LIS on seq
        vector<int> lis;
        for (int x : seq) {
            auto it = lower_bound(lis.begin(), lis.end(), x);
            if (it == lis.end())
                lis.push_back(x);
            else
                *it = x;
        }

        int L = lis.size();

        // Step 4: Total operations = deletions + insertions
        return (N - L) + (M - L);
    }
};

int main() {
    int N, M;
    cin >> N >> M;

    int A[N], B[M];
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < M; i++) cin >> B[i];

    Solution ob;
    cout << ob.minInsAndDel(A, B, N, M) << endl;

    return 0;
}
