#include <bits/stdc++.h>
using namespace std;

class LRUCache {
    int capacity;
    list<int> dll;  
    unordered_map<int, pair<int, list<int>::iterator>> mp;

public:
    LRUCache(int cap) {
        capacity = cap;
    }

    int get(int key) {
        if (mp.find(key) == mp.end())
            return -1;

        dll.erase(mp[key].second);
        dll.push_front(key);
        mp[key].second = dll.begin();

        return mp[key].first;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            dll.erase(mp[key].second);
        }
        else if (dll.size() == capacity) {
            int lru = dll.back();
            dll.pop_back();
            mp.erase(lru);
        }

        dll.push_front(key);
        mp[key] = {value, dll.begin()};
    }
};

int main() {
    LRUCache cache(2);

    cache.put(1, 10);
    cache.put(2, 20);

    cout << cache.get(1) << endl; // 10
    cache.put(3, 30);             // evicts key 2
    cout << cache.get(2) << endl; // -1
    cout << cache.get(3) << endl; // 30

    return 0;
}
