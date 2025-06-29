class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        sort(nums.begin(), nums.end());
        int lastSmall = INT_MIN;
        int len = 0, maxLen = 1;
        for(int i=0; i<n; i++) {
            if(nums[i] - 1 == lastSmall) {
                len += 1;
                lastSmall = nums[i];
            } else if (lastSmall != nums[i]) {
                len = 1;
                lastSmall = nums[i];
            }
            maxLen = max(maxLen, len);
        }
        return maxLen;
    }
};