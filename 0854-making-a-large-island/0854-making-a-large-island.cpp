class DisjointSet {
    public:
        vector<int> parent, size;
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
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n*n);
        vector<int> dr = {-1, 0, 1, 0};
        vector<int> dc = {0, 1, 0, -1};

        // 1: making dsu (connection components)
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 0) continue;
                for(int ind=0; ind<4; ind++) {
                    int nr = i + dr[ind];
                    int nc = j + dc[ind];
                    if(nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                        ds.unionBySize(i * n + j, nr * n + nc);
                    }
                }
            }
        }

        // 2: checking by converting every 0 to 1 
        int maxSize = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 1) continue;
                set<int> components;
                for(int ind=0; ind<4; ind++) {
                    int nr = i + dr[ind];
                    int nc = j + dc[ind];
                    if(nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                        components.insert(ds.findUParent(nr * n + nc)); 
                    }
                }
                int totalSize = 1;
                for(auto it: components) {
                    totalSize += ds.size[it];
                }
                maxSize = max(maxSize, totalSize);
            }
        }

        // edge case: if the grid consists all the 1's
        for(int cellNo = 0; cellNo < n*n; cellNo++) {
            maxSize = max(maxSize, ds.size[ds.findUParent(cellNo)]);
        }

        return maxSize;
    }
};