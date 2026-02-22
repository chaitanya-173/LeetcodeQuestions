class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        long long m = n;   

        if(m < 0) m = -m;  // now safe

        while(m > 0) {
            if((m & 1) == 1) {  // odd
                ans = ans * x;
                m = m - 1;
            } else {  // even
                m = m >> 1;
                x = x * x;
            }
        }

        if(n < 0) ans = 1.0 / ans;
        return ans;
    }
};