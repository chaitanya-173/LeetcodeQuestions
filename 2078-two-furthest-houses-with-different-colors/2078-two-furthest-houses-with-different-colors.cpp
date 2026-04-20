class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int color0 = colors.front(), colorN = colors.back();
        int leftMax = 0, rightMax = 0;

        for(int i = 0; i < n; i++) {
            if(color0 != colors[i]) leftMax = max(leftMax, i);
            if(colorN != colors[i]) rightMax = max(rightMax, n-i-1);
        }

        return max(leftMax, rightMax);
    }
};