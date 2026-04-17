class Solution {
private:
    int rev(int num) {
        int ans = 0;
        while(num) {
            int digit = num % 10;
            num /= 10;
            ans = (ans * 10) + digit;
        }
        return ans;
    }

public:
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int,int> hash;
        int mini = INT_MAX;

        for(int i = 0; i < n; i++) {
            if(hash.count(nums[i])) {
                mini = min(mini, abs(i - hash[nums[i]]));
            }
            hash[rev(nums[i])] = i;
        }

        return mini == INT_MAX ? -1 : mini;
    }
};