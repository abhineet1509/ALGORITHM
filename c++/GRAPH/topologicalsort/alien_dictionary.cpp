#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

string findOrder(string dict[], int N, int K) {
    // Step 1: Build adjacency list
    vector<int> adj[K];

    for (int i = 0; i < N - 1; i++) {
        string word1 = dict[i];
        string word2 = dict[i + 1];
        int len = min(word1.length(), word2.length());

        for (int j = 0; j < len; j++) {
            if (word1[j] != word2[j]) {
                adj[word1[j] - 'a'].push_back(word2[j] - 'a');
                break; // Only first difference matters
            }
        }
    }

    // Step 2: Compute in-degrees
    vector<int> inDegree(K, 0);
    for (int u = 0; u < K; u++) {
        for (int v : adj[u]) {
            inDegree[v]++;
        }
    }

    // Step 3: Topological sort using BFS (Kahn's algorithm)
    queue<int> q;
    for (int i = 0; i < K; i++) {
        if (inDegree[i] == 0)
            q.push(i);
    }

    string result = "";
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        result += (char)(u + 'a');

        for (int v : adj[u]) {
            inDegree[v]--;
            if (inDegree[v] == 0)
                q.push(v);
        }
    }

    return result;
}

// 🔍 Sample usage:
int main() {
    int N = 5, K = 4;
    string dict[] = {"baa", "abcd", "abca", "cab", "cad"};

    string order = findOrder(dict, N, K);
    cout << "Alien Dictionary Order: " << order << endl;

    return 0;
}
