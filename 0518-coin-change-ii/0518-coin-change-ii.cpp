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
        using ull = unsigned long long;
        int n = coins.size();
        vector<vector<ull>> dp(n+1, vector<ull>(amount+1, 0));

        for(int i=0; i<=n; i++) dp[i][0] = 1;
        for(int i=n-1; i>=0; i--) {
            for(int amt = 0; amt <= amount; amt++) {
                ull notPick = dp[i+1][amt];
                ull pick = (coins[i] <= amt ? dp[i][amt - coins[i]] : 0);

                dp[i][amt] = notPick + pick;
            }
        }

        return dp[0][amount];
    }
};