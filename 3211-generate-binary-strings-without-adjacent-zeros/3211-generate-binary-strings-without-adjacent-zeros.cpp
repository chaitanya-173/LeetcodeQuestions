class Solution {
private:
    void solve(int prev, int n, string &temp, vector<string> &ans) {
        if(temp.size() == n) {
            ans.push_back(temp);
            return;
        }

        temp.push_back('1');
        solve(1, n, temp, ans);
        temp.pop_back();

        if(prev != 0) {
            temp.push_back('0');
            solve(0, n, temp, ans);
            temp.pop_back();
        }
    }

public:
    vector<string> validStrings(int n) {
        vector<string> ans;
        string temp = "";
        solve(-1, n, temp, ans);
        return ans;
    }
};