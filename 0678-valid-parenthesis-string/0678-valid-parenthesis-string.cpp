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
        vector<bool> next(n+1, 0), cur(n+1, 0);

        for(int ind=n; ind>=0; ind--) {
            fill(cur.begin(), cur.end(), false); 
            for(int cnt=n; cnt>=0; cnt--) {
                if(ind == n) {
                    cur[cnt] = (cnt == 0); 
                } else if(s[ind] == '(') {
                    if(cnt + 1 <= n) cur[cnt] = next[cnt+1];
                } else if(s[ind] == ')') {
                    if(cnt > 0) cur[cnt] = next[cnt-1];
                } else {
                    bool op1 = (cnt + 1 <= n) ? next[cnt+1] : false; // '('
                    bool op2 = (cnt > 0) ? next[cnt-1] : false;      // ')'
                    bool op3 = next[cnt];                            // empty
                    cur[cnt] = op1 || op2 || op3;
                }
            }
            next = cur;
        }

        return next[0];
    }
};