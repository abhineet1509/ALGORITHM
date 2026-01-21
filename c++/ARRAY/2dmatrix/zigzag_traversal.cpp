#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
     //zigzag conversion
     string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.size()) return s;

        vector<string> rows(numRows);
        int cur = 0;
        bool down = true;

        for (char c : s) {
            rows[cur] += c;
            if (cur == 0) down = true;
            else if (cur == numRows - 1) down = false;
            cur += down ? 1 : -1;
        }

        string ans;
        for (auto &r : rows) ans += r;
        return ans;
    }
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        int m = grid.size();
        bool visit = true;     // track visit or skip
        vector<int> result;

        for (int i = 0; i < m; i++) {
            int n = grid[i].size();

            // If the row is odd, traverse right-to-left
            if (i % 2 == 1) {
                for (int j = n - 1; j >= 0; j--) {
                    if (visit) result.push_back(grid[i][j]);
                    visit = !visit;
                }
            } else { // even row, left-to-right
                for (int j = 0; j < n; j++) {
                    if (visit) result.push_back(grid[i][j]);
                    visit = !visit;
                }
            }
        }
        return result;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> grid1 = {{1,2},{3,4}};
    vector<vector<int>> grid2 = {{2,1},{2,1},{2,1}};
    vector<vector<int>> grid3 = {{1,2,3},{4,5,6},{7,8,9}};

    vector<int> ans1 = sol.zigzagTraversal(grid1);
    vector<int> ans2 = sol.zigzagTraversal(grid2);
    vector<int> ans3 = sol.zigzagTraversal(grid3);

    // Print results
    for (int x : ans1) cout << x << " ";
    cout << endl;

    for (int x : ans2) cout << x << " ";
    cout << endl;

    for (int x : ans3) cout << x << " ";
    cout << endl;

    return 0;
}
