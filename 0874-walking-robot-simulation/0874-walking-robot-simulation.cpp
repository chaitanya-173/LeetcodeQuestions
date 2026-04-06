class Solution {
public:
    struct pair_hash {
        size_t operator()(const pair<int,int>& p) const {
            return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
        }
    };

    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<pair<int,int>, pair_hash> obs;

        for(auto &it : obstacles) {
            obs.insert({it[0], it[1]});
        }

        int x = 0, y = 0;
        int dir = 0; // 0=N, 1=E, 2=S, 3=W
        int maxDist = 0;

        vector<pair<int,int>> dirs = {{0,1}, {1,0}, {0,-1}, {-1,0}};

        for(int cmd : commands) {
            if(cmd == -1) {
                dir = (dir + 1) % 4; // right turn
            } 
            else if(cmd == -2) {
                dir = (dir + 3) % 4; // left turn
            } 
            else {
                for(int i = 0; i < cmd; i++) {
                    int nx = x + dirs[dir].first;
                    int ny = y + dirs[dir].second;

                    if(obs.count({nx, ny})) break;

                    x = nx;
                    y = ny;
                }
            }

            maxDist = max(maxDist, x*x + y*y);
        }

        return maxDist;
    }
};