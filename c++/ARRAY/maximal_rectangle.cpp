#include <bits/stdc++.h>
using namespace std;

// Largest Rectangle in Histogram
int largestRectangleArea(vector<int>& heights) {
    stack<int> st;
    heights.push_back(0); // Sentinel
    int maxArea = 0;
    
    for(int i = 0; i < heights.size(); i++){
        while(!st.empty() && heights[i] < heights[st.top()]){
            int h = heights[st.top()]; st.pop();
            // int side = min(h, w);  for square, side = min(height, width)
            int w = st.empty() ? i : i - st.top() - 1;
            maxArea = max(maxArea, h * w);
        }
        st.push(i);
    }
    //   heights.pop_back();
    return maxArea;
}

int maximalRectangleOptimized(vector<vector<char>>& matrix) {
    if(matrix.empty()) return 0;
    int n = matrix.size(), m = matrix[0].size();
    vector<int> heights(m, 0);
    int maxArea = 0;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            heights[j] = (matrix[i][j] == '1') ? heights[j] + 1 : 0;
        }
        maxArea = max(maxArea, largestRectangleArea(heights));
    }
    
    return maxArea;
}

int main() {
    vector<vector<char>> matrix = {
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'}
    };
    cout << "Optimized Maximal Rectangle Area: " << maximalRectangleOptimized(matrix) << endl;
    return 0;
}
