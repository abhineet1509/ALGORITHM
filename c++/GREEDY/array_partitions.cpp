#include <bits/stdc++.h>
using namespace std;
 // sum of minimum of ai ,bi
int arrayPairSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int sum = 0;
    for (int i = 0; i < nums.size(); i += 2) {
        sum += nums[i];
    }
    return sum;
}

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
