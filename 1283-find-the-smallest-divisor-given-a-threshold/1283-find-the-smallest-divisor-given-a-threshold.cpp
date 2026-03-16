class Solution {
private:
    bool isPossible(int divisor, vector<int> &arr, int threshold) {
        long long ans = 0;
        for(int i=0; i<arr.size(); i++) {
            ans += ((arr[i] + divisor - 1) / divisor);
        }
        return ans <= threshold;
    }

public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int maxi = INT_MIN;
        for(int i=0; i<nums.size(); i++) {
            maxi = max(maxi, nums[i]);
        }

        int low = 1, high = maxi;
        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(isPossible(mid, nums, threshold)) high = mid - 1;
            else low = mid + 1;
        } 

        return low;
    }
};