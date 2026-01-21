#include <bits/stdc++.h>
using namespace std;

int minMovesFormula(vector<int>& nums) {
    long long sum = 0;
    int minVal = INT_MAX;
    for (int num : nums) {
        sum += num;
        minVal = min(minVal, num);
    }
    return (int)(sum - (long long)nums.size() * minVal);
}

int minMoves(vector<int>& nums) {
    int minVal = *min_element(nums.begin(), nums.end());
    int moves = 0;
    for (int i = 0; i < nums.size(); i++)
        moves += nums[i] - minVal;
    return moves;
}

int minMoves2(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int median = nums[n / 2]; // if n is even, either middle works
    int moves = 0;
    for (int num : nums) moves += abs(num - median);
    return moves;
}

int main() {
    vector<int> nums = {1,2,3};
    cout << minMoves(nums) << endl; // Output: 3
    return 0;
}
