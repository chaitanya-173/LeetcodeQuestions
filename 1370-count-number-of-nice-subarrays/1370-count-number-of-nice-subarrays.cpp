class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int,int> prefixSum;
        prefixSum[0] = 1;
        int count = 0, sum = 0;
        for(int i=0; i<nums.size(); i++) {
            sum += nums[i] % 2;
            if(prefixSum.find(sum - k) != prefixSum.end()) {
                count += prefixSum[sum - k];
            } 
            prefixSum[sum]++;
        }
        return count;
    }
};