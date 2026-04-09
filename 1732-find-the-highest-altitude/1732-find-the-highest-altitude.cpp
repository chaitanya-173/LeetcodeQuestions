class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int alt = 0, maxi = 0;
        
        for(int x : gain) {
            alt += x;
            maxi = max(maxi, alt);
        }

        return maxi;
    }
};