class Solution {
public:

    bool isPalindrome(string s, int i, int j) {
        while(i <= j) {
            if(s[i++] != s[j--]) return false;
        }
        return true;
    }

    string longestPalindrome(string s) {
        int n = s.length();
        int maxi = 0;
        int index = 0;
        for(int i=0; i<n; i++) {
            for(int j=i; j<n; j++) {
                if(s[i] == s[j]) {
                    if(isPalindrome(s, i, j)) {
                        if(j-i+1 > maxi) {
                            maxi = j-i+1;
                            index = i;
                        }
                    }
                }
            }
        }
        return s.substr(index, maxi);
    }
};