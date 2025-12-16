class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        // edge cases
        if(grid[0][0] != 0 || grid[n-1][n-1] != 0) return -1;
        if(n == 1) return 1;

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        queue<tuple<int,int,int>> q; // dis, row, col
        dist[0][0] = 1;
        q.push({1, 0, 0});

        vector<int> drow = {-1, -1, 0, 1, 1, 1, 0, -1};
        vector<int> dcol = {0, 1, 1, 1, 0, -1, -1, -1};

        while(!q.empty()) {
            auto [dis, row, col] = q.front();
            q.pop();

            for(int i=0; i<8; i++) {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < n && grid[nrow][ncol] == 0 && dis + 1 < dist[nrow][ncol]) {
                    if(nrow == n-1 && ncol == n-1) return dis + 1;
                    dist[nrow][ncol] = dis + 1;
                    q.push({dis + 1, nrow, ncol});
                }
            }
        }

        return -1;   
    }
};