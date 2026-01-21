#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /* ---------- 1️⃣ Hamming Distance (Normal XOR + Shift) ---------- */
    int hammingDistanceNormal(int x, int y) {
        int val = x ^ y;
        int count = 0;

        while (val) {
            if (val & 1)
                count++;
            val /= 2;
        }
        return count;
    }

    /* ---------- 2️⃣ Hamming Distance (Brian Kernighan - Optimized) ---------- */
    int hammingDistanceOptimized(int x, int y) {
        int val = x ^ y;
        int count = 0;

        while (val) {
            val &= (val - 1); // removes lowest set bit
            count++;
        }
        return count;
    }

    /* ---------- 3️⃣ Total Hamming Distance (Normal / Brute Force) ---------- */
    int totalHammingDistanceNormal(vector<int>& nums) {
        int n = nums.size();
        int total = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                total += hammingDistanceOptimized(nums[i], nums[j]);
            }
        }
        return total;
    }

    /* ---------- 4️⃣ Total Hamming Distance (Optimized Bit Count) ---------- */
    int totalHammingDistanceOptimized(vector<int>& nums) {
        int n = nums.size();
        int total = 0;

        for (int bit = 0; bit < 32; bit++) {
            int ones = 0;

            for (int i = 0; i < n; i++) {
                if ((nums[i] >> bit) & 1)
                    ones++;
            }

            int zeros = n - ones;
            total += ones * zeros;
        }
        return total;
    }
};

int main() {
    Solution sol;

    int x = 1, y = 4;
    cout << "Hamming Distance (Normal): "
         << sol.hammingDistanceNormal(x, y) << endl;

    cout << "Hamming Distance (Optimized): "
         << sol.hammingDistanceOptimized(x, y) << endl;

    vector<int> nums = {4, 14, 2};

    cout << "Total Hamming Distance (Normal): "
         << sol.totalHammingDistanceNormal(nums) << endl;

    cout << "Total Hamming Distance (Optimized): "
         << sol.totalHammingDistanceOptimized(nums) << endl;

    return 0;
}
