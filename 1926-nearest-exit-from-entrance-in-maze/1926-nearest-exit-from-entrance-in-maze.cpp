class Solution {
private:
    struct Node {
        int row, col, steps;
    };

public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size();
        int m = maze[0].size();
        
        queue<Node> q;
        q.push({entrance[0], entrance[1], 0});
        maze[entrance[0]][entrance[1]] = '+';

        vector<int> dr = {-1, 0, 1, 0};
        vector<int> dc = {0, 1, 0, -1};

        while(!q.empty()) {
            Node cur = q.front();
            q.pop();

            for(int i = 0; i < 4; i++) {
                int nr = cur.row + dr[i];
                int nc = cur.col + dc[i];

                if(nr>=0 && nr<n && nc>=0 && nc<m && maze[nr][nc] == '.') {
                    if(nr == 0 || nr == n-1 || nc == 0 || nc == m-1) return cur.steps+1;
                    q.push({nr, nc, cur.steps+1});
                    maze[nr][nc] = '+';
                }
            }
        }

        return -1; 
    }
};