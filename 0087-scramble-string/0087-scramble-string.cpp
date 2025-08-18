class Solution {
public:
    unordered_map<string, bool> mpp;
    bool solve(string a, string b){
        string key = a + " " + b;
        if(mpp.count(key)) return mpp[key];
        int n = a.length();
        if(a == b) return mpp[key] = true;
        if(n <= 1) return mpp[key] = false;
        for(int i = 1; i < n; i++){
            bool cond1 = solve(a.substr(0, i), b.substr(n-i, i)) && 
                        solve(a.substr(i, n-i), b.substr(0, n-i));
            bool cond2 = solve(a.substr(0, i), b.substr(0, i)) && 
                        solve(a.substr(i, n-i), b.substr(i, n-i));
            if(cond1 || cond2 ) return mpp[key] = true;
        }
        return mpp[key] = false;
    }
    bool isScramble(string s1, string s2) {
        if(s1.length() != s2.length()) return false;
        if(s1.length() <= 1) return s1 == s2;
        return solve(s1, s2);
    }
};