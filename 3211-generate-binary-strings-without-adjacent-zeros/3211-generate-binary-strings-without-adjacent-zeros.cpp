class Solution {
private:
    void solve(int i, int prev, int n, string temp, vector<string> &ans) {
        if(i == n) {
            ans.push_back(temp);
            return;
        }

        solve(i+1, 1, n, temp+'1', ans);
        if(prev != 0) solve(i+1, 0, n, temp+'0', ans);
    }

public:
    vector<string> validStrings(int n) {
        vector<string> ans;
        solve(0, -1, n, "", ans);
        return ans;
    }
};