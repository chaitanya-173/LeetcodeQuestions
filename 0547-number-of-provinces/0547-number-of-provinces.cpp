#include <vector>
using namespace std;

class DisjointSet {
    vector<int> size, parent;
public:
    // constructor
    DisjointSet(int n) { 
        size.resize(n, 1); // initially each node size = 1
        parent.resize(n);
        for(int i=0; i<n; i++) parent[i] = i;
    }

    int findParent(int node) {
        if(parent[node] == node) return node;
        return parent[node] = findParent(parent[node]); // path compression
    }

    void unionBySize(int u, int v) {
        int ulpU = findParent(u);
        int ulpV = findParent(v);
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
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        DisjointSet ds(V);

        // connect directly connected cities
        for(int i=0; i<V; i++) {
            for(int j=0; j<V; j++) {
                if(isConnected[i][j] == 1) {
                    ds.unionBySize(i, j);
                }
            }
        }

        // count number of unique ultimate parents
        int cnt = 0;
        for(int i=0; i<V; i++) {
            if(ds.findParent(i) == i) cnt++;
        }

        return cnt;
    }
};
