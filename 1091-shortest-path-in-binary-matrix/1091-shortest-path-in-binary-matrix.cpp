class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        // edge cases
        if(grid[0][0] != 0 || grid[n-1][n-1] != 0) return -1;
        if(n == 1) return 1;

        vector<vector<int>> vis(n, vector<int>(n, 0));
        queue<tuple<int,int,int>> q; // dis, row, col
        vis[0][0] = 1;
        q.push({1, 0, 0});

        vector<int> drow = {-1, -1, 0, 1, 1, 1, 0, -1};
        vector<int> dcol = {0, 1, 1, 1, 0, -1, -1, -1};

        while(!q.empty()) {
            auto [dis, row, col] = q.front();
            q.pop();

            for(int i=0; i<8; i++) {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < n && grid[nrow][ncol] == 0 && !vis[nrow][ncol]) {
                    if(nrow == n-1 && ncol == n-1) return dis + 1;
                    vis[nrow][ncol] = 1;
                    q.push({dis + 1, nrow, ncol});
                }
            }
        }

        return -1;   
    }
};