class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldColor = image[sr][sc];
        image[sr][sc] = color;
        int n = image.size(), m = image[0].size();

        int dir[4][2] = {{0,1},{1,0},{-1,0},{0,-1}};
        vector<vector<bool>> vis(n+1, vector<bool>(m+1,false));
        queue<vector<int>> q;
        q.push({sr,sc});

        while (!q.empty()){
            vector <int> node = q.front();
            q.pop();
            int a = node[0];
            int b = node[1];
            for (int i=0; i<4; i++){
                int c = a+dir[i][0], d = b+dir[i][1];
                if (c>=0 && c<n && d>=0 && d<m && image[c][d] == oldColor && vis[c][d] == false){
                    q.push({c,d});
                    vis[c][d] = true;
                    image[c][d] = color;
                }
            }
        }
        
        return image;
    }
};