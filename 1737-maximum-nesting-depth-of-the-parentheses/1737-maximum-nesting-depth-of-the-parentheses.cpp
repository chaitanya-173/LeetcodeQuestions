class Solution {
public:
    int maxDepth(string s) {
        int balance = 0;
        int maxi = 0;
        for(int i=0; i<s.length(); i++) {
            if(s[i] == '(') {
                balance++;
                maxi = max(maxi, balance);
            }
            if(s[i] == ')') {
                balance--;
            }
        }
        return maxi;
    }
};