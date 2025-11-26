class Solution {
public:
    // int f(int i, int j, string a, string b, vector<vector<int>> &dp) {
    //     if(i < 0 || j < 0) return 0;

    //     if(dp[i][j] != -1) return dp[i][j];

    //     if(a[i] == b[j]) return dp[i][j] = 1 + f(i-1, j-1, a, b, dp);

    //     return dp[i][j] = max(f(i-1, j, a, b, dp), f(i, j-1, a, b, dp));
    // }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<int> prev(m+1, 0), curr(m+1, 0);

        for(int i=0; i<=n; i++) {
            for(int j=0; j<=m; j++) {
                if(i == 0 || j == 0) curr[j] = 0;
                else {
                    if(text1[i-1] == text2[j-1]) curr[j] = 1 + prev[j-1];
                    else curr[j] = max(prev[j], curr[j-1]);
                }
            }
            prev = curr;
        }

        return prev[m];
    }
};