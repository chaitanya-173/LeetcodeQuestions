class Solution {
private:
    struct Node {
        int r, c, t;
    };

public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<Node> q; 
        int cntFresh = 0;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 2) {
                    q.push({i, j, 0});
                    grid[i][j] = 2;
                } else if(grid[i][j] == 1) {
                    cntFresh++;
                }
            }
        }

        vector<int> drow = {-1, 0, 1, 0};
        vector<int> dcol = {0, 1, 0, -1};
        int time = 0;

        while(!q.empty()) {
            Node cur = q.front();
            q.pop();
            time = max(time, cur.t);

            for(int i = 0; i < 4; i++) {
                int nrow = cur.r + drow[i];
                int ncol = cur.c + dcol[i];
                
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1) {
                    q.push({nrow, ncol, cur.t+1});
                    grid[nrow][ncol] = 2;
                    cntFresh--;
                }
            }
        }

        return (cntFresh != 0 ? -1 : time);
    }
};