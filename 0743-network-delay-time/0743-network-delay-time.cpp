class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto it: times) {
            adj[it[0]].push_back({it[1], it[2]});
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> time(n+1, INT_MAX);
        pq.push({0, k});
        time[k] = 0;

        while(!pq.empty()) {
            auto [t, node] = pq.top();
            pq.pop();

            if(t > time[node]) continue;

            for(auto it: adj[node]) {
                auto [adjNode, edgeWt] = it;
                if(t + edgeWt < time[adjNode]) {
                    pq.push({t + edgeWt, adjNode});
                    time[adjNode] = t + edgeWt;
                } 
            }
        }

        int maxTime = INT_MIN;
        for(int i=1; i<=n; i++) {
            if(time[i] == INT_MAX) return -1;
            maxTime = max(time[i], maxTime);
        }

        return maxTime;
    }
};