#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int>& arr, int k, int w, int target) {
    int n = arr.size();
    vector<long long> added(n+1, 0); // to track increments
    long long sum = 0; // current window effect
    long long used = 0; // total watering used

    for(int i=0;i<n;i++){
        if(i>=w) sum -= added[i-w]; // sliding window remove
        long long curr = arr[i] + sum;
        if(curr < target){
            long long diff = target - curr;
            used += diff;
            if(used > k) return false;
            sum += diff;
            added[i] = diff;
        }
    }
    return true;
}

int maximizeMinHeight(vector<int>& arr, int k, int w) {
    int low = *min_element(arr.begin(), arr.end());
    int high = low + k + 1; // max possible height

    while(low < high){
        int mid = low + (high - low)/2;
        if(isPossible(arr, k, w, mid))
            low = mid + 1;
        else
            high = mid;
    }
    return low - 1;
}

int main(){
    vector<int> arr = {1,2,4};
    int k = 3, w = 2;
    cout << "Maximum minimum height: " << maximizeMinHeight(arr, k, w) << endl;
}
