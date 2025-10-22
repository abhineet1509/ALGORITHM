#include <bits/stdc++.h>
using namespace std;

class MedianFinder {
public:
    priority_queue<int> leftMax; 
    priority_queue<int, vector<int>, greater<int>> rightMin; 

    MedianFinder() {}

    void addNum(int num) {
        // Step 1: Add to max-heap
        leftMax.push(num);

        // Step 2: Balance so all elements in leftMax <= rightMin
        if (!leftMax.empty() && !rightMin.empty() && leftMax.top() > rightMin.top()) {
            rightMin.push(leftMax.top());
            leftMax.pop();
        }

        // Step 3: Balance sizes
        if (leftMax.size() > rightMin.size() + 1) {
            rightMin.push(leftMax.top());
            leftMax.pop();
        } else if (rightMin.size() > leftMax.size()) {
            leftMax.push(rightMin.top());
            rightMin.pop();
        }
    }

    double findMedian() {
        if (leftMax.size() == rightMin.size()) {
            return (leftMax.top() + rightMin.top()) / 2.0;
        }
        return leftMax.top();
    }
};

class MedianFinder {
public:
    vector<int> nums;  // store all numbers

    MedianFinder() {}

    void addNum(int num) {
        nums.push_back(num);
    }

    double findMedian() {
        if (nums.empty()) return 0.0;

        sort(nums.begin(), nums.end()); // sort before finding median
        int n = nums.size();

        if (n % 2 == 1) {
            // Odd count → middle element
            return nums[n / 2];
        } else {
            // Even count → average of middle two
            return (nums[n / 2 - 1] + nums[n / 2]) / 2.0;
        }
    }
};
int main() {
    MedianFinder mf;
    mf.addNum(3);
    mf.addNum(1);
    cout << mf.findMedian() << endl; // 2.0
    mf.addNum(2);
    cout << mf.findMedian() << endl; // 2.0
}
