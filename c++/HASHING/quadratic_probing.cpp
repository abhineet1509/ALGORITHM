#include <bits/stdc++.h>
using namespace std;

class HashTableQuadratic {
    int size;
    vector<int> table;

public:
    HashTableQuadratic(int s) : size(s) {
        table.assign(size, -1);
    }

    int hash(int key) {
        return key % size;
    }

    void insert(int key) {
        int idx = hash(key);
        int i = 0;
        while (table[(idx + i * i) % size] != -1) {
            i++;
            if (i == size) {
                cout << "Hash Table is full\n";
                return;
            }
        }
        table[(idx + i * i) % size] = key;
    }

    bool search(int key) {
        int idx = hash(key);
        int i = 0;
        while (table[(idx + i * i) % size] != -1) {
            if (table[(idx + i * i) % size] == key) return true;
            i++;
            if (i == size) break;
        }
        return false;
    }

    void display() {
        for (int i = 0; i < size; i++)
            cout << i << ": " << (table[i] == -1 ? "EMPTY" : to_string(table[i])) << "\n";
    }
};

int main() {
    HashTableQuadratic ht(7);
    vector<int> keys = {10, 20, 15, 7, 32};
    for (int k : keys) ht.insert(k);
    ht.display();
    cout << "Search 15: " << (ht.search(15) ? "Found" : "Not Found") << "\n";
}
