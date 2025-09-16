class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int,int>> q;

        // traversing first row and last row
        for(int j=0; j<m; j++) {
            // first row
            if(grid[0][j] == 1) {
                q.push({0, j});
                vis[0][j] = 1;
            }
            // last row
            if(grid[n-1][j] == 1) {
                q.push({n-1, j});
                vis[n-1][j] = 1;
            }
        }

        // traversing first col and last col
        for(int i=0; i<n; i++) {
            // first col
            if(grid[i][0] == 1) {
                q.push({i, 0});
                vis[i][0] = 1;
            }
            // last col
            if(grid[i][m-1] == 1) {
                q.push({i, m-1});
                vis[i][m-1] = 1;
            }
        }

        vector<int> drow = {-1, 0, 1, 0};
        vector<int> dcol = {0, 1, 0, -1};

        while(!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i=0; i<4; i++) {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] 
                    && grid[nrow][ncol] == 1) {
                    q.push({nrow, ncol});
                    vis[nrow][ncol] = 1;
                }
            }
        }

        int enclaves = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 1 && vis[i][j] == 0) {
                    enclaves++;
                }
            }
        }

        return enclaves;
    }
};