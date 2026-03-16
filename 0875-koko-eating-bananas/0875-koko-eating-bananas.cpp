class Solution {
private:
    int maxElem(vector<int> &piles) {
        int maxi = INT_MIN;
        for(int i=0; i<piles.size(); i++) {
            maxi = max(maxi, piles[i]);
        }
        return maxi;
    }

    long long calculateTotalHrs(vector<int> &piles, int perHr) {
        long long totalHrs = 0;
        for(int i=0; i<piles.size(); i++) {
            totalHrs += (piles[i] + perHr - 1) / perHr;
        }
        return totalHrs;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = maxElem(piles);
        int ans = high;

        while(low <= high) {
            int mid = low + (high - low) / 2;
            long long totalHrs = calculateTotalHrs(piles, mid);

            if(totalHrs <= h) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};