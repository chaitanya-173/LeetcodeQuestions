class Solution {
private:
    bool isSafe(int row, int col, vector<int> &leftRow, vector<int> &upperDiagonal, vector<int> &lowerDiagonal, int n) {
        if(leftRow[row] == 0 && lowerDiagonal[row+col] == 0 && upperDiagonal[n-1 + col-row] == 0) {
            return true;
        }
        return false;
    }

    void f(int col, vector<string> &board, int &cnt, int n, 
        vector<int> &leftRow, vector<int> &upperDiagonal, vector<int> &lowerDiagonal) {
        if(col == n) {
            cnt++;
            return;
        }

        for(int row = 0; row < n; row++) {
            if(isSafe(row, col, leftRow, upperDiagonal, lowerDiagonal, n)) {

                board[row][col] = 'Q';
                leftRow[row] = 1;
                lowerDiagonal[row+col] = 1;
                upperDiagonal[n-1 + col-row] = 1;

                f(col+1, board, cnt, n, leftRow, upperDiagonal, lowerDiagonal);

                board[row][col] = '.';
                leftRow[row] = 0;
                lowerDiagonal[row+col] = 0;
                upperDiagonal[n-1 + col-row] = 0;
            }
        }
    }

public:
    int totalNQueens(int n) {
        int cnt = 0;
        vector<string> board(n);
        string s(n, '.');
        for(int i=0; i<n; i++) board[i] = s;
        vector<int> leftRow(n, 0), upperDiagonal(2*n - 1, 0), lowerDiagonal(2*n - 1, 0);
        f(0, board, cnt, n, leftRow, upperDiagonal, lowerDiagonal);
        return cnt;
    }
};