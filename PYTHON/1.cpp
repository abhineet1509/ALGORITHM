#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<tuple<int, int, int>> ops;

        // Reverse entire first row
        ops.push_back(make_tuple(1, 1, n));

        // Apply shifts to rows 2 to n
        for (int row = 2; row <= n; ++row) {
            int front_span = n - row + 1;
            int back_start = front_span + 1;

            // Reverse front part
            ops.push_back(make_tuple(row, 1, front_span));

            // Reverse back part if valid
            if (back_start <= n) {
                ops.push_back(make_tuple(row, back_start, n));
            }
        }

        // Output results
        cout << ops.size() << '\n';
        for (size_t i = 0; i < ops.size(); ++i) {
            int row_id, left, right;
            tie(row_id, left, right) = ops[i];
            cout << row_id << ' ' << left << ' ' << right << '\n';
        }
    }

    return 0;
}
