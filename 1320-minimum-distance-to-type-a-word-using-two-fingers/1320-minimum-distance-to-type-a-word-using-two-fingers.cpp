class Solution {
public:
    int dist(int a, int b) {
        if(a == -1) return 0;
        int x1 = a / 6, y1 = a % 6;
        int x2 = b / 6, y2 = b % 6;
        return abs(x1 - x2) + abs(y1 - y2);
    }

    // int f(int i, int f1, int f2, string &word, vector<vector<vector<int>>> &dp) {
    //     if(i == word.size()) return 0;

    //     if(dp[i][f1+1][f2+1] != -1) return dp[i][f1+1][f2+1];

    //     int cur = word[i] - 'A';

    //     int op1 = dist(f1, cur) + f(i+1, cur, f2, word, dp); // use f1
    //     int op2 = dist(f2, cur) + f(i+1, f1, cur, word, dp); // use f2

    //     return dp[i][f1+1][f2+1] = min(op1, op2);
    // }

    int minimumDistance(string word) {
        int n = word.size();
        vector<vector<int>> next(27, vector<int>(27, 0));
        vector<vector<int>> cur(27, vector<int>(27, 0));

        for(int i = n-1; i >= 0; i--) {
            int c = word[i] - 'A';
            for(int f1 = 25; f1 >= -1; f1--) {
                for(int f2 = 25; f2 >= -1; f2--) {
                    int op1 = dist(f1, c) + next[c+1][f2+1];
                    int op2 = dist(f2, c) + next[f1+1][c+1];
                    cur[f1+1][f2+1] = min(op1, op2);
                }
            }
            next = cur;
        }
        
        return next[0][0];
    }
};