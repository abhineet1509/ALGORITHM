#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void printNiceSubarrays(vector<int>& nums, int k) {
    unordered_map<int, vector<int>> mp;
    mp[0] = {-1}; // prefix sum 0 occurs at index -1 (before start)

    int odd = 0;

    for (int i = 0; i < nums.size(); i++) {
        odd += nums[i] % 2;

        if (mp.find(odd - k) != mp.end()) {
            for (int startIdx : mp[odd - k]) {
                cout << "[ ";
                for (int j = startIdx + 1; j <= i; j++)
                    cout << nums[j] << " ";
                cout << "]\n";
            }
        }

        mp[odd].push_back(i);
    }
}

int main() {
    vector<int> nums = {1, 1, 2, 1, 1};
    int k = 3;

    cout << "Subarrays with exactly " << k << " odd numbers:\n";
    printNiceSubarrays(nums, k);

    return 0;
}
