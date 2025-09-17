class Solution {
public:
    bool dfsColor(int node, int col, vector<vector<int>> &graph, vector<int> &color) {
        color[node] = col;

        for(auto it: graph[node]) {
            if(color[it] == -1) {
                if(!dfsColor(it, !col, graph, color)) { 
                    return false;
                }
            } else if(color[it] == col) {
                return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);

        for(int i=0; i<n; i++) {
            if(color[i] == -1) {
                if(!dfsColor(i, 0, graph, color)) {
                    return false;
                }
            }
        }
        return true;
    }
};