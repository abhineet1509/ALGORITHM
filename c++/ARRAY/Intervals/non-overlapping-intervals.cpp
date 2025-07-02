#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    if (intervals.empty()) return 0;

    // Step 1: Sort by end time
    sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){
        return a[1] < b[1];
    });

    int count = 1;  // First interval is always picked
    int end = intervals[0][1];

    // Step 2: Count non-overlapping intervals
    for (int i = 1; i < intervals.size(); ++i) {
        if (intervals[i][0] >= end) {
            count++;
            end = intervals[i][1];
        }
    }

    // Step 3: Remove rest
    return intervals.size() - count;
}

int main() {
    vector<vector<int>> intervals = {{1,2}, {2,3}, {3,4}, {1,3}};

    int removed = eraseOverlapIntervals(intervals);

    cout << "Minimum intervals to remove: " << removed << endl;

    return 0;
}
