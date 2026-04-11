class Solution {
private:
    const int mod = 1e9 + 7;

    int f(int n, vector<int> &dp) {
        if(n == 0 || n == 1) return 1;
        if(n == 2) return 2;

        if(dp[n] != -1) return dp[n];

        long long ans = (2LL * f(n-1, dp) + f(n-3, dp)) % mod;
        return dp[n] = ans;
    }

public:
    int numTilings(int n) {
        vector<int> dp(n+1, -1);
        return f(n, dp);
    }
};