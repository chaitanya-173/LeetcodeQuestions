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
        vector<int> next(m+1, 0), cur(m+1, 0);

        for(int i=n; i>=0; i--) {
            for(int j=m; j>=0; j--) {
                if(i == n) cur[j] = m - j;
                else if(j == m) cur[j] = n - i;
                else {
                    if(word1[i] == word2[j]) cur[j] = next[j+1];
                    else cur[j] = 1 + min(next[j+1], min(next[j], cur[j+1]));
                }
            }
            next = cur;
        }

        return next[0];
    }
};