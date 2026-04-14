class Solution {
private:
    using ll = long long;

    ll f(int i, int j, vector<int> &robot, vector<int> &slots, vector<vector<ll>> &dp) {
        if(i == robot.size()) return 0;
        if(j == slots.size()) return 1e15;

        if(dp[i][j] != -1) return dp[i][j];

        ll take = abs(robot[i] - slots[j]) + f(i+1, j+1, robot, slots, dp);
        ll notTake = f(i, j+1, robot, slots, dp);

        return dp[i][j] = min(take, notTake);
    }

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
        vector<vector<ll>> dp(n, vector<ll>(m, -1));

        return f(0, 0, robot, slots, dp);
    }
};