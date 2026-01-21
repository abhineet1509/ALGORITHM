#include <bits/stdc++.h>
using namespace std;

int maxProfitAssignment(vector<int>& difficulty,
                        vector<int>& profit,
                        vector<int>& worker) {

    vector<pair<int,int>> jobs;
    for (int i = 0; i < difficulty.size(); i++)
        jobs.push_back({difficulty[i], profit[i]});

    sort(jobs.begin(), jobs.end());
    sort(worker.begin(), worker.end());

    int i = 0, best = 0, total = 0;

    for (int w : worker) {
        while (i < jobs.size() && jobs[i].first <= w) {
            best = max(best, jobs[i].second);
            i++;
        }
        total += best;
    }
    return total;
}

int main() {
    vector<int> difficulty = {2,4,6,8,10};
    vector<int> profit     = {10,20,30,40,50};
    vector<int> worker     = {4,5,6,7};

    cout << maxProfitAssignment(difficulty, profit, worker); // Output: 100
    return 0;
}
