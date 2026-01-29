class Solution {
public:
    int largestRectangleArea(vector<int>& heights) { 
        int n = heights.size();
        vector<int> nse(n, n);   
        vector<int> pse(n, -1); 
        stack<int> st;

        for(int i=0; i<n; i++) {
            while(!st.empty() && heights[st.top()] >= heights[i]) {
                nse[st.top()] = i;  
                st.pop();
            }
            if(!st.empty()) pse[i] = st.top();  
            
            st.push(i);
        }

        int area = 0;
        for(int i=0; i<n; i++) {
            int width = nse[i] - pse[i] - 1;
            area = max(area, heights[i] * width);
        }
        return area;
    }
};