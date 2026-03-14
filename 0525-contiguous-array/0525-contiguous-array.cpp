class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> preSum;
        int sum = 0;
        int maxLen = 0;
        
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==1) sum++;
            else sum--;
            
            if(sum == 0) maxLen = i+1;
            
            if(preSum.count(sum)){
                maxLen = max(maxLen, i - preSum[sum]); 
            } else {
                preSum[sum] = i;
            }
        }

        return maxLen;
    }
};