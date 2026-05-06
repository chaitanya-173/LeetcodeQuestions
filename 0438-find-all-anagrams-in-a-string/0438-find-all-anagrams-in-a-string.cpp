class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;

        if(s.size() < p.size()) return ans;

        vector<int> freqP(26, 0);
        vector<int> window(26, 0);

        for(char c : p) {
            freqP[c - 'a']++;
        }

        int k = p.size();

        for(int i = 0; i < k; i++) {
            window[s[i] - 'a']++;
        }

        if(window == freqP) {
            ans.push_back(0);
        }

        for(int i = k; i < s.size(); i++) {

            // add new char
            window[s[i] - 'a']++;

            // remove old char
            window[s[i-k] - 'a']--;

            if(window == freqP) {
                ans.push_back(i-k+1);
            }
        }

        return ans;
    }
};