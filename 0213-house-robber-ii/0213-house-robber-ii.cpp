class Solution {
public:
    int robLinear(vector<int>& nums, int start, int end) {
        int prev2 = 0, prev = 0;

        for(int i=start; i<end; i++) {
            int curr = max(prev, prev2 + nums[i]);
            prev2 = prev;
            prev = curr;
        }

        return prev;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        int ans1 = robLinear(nums, 0, n-1);
        int ans2 = robLinear(nums, 1, n);

        return max(ans1, ans2);
    }
};