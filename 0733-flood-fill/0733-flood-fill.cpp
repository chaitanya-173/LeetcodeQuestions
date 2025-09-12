class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> ans = image;

        int originalColor = image[sr][sc];
        if(originalColor == color) return ans;

        queue<pair<int,int>> q;
        q.push({sr, sc});
        ans[sr][sc] = color;

        vector<int> drow = {-1, 0, 1, 0};
        vector<int> dcol = {0, 1, 0, -1};

        while(!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i=0; i<4; i++) {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m 
                && ans[nrow][ncol] == originalColor) {
                    ans[nrow][ncol] = color;
                    q.push({nrow, ncol});
                }
            }
        }

        return ans;
    }
};