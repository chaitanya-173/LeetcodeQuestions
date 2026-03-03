class DSU {
private:
    vector<int> parent, size;
public:
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DSU ds(n);
        unordered_map<string, int> mapMailNode;

        // creation of dsu
        for(int i=0; i<n; i++) {
            for(int j=1; j<accounts[i].size(); j++) {
                string mail = accounts[i][j];
                if(mapMailNode.count(mail) == 0) {
                    mapMailNode[mail] = i;
                } else {
                    ds.unionBySize(i, mapMailNode[mail]);
                }
            }
        }

        vector<vector<string>> mergedMail(n);
        for(auto it: mapMailNode) {
            string mail = it.first;
            int node = ds.findUParent(it.second);
            mergedMail[node].push_back(mail);
        }

        vector<vector<string>> ans;
        for(int i=0; i<n; i++) {
            if(mergedMail[i].size() == 0) continue;
            sort(mergedMail[i].begin(), mergedMail[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto it: mergedMail[i]) {
                temp.push_back(it);
            }
            ans.push_back(temp);
        }

        return ans;
    }
};