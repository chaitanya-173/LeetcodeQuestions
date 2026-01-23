class Solution {
private:
    void f(int idx, int target, vector<int> &candidates,
           vector<int> &path, vector<vector<int>> &ans) {
        if(target == 0) {
            ans.push_back(path);
            return;
        }

        for(int i = idx; i < candidates.size(); i++) {
            if(i > idx && candidates[i] == candidates[i-1]) continue; // skip duplicates
            if(candidates[i] > target) break;

            path.push_back(candidates[i]);
            f(i + 1, target - candidates[i], candidates, path, ans);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> path;
        f(0, target, candidates, path, ans);
        return ans;
    }
};
