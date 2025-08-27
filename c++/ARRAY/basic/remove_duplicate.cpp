#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
using namespace std;

void removeDuplicatesTwoPointer(vector<int>& nums) {
    if (nums.empty()) return;
    int i = 0;
    for (int j = 1; j < nums.size(); j++) {
        if (nums[j] != nums[i]) {
            i++;
            nums[i] = nums[j];
        }
    }
    cout << "Two Pointer Method:\nArray: ";
    for (int k = 0; k <= i; k++) cout << nums[k] << " ";
    cout << "\n";
}

void removeDuplicatesSet(const vector<int>& nums) {
    set<int> unique(nums.begin(), nums.end());
    cout << "Set Method:\nArray: ";
    for (int x : unique) cout << x << " ";
    cout << "\n";
}

void removeDuplicatesUnorderedSet(const vector<int>& nums) {
    unordered_set<int> unique(nums.begin(), nums.end());
    cout << "Unordered_Set Method:\nArray: ";
    for (int x : unique) cout << x << " ";
    cout << "\n";
}

int main() {
    vector<int> nums = {1,1,2,2,3,3,4};

    cout << "Original: ";
    for (int x : nums) cout << x << " ";
    cout << "\n\n";

    removeDuplicatesTwoPointer(nums);
    removeDuplicatesSet(nums);
    removeDuplicatesUnorderedSet(nums);
}
