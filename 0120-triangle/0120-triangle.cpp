class Solution {
public:
    int f(int i, int j, vector<vector<int>> &arr, vector<vector<int>> &dp) {
        if(i == 0 && j == 0) return arr[0][0];
        if(j < 0 || j > i) return 1e9;

        if(dp[i][j] != -1) return dp[i][j];

        int top = f(i-1, j, arr, dp);
        int topLeft = f(i-1, j-1, arr, dp);
        return dp[i][j] = arr[i][j] + min(top, topLeft);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        int mini = INT_MAX;
        for(int j = 0; j < n; j++) {
            mini = min(mini, f(n-1, j, triangle, dp));
        }
        return mini;
    }
};