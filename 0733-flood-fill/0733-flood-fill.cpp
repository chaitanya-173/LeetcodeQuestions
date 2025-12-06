class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();

        vector<vector<int>> ans = image;
        queue<pair<int,int>> q;

        int originalColor = image[sr][sc];
        if(originalColor == color) return ans;

        q.push({sr, sc});
        ans[sr][sc] = color;

        vector<int> dr = {-1, 0, 1, 0};
        vector<int> dc = {0, 1, 0, -1};

        while(!q.empty()) {
            auto [row, col] = q.front();
            q.pop();

            for(int i=0; i<4; i++) {
                int nr = row + dr[i];
                int nc = col + dc[i];

                if(nr >= 0 && nr < n && nc >= 0 && nc < m && ans[nr][nc] == originalColor) {
                    q.push({nr, nc});
                    ans[nr][nc] = color;
                }
            }
        }

        return ans;
    }
};