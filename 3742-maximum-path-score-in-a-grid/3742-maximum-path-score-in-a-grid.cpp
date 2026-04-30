class Solution {
private:
    // int solve(int i, int j, int cost, int k, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp) {
    //     int n = grid.size();
    //     int m = grid[0].size();

    //     if(i >= n || j >= m) return -1e9;
    //     if(i == n-1 && j == m-1) return 0;

    //     if(dp[i][j][cost] != -1) return dp[i][j][cost];

    //     int score = -1e9;

    //     // right
    //     if(j+1 < m) {
    //         int val = grid[i][j+1];
    //         int newCost = cost + (val == 0 ? 0 : 1);
    //         if(newCost <= k) score = max(score, val + solve(i, j+1, newCost, k, grid, dp));
    //     }

    //     // down
    //     if(i+1 < n) {
    //         int val = grid[i+1][j];
    //         int newCost = cost + (val == 0 ? 0 : 1);
    //         if(newCost <= k) score = max(score, val + solve(i+1, j, newCost, k, grid, dp));
    //     }

    //     return dp[i][j][cost] = score;
    // }

public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (m, vector<int>(k+1, -1e9)));

        // base case
        for(int cost = 0; cost <= k; cost++) {
            dp[n-1][m-1][cost] = 0;
        }

        for(int i = n-1; i >= 0; i--) {
            for(int j = m-1; j >= 0; j--) {
                if (i == n - 1 && j == m - 1) continue;

                for(int cost = k; cost >= 0; cost--) {
                    int score = -1e9;
                    // right
                    if(j+1 < m) {
                        int val = grid[i][j+1];
                        int newCost = cost + (val == 0 ? 0 : 1);
                        if(newCost <= k) score = max(score, val + dp[i][j+1][newCost]);
                    }

                    // down
                    if(i+1 < n) {
                        int val = grid[i+1][j];
                        int newCost = cost + (val == 0 ? 0 : 1);
                        if(newCost <= k) score = max(score, val + dp[i+1][j][newCost]);
                    }
                    dp[i][j][cost] = score;
                }
            }
        }

        int ans = dp[0][0][0];
        return (ans < 0 ? -1 : ans);
    }
};