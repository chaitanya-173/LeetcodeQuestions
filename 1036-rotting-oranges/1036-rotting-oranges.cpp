class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<tuple<int,int,int>> q;  // row, col, time
        int cntFresh = 0;
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 2) {
                    q.push({i,j,0});
                    vis[i][j] = 1;
                } else if(grid[i][j] == 1) {
                    cntFresh++;
                }
            }
        }

        vector<int> drow = {-1, 0, 1, 0};
        vector<int> dcol = {0, 1, 0, -1};
        int time = 0;

        while(!q.empty()) {
            auto [r, c, t] = q.front();
            q.pop();
            time = max(time, t);

            for(int i=0; i<4; i++) {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m 
                && grid[nrow][ncol] == 1 && !vis[nrow][ncol]) {
                    q.push({nrow, ncol, t+1});
                    vis[nrow][ncol] = 1;
                    cntFresh--;
                }
            }
        }

        return (cntFresh != 0 ? -1 : time);
    }
};