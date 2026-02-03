class Solution {
// private:
//     int f(int i, int j, string &s1, string &s2, int n, int m, vector<vector<int>> &dp) {
//         if(i == n) return m - j;
//         if(j == m) return n - i;

//         if(dp[i][j] != -1) return dp[i][j];

//         if(s1[i] == s2[j]) return dp[i][j] = f(i+1, j+1, s1, s2, n, m, dp);

//         return dp[i][j] = 1 + min(f(i+1, j+1, s1, s2, n, m, dp), min(f(i+1, j, s1, s2, n, m, dp), f(i, j+1, s1, s2, n, m, dp)));
//     }

public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));


        
        for(int i=n; i>=0; i--) {
            for(int j=m; j>=0; j--) {
                if(i == n) dp[i][j] = m - j;
                else if(j == m) dp[i][j] = n - i;
                else {
                    if(word1[i] == word2[j]) dp[i][j] = dp[i+1][j+1];
                    else dp[i][j] = 1 + min(dp[i+1][j+1], min(dp[i+1][j], dp[i][j+1]));
                }
            }
        }

        return dp[0][0];
    }
};