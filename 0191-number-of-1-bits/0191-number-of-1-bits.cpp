class Solution {
public:
    int hammingWeight(int n) {
        // return __builtin_popcount(n);
        int cnt = 0;
        while(n) {
            n = (n & n-1);
            cnt++;
        }
        return cnt;
    }
};