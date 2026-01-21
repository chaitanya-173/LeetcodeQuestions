class Solution {
private:
    double f(double x, long n) {
        if(n == 0) return 1;

        double half = f(x, n / 2);

        if(n % 2 == 0)
            return half * half;
        else
            return half * half * x;
    }
public:
    double myPow(double x, int n) {
        long N = n;          // INT_MIN safe
        if(N < 0) {
            x = 1 / x;
            N = -N;
        }
        return f(x, N);
    }
};
