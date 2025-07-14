class Solution {
public:
    int maxDepth(string s) {
        int balance = 0;
        int maxi = 0;
        for(int i=0; i<s.length(); i++) {
            if(s[i] == '(') {
                balance++;   
            }
            if(s[i] == ')') {
                maxi = max(maxi, balance);
                balance--;
            }
        }
        return maxi;
    }
};