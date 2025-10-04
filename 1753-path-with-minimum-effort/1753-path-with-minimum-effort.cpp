class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;
        vector<vector<int>> diff(n, vector<int>(m, INT_MAX));
        pq.push({0, {0,0}});
        diff[0][0] = 0;

        vector<int> drow = {-1, 0, 1, 0};
        vector<int> dcol = {0, 1, 0, -1};

        while(!pq.empty()) {
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            int difference = pq.top().first;
            pq.pop();
            
            if(r == n-1 && c == m-1) return difference;

            for(int i=0; i<4; i++) {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m) {
                    int effort = max(abs(heights[r][c] - heights[nrow][ncol]), difference);

                    if(effort < diff[nrow][ncol]) {
                        diff[nrow][ncol] = effort;
                        pq.push({effort, {nrow, ncol}});
                    }
                }
            } 
        }
        
        return 0; // unreachable
    }
};