class Solution {
private:
    bool row[9][10] = {false};
    bool col[9][10] = {false};
    bool box[9][10] = {false};

    bool solve(vector<vector<char>> &board) {
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] == '.') {
                    for(char c = '1'; c <= '9'; c++) {
                        int d = c - '0';
                        int b = (i / 3) * 3 + (j / 3);

                        if(!row[i][d] && !col[j][d] && !box[b][d]) {
                            board[i][j] = c;
                            row[i][d] = col[j][d] = box[b][d] = true;

                            if(solve(board)) return true;

                            // backtrack
                            board[i][j] = '.';
                            row[i][d] = col[j][d] = box[b][d] = false;
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {

        // initialize helper arrays
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] != '.') {
                    int d = board[i][j] - '0';
                    int b = (i / 3) * 3 + (j / 3);
                    row[i][d] = col[j][d] = box[b][d] = true;
                }
            }
        }

        solve(board);
    }
};
