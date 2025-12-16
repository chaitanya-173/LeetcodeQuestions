class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;
        vector<vector<int>> diff(n, vector<int>(m, INT_MAX));

        diff[0][0] = 0;
        pq.push({0, 0, 0});

        vector<int> dr = {-1, 0, 1, 0};
        vector<int> dc = {0, 1, 0, -1};

        while(!pq.empty()) {
            auto [dif, r, c] = pq.top();
            pq.pop();

            if(r == n-1 && c == m-1) return dif;

            for(int i=0; i<4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                
                if(nr >= 0 && nr < n && nc >= 0 && nc < m) {
                    int effort = max(abs(heights[r][c] - heights[nr][nc]), dif);
                    if(effort < diff[nr][nc]) {
                        diff[nr][nc] = effort;
                        pq.push({effort, nr, nc});
                    }
                }
            }
        }

        return 0; // unreachable
    }
};