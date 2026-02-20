class Solution {
public:
    // int f(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp) {
    //     if(i == 0 && j == 0) return grid[i][j];
    //     if(i < 0 || j < 0) return 1e9;

    //     if(dp[i][j] != -1) return dp[i][j];

    //     int left = f(i, j-1, grid, dp);
    //     int top = f(i-1, j, grid, dp);

    //     return dp[i][j] = grid[i][j] + min(left, top);
    // }

    int f(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp, int n, int m) {
        if(i == n-1 && j == m-1) return grid[i][j];
        if(i >= n || j >= m) return 1e9; 

        if(dp[i][j] != -1) return dp[i][j];

        int right = f(i, j+1, grid, dp, n, m);
        int bottom = f(i+1, j, grid, dp, n, m);

        return dp[i][j] = grid[i][j] + min(right, bottom);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(0, 0, grid, dp, n, m);
    }
};