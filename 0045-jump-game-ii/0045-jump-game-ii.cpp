class Solution {
private:
    int f(int ind, vector<int> &arr, vector<int> &dp, int n) {
        if(ind >= n-1) return 0;
        if(arr[ind] == 0) return 1e9;

        if(dp[ind] != -1) return dp[ind];

        int ans = 1e9;
        for(int i = 1; i <= arr[ind]; i++) {
            if(ind + i < n) {
                ans = min(ans, 1 + f(ind + i, arr, dp, n));
            }
        }
        return dp[ind] = ans;
    }

public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return f(0, nums, dp, n);
    }
};
