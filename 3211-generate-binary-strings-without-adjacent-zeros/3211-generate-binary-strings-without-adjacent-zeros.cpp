class Solution {
private:
    void solve(int i, int prev, int n, string &temp, vector<string> &ans) {
        if(i == n) {
            ans.push_back(temp);
            return;
        }

        temp.push_back('1');
        solve(i+1, 1, n, temp, ans);
        temp.pop_back();

        if(prev != 0) {
            temp.push_back('0');
            solve(i+1, 0, n, temp, ans);
            temp.pop_back();
        }
    }

public:
    vector<string> validStrings(int n) {
        vector<string> ans;
        string temp = "";
        solve(0, -1, n, temp, ans);
        return ans;
    }
};