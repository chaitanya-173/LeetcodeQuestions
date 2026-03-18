class Solution {
private:
    bool isPossible(int cap, vector<int> &arr, int days) {
        int cnt = 1, curCap = cap;
        for(int i=0; i<arr.size(); i++) {
            if(arr[i] <= curCap) {
                curCap -= arr[i];
            } else {
                curCap = cap - arr[i];
                cnt++;
            }
        }
        return cnt <= days;
    }

public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();

        int maxi = *max_element(weights.begin(), weights.end());
        int sum = accumulate(weights.begin(), weights.end(), 0);

        // for(int i=maxi; i<=sum; i++) {
        //     if(isPossible(i, weights, days)) return i;
        // }

        int low = maxi, high = sum;
        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(isPossible(mid, weights, days)) high = mid - 1;
            else low = mid + 1;
        }

        return low;
    }
};