#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) return 0;
    int i = 0;
    for (int j = 1; j < nums.size(); j++) {
        if (nums[j] != nums[i]) {
            i++;
            nums[i] = nums[j];
        }
    }
    return i + 1;
}

vector<int> removeDuplicatesBrute(vector<int>& nums) {
    vector<int> result;
    for (int i = 0; i < nums.size(); i++) {
        if (i == 0 || nums[i] != nums[i - 1]) {
            result.push_back(nums[i]);
        }
    }
    return result;
}

int main() {
    vector<int> nums = {1, 1, 2, 2, 3, 4, 4};

    int newLength = removeDuplicates(nums);
    for (int i = 0; i < newLength; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    vector<int> result = removeDuplicatesBrute(nums);
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
