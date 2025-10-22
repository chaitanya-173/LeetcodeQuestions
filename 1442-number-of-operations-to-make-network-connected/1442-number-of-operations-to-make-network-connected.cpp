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
        int noOfEdges = 0;
        for(int i=0; i<connections.size(); i++) {
            int u = connections[i][0];
            int v = connections[i][1];
            if(ds.findUParent(u) != ds.findUParent(v)) {
                ds.unionBySize(u, v);
            } else {
                noOfEdges++;
            }
        }

        int noOfComponents = 0;
        for(int i=0; i<n; i++) {
            if(ds.findUParent(i) == i) noOfComponents++;
        }

        if(noOfComponents - noOfEdges <= 1) return noOfComponents - 1;
        return -1;
    }
};