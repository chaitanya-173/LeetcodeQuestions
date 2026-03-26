class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>st;
        for(char curr : s){
            if(!st.empty()){
                char last = st.top();
                if(last == '(' && curr == ')'){
                    st.pop();
                    continue;
                }
            }
            st.push(curr);
        }
        if(st.empty()) return 0;
        string ans="";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        return ans.size();
    }
};