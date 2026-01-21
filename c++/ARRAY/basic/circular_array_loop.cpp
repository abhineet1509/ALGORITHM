#include <bits/stdc++.h>
using namespace std;


int nextIndex(vector<int>& nums, int i) {
    int n = nums.size();
    return ((i + nums[i]) % n + n) % n; 
}

bool circularArrayLoop(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        if (nums[i] == 0) continue;

        int slow = i, fast = i;
        bool direction = nums[i] > 0;

        while (true) {
            // move slow pointer once
            int nextSlow = nextIndex(nums, slow);
            if (nums[nextSlow] == 0 || (nums[nextSlow] > 0) != direction || nextSlow == slow) break;

            // move fast pointer twice
            int nextFast = nextIndex(nums, fast);
            if (nums[nextFast] == 0 || (nums[nextFast] > 0) != direction || nextFast == fast) break;
            nextFast = nextIndex(nums, nextFast);
            if (nums[nextFast] == 0 || (nums[nextFast] > 0) != direction || nextFast == nextIndex(nums, fast)) break;

            slow = nextSlow;
            fast = nextFast;

            if (slow == fast) return true;
        }

       
        int val = i;
        while (nums[val] != 0 && (nums[val] > 0) == direction) {
            int nextVal = nextIndex(nums, val);
            nums[val] = 0;
            val = nextVal;
        }
    }

    return false;
}

int main() {
    vector<int> nums = {2, -1, 1, 2, 2};
    cout << (circularArrayLoop(nums) ? "true" : "false") << endl; // Output: true
    return 0;
}
