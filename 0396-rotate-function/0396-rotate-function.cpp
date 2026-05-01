class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        // f(k+1) = f(k) + sum - (n * nums[n-i])
        
        int n = nums.size();

        int sum = 0, f = 0;
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            f += (nums[i] * i);
        }

        int ans = f;
        for(int i = 1; i < n; i++) {
            f = f + sum - (n * nums[n-i]);
            ans = max(ans, f);
        }

        return ans;
    }
};