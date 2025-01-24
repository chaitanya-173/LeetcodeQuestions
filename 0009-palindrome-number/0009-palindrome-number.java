class Solution {
    public boolean isPalindrome(int x) {
        if(x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }
        int reverseNumber = 0;
        while(x > reverseNumber) {
            int digit = x % 10;
            reverseNumber = reverseNumber * 10 + digit;
            x = x / 10;
        }
        return (x == reverseNumber || x == reverseNumber / 10);

    }
}