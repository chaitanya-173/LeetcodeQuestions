class Solution {
// private:
//     int f(int i, int j, int m, int n, vector<vector<int>> &dp) {
//         if(i == m-1 && j == n-1) return 1;
//         if(i >= m || j >= n) return 0;

//         if(dp[i][j] != -1) return dp[i][j];

//         return dp[i][j] = f(i+1, j, m, n, dp) + f(i, j+1, m, n, dp);
//     }

public:
    int uniquePaths(int m, int n) {
        vector<int> next(n+1, 1), cur(n+1, 1);

        for(int i = m-2; i >= 0; i--) {
            for(int j = n-2; j >= 0; j--) {
                cur[j] = next[j] + cur[j+1];
            }
            next = cur;
        }

        return next[0];
    }
};