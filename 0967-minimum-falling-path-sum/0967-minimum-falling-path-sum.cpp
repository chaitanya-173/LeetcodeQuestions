class Solution {
public:
    // int f(int i, int j, int n, vector<vector<int>> &arr, vector<vector<int>> &dp) {
    //     if(i < 0 || j < 0 || j >= n) return 1e9;
    //     if(i == 0) return arr[i][j];

    //     if(dp[i][j] != 1e9) return dp[i][j];

    //     int top = f(i-1, j, n, arr, dp);
    //     int topLeft = f(i-1, j-1, n, arr, dp);
    //     int topRight = f(i-1, j+1, n, arr, dp);

    //     return dp[i][j] = arr[i][j] + min(top, min(topLeft, topRight));
    // }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> prevRow(n, 1e9);

        for(int i=0; i<n; i++) {
            vector<int> currRow(n, 1e9);
            for(int j=0; j<n; j++) {
                if(i == 0) currRow[j] = matrix[i][j];
                else {
                    int top = 1e9, topLeft = 1e9, topRight = 1e9;
                    if(i > 0) top = prevRow[j];
                    if(i > 0 && j > 0) topLeft = prevRow[j-1];
                    if(i > 0 && j+1 < n) topRight = prevRow[j+1];
                    currRow[j] = matrix[i][j] + min(top, min(topLeft, topRight));
                }
            }
            prevRow = currRow;
        }

        int mini = INT_MAX;
        for(int j=0; j<n; j++) {
            mini = min(mini, prevRow[j]);
        }
        return mini;
    }
};