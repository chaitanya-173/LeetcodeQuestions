class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int,vector<int>> hash;
        for(int i = 0; i < nums.size(); i++) {
            hash[nums[i]].push_back(i);
        }

        int mini = INT_MAX;
        for(auto &it : hash) {
            vector<int> indices = it.second;

            for(int i = 2; i < indices.size(); i++) {
                mini = min(mini, abs(indices[i-2]-indices[i-1]) + abs(indices[i-1]-indices[i]) + abs(indices[i]-indices[i-2]));
            }
        }

        return mini == INT_MAX ? -1 : mini;
    }
};