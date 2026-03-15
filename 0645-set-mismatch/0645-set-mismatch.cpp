class Solution {
public:
    vector<int> findErrorNums(vector<int>& arr) {
        using ll = long long;
        ll n = arr.size();
        
        // s - sn = x - y
        // s2 - s2n = x^2 - y^2
        
        ll sn = (n * (n+1)) / 2;
        ll s2n = (n * (n+1) * (2*n + 1)) / 6;
        ll s = 0, s2 = 0;
        
        for(int i=0; i<n; i++) {
            s += arr[i];
            s2 += (ll)arr[i] * (ll)arr[i];
        }
        
        ll val1 = s - sn; // x - y
        ll val2 = s2 - s2n;
        val2 = val2 / val1; // x + y
        ll x = (val1 + val2) / 2;
        ll y = x - val1;
        
        return {(int)x, (int)y};
    }
};