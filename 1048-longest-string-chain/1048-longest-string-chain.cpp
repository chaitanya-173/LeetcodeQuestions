class Solution {
private:
    bool isPossible(string &s1, string &s2) {
        if(s1.size() != s2.size() + 1) return false;

        int i=0, j=0;
        while(i < s1.size()) {
            if(s1[i] == s2[j] && j < s2.size()) {
                i++, j++;
            } else {
                i++;
            }
        }

        return (i == s1.size() && j == s2.size());
    }

public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), [](string &s1, string &s2) {
            return s1.size() < s2.size();
        });
        
        vector<int> dp(n, 1);
        int maxi = 1;

        for(int i=0; i<n; i++) {
            for(int prev=0; prev<i; prev++) {
                if(isPossible(words[i], words[prev])) {
                    dp[i] = max(dp[i], 1 + dp[prev]);
                }
            }
            maxi = max(maxi, dp[i]);
        }

        return maxi;
    }
};