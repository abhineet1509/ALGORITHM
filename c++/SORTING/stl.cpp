#include <bits/stdc++.h>
using namespace std;

int main() {
    // -----------------------------------
    // 1️⃣ Vector of pairs
    // -----------------------------------
    vector<pair<int, int>> v = {{3, 5}, {1, 2}, {2, 9}, {1, 7}};

    cout << "Original vector<pair>:\n";
    for (auto p : v)
        cout << p.first << " " << p.second << "\n";
    cout << "\n";

    // (a) Sort by first (default)
    sort(v.begin(), v.end());
    cout << "Sorted by first (default):\n";
    for (auto p : v)
        cout << p.first << " " << p.second << "\n";
    cout << "\n";

    // (b) Sort by second (ascending)
    sort(v.begin(), v.end(), [](pair<int,int> a, pair<int,int> b) {
        return a.second < b.second;
    });
    cout << "Sorted by second (ascending):\n";
    for (auto p : v)
        cout << p.first << " " << p.second << "\n";
    cout << "\n";

    // (c) Sort by first ascending, then second descending
    sort(v.begin(), v.end(), [](pair<int,int> a, pair<int,int> b) {
        if (a.first == b.first)
            return a.second > b.second;
        return a.first < b.first;
    });
    cout << "Sorted by first asc, then second desc:\n";
    for (auto p : v)
        cout << p.first << " " << p.second << "\n";
    cout << "\n";

    // -----------------------------------
    // 2️⃣ Map examples
    // -----------------------------------
    map<int, string> m = {{2,"B"}, {1,"A"}, {3,"C"}};

    cout << "Map sorted by key (default ascending):\n";
    for (auto x : m)
        cout << x.first << " -> " << x.second << "\n";
    cout << "\n";

    // (a) Map with keys in descending order
    map<int, string, greater<int>> m2 = {{2,"B"}, {1,"A"}, {3,"C"}};
    cout << "Map sorted by key (descending):\n";
    for (auto x : m2)
        cout << x.first << " -> " << x.second << "\n";
    cout << "\n";

    // -----------------------------------
    // 3️⃣ Sort map by values
    // -----------------------------------
    map<int, int> m3 = {{1, 50}, {2, 30}, {3, 40}};
    vector<pair<int,int>> vec(m3.begin(), m3.end());

    cout << "Original map elements:\n";
    for (auto p : vec)
        cout << p.first << " -> " << p.second << "\n";
    cout << "\n";

    // (a) Sort by value ascending
    sort(vec.begin(), vec.end(), [](pair<int,int> a, pair<int,int> b) {
        return a.second < b.second;
    });
    cout << "Map sorted by value (ascending):\n";
    for (auto p : vec)
        cout << p.first << " -> " << p.second << "\n";
    cout << "\n";

    // (b) Sort by value descending
    sort(vec.begin(), vec.end(), [](pair<int,int> a, pair<int,int> b) {
        return a.second > b.second;
    });
    cout << "Map sorted by value (descending):\n";
    for (auto p : vec)
        cout << p.first << " -> " << p.second << "\n";
    cout << "\n";

    return 0;
}
