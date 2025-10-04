class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // adj list creation
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0; i<flights.size(); i++) {
            int u = flights[i][0];
            int v = flights[i][1];
            int wt = flights[i][2];
            adj[u].push_back({v, wt});
        }

        // {stops, {dist, node}}
        queue<pair<int, pair<int,int>>> q;
        vector<int> dist(n, INT_MAX);
        q.push({0, {0, src}});
        dist[src] = 0;

        while(!q.empty()) {
            int node = q.front().second.second;
            int cost = q.front().second.first;
            int stops = q.front().first;
            q.pop();

            if(stops > k) break;

            for(auto it: adj[node]) {
                int adjNode = it.first;
                int edgeWt = it.second;

                if(cost + edgeWt < dist[adjNode] && stops <= k) {
                    dist[adjNode] = cost + edgeWt;
                    q.push({stops + 1, {cost + edgeWt, adjNode}});
                }
            }
        }

        if(dist[dst] == INT_MAX) return -1;
        return dist[dst];
    }
};