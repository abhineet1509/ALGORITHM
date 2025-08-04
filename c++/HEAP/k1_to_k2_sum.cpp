#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// Function to get kth smallest element using maxHeap
int kthSmallest(vector<int>& arr, int k) {
    priority_queue<int> maxHeap;
    for (int num : arr) {
        maxHeap.push(num);
        if (maxHeap.size() > k) 
            maxHeap.pop();
    }
    return maxHeap.top();
}

int sumBetweenK1K2(vector<int>& arr, int k1, int k2) {
    int first = kthSmallest(arr, k1);
    int second = kthSmallest(arr, k2);
    
    if (first > second) swap(first, second);
    
    int sum = 0;
    for (int num : arr) {
        if (num > first && num < second) {
            sum += num;
        }
    }
    return sum;
}

int main() {
    vector<int> arr = {20, 8, 22, 4, 12, 10, 14};
    int k1 = 3, k2 = 6;
    cout << "Sum between k1 and k2 smallest elements = " 
         << sumBetweenK1K2(arr, k1, k2) << endl;
    return 0;
}
