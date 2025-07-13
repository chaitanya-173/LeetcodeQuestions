class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.length();
        if(n != goal.length()) return false;

        for(int i=0; i<n; i++) {
            int temp = s[0];
            for(int i=1; i<n; i++) {
                s[i-1] = s[i];
            }
            s[n-1] = temp;
            if(s == goal) return true;
        }

        return false;
    }
};