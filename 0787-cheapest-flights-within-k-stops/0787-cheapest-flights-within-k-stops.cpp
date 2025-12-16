class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto it: flights) {
            adj[it[0]].push_back({it[1], it[2]});
        }

        queue<tuple<int,int,int>> q;
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        q.push({0, 0, src});

        while(!q.empty()) {
            auto [stops, dis, node] = q.front();
            q.pop();
            
            if(stops > k) continue;

            for(auto it: adj[node]) {
                auto [adjNode, edgeWt] = it;
                if(dis + edgeWt < dist[adjNode] && stops <= k) {
                    dist[adjNode] = dis + edgeWt;
                    q.push({stops + 1, dis + edgeWt, adjNode});
                }
            }
        }

        return (dist[dst] == INT_MAX ? -1 : dist[dst]);
    }
};