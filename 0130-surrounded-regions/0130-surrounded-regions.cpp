class Solution {
public:
    void dfs(int i, int j, vector<vector<char>> &board, vector<vector<int>> &vis, 
        int n, int m, vector<int> &dr, vector<int> &dc) {
        vis[i][j] = 1;
        for(int k=0; k<4; k++) {
            int nr = i + dr[k];
            int nc = j + dc[k];
            if(nr >= 0 && nr < n && nc >= 0 && nc < m  
                && board[nr][nc] == 'O' && !vis[nr][nc]) {
                dfs(nr, nc, board, vis, n, m, dr, dc);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        vector<int> dr = {-1, 0, 1, 0};
        vector<int> dc = {0, 1, 0, -1};

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if((board[i][j] == 'O') && (i == 0 || j == 0 || i == n-1 || j == m-1)) {
                    dfs(i, j, board, vis, n, m, dr, dc);
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