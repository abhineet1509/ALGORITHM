#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int numberOfSubarrays(vector<int>& nums, int k) {
    unordered_map<int, int> freq;
    freq[0] = 1;

    int count = 0, odd = 0;

    for (int num : nums) {
        odd += num % 2;

        // count subarrays ending here with k odd numbers
        if (freq.find(odd - k) != freq.end()) {
            count += freq[odd - k];
        }

        freq[odd]++;
    }

    return count;
}
int main() {
    vector<int> nums = {1, 1, 2, 1, 1};
    int k = 3;

    int result = numberOfSubarrays(nums, k);
    cout << "Number of subarrays with exactly " << k << " odd numbers: " << result << endl;

    return 0;
}