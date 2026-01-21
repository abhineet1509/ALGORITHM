#include <iostream>
#include <vector>
#include <deque>
#include<set>
using namespace std;

// Function to find maximum of all subarrays of size k
vector<int> maxSlidingWindow(vector<int>& arr, int k) {
    deque<int> dq;
    vector<int> res;
    int n = arr.size();

    for (int i = 0; i < n; i++) {
        // Step 1: Remove indices out of current window
        if (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();

        // Step 2: Remove elements smaller than current from the back
        while (!dq.empty() && arr[dq.back()] < arr[i])
            dq.pop_back();

        // Step 3: Add current index to deque
        dq.push_back(i);

        // Step 4: Store result once the window size hits k
        if (i >= k - 1)
            res.push_back(arr[dq.front()]);
    }

    return res;
}

vector<double> medianSlidingWindow(vector<int>& nums, int k) {
    vector<double> medians;
    multiset<int> window;
    auto mid = window.begin();

    for (int i = 0; i < nums.size(); i++) {
        if (i >= k) {
            // Remove the outgoing element
            if (nums[i - k] <= *mid) mid--;
            window.erase(window.lower_bound(nums[i - k]));
        }

        // Insert the new element
        window.insert(nums[i]);
        if (i == 0) mid = window.begin();
        else {
            if (nums[i] < *mid) mid--;
            else if (nums[i] >= *mid && i - k >= 0 && nums[i - k] <= *mid) mid++;
        }

        if (i >= k - 1) {
            if (k % 2 == 1)
                medians.push_back(*next(window.begin(), k / 2));
            else {
                auto it1 = next(window.begin(), k / 2 - 1);
                auto it2 = next(window.begin(), k / 2);
                medians.push_back(((double)(*it1) + *it2) / 2.0);
            }
        }
    }

    return medians;
}

int main() {
    vector<int> arr = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    vector<int> result = maxSlidingWindow(arr, k);

    cout << "Maximum of all subarrays of size " << k << ":\n";
    for (int x : result)
        cout << x << " ";

    return 0;
}
