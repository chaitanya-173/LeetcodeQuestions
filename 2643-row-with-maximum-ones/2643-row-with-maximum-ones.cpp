class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int ind = 0, cntMax = 0;

        for(int i = 0; i < n; i++) {
            int cntOnes = 0;
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 1) cntOnes++;
            }

            if(cntOnes > cntMax) {
                cntMax = cntOnes;
                ind = i;
            }
        }

        return {ind, cntMax};
    }
};