class Solution {
public:
    int countPrimes(int n) {
        if(n == 0 || n == 1) return false; 
        vector<bool> isPrime(n, true);
        isPrime[0] = isPrime[1] = false;
        int cnt = 0;

        for(int i=2; i*i < n; i++) {
            if(isPrime[i]) {
                for(int j=i*i; j<n; j+=i) {
                    isPrime[j] = false;
                }
            }
        }

        for(int x: isPrime) {
            if(x == true) cnt++;
        }

        return cnt;
    }
};