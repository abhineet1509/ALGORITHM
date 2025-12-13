#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool solve(int idx, int k, int currSum, int target, vector<int>& arr, vector<bool>& used) {
        if (k == 1) return true;
        if (currSum == target)
            return solve(0, k - 1, 0, target, arr, used);

        for (int i = idx; i < arr.size(); i++) {
            if (!used[i] && currSum + arr[i] <= target) {
                used[i] = true;
                if (solve(i + 1, k, currSum + arr[i], target, arr, used))
                    return true;
                used[i] = false;
                if (currSum == 0) return false;
            }
        }
        return false;
    }

    bool isKPartitionPossible(vector<int>& arr, int k) {
        int sum = accumulate(arr.begin(), arr.end(), 0);
        if (k == 0 || sum % k != 0) return false;
        int target = sum / k;
        vector<bool> used(arr.size(), false);

        sort(arr.rbegin(), arr.rend());
        if (arr[0] > target) return false;

        return solve(0, k, 0, target, arr, used);
    }
};

int main() {
    Solution sol;
    vector<int> arr = {2, 1, 4, 5, 3, 3};
    int k = 3;

    if (sol.isKPartitionPossible(arr, k))
        cout << "Partition possible" << endl;
    else
        cout << "Partition not possible" << endl;

    return 0;
}
