class Solution {
private:
    int solve(vector<int> &nums, int k) {
        int odds = 0, cnt = 0, l = 0;
        for(int r = 0; r < nums.size(); r++) {
            if((nums[r] & 1) == 1) odds++;

            while(odds > k) {
                if((nums[l] & 1) == 1) odds--;
                l++;
            }

            cnt += r-l+1;
        }
        return cnt;
    }

public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return solve(nums, k) - solve(nums, k-1);
    }
};