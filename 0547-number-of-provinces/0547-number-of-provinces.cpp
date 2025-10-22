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
            if(size[ulpU] < size[ulpV]) parent[ulpU] = ulpV;
            else if(size[ulpU] > size[ulpV]) parent[ulpV] = ulpU;
            else {
                parent[ulpV] = ulpU;
                size[ulpU] += size[ulpV];
            }
        }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        DisjointSet ds(n);

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(isConnected[i][j] == 1) {
                    ds.unionBySize(i, j);
                }
            }
        }

        int cnt = 0;
        for(int i=0; i<n; i++) {
            if(ds.findUParent(i) == i) cnt++;
        }

        return cnt;
    }
};