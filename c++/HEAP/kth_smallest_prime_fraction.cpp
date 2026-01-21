#include <bits/stdc++.h>
using namespace std;

vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
    int n = arr.size();
    
    // Comparator for min-heap
    struct cmp {
        bool operator()(const tuple<double,int,int>& a, const tuple<double,int,int>& b) {
            return get<0>(a) > get<0>(b); // min-heap
        }
    };
    
    priority_queue<tuple<double,int,int>, vector<tuple<double,int,int>>, cmp> pq;

    // Push fractions with numerator arr[0]
    for (int j = 1; j < n; j++) {
        pq.push(make_tuple(double(arr[0]) / arr[j], 0, j));
    }

    tuple<double,int,int> top;
    for (int iter = 0; iter < k; iter++) {
        top = pq.top(); pq.pop();
        int i = get<1>(top);
        int j = get<2>(top);

        if (i + 1 < j) { // push next fraction with same denominator
            pq.push(make_tuple(double(arr[i+1]) / arr[j], i+1, j));
        }
    }

    return {arr[get<1>(top)], arr[get<2>(top)]};
}


vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
    int n = arr.size();
    double left = 0.0, right = 1.0;
    vector<int> ans(2);

    while (true) {
        double mid = (left + right) / 2;
        int count = 0;
        double maxFraction = 0.0;
        int p = 0, q = 1; // numerator / denominator

        int j = 1;
        for (int i = 0; i < n - 1; i++) {
            while (j < n && arr[i] > mid * arr[j]) j++;
            if (j == n) break;
            count += n - j;

            // track the largest fraction ≤ mid
            if (double(arr[i]) / arr[j] > maxFraction) {
                maxFraction = double(arr[i]) / arr[j];
                p = arr[i];
                q = arr[j];
            }
        }

        if (count == k) return {p, q};
        else if (count < k) left = mid;
        else right = mid;
    }
}

int main() {
    vector<int> arr = {1, 2, 3, 5};
    int k = 3;
    vector<int> result = kthSmallestPrimeFraction(arr, k);
    cout << "K-th smallest fraction: " << result[0] << "/" << result[1] << endl; // 2/5
