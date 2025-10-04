class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // adj list creation
        vector<vector<pair<int,int>>> adj(n+1);
        for(int i=0; i<times.size(); i++) {
            int u = times[i][0];
            int v = times[i][1];
            int wt = times[i][2];
            adj[u].push_back({v, wt});
        }

        // dijkstra
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> dist(n+1, INT_MAX);
        pq.push({0, k});
        dist[k] = 0;

        while(!pq.empty()) {
            int node = pq.top().second;
            int time = pq.top().first;
            pq.pop();

            for(auto it: adj[node]) {
                int adjNode = it.first;
                int edgeWt = it.second;

                if(edgeWt + time < dist[adjNode]) {
                    dist[adjNode] = edgeWt + time;
                    pq.push({edgeWt + time, adjNode});
                }
            }
        }

        int maxTime = INT_MIN;
        for(int i=1; i<=n; i++) {
            if(dist[i] == INT_MAX) return -1;
            maxTime = max(maxTime, dist[i]);
        }

        return maxTime;
    }
};