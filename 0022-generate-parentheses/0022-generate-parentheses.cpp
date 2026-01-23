class Solution {
private:
    void f(int open, int close, int n, string row, vector<string> &ans) {
        if(open == n && close == n) {
            ans.push_back(row);
            return;
        }

        if(open < n) f(open + 1, close, n, row + '(', ans);

        if(open > close) f(open, close + 1, n, row + ')', ans);
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        f(0, 0, n, "", ans);
        return ans;
    }
};