class Solution {
public:
    // Expand from given center [left, right]; update bestStart/bestLen if longer palindrome found.
    void expandAroundCenter(const string &s, int left, int right,
                            int &bestStart, int &bestLen) {
        int n = s.size();

        // Expand outward as long as characters match.
        while (left >= 0 && right < n && s[left] == s[right]) {
            left--;
            right++;
        }

        // We stepped one too far on both sides; actual palindrome is [left+1, right-1].
        int len = right - left - 1;
        if (len > bestLen) {
            bestLen = len;
            bestStart = left + 1;
        }
    }

    string longestPalindrome(string s) {
        int n = s.size();
        if (n <= 1) return s;  // single char (or empty) is already a palindrome

        int bestStart = 0;
        int bestLen = 1;       // at least one char is always a palindrome

        for (int i = 0; i < n; i++) {
            expandAroundCenter(s, i, i,     bestStart, bestLen); // odd-length center
            expandAroundCenter(s, i, i + 1, bestStart, bestLen); // even-length center
        }

        return s.substr(bestStart, bestLen);
    }
};
