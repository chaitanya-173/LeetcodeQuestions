class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int low = 0, high = n-1;
        while(low <= high) {
            int row = low + (high - low) / 2;

            int col = max_element(mat[row].begin(), mat[row].end()) - mat[row].begin();

            int top = row-1 >= 0 ? mat[row-1][col] : -1;
            int bottom = row+1 < n ? mat[row+1][col] : -1;

            if(mat[row][col] > top && mat[row][col] > bottom) return {row, col};
            else if(mat[row][col] < top) high = row - 1;
            else low = row + 1;
        }

        return {-1,-1};
    }
};