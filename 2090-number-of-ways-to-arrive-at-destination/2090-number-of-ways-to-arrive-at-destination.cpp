class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int mod = 1e9 + 7;

        // adjacency list
        vector<vector<pair<int,int>>> adj(n);
        for (auto &r : roads) {
            int u = r[0], v = r[1], wt = r[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        // Dijkstra
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);

        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        while (!pq.empty()) {
            long long dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (dis > dist[node]) continue;  // skip outdated entries

            for (auto it : adj[node]) {
                int adjNode = it.first;
                long long edgeWt = it.second;

                if (edgeWt + dis < dist[adjNode]) { // first arrival with this short distance
                    dist[adjNode] = edgeWt + dis;
                    ways[adjNode] = ways[node];
                    pq.push({dist[adjNode], adjNode});
                } else if (edgeWt + dis == dist[adjNode]) {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }

        return ways[n-1] % mod;
    }
};
