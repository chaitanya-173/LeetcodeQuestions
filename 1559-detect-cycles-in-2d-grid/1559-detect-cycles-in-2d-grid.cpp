class Solution {
    vector<int> dr = {-1, 0, 1, 0};
    vector<int> dc = {0, 1, 0, -1};

    bool dfs(int r, int c, int parr, int parc, vector<vector<char>> &grid, vector<vector<int>> &vis) {
        int n = grid.size();
        int m = grid[0].size();

        vis[r][c] = 1;
        for(int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc] == grid[r][c]) {
                if(vis[nr][nc] && !(nr == parr && nc == parc)) return true;
                else if(!vis[nr][nc]) {
                    if(dfs(nr, nc, r, c, grid, vis)) return true;
                }
            }
        }

        return false;
    }

public:
    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!vis[i][j]) {
                    if(dfs(i, j, -1, -1, grid, vis)) return true;
                }
            }
        }

        return false;
    }
};