class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        // pref[26][n+1]
        vector<vector<int>> pref(26, vector<int>(n+1, 0));

        for (int i = 0; i < n; i++) {
            for (int c = 0; c < 26; c++) {
                pref[c][i+1] = pref[c][i];
            }
            pref[s[i]-'a'][i+1]++;
        }

        int total = 0;
        for (int l = 0; l < n; l++) {
            for (int r = l; r < n; r++) {
                int mx = 0;
                int mn = INT_MAX;
                for (int c = 0; c < 26; c++) {
                    int cnt = pref[c][r+1] - pref[c][l];
                    if (cnt == 0) continue;
                    mx = max(mx, cnt);
                    mn = min(mn, cnt);
                }
                total += (mx - mn);
            }
        }
        return total;
    }
};
