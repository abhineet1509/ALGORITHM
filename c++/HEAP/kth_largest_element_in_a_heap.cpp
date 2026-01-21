#include <bits/stdc++.h>
using namespace std;

int findKthLargestHeap(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> pq; // min-heap
    for (int num : nums) {
        pq.push(num);
        if (pq.size() > k)
            pq.pop();
    }
    return pq.top();
}

int main() {
    vector<int> nums = {3,2,1,5,6,4};
    int k = 2;

    cout << findKthLargestHeap(nums, k) << endl; // Output: 5
    return 0;
}
