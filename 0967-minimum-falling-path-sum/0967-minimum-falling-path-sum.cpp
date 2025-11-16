class Solution {
public:
    int f(int i, int j, int n, vector<vector<int>> &arr, vector<vector<int>> &dp) {
        if(i < 0 || j < 0 || j >= n) return 1e9;
        if(i == 0) return arr[i][j];

        if(dp[i][j] != 1e9) return dp[i][j];

        int top = f(i-1, j, n, arr, dp);
        int topLeft = f(i-1, j-1, n, arr, dp);
        int topRight = f(i-1, j+1, n, arr, dp);

        return dp[i][j] = arr[i][j] + min(top, min(topLeft, topRight));
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, 1e9));
        int mini = INT_MAX;
        for(int j=0; j<n; j++) {
            mini = min(mini, f(n-1, j, n, matrix, dp));
        }
        return mini;
    }
};