class Solution {
private:
    using ll = long long;

    // // TLE : recursive approach
    // ll f(int ind, vector<int> &robot, vector<vector<int>> &factory) {
    //     if(ind == robot.size()) return 0;

    //     ll mini = LLONG_MAX;
    //     for(int i = 0; i < factory.size(); i++) {
    //         if(factory[i][1] > 0) {
    //             factory[i][1]--; 
    //             ll dist = abs(robot[ind] - factory[i][0]) + f(ind+1, robot, factory);
    //             mini = min(mini, dist);
    //             factory[i][1]++;
    //         }
    //     }

    //     return mini;
    // }
    
    // // 
    // ll f(int i, int j, vector<int> &robot, vector<int> &slots, vector<vector<ll>> &dp) {
    //     if(i == robot.size()) return 0;
    //     if(j == slots.size()) return 1e15;

    //     if(dp[i][j] != -1) return dp[i][j];

    //     ll take = abs(robot[i] - slots[j]) + f(i+1, j+1, robot, slots, dp);
    //     ll notTake = f(i, j+1, robot, slots, dp);

    //     return dp[i][j] = min(take, notTake);
    // }

public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        vector<int> slots;
        for(auto &f : factory) { 
            int pos = f[0]; 
            int cap = f[1]; 
            while(cap--) slots.push_back(pos); 
        }

        int n = robot.size(), m = slots.size(); 
        // vector<vector<ll>> dp(n+1, vector<ll>(m+1, 0));
        vector<ll> cur(m+1, 0), next(m+1, 0);
        
        // base case 
        cur[m] = 1e15;

        for(int i = n-1; i >= 0; i--) {
            for(int j = m-1; j >= 0; j--) {
                ll take = abs(robot[i] - slots[j]) + next[j+1];
                ll notTake = cur[j+1];
                cur[j] = min(take, notTake);
            }
            next = cur;
        }

        return next[0];
    }
};