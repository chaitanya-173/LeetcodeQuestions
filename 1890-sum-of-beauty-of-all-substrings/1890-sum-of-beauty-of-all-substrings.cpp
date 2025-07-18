class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int total = 0;

        for (int i = 0; i < n; i++) {
            int freq[26] = {0};  // fresh counts for substrings starting at i

            for (int j = i; j < n; j++) {
                freq[s[j] - 'a']++;

                int mx = 0;
                int mn = INT_MAX;

                for (int k = 0; k < 26; k++) {
                    if (freq[k] == 0) continue;
                    mx = max(mx, freq[k]);
                    mn = min(mn, freq[k]);
                }
                total += (mx - mn);
            }
        }
        return total;
    }
};
