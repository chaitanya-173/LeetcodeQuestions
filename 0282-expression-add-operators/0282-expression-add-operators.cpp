class Solution {
private:
    void solve(int idx, string &num, int target,
               string expr, long long currVal, long long prev, vector<string> &ans) {

        if(idx == num.size()) {
            if(currVal == target) {
                ans.push_back(expr);
            }
            return;
        }

        for(int i = idx; i < num.size(); i++) {

            if(i > idx && num[idx] == '0') break;

            string part = num.substr(idx, i - idx + 1);
            long long currNum = stoll(part);

            if(idx == 0) {  // no operator before first number
                solve(i+1, num, target, part, currNum, currNum, ans); 
            } else {
                solve(i+1, num, target, expr+"+"+part, currVal+currNum, currNum, ans);
                solve(i+1, num, target, expr+"-"+part, currVal-currNum, -currNum, ans); 
                solve(i+1, num, target, expr+"*"+part, currVal-prev+(prev*currNum), prev*currNum, ans);
            }
        }
    }

public:
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        ans.clear();          
        solve(0, num, target, "", 0, 0, ans);               
        return ans;
    }
};
