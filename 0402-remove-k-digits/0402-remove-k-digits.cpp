class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;

        // build monotonic increasing stack
        for(char ch : num) {
            while(!st.empty() && k > 0 && st.top() > ch) {
                st.pop();
                k--;
            }
            st.push(ch);
        }

        // if removals still left, remove from end
        while(k > 0 && !st.empty()) {
            st.pop();
            k--;
        }

        // build answer from stack
        string ans = "";
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());

        // remove leading zeros
        int idx = 0;
        while(idx < ans.size() && ans[idx] == '0') idx++;
        ans = ans.substr(idx);

        return ans.empty() ? "0" : ans;
    }
};
