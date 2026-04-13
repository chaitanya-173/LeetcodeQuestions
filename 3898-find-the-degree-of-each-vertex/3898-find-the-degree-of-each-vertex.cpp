class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        int V = matrix.size();
        vector<int> degree(V, 0);

        for(int i = 0; i < V; i++) {
            for(int j = i+1; j < V; j++) {
                if(matrix[i][j] == 1) {
                    degree[i]++;
                    degree[j]++;
                }
            }
        }

        return degree;
    }
};