#include <iostream>
#include <vector>
#include <list>
using namespace std;

class HashTable {
    int size;
    vector<list<int>> table;

public:
    HashTable(int s) : size(s), table(s) {}

    void insert(int key) {
        table[key % size].push_back(key);
    }

    bool search(int key) {
        for (int x : table[key % size]) {
            if (x == key) return true;
        }
        return false;
    }

    void remove(int key) {
        table[key % size].remove(key);
    }

    void display() {
        for (int i = 0; i < size; i++) {
            cout << i << ": ";
            for (int x : table[i]) cout << x << " ";
            cout << "\n";
        }
    }
};

int main() {
    HashTable h(7);

    h.insert(10);
    h.insert(20);
    h.insert(15);
    h.insert(7);

    h.display();

    cout << "Search 15: " << (h.search(15) ? "Found" : "Not Found") << "\n";
    h.remove(15);
    cout << "Search 15 after removal: " << (h.search(15) ? "Found" : "Not Found") << "\n";
}
