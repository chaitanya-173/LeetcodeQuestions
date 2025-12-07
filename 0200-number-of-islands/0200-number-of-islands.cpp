class Solution {
public:
    void bfs(int row, int col, vector<vector<char>> &grid, vector<vector<int>> &vis, int n,int m) {
        queue<pair<int,int>> q;
        q.push({row, col});
        vis[row][col] = 1;

        vector<int> dr = {-1, 0, 1, 0};
        vector<int> dc = {0, 1, 0, -1};

        while(!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for(int i=0; i<4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && grid[nr][nc] == '1') {
                    q.push({nr, nc});
                    vis[nr][nc] = 1;
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        int cnt = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(!vis[i][j] && grid[i][j] == '1') {
                    cnt++;
                    bfs(i, j, grid, vis, n, m);
                }
            }
        }

        return cnt;
    }
};