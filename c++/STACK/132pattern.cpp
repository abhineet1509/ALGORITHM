#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return false;

        stack<int> st;
        int third = INT_MIN;  

        for (int i = n - 1; i >= 0; i--) {

          
            if (nums[i] < third)
                return true;

        
            while (!st.empty() && nums[i] > st.top()) {
                third = st.top();   
                st.pop();
            }

            st.push(nums[i]);
        }
        return false;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {3, 1, 4, 2};

    if (sol.find132pattern(nums))
        cout << "True (132 pattern exists)\n";
    else
        cout << "False (No 132 pattern)\n";

    return 0;
}
