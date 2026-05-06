class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int n = boxGrid.size();
        int m = boxGrid[0].size();

        vector<vector<char>> ans(m, vector<char>(n));

        // rotate
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                ans[j][n-1-i] = boxGrid[i][j];
            }
        }

        // gravity implementation
        for(int j = 0; j < n; j++) {
            int blank = m-1; // lowest empty spot

            for(int i = m-1; i >= 0; i--) {
                if(ans[i][j] == '*') {
                    blank = i-1; // reset after obstacle
                }
                else if(ans[i][j] == '#') {
                    swap(ans[i][j], ans[blank][j]);
                    blank--;
                }
            }
        }

        return ans;
    }
};