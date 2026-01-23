class Solution {
private:
    void f(int idx, int sum, int k, int n, vector<int> &row, vector<vector<int>> &ans) {
        if(sum == n && k == 0) {
            ans.push_back(row);
            return;
        }
        if(idx > 9) return;

        // exclude
        f(idx + 1, sum, k, n, row, ans);

        // include 
        row.push_back(idx);
        f(idx + 1, sum + idx, k-1, n, row, ans);
        row.pop_back();
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> row;
        vector<vector<int>> ans;
        f(1, 0, k, n, row, ans);
        return ans;
    }
};