#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Check if it's safe to color vertex 'node' with color 'c'
    bool isSafe(int node, int color[], bool graph[101][101], int n, int c) {
        for (int k = 0; k < n; k++) {
            if (graph[node][k] && color[k] == c)
                return false;
        }
        return true;
    }

    // Backtracking function to try coloring
    bool solve(int node, int color[], int m, int n, bool graph[101][101]) {
        if (node == n) return true; // All nodes colored

        for (int c = 1; c <= m; c++) {
            if (isSafe(node, color, graph, n, c)) {
                color[node] = c;

                if (solve(node + 1, color, m, n, graph))
                    return true;

                color[node] = 0; // backtrack
            }
        }
        return false;
    }

    // Main function to be called
    bool graphColoring(bool graph[101][101], int m, int n) {
        int color[101] = {0}; // Initially all vertices uncolored

        return solve(0, color, m, n, graph);
    }
};

int main() {
    Solution obj;

    // Example: 4 vertices, 3 colors
    int n = 4, m = 3;
    bool graph[101][101] = {0};

    // Undirected edges
    graph[0][1] = graph[1][0] = 1;
    graph[0][2] = graph[2][0] = 1;
    graph[1][2] = graph[2][1] = 1;
    graph[1][3] = graph[3][1] = 1;

    if (obj.graphColoring(graph, m, n))
        cout << "Coloring possible\n";
    else
        cout << "Coloring not possible\n";

    return 0;
}
