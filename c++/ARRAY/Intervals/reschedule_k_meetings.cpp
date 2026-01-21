#include <bits/stdc++.h>
using namespace std;

int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
    int n = startTime.size();
    vector<long long> gaps;

    gaps.push_back(startTime[0]);

    for (int i = 1; i < n; i++) {
        gaps.push_back(startTime[i] - endTime[i - 1]);
    }

    gaps.push_back(eventTime - endTime[n - 1]);

    long long windowSum = 0, ans = 0;

    for (int i = 0; i <= k && i < gaps.size(); i++)
        windowSum += gaps[i];

    ans = windowSum;

    for (int i = k + 1; i < gaps.size(); i++) {
        windowSum += gaps[i] - gaps[i - k - 1];
        ans = max(ans, windowSum);
    }

    return ans;
}

int main() {
    int eventTime = 10;
    int k = 1;
    vector<int> startTime = {0,2,9};
    vector<int> endTime   = {1,4,10};

    cout << maxFreeTime(eventTime, k, startTime, endTime);
    return 0;
}
