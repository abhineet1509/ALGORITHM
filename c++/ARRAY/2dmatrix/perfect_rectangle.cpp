#include <bits/stdc++.h>
using namespace std;

bool isRectangleCover(vector<vector<int>>& rectangles) {
    long long area = 0;
    int minX = INT_MAX, minY = INT_MAX;
    int maxX = INT_MIN, maxY = INT_MIN;

    set<pair<int,int>> st;

    for (auto &r : rectangles) {
        int x1 = r[0], y1 = r[1], x2 = r[2], y2 = r[3];

        area += (long long)(x2 - x1) * (y2 - y1);

        minX = min(minX, x1);
        minY = min(minY, y1);
        maxX = max(maxX, x2);
        maxY = max(maxY, y2);

        pair<int,int> p1 = {x1, y1};
        pair<int,int> p2 = {x1, y2};
        pair<int,int> p3 = {x2, y1};
        pair<int,int> p4 = {x2, y2};

        for (auto p : {p1, p2, p3, p4}) {
            if (st.count(p)) st.erase(p);
            else st.insert(p);
        }
    }

    long long bigArea = (long long)(maxX - minX) * (maxY - minY);

    if (area != bigArea) return false;
    if (st.size() != 4) return false;

    if (!st.count({minX, minY}) ||
        !st.count({minX, maxY}) ||
        !st.count({maxX, minY}) ||
        !st.count({maxX, maxY}))
        return false;

    return true;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> rectangles(n, vector<int>(4));
    for (int i = 0; i < n; i++) {
        cin >> rectangles[i][0] >> rectangles[i][1]
            >> rectangles[i][2] >> rectangles[i][3];
    }

    cout << (isRectangleCover(rectangles) ? "true" : "false");
    return 0;
}
