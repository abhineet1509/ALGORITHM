#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

string alienOrder(vector<string>& words) {
    unordered_map<char, unordered_set<char>> adj;
    unordered_map<char, int> inDegree;

    // Initialize inDegree for all characters
    for (auto& word : words) {
        for (char c : word)
            inDegree[c] = 0;
    }

    // Build graph
    for (int i = 0; i < words.size() - 1; ++i) {
        string w1 = words[i];
        string w2 = words[i + 1];
        int len = min(w1.length(), w2.length());

        // Check for invalid case like: ["abc", "ab"]
        if (w1.length() > w2.length() && w1.substr(0, len) == w2.substr(0, len))
            return "";

        for (int j = 0; j < len; ++j) {
            if (w1[j] != w2[j]) {
                if (!adj[w1[j]].count(w2[j])) {
                    adj[w1[j]].insert(w2[j]);
                    inDegree[w2[j]]++;
                }
                break;
            }
        }
    }

    // Topological Sort (Kahn's Algo)
    queue<char> q;
    for (auto& pair : inDegree) {
        if (pair.second == 0)
            q.push(pair.first);
    }

    string result;
    while (!q.empty()) {
        char c = q.front();
        q.pop();
        result += c;

        for (char neighbor : adj[c]) {
            if (--inDegree[neighbor] == 0)
                q.push(neighbor);
        }
    }

    // If result length doesn't match total characters → cycle exists
    return result.length() == inDegree.size() ? result : "";
}
int main() {
    vector<string> words = {"wrt", "wrf", "er", "ett", "rftt"};
    string order = alienOrder(words);
    if (order == "")
        cout << "Invalid alien dictionary (cycle or conflict)\n";
    else
        cout << "Alien Order: " << order << endl;
    return 0;
}
