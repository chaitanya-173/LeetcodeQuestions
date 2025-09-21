class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // reverse adj list creation
        int V = graph.size();
        vector<vector<int>> adj(V);
        vector<int> indegree(V);
        for(int i=0; i<graph.size(); i++) {
            for(auto it: graph[i]) {
                adj[it].push_back(i);
                indegree[i]++;
            }
        }

        // queue initialisation
        queue<int> q;
        for(int i=0; i<V; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        // bfs (topo sort)
        vector<int> safeNodes;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            safeNodes.push_back(node);

            for(auto it: adj[node]) {
                indegree[it]--;
                if(indegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }
};