class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> freq; 
        freq[0] = 1;  // Empty prefix sum (0) occurs once.
        
        int sum = 0;  // Running prefix sum
        int ans = 0;  // Count of valid subarrays
        
        for (int x : nums) {
            sum += x;  // Update prefix sum
            
            // Check if there is a prefix sum that we can subtract to get k
            if (freq.count(sum - k)) {
                ans += freq[sum - k];  // Add all occurrences of that prefix sum
            }
            
            // Store/update the frequency of the current prefix sum
            freq[sum]++;
        }
        return ans;  // Final answer
    }
};