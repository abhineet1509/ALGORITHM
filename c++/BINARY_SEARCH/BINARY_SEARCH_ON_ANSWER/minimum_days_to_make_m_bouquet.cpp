#include <bits/stdc++.h>
using namespace std;

bool canMake(vector<int>& bloomDay, int m, int k, int day) {
    int cnt = 0, bouquets = 0;

    for (int x : bloomDay) {
        if (x <= day) {
            cnt++;
            if (cnt == k) {
                bouquets++;
                cnt = 0;
            }
        } else {  
            cnt = 0;
        }
    }
    return bouquets >= m;
}
 //O(n × log(maxBloomDay))
int minDays(vector<int>& bloomDay, int m, int k) {
    int n = bloomDay.size();
    if (1LL * m * k > n) return -1;

    int low = *min_element(bloomDay.begin(), bloomDay.end());
    int high = *max_element(bloomDay.begin(), bloomDay.end());
    int ans = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (canMake(bloomDay, m, k, mid)) {
            ans = mid;
            high = mid - 1;   // minimize days
        } else {
            low = mid + 1;
        }
    }
    return ans;
}


int minDaysBrute(vector<int>& bloomDay, int m, int k) {
    int n = bloomDay.size();
    if (1LL * m * k > n) return -1;

    int low = *min_element(bloomDay.begin(), bloomDay.end());
    int high = *max_element(bloomDay.begin(), bloomDay.end());

    for (int day = low; day <= high; day++) {
        if (canMake(bloomDay, m, k, day))
            return day;
    }
    return -1;
}
int main(){

}