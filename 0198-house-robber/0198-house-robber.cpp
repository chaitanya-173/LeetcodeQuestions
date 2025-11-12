class Solution {
public:
    int f(int n, vector<int> &nums, vector<int> &dp) {
        if(n == 0) return nums[n];
        if(n == 1) return max(nums[0], nums[1]);

        if(dp[n] != -1) return dp[n];

        int prev = f(n-1, nums, dp);
        int prev2 = INT_MIN;
        if(n > 1) prev2 = f(n-2, nums, dp) + nums[n];

        return dp[n] = max(prev, prev2);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return f(n-1, nums, dp);
    }
};