class Solution {
private:
    void f(int idx, vector<int> &nums, vector<int> &path, vector<vector<int>> &ans) {
        ans.push_back(path); // current subset store

        for(int i = idx; i < nums.size(); i++) {
            if(i > idx && nums[i] == nums[i-1]) continue; // skip duplicates
            path.push_back(nums[i]);
            f(i + 1, nums, path, ans);
            path.pop_back(); // backtrack
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // sort to handle duplicates
        vector<vector<int>> ans;
        vector<int> path;
        f(0, nums, path, ans);
        return ans;
    }
};
