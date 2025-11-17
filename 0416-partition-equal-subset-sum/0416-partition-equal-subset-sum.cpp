class Solution {
public:
    bool canPartition(vector<int>& arr) {
        int n = arr.size();
        int sum = 0;
        for(int i=0; i<n; i++) sum += arr[i];
        if(sum % 2 != 0) return false;

        int target = sum/2;
        vector<vector<bool>> dp(n, vector<bool>(target + 1, 0)); 

        for(int i=0; i<n; i++) dp[i][0] = 1;
        // dp[0][0] = 0;

        for(int i=1; i<n; i++) {
            for(int j=1; j<=target; j++) {
                bool notPick = dp[i-1][j];
                bool pick = false;
                if(arr[i] <= j) pick = dp[i-1][j-arr[i]];
                dp[i][j] = notPick || pick;
            }
        }

        return dp[n-1][target];
         
    }
};