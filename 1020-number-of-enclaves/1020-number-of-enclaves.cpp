class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
      int n = grid.size();
      int m = grid[0].size();
      
      vector<vector<int>> vis(n, vector<int>(m, 0));
      queue<pair<int,int>> q;

      for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
          if((i == 0 || j == 0 || i == n-1 || j == m-1) && (grid[i][j] == 1)) {
            q.push({i, j});
            vis[i][j] = 1;
          }
        }
      }

      vector<int> dr = {-1, 0, 1, 0};
      vector<int> dc = {0, 1, 0, -1};
      
      while(!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        for(int i=0; i<4; i++) {
          int nr = r + dr[i];
          int nc = c + dc[i];

          if(nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && grid[nr][nc] == 1) {
            q.push({nr, nc});
            vis[nr][nc] = 1;
          }
        }
      }

      int cnt = 0;
      for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
          if(grid[i][j] == 1 && !vis[i][j]) cnt++;
        }
      }

      return cnt;
    }
};