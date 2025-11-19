class Solution {
public:
    int f(int i, int amt, vector<int> &coins, vector<vector<int>> &dp) {
        if(i == 0) {
            if(amt % coins[0] == 0) return amt / coins[0];
            return 1e9;
        }

        if(dp[i][amt] != -1) return dp[i][amt];

        int notPick = f(i-1, amt, coins, dp);
        int pick = (coins[i] <= amt ? 1 + f(i, amt - coins[i], coins, dp) : 1e9);
        
        return dp[i][amt] = min(notPick, pick);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, 1e9));

        for(int amt=0; amt<=amount; amt++) {
            if(amt % coins[0] == 0) dp[0][amt] = amt / coins[0];
        }

        for(int i=1; i<n; i++) {
            for(int amt=0; amt<=amount; amt++) {
                int notPick = dp[i-1][amt];
                int pick = (coins[i] <= amt ? 1 + dp[i][amt - coins[i]] : 1e9);
                dp[i][amt] = min(notPick, pick);
            }
        }

        return (dp[n-1][amount] >= 1e9 ? -1 : dp[n-1][amount]);
    }
};