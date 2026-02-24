class Solution {
private:
    void solve(int i, int k, int n, vector<int> &temp, vector<vector<int>> &ans) {
        if(k == 0 && n == 0) {
            ans.push_back(temp);
            return;
        }
        if(i > 9) return;

        // include 
        temp.push_back(i);
        solve(i+1, k-1, n-i, temp, ans);
        temp.pop_back();

        // exclude
        solve(i+1, k, n, temp, ans);
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(1, k, n, temp, ans);
        return ans;
    }
};