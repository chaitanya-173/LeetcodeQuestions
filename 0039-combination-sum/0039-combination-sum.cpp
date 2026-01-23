class Solution {
private:
    void f(int i, vector<int> &row, vector<int> &candidates, int target, vector<vector<int>> &ans, int n) {
        if(target == 0) {
            ans.push_back(row);
            return;
        }
        if(i >= n || target < 0) return;

        // exclude
        f(i+1, row, candidates, target, ans, n);

        // include
        row.push_back(candidates[i]);
        f(i, row, candidates, target - candidates[i], ans, n);
        row.pop_back();
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> row;
        int n = candidates.size();
        f(0, row, candidates, target, ans, n);
        return ans;
    }
};
