class Solution {
private:
    bool f(int ind, int cnt, string &s, vector<vector<int>> &dp) {
        // base case
        if(cnt < 0) return false;
        if(ind == s.size()) return (cnt == 0);

        if(dp[ind][cnt] != -1) return dp[ind][cnt];

        if(s[ind] == '(') return dp[ind][cnt] = f(ind+1, cnt+1, s, dp);
        if(s[ind] == ')') return dp[ind][cnt] = f(ind+1, cnt-1, s, dp);
        return dp[ind][cnt] = f(ind+1, cnt+1, s, dp) || f(ind+1, cnt-1, s, dp) || f(ind+1, cnt, s, dp);
    }
    
public:
    bool checkValidString(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return f(0, 0, s, dp);
    }
};