class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> prevRow(m, 0);

        for(int i=0; i<n; i++) {
            vector<int> currRow(m, 0);
            for(int j=0; j<m; j++) {
                if(i == 0 && j == 0) currRow[j] = grid[i][j];
                else {
                    int left = 1e9, top = 1e9;
                    if(j > 0) left = currRow[j-1];
                    if(i > 0) top = prevRow[j];
                    currRow[j] = grid[i][j] + min(left, top);
                }
            }
            prevRow = currRow;
        }

        return prevRow[m-1];
    }
};