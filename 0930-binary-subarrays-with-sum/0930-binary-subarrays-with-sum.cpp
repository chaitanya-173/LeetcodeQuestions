class Solution {
public:
    int numSubarraysWithLessThanEqualToSum(vector<int>& nums, int goal) {
        int cnt = 0, l = 0, sum = 0;
        if(goal < 0) return 0;
        
        for(int r = 0; r < nums.size(); r++) {
            if(nums[r] == 1) sum++;

            while(sum > goal) {
                if(nums[l] == 1) sum--;
                l++;
            }

            cnt += r-l+1;
        }

        return cnt;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return (numSubarraysWithLessThanEqualToSum(nums, goal) - numSubarraysWithLessThanEqualToSum(nums, goal-1));
    }
};