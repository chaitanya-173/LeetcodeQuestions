class Solution {
public:
    // int f(int i, int amt, vector<int> &arr, vector<vector<int>> &dp) {
    //     if(i == 0) {
    //         if(amt % arr[0] == 0) return amt / arr[0];
    //         return 1e9;
    //     }

    //     if(dp[i][amt] != -1) return dp[i][amt];

    //     int notPick = f(i-1, amt, arr, dp);
    //     int pick = (arr[i] <= amt ? 1 + f(i, amt - arr[i], arr, dp): 1e9);
    //     return dp[i][amt] = min(notPick, pick);
    // }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> prev(amount + 1, 1e9), curr(amount + 1, 1e9);

        for(int amt = 0; amt <= amount; amt++) {
            if(amt % coins[0] == 0) prev[amt] = amt / coins[0];
        }

        for(int i=1; i<n; i++) {
            for(int amt = 0; amt <= amount; amt++) {
                int notPick = prev[amt];
                int pick = (coins[i] <= amt ? 1 + curr[amt - coins[i]] : 1e9);
                curr[amt] = min(notPick, pick);
            }
            prev = curr;
        }

        return (prev[amount] >= 1e9 ? -1 : prev[amount]);
    }
};