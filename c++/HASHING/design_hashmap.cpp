#include <bits/stdc++.h>
using namespace std;

class MyHashMap {
private:
    static const int SIZE = 1000;
    vector<pair<int,int>> buckets[SIZE];
    
    int hash(int key) {
        return key % SIZE;
    }

public:
    MyHashMap() {}

    void put(int key, int value) {
        int h = hash(key);
        for (auto &p : buckets[h]) {
            if (p.first == key) {
                p.second = value;
                return;
            }
        }
        buckets[h].push_back({key, value});
    }

    int get(int key) {
        int h = hash(key);
        for (auto &p : buckets[h]) {
            if (p.first == key) return p.second;
        }
        return -1;
    }

    void remove(int key) {
        int h = hash(key);
        auto &bucket = buckets[h];
        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (it->first == key) {
                bucket.erase(it);
                return;
            }
        }
    }
};

int main() {
    MyHashMap myMap;
    myMap.put(1, 100);
    myMap.put(2, 200);
    myMap.put(1001, 300);
    cout << myMap.get(1) << endl;
    cout << myMap.get(2) << endl;
    cout << myMap.get(3) << endl;
    cout << myMap.get(1001) << endl;
    myMap.remove(2);
    cout << myMap.get(2) << endl;
    return 0;
}
