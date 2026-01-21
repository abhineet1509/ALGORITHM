#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2,
                    int bx1, int by1, int bx2, int by2) {

        // Area of rectangle A
        int areaA = (ax2 - ax1) * (ay2 - ay1);

        // Area of rectangle B
        int areaB = (bx2 - bx1) * (by2 - by1);

        // Overlapping width
        int overlapWidth = max(0, min(ax2, bx2) - max(ax1, bx1));

        // Overlapping height
        int overlapHeight = max(0, min(ay2, by2) - max(ay1, by1));

        // Overlapping area
        int overlapArea = overlapWidth * overlapHeight;

        // Total area
        return areaA + areaB - overlapArea;
    }
};

// -------- Driver Code --------
int main() {
    Solution sol;

    // Example input
    int ax1 = -3, ay1 = 0, ax2 = 3, ay2 = 4;
    int bx1 = 0,  by1 = -1, bx2 = 9, by2 = 2;

    cout << sol.computeArea(ax1, ay1, ax2, ay2,
                            bx1, by1, bx2, by2) << endl;

    return 0;
}
