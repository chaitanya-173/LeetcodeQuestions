class Solution {
public:
    int recur(int i, int j, vector<int>& cuts, vector<vector<int>>& dp){
        if(i>j) return 0;
        if(dp[i][j]!= -1) return dp[i][j];
        int mini = INT_MAX;
        for(int k=i; k<=j; k++){
            int cut = cuts[j+1]-cuts[i-1]+ recur(i, k-1, cuts, dp) + recur(k+1, j, cuts, dp);
            mini = min(mini, cut);
        }
        dp[i][j] = mini;
        return mini;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        int m = cuts.size();
        vector<vector<int>>dp(m, vector<int>(m, -1));
        
        return recur(1, m-2, cuts, dp);
    }
};