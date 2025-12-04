#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
    int maxArea = 0;
    int n = heights.size();

    for (int i = 0; i < n; ++i) {
        int height = heights[i];
        int left = i, right = i;

        // Expand to the left
        while (left > 0 && heights[left - 1] >= height)
            left--;

        // Expand to the right
        while (right < n - 1 && heights[right + 1] >= height)
            right++;

        int width = right - left + 1;
        int area = height * width;
        maxArea = max(maxArea, area);
    }

    return maxArea;
}
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    vector<int> prevSmaller(n), nextSmaller(n);
    stack<int> st;

    // 1. Find Previous Smaller Element for each bar
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && heights[st.top()] >= heights[i])
            st.pop();
        prevSmaller[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }

    // Clear the stack for next use
    while (!st.empty()) st.pop();

    // 2. Find Next Smaller Element for each bar
    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() && heights[st.top()] >= heights[i])
            st.pop();
        nextSmaller[i] = st.empty() ? n : st.top();
        st.push(i);
    }

    // 3. Compute max area using formula
    int maxArea = 0;
    for (int i = 0; i < n; ++i) {
        int width = nextSmaller[i] - prevSmaller[i] - 1;
        int area = heights[i] * width;
        maxArea = max(maxArea, area);
    }

    return maxArea;
}

int main() {
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    cout << "Largest Rectangle Area (Brute Force): " << largestRectangleArea(heights) << endl;
    return 0;
}
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
    stack<int> st;
    heights.push_back(0); // Sentinel
    int maxArea = 0;
    
    for(int i = 0; i < heights.size(); i++){
        while(!st.empty() && heights[i] < heights[st.top()]){
            int h = heights[st.top()]; st.pop();
            int w = st.empty() ? i : i - st.top() - 1;
            maxArea = max(maxArea, h * w);
        }
        st.push(i);
    }
    
    return maxArea;
}

int main() {
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    cout << "Largest Rectangle Area: " << largestRectangleArea(heights) << endl;
    return 0;
}
