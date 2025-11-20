class Solution {
public:
    int f(int i, int amt, vector<int> &arr, vector<vector<int>> &dp) {
        if(i == 0) {
            if(amt % arr[0] == 0) return amt / arr[0];
            return 1e9;
        }

        if(dp[i][amt] != -1) return dp[i][amt];

        int notPick = f(i-1, amt, arr, dp);
        int pick = (arr[i] <= amt ? 1 + f(i, amt - arr[i], arr, dp): 1e9);
        return dp[i][amt] = min(notPick, pick);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ans = f(n-1, amount, coins, dp);
        return (ans >= 1e9 ? -1 : ans);
    }
};