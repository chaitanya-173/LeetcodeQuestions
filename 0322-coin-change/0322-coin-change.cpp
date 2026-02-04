class Solution {
// private:
//     int f(int i, vector<int> &coins, int amount, int n, vector<vector<int>> &dp) {
//         if(amount == 0) return 0;
//         if(i == n) return 1e9;

//         if(dp[i][amount] != -1) return dp[i][amount];

//         int notPick = f(i+1, coins, amount, n, dp);
//         int pick = (coins[i] <= amount ? 1 + f(i, coins, amount-coins[i], n, dp) : 1e9);

//         return dp[i][amount] = min(notPick, pick);
//     }

public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1, 1e9));

        for(int i=0; i<=n; i++) dp[i][0] = 0;

        for(int i=n-1; i>=0; i--) {
            for(int j=0; j<=amount; j++) {
                int notPick = dp[i+1][j];
                int pick = (coins[i] <= j ? 1 + dp[i][j - coins[i]] : 1e9);
                dp[i][j] = min(notPick, pick);
            }
        }

        return dp[0][amount] == 1e9 ? -1 : dp[0][amount];
    }
};