class Solution {
private:
    // int f(int i, int j, string &s, string &t, vector<vector<int>> &dp) {
    //     if(i == 0) return j;
    //     if(j == 0) return i;

    //     if(dp[i][j] != -1) return dp[i][j];

    //     if(s[i-1] == t[j-1]) return dp[i][j] = f(i-1, j-1, s, t, dp);

    //     return dp[i][j] = 1 + min(
    //         f(i-1, j, s, t, dp),      // delete
    //         min(
    //             f(i, j-1, s, t, dp),  // insert
    //             f(i-1, j-1, s, t, dp) // replace
    //         )
    //     );
    // }

public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<int> prev(m+1, 0), cur(m+1, 0);

        // base case: word1 empty
        for(int j = 0; j <= m; j++) prev[j] = j;

        for(int i = 1; i <= n; i++) {
            cur[0] = i;  // word2 empty

            for(int j = 1; j <= m; j++) {
                if(word1[i-1] == word2[j-1]) {
                    cur[j] = prev[j-1];
                } else {
                    cur[j] = 1 + min(prev[j-1], min(prev[j], cur[j-1]));
                }
            }
            prev = cur;  
        }

        return prev[m];
    }
};
