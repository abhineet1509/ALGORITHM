#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> dist;
vector<bool> visited;
int res = INT_MAX;

void tsp(int city, int count, int cost) {
    if(count == n) { // visited all cities
        res = min(res, cost + dist[city][0]); // return to start
        return;
    }

    for(int i=0; i<n; i++) {
        if(!visited[i]) {
            visited[i] = true;
            tsp(i, count+1, cost + dist[city][i]);
            visited[i] = false; // backtrack
        }
    }
}

int main() {
    n = 4;
    dist = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    visited.assign(n, false);
    visited[0] = true; // start from city 0
    tsp(0, 1, 0);

    cout << "Minimum cost: " << res << endl; // Output: 80
    return 0;
}
