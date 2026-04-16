class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        unordered_map<int, vector<int>> hash;
        for(int i = 0; i < n; i++) {
            hash[nums[i]].push_back(i);
        }

        vector<int> ans;
        
        for(auto &q : queries) {
            auto &vec = hash[nums[q]];

            if(vec.size() == 1) {
                ans.push_back(-1);
                continue;
            }

            int m = vec.size();
            int pos = lower_bound(vec.begin(), vec.end(), q) - vec.begin();

            int leftInd = vec[(pos - 1 + m) % m];
            int rightInd = vec[(pos + 1) % m];

            int leftDist = min(abs(q - leftInd), n - abs(q - leftInd));
            int rightDist = min(abs(q - rightInd), n - abs(q - rightInd));

            ans.push_back(min(leftDist, rightDist));
        }

        return ans;
    }
};