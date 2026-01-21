#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    if (intervals.empty()) return 0;

    // sort by end time
    sort(intervals.begin(), intervals.end(),
         [](vector<int>& a, vector<int>& b) {
             return a[1] < b[1];
         });

    vector<vector<int>> kept, removed;

    int end = intervals[0][1];
    kept.push_back(intervals[0]);   // first interval always kept

    for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i][0] >= end) {
            // no overlap → keep
            kept.push_back(intervals[i]);
            end = intervals[i][1];
        } else {
            // overlap → remove
            removed.push_back(intervals[i]);
        }
    }

    // printing results
    cout << "Kept intervals:\n";
    for (auto &v : kept)
        cout << "[" << v[0] << "," << v[1] << "] ";

    cout << "\n\nRemoved intervals:\n";
    for (auto &v : removed)
        cout << "[" << v[0] << "," << v[1] << "] ";

    cout << endl;

    return removed.size();
}

int main() {
    vector<vector<int>> intervals = {{1,2}, {2,3}, {3,4}, {1,3}};

    int removedCount = eraseOverlapIntervals(intervals);

    cout << "\nMinimum intervals to remove: " << removedCount << endl;
    return 0;
}
