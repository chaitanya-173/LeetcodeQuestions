class Solution {
private:
    int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    stack<int> st;          // stores indices
    int maxArea = 0;

    for(int i = 0; i <= n; i++) {
        int currHeight = (i == n ? 0 : heights[i]);

        while(!st.empty() && heights[st.top()] > currHeight) {
            int h = heights[st.top()];
            st.pop();

            int right = i;
            int left = st.empty() ? -1 : st.top();
            int width = right - left - 1;

            maxArea = max(maxArea, h * width);
        }
        st.push(i);
    }

    return maxArea;
}

public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int maxi = 0;
        vector<int> height(m, 0);
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(matrix[i][j] == '1') height[j]++;
                else height[j] = 0; 
            }
            maxi = max(maxi, largestRectangleArea(height));
        }

        return maxi;
    }
};