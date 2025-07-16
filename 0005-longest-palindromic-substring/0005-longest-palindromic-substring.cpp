class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n <= 1) return s; // agar string size 0 ya 1 hai, wahi palindrome hai

        int start = 0;  // best palindrome ka starting index
        int maxLen = 1; // ab tak ka longest palindrome length

        // Helper function to expand around center
        auto expandAroundCenter = [&](int left, int right) {
            // Jab tak left aur right valid hai aur same char hai, expand karo
            while (left >= 0 && right < n && s[left] == s[right]) {
                left--;
                right++;
            }
            // Loop khatam hote hi, left aur right ek extra step bahar chale gaye
            int len = right - left - 1;   // actual palindrome length
            if (len > maxLen) {           // agar yeh maxLen se bada hai, update karo
                maxLen = len;
                start = left + 1;        // left+1 se start hota hai palindrome
            }
        };

        // Har character ko center maan ke check karo
        for (int i = 0; i < n; i++) {
            expandAroundCenter(i, i);     // Odd length palindrome
            expandAroundCenter(i, i + 1); // Even length palindrome
        }

        // Longest palindrome substring return karo
        return s.substr(start, maxLen);
    }
};
