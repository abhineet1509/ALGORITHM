#include <bits/stdc++.h>
using namespace std;

int countHiddenSequences(vector<int>& differences, int lower, int upper) {
    long long prefix = 0;           // to build prefix sum
    long long minPrefix = 0;        // minimum prefix sum
    long long maxPrefix = 0;        // maximum prefix sum

    // Build prefix sum dynamically and track min/max
    for (int diff : differences) {
        prefix += diff;
        minPrefix = min(minPrefix, prefix);
        maxPrefix = max(maxPrefix, prefix);
    }

    // Find valid range for nums[0]
    long long minStart = lower - minPrefix;
    long long maxStart = upper - maxPrefix;

    // Total valid starting points
    long long count = max(0LL, maxStart - minStart + 1);
    return (int)count;
}

int main() {
    vector<int> differences = {1, -3, 4};
    int lower = 1, upper = 6;

    int result = countHiddenSequences(differences, lower, upper);
    cout << "Number of hidden sequences: " << result << endl;
    return 0;
}
