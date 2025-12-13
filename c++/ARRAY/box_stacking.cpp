#include <bits/stdc++.h>
using namespace std;

struct Box {
    int h, w, d;
};

bool cmp(Box a, Box b) {
    return (a.w * a.d) > (b.w * b.d); // decreasing base area
}

int maxStackHeight(vector<Box>& boxes) {
    vector<Box> allBoxes;

    for(auto box : boxes){
        int h = box.h, w = box.w, d = box.d;
        // all rotations, width >= depth
        allBoxes.push_back({h, max(w,d), min(w,d)});
        allBoxes.push_back({w, max(h,d), min(h,d)});
        allBoxes.push_back({d, max(h,w), min(h,w)});
    }

    sort(allBoxes.begin(), allBoxes.end(), cmp);

    int n = allBoxes.size();
    vector<int> dp(n);
    for(int i=0;i<n;i++) dp[i] = allBoxes[i].h;

    int maxHeight = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(allBoxes[i].w < allBoxes[j].w && allBoxes[i].d < allBoxes[j].d){
                dp[i] = max(dp[i], dp[j] + allBoxes[i].h);
            }
        }
        maxHeight = max(maxHeight, dp[i]);
    }

    return maxHeight;
}

int main() {
    vector<Box> boxes = {
        {4,6,7},
        {1,2,3},
        {4,5,6},
        {10,12,32}
    };

    cout << "Maximum stack height: " << maxStackHeight(boxes) << endl; // Output example
    return 0;
}
