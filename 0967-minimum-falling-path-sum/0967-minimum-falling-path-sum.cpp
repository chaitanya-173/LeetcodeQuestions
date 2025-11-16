class Solution {
public:
    int f(int i, int j, int n, vector<vector<int>> &mat, vector<vector<int>> &dp) {
        // base case
        if(j < 0 || j >= n) return 1e9;
        if(i == n-1) return mat[i][j];
        
        if(dp[i][j] != 1e9) return dp[i][j];
        
        int bottom = f(i+1, j, n, mat, dp);
        int bottomLeft = f(i+1, j-1, n, mat, dp);
        int bottomRight = f(i+1, j+1, n, mat, dp);
        
        return dp[i][j] = mat[i][j] + min(bottom, min(bottomRight, bottomLeft));
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, 1e9));
        int mini = INT_MAX;
        for(int j=0; j<n; j++) {
            mini = min(mini, f(0, j, n, matrix, dp));
        }
        return mini;
    }
};