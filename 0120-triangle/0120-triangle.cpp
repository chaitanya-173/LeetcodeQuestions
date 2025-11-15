class Solution {
public:
    // int f(int i, int j, vector<vector<int>> &arr, vector<vector<int>> &dp) {
    //     if(i == 0 && j == 0) return arr[0][0];
    //     if(j < 0 || j > i) return 1e9;

    //     if(dp[i][j] != -1) return dp[i][j];

    //     int top = f(i-1, j, arr, dp);
    //     int topLeft = f(i-1, j-1, arr, dp);
    //     return dp[i][j] = arr[i][j] + min(top, topLeft);
    // }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, 1e9));
        dp[0][0] = triangle[0][0];

        for(int i=1; i<n; i++) {
            for(int j=0; j<=i; j++) {
                int top = 1e9, topLeft = 1e9;
                if(j <= i-1) top = dp[i-1][j];
                if(j > 0) topLeft = dp[i-1][j-1];
                dp[i][j] = triangle[i][j] + min(top, topLeft);
            }
        }

        int mini = INT_MAX;
        for(int j=0; j<n; j++) {
            mini = min(mini, dp[n-1][j]);
        }
        return mini;
    }
};