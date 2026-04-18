class Solution {
private:
    void dfs(int ind, vector<int> &vis, vector<vector<int>> &rooms) {
        vis[ind] = 1;
        
        for(int &x : rooms[ind]) {
            if(!vis[x]) dfs(x, vis, rooms);
        }
    }

public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> vis(n, 0);
        dfs(0, vis, rooms);

        for(int &x : vis) {
            if(x == 0) return false;
        }
        return true;
    }
};