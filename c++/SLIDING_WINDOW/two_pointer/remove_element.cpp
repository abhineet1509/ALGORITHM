#include <bits/stdc++.h>
using namespace std;

int removeElement(vector<int>& nums, int val) {
    int k = 0; // next position for valid element
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != val) {
            nums[k] = nums[i];
            k++;
        }
    }
    return k;
}

int main() {
    vector<int> nums = {3,2,2,3,4,3,5};
    int val = 3;

    int newLength = removeElement(nums, val);

    cout << "New length: " << newLength << endl;
    cout << "Updated array: ";
    for (int i = 0; i < newLength; i++) cout << nums[i] << " ";
    cout << endl;

    return 0;
}
