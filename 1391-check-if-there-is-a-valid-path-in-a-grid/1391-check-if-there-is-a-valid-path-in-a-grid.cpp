class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        q.push({0, 0});

        while(!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            vis[r][c] = 1;
            if(r == n-1 && c == m-1) return true;

            if(grid[r][c] == 1) {

                if(c-1 >= 0 && !vis[r][c-1] && (grid[r][c-1] == 1 || grid[r][c-1] == 4 || grid[r][c-1] == 6)) q.push({r, c-1}); // left
                if(c+1 < m && !vis[r][c+1] && (grid[r][c+1] == 1 || grid[r][c+1] == 3 || grid[r][c+1] == 5)) q.push({r, c+1}); // right          

            } else if(grid[r][c] == 2) {

                if(r-1 >= 0 && !vis[r-1][c] && (grid[r-1][c] == 2 || grid[r-1][c] == 3 || grid[r-1][c] == 4)) q.push({r-1, c}); // top
                if(r+1 < n && !vis[r+1][c] && (grid[r+1][c] == 2 || grid[r+1][c] == 5 || grid[r+1][c] == 6)) q.push({r+1, c}); // bottom

            } else if(grid[r][c] == 3) {

                if(c-1 >= 0 && !vis[r][c-1] && (grid[r][c-1] == 1 || grid[r][c-1] == 4 || grid[r][c-1] == 6)) q.push({r, c-1}); // left
                if(r+1 < n && !vis[r+1][c] && (grid[r+1][c] == 2 || grid[r+1][c] == 5 || grid[r+1][c] == 6)) q.push({r+1, c}); // bottom

            } else if(grid[r][c] == 4) {

                if(c+1 < m && !vis[r][c+1] && (grid[r][c+1] == 1 || grid[r][c+1] == 3 || grid[r][c+1] == 5)) q.push({r, c+1}); // right 
                if(r+1 < n && !vis[r+1][c] && (grid[r+1][c] == 2 || grid[r+1][c] == 5 || grid[r+1][c] == 6)) q.push({r+1, c}); // bottom

            } else if(grid[r][c] == 5) {

                if(c-1 >= 0 && !vis[r][c-1] && (grid[r][c-1] == 1 || grid[r][c-1] == 4 || grid[r][c-1] == 6)) q.push({r, c-1}); // left
                if(r-1 >= 0 && !vis[r-1][c] && (grid[r-1][c] == 2 || grid[r-1][c] == 3 || grid[r-1][c] == 4)) q.push({r-1, c}); // top

            } else {

                if(r-1 >= 0 && !vis[r-1][c] && (grid[r-1][c] == 2 || grid[r-1][c] == 3 || grid[r-1][c] == 4)) q.push({r-1, c}); // top
                if(c+1 < m && !vis[r][c+1] && (grid[r][c+1] == 1 || grid[r][c+1] == 3 || grid[r][c+1] == 5)) q.push({r, c+1}); // right 

            }
        }

        return false;
    }
};