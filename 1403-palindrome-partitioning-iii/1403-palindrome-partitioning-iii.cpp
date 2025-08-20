class Solution {
public:
    int t[101][101];
    int palindromePartition(string s, int k) {
        memset(t, -1, sizeof(t));
        return mcm(s, 0, s.length(), k);
    }

    int mcm(string& s, int i, int j, int mx) {
        if (mx == 1) {
            return check(s, i, j-1);
        }

        if (t[i][mx] != -1) {
            return t[i][mx];
        }

        int mn = INT_MAX;
        for (int k = i; k <= j - mx; k++) {
            int temp = check(s, i, k) + mcm(s, k+1, j, mx-1);
            mn = min(mn, temp);
        }

        return t[i][mx] = mn;
    }

    int check(string& s, int i, int j) {
        int count = 0;
        while (i < j) {
            if (s[i] != s[j]) {
                count++;
            }
            i++;
            j--;
        }
        return count;
    }
};