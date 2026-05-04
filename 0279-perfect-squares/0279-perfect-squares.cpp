class Solution {
public:
    int solve(int n, vector<int> &dp) {
        // Base case:
        // Agar n = 0 ho gaya, matlab koi number bachha hi nahi,
        // toh aur squares ki zarurat nahi
        if (n == 0) return 0;

        if(dp[n] != -1) return dp[n];

        // Minimum answer track karne ke liye
        int ans = INT_MAX;

        // Har possible perfect square try karo
        // Example: n = 12
        // squares: 1, 4, 9
        for (int i = 1; i * i <= n; i++) {
            int sq = i * i;

            // Current square use kiya (+1)
            // Remaining value ke liye recursion
            ans = min(ans, 1 + solve(n - sq, dp));
        }

        return dp[n] = ans;
    }

    int numSquares(int n) {
        vector<int> dp(n+1, -1);
        return solve(n, dp);
    }
};