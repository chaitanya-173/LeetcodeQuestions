class Solution {
private:
    bool f(int ind, vector<int> &arr, vector<int> &dp) {
        if(ind >= arr.size()-1) return true;
        if(arr[ind] == 0) return false;

        if(dp[ind] != -1) return dp[ind];

        int num = arr[ind];
        for(int i=1; i<=num; i++) {
            if(f(ind+i, arr, dp)) return dp[ind] = true;
        } 
        return dp[ind] = false;
    }

public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return f(0, nums, dp);
    }
};