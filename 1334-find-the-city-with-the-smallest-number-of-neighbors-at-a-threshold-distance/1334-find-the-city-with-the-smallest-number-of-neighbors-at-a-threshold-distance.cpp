class Solution {
private:
    int dijkstra(int src, vector<vector<pair<int,int>>> &adj, int n, int distanceThreshold) {
        vector<int> dist(n, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, src});
        dist[src] = 0;

        while(!pq.empty()) {
            auto [dis, node] = pq.top();
            pq.pop();
            
            if(dis > dist[node]) continue;

            for(auto &it: adj[node]) {
                auto [adjNode, edgeWt] = it;
                if(dis + edgeWt < dist[adjNode]) {
                    dist[adjNode] = dis + edgeWt;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        int cnt = 0;
        for(int x: dist) {
            if(x <= distanceThreshold) cnt++;
        }

        return cnt;
    }

public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto &it: edges) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        int city = -1;
        int mini = INT_MAX;
        for(int i=0; i<n; i++) {
            int cnt = dijkstra(i, adj, n, distanceThreshold);
            if(cnt <= mini) {
                mini = cnt;
                city = i;
            }
        }

        return city;
    }
};