#include <bits/stdc++.h>
using namespace std;

bool canPlace(vector<int>& stations, int k, double maxDist) {
    int required = 0;

    for (int i = 1; i < stations.size(); i++) {
        double gap = stations[i] - stations[i - 1];
        required += (int)(gap / maxDist);
        if (required > k) return false;
    }
    return true;
}

double minmaxGasDist(vector<int>& stations, int k) {
    sort(stations.begin(), stations.end());

    double low = 0.0;
    double high = stations.back() - stations.front();
    double ans = high;

    while (high - low > 1e-6) {
        double mid = (low + high) / 2.0;

        if (canPlace(stations, k, mid)) {
            ans = mid;
            high = mid;   // try smaller distance
        } else {
            low = mid;
        }
    }
    return ans;
}

int main() {
    int n, k;
    cin >> n;

    vector<int> stations(n);
    for (int i = 0; i < n; i++) cin >> stations[i];

    cin >> k;

    cout << fixed << setprecision(6) << minmaxGasDist(stations, k);
    return 0;
}
