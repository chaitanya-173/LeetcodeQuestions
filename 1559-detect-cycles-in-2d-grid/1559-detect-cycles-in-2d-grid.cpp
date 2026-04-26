class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        vector<int> dr = {-1, 0, 1, 0};
        vector<int> dc = {0, 1, 0, -1};

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!vis[i][j]) {

                    queue<tuple<int,int,int,int>> q;
                    q.push({i, j, -1, -1});
                    vis[i][j] = 1;

                    while(!q.empty()) {
                        auto [r, c, parr, parc] = q.front();
                        q.pop();

                        for(int k = 0; k < 4; k++) {
                            int nr = r + dr[k];
                            int nc = c + dc[k];
                            
                            if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc] == grid[i][j]) {
                                if(vis[nr][nc] && nr != parr && nc != parc) return true;
                                else if(!vis[nr][nc]) {
                                    q.push({nr, nc, r, c});
                                    vis[nr][nc] = 1;
                                }
                            }
                        }
                    }

                }
            }
        }

        return false;
    }
};