#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Cell {
    int x, y, time;
};

bool isValid(int x, int y, int n, int m, vector<vector<int>> &grid) {
    return (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 1);
}

int covidSpreadTime(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    queue<Cell> q;
    int totalPatients = 0, infectedPatients = 0, maxTime = 0;

    // Initialize the queue with all sources (value 2) and count patients (value 1)
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 2) {
                q.push({i, j, 0}); // Add all sources with time 0
            } else if (grid[i][j] == 1) {
                totalPatients++;
            }
        }
    }

    // BFS for infection spread
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};

    while (!q.empty()) {
        Cell current = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int newX = current.x + dx[i];
            int newY = current.y + dy[i];

            if (isValid(newX, newY, n, m, grid)) {
                grid[newX][newY] = 2; // Infect the patient
                q.push({newX, newY, current.time + 1});
                infectedPatients++;
                maxTime = max(maxTime, current.time + 1);
            }
        }
    }

    // Check if all patients are infected
    return (infectedPatients == totalPatients) ? maxTime : -1;
}

int main() {
    int n, m;
    cout << "Enter the dimensions of the grid (n m): ";
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));
    cout << "Enter the grid values (0 for empty, 1 for patient, 2 for source):\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }

    int result = covidSpreadTime(grid);
    if (result == -1) {
        cout << "Not all patients can be infected.\n";
    } else {
        cout << "Time taken to infect all patients: " << result << "\n";
    }

    return 0;
}
