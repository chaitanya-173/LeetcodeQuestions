class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        if(totalSum % 2 != 0) return false;
        totalSum = totalSum / 2;

        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(totalSum + 1, 0));

        for(int sum = 0; sum <= totalSum; sum++) {
            if(nums[0] == sum) dp[0][sum] = 1;
        }
        
        for(int i=0; i<n; i++) {
            dp[i][0] = 0;
        }

        for(int i=1; i<n; i++) {
            for(int sum = 0; sum <= totalSum; sum++) {
                int notPick = dp[i-1][sum];
                int pick = (nums[i] <= sum ? dp[i-1][sum - nums[i]] : 0);
                dp[i][sum] = notPick || pick;
            }
        }

        return dp[n-1][totalSum];
    }
};