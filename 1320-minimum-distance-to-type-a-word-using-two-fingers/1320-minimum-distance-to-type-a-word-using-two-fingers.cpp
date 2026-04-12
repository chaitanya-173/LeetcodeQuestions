class Solution {
private:
    int findDist(char ind1, char ind2, unordered_map<char,pair<int,int>> &hash) {
        auto [x1, y1] = hash[ind1];
        auto [x2, y2] = hash[ind2];
        return abs(x1 - x2) + abs(y1 - y2);
    }

    int f(int i, int f1, int f2, string &word,
          unordered_map<char,pair<int,int>> &hash,
          vector<vector<vector<int>>> &dp) {

        if(i == word.size()) return 0;

        if(dp[i][f1+1][f2+1] != -1) return dp[i][f1+1][f2+1];

        int curr = word[i];

        int d1 = (f1 == -1) ? 0 : findDist(f1 + 'A', curr, hash);
        int useF1 = d1 + f(i + 1, curr - 'A', f2, word, hash, dp);

        int d2 = (f2 == -1) ? 0 : findDist(f2 + 'A', curr, hash);
        int useF2 = d2 + f(i + 1, f1, curr - 'A', word, hash, dp);

        return dp[i][f1+1][f2+1] = min(useF1, useF2);
    }

public:
    int minimumDistance(string word) {
        unordered_map<char, pair<int,int>> hash;

        char ch = 'A';
        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 6; j++) {
                hash[ch] = {i, j};
                if(ch == 'Z') break;
                ch++;
            }
        }

        int n = word.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(27, vector<int>(27, -1)));

        return f(0, -1, -1, word, hash, dp);
    }
};