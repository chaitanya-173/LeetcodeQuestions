class DSU {
public:
    vector<int> parent, size;

    DSU(int n) {
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
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DSU ds(n*n);

        vector<int> dr = {-1, 0, 1, 0};
        vector<int> dc = {0, 1, 0, -1};

        // applying dsu
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {

                if(grid[i][j] == 1) {
                    for(int k=0; k<4; k++) {
                        int nr = i + dr[k];
                        int nc = j + dc[k];
                        if(nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                            int nodeNo = i * n + j;
                            int adjNodeNo = nr * n + nc;

                            if(ds.findUParent(nodeNo) != ds.findUParent(adjNodeNo)) {
                                ds.unionBySize(nodeNo, adjNodeNo);
                            }
                        } 
                    }
                }

            }
        }

        // try converting each 0 to 1 and find max island size
        int maxi = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {

                if(grid[i][j] == 0) {
                    int cnt = 1;
                    unordered_set<int> st;
                    for(int k=0; k<4; k++) {
                        int nr = i + dr[k];
                        int nc = j + dc[k];
                        if(nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                            int nodeNo = i * n + j;
                            int adjNodeNo = nr * n + nc;
                            st.insert(ds.findUParent(adjNodeNo));
                        } 
                    }
                    for(auto it: st) {
                        cnt += ds.size[it];
                    }
                    maxi = max(maxi, cnt);
                }

            }
        }

        for(int i=0; i<n*n; i++) {
            maxi = max(maxi, ds.size[ds.findUParent(i)]);
        }

        return maxi;
    }
};