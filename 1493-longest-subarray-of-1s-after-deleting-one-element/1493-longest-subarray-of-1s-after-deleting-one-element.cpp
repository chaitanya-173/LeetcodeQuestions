class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int l = 0, k = 1, maxi = 0;

        for(int r = 0; r < n; r++) {
            if(nums[r] == 0) k--;

            while(k < 0) {
                if(nums[l] == 0) k++;
                l++;
            }

            maxi = max(maxi, r - l + 1);
        }

        return maxi - 1;
    }
};