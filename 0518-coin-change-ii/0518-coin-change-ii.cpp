class Solution {
public:
    int f(int i, int amt, vector<int> &coins, vector<vector<int>> &dp) {
        // base case
        if(i == 0) {
            if(amt % coins[0] == 0) return 1;
            return 0;
        }

        if(dp[i][amt] != -1) return dp[i][amt];

        int notPick = f(i-1, amt, coins, dp);
        int pick = (coins[i] <= amt ? f(i, amt - coins[i], coins, dp) : 0);

        return dp[i][amt] = notPick + pick;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        return f(n-1, amount, coins, dp);
    }
};