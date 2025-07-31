class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int> prefixSum;
        prefixSum[0] = 1;
        int count = 0, sum = 0;
        for(int i=0; i<nums.size(); i++) {
            sum += nums[i];
            if(prefixSum.find(sum - goal) != prefixSum.end()) {
                count += prefixSum[sum - goal];
            } 
            prefixSum[sum]++;
        }
        return count;
    }
};