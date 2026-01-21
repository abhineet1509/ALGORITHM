#include <bits/stdc++.h>
using namespace std;

int maxFreeTimeAfterRescheduling(vector<vector<int>>& meetings) {
    int n = meetings.size();
    if (n <= 2) return INT_MAX; 

   
    sort(meetings.begin(), meetings.end());

 
    vector<int> gaps;
    for (int i = 0; i < n - 1; ++i) {
        gaps.push_back(meetings[i + 1][0] - meetings[i][1]);
    }

  
    int maxGap = *max_element(gaps.begin(), gaps.end());

    // Step 4: Try removing one meeting and merge the two adjacent ones
    for (int i = 1; i < n - 1; ++i) {
        int mergedGap = meetings[i + 1][0] - meetings[i - 1][1];
        maxGap = max(maxGap, mergedGap);
    }

    return maxGap;
}

int main() {
    vector<vector<int>> meetings = {{1, 3}, {5, 6}, {7, 9}, {10, 11}};
    cout << "Max free time after rescheduling: " << maxFreeTimeAfterRescheduling(meetings) << endl;
    return 0;
}
