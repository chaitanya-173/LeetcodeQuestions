class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> prefixCount;
        prefixCount[0] = 1; // base case

        int count = 0, oddCount = 0;

        for (int num : nums) {
            // increase oddCount if num is odd
            oddCount += num % 2;

            // check if there exists a prefix where oddCount - k occurred
            if (prefixCount.find(oddCount - k) != prefixCount.end()) {
                count += prefixCount[oddCount - k];
            }

            // store current prefix count
            prefixCount[oddCount]++;
        }

        return count;
    }
};
