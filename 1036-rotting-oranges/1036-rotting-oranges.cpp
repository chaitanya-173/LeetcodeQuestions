class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        // queue<pair< pair<int,int>, int >> q;
        queue<tuple<int,int,int>> q;
        int cntFresh = 0;

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 2) {
                    q.push({i,j,0});
                    vis[i][j] = 2;
                } else if(grid[i][j] == 1) {
                    cntFresh++;
                }
            }
        }

        vector<int> drow = {-1, 0, 1, 0};
        vector<int> dcol = {0, 1, 0, -1};
        int time = 0;

        while(!q.empty()) {
            auto it = q.front();
            int r = get<0>(it);
            int c = get<1>(it);
            int t = get<2>(it);
            // int r = q.front().first.first;
            // int c = q.front().first.second;
            // int t = q.front().second;
            q.pop();
            time = max(time, t);

            for(int i=0; i<4; i++) {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                if(nrow >= 0 && ncol >= 0 && nrow < n 
                && ncol < m && vis[nrow][ncol] != 2 && grid[nrow][ncol] == 1) {
                    q.push({nrow, ncol, t+1});
                    vis[nrow][ncol] = 2;
                    cntFresh--;
                }
            }
        }

        return (cntFresh != 0 ? -1 : time);
    }
};