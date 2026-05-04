class Solution {
private:
    bool solve(int ind, string &s, unordered_set<string> &dict, vector<int> &dp) {
        if(ind == s.size()) return true;

        if(dp[ind] != -1) return dp[ind];

        string substr = "";
        for(int i = ind; i < s.size(); i++) {
            substr += s[i];

            if(dict.count(substr) && solve(i+1, s, dict, dp)) {
                return dp[ind] = true;
            }
        }

        return dp[ind] = false;
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int n = s.size();
        vector<int> dp(n+1, 0);
        dp[n] = true;

        for(int ind = n-1; ind >= 0; ind--) {
            string substr = "";
            for(int i = ind; i < s.size(); i++) {
                substr += s[i];

                if(dict.count(substr) && dp[i+1]) {
                    dp[ind] = true;
                    break;
                }
            }
        }


        return dp[0];
    }
};