#include <bits/stdc++.h>
using namespace std;

int leastInterval(vector<char>& tasks, int n) {
    unordered_map<char, int> freq;
    for (char t : tasks) {
        freq[t]++;
    }

    priority_queue<int> pq;
    for (auto& it : freq) {
        pq.push(it.second);
    }

    int time = 0;

    while (!pq.empty()) {
        vector<int> temp;
        int k = n + 1;

        while (k > 0 && !pq.empty()) {
            int count = pq.top();
            pq.pop();
            count--;
            if (count > 0) temp.push_back(count);
            time++;
            k--;
        }

        for (int c : temp) pq.push(c);

        if (!pq.empty()) time += k;
    }

    return time;
}

int leastInterval(vector<char>& tasks, int n) {
    vector<int> freq(26, 0);
    for (char t : tasks) freq[t - 'A']++;

    sort(freq.begin(), freq.end(), greater<int>());
    int maxFreq = freq[0];
    int idleSlots = (maxFreq - 1) * n; // A _ _ | A _ _ | A

    for (int i = 1; i < 26; i++) {
        idleSlots -= min(freq[i], maxFreq - 1);
    }

    return tasks.size() + max(0, idleSlots);
}
int main() {
    vector<char> tasks = {'A','A','A','B','B','B'};
    int n = 2;
    cout << leastInterval(tasks, n) << endl;
    return 0;
}
