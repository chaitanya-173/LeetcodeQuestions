class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.length();
        int m = str2.length();

        // Step 1: Build LCS dp table
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (str1[i-1] == str2[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        // Step 2: Backtrack to get the LCS string
        string lcs = "";
        int i = n, j = m;
        while (i > 0 && j > 0) {
            if (str1[i-1] == str2[j-1]) {
                lcs += str1[i-1];
                i--; j--;
            } 
            else if (dp[i-1][j] > dp[i][j-1]) {
                i--;
            } 
            else {
                j--;
            }
        }
        reverse(lcs.begin(), lcs.end());

        // Step 3: Merge using LCS
        string ans = "";
        i = 0; j = 0;
        for (char c : lcs) {
            while (i < n && str1[i] != c) {
                ans += str1[i++];
            }
            while (j < m && str2[j] != c) {
                ans += str2[j++];
            }
            ans += c; // add the common char once
            i++;
            j++;
        }
        // Append remaining parts
        ans += str1.substr(i);
        ans += str2.substr(j);

        return ans;
    }
};
