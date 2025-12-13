#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string partitionArray(int N, int K, int M, vector<int> &A) {
        sort(A.begin(), A.end());
        
        int i = 0;
        while (i < N) {
            int j = i;

            // Expand the current partition while max-min <= M
            while (j < N && A[j] - A[i] <= M) {
                j++;
            }

            int size = j - i;
            if (size < K) return "NO";  // Partition does not have enough elements

            i = j; // Move to next partition
        }

        return "YES";
    }
};

int main() {
    int N, K, M;
    cin >> N >> K >> M;

    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    Solution ob;
    cout << ob.partitionArray(N, K, M, A) << endl;

    return 0;
}
