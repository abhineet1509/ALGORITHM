#include <bits/stdc++.h>
using namespace std;

// 1. Brute Force Approach
int mostFrequentBF(vector<int>& arr) {
    int n = arr.size();
    int maxCount = 0, element = arr[0];
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++)
            if (arr[j] == arr[i]) count++;
        if (count > maxCount) {
            maxCount = count;
            element = arr[i];
        }
    }
    return element;
}

// 2. Hash Map Approach
int mostFrequentMap(vector<int>& arr) {
    unordered_map<int,int> freq;
    int maxCount = 0, element = arr[0];
    for (int x : arr) freq[x]++;
    for (auto i: freq) {
        if (i.second > maxCount) {
            maxCount = i.second;
            element = i.first;
        }
    }
    return element;
}

// 4. STL max_element Approach
int mostFrequentSTL(vector<int>& arr) {
    unordered_map<int,int> freq;
    for (int x : arr) freq[x]++;
    return max_element(freq.begin(), freq.end(),
                       [](auto &a, auto &b){ return a.second < b.second; })->first;
}

int main() {
    vector<int> arr = {1, 3, 2, 3, 4, 3, 2};

    cout << "Brute Force: " << mostFrequentBF(arr) << endl;
    cout << "Hash Map: " << mostFrequentMap(arr) << endl;
    cout << "STL max_element: " << mostFrequentSTL(arr) << endl;

    return 0;
}
