class Solution {
public:
    int dist(int a, int b) {
        if(a == -1) return 0;
        int x1 = a / 6, y1 = a % 6;
        int x2 = b / 6, y2 = b % 6;
        return abs(x1 - x2) + abs(y1 - y2);
    }

    int f(int i, int f1, int f2, string &word, vector<vector<vector<int>>> &dp) {
        if(i == word.size()) return 0;

        if(dp[i][f1+1][f2+1] != -1) return dp[i][f1+1][f2+1];

        int curr = word[i] - 'A';

        int op1 = dist(f1, curr) + f(i+1, curr, f2, word, dp); // use f1
        int op2 = dist(f2, curr) + f(i+1, f1, curr, word, dp); // use f2

        return dp[i][f1+1][f2+1] = min(op1, op2);
    }

    int minimumDistance(string word) {
        int n = word.size();

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(27, vector<int>(27, -1)));

        return f(0, -1, -1, word, dp);
    }
};