#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxPoints(vector<vector<int>>& pts) {
        int n = pts.size(), ans = 0;
        for(int i = 0; i < n; i++){
            map<pair<int,int>,int> m;
            int dup = 0, cur = 0;
            for(int j = i+1; j < n; j++){
                int dx = pts[j][0]-pts[i][0], dy = pts[j][1]-pts[i][1];
                if(dx==0 && dy==0){ dup++; continue; }
                int g = __gcd(dy,dx);
                dy/=g; dx/=g;
                m[{dy,dx}]++;
                cur = max(cur, m[{dy,dx}]);
            }
            ans = max(ans, cur+dup+1);
        }
        return ans;
    }
};

int main(){
    vector<vector<int>> points = {{1,1},{2,2},{3,3},{3,4}};
    Solution sol;
    cout << sol.maxPoints(points) << endl; // Output: 3
}
