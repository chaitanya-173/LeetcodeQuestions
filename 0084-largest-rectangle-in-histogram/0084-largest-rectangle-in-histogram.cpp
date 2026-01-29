class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int maxArea = 0;

        for(int i = 0; i <= n; i++) {
            int cur = (i == n ? 0 : heights[i]);

            while(!st.empty() && heights[st.top()] > cur) {
                int h = heights[st.top()];
                st.pop();

                int pse = st.empty() ? -1 : st.top();
                int nse = i;

                maxArea = max(maxArea, h * (nse - pse - 1));
            }
            st.push(i);
        }
        return maxArea;
    }
};
