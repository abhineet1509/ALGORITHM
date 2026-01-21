#include <bits/stdc++.h>
using namespace std;

class LFUCache {
    int capacity, minFreq;
    unordered_map<int, int> value, freq;
    unordered_map<int, list<int>> freqList;
    unordered_map<int, list<int>::iterator> pos;

public:
    LFUCache(int cap) {
        capacity = cap;
        minFreq = 0;
    }

    int get(int key) {
        if (value.find(key) == value.end())
            return -1;

        int f = freq[key];
        freqList[f].erase(pos[key]);

        freq[key]++;
        freqList[f + 1].push_front(key);
        pos[key] = freqList[f + 1].begin();

        if (freqList[f].empty() && minFreq == f)
            minFreq++;

        return value[key];
    }

    void put(int key, int val) {
        if (capacity == 0) return;

        if (value.find(key) != value.end()) {
            value[key] = val;
            get(key);
            return;
        }

        if (value.size() == capacity) {
            int evict = freqList[minFreq].back();
            freqList[minFreq].pop_back();
            value.erase(evict);
            freq.erase(evict);
            pos.erase(evict);
        }

        value[key] = val;
        freq[key] = 1;
        minFreq = 1;
        freqList[1].push_front(key);
        pos[key] = freqList[1].begin();
    }
};

int main() {
    LFUCache cache(2);

    cache.put(1, 10);
    cache.put(2, 20);

    cout << cache.get(1) << endl; // 10
    cache.put(3, 30);             // evicts key 2
    cout << cache.get(2) << endl; // -1
    cout << cache.get(3) << endl; // 30

    return 0;
}
