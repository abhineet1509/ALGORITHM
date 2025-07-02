#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> res;

    for (auto it : intervals) {
        if (res.empty() || res.back()[1] < it[0]) {
            res.push_back(it);
        } else {
            res.back()[1] = max(res.back()[1], it[1]);
        }
    }
    return res;
}

int main() {
    vector<vector<int>> intervals = {
        {1, 3}, {2, 6}, {8, 10}, {15, 18}
    };

    vector<vector<int>> merged = merge(intervals);

    cout << "Merged Intervals:\n";
    for (auto interval : merged) {
        cout << "[" << interval[0] << ", " << interval[1] << "]\n";
    }

    return 0;
}
