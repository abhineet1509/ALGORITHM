#include<iostream> 
#include<vector>
using namespace std;


int minKBitFlips(vector<int>& A, int K) {
    int n = A.size();
    int flip = 0;         // current flip parity (0 or 1)
    int ans = 0;

    vector<int> isFlipped(n, 0);

    for (int i = 0; i < n; i++) {
        if (i >= K) flip ^= isFlipped[i - K];

        if (A[i] == flip) {
            if (i + K > n) return -1;

            isFlipped[i] = 1;
            flip ^= 1;
            ans++;
        }
    }

    return ans;
}
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {
        int n = A.size();
        int ans = 0;
        queue<int> flipIndices; // stores indices where flips start

        for (int i = 0; i < n; i++) {
            // Remove expired flips (older than i - K + 1)
            if (!flipIndices.empty() && flipIndices.front() + K <= i) {
                flipIndices.pop();
            }

            // Count of active flips affecting index i = size of queue % 2
            int currentBit = A[i];
            if (flipIndices.size() % 2 == 1) {
                currentBit ^= 1; // flip logically
            }

            if (currentBit == 0) {
                if (i + K > n) return -1; // can't flip out of bounds
                flipIndices.push(i); // new flip starts
                ans++;
            }
        }

        return ans;
    }
};

int main(){
    vector<int> A = {0, 1, 0};
    int K = 1;
    int result = minKBitFlips(A, K);
    cout << "Minimum number of flips: " << result << endl; // Output: 2
    return 0;
}