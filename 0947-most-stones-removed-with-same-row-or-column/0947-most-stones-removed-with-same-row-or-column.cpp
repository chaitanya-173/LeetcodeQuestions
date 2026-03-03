class DSU {
private:
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
    int removeStones(vector<vector<int>>& stones) {
        int n = 0, m = 0;  // try figuring out the length of the grid
        for(auto it: stones) {
            n = max(n, it[0]);
            m = max(m, it[1]);
        }

        DSU ds(n + m + 1);
        unordered_map<int,int> stoneNodes;
        for(auto it: stones) {
            int nodeRow = it[0];
            int nodeCol = it[1] + n + 1;
            ds.unionBySize(nodeRow, nodeCol);
            stoneNodes[nodeRow] = 1;
            stoneNodes[nodeCol] = 1;
        }

        int cnt = 0;
        for(auto it: stoneNodes) {
            if(ds.findUParent(it.first) == it.first) {
                cnt++;
            }
        }

        return stones.size() - cnt;
    }
};