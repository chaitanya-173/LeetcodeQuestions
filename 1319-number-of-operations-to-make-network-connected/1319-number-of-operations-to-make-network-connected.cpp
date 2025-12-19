class DSU {
    vector<int> parent, rank, size;
    public:
        DSU(int n) {
            rank.resize(n+1, 0);
            size.resize(n+1, 1);
            for(int i=0; i<=n; i++) parent.push_back(i);
        }
        
        int findUParent(int node) {
            if(node == parent[node]) return node;
            return parent[node] = findUParent(parent[node]);
        }
        
        void unionByRank(int u, int v) {
            int ulpU = findUParent(u);
            int ulpV = findUParent(v);
            if(ulpU == ulpV) return;
            if(rank[ulpU] < rank[ulpV]) parent[ulpU] = ulpV;
            else if(rank[ulpU] > rank[ulpV]) parent[ulpV] = ulpU; 
            else {
                parent[ulpU] = ulpV;
                rank[ulpV]++;
            }
        }
        
        void unionBySize(int u, int v) {
            int ulpU = findUParent(u);
            int ulpV = findUParent(v);
            if(ulpU == ulpV) return;
            if(size[ulpU] < size[ulpV]) {
                parent[ulpU] = ulpV;
                size[ulpV] += size[ulpU];
            } else {
                parent[ulpV] = ulpU; 
                size[ulpU] += size[ulpV];
            }
        }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DSU ds(n);

        int extraCables = 0;
        for(auto it: connections) {
            int u = it[0];
            int v = it[1];
            if(ds.findUParent(u) != ds.findUParent(v)) {
                ds.unionBySize(u, v);
            } else {
                extraCables++;
            }
        }
        
        int extraComputers = 0;
        for(int i=0; i<n; i++) {
            if(ds.findUParent(i) == i) extraComputers++;
        }

        int neededComputers = extraComputers - 1;
        return (extraCables >= neededComputers ? neededComputers : -1);
    }
};