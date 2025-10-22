#include <bits/stdc++.h>
using namespace std;

class TrappingRainWater {
public:
    //  Brute-Force Approach
    int trapBrute(vector<int>& height) {
        int n = height.size();
        int water = 0;

        for(int i = 0; i < n; i++) {
            int maxLeft = 0, maxRight = 0;

            for(int j = 0; j <= i; j++) maxLeft = max(maxLeft, height[j]);
            for(int j = i; j < n; j++) maxRight = max(maxRight, height[j]);

            water += min(maxLeft, maxRight) - height[i];
        }

        return water;
    }

    // Prefix-Suffix Arrays
    int trapPrefixSuffix(vector<int>& height) {
        int n = height.size();
        if(n == 0) return 0;

        vector<int> leftMax(n), rightMax(n);
        leftMax[0] = height[0];
        for(int i=1; i<n; i++)
            leftMax[i] = max(leftMax[i-1], height[i]);

        rightMax[n-1] = height[n-1];
        for(int i=n-2; i>=0; i--)
            rightMax[i] = max(rightMax[i+1], height[i]);

        int water = 0;
        for(int i=0; i<n; i++)
            water += min(leftMax[i], rightMax[i]) - height[i];

        return water;
    }

    //  Two-Pointer Optimized
    int trapTwoPointer(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int leftMax = 0, rightMax = 0, water = 0;

        while(left <= right) {
            if(height[left] < height[right]) {
                if(height[left] >= leftMax) leftMax = height[left];
                else water += leftMax - height[left];
                left++;
            } else {
                if(height[right] >= rightMax) rightMax = height[right];
                else water += rightMax - height[right];
                right--;
            }
        }

        return water;
    }

    //  Stack Approach
    int trapStack(vector<int>& height) {
        stack<int> st;
        int water = 0, n = height.size();

        for(int i=0; i<n; i++) {
            while(!st.empty() && height[i] > height[st.top()]) {
                int top = st.top();
                st.pop();

                if(st.empty()) break; // no left boundary

                int distance = i - st.top() - 1;
                int bounded_height = min(height[i], height[st.top()]) - height[top];
                water += distance * bounded_height;
            }
            st.push(i);
        }

        return water;
    }
};

int main() {
    TrappingRainWater solver;
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};

    cout << "Water trapped (Brute-Force)   : " << solver.trapBrute(height) << "\n";
    cout << "Water trapped (Prefix-Suffix) : " << solver.trapPrefixSuffix(height) << "\n";
    cout << "Water trapped (Two-Pointer)   : " << solver.trapTwoPointer(height) << "\n";
    cout << "Water trapped (Stack)         : " << solver.trapStack(height) << "\n";

    return 0;
}
