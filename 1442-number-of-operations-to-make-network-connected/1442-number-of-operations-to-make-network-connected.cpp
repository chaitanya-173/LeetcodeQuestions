class DisjointSet {
    vector<int> parent, size;
    public:
        DisjointSet(int n) {
            parent.resize(n+1);
            size.resize(n+1, 1);
            for(int i=0; i<=n; i++) parent[i] = i;
        }

        int findUParent(int node) {
            if(parent[node] == node) return node;
            return parent[node] = findUParent(parent[node]);
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
        DisjointSet ds(n);
        int extraEdges = 0;
        for(auto it: connections) {
            int u = it[0];
            int v = it[1];
            if(ds.findUParent(u) == ds.findUParent(v)) {
                extraEdges++;
            } else {
                ds.unionBySize(u, v);
            }
        }

        int noOfComp = 0;
        for(int i=0; i<n; i++) {
            if(ds.findUParent(i) == i) {
                noOfComp++;
            }
        }

        if(noOfComp - extraEdges <= 1) return noOfComp-1;
        return -1;
    }
};