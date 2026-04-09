class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int l = 0, sum = 0;
        double avg = -1e9;

        for(int r = 0; r < nums.size(); r++) {
            sum += nums[r];

            if(r - l + 1 > k) {
                sum -= nums[l];
                l++;
            }

            if(r - l + 1 == k) avg = max(avg, (sum / (double)k));
        }

        return avg;
    }
};