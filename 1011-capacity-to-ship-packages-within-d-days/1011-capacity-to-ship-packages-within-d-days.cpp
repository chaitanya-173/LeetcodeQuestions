class Solution {
private:
    bool isPossible(int cap, vector<int> &arr, int days) {
        int curCap = cap, cnt = 1;
        for(int i=0; i<arr.size(); i++) {
            if(arr[i] <= curCap) {
                curCap = curCap - arr[i];
            } else {
                curCap = cap;
                curCap = curCap - arr[i];
                cnt++;
            }
        }
        return (cnt <= days);
    }

public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int maxi = 0, sum = 0;
        for(int &x : weights) {
            maxi = max(maxi, x);
            sum += x;
        }

        int low = maxi, high = sum;
        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(isPossible(mid, weights, days)) high = mid - 1;
            else low = mid + 1;
        }

        return low;
    }
};