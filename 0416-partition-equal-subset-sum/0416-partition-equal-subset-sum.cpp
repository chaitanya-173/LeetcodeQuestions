class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        if(totalSum % 2 != 0) return false;
        totalSum = totalSum / 2;

        int n = nums.size();
        vector<int> prev(totalSum + 1, 0), curr(totalSum + 1, 0);

        for(int sum = 0; sum <= totalSum; sum++) {
            if(nums[0] == sum) prev[sum] = 1;
        }

        for(int i=1; i<n; i++) {
            for(int sum = 0; sum <= totalSum; sum++) {
                int notPick = prev[sum];
                int pick = (nums[i] <= sum ? prev[sum - nums[i]] : 0);
                curr[sum] = notPick || pick;
            }
            prev = curr;
        }

        return prev[totalSum];
    }
};