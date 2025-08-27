#include <bits/stdc++.h>
using namespace std;

class HashTableLinear {
    int size;
    vector<int> table;

public:
    HashTableLinear(int s) : size(s), table(s, -1) {}

    void insert(int key) {
        int idx = key % size, start = idx;
        while (table[idx] != -1) {
            idx = (idx + 1) % size;
            if (idx == start) { cout << "Full\n"; return; }
        }
        table[idx] = key;
    }

    bool search(int key) {
        int idx = key % size, start = idx;
        while (table[idx] != -1) {
            if (table[idx] == key) return true;
            idx = (idx + 1) % size;
            if (idx == start) break;
        }
        return false;
    }

    void display() {
        for (int i = 0; i < size; i++)
            cout << i << ": " << (table[i] == -1 ? "EMPTY" : to_string(table[i])) << "\n";
    }
};

int main() {
    HashTableLinear ht(7);
    for (int k : {10, 20, 15, 7, 32}) ht.insert(k);
    ht.display();
    cout << "Search 15: " << (ht.search(15) ? "Found" : "Not Found") << "\n";
}
