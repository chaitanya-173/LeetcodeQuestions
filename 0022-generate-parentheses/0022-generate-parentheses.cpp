class Solution {
private:
    void solve(int open, int close, int n, string &temp, vector<string> &ans) {
        if(open == n && close == n) {
            ans.push_back(temp);
            return;
        }

        if(open < n) {
            temp.push_back('(');
            solve(open+1, close, n, temp, ans);
            temp.pop_back();
        }

        if(open > close) {
            temp.push_back(')');
            solve(open, close+1, n, temp, ans);
            temp.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp = "";
        solve(0, 0, n, temp, ans);
        return ans;
    }
};