class Solution {
    void solve( string &digits, string &curr, vector<string> &ans, vector<string> &dict, int i) {
        if (curr.length() == digits.length()) {
            ans.push_back(curr);
            return;
        }

        int digit = digits[i] - '0';
        string temp = dict[digit];
        for (int j = 0; j < temp.length(); j++) {
            curr.push_back(temp[j]);
            solve(digits, curr, ans, dict, i+1);
            curr.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) { 
        vector<string> dict = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string curr;
        vector<string> ans;

        solve( digits, curr, ans, dict, 0 );

        return ans;
    }
};