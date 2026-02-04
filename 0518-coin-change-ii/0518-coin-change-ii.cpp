class Solution {
private:    
    int f(int i, int amt, vector<int> &coins, int n, vector<vector<int>> &dp) {
        if(amt == 0) return 1;
        if(i == n) return 0;

        if(dp[i][amt] != -1) return dp[i][amt];

        int notPick = f(i+1, amt, coins, n, dp);
        int pick = (coins[i] <= amt ? f(i, amt - coins[i], coins, n, dp) : 0);

        return dp[i][amt] = notPick + pick;
    }

public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        return f(0, amount, coins, n, dp);
    }
};