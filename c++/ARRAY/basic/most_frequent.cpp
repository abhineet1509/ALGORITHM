#include <bits/stdc++.h>
using namespace std;

/* -------- Brute Force Frequency -------- */
void frequencyBrute(vector<int>& arr) {
    int n = arr.size();
    vector<bool> visited(n, false);

    cout << "\nBrute Force Frequency:\n";
    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;

        int cnt = 1;
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                cnt++;
                visited[j] = true;
            }
        }
        cout << arr[i] << " -> " << cnt << endl;
    }
}

/* -------- Brute Force Max Frequency -------- */
void maxFreqBrute(vector<int>& arr) {
    int n = arr.size();
    int maxFreq = 0, element = arr[0];

    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (arr[i] == arr[j])
                cnt++;
        }
        if (cnt > maxFreq) {
            maxFreq = cnt;
            element = arr[i];
        }
    }
    cout << "Max Frequency Element (Brute): " 
         << element << " (" << maxFreq << " times)\n";
}

/* -------- STL Frequency -------- */
void frequencySTL(vector<int>& arr) {
    unordered_map<int, int> freq;

    for (int x : arr)
        freq[x]++;

    cout << "\nSTL Frequency (unordered_map):\n";
    for (auto &p : freq)
        cout << p.first << " -> " << p.second << endl;
}

/* -------- STL Max Frequency -------- */
void maxFreqSTL(vector<int>& arr) {
    unordered_map<int, int> freq;
    int maxFreq = 0, element = arr[0];

    for (int x : arr) {
        freq[x]++;
        if (freq[x] > maxFreq) {
            maxFreq = freq[x];
            element = x;
        }
    }
    cout << "Max Frequency Element (STL): " 
         << element << " (" << maxFreq << " times)\n";
}

/* -------- Main -------- */
int main() {
    vector<int> arr = {1, 2, 2, 3, 3, 3, 4};

    frequencyBrute(arr);
    maxFreqBrute(arr);

    frequencySTL(arr);
    maxFreqSTL(arr);

    return 0;
}
