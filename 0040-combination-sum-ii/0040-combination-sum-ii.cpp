class Solution {
private:
    void solve(int ind, int target, vector<int> &arr, vector<int> &temp, vector<vector<int>> &ans) {
        if(target == 0) {
            ans.push_back(temp);
            return;
        }

        for(int i=ind; i<arr.size(); i++) {
            if(i > ind && arr[i] == arr[i-1]) continue;
            if(arr[i] > target) break;

            temp.push_back(arr[i]);
            solve(i+1, target-arr[i], arr, temp, ans);
            temp.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        solve(0, target, candidates, temp, ans);
        return ans;
    }
};