class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        freq[0] = 1;          // empty prefix
        int sum = 0;
        int ans = 0;

        for (int x : nums) {
            sum += x;
            if (freq.count(sum - k)) {
                ans += freq[sum - k];   // all j's with prefix[j] = sum - k
            }
            freq[sum]++;                // store current prefix
        }
        return ans;
    }
};