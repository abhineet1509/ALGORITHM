#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals) {
    if (intervals.empty()) return {};

    sort(intervals.begin(), intervals.end());

    vector<vector<int>> res;

    int start = intervals[0][0];
    int end   = intervals[0][1];

    for (int i = 1; i < intervals.size(); i++) {
        // overlap
        if (intervals[i][0] <= end) {
            end = max(end, intervals[i][1]);
        }
        // no overlap
        else {
            res.push_back({start, end});
            start = intervals[i][0];
            end   = intervals[i][1];
        }
    }

    // last interval
    res.push_back({start, end});
    return res;
}

int main() {
    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> ans = mergeIntervals(intervals);

    for (auto &v : ans)
        cout << "[" << v[0] << "," << v[1] << "] ";

    return 0;
}
