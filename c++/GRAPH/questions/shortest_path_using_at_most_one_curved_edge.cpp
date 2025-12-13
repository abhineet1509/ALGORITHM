#include <bits/stdc++.h>
using namespace std;

struct Edge { int to, weight; bool curved; };

const long long INF = 1e18;

long long shortestPath(int n, int src, int dest, vector<vector<Edge>>& adj) {
    vector<long long> dist0(n, INF), dist1(n, INF);
    dist0[src] = 0;

    // {distance, node, usedCurvedEdge?}
    priority_queue<tuple<long long,int,bool>, vector<tuple<long long,int,bool>>, greater<>> pq;
    pq.push({0, src, false});

    while(!pq.empty()) {
        auto [d, u, used] = pq.top(); pq.pop();
        if(used && d > dist1[u]) continue;
        if(!used && d > dist0[u]) continue;

        for(auto &e : adj[u]){
            if(!e.curved){
                if(!used && dist0[e.to] > d + e.weight){
                    dist0[e.to] = d + e.weight;
                    pq.push({dist0[e.to], e.to, false});
                }
                if(used && dist1[e.to] > d + e.weight){
                    dist1[e.to] = d + e.weight;
                    pq.push({dist1[e.to], e.to, true});
                }
            } else { // curved edge
                if(!used && dist1[e.to] > d + e.weight){
                    dist1[e.to] = d + e.weight;
                    pq.push({dist1[e.to], e.to, true});
                }
            }
        }
    }

    return min(dist0[dest], dist1[dest]);
}

int main() {
    int n = 5; // nodes 0 to 4
    vector<vector<Edge>> adj(n);

    // normal edges
    adj[0].push_back({1, 2, false});
    adj[1].push_back({2, 3, false});
    adj[0].push_back({3, 6, false});

    // curved edge
    adj[3].push_back({2, 1, true});

    cout << "Shortest path using at most one curved edge: " 
         << shortestPath(n, 0, 2, adj) << endl;
}
