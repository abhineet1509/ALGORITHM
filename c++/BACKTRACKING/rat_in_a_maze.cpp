#include <iostream>
#include <vector>
#include <string>
using namespace std;

int row[4] = {1, 0, 0, -1}; 
int col[4] = {0, -1, 1, 0};
string dir = "DLRU";


bool isValid(int i, int j, int n, vector<vector<int>> &maze, vector<vector<bool>> &visited) {
    return i >= 0 && j >= 0 && i < n && j < n && maze[i][j] == 1 && !visited[i][j];
}


void solveMaze(vector<vector<int>> &maze, int i, int j, int n, vector<vector<bool>> &visited, string &path, vector<string> &paths) {
    // Base case
    if (i == n - 1 && j == n - 1) {
        paths.push_back(path);
        return;
    }

    // current cell
    visited[i][j] = true;

    // sare directions
    for (int k = 0; k < 4; k++) {
        int ni = i + row[k];
        int nj = j + col[k];

        if (isValid(ni, nj, n, maze, visited)) {
            path.push_back(dir[k]);
            solveMaze(maze, ni, nj, n, visited, path, paths);
            path.pop_back(); // Backtrack
        }
    }

    // jo visited nhi hai use unmark kro
    visited[i][j] = false;
}


vector<string> findPaths(vector<vector<int>> &maze) {
    int n = maze.size();
    vector<string> paths;
    if (maze[0][0] == 0 || maze[n - 1][n - 1] == 0) return paths; 

    vector<vector<bool>> visited(n, vector<bool>(n, false));
    string path;

    solveMaze(maze, 0, 0, n, visited, path, paths);
    return paths;
}

int main() {
    int n;
    cin>>n;
    vector<vector<int>> maze(n, vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>maze[i][j];
        }
    }
   

    vector<string> result = findPaths(maze);

    if (result.empty()) {
        cout << "No path found!" << endl;
    } else {
        cout << "Paths: " << endl;
        for (const string &path : result) {
            cout << path << endl;
        }
    }

    return 0;
}
