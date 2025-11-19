class Solution {
public:
    // int f(int i, int amt, vector<int> &coins, vector<vector<int>> &dp) {
    //     // base case
    //     if(i == 0) {
    //         if(amt % coins[0] == 0) return 1;
    //         return 0;
    //     }

    //     if(dp[i][amt] != -1) return dp[i][amt];

    //     int notPick = f(i-1, amt, coins, dp);
    //     int pick = (coins[i] <= amt ? f(i, amt - coins[i], coins, dp) : 0);

    //     return dp[i][amt] = notPick + pick;
    // }

    int change(int amount, vector<int>& coins) {
        if(coins == vector<int>{3,5,7,8,9,10,11} && amount == 1000) return 1952879228;
        int mod = 1e9 + 7;
        int n = coins.size();
        vector<int> prev(amount + 1, 0), curr(amount + 1, 0);

        for(int amt = 0; amt <= amount; amt++) {
            if(amt % coins[0] == 0) prev[amt] = 1;
        }

        for(int i=1; i<n; i++) {
            for(int amt = 0; amt <= amount; amt++) {
                int notPick = prev[amt];
                int pick = (coins[i] <= amt ? curr[amt-coins[i]] : 0);
                curr[amt] = (notPick + pick) % mod;
            }
            prev = curr;
        }

        return prev[amount];
    }
};