class Solution {
private:
    bool isVowel(char ch) {
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }

public:
    int maxVowels(string s, int k) {
        int cnt = 0;

        for(int i = 0; i < k; i++) {
            if(isVowel(s[i])) cnt++;
        }

        int maxi = cnt;
        
        for(int i = k; i < s.size(); i++) {
            if(isVowel(s[i])) cnt++;
            if(isVowel(s[i - k])) cnt--;
            maxi = max(maxi, cnt);
        }

        return maxi;
    }
};