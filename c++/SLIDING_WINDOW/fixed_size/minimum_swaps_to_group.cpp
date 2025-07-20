#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minSwaps(vector<int>& nums) {
    int totalOnes = 0;

    // Step 1: Count total number of 1s
    for (int num : nums) {
        if (num == 1) totalOnes++;
    }

    // If there are no 1s or all are 1s, no swaps needed
    if (totalOnes == 0 || totalOnes == nums.size()) return 0;

    int maxOnesInWindow = 0;
    int currentOnes = 0;

    // Step 2: Initial window of size totalOnes
    for (int i = 0; i < totalOnes; ++i) {
        if (nums[i] == 1) currentOnes++;
    }

    maxOnesInWindow = currentOnes;

    // Step 3: Slide the window and update maxOnesInWindow
    for (int i = totalOnes; i < nums.size(); ++i) {
        if (nums[i] == 1) currentOnes++;
        if (nums[i - totalOnes] == 1) currentOnes--;

        maxOnesInWindow = max(maxOnesInWindow, currentOnes);
    }

    // Step 4: Minimum swaps = total 1s - max 1s in best window
    return totalOnes - maxOnesInWindow;
}

int main() {
    vector<int> nums = {1, 0, 1, 0, 1};
    cout << "Minimum swaps needed: " << minSwaps(nums) << endl;
    return 0;
}
