class Solution {
public:
    void bfs(int node, vector<vector<int>> &adj, vector<bool> &vis) {
        queue<int> q;
        q.push(node);
        vis[node] = true;

        while(!q.empty()) {
            int frontNode = q.front();
            q.pop();
            
            for(auto it: adj[frontNode]) {
                if(!vis[it]) {
                    vis[it] = true;
                    q.push(it);
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();

        // making adj list
        vector<vector<int>> adj(V);
        for(int i=0; i<V; i++) {
            for(int j=0; j<V; j++) {
                if(isConnected[i][j] == 1 && i != j) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<bool> vis(V, false);
        int cnt = 0;
        for(int i=0; i<V; i++) {
            if(!vis[i]) {
                cnt++;
                bfs(i, adj, vis);
            }
        }

        return cnt;
    }
};