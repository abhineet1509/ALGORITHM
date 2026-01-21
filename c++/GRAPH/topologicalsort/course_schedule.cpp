#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Create adjacency list
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        
        for (auto& pair : prerequisites) {
            int course = pair[0];
            int prereq = pair[1];
            adj[prereq].push_back(course);
            indegree[course]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        int count = 0; 

        while (!q.empty()) {
            int current = q.front();
            q.pop();
            count++;

            for (int neighbor : adj[current]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        return count == numCourses; 
    }
};

// Example usage
int main() {
    Solution sol;

    int numCourses = 4;
    vector<vector<int>> prerequisites = {{1, 0}, {2, 1}, {3, 2}}; // Sample input

    if (sol.canFinish(numCourses, prerequisites)) {
        cout << "Yes, you can finish all courses.\n";
    } else {
        cout << "No, you can't finish all courses.\n";
    }

    return 0;
}
