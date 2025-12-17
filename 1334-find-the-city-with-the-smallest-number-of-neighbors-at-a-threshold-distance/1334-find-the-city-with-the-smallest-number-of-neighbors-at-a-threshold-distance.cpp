class Solution {
public:
    vector<int> dijkstra(int n, vector<vector<pair<int,int>>> &adj, int src) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> dist(n, INT_MAX);
        pq.push({0, src});
        dist[src] = 0;

        while(!pq.empty()) {
            auto [dis, node] = pq.top();
            pq.pop();

            if(dis > dist[node]) continue;

            for(auto it: adj[node]) {
                auto [adjNode, edgeWt] = it;
                if(dis + edgeWt < dist[adjNode]) {
                    pq.push({dis + edgeWt, adjNode});
                    dist[adjNode] = dis + edgeWt;
                }
            }
        }

        return dist;
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto it: edges) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        int minCities = INT_MAX;
        int ans = -1;

        for(int i=0; i<n; i++) {
            vector<int> dist = dijkstra(n, adj, i);

            int cnt = 0;
            for(int j=0; j<n; j++) {
                if(dist[j] <= distanceThreshold) cnt++;
            }

            if(cnt <= minCities) {
                minCities = cnt;
                ans = i;
            }
        }

        return ans;
    }
};