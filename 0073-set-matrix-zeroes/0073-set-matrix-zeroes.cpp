class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int col0 = 1;
        
        // track 0s to be marked in the cols and rows within the matrix
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(matrix[i][j] == 0) {
                    // col mark
                    matrix[i][0] = 0;
                    // row mark
                    if(j != 0) matrix[0][j] = 0;
                    else col0 = 0;
                }
            }
        }

        // mark the required elements 0 except the 1st row and 1st col as kept for tracking
        for(int i=1; i<n; i++) {
            for(int j=1; j<m; j++) {
                if(matrix[i][j] != 0) {
                    if(matrix[i][0] == 0 || matrix[0][j] ==  0) {
                        matrix[i][j] = 0;
                    }
                }
            }
        }

        // first mark the 1st row -> according to the matrix[0][0]
        if(matrix[0][0] == 0) {
            for(int j=0; j<m; j++) {
                matrix[0][j] = 0;
            }
        }

        // then mark the 1st col -> according to the col0
        if(col0 == 0) {
            for(int i=0; i<n; i++) {
                matrix[i][0] = 0;
            }
        }

    }
};