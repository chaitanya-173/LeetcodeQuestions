class Solution {
public:
    // int f(int n, vector<int> &nums, vector<int> &dp) {
    //     if(n == 0) return nums[n];
    //     if(n == 1) return max(nums[0], nums[1]);

    //     if(dp[n] != -1) return dp[n];

    //     int prev = f(n-1, nums, dp);
    //     int prev2 = INT_MIN;
    //     if(n > 1) prev2 = f(n-2, nums, dp) + nums[n];

    //     return dp[n] = max(prev, prev2);
    // }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];

        vector<int> dp(n);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for(int i=2; i<n; i++) {
            int prev = dp[i-1];
            int prev2 = dp[i-2] + nums[i];
            dp[i] = max(prev, prev2);
        }

        return dp[n-1];
    }
};