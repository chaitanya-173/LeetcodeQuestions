class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        const int mod = 1e9 + 7;

        for(int i = 0; i < queries.size(); i++) {
            int idx = queries[i][0];

            while(idx <= queries[i][1]) {
                nums[idx] = (1LL * nums[idx] * queries[i][3]) % mod;
                idx += queries[i][2];
            }
        }

        int ans = 0;
        for(int &x : nums) {
            ans ^= x;
        }

        return ans;
    }
};