class Solution {
private:
    int f(int i, int j, string &s, string &t, int n, int m, vector<vector<int>> &dp) {
        if(j == m) return 1;
        if(i == n) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == t[j]) return dp[i][j] = f(i+1, j, s, t, n, m, dp) + f(i+1, j+1, s, t, n, m, dp);
        return dp[i][j] = f(i+1, j, s, t, n, m, dp);
    }

public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<unsigned long long> next(m+1, 0), cur(m+1, 0);

        next[m] = 1;
        cur[m] = 1;

        for(int i=n-1; i>=0; i--) {
            for(int j=m-1; j>=0; j--) {
                if(s[i] == t[j]) cur[j] = next[j] + next[j+1];
                else cur[j] = next[j];
            }
            next = cur;
        }

        return next[0];
    }
};