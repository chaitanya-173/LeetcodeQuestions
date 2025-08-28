class Solution {
public:
    void dfs(int node, vector<vector<int>> &adj, vector<bool> &vis) {
        vis[node] = true;
        for(auto it: adj[node]) {
            if(!vis[it]) {
                dfs(it, adj, vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        // adj list creation
        vector<vector<int>> adjList(V);
        for(int i=0; i<V; i++) {
            for(int j=0; j<V; j++) {
                if(isConnected[i][j] == 1 & i != j) {
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }

        vector<bool> vis(V+1, false);
        int cnt = 0;
        for(int i=0; i<V; i++) {
            if(!vis[i]) {
                cnt++;
                dfs(i, adjList, vis);
            }
        }

        return cnt;
    }
};