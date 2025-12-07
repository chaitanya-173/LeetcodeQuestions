class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int,int>> q;

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if((board[i][j] == 'O') && (i == 0 || j == 0 || i == n-1 || j == m-1)) {
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

                if(nr >= 0 && nr < n && nc >= 0 && nc < m  
                    && board[nr][nc] == 'O' && !vis[nr][nc]) {
                    q.push({nr, nc});
                    vis[nr][nc] = 1;
                }
            }
        }

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(board[i][j] == 'O' && !vis[i][j]) board[i][j] = 'X';
            }
        }
    }
};