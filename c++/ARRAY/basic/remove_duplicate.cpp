#include <iostream>
#include <vector>
#include <set>
#include<unordered_map>
#include <unordered_set>
using namespace std;
       //perferct number is a number whose sum of divisior  ==  num
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

bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_map<int, int> lastIndex;
    for (int i = 0; i < nums.size(); i++) {
        if (lastIndex.count(nums[i]) && i - lastIndex[nums[i]] <= k)
            return true;
        lastIndex[nums[i]] = i;
    }
    return false;
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
