class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();

        int sumOfArr = 0;
        for(int num : nums) {
            sumOfArr += num;
        }

        // Invalid cases
        if (target > sumOfArr || target < -sumOfArr) return 0;
        if ((target + sumOfArr) % 2 != 0) return 0;

        int sum = (target + sumOfArr) / 2;

        vector<vector<int>> dp(n+1, vector<int>(sum+1, 0));

        // Base case: sum = 0
        dp[0][0] = 1;

        for(int i=1; i<=n; i++) {
            for(int j=0; j<=sum; j++) {
                if(nums[i-1] <= j) {
                    dp[i][j] = dp[i-1][j-nums[i-1]] + dp[i-1][j];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return dp[n][sum];
    }
};
