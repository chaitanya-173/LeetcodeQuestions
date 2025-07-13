class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.length();
        if(n != t.length()) return false;
        vector<int> occArr(200, 0);

        for(int i=0; i<n; i++) {
            occArr[s[i]] += 1;
        }

        for(int i=0; i<n; i++) {
            if(occArr[t[i]] == 0) return false;
            occArr[t[i]] -= 1;
        }

        return true;
    }
};