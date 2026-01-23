class Solution {
private:
    void f(int i, int n, string &digits, vector<string> &dict, string &row, vector<string> &ans) {
        if(i == n) {
           ans.push_back(row);
           return; 
        }

        int digit = digits[i] - '0';
        string temp = dict[digit];
        for(int j=0; j<temp.size(); j++) {
            row.push_back(temp[j]);
            f(i+1, n, digits, dict, row, ans);
            row.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        vector<string> dict = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans;
        string row = "";
        f(0, n, digits, dict, row, ans);
        return ans;
    }
};