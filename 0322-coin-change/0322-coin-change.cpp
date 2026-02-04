class Solution {
private:
    int f(int i, vector<int> &coins, int amount, int n, vector<vector<int>> &dp) {
        if(amount == 0) return 0;
        if(i == n) return 1e9;

        if(dp[i][amount] != -1) return dp[i][amount];

        int notPick = f(i+1, coins, amount, n, dp);
        int pick = (coins[i] <= amount ? 1 + f(i, coins, amount-coins[i], n, dp) : 1e9);

        return dp[i][amount] = min(notPick, pick);
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        int ans = f(0, coins, amount, n, dp);
        return (ans >= 1e9 ? -1 : ans);
    }
};