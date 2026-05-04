class Solution {
public:
    int solve(int n, vector<int> &dp) {
        if(n == 0) return 0; // BC: no need of mroe squares if n=0

        if(dp[n] != -1) return dp[n];

        int ans = n; // to track min. ans

        // try every possible perfect square
        for(int i = 1; i * i <= n; i++) {
            int sq = i * i;

            // recursion for rem. values
            ans = min(ans, 1 + solve(n - sq, dp));
        }

        return dp[n] = ans;
    } 

    int numSquares(int n) {
        // vector<int> dp(n+1, -1);
        // return solve(n, dp);

        vector<int> dp(n+1, n);
        dp[0] = 0;

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j * j <= i; j++) {
                int sq = j * j;
                dp[i] = min(dp[i], 1 + dp[i - sq]);
            }
        }

        return dp[n];
    }
};