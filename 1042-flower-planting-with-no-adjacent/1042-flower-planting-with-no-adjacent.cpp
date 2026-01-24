class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> adj(n);
        
        for(auto &p : paths) {
            adj[p[0] - 1].push_back(p[1] - 1);
            adj[p[1] - 1].push_back(p[0] - 1);
        }
        
        vector<int> color(n, 0);
        
        for(int i = 0; i < n; i++) {
            vector<bool> used(5, false);
            
            for(auto neigh : adj[i]) {
                if(color[neigh] != 0)
                    used[color[neigh]] = true;
            }
            
            for(int c = 1; c <= 4; c++) {
                if(!used[c]) {
                    color[i] = c;
                    break;
                }
            }
        }
        
        return color;
    }
};
