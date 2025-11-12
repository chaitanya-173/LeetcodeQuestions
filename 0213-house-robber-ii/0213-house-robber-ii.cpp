class Solution {
public:
    int func(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];

        int prev2 = nums[0];
        int prev = max(nums[0], nums[1]);

        for(int i=2; i<n; i++) {
            int curr = max(prev, prev2 + nums[i]);
            prev2 = prev;
            prev = curr;
        }

        return prev;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        
        vector<int> temp1(nums.begin(), nums.end() - 1); // exclude last
        vector<int> temp2(nums.begin() + 1, nums.end()); // exclude first

        int ans1 = func(temp1);
        int ans2 = func(temp2);

        return max(ans1, ans2);
    }
};